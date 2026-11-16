import { test } from "node:test";
import assert from "node:assert/strict";
import { toItem, isActive, parseCommand, nextDelay } from "./protocol.js";

const WIN_PATH = String.raw`C:\Users\a\Downloads\x.zip`;

test("toItem keeps the path, takes the name and hides an unknown total", () => {
  assert.deepEqual(
    toItem({ id: 3, filename: WIN_PATH, bytesReceived: 10,
             totalBytes: -1, state: "in_progress", paused: false, canResume: false }),
    { id: 3, path: WIN_PATH, name: "x.zip", bytes: 10,
      total: 0, state: "in_progress", paused: false, canResume: false });
});

test("toItem with a slash path and a known total", () => {
  const item = toItem({ id: 1, filename: "/home/a/b.iso", bytesReceived: 5,
                        totalBytes: 50, state: "in_progress", paused: true, canResume: true });
  assert.equal(item.name, "b.iso");
  assert.equal(item.total, 50);
  assert.equal(item.paused, true);
});

test("isActive: downloading or resumable interrupted only", () => {
  assert.equal(isActive({ state: "complete" }), false);
  assert.equal(isActive({ state: "in_progress" }), true);
  assert.equal(isActive({ state: "interrupted", canResume: true }), true);
  assert.equal(isActive({ state: "interrupted", canResume: false }), false);
});

test("parseCommand accepts pause/resume/cancel with a numeric id", () => {
  assert.deepEqual(parseCommand('{"type":"pause","id":4}'), { type: "pause", id: 4 });
  assert.deepEqual(parseCommand('{"type":"cancel","id":7}'), { type: "cancel", id: 7 });
  assert.equal(parseCommand('{"type":"rm","id":4}'), null);
  assert.equal(parseCommand('{"type":"pause","id":"4"}'), null);
  assert.equal(parseCommand("x"), null);
});

test("nextDelay doubles up to 60 s", () => {
  assert.equal(nextDelay(5000), 10000);
  assert.equal(nextDelay(40000), 60000);
  assert.equal(nextDelay(60000), 60000);
});
