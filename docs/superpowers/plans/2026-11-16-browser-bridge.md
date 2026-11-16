# Ponte dock ↔ navegadores — plano de implementação

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Pausar/continuar/cancelar e ver a % dos downloads do Chrome e do Zen pelo painel de Downloads da dock.

**Architecture:** Uma extensão MV3 (`extension/`) conecta via WebSocket em `127.0.0.1:47821`, servido por uma thread nova dentro do mod (`mac-dock-26320.wh.cpp`). A extensão manda a lista de downloads; a dock manda comandos. O painel GDI existente mostra os itens do navegador com barra e botões.

**Tech Stack:** C++23 (clang/mingw do Windhawk), Winsock, BCrypt, `winrt::Windows::Data::Json`; JavaScript (MV3, `chrome.downloads` / `browser.downloads`); Node 26 para testes da extensão.

**Spec:** `docs/superpowers/specs/2026-11-16-browser-bridge-design.md`

## Global Constraints

- Porta `47821`, bind só em `127.0.0.1`; até 4 clientes.
- Handshake só com `Origin` começando com `chrome-extension://` ou `moz-extension://`; outros → HTTP 403 e fecha.
- Sem polling rápido: thread da dock bloqueia em `WaitForMultipleObjects` sem timeout curto; extensão manda `downloads` a cada 1 s só com download ativo e `ping` a cada 20 s.
- Mod compila em 64 **e** 32 bits (`dock-link.ps1`, `dock-link32.ps1` → `exit=0`); callbacks Win32 são funções nomeadas, nunca lambdas.
- `@compilerOptions` ganha `-lws2_32 -lbcrypt`.
- gecko id: `mac-dock-downloads@racanelli`. Nome da extensão: `Mac Dock Downloads`.
- Textos de interface em pt-BR.
- Opção `dock.browserBridge` (padrão `true`), nome pt-BR "Ponte com navegadores (pausar/cancelar downloads)".

## Review Focus

1. Dock reiniciada (explorer reinicia) com navegador aberto → extensão reconecta sozinha (backoff 5 s → 60 s) sem recarregar a extensão.
2. Mensagem WebSocket fragmentada ou > 64 KB (muitos downloads) → dock remonta e processa; frame de controle `ping`/`close` do cliente respondido corretamente.
3. Download com `totalBytes` = 0/-1 (tamanho desconhecido) → barra indeterminada e ícone mostra o tamanho, nunca `NaN%`/divisão por zero.
4. Dois navegadores baixando ao mesmo tempo → ids não colidem (chave = cliente + id), comando vai só para o navegador dono.
5. Extensão conectada mas download do navegador sem arquivo correspondente na pasta Downloads (outra pasta) → aparece no painel mesmo assim; clicar mostra o arquivo na pasta dele.

---

### Task 1: Extensão (Chrome + Zen)

**Files:**
- Create: `extension/manifest.json`, `extension/background.js`, `extension/protocol.js`
- Test: `extension/protocol.test.mjs`

**Interfaces:**
- Produces (`protocol.js`, ES module, também carregado pelo service worker):
  - `toItem(d: DownloadItem) -> {id, path, name, bytes, total, state, paused, canResume}` — `name` = último segmento de `d.filename`; `total` = `d.totalBytes > 0 ? d.totalBytes : 0`.
  - `isActive(d) -> bool` — `state === "in_progress"` ou (`state === "interrupted"` e `canResume`).
  - `parseCommand(text: string) -> {type: "pause"|"resume"|"cancel", id: number} | null` — `null` para JSON inválido ou tipo desconhecido.
  - `nextDelay(prevMs: number) -> number` — `min(prev*2, 60000)`, início `5000`.
- Protocolo: ver spec (`hello`, `downloads`, `ping`; comandos `pause`/`resume`/`cancel`).

- [ ] **Step 1: Write the failing test** (`node --test`)

```js
import { test } from "node:test"; import assert from "node:assert/strict";
import { toItem, isActive, parseCommand, nextDelay } from "./protocol.js";
test("toItem", () => assert.deepEqual(
  toItem({id: 3, filename: "C:\\Users\\a\\Downloads\\x.zip", bytesReceived: 10, totalBytes: -1, state: "in_progress", paused: false, canResume: false}),
  {id: 3, path: "C:\\Users\\a\\Downloads\\x.zip", name: "x.zip", bytes: 10, total: 0, state: "in_progress", paused: false, canResume: false}));
test("isActive", () => { assert.equal(isActive({state: "complete"}), false); assert.equal(isActive({state: "interrupted", canResume: true}), true); });
test("parseCommand", () => { assert.deepEqual(parseCommand('{"type":"pause","id":4}'), {type: "pause", id: 4}); assert.equal(parseCommand('{"type":"rm","id":4}'), null); assert.equal(parseCommand("x"), null); });
test("nextDelay", () => { assert.equal(nextDelay(5000), 10000); assert.equal(nextDelay(40000), 60000); });
```

- [ ] **Step 2:** `node --test extension/` → FAIL (módulo não existe).
- [ ] **Step 3:** Implementar `protocol.js`; `background.js` usa `chrome.downloads` (no Zen `chrome` também existe): conecta `ws://127.0.0.1:47821`, manda `hello` (`browser`: `"zen"` se `navigator.userAgent` contém `Firefox`, senão `"chrome"`), escuta `onCreated`/`onChanged`/`onErased`, manda `downloads` com todos os ativos; `setInterval` 1 s só enquanto houver ativo; `ping` 20 s; comandos → `chrome.downloads.pause/resume/cancel`; reconexão com `nextDelay` (e `chrome.alarms` de 1 min para acordar o service worker). `manifest.json`: MV3, `permissions: ["downloads","alarms"]`, `background: {service_worker: "background.js", scripts: ["background.js"], type: "module"}`, gecko id e `strict_min_version: "121.0"`.
- [ ] **Step 4:** `node --test extension/` → PASS; `node --check extension/background.js` → sem erro.
- [ ] **Step 5:** Commit `feat(extension): downloads bridge extension`.

### Task 2: Servidor WebSocket no mod

**Files:**
- Modify: `mac-dock-26320.wh.cpp` (seção nova "Browser bridge" logo após o bloco do painel de Downloads; `@compilerOptions`; settings `dock.browserBridge`; `Wh_ModInit`/`Wh_ModUninit` para iniciar/parar a thread)
- Create: `tools/bridge-test.ps1`

**Interfaces:**
- Produces (thread do painel lê sob `g_bridgeLock`):
  - `struct BridgeItem { int client; long long id; std::wstring path, name; ULONGLONG bytes, total; bool paused, canResume, interrupted; };`
  - `std::vector<BridgeItem> BridgeSnapshot();`
  - `bool BridgeConnected(PCWSTR browser);` — `L"chrome"` / `L"zen"`.
  - `void BridgeSend(int client, PCWSTR type, long long id);` — enfileira e sinaliza o evento.
  - `void StartBridge(); void StopBridge();`
  - Ao mudar a lista: chama `PokeDockRendering()` e posta `kBridgeChanged = WM_APP + 11` para a thread do painel (`g_downloadsThreadId`).
- Handshake: `Sec-WebSocket-Accept = base64(SHA1(key + "258EAFA5-E914-47DA-95CA-C5AB0DC65B11"))`.
- Frames: aceitar texto mascarado (FIN/continuação), `ping`→`pong`, `close`→fechar; enviar texto sem máscara. Limite 1 MB por mensagem.

- [ ] **Step 1:** Escrever `tools/bridge-test.ps1` (ClientWebSocket .NET com `Options.SetRequestHeader("Origin", ...)`): (a) Origin `chrome-extension://test` → conecta, manda `hello` + `downloads` com 1 item, recebe nada e fecha limpo → imprime `OK accept`; (b) Origin `https://example.com` → falha no connect → imprime `OK reject`.
- [ ] **Step 2:** Rodar o script antes do mod novo → falha (`connection refused`).
- [ ] **Step 3:** Implementar a seção (thread com `WSAEventSelect` + evento de saída; parse JSON com `winrt::Windows::Data::Json::JsonObject::TryParse`).
- [ ] **Step 4:** `dock-link.ps1` e `dock-link32.ps1` → `exit=0`. Depois de o usuário compilar no Windhawk: `tools/bridge-test.ps1` → `OK accept` e `OK reject`.
- [ ] **Step 5:** Commit `feat(dock): local WebSocket bridge for browser downloads`.

### Task 3: Painel e ícone com itens do navegador

**Files:**
- Modify: `mac-dock-26320.wh.cpp` — `ScanDownloads`, `DownloadItem`, `PaintDownloads`, `DownloadsHitTest`, `DownloadsWndProc`, badge do ícone no `OnRendering`.

**Interfaces:**
- Consumes: Task 2 (`BridgeSnapshot`, `BridgeSend`, `kBridgeChanged`).
- `DownloadItem` ganha `int bridgeClient = -1; long long bridgeId = 0; ULONGLONG total = 0; bool paused = false, canResume = false;`.
- Hit codes novos: `-100 - 2*i` = pausar/continuar do item `i`, `-101 - 2*i` = cancelar do item `i`.
- `g_downloadsTotal` (`std::atomic<ULONGLONG>`) ao lado de `g_downloadsBytes`; ícone mostra `NN%` quando `total > 0`.

- [ ] **Step 1:** Em `ScanDownloads`, adicionar os itens do bridge no topo e remover o `.crdownload`/`.part` cujo caminho sem sufixo (ou nome) é igual ao `path` do item do navegador.
- [ ] **Step 2:** Desenho: grade = barra de 3 DIP sob a miniatura + 2 botões redondos de 22 DIP no canto superior direito (`\uE769` pausar, `\uE768` continuar, `\uE711` cancelar); lista = botões à direita (texto encurta) + barra sob a linha de detalhe. Detalhe: `Baixando… 45% · 120 MB de 260 MB` / `Pausado · 45%`.
- [ ] **Step 3:** Clique nos botões → `BridgeSend`; não fecha o painel.
- [ ] **Step 4:** Compilar 64/32 → `exit=0`. Teste manual com o usuário: baixar arquivo grande no Chrome → pausar, continuar, cancelar pelo painel (grade e lista); ícone mostra `%`.
- [ ] **Step 5:** Commit `feat(dock): browser downloads in panel with pause/resume/cancel`.

### Task 4: Rodapé de instalação

**Files:**
- Modify: `mac-dock-26320.wh.cpp` (rodapé no painel; extensão embutida como raw strings; instalação)
- Create: `extension/LEIA-ME.txt`, `tools/pack-extension.ps1` (gera `dist/mac-dock-downloads.zip` para assinar na AMO)

**Interfaces:**
- `void InstallExtension(bool zen);` — grava `manifest.json`, `protocol.js`, `background.js` em `%LOCALAPPDATA%\MacDock\extensao` (conteúdo idêntico a `extension/`; o pack script confere com hash); Chrome: copia o caminho para a área de transferência e abre `chrome.exe chrome://extensions` (App Paths); Zen: se `%LOCALAPPDATA%\MacDock\mac-dock-downloads.xpi` existe → `zen.exe <xpi>`, senão abre a pasta.
- Hit codes: `-5` instalar Chrome, `-6` instalar Zen. Rodapé de 34 DIP com `Chrome ● conectado` / `○ Instalar`.

- [ ] **Step 1:** `tools/pack-extension.ps1` gera o zip e falha se o conteúdo embutido no mod divergir de `extension/` → rodar → PASS.
- [ ] **Step 2:** Implementar rodapé + `InstallExtension`.
- [ ] **Step 3:** Compilar 64/32 → `exit=0`. Manual: botão do Chrome abre `chrome://extensions` com o caminho copiado; após carregar, rodapé mostra `● conectado`.
- [ ] **Step 4:** Atualizar README (seção "Extensão dos navegadores" com os passos do Chrome e da assinatura no Zen), versão `3.1.0-dock11`, push, mandar arquivo ao usuário.
- [ ] **Step 5:** Commit `feat(dock): install buttons for the browser extension`.
