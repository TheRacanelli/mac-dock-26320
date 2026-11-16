// Mac Dock Downloads: what the extension and the dock say to each other.

export const PORT = 47821;
const COMMANDS = ["pause", "resume", "cancel"];

// A browser download as the dock wants it.
export function toItem(d) {
  const path = d.filename || "";
  const parts = path.split(/[\\/]/);
  return {
    id: d.id,
    path,
    name: parts[parts.length - 1] || "",
    bytes: d.bytesReceived || 0,
    total: d.totalBytes > 0 ? d.totalBytes : 0,
    state: d.state,
    paused: !!d.paused,
    canResume: !!d.canResume,
  };
}

// Downloading now, or stopped but able to go on.
export function isActive(d) {
  return d.state === "in_progress" || (d.state === "interrupted" && !!d.canResume);
}

// A command from the dock, or null for anything else.
export function parseCommand(text) {
  let message;
  try {
    message = JSON.parse(text);
  } catch {
    return null;
  }
  if (!message || !COMMANDS.includes(message.type) || typeof message.id !== "number") {
    return null;
  }
  return { type: message.type, id: message.id };
}

// How long to wait before trying the dock again.
export function nextDelay(previousMs) {
  return Math.min(previousMs * 2, 60000);
}
