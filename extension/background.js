// Mac Dock Downloads: tells the dock (Windhawk mod, ws://127.0.0.1:27821)
// what's downloading and does what it asks: pause, resume, cancel.
import { PORT, toItem, isActive, parseCommand, nextDelay } from "./protocol.js";

const browserName = navigator.userAgent.includes("Firefox") ? "zen" : "chrome";
let socket = null;
let retryDelay = 5000;
let retryTimer = null;
let tickTimer = null;
let pingTimer = null;

function send(message) {
  if (socket && socket.readyState === WebSocket.OPEN) {
    socket.send(JSON.stringify(message));
  }
}

async function sendDownloads() {
  const all = await chrome.downloads.search({ orderBy: ["-startTime"], limit: 50 });
  const active = all.filter(isActive);
  send({ type: "downloads", items: active.map(toItem) });
  // Every second only while something is downloading.
  const downloading = active.some((d) => d.state === "in_progress" && !d.paused);
  if (downloading && !tickTimer) {
    tickTimer = setInterval(sendDownloads, 1000);
  } else if (!downloading && tickTimer) {
    clearInterval(tickTimer);
    tickTimer = null;
  }
}

async function runCommand(command) {
  try {
    await chrome.downloads[command.type](command.id);
  } catch (error) {
    console.warn("Mac Dock:", command, error);
  }
  sendDownloads();
}

function scheduleRetry() {
  if (retryTimer) {
    return;
  }
  retryTimer = setTimeout(() => {
    retryTimer = null;
    connect();
  }, retryDelay);
  retryDelay = nextDelay(retryDelay);
}

function connect() {
  if (socket && (socket.readyState === WebSocket.OPEN ||
                 socket.readyState === WebSocket.CONNECTING)) {
    return;
  }
  try {
    socket = new WebSocket(`ws://127.0.0.1:${PORT}`);
  } catch {
    scheduleRetry();
    return;
  }
  socket.onopen = () => {
    retryDelay = 5000;
    send({ type: "hello", browser: browserName, version: 1 });
    sendDownloads();
    clearInterval(pingTimer);
    // (Also keeps Chrome's service worker awake; in Zen, an event of the
    // extension's own every 20 s keeps its background page from idling.)
    pingTimer = setInterval(() => {
      send({ type: "ping" });
      chrome.storage?.session?.set({ alive: Date.now() }).catch(() => {});
    }, 20000);
  };
  socket.onmessage = (event) => {
    const command = parseCommand(event.data);
    if (command) {
      runCommand(command);
    }
  };
  socket.onclose = () => {
    clearInterval(pingTimer);
    pingTimer = null;
    socket = null;
    scheduleRetry();
  };
  socket.onerror = () => {};
}

chrome.downloads.onCreated.addListener(sendDownloads);
chrome.downloads.onChanged.addListener(sendDownloads);
chrome.downloads.onErased.addListener(sendDownloads);
// (The keep-alive's event: nothing to do, receiving it is the point.)
chrome.storage?.onChanged?.addListener(() => {});
// Wakes the extension now and then, in case the dock came back.
chrome.alarms.create("mac-dock-reconnect", { periodInMinutes: 1 });
chrome.alarms.onAlarm.addListener(connect);
chrome.runtime.onStartup.addListener(connect);
chrome.runtime.onInstalled.addListener(connect);
connect();
