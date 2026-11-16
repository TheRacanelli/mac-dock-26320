<div align="center">

# 🍏 Mac Dock

**A dock do macOS no lugar da barra de tarefas do Windows 11.**
Ícones que crescem com o mouse, apps que pulam ao abrir e uma pasta de Downloads que
pausa e cancela os downloads do Chrome e do Zen.

![Windows 11](https://img.shields.io/badge/Windows%2011-build%2026320-0078D4?logo=windows11&logoColor=white)
![Windhawk](https://img.shields.io/badge/Windhawk-mod-2EA043)
![Chrome](https://img.shields.io/badge/Chrome-extens%C3%A3o-4285F4?logo=googlechrome&logoColor=white)
![Zen](https://img.shields.io/badge/Zen-extens%C3%A3o%20assinada-F76F53?logo=firefoxbrowser&logoColor=white)
![Licença](https://img.shields.io/badge/licen%C3%A7a-GPL--3.0-blue)

**[📦 Instalar em 5 minutos →](INSTALACAO.md)**

</div>

---

## ✨ O que ela faz

| | |
|---|---|
| 🔍 **Ampliação** | Os ícones crescem quando o mouse passa, como no Mac. |
| 🏀 **Pulos** | O app pula enquanto abre e quando pede atenção. |
| ⚫ **Estilo island** | Dock preta, grudada na borda de baixo, com os cantos curvando para fora. |
| 📌 **Fixar por monitor** | Uma setinha na ponta da dock fixa ou esconde a dock em cada monitor. |
| 📥 **Pasta de Downloads** | Painel em grade ou lista com os arquivos mais recentes. O ícone fica azul e mostra o tamanho enquanto baixa, e diz "Pronto" quando termina. |
| ⏯️ **Pausar e cancelar** | Com a extensão no Chrome ou no Zen, o painel mostra a % real e os botões ⏸ ▶ ✕. |
| 🖱️ **Menu do clique direito** | Abre centralizado em cima do ícone clicado. |

## 🧩 Como as peças se encaixam

```
┌──────────────┐  WebSocket em 127.0.0.1:27821  ┌───────────────────────────┐
│ Chrome / Zen │ ─────────────────────────────▶ │ Mac Dock (mod do Windhawk, │
│  extensão    │ ◀──── pausar / retomar / ✕ ─── │ dentro do explorer.exe)    │
└──────────────┘                                └───────────────────────────┘
```

- **O mod** ([`mac-dock-26320.wh.cpp`](mac-dock-26320.wh.cpp)) desenha a dock e o painel de
  Downloads. Ele roda dentro do Explorer.
- **A extensão** "Mac Dock Downloads" ([`extension/`](extension/)) conta para a dock o que o
  navegador está baixando e executa os comandos que a dock manda.
- A conexão é **só local**: a dock escuta em `127.0.0.1` e recusa qualquer site. Só aceita
  extensões de navegador (`chrome-extension://` e `moz-extension://`).
- Sem a extensão, a dock continua mostrando a pasta de Downloads. Ela só não pausa nem
  cancela.

## 📦 Instalação

O passo a passo completo, com a solução dos problemas comuns, está em
**[INSTALACAO.md](INSTALACAO.md)**.

Os arquivos prontos ficam na pasta [`instalar/`](instalar/) e na página de
[Releases](../../releases):

| Arquivo | Para quê |
|---|---|
| [`mac-dock-26320.wh.cpp`](mac-dock-26320.wh.cpp) | O mod, para colar no Windhawk |
| [`instalar/mac-dock-downloads-zen.xpi`](instalar/mac-dock-downloads-zen.xpi) | Extensão do **Zen**, já assinada pela Mozilla |
| [`instalar/mac-dock-downloads-chrome.zip`](instalar/mac-dock-downloads-chrome.zip) | Extensão do **Chrome**, para descompactar e carregar |

## ⚙️ Opções

No Windhawk, abra o mod e vá em **Settings**. As principais da dock:

| Opção | Padrão | O que faz |
|---|---|---|
| Tamanho dos ícones | 32 px | Tamanho de cada ícone parado |
| Espaço entre os ícones | 8 px | Distância entre os ícones |
| Ampliação dos ícones | 170 % | Quanto o ícone cresce sob o mouse |
| Estilo island | ligado | Dock preta grudada embaixo |
| Botão para fixar ou esconder | ligado | A setinha na ponta direita |
| Pasta de downloads na dock | ligado | O ícone e o painel de Downloads |
| Ponte com navegadores | ligado | Liga a conexão com a extensão |
| Pontinhos embaixo dos apps abertos | ligado | Indicador de app aberto |
| Esconder a barra até o mouse chegar embaixo | desligado | Esconde a dock automaticamente |

## 🧪 Para quem mexe no código

```bash
node --test extension/
```

```bash
pwsh tools/test-bridge-core.ps1
```

```bash
pwsh tools/bridge-test.ps1
```

- `node --test` roda os testes da extensão.
- `test-bridge-core.ps1` testa o núcleo do WebSocket do mod.
- `bridge-test.ps1` testa ao vivo e precisa da dock rodando: aceita uma extensão, recusa um
  site e sobrevive a uma mensagem quebrada.
- `tools/pack-extension.ps1` confere se a extensão embutida no mod é igual à pasta
  `extension/` e gera o zip.

## 🙏 Créditos

- Fork **só da parte da dock** do mod [Mac Island & Dock](https://island.caliberda.com.br/)
  (`mac-island-dock` 3.1.0), do **caliberda**. Todo o crédito do design e do código original
  da dock é dele. A ilha continua vindo do mod original.
- O caminho até o XAML da barra de tarefas veio de mods do **m417z**.
- Feito para o Windows 11 Insider **build 26320**. Nesse build a barra tem outra estrutura
  (`Taskbar.TaskbarFrame` como raiz), e a dock do mod original não aparece.

## 📄 Licença

GPL-3.0, a mesma do mod original.
