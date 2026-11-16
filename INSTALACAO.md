# 📦 Instalação do Mac Dock

São 3 partes. Só a primeira é obrigatória.

| Parte | Tempo | Precisa? |
|---|---|---|
| [1. A dock](#1-a-dock-obrigatório) | 5 min | Sim |
| [2. Extensão no Chrome](#2-extensão-no-chrome-opcional) | 2 min | Só para pausar e cancelar downloads do Chrome |
| [3. Extensão no Zen](#3-extensão-no-zen-opcional) | 1 min | Só para pausar e cancelar downloads do Zen |

> **Antes de começar:** você precisa do Windows 11 e do [Windhawk](https://windhawk.net/)
> instalado. A dock foi feita para o build 26320, mas usa os mesmos caminhos dos outros builds
> do Windows 11.

---

## 1. A dock (obrigatório)

1. Abra o arquivo [`mac-dock-26320.wh.cpp`](mac-dock-26320.wh.cpp) e clique em **Raw**.
2. Selecione tudo (`Ctrl+A`) e copie (`Ctrl+C`).
3. No Windhawk, clique em **Create a new mod**.
4. Apague todo o texto de exemplo e cole o que você copiou.
5. Clique em **Compile**. Leva uns 30 segundos.
6. Clique em **Exit editing mode**.

A dock aparece no lugar da barra de tarefas. Para mudar o tamanho, a ampliação ou o estilo,
abra o mod no Windhawk e vá em **Settings**.

### Se você também usa o Mac Island & Dock original

O mod original do caliberda continua cuidando da **ilha** lá em cima. Para as duas docks não
brigarem, abra as opções dele e deixe a barra em **"Barra do Windows sem mudanças"**.

---

## 2. Extensão no Chrome (opcional)

O Chrome só aceita extensões fora da loja no **modo do desenvolvedor**.

### Jeito fácil: pela própria dock

1. Clique no ícone de **Downloads** na dock.
2. No rodapé do painel, clique em **Instalar no Chrome**.

   A dock grava a extensão em `%LOCALAPPDATA%\MacDock\extensao`, copia esse caminho e abre
   `chrome://extensions`.
3. Ligue **Modo do desenvolvedor**, no canto superior direito.
4. Clique em **Carregar sem compactação**.
5. Cole o caminho (`Ctrl+V`) na barra de endereço da janela e clique em **Selecionar pasta**.

### Jeito manual: pelo zip

1. Baixe [`instalar/mac-dock-downloads-chrome.zip`](instalar/mac-dock-downloads-chrome.zip).
2. Descompacte numa pasta que você **não vai apagar**, por exemplo `Documentos\MacDock`.
3. Siga os passos 3 a 5 acima, escolhendo essa pasta.

**Pronto quando:** o rodapé do painel de Downloads mostra **● Chrome conectado** em verde.

---

## 3. Extensão no Zen (opcional)

O Zen só instala extensões **assinadas pela Mozilla**. A deste repositório já está assinada.

1. Baixe [`instalar/mac-dock-downloads-zen.xpi`](instalar/mac-dock-downloads-zen.xpi).
2. Arraste o arquivo para uma janela do Zen.
3. Clique em **Adicionar**.

**Pronto quando:** o rodapé do painel de Downloads mostra **● Zen conectado** em verde.

> **Dica:** se você salvar o `.xpi` como `%LOCALAPPDATA%\MacDock\mac-dock-downloads.xpi`, o
> botão **Instalar no Zen** do painel abre o Zen direto na instalação.

---

## ✅ Testando

1. Comece um download grande, de uns 500 MB ou mais.
2. O ícone de Downloads da dock fica azul e pula.
3. Abra o painel: o download aparece com a porcentagem e os botões **⏸** e **✕**.
4. Clique em **⏸**: o navegador pausa. Clique em **▶**: ele continua.
5. Clique em **✕**: o navegador cancela.

---

## 🛠️ Problemas comuns

### O rodapé não mostra "conectado"

- Confira se a opção **Ponte com navegadores** está ligada nas Settings do mod.
- No Chrome, abra `chrome://extensions` e veja se o cartão **Mac Dock Downloads** tem um botão
  **Erros**.
- A extensão tenta de novo a cada minuto. Reabrir o navegador força a conexão na hora.
- Teste se a dock está escutando:

  ```bash
  netstat -ano | findstr :27821
  ```

  Tem que aparecer uma linha com `127.0.0.1:27821`.

### Usa WSL com `networkingMode=mirrored`?

O WSL nesse modo reserva no Windows as portas de 32768 a 60999, e elas não aparecem no
`netstat`. Por isso a dock usa a porta **27821**, que fica fora dessa faixa.

### O Zen diz que a extensão está corrompida ou não verificada

Você está tentando instalar o `.zip`. No Zen, use o **`.xpi` assinado**
(`instalar/mac-dock-downloads-zen.xpi`).

### "Mostrar na pasta" abre outro explorador de arquivos

A dock abre pastas pelo Windows (`ShellExecute`, com `explorer.exe /select,...` para mostrar o
arquivo selecionado). Exploradores de terceiros, como o Directory Opus, se registram em
`ShellExecuteHooks` e pegam essas chamadas.

- O primeiro hook da lista ganha.
- Para trocar de explorador, desligue o "Explorer Replacement" do outro explorador.

### O download aparece duas vezes no painel

Isso foi corrigido no dock13. Atualize o mod colando a versão nova do
`mac-dock-26320.wh.cpp`.

---

## 🖤 Extra: menu do clique direito preto

1. Instale o mod **Windows 11 Notification Center Styler**, do m417z.
2. Deixe **Theme** vazio.
3. Em **Control styles**, adicione:
   - Target: `Border#JumpListRestyledAcrylic`
   - Styles:
     - `Background:=<SolidColorBrush Color="#E6000000"/>`
     - `BorderThickness=0`
     - `CornerRadius=16`

---

## 🔄 Atualizando

- **Dock:** no Windhawk, abra o mod, clique em **Edit**, cole a versão nova do
  `mac-dock-26320.wh.cpp` e clique em **Compile**.
- **Chrome:** em `chrome://extensions`, clique no ↻ do cartão Mac Dock Downloads.
- **Zen:** instale o `.xpi` novo por cima do antigo.
