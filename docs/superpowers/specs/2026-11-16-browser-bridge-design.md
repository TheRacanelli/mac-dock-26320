# Ponte dock ↔ navegadores (Chrome e Zen) — design

Data: 2026-11-16 · Status: aprovado (opção 1)

## Intenção

No painel de Downloads da dock, poder **pausar, continuar e cancelar** downloads
que estão em andamento no Chrome e no Zen, e ver a **% real**. Hoje a dock só
enxerga os arquivos `.crdownload`/`.part` crescendo na pasta (sem %, sem
controle). Uso pessoal do autor por enquanto (não publicado em lojas).

## Objetivos

- Uma extensão única (Manifest V3) que roda no Chrome e no Zen.
- A extensão conecta na dock e manda a lista de downloads (nome, caminho, bytes,
  total, estado, pausado).
- A dock manda comandos: pausar, continuar, cancelar.
- Painel: itens do navegador com barra de %, botões ⏸/▶ e ✕ (grade e lista).
- Ícone da dock mostra `45%` quando o total é conhecido (senão, o tamanho, como hoje).
- Rodapé do painel com estado e botões "Instalar no Chrome" / "Instalar no Zen".

## Não-objetivos

- Publicar na Chrome Web Store ou listar na AMO.
- Edge, Brave, Firefox comum (podem funcionar por tabela, sem garantia).
- Velocidade/tempo restante (fica para depois).

## Anti-objetivos

- Pesar a máquina: nada de polling rápido. Sem downloads, a dock fica parada
  esperando eventos e a extensão só manda um ping a cada 20 s.
- Abrir a dock para sites: só conexões com `Origin` de extensão são aceitas.
- Quebrar o que já funciona sem extensão.

## Abordagens consideradas

1. **Servidor WebSocket local dentro da dock (escolhida).** A dock escuta em
   `127.0.0.1:47821`; a extensão conecta. Sem exe extra; a dock grava a
   extensão sozinha. Custo: ~300 linhas (handshake SHA-1/base64, quadros).
2. **Native messaging + exe ajudante.** Oficial, mas exige um `.exe` separado,
   registro no Windows e ainda um canal exe ↔ explorer.exe. Mais peças.

## Decisões (como foi decidido)

- Porta fixa `47821`, só loopback. Aceita até 4 clientes; cada um se apresenta
  com `hello` (`browser: "chrome" | "zen"`).
- Só aceita handshake com `Origin` começando com `chrome-extension://` ou
  `moz-extension://`.
- JSON com `winrt::Windows::Data::Json`. SHA-1 via BCrypt. Link: `-lws2_32 -lbcrypt`.
- Thread própria na dock com `WSAEventSelect` + `WaitForMultipleObjects`
  (sockets + evento de "tem comando para enviar"). Sem timeout curto.
- Protocolo (texto JSON):
  - extensão → dock: `{"type":"hello","browser":"chrome","version":1}`,
    `{"type":"downloads","items":[{"id":12,"path":"C:\\...\\a.zip","name":"a.zip","bytes":123,"total":456,"state":"in_progress","paused":false,"canResume":true}]}`
    (só itens `in_progress` ou `interrupted` pausáveis; enviado em eventos e a
    cada 1 s **só enquanto há download ativo**), `{"type":"ping"}` a cada 20 s.
  - dock → extensão: `{"type":"pause","id":12}`, `resume`, `cancel`.
- Painel: itens do navegador ficam no topo; o arquivo `.crdownload`/`.part`
  correspondente (mesmo caminho final) some para não duplicar. Sem extensão
  conectada, comportamento atual.
- Grade: barra de % fina sob a miniatura; botões redondos ⏸/▶ e ✕ no canto
  superior direito do card. Lista: barra sob a linha de detalhe; botões à direita.
- Rodapé (altura 34): "Chrome ● conectado / ○ Instalar" e "Zen ● / ○ Instalar".
- Instalar no Chrome: grava `manifest.json` e `background.js` (embutidos no mod)
  em `%LOCALAPPDATA%\MacDock\extensao`, copia o caminho para a área de
  transferência e abre `chrome.exe chrome://extensions` (App Paths). O usuário
  faz "Carregar sem compactação" uma vez.
- Instalar no Zen: se existir `%LOCALAPPDATA%\MacDock\mac-dock-downloads.xpi`
  (assinado na AMO, não listado), abre `zen.exe <xpi>`; senão grava a extensão e
  abre a pasta com instruções. O `.zip` para assinar vai no repositório.
- Extensão: `browser_specific_settings.gecko.id = "mac-dock-downloads@racanelli"`,
  `background` com `service_worker` (Chrome) e `scripts` (Zen), permissão
  `downloads`. Reconecta a cada 5 s com backoff até 60 s se a dock não responder.
- Opção nova no mod: `dock.browserBridge` (padrão ligado).

## Restrições

- Zen só instala extensão assinada (`xpinstall.signatures.required` não vale em
  builds release).
- Mod compila em 64 e 32 bits (sem lambdas como callbacks Win32).
- Service worker do Chrome MV3: WebSocket ativo mantém vivo (Chrome 116+).

## Deixado para quem constrói

- Layout fino dos botões e da barra (pixels), cores dentro do estilo atual.
- Mensagens de erro/estado no rodapé.
