# Mac Dock (build 26320)

Fork **só da parte da dock** do mod do Windhawk
[Mac Island & Dock](https://island.caliberda.com.br/) (`mac-island-dock` 3.1.0), de
**caliberda**. A island continua vindo do mod original: este mod faz só a dock embaixo.

Feito para o Windows 11 Insider **build 26320**, em que a dock do mod original não aparece
(a barra de tarefas desse build tem outra estrutura XAML: `Taskbar.TaskbarFrame` como raiz).

Todo o crédito do design e do código da dock é do caliberda. A parte do caminho até o XAML da
barra veio de mods do **m417z**.

## O que muda em relação ao original

- Funciona no build 26320 (acha o `TaskbarFrame` e mede pela `XamlRoot`).
- Só a dock: island, notificações e bandeja da island foram removidas.
- **Estilo island:** dock preta, grudada na borda de baixo, cantos de cima redondos e os de
  baixo curvando para fora (opção `dock.islandStyle`).
- **Menu do clique direito** abre centralizado em cima do ícone clicado.
- **Setinha de fixar/esconder por monitor** na ponta direita da dock (opção `dock.pinButton`).
  Cada monitor lembra a escolha, e o monitor com a dock fixa continua reservando o espaço dela.
- **Pasta de downloads** na dock (opção `dock.downloads`): painel preto com os arquivos mais
  recentes, downloads do Chrome/Edge/Zen/Firefox aparecendo enquanto baixam, ícone azul durante
  o download e pulando quando termina.

## Instalar

1. No Windhawk, deixe o mod original **Mac Island & Dock** com a barra em "Barra do Windows
   sem mudanças" (para usar só a island dele).
2. Clique em **Create a new mod**, apague tudo e cole o conteúdo de
   [`mac-dock-26320.wh.cpp`](mac-dock-26320.wh.cpp).
3. Clique em **Compile** e depois em **Exit editing mode**.

## Extensão dos navegadores (pausar/cancelar downloads)

Com a extensão **Mac Dock Downloads** ([`extension/`](extension/)), o painel de Downloads mostra
os downloads do Chrome e do Zen com a porcentagem e botões ⏸/▶ e ✕. A dock só escuta em
`127.0.0.1:27821` e só aceita extensões de navegador (opção **Ponte com navegadores**).

**Chrome** (uma vez): no painel de Downloads, clique em **Instalar no Chrome**. A dock grava a
extensão em `%LOCALAPPDATA%\MacDock\extensao`, copia o caminho e abre `chrome://extensions`.
Ligue **Modo do desenvolvedor** → **Carregar sem compactação** → cole o caminho.

**Zen** (uma vez): o Zen só instala extensão assinada pela Mozilla.

1. Rode `pwsh tools/pack-extension.ps1` (gera `dist/mac-dock-downloads.zip`).
2. Em [addons.mozilla.org/developers](https://addons.mozilla.org/developers/), envie o zip
   escolhendo **Por conta própria** (não listada). A assinatura sai em minutos.
3. Baixe o `.xpi` assinado e salve como `%LOCALAPPDATA%\MacDock\mac-dock-downloads.xpi`.
4. No painel de Downloads, clique em **Instalar no Zen** → **Adicionar**.

Testes: `node --test extension/`, `tools/test-bridge-core.ps1` (núcleo WebSocket) e, com a dock
rodando, `pwsh tools/bridge-test.ps1`.

## Menu do clique direito preto (opcional)

Instale o mod **Windows 11 Notification Center Styler** (m417z), deixe **Theme** vazio e em
**Control styles** adicione:

- Target: `Border#JumpListRestyledAcrylic`
- Styles:
  - `Background:=<SolidColorBrush Color="#E6000000"/>`
  - `BorderThickness=0`
  - `CornerRadius=16`

## Licença

GPL-3.0, a mesma do mod original.
