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

## Instalar

1. No Windhawk, deixe o mod original **Mac Island & Dock** com a barra em "Barra do Windows
   sem mudanças" (para usar só a island dele).
2. Clique em **Create a new mod**, apague tudo e cole o conteúdo de
   [`mac-dock-26320.wh.cpp`](mac-dock-26320.wh.cpp).
3. Clique em **Compile** e depois em **Exit editing mode**.

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
