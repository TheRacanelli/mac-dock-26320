import { test } from "node:test";
import assert from "node:assert/strict";
import { readFileSync } from "node:fs";

const manifest = JSON.parse(readFileSync(new URL("./manifest.json", import.meta.url), "utf8"));

test("extension pages CSP drops upgrade-insecure-requests (Firefox would turn ws:// into wss://)", () => {
  const csp = manifest.content_security_policy?.extension_pages;
  assert.ok(csp, "content_security_policy.extension_pages is set");
  assert.ok(csp.includes("script-src 'self'"));
  assert.ok(!csp.includes("upgrade-insecure-requests"));
});

test("storage permission for the Zen keep-alive", () => {
  assert.ok(manifest.permissions.includes("storage"));
});
