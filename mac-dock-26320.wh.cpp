// ==WindhawkMod==
// @id              mac-island-dock-26320
// @name            Mac Dock (build 26320)
// @name:pt-BR      Dock estilo Mac (build 26320)
// @description     A macOS-like dock instead of the taskbar (only the dock from Mac Island & Dock, fixed for build 26320)
// @description:pt-BR Uma dock como a do macOS no lugar da barra de tarefas (só a dock do Mac Island & Dock, corrigida para o build 26320)
// @version         3.1.0-dock6
// @author          caliberda
// @github          https://github.com/cesarkali
// @homepage        https://island.caliberda.com.br
// @donateUrl       https://github.com/sponsors/cesarkali
// @include         explorer.exe
// @compilerOptions -DWIN32_LEAN_AND_MEAN -lole32 -loleaut32 -lruntimeobject -lshell32 -ldwmapi -lcomctl32 -lgdi32 -lmsimg32 -ld2d1 -ldwrite -lwlanapi -luuid -lversion -lbthprops -ldxva2 -lshlwapi -lwinhttp -lwinmm -liphlpapi -lshcore -lcomdlg32 -limm32 -lsetupapi -lcfgmgr32 -luserenv
// @license         GPL-3.0
// ==/WindhawkMod==

// Mac Island & Dock
// Copyright (C) 2026 caliberda (https://github.com/cesarkali)
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, version 3 of the License. It is distributed in the
// hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details:
// https://www.gnu.org/licenses/gpl-3.0.html
//
// The code that reaches the taskbar's XAML tree is based on "Taskbar tray
// auto-hide (show on hover)" by m417z, published under the same license; that
// part keeps m417z's copyright.
//
// If you reuse this mod's code, or it inspired your work, credit to "Mac
// Island & Dock by caliberda" with a link to it would be appreciated (and to
// m417z's mod for the taskbar XAML code). This is a request, not a license
// condition.

// ==WindhawkModReadme==
/*
# Mac Dock (build 26320)

Só a dock do mod **Mac Island & Dock** do caliberda, sem a ilha, com uma
correção para o Windows 11 Insider build 26320 (lá a `Taskbar.TaskbarFrame`
virou a raiz da barra e o mod original não a encontrava).

- Use junto com o mod original para ter a ilha: deixe nele `taskbarMode: windows`.
- A dock fica no lugar da barra de tarefas, embaixo da tela.

Baseado em "Mac Island & Dock" por caliberda
(https://github.com/cesarkali, https://island.caliberda.com.br), GPL-3.0.
O código que alcança o XAML da barra é baseado no mod
"Taskbar tray auto-hide (show on hover)" do m417z.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- hiding:
  - autoHide: false
    $name: Hide the taskbar until the mouse reaches the bottom edge
    $name:pt-BR: Esconder a barra até o mouse chegar na borda de baixo
    $name:zh-CN: 隐藏任务栏，直到鼠标移到底部边缘
    $name:de-DE: Taskleiste ausblenden, bis die Maus den unteren Rand erreicht
    $name:es: Ocultar la barra de tareas hasta que el ratón llegue al borde inferior
    $name:ru-RU: Скрывать панель задач, пока мышь не достигнет нижнего края
    $name:ja-JP: マウスが下端に届くまでタスクバーを隠す
    $name:vi-VN: "Tự động ẩn thanh tác vụ"
    $description: Turns on the Windows auto-hide while the mod is on, and back off when it's turned off (if it was off before), with every choice of "Taskbar" (off by default). The other options of this group need it
    $description:pt-BR: Liga o ocultar automaticamente do Windows enquanto o mod está ativo, e desliga de novo quando ele é desativado (se estava desligado antes), com qualquer opção de "Barra de tarefas" (desligado por padrão). As outras opções deste grupo precisam dela
    $description:zh-CN: mod 启用时打开 Windows 的自动隐藏，mod 关闭时再关掉（如果之前是关闭的），适用于"任务栏"的所有选项（默认关闭）。本组的其他选项需要它
    $description:de-DE: Schaltet das automatische Ausblenden von Windows ein, solange der Mod läuft, und wieder aus, wenn er beendet wird (falls es vorher aus war), bei jeder Auswahl von "Taskleiste" (standardmäßig aus). Die anderen Optionen dieser Gruppe setzen es voraus
    $description:es: Activa el ocultado automático de Windows mientras el mod está activo y lo desactiva al apagarlo (si estaba desactivado antes), con cada opción de "Barra de tareas" (desactivado por defecto). Las demás opciones de este grupo lo necesitan
    $description:ru-RU: Включает автоскрытие Windows, пока мод включён, и снова выключает при его отключении (если раньше было выключено), для любого варианта «Панель задач» (по умолчанию выключено). Остальные параметры этой группы требуют его
    $description:ja-JP: Mod がオンの間は Windows の自動非表示をオンにし、Mod をオフにすると元に戻します（以前オフだった場合）。「タスクバー」のどの選択肢でも使えます（既定ではオフ）。このグループの他のオプションにはこれが必要です
    $description:vi-VN: "Bật chế độ tự động ẩn của Windows khi mod hoạt động và khôi phục trạng thái ban đầu khi tắt mod. Đưa chuột xuống mép dưới màn hình để hiện lại thanh tác vụ. Áp dụng cho mọi chế độ thanh tác vụ, mặc định tắt; các tùy chọn còn lại trong nhóm cần bật mục này"
  - hideWhen: mouseAway
    $name: When it hides
    $name:pt-BR: Quando esconder
    $name:zh-CN: 何时隐藏
    $name:de-DE: Wann sie sich ausblendet
    $name:es: Cuándo se oculta
    $name:ru-RU: Когда скрывать
    $name:ja-JP: 隠すタイミング
    $name:vi-VN: "Điều kiện tự động ẩn"
    $description: "With \"Mouse away\" (the default) it hides as soon as the mouse leaves it. The others keep it shown on the desktop and hide it only while an app's window is maximized on its monitor, or is over it (maximized ones too); it comes back once the window goes. The mouse at the bottom edge still brings it up. Only for \"Dock\" and \"Windows taskbar, transparent\" (and \"only the apps\" with its option in App icons)"
    $description:pt-BR: "Com \"Mouse longe\" (o padrão) ela se esconde assim que o mouse sai dela. As outras a deixam aparecendo na área de trabalho e só a escondem enquanto a janela de um app está maximizada no monitor dela, ou por cima dela (as maximizadas também); ela volta quando a janela sai. O mouse na borda de baixo continua trazendo ela. Só para \"Dock\" e \"Barra do Windows transparente\" (e \"só com os apps\" com a opção dela em Ícones dos apps)"
    $description:zh-CN: "选择“鼠标离开”（默认）时，鼠标一离开它就隐藏。其他选项让它在桌面上保持显示，只有当某个应用窗口在它所在的显示器上最大化，或盖住它（包括最大化的窗口）时才隐藏；窗口离开后它会回来。鼠标移到底部边缘仍可让它出现。仅适用于\"程序坞\"和\"Windows 任务栏，透明\"（在应用图标中开启其选项时也适用于\"只显示应用\"）"
    $description:de-DE: "Mit \"Maus weg\" (Standard) blendet sie sich aus, sobald die Maus sie verlässt. Die anderen lassen sie auf dem Desktop sichtbar und blenden sie nur aus, solange ein App-Fenster auf ihrem Monitor maximiert ist oder über ihr liegt (maximierte auch); sie kommt zurück, sobald das Fenster weg ist. Die Maus am unteren Rand blendet sie weiterhin ein. Nur für \"Dock\" und \"Windows-Taskleiste, transparent\" (und \"nur die Apps\" mit ihrer Option unter App-Symbole)"
    $description:es: "Con \"Ratón lejos\" (el predeterminado) se oculta en cuanto el ratón sale de ella. Las otras la mantienen visible en el escritorio y solo la ocultan mientras la ventana de una app está maximizada en su monitor, o encima de ella (las maximizadas también); vuelve cuando la ventana se va. El ratón en el borde inferior la sigue mostrando. Solo para \"Dock\" y \"Barra de tareas de Windows, transparente\" (y \"solo las apps\" con su opción en Iconos de apps)"
    $description:ru-RU: "При «Мышь далеко» (по умолчанию) она скрывается, как только мышь уходит с неё. Остальные варианты оставляют её видимой на рабочем столе и скрывают, только пока окно приложения развёрнуто на её мониторе или находится над ней (развёрнутые тоже); она возвращается, когда окно уходит. Мышь у нижнего края по-прежнему вызывает её. Только для «Док» и «Панель задач Windows, прозрачная» (и «только приложения» с её параметром в «Значки приложений»)"
    $description:ja-JP: "「マウスが離れたとき」（既定）では、マウスが離れるとすぐに隠れます。ほかの選択肢では、デスクトップでは表示したままにし、そのモニターでアプリのウィンドウが最大化されているとき、またはウィンドウが重なっているとき（最大化も含む）だけ隠れます。ウィンドウがなくなると戻ります。下端のマウスでは引き続き表示されます。「Dock」と「Windows タスクバー、透明」のみ（アプリのアイコンでオプションをオンにすると「アプリのみ」も）"
    $description:vi-VN: "“Chuột ở ngoài” (mặc định) ẩn thanh tác vụ khi con trỏ rời khỏi thanh. Hai lựa chọn còn lại giữ thanh hiển thị trên màn hình nền và chỉ ẩn khi có cửa sổ phóng to trên cùng màn hình, hoặc khi cửa sổ che vị trí của thanh; thanh hiện lại khi điều kiện đó không còn. Đưa chuột xuống mép dưới vẫn hiện thanh tác vụ. Áp dụng cho Dock và thanh tác vụ trong suốt; chế độ chỉ hiện ứng dụng cần bật thêm tùy chọn tương ứng trong nhóm Biểu tượng ứng dụng"
    $options:
    - mouseAway: Mouse away
    - maximized: Window maximized
    - windowOver: Window over it
    $options:pt-BR:
    - mouseAway: Mouse longe
    - maximized: Janela maximizada
    - windowOver: Janela por cima
    $options:zh-CN:
    - mouseAway: 鼠标离开
    - maximized: 窗口最大化
    - windowOver: 窗口挡住它
    $options:de-DE:
    - mouseAway: Maus weg
    - maximized: Fenster maximiert
    - windowOver: Fenster darüber
    $options:es:
    - mouseAway: Ratón lejos
    - maximized: Ventana maximizada
    - windowOver: Ventana encima
    $options:ru-RU:
    - mouseAway: Мышь далеко
    - maximized: Окно развёрнуто
    - windowOver: Окно над ней
    $options:ja-JP:
    - mouseAway: マウスが離れたとき
    - maximized: ウィンドウの最大化
    - windowOver: ウィンドウが重なったとき
    $options:vi-VN:
    - mouseAway: "Chuột ở ngoài"
    - maximized: "Cửa sổ phóng to"
    - windowOver: "Cửa sổ che khuất"
  - showDelay: 0
    $name: Wait before showing (ms)
    $name:pt-BR: Espera para aparecer (ms)
    $name:zh-CN: 显示前等待（毫秒）
    $name:de-DE: Wartezeit vor dem Einblenden (ms)
    $name:es: Espera antes de mostrar (ms)
    $name:ru-RU: Задержка перед показом (мс)
    $name:ja-JP: 表示までの待ち時間 (ms)
    $name:vi-VN: "Độ trễ trước khi hiện (ms)"
    $description: How long the mouse has to stay at the bottom edge (0-2000, default 0)
    $description:pt-BR: Quanto tempo o mouse precisa ficar na borda de baixo (0-2000, padrão 0)
    $description:zh-CN: 鼠标需要在底部边缘停留多久（0-2000，默认 0）
    $description:de-DE: Wie lange die Maus am unteren Rand bleiben muss (0-2000, Standard 0)
    $description:es: Cuánto tiempo debe quedarse el ratón en el borde inferior (0-2000, predeterminado 0)
    $description:ru-RU: Как долго мышь должна находиться у нижнего края (0-2000, по умолчанию 0)
    $description:ja-JP: マウスが下端にとどまる必要がある時間（0-2000、既定値 0）
    $description:vi-VN: "Thời gian giữ chuột ở mép dưới trước khi thanh tác vụ hiện lên (0–2000, mặc định 0)"
  - revealHeight: 0
    $name: Height over the bottom edge that brings it up (px at 100% scale)
    $name:pt-BR: Altura acima da borda de baixo que faz ela aparecer (px na escala de 100%)
    $name:zh-CN: 底部边缘上方触发显示的高度（像素，按 100% 缩放）
    $name:de-DE: Höhe über dem unteren Rand, die sie einblendet (px bei 100 % Skalierung)
    $name:es: Altura sobre el borde inferior que la muestra (px con escala al 100 %)
    $name:ru-RU: Высота над нижним краем, при которой она появляется (пикс. при масштабе 100%)
    $name:ja-JP: 表示のきっかけになる下端からの高さ (px、100% スケール時)
    $name:vi-VN: "Chiều cao vùng kích hoạt ở mép dưới (px, tỷ lệ 100%)"
    $description: The same on every monitor. 0 is automatic (the default), only the edge itself, and the icons' height on a monitor with another one below it (where the mouse easily goes past the edge). Only for "Dock" and "Windows taskbar, transparent" (0-120, default 0)
    $description:pt-BR: A mesma em todos os monitores. 0 é automático (o padrão), só a própria borda, e a altura dos ícones num monitor com outro embaixo dele (onde o mouse passa fácil da borda). Só para "Dock" e "Barra do Windows transparente" (0-120, padrão 0)
    $description:zh-CN: 所有显示器相同。0 为自动（默认）：只有边缘本身；下方还有另一台显示器时为图标的高度（鼠标很容易越过边缘）。仅适用于"程序坞"和"Windows 任务栏，透明"（0-120，默认 0）
    $description:de-DE: "Gleich auf jedem Monitor. 0 ist automatisch, der Standard: nur der Rand selbst und die Symbolhöhe auf einem Monitor mit einem weiteren darunter (wo die Maus leicht über den Rand hinausgeht). Nur für \"Dock\" und \"Windows-Taskleiste, transparent\" (0-120, Standard 0)"
    $description:es: "Igual en todos los monitores. 0 es automático, el valor predeterminado: solo el borde en sí, y la altura de los iconos en un monitor con otro debajo (donde el ratón se pasa fácilmente del borde). Solo para \"Dock\" y \"Barra de tareas de Windows, transparente\" (0-120, predeterminado 0)"
    $description:ru-RU: "Одинаково на всех мониторах. 0 — автоматически, по умолчанию: только сам край, а на мониторе с другим монитором снизу (где мышь легко проскакивает край) — высота значков. Только для «Док» и «Панель задач Windows, прозрачная» (0-120, по умолчанию 0)"
    $description:ja-JP: "すべてのモニターで共通です。0 は自動（既定）: 端そのもののみ。下に別のモニターがある場合（マウスが端を通り過ぎやすい）はアイコンの高さになります。「Dock」と「Windows タスクバー、透明」のみ（0-120、既定値 0）"
    $description:vi-VN: "Áp dụng cùng một giá trị cho mọi màn hình. Đặt 0 để tự động: chỉ nhận chuột ở sát mép dưới; nếu có màn hình khác nằm bên dưới, vùng kích hoạt cao bằng biểu tượng để dễ thao tác khi chuột đi qua ranh giới hai màn hình. Chỉ áp dụng cho Dock và thanh tác vụ trong suốt (0–120, mặc định 0)"
  - hideDelay: 400
    $name: Wait before hiding (ms)
    $name:pt-BR: Espera para esconder (ms)
    $name:zh-CN: 隐藏前等待（毫秒）
    $name:de-DE: Wartezeit vor dem Ausblenden (ms)
    $name:es: Espera antes de ocultar (ms)
    $name:ru-RU: Задержка перед скрытием (мс)
    $name:ja-JP: 非表示までの待ち時間 (ms)
    $name:vi-VN: "Độ trễ trước khi ẩn (ms)"
    $description: How long it stays after the mouse leaves it (0-5000, default 400)
    $description:pt-BR: Quanto tempo ela fica depois que o mouse sai (0-5000, padrão 400)
    $description:zh-CN: 鼠标离开后它保留多久（0-5000，默认 400）
    $description:de-DE: Wie lange sie bleibt, nachdem die Maus sie verlassen hat (0-5000, Standard 400)
    $description:es: Cuánto tiempo se queda tras salir el ratón (0-5000, predeterminado 400)
    $description:ru-RU: Как долго она остаётся после ухода мыши (0-5000, по умолчанию 400)
    $description:ja-JP: マウスが離れてから表示を続ける時間（0-5000、既定値 400）
    $description:vi-VN: "Thời gian chờ từ khi đưa chuột ra khỏi thanh tác vụ đến khi thanh tự ẩn (0–5000, mặc định 400)"
  - showDuration: 260
    $name: Showing animation (ms)
    $name:pt-BR: Animação de aparecer (ms)
    $name:zh-CN: 显示动画（毫秒）
    $name:de-DE: Einblendanimation (ms)
    $name:es: Animación de aparición (ms)
    $name:ru-RU: Анимация появления (мс)
    $name:ja-JP: 表示アニメーション (ms)
    $name:vi-VN: "Thời lượng hiệu ứng hiện (ms)"
    $description: How long it takes to slide in, with a little spring; 0 is instant, and the speed in the animations group changes it too (0-1000, default 260)
    $description:pt-BR: Quanto tempo ela leva para entrar, com um leve efeito de mola; 0 é na hora, e a velocidade do grupo de animações também muda isso (0-1000, padrão 260)
    $description:zh-CN: 滑入所需的时间，带一点弹性；0 为立即，动画分组中的速度也会影响它（0-1000，默认 260）
    $description:de-DE: Wie lange das Hineingleiten mit leichter Federung dauert; 0 ist sofort, und die Geschwindigkeit in der Animationsgruppe ändert es ebenfalls (0-1000, Standard 260)
    $description:es: Cuánto tarda en deslizarse hacia dentro, con un pequeño rebote; 0 es instantáneo, y la velocidad del grupo de animaciones también lo cambia (0-1000, predeterminado 260)
    $description:ru-RU: Сколько длится выезд с лёгким пружинным эффектом; 0 — мгновенно, скорость в группе анимаций тоже влияет (0-1000, по умолчанию 260)
    $description:ja-JP: わずかなバネ効果でスライドインする時間。0 は即時で、アニメーション グループの速度にも影響されます（0-1000、既定値 260）
    $description:vi-VN: "Thời gian thanh tác vụ trượt lên, kèm độ nảy nhẹ. Đặt 0 để hiện ngay. Giá trị này còn chịu ảnh hưởng của Tốc độ hiệu ứng trong nhóm Hiệu ứng chuyển động (0–1000, mặc định 260)"
  - hideDuration: 220
    $name: Hiding animation (ms)
    $name:pt-BR: Animação de esconder (ms)
    $name:zh-CN: 隐藏动画（毫秒）
    $name:de-DE: Ausblendanimation (ms)
    $name:es: Animación de ocultación (ms)
    $name:ru-RU: Анимация скрытия (мс)
    $name:ja-JP: 非表示アニメーション (ms)
    $name:vi-VN: "Thời lượng hiệu ứng ẩn (ms)"
    $description: How long it takes to slide out; 0 is instant (0-1000, default 220)
    $description:pt-BR: Quanto tempo ela leva para sair; 0 é na hora (0-1000, padrão 220)
    $description:zh-CN: 滑出所需的时间；0 为立即（0-1000，默认 220）
    $description:de-DE: Wie lange das Hinausgleiten dauert; 0 ist sofort (0-1000, Standard 220)
    $description:es: Cuánto tarda en deslizarse hacia fuera; 0 es instantáneo (0-1000, predeterminado 220)
    $description:ru-RU: Сколько длится уход; 0 — мгновенно (0-1000, по умолчанию 220)
    $description:ja-JP: スライドアウトする時間。0 は即時（0-1000、既定値 220）
    $description:vi-VN: "Thời gian thanh tác vụ trượt xuống khi ẩn. Đặt 0 để ẩn ngay (0–1000, mặc định 220)"
  - fullscreenGuard: true
    $name: Not over games and videos in full screen
    $name:pt-BR: Não aparecer sobre jogos e vídeos em tela cheia
    $name:zh-CN: 不在全屏游戏和视频上方出现
    $name:de-DE: Nicht über Spielen und Videos im Vollbild
    $name:es: No sobre juegos ni vídeos en pantalla completa
    $name:ru-RU: Не поверх игр и видео на весь экран
    $name:ja-JP: 全画面のゲームや動画の上には表示しない
    $name:vi-VN: "Không hiện đè lên trò chơi hoặc video toàn màn hình"
    $description: The mouse at the bottom edge doesn't bring it up over them (the Windows key still does)
    $description:pt-BR: O mouse na borda de baixo não faz ela aparecer sobre eles (a tecla Windows continua funcionando)
    $description:zh-CN: 鼠标移到底部边缘不会让它出现在它们上方（Windows 键仍然可以）
    $description:de-DE: Die Maus am unteren Rand blendet sie darüber nicht ein (die Windows-Taste schon)
    $description:es: El ratón en el borde inferior no la muestra sobre ellos (la tecla Windows sí)
    $description:ru-RU: Мышь у нижнего края не вызывает её поверх них (клавиша Windows по-прежнему вызывает)
    $description:ja-JP: 下端にマウスを置いても、それらの上には表示されません（Windows キーでは引き続き表示されます）
    $description:vi-VN: "Đưa chuột xuống mép dưới sẽ không làm thanh tác vụ hiện đè lên nội dung toàn màn hình. Nhấn phím Windows vẫn có thể hiện thanh tác vụ"
  $name: Hiding and showing
  $name:pt-BR: Esconder e mostrar
  $name:zh-CN: 隐藏和显示
  $name:de-DE: Aus- und Einblenden
  $name:es: Ocultar y mostrar
  $name:ru-RU: Скрытие и показ
  $name:ja-JP: 非表示と表示
  $name:vi-VN: "Tự động ẩn và hiện"
  $description: Hiding the taskbar is for every choice above; the waits, the animations and full screen only for "Dock" and "Windows taskbar, transparent" (the others hide the Windows way)
  $description:pt-BR: Esconder a barra vale para todas as opções acima; as esperas, as animações e a tela cheia só para "Dock" e "Barra do Windows transparente" (as outras se escondem do jeito do Windows)
  $description:zh-CN: 隐藏任务栏适用于上面的所有选项；等待、动画和全屏仅适用于"程序坞"和"Windows 任务栏，透明"（其他选项按 Windows 自己的方式隐藏）
  $description:de-DE: Das Ausblenden der Taskleiste gilt für jede Auswahl oben; Wartezeiten, Animationen und Vollbild nur für "Dock" und "Windows-Taskleiste, transparent" (die anderen blenden sich nach Windows-Art aus)
  $description:es: Ocultar la barra de tareas vale para todas las opciones de arriba; las esperas, las animaciones y la pantalla completa solo para "Dock" y "Barra de tareas de Windows, transparente" (las demás se ocultan a la manera de Windows)
  $description:ru-RU: Скрытие панели задач действует для всех вариантов выше; задержки, анимации и полный экран — только для «Док» и «Панель задач Windows, прозрачная» (остальные скрываются средствами Windows)
  $description:ja-JP: タスクバーの非表示は上のすべての選択肢に適用されます。待ち時間、アニメーション、全画面は「Dock」と「Windows タスクバー、透明」のみ（他は Windows の方法で隠れます）
  $description:vi-VN: "Chế độ tự động ẩn áp dụng cho mọi kiểu thanh tác vụ. Độ trễ, hiệu ứng và tùy chọn không hiện đè lên nội dung toàn màn hình chỉ áp dụng cho Dock và thanh tác vụ trong suốt; các kiểu còn lại dùng cơ chế ẩn mặc định của Windows"
- icons:
  - magnification: 170
    $name: Icon magnification (%)
    $name:pt-BR: Ampliação dos ícones (%)
    $name:zh-CN: 图标放大（%）
    $name:de-DE: Symbolvergrößerung (%)
    $name:es: Ampliación de iconos (%)
    $name:ru-RU: Увеличение значков (%)
    $name:ja-JP: アイコンの拡大 (%)
    $name:vi-VN: "Mức phóng đại biểu tượng (%)"
    $description: How big the icon under the mouse gets, in a wave like on macOS, pushing its neighbors aside; 100 turns it off. The dock makes room above itself for them; on the transparent taskbar they only grow up to its top (100-200, default 170)
    $description:pt-BR: O quanto o ícone embaixo do mouse cresce, numa onda como no macOS, afastando os vizinhos; 100 desliga. A dock abre espaço acima dela para eles; na barra transparente eles só crescem até o topo dela (100-200, padrão 170)
    $description:zh-CN: 鼠标下的图标放大多少，像 macOS 一样呈波浪状，并把相邻图标推开；100 为关闭。程序坞会在上方留出空间；在透明任务栏上图标最多只能放大到任务栏顶部（100-200，默认 170）
    $description:de-DE: Wie groß das Symbol unter der Maus wird, in einer Welle wie unter macOS, wobei die Nachbarn zur Seite rücken; 100 schaltet es aus. Das Dock schafft darüber Platz dafür; in der transparenten Taskleiste wachsen sie nur bis zu ihrer Oberkante (100-200, Standard 170)
    $description:es: Cuánto crece el icono bajo el ratón, en una onda como en macOS, apartando a sus vecinos; 100 lo desactiva. El dock deja espacio encima para ellos; en la barra de tareas transparente solo crecen hasta su borde superior (100-200, predeterminado 170)
    $description:ru-RU: Насколько увеличивается значок под мышью волной, как в macOS, раздвигая соседние; 100 — выключено. Док освобождает над собой место для них; на прозрачной панели задач они вырастают только до её верха (100-200, по умолчанию 170)
    $description:ja-JP: マウスの下のアイコンが macOS のように波状に拡大し、隣のアイコンを押し広げる大きさ。100 でオフ。Dock は上に余白を作ります。透明タスクバーでは、上端までしか拡大しません（100-200、既定値 170）
    $description:vi-VN: "Phóng to biểu tượng dưới con trỏ theo hiệu ứng sóng của macOS, đồng thời đẩy các biểu tượng lân cận sang hai bên. Đặt 100 để tắt. Với Dock, biểu tượng có thể mở rộng lên phía trên; với thanh tác vụ trong suốt, biểu tượng chỉ phóng to đến mép trên của thanh (100–200, mặc định 170)"
  - magnificationRange: 150
    $name: Magnification reach (px)
    $name:pt-BR: Alcance da ampliação (px)
    $name:zh-CN: 放大范围（像素）
    $name:de-DE: Reichweite der Vergrößerung (px)
    $name:es: Alcance de la ampliación (px)
    $name:ru-RU: Зона увеличения (px)
    $name:ja-JP: 拡大の範囲 (px)
    $name:vi-VN: "Phạm vi phóng đại (px)"
    $description: How far from the mouse the neighboring icons still grow. Only with magnification above 100 (40-300, default 150)
    $description:pt-BR: Até que distância do mouse os ícones vizinhos também crescem. Só com ampliação acima de 100 (40-300, padrão 150)
    $description:zh-CN: 距离鼠标多远的相邻图标也会放大。仅在放大大于 100 时有效（40-300，默认 150）
    $description:de-DE: Wie weit von der Maus entfernt die Nachbarsymbole noch wachsen. Nur bei Vergrößerung über 100 (40-300, Standard 150)
    $description:es: A qué distancia del ratón siguen creciendo los iconos vecinos. Solo con ampliación superior a 100 (40-300, predeterminado 150)
    $description:ru-RU: На каком расстоянии от мыши соседние значки ещё увеличиваются. Только при увеличении больше 100 (40-300, по умолчанию 150)
    $description:ja-JP: マウスからどこまで離れた隣のアイコンまで拡大するか。拡大が 100 を超えるときのみ（40-300、既定値 150）
    $description:vi-VN: "Khoảng cách tính từ con trỏ mà các biểu tượng lân cận vẫn được phóng to. Chỉ có tác dụng khi mức phóng đại lớn hơn 100% (40–300, mặc định 150)"
  - onlyApps: false
    $name: Also on "Windows taskbar, only the apps"
    $name:pt-BR: Também na "Barra do Windows só com os apps"
    $name:zh-CN: 也用于"Windows 任务栏，只显示应用"
    $name:de-DE: Auch für "Windows-Taskleiste, nur die Apps"
    $name:es: También en "Barra de tareas de Windows, solo las apps"
    $name:ru-RU: Также для «Панель задач Windows, только приложения»
    $name:ja-JP: 「Windows タスクバー、アプリのみ」でも使う
    $name:vi-VN: "Áp dụng cả cho thanh tác vụ chỉ hiện ứng dụng"
    $description: The magnification and the bounces on that taskbar too (the icons grow up to its top), and "When it hides" with Windows' own auto-hide. Off, that taskbar stays as Windows has it
    $description:pt-BR: A ampliação e os pulos nessa barra também (os ícones crescem até o topo dela), e o "Quando esconder" com o esconder automático do próprio Windows. Desligado, essa barra fica como o Windows a deixa
    $description:zh-CN: 该任务栏也使用放大和跳动（图标最多放大到任务栏顶部），并在 Windows 自带的自动隐藏下使用"何时隐藏"。关闭时，该任务栏保持 Windows 的原样
    $description:de-DE: Die Vergrößerung und das Hüpfen auch in dieser Taskleiste (die Symbole wachsen bis zu ihrer Oberkante) und "Wann sie sich ausblendet" mit dem automatischen Ausblenden von Windows. Aus, bleibt diese Taskleiste, wie Windows sie hat
    $description:es: La ampliación y los rebotes también en esa barra (los iconos crecen hasta su borde superior), y "Cuándo se oculta" con la ocultación automática del propio Windows. Desactivado, esa barra queda como la tiene Windows
    $description:ru-RU: Увеличение и подпрыгивание и на этой панели (значки вырастают до её верха), а также «Когда скрывать» с автоскрытием самой Windows. Если выключено, эта панель остаётся такой, как в Windows
    $description:ja-JP: そのタスクバーでも拡大とバウンスを使い（アイコンは上端まで拡大）、Windows 自身の自動非表示で「隠すタイミング」を使います。オフのときは Windows のままです
    $description:vi-VN: "Dùng hiệu ứng phóng đại và nảy trên thanh tác vụ Windows ở chế độ chỉ hiện ứng dụng; biểu tượng chỉ phóng to đến mép trên của thanh. Đồng thời áp dụng Điều kiện tự động ẩn cùng chế độ tự động ẩn của Windows. Khi tắt, thanh tác vụ giữ cách hoạt động mặc định của Windows"
  - bounceOnLaunch: true
    $name: Bounce while an app opens
    $name:pt-BR: Pular enquanto um app abre
    $name:zh-CN: 应用打开时跳动
    $name:de-DE: Hüpfen, während eine App startet
    $name:es: Rebotar mientras se abre una app
    $name:ru-RU: Подпрыгивание при открытии приложения
    $name:ja-JP: アプリの起動中にバウンス
    $name:vi-VN: "Nảy biểu tượng khi mở ứng dụng"
    $description: The icon of an app being opened bounces until its window shows, like on macOS (not with the "partial" or no animations)
    $description:pt-BR: O ícone de um app abrindo pula até a janela dele aparecer, como no macOS (não com animações "parciais" ou sem animações)
    $description:zh-CN: 正在打开的应用图标会一直跳动，直到窗口出现，像 macOS 一样（"部分"动画或无动画时不会）
    $description:de-DE: Das Symbol einer startenden App hüpft, bis ihr Fenster erscheint, wie unter macOS (nicht bei "Teilweise" oder ohne Animationen)
    $description:es: El icono de una app que se abre rebota hasta que aparece su ventana, como en macOS (no con "Parcial" ni sin animaciones)
    $description:ru-RU: Значок открываемого приложения подпрыгивает, пока не появится его окно, как в macOS (не при «Частично» и без анимаций)
    $description:ja-JP: 起動中のアプリのアイコンは、macOS のようにウィンドウが表示されるまでバウンスします（「一部」またはアニメーションなしのときは無効）
    $description:vi-VN: "Biểu tượng nảy cho đến khi cửa sổ ứng dụng xuất hiện, tương tự macOS. Không áp dụng khi chọn hiệu ứng Cơ bản hoặc tắt hiệu ứng"
  - keepOpenOnLaunch: true
    $name: Stay up while a clicked app opens
    $name:pt-BR: Ficar aberta enquanto um app clicado abre
    $name:zh-CN: 点击的应用打开时保持显示
    $name:de-DE: Oben bleiben, während eine angeklickte App startet
    $name:es: Quedarse arriba mientras se abre una app pulsada
    $name:ru-RU: Оставаться, пока открывается нажатое приложение
    $name:ja-JP: クリックしたアプリの起動中は表示したままにする
    $name:vi-VN: "Giữ thanh tác vụ hiển thị trong lúc mở ứng dụng"
    $description: After clicking an app that isn't open, the taskbar waits for it to open (and bounce) before hiding. Only with the hiding of the group above
    $description:pt-BR: Depois de clicar num app que não está aberto, a barra espera ele abrir (e pular) antes de se esconder. Só com o esconder do grupo acima
    $description:zh-CN: 点击一个未打开的应用后，任务栏会等它打开（并跳动）后再隐藏。仅在上面分组的隐藏开启时有效
    $description:de-DE: Nach dem Klick auf eine nicht geöffnete App wartet die Taskleiste, bis sie startet (und hüpft), bevor sie sich ausblendet. Nur mit dem Ausblenden der Gruppe oben
    $description:es: Tras hacer clic en una app que no está abierta, la barra de tareas espera a que se abra (y rebote) antes de ocultarse. Solo con el ocultado del grupo de arriba
    $description:ru-RU: После нажатия на неоткрытое приложение панель задач ждёт его открытия (и подпрыгивания) и только потом скрывается. Только при скрытии из группы выше
    $description:ja-JP: 開いていないアプリをクリックした後、タスクバーはそのアプリが開く（とバウンスする）まで待ってから隠れます。上のグループの自動非表示がオンのときのみ
    $description:vi-VN: "Khi bấm mở một ứng dụng chưa chạy, thanh tác vụ đợi cửa sổ xuất hiện và hiển thị hiệu ứng nảy trước khi tự ẩn. Cần bật Tự động ẩn thanh tác vụ ở nhóm trên"
  - keepOpenDuration: 1500
    $name: How long it stays after the app opens (ms)
    $name:pt-BR: Quanto tempo ela fica depois que o app abre (ms)
    $name:zh-CN: 应用打开后保持多久（毫秒）
    $name:de-DE: Wie lange sie nach dem Start der App bleibt (ms)
    $name:es: Cuánto se queda tras abrirse la app (ms)
    $name:ru-RU: Как долго остаётся после открытия приложения (мс)
    $name:ja-JP: アプリが開いてから表示を続ける時間 (ms)
    $name:vi-VN: "Thời gian hiển thị thêm sau khi ứng dụng mở (ms)"
    $description: Enough to see the bounces. Only with the option above on (0-5000, default 1500)
    $description:pt-BR: O suficiente para ver os pulos. Só com a opção acima ligada (0-5000, padrão 1500)
    $description:zh-CN: 足够看到跳动。仅在上面的选项开启时有效（0-5000，默认 1500）
    $description:de-DE: Genug, um das Hüpfen zu sehen. Nur mit eingeschalteter Option oben (0-5000, Standard 1500)
    $description:es: Suficiente para ver los rebotes. Solo con la opción de arriba activada (0-5000, predeterminado 1500)
    $description:ru-RU: Достаточно, чтобы увидеть подпрыгивания. Только при включённом параметре выше (0-5000, по умолчанию 1500)
    $description:ja-JP: バウンスが見える程度の長さです。上のオプションがオンのときのみ（0-5000、既定値 1500）
    $description:vi-VN: "Giữ thanh tác vụ hiển thị thêm để thấy trọn hiệu ứng nảy. Chỉ có tác dụng khi bật tùy chọn ngay phía trên (0–5000, mặc định 1500)"
  $name: App icons (dock and transparent taskbar)
  $name:pt-BR: Ícones dos apps (dock e barra transparente)
  $name:zh-CN: 应用图标（程序坞和透明任务栏）
  $name:de-DE: App-Symbole (Dock und transparente Taskleiste)
  $name:es: Iconos de apps (dock y barra de tareas transparente)
  $name:ru-RU: Значки приложений (док и прозрачная панель задач)
  $name:ja-JP: アプリのアイコン（Dock と透明タスクバー）
  $name:vi-VN: "Biểu tượng ứng dụng (Dock và thanh tác vụ trong suốt)"
  $description: Only for the "Dock" and "Windows taskbar, transparent" choices above (and "only the apps" with its option below on)
  $description:pt-BR: Só para as opções "Dock" e "Barra do Windows transparente" acima (e "só com os apps" com a opção dela abaixo ligada)
  $description:zh-CN: 仅适用于上面的"程序坞"和"Windows 任务栏，透明"选项（开启下面的选项时也适用于"只显示应用"）
  $description:de-DE: Nur für die Auswahl "Dock" und "Windows-Taskleiste, transparent" oben (und "nur die Apps" mit ihrer Option unten eingeschaltet)
  $description:es: Solo para las opciones "Dock" y "Barra de tareas de Windows, transparente" de arriba (y "solo las apps" con su opción de abajo activada)
  $description:ru-RU: Только для вариантов «Док» и «Панель задач Windows, прозрачная» выше (и «только приложения» при включённом параметре ниже)
  $description:ja-JP: 上の「Dock」と「Windows タスクバー、透明」の選択肢のみ（下のオプションがオンなら「アプリのみ」も）
  $description:vi-VN: "Áp dụng cho Dock và thanh tác vụ trong suốt. Chế độ chỉ hiện ứng dụng cũng được hỗ trợ nếu bật tùy chọn tương ứng bên dưới"
- dock:
  - iconSize: 32
    $name: Icon size (px)
    $name:pt-BR: Tamanho dos ícones (px)
    $name:zh-CN: 图标大小（像素）
    $name:de-DE: Symbolgröße (px)
    $name:es: Tamaño de iconos (px)
    $name:ru-RU: Размер значков (px)
    $name:ja-JP: アイコンのサイズ (px)
    $name:vi-VN: "Kích thước biểu tượng (px)"
    $description: At rest, like on macOS; the dock's height and margins follow them. When the taskbar doesn't hide itself, the dock at rest fits in the taskbar's height (only the magnified icons go over the windows), so its icons may be smaller (24-64, default 32)
    $description:pt-BR: Em repouso, como no macOS; a altura e as margens da dock acompanham. Quando a barra não se esconde sozinha, a dock em repouso cabe na altura da barra (só os ícones ampliados passam por cima das janelas), então os ícones podem ficar menores (24-64, padrão 32)
    $description:zh-CN: 静止时的大小，像 macOS 一样；程序坞的高度和边距随之变化。任务栏不自动隐藏时，静止的程序坞会放进任务栏的高度内（只有放大的图标会盖住窗口），所以图标可能更小（24-64，默认 32）
    $description:de-DE: In Ruhe, wie unter macOS; Höhe und Ränder des Docks richten sich danach. Wenn sich die Taskleiste nicht selbst ausblendet, passt das Dock in Ruhe in die Taskleistenhöhe (nur die vergrößerten Symbole ragen über die Fenster), daher können die Symbole kleiner sein (24-64, Standard 32)
    $description:es: En reposo, como en macOS; la altura y los márgenes del dock los siguen. Si la barra de tareas no se oculta sola, el dock en reposo cabe en la altura de la barra (solo los iconos ampliados pasan por encima de las ventanas), por lo que sus iconos pueden ser más pequeños (24-64, predeterminado 32)
    $description:ru-RU: В покое, как в macOS; высота и поля дока следуют за ними. Если панель задач не скрывается сама, док в покое вписывается в высоту панели задач (поверх окон выходят только увеличенные значки), поэтому значки могут быть меньше (24-64, по умолчанию 32)
    $description:ja-JP: 通常時のサイズ（macOS と同様）。Dock の高さと余白もそれに合わせて変わります。タスクバーが自動で隠れない場合、通常時の Dock はタスクバーの高さに収まる（拡大したアイコンだけがウィンドウの上に出る）ため、アイコンが小さくなることがあります（24-64、既定値 32）
    $description:vi-VN: "Kích thước biểu tượng khi chưa phóng đại; chiều cao và lề Dock được điều chỉnh theo. Nếu tắt tự động ẩn, Dock thu vừa chiều cao thanh tác vụ Windows nên biểu tượng có thể nhỏ hơn giá trị đã đặt; chỉ biểu tượng đang phóng đại mới vượt lên vùng cửa sổ (24–64, mặc định 32)"
  - iconGap: 8
    $name: Space between icons (px)
    $name:pt-BR: Espaço entre os ícones (px)
    $name:zh-CN: 图标间距（像素）
    $name:de-DE: Abstand zwischen Symbolen (px)
    $name:es: Espacio entre iconos (px)
    $name:ru-RU: Расстояние между значками (px)
    $name:ja-JP: アイコンの間隔 (px)
    $name:vi-VN: "Khoảng cách giữa các biểu tượng (px)"
    $description: The dock gets wider with it (0-32, default 8)
    $description:pt-BR: A dock fica mais larga junto (0-32, padrão 8)
    $description:zh-CN: 程序坞会随之变宽（0-32，默认 8）
    $description:de-DE: Das Dock wird dadurch breiter (0-32, Standard 8)
    $description:es: El dock se hace más ancho con él (0-32, predeterminado 8)
    $description:ru-RU: Док становится шире вместе с ним (0-32, по умолчанию 8)
    $description:ja-JP: これに合わせて Dock も広くなります（0-32、既定値 8）
    $description:vi-VN: "Tăng khoảng cách sẽ làm Dock rộng hơn (0–32, mặc định 8)"
  - bottomGap: 2
    $name: Gap at the bottom (px)
    $name:pt-BR: Espaço embaixo (px)
    $name:zh-CN: 底部间距（像素）
    $name:de-DE: Abstand unten (px)
    $name:es: Espacio inferior (px)
    $name:ru-RU: Отступ снизу (px)
    $name:ja-JP: 下端の余白 (px)
    $name:vi-VN: "Khoảng cách đến mép dưới (px)"
    $description: Between the dock and the bottom edge of the screen (0-24, default 2)
    $description:pt-BR: Entre a dock e a borda de baixo da tela (0-24, padrão 2)
    $description:zh-CN: 程序坞与屏幕底部边缘之间的距离（0-24，默认 2）
    $description:de-DE: Zwischen dem Dock und dem unteren Bildschirmrand (0-24, Standard 2)
    $description:es: Entre el dock y el borde inferior de la pantalla (0-24, predeterminado 2)
    $description:ru-RU: Между доком и нижним краем экрана (0-24, по умолчанию 2)
    $description:ja-JP: Dock と画面の下端の間（0-24、既定値 2）
    $description:vi-VN: "Khoảng trống giữa đáy Dock và mép dưới màn hình (0–24, mặc định 2)"
  - cornerRadius: 22
    $name: Corner roundness (px)
    $name:pt-BR: Arredondamento dos cantos (px)
    $name:zh-CN: 圆角大小（像素）
    $name:de-DE: Eckenrundung (px)
    $name:es: Redondez de las esquinas (px)
    $name:ru-RU: Скругление углов (px)
    $name:ja-JP: 角の丸み (px)
    $name:vi-VN: "Độ bo góc Dock (px)"
    $description: 0 is square, 32 is very round (0-32, default 22)
    $description:pt-BR: 0 é quadrado, 32 é bem arredondado (0-32, padrão 22)
    $description:zh-CN: 0 为直角，32 为很圆（0-32，默认 22）
    $description:de-DE: 0 ist eckig, 32 sehr rund (0-32, Standard 22)
    $description:es: 0 es cuadrado, 32 muy redondo (0-32, predeterminado 22)
    $description:ru-RU: 0 — прямые, 32 — очень круглые (0-32, по умолчанию 22)
    $description:ja-JP: 0 は直角、32 は非常に丸い（0-32、既定値 22）
    $description:vi-VN: "Đặt 0 để dùng góc vuông, 32 để bo tròn tối đa (0–32, mặc định 22)"
  - maxWidth: 0
    $name: Widest the dock gets (% of the screen)
    $name:pt-BR: Largura máxima da dock (% da tela)
    $name:zh-CN: 程序坞的最大宽度（屏幕的 %）
    $name:de-DE: Größte Breite des Docks (% des Bildschirms)
    $name:es: Ancho máximo del dock (% de la pantalla)
    $name:ru-RU: Наибольшая ширина дока (% экрана)
    $name:ja-JP: Dock の最大幅（画面の %）
    $name:vi-VN: "Chiều rộng tối đa của Dock (% màn hình)"
    $description: With more apps than fit, the dock stays this wide, like a box; the apps past its ends are cut off and the mouse wheel over it scrolls them. 0 is no limit (0 or 30-100, default 0)
    $description:pt-BR: Com mais apps do que cabem, a dock fica com essa largura, como uma caixa; os apps além das pontas ficam cortados e a roda do mouse sobre ela os rola. 0 é sem limite (0 ou 30-100, padrão 0)
    $description:zh-CN: 应用多到放不下时，程序坞保持这个宽度，像一个收纳盒；超出两端的应用被裁掉，在其上滚动鼠标滚轮即可滚动它们。0 为不限制（0 或 30-100，默认 0）
    $description:de-DE: Bei mehr Apps, als hineinpassen, bleibt das Dock so breit wie eine Box; die Apps hinter seinen Enden werden abgeschnitten und das Mausrad darüber scrollt sie. 0 ist ohne Grenze (0 oder 30-100, Standard 0)
    $description:es: Con más apps de las que caben, el dock se queda así de ancho, como una caja; las apps más allá de sus extremos se cortan y la rueda del ratón sobre él las desplaza. 0 es sin límite (0 o 30-100, predeterminado 0)
    $description:ru-RU: Если приложений больше, чем помещается, док остаётся такой ширины, как коробка; приложения за его краями обрезаются, а колесо мыши над ним их прокручивает. 0 — без ограничения (0 или 30-100, по умолчанию 0)
    $description:ja-JP: アプリが収まりきらないとき、Dock はこの幅のまま箱のようになり、端からはみ出たアプリは切り取られ、上でマウス ホイールを回すとスクロールします。0 は制限なし（0 または 30-100、既定値 0）
    $description:vi-VN: "Giới hạn chiều rộng Dock. Khi không đủ chỗ, các ứng dụng ngoài vùng hiển thị được ẩn; lăn chuột trên Dock để cuộn đến chúng. Đặt 0 để không giới hạn (0 hoặc 30–100, mặc định 0)"
  - background: true
    $name: Background behind the icons
    $name:pt-BR: Fundo atrás dos ícones
    $name:zh-CN: 图标后面的背景
    $name:de-DE: Hintergrund hinter den Symbolen
    $name:es: Fondo detrás de los iconos
    $name:ru-RU: Фон за значками
    $name:ja-JP: アイコンの背景
    $name:vi-VN: "Hiện nền Dock"
    $description: The rounded shelf with its thin edge (also around the tray). Off, only the icons show, with the same sizes and magnification
    $description:pt-BR: A base arredondada com a borda fina (também em volta da bandeja). Desligado, só os ícones aparecem, com os mesmos tamanhos e a mesma ampliação
    $description:zh-CN: 带细边框的圆角底座（托盘周围也有）。关闭后只显示图标，大小和放大效果不变
    $description:de-DE: Das abgerundete Regal mit dünnem Rand (auch um den Infobereich). Aus, werden nur die Symbole mit denselben Größen und derselben Vergrößerung angezeigt
    $description:es: El estante redondeado con su borde fino (también alrededor de la bandeja). Desactivado, solo se ven los iconos, con los mismos tamaños y ampliación
    $description:ru-RU: Скруглённая подложка с тонкой рамкой (также вокруг области уведомлений). Если выключено, показываются только значки, с теми же размерами и увеличением
    $description:ja-JP: 細い縁取りのある角丸の台座（トレイの周りにも）。オフにするとアイコンだけが表示され、サイズと拡大は同じです
    $description:vi-VN: "Hiện nền bo góc và viền mảnh phía sau các biểu tượng, kể cả khu vực khay hệ thống. Khi tắt, chỉ hiện biểu tượng; kích thước và hiệu ứng phóng đại được giữ nguyên"
  - islandStyle: true
    $name: Island style (black, stuck to the bottom edge)
    $name:pt-BR: Estilo island (preta, grudada na borda de baixo)
    $description: The dock's background is black like the island's, with no gap under it, its top corners round and its bottom corners curving out into the screen's edge. Its opacity is "Background color (%)" (100 for the island's look)
    $description:pt-BR: O fundo da dock fica preto como o da island, sem espaço embaixo, com os cantos de cima arredondados e os de baixo se curvando para fora até a borda da tela. A transparência é a de "Cor do fundo (%)" (100 para ficar igual à island)
  - pinButton: true
    $name: Button to pin or hide the dock (per monitor)
    $name:pt-BR: Botão para fixar ou esconder a dock (por monitor)
    $description: A small arrow at the dock's right end, like the island's. Down hides the dock on that monitor (it comes back with the mouse at the bottom edge); up keeps it shown there. Each monitor remembers its choice, over "Hide the taskbar until the mouse reaches the bottom edge"
    $description:pt-BR: Uma setinha na ponta direita da dock, como a da island. Para baixo esconde a dock naquele monitor (ela volta com o mouse na borda de baixo); para cima deixa ela fixa ali. Cada monitor lembra a sua escolha, por cima de "Esconder a barra até o mouse chegar na borda de baixo"
  - backgroundOpacity: 50
    $name: Background color (%)
    $name:pt-BR: Cor do fundo (%)
    $name:zh-CN: 背景颜色（%）
    $name:de-DE: Hintergrundfarbe (%)
    $name:es: Color de fondo (%)
    $name:ru-RU: Цвет фона (%)
    $name:ja-JP: 背景の色 (%)
    $name:vi-VN: "Độ đục của nền Dock (%)"
    $description: How much color the background has, in the theme's color; 0 is see-through (only its edge shows), 100 is solid (0-100, default 50)
    $description:pt-BR: Quanto de cor o fundo tem, na cor do tema; 0 é transparente (só a borda aparece), 100 é sólido (0-100, padrão 50)
    $description:zh-CN: 背景的颜色有多浓，使用主题颜色；0 为透明（只显示边框），100 为纯色（0-100，默认 50）
    $description:de-DE: Wie viel Farbe der Hintergrund hat, in der Farbe des Designs; 0 ist durchsichtig (nur der Rand ist sichtbar), 100 deckend (0-100, Standard 50)
    $description:es: Cuánto color tiene el fondo, en el color del tema; 0 es transparente (solo se ve su borde), 100 sólido (0-100, predeterminado 50)
    $description:ru-RU: Насколько фон окрашен цветом темы; 0 — прозрачный (виден только край), 100 — сплошной (0-100, по умолчанию 50)
    $description:ja-JP: 背景にテーマの色をどれだけ付けるか。0 は透明（縁のみ表示）、100 は不透明（0-100、既定値 50）
    $description:vi-VN: "Độ đục của màu nền Dock theo giao diện đang dùng. 0 là trong suốt hoàn toàn, chỉ còn viền; 100 là không trong suốt (0–100, mặc định 50)"
  - dotIndicator: true
    $name: Dots under open apps
    $name:pt-BR: Pontinhos embaixo dos apps abertos
    $name:zh-CN: 已打开应用下方的圆点
    $name:de-DE: Punkte unter geöffneten Apps
    $name:es: Puntos bajo las apps abiertas
    $name:ru-RU: Точки под открытыми приложениями
    $name:ja-JP: 開いているアプリの下のドット
    $name:vi-VN: "Dấu chấm dưới ứng dụng đang mở"
    $description: Instead of the Windows line
    $description:pt-BR: No lugar do traço do Windows
    $description:zh-CN: 代替 Windows 的横线
    $description:de-DE: Anstelle der Windows-Linie
    $description:es: En lugar de la línea de Windows
    $description:ru-RU: Вместо линии Windows
    $description:ja-JP: Windows の線の代わりに表示します
    $description:vi-VN: "Thay vạch chỉ báo mặc định của Windows bằng dấu chấm"
  - separator: false
    $name: Line between pinned and open apps
    $name:pt-BR: Linha entre os apps fixados e os abertos
    $name:zh-CN: 已固定与已打开应用之间的分隔线
    $name:de-DE: Linie zwischen angehefteten und geöffneten Apps
    $name:es: Línea entre las apps fijadas y las abiertas
    $name:ru-RU: Линия между закреплёнными и открытыми приложениями
    $name:ja-JP: 固定アプリと起動中アプリの区切り線
    $name:vi-VN: "Đường kẻ giữa ứng dụng đã ghim và ứng dụng đang mở"
    $description: A thin vertical line like the one on macOS, after the apps pinned to the taskbar and before the ones open but not pinned. Only for the Dock; it moves with the icons as they grow
    $description:pt-BR: Um traço vertical fino, como no macOS, depois dos apps fixados na barra e antes dos que estão abertos sem estar fixados. Só para a Dock; ele acompanha os ícones quando crescem
    $description:zh-CN: 类似 macOS 的细竖线，位于固定在任务栏的应用之后、已打开但未固定的应用之前。仅用于程序坞；它会随图标放大而移动
    $description:de-DE: Eine dünne senkrechte Linie wie unter macOS, nach den an die Taskleiste angehefteten Apps und vor den geöffneten, aber nicht angehefteten. Nur für das Dock; sie bewegt sich mit den Symbolen mit, wenn diese wachsen
    $description:es: Una línea vertical fina, como en macOS, después de las apps fijadas en la barra de tareas y antes de las abiertas sin fijar. Solo para el dock; se mueve con los iconos cuando crecen
    $description:ru-RU: Тонкая вертикальная линия, как в macOS, после приложений, закреплённых на панели задач, и перед открытыми, но не закреплёнными. Только для дока; она движется вместе со значками, когда они увеличиваются
    $description:ja-JP: macOS のような細い縦線を、タスクバーに固定したアプリの後ろ、固定していない起動中のアプリの前に表示します。Dock のみ。アイコンが拡大するとそれに合わせて動きます
    $description:vi-VN: "Một đường dọc mảnh như trên macOS, đặt sau các ứng dụng đã ghim vào thanh tác vụ và trước các ứng dụng đang mở nhưng chưa ghim. Chỉ áp dụng cho Dock; đường kẻ di chuyển theo biểu tượng khi chúng phóng to"
  - attentionMode: icon
    $name: When an app needs attention with the dock hidden
    $name:pt-BR: Quando um app pede atenção com a dock escondida
    $name:zh-CN: 程序坞隐藏时应用需要注意
    $name:de-DE: Wenn eine App Aufmerksamkeit braucht und das Dock ausgeblendet ist
    $name:es: Cuando una app necesita atención con el dock oculto
    $name:ru-RU: Когда приложение требует внимания при скрытом доке
    $name:ja-JP: Dock が非表示のときにアプリが注意を求めたら
    $name:vi-VN: "Báo hiệu ứng dụng khi Dock đang ẩn"
    $description: An app flashing its taskbar button (a message, a download done) while the dock is hidden
    $description:pt-BR: Um app piscando o botão na barra (uma mensagem, um download pronto) enquanto a dock está escondida
    $description:zh-CN: 程序坞隐藏时，某个应用闪烁它的任务栏按钮（一条消息、一个下载完成）
    $description:de-DE: Eine App, deren Taskleisten-Schaltfläche blinkt (eine Nachricht, ein fertiger Download), während das Dock ausgeblendet ist
    $description:es: Una app cuyo botón de la barra de tareas parpadea (un mensaje, una descarga terminada) mientras el dock está oculto
    $description:ru-RU: Приложение мигает кнопкой на панели задач (сообщение, завершённая загрузка), пока док скрыт
    $description:ja-JP: Dock が非表示の間に、アプリがタスクバーのボタンを点滅させたとき（メッセージ、ダウンロード完了など）
    $description:vi-VN: "Chọn cách báo hiệu khi ứng dụng nhấp nháy nút trên thanh tác vụ, chẳng hạn có tin nhắn hoặc tải xong tệp, trong lúc Dock đang ẩn"
    $options:
    - icon: Only the app's icon peeks out, bouncing
    - dock: The whole dock shows up
    - none: Nothing
    $options:pt-BR:
    - icon: Só o ícone do app aparece, pulando
    - dock: A dock inteira aparece
    - none: Nada
    $options:zh-CN:
    - icon: 只有应用图标探出并跳动
    - dock: 整个程序坞显示出来
    - none: 什么都不做
    $options:de-DE:
    - icon: Nur das App-Symbol schaut hüpfend hervor
    - dock: Das ganze Dock erscheint
    - none: Nichts
    $options:es:
    - icon: Solo asoma el icono de la app, rebotando
    - dock: Aparece todo el dock
    - none: Nada
    $options:ru-RU:
    - icon: Выглядывает только значок приложения, подпрыгивая
    - dock: Появляется весь док
    - none: Ничего
    $options:ja-JP:
    - icon: アプリのアイコンだけがバウンスしながらのぞく
    - dock: Dock 全体が表示される
    - none: 何もしない
    $options:vi-VN:
    - icon: "Chỉ hiện và nảy biểu tượng ứng dụng"
    - dock: "Hiện toàn bộ Dock"
    - none: "Không báo hiệu"
  - hideTray: false
    $name: Hide the clock and the tray from the dock (without the island)
    $name:pt-BR: Esconder o relógio e a bandeja da dock (sem a ilha)
    $name:zh-CN: 从程序坞隐藏时钟和托盘（没有灵动岛时）
    $name:de-DE: Uhr und Infobereich im Dock ausblenden (ohne die Insel)
    $name:es: Ocultar el reloj y la bandeja del dock (sin la isla)
    $name:ru-RU: Скрыть часы и область уведомлений из дока (без острова)
    $name:ja-JP: Dock の時計とトレイを非表示（アイランドなし）
    $name:vi-VN: "Ẩn đồng hồ và khay hệ thống trên Dock khi tắt Island"
    $description: Only for the "Dock" choice with the island at the top off. The dock shows only the apps. With the island on, the dock never shows them (the island does), so this changes nothing then
    $description:pt-BR: Só para a opção "Dock" com a ilha no topo desligada. A dock mostra só os apps. Com a ilha ligada, a dock nunca mostra os dois (a ilha mostra), então esta opção não muda nada
    $description:zh-CN: 仅适用于"程序坞"选项，并且顶部灵动岛关闭时：程序坞只显示应用。灵动岛开启时，程序坞从不显示它们（由灵动岛显示），所以这时此选项不起作用
    $description:de-DE: Nur für die Auswahl "Dock" bei ausgeschalteter Insel oben. Das Dock zeigt nur die Apps. Bei eingeschalteter Insel zeigt das Dock sie nie (die Insel tut es), daher ändert dies dann nichts
    $description:es: Solo para la opción "Dock" con la isla arriba desactivada. El dock muestra solo las apps. Con la isla activada, el dock nunca los muestra (lo hace la isla), así que esto no cambia nada entonces
    $description:ru-RU: Только для варианта «Док» при выключенном острове вверху. Док показывает только приложения. При включённом острове док никогда их не показывает (это делает остров), поэтому тогда параметр ничего не меняет
    $description:ja-JP: 上部のアイランドがオフのときの「Dock」専用です。Dock にはアプリだけが表示されます。アイランドがオンのときは Dock には表示されず（アイランドが表示します）、このオプションは何も変更しません
    $description:vi-VN: "Chỉ áp dụng khi dùng Dock và tắt Island, giúp Dock chỉ hiển thị ứng dụng. Khi bật Island, đồng hồ và khay hệ thống luôn được hiển thị trên Island nên tùy chọn này không có tác dụng"
  $name: Dock look (dock only)
  $name:pt-BR: Visual da dock (só para a dock)
  $name:zh-CN: 程序坞外观（仅程序坞）
  $name:de-DE: Dock-Aussehen (nur Dock)
  $name:es: Aspecto del dock (solo dock)
  $name:ru-RU: Вид дока (только для дока)
  $name:ja-JP: Dock の外観（Dock のみ）
  $name:vi-VN: "Giao diện Dock"
  $description: Only for the "Dock" choice above
  $description:pt-BR: Só para a opção "Dock" acima
  $description:zh-CN: 仅适用于上面的"程序坞"选项
  $description:de-DE: Nur für die Auswahl "Dock" oben
  $description:es: Solo para la opción "Dock" de arriba
  $description:ru-RU: Только для варианта «Док» выше
  $description:ja-JP: 上の「Dock」の選択肢のみ
  $description:vi-VN: "Chỉ áp dụng khi chọn Dock ở mục Thanh tác vụ"
- animations:
  - enabled: true
    $name: Animations
    $name:pt-BR: Animações
    $name:zh-CN: 动画
    $name:de-DE: Animationen
    $name:es: Animaciones
    $name:ru-RU: Анимации
    $name:ja-JP: アニメーション
    $name:vi-VN: "Bật hiệu ứng chuyển động"
    $description: The dock's and the transparent taskbar's animations (sliding, magnifying, bouncing). Off, everything changes at once
    $description:pt-BR: As animações da dock e da barra transparente (deslizar, ampliar, pular). Desligadas, tudo muda na hora
    $description:zh-CN: 程序坞和透明任务栏的动画（滑动、放大、弹跳）。关闭后，一切立即变化
    $description:de-DE: Die Animationen des Docks und der transparenten Taskleiste (Gleiten, Vergrößern, Hüpfen). Aus, ändert sich alles auf einmal
    $description:es: Las animaciones del dock y de la barra de tareas transparente (deslizar, ampliar, rebotar). Desactivadas, todo cambia de golpe
    $description:ru-RU: Анимации дока и прозрачной панели задач (выезд, увеличение, подпрыгивание). Если выключено, всё меняется мгновенно
    $description:ja-JP: Dock と透明タスクバーのアニメーション（スライド、拡大、バウンス）。オフにすると、すべてが即座に切り替わります
    $description:vi-VN: "Bật hiệu ứng trượt, phóng đại và nảy biểu tượng cho Dock và thanh tác vụ trong suốt. Khi tắt, các thay đổi diễn ra ngay, không có chuyển động trung gian"
  - level: all
    $name: How many
    $name:pt-BR: Quantas
    $name:zh-CN: 数量
    $name:de-DE: Wie viele
    $name:es: Cuántas
    $name:ru-RU: Сколько
    $name:ja-JP: 量
    $name:vi-VN: "Mức độ hiệu ứng"
    $description: '"Partial" keeps the taskbar sliding in and out, and drops what only decorates, for slower computers'
    $description:pt-BR: '"Parciais" mantém a barra entrando e saindo, e tira o que só enfeita, para computadores mais lentos'
    $description:zh-CN: '"部分"保留任务栏滑入和滑出的动画，去掉只用于装饰的动画，适合较慢的电脑'
    $description:de-DE: '"Teilweise" lässt die Taskleiste weiter ein- und ausgleiten und lässt weg, was nur dekoriert, für langsamere Computer'
    $description:es: '"Parcial" mantiene el deslizamiento de la barra de tareas y quita lo que solo decora, para equipos más lentos'
    $description:ru-RU: '«Частично» оставляет выезд и уход панели задач и убирает то, что только украшает, для медленных компьютеров'
    $description:ja-JP: '「一部」はタスクバーのスライドイン/アウトを残し、装飾だけのものを省きます。低速な PC 向けです'
    $description:vi-VN: "Chế độ Cơ bản giữ hiệu ứng trượt ẩn/hiện và bỏ bớt hiệu ứng trang trí để giảm tải cho máy cấu hình thấp"
    $options:
    - all: All
    - partial: "Partial: no bounces, glows, color blends, counting numbers nor scrolling text"
    - none: None
    $options:pt-BR:
    - all: Todas
    - partial: "Parciais: sem quiques, brilhos, mistura de cores, números contando nem texto rolando"
    - none: Nenhuma
    $options:zh-CN:
    - all: 全部
    - partial: "部分：没有弹跳、发光、颜色渐变、数字滚动和文字滚动"
    - none: 无
    $options:de-DE:
    - all: Alle
    - partial: "Teilweise: kein Hüpfen, Leuchten, Farbübergänge, Zählzahlen oder Lauftext"
    - none: Keine
    $options:es:
    - all: Todas
    - partial: "Parcial: sin rebotes, brillos, mezclas de color, números que cuentan ni texto que se desplaza"
    - none: Ninguna
    $options:ru-RU:
    - all: Все
    - partial: "Частично: без подпрыгиваний, свечения, смешения цветов, счёта чисел и прокрутки текста"
    - none: Нет
    $options:ja-JP:
    - all: すべて
    - partial: "一部: バウンス、グロー、色のブレンド、数字のカウント、テキストのスクロールなし"
    - none: なし
    $options:vi-VN:
    - all: "Đầy đủ"
    - partial: "Cơ bản: tắt hiệu ứng nảy, phát sáng, chuyển màu, đổi số và cuộn chữ"
    - none: "Tắt hiệu ứng"
  - speed: 125
    $name: Speed (%)
    $name:pt-BR: Velocidade (%)
    $name:zh-CN: 速度（%）
    $name:de-DE: Geschwindigkeit (%)
    $name:es: Velocidad (%)
    $name:ru-RU: Скорость (%)
    $name:ja-JP: 速度 (%)
    $name:vi-VN: "Tốc độ hiệu ứng (%)"
    $description: More is faster, less is slower (50-200, default 125)
    $description:pt-BR: Mais é mais rápido, menos é mais lento (50-200, padrão 125)
    $description:zh-CN: 越大越快，越小越慢（50-200，默认 125）
    $description:de-DE: Mehr ist schneller, weniger langsamer (50-200, Standard 125)
    $description:es: Más es más rápido, menos más lento (50-200, predeterminado 125)
    $description:ru-RU: Больше — быстрее, меньше — медленнее (50-200, по умолчанию 125)
    $description:ja-JP: 大きいほど速く、小さいほど遅くなります（50-200、既定値 125）
    $description:vi-VN: "Giá trị càng cao, hiệu ứng càng nhanh (50–200, mặc định 125)"
  - frameRate: screen
    $name: Frame rate limit
    $name:pt-BR: Limite de quadros por segundo
    $name:zh-CN: 帧率限制
    $name:de-DE: Bildratenlimit
    $name:es: Límite de fotogramas
    $name:ru-RU: Ограничение частоты кадров
    $name:ja-JP: フレーム レートの上限
    $name:vi-VN: "Giới hạn tốc độ khung hình (FPS)"
    $description: Fewer frames cost less on slower computers; the animations keep their length
    $description:pt-BR: Menos quadros custam menos em computadores mais lentos; as animações mantêm a duração
    $description:zh-CN: 较少的帧在较慢的电脑上开销更小；动画时长不变
    $description:de-DE: Weniger Bilder kosten auf langsameren Computern weniger; die Animationen behalten ihre Dauer
    $description:es: Menos fotogramas cuestan menos en equipos más lentos; las animaciones mantienen su duración
    $description:ru-RU: Меньше кадров — меньше нагрузка на медленных компьютерах; длительность анимаций сохраняется
    $description:ja-JP: フレーム数が少ないほど低速な PC での負荷が下がります。アニメーションの長さは変わりません
    $description:vi-VN: "Giảm tốc độ khung hình để giảm tải cho máy cấu hình thấp. Thời lượng của hiệu ứng vẫn giữ nguyên"
    $options:
    - screen: The screen's rate
    - fps90: About 90 a second
    - fps60: About 60 a second
    - fps30: About 30 a second
    $options:pt-BR:
    - screen: A taxa da tela
    - fps90: Cerca de 90 por segundo
    - fps60: Cerca de 60 por segundo
    - fps30: Cerca de 30 por segundo
    $options:zh-CN:
    - screen: 屏幕刷新率
    - fps90: 约每秒 90 帧
    - fps60: 约每秒 60 帧
    - fps30: 约每秒 30 帧
    $options:de-DE:
    - screen: Die Rate des Bildschirms
    - fps90: Etwa 90 pro Sekunde
    - fps60: Etwa 60 pro Sekunde
    - fps30: Etwa 30 pro Sekunde
    $options:es:
    - screen: La tasa de la pantalla
    - fps90: Unos 90 por segundo
    - fps60: Unos 60 por segundo
    - fps30: Unos 30 por segundo
    $options:ru-RU:
    - screen: Частота экрана
    - fps90: Около 90 в секунду
    - fps60: Около 60 в секунду
    - fps30: Около 30 в секунду
    $options:ja-JP:
    - screen: 画面のリフレッシュ レート
    - fps90: 約 90 フレーム/秒
    - fps60: 約 60 フレーム/秒
    - fps30: 約 30 フレーム/秒
    $options:vi-VN:
    - screen: "Theo tần số quét màn hình"
    - fps90: "Khoảng 90 FPS"
    - fps60: "Khoảng 60 FPS"
    - fps30: "Khoảng 30 FPS"
  $name: Dock animations
  $name:pt-BR: Animações da dock
  $name:zh-CN: 程序坞动画
  $name:de-DE: Dock-Animationen
  $name:es: Animaciones del dock
  $name:ru-RU: Анимации дока
  $name:ja-JP: Dock のアニメーション
  $name:vi-VN: "Hiệu ứng chuyển động của Dock"
  $description: For the dock and the transparent taskbar. The island's own animations are in its settings (they start as these were)
  $description:pt-BR: Para a dock e a barra transparente. As animações da ilha ficam nas configurações dela (começam como estas estavam)
  $description:zh-CN: 适用于程序坞和透明任务栏。灵动岛自己的动画在它的设置中（初始与这里相同）
  $description:de-DE: Für das Dock und die transparente Taskleiste. Die eigenen Animationen der Insel stehen in ihren Einstellungen (sie starten wie diese)
  $description:es: Para el dock y la barra de tareas transparente. Las animaciones propias de la isla están en su configuración (empiezan como estas)
  $description:ru-RU: Для дока и прозрачной панели задач. Анимации острова — в его настройках (они начинаются такими же)
  $description:ja-JP: Dock と透明タスクバー用です。アイランドのアニメーションはその設定にあります（初期値はこれらと同じ）
  $description:vi-VN: "Áp dụng cho Dock và thanh tác vụ trong suốt. Hiệu ứng của Island được chỉnh trong cài đặt Island; giá trị ban đầu được lấy từ các thiết lập này"
*/
// ==/WindhawkModSettings==

#include <windhawk_utils.h>

#include <appmodel.h>
#include <aclapi.h>
#include <audiopolicy.h>
#include <bluetoothapis.h>
#include <cfgmgr32.h>
#include <commdlg.h>
#include <d2d1.h>
#include <d2d1_1.h>
#include <d2d1_3.h>
#include <dbt.h>
#include <devicetopology.h>
#include <dwmapi.h>
#include <dwrite.h>
#include <endpointvolume.h>
#include <exdisp.h>
#include <highlevelmonitorconfigurationapi.h>
#include <imm.h>
#include <mmdeviceapi.h>
// The notification sounds (PlaySound; WIN32_LEAN_AND_MEAN leaves it out).
#include <mmsystem.h>
#include <msctf.h>
#include <netlistmgr.h>
// The network adapters' table (GetIfTable2) needs the Winsock types first
// (WIN32_LEAN_AND_MEAN, in the compiler options, keeps windows.h from pulling
// the old winsock.h in before it).
#include <winsock2.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <dxgi.h>
#include <pdh.h>
#include <psapi.h>
#include <physicalmonitorenumerationapi.h>
#include <propsys.h>
#include <wbemidl.h>
#include <wincodec.h>
#include <winhttp.h>
#include <winioctl.h>
#include <wlanapi.h>
#include <setupapi.h>
#include <shellapi.h>
#include <sddl.h>
#include <shellscalingapi.h>
#include <shldisp.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shobjidl.h>
#include <tlhelp32.h>
#include <userenv.h>
#include <uiautomation.h>
#include <wuapi.h>
#include <dispatcherqueue.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cwctype>
#include <functional>
#include <limits>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#undef GetCurrentTime

#include <winrt/Windows.Devices.Geolocation.h>
#include <winrt/Windows.Devices.Radios.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Effects.h>
#include <winrt/Windows.Graphics.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.Composition.Desktop.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Media.Core.h>
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.Media.Playback.h>
#include <winrt/Windows.Networking.Connectivity.h>
#include <winrt/Windows.Networking.NetworkOperators.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Automation.Peers.h>
#include <winrt/Windows.UI.Xaml.Automation.Provider.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.h>

// The last lines the island's process logged (with their time), kept for
// the settings' Logs page whether Windhawk's logging is on or not (see
// IslandLog). Only there (g_keepLog, set in WhTool_ModInit): explorer's
// lines go to Windhawk's log alone.
constexpr size_t kKeptLogLines = 300;
SRWLOCK g_keptLogLock = SRWLOCK_INIT;
std::wstring g_keptLog[kKeptLogLines];
size_t g_keptLogNext = 0;
size_t g_keptLogCount = 0;
bool g_keepLog = false;

void KeptLog(int line, PCSTR function, PCWSTR format, ...) {
    WCHAR text[1024];
    va_list args;
    va_start(args, format);
    _vsnwprintf_s(text, ARRAYSIZE(text), _TRUNCATE, format, args);
    va_end(args);
    SYSTEMTIME now;
    GetLocalTime(&now);
    WCHAR head[160];
    swprintf_s(head, L"%02u:%02u:%02u.%03u [%d:%S]: ", now.wHour, now.wMinute,
               now.wSecond, now.wMilliseconds, line, function);
    AcquireSRWLockExclusive(&g_keptLogLock);
    g_keptLog[g_keptLogNext] = std::wstring(head) + text;
    g_keptLogNext = (g_keptLogNext + 1) % kKeptLogLines;
    g_keptLogCount = std::min(g_keptLogCount + 1, kKeptLogLines);
    ReleaseSRWLockExclusive(&g_keptLogLock);
}

// The lines kept, oldest first.
std::wstring KeptLogText() {
    std::wstring text;
    AcquireSRWLockShared(&g_keptLogLock);
    for (size_t i = 0; i < g_keptLogCount; i++) {
        text += g_keptLog[(g_keptLogNext + kKeptLogLines - g_keptLogCount + i) %
                          kKeptLogLines] +
                L"\r\n";
    }
    ReleaseSRWLockShared(&g_keptLogLock);
    return text;
}

// A line to Windhawk's log (Wh_Log), and in the island's process kept for
// its Logs page too (see KeptLog).
#define IslandLog(message, ...)                                        \
    do {                                                               \
        Wh_Log(message, ##__VA_ARGS__);                                \
        if (g_keepLog) {                                               \
            KeptLog(__LINE__, __FUNCTION__, message, ##__VA_ARGS__);   \
        }                                                              \
    } while (0)

using namespace winrt::Windows::UI::Xaml;

enum class AttentionMode { Icon, Dock, None };

struct {
    // What the taskbar is: the mod's dock, or the Windows taskbar (all of it,
    // or only its apps).
    enum class TaskbarMode {
        Dock,
        Windows,
        WindowsApps,
        WindowsTransparent,
    } taskbarMode;
    bool autoHide;
    double cornerRadius;
    double dockIconSize;
    double dockIconGap;
    double bottomGap;
    bool dockBackground;
    // Black and stuck to the bottom edge, like the island (dock.islandStyle).
    bool dockIslandStyle;
    // The arrow that pins or hides each monitor's dock (dock.pinButton).
    bool dockPinButton;
    double backgroundOpacity;
    int showDuration;
    int hideDuration;
    int showDelay;
    int hideDelay;
    // When the taskbar hides (hiding.hideWhen): 0 with the mouse away (as
    // Windows does), 1 only while an app's window is maximized on its
    // monitor, 2 while one is over it (see TaskbarWayWatched).
    int hideWhen;
    // The strip over the bottom edge that brings the taskbar up, in DIPs, on
    // every monitor; 0 automatic (see EdgeStripPixels).
    int revealHeight;
    bool fullscreenGuard;
    bool hideTray;
    // The Windows taskbar unchanged, but without its tray (the island's).
    bool windowsHideTray;
    bool showIsland;
    bool islandBar;
    // The pill keeping its room at its edge (windows maximize beside it).
    bool islandReserve;
    // What the island shows.
    bool islandTray;
    bool islandTrayOpen;
    // How the tray icons that aren't pinned show from the arrow: 0 opening
    // sideways in the pill, 1 a grid of icons under it (like Windows'), 2 a
    // list with their names (see TrayListPanel).
    int islandTrayStyle;
    // Files dragged out of the folders panel: 0 asked, 1 copied, 2 moved.
    int islandFolderDrag;
    bool islandNetwork;
    bool islandVolume;
    bool islandBattery;
    bool islandBell;
    bool islandMedia;
    bool islandMediaButtons;
    bool islandBanner;
    bool islandBannerMinimized;
    bool islandHideWindowsBanners;
    // Pictures of notifications that are on the web (like WhatsApp's contact
    // photos) are downloaded: off unless chosen, since it goes online.
    bool islandWebPictures;
    // A click on the Snipping Tool's notifications shows the newest
    // screenshot in Explorer instead of opening the Snipping Tool.
    bool islandScreenshotFolder;
    // The wheel on what's playing on the pill changes the song (not the
    // volume).
    bool islandMediaWheel;
    // A title too long for the pill keeps scrolling while it plays.
    bool islandMediaMarquee;
    // The island's clock: seconds (-1 like the Windows clock), the day of the
    // week, the day and month, the year.
    int clockSeconds;
    bool clockWeekday;
    bool clockDate;
    bool clockYear;
    // Moving the pill by dragging it, and standing it upright on the sides.
    bool islandFreeDrag;
    // Minimized to its line while the mouse is away (at the edges).
    bool islandAutoHide;
    // An island on each monitor (the chosen one's is the main one).
    bool islandAllMonitors;
    // The volume's and the battery's percentage beside their icons.
    bool islandVolumePercent;
    bool islandBatteryPercent;
    // The screen's brightness on the pill.
    bool islandBrightness;
    // A bubble with what was copied (see Island::OnClipboardChanged).
    bool islandClipboard;
    // The keyboard's input method on the pill (see
    // Island::UpdateInputMethodWatch), the apps using the microphone, the
    // camera or the location (see PrivacyThreadProc), and for USB drives an
    // icon to open or eject them and a notification when one is plugged in
    // (see Island::OnDeviceChange).
    bool islandInputMethod;
    bool islandPrivacy;
    bool islandUsbDrives;
    bool islandUsbNotify;
    // The virtual desktops on the pill (see DesktopsThreadProc), and the
    // control center's buttons put on it (a bit each, see kPillActions).
    bool islandDesktops;
    unsigned pillActions;
    // What komorebi's start, stop and reload buttons take along (see
    // KomorebiCommands).
    bool komorebiWhkd;
    bool komorebiMasir;
    // The island's background taking the color of the app in front (see
    // WindowColor).
    bool islandWindowColor;
    // Windows' Win+N and Win+A opening the island's notifications and
    // control center instead (see ShortcutKeyProc).
    bool islandWinN;
    bool islandWinA;
    // Win+J minimizes the islands to their line and brings them back.
    bool islandMinimizeKey;
    // A bubble when Caps Lock is turned on or off (the main island's).
    bool islandCapsLock;
    // Items added in 2.1 (#6157, #6156): the network's speed, other cities'
    // times (Windows' additional clocks), the time until the next event and
    // the Recycle Bin.
    bool islandNetSpeed;
    bool islandWorldClocks;
    bool islandCountdown;
    bool islandCountdownEvents;
    bool islandCountdownAlarms;
    bool islandCountdownTimer;
    bool islandCountdownPomodoro;
    bool islandDownloadFill;
    bool islandChargeFill;
    // The fill's colors, for downloads and other apps, file copies and the
    // battery charging: 0 green, 1 blue, 2 Windows' accent, 3 the user's own
    // (its own 0xRRGGBB).
    int islandFillColor;
    int islandFillOwnColor;
    int islandFillCopyColor;
    int islandFillCopyOwnColor;
    int islandFillChargeColor;
    int islandFillChargeOwnColor;
    // How the fill moves: 0 simple, 1 a liquid wave, 2 a glow with
    // particles (see Island::DrawFill).
    int islandFillStyle;
    // Song lyrics (from lrclib.net, see LyricsThreadProc): on, their size on
    // the pill (0 small, 1 medium, 2 large), their color (0 the text's, 1
    // Windows' accent, 2 their own, 0xRRGGBB); the line sung in the song
    // title's place (see Island::LyricsInTitle).
    bool islandLyrics;
    int islandLyricsSize;
    int islandLyricsColor;
    int islandLyricsOwnColor;
    bool islandLyricsInTitle;
    // The longest a line gets on the pill (see kLyricsMaxWidths).
    int islandLyricsWidth;
    // The Recycle Bin on the pill, from how much in it (see
    // kRecycleMinMegabytes: 0 always).
    bool islandRecycleBin;
    int islandRecycleMinSize;
    // Short notices from the pill: the charger plugged in, low battery, a
    // Bluetooth audio device connected, "Do not disturb" on or off (#6158).
    bool islandStatusNotices;
    // The apps with notifications folded into an arrow on the pill, like the
    // tray: out a moment when one comes, and under the mouse (#6129, #6204).
    bool islandFoldApps;
    // A timer, a stopwatch and Pomodoro on the pill (see TimerPanel).
    bool islandTimer;
    // Bars moving with the sound while something plays (see
    // Island::StepVisualizer), and their color (0 the icons', 1 Windows'
    // accent, 2 a rainbow, 3 their own, 0xRRGGBB).
    bool islandVisualizer;
    int islandVisualizerColor;
    int islandVisualizerOwnColor;
    // Its bars sway smoothly like the iPhone's; off, they jump with the beat.
    bool islandVisualizerSmooth;
    // Once per version, a notice from the pill opens What's new (see
    // Island::StartWhatsNewNotice).
    bool islandWhatsNewNotice;
    // Folders and places, and the wallpapers, on the pill (and how a
    // wallpaper comes in, a WallpaperTransition).
    bool islandFolders;
    bool islandWallpaper;
    int wallpaperTransition;
    // Windows' blur behind the bar and the Fixed style's strip (see
    // Island::UpdateGlass).
    bool islandFrosted;
    // The island and its panels as glass (see GlassLayer).
    bool islandLiquidGlass;
    bool islandTips;
    // The soft gray shape behind the pill's item under the mouse.
    bool islandHoverHighlight;
    // The arrow at the pill's end that minimizes it to its line.
    bool islandMinimizeButton;
    // The bar's items at the screen's corners, the clock in the middle.
    bool islandBarCorners;
    // The bar's edge: 0 the top, 1 the left, 2 the right (upright there,
    // see Island::m_vertical); its corners facing the screen rounded (an
    // index of kBarInnerCornerRadii, 0 none).
    int islandBarSide;
    int islandBarInnerCorners;
    // Where the bar's items go (#6922): 0 as they always did (around
    // the clock in the middle, otherwise at the right end), 1 the
    // left end, 2 the middle, 3 the right end (top to bottom on a
    // side). Not with the items at the screen's corners.
    int islandBarAlign;
    // The What's playing panel's look (#7042): 0 as it always was, 1
    // Pixel (Android), 2 One UI (Samsung), 3 Windows 11, 4 only the
    // cover with the buttons over it (see MediaPlayerLayout).
    int islandMediaStyle;
    // The battery's charge as a ring along the island's edge (#6071): 0
    // off, 1 on the notch with the battery (or the pill), 2 on every
    // notch. Not on the bar.
    int islandBatteryRing;
    // The banner's size, width and corners (indexes of kBannerSizes,
    // kBannerWidths and kBannerCornerShares), and where it shows: 0 out of
    // the pill (where the bell is), 1-9 a point of the screen (its top left
    // to its bottom right, see Island::BannerPlaced).
    int islandBannerSize;
    int islandBannerWidth;
    int islandBannerCorners;
    int islandBannerPlace;
    // How many files the shelf keeps (an index of kShelfLimits).
    int islandShelfLimit;
    // The glass translucent: a lighter tint and livelier colors.
    bool islandGlassTranslucent;
    // The date's order on the clock: 0 the Windows regional format's, 1 the
    // day first, 2 the month first, 3 the year first; and the month as a
    // number ("9/10").
    int clockDateOrder;
    bool clockMonthNumber;
    // The time's format: 0 the Windows regional format's, 1 24 hours, 2 12
    // hours with AM and PM (see FormatClockTime).
    int clockFormat;
    // 0 Windows' measurement system, 1 Celsius, 2 Fahrenheit.
    int weatherUnit;
    // The weather's sky: 0 emoji, 1 the icon pack's pictures, 2 Meteocons
    // (in color), 3 Weather Icons (see WeatherSky).
    int islandWeatherIcons;
    // The icon pack (see IconPackId), and its pictures' and emojis' colors
    // (pictures of one's own, see g_iconFiles, too): 0 only their shapes, in
    // the icons' colors (like the font's), 1 their own colors.
    int islandIconPack;
    int islandIconColors;
    // How long the mouse is away before the island hides as its line, in
    // tenths of a second (see islandAutoHide).
    int islandAutoHideDelay;
    // When it hides (islandAutoHide, the Island style): 0 with the mouse
    // away, 1 only while a window is maximized on its monitor, 2 only while
    // a window is over it (see Island::WindowInTheWay).
    int islandHideWhen;
    // Hidden by the auto-hide (the Island and Fixed styles), or the Bar
    // hidden by Win+J: a small pill with the time instead of the line (see
    // Island::HiddenClockWanted).
    bool islandHideClock;
    // The minimized line fading away after a while (OLED screens): an index
    // of kLineFadeSeconds (0 never).
    int islandLineFade;
    // What opens the minimized line (and the hidden Bar's clock): the
    // mouse reaching it (0), or a click on it (1: it only grows under
    // the mouse).
    int islandLineClick;
    // The Fixed style as notches against the top edge (0: the pill as it
    // is; 1 in the middle, 2 at the screen's corners, or 3), how round
    // their curves are (in percent of the usual), and whether each one hides
    // on its own (otherwise they all do together).
    int islandNotches;
    // The Island style's own (0 by default), the same way, without keeping
    // a strip (see NotchCountWanted).
    int islandPillNotches;
    // The Bar style without its background: only the items (see
    // Island::Render), the frosted glass only lightly tinted.
    bool islandBarClear;
    // The AI agents' usage limits on the pill (see AiUsagePanel), and which
    // agents.
    bool islandAiUsage;
    bool islandAiClaude;
    bool islandAiCodex;
    // The app in focus with its window's title too (see
    // Island::FocusedText).
    bool islandFocusedTitle;
    // The weather's details in its panel as small cards, like a phone's
    // (#6129, see WeatherPanel::Draw), instead of two lines.
    bool islandWeatherCards;
    // The calendar with today big at its left, with alarm, timer and
    // agendas buttons and the day's events beside it (#6165, see
    // CalendarPanel::DrawBigDay).
    bool islandCalendarBigDay;
    // The user's own commands (#6165 #6161): shortcuts to a program, a
    // file, a folder, a link or a command line, run from their panel, or
    // from the pill for the ones chosen as buttons (see CommandsPanel).
    bool islandCommands;
    // The island's Do not disturb silences calls, alarms and reminders
    // too (they still show on the pill; see Island::OnToastsChanged).
    bool islandDndSilent;
    // A browser's download standing still for 30 s shows as paused (see
    // Island::UpdateFill): browsers never tell a pause or a failure.
    bool islandDownloadStalled;
    // Files show Windows' thumbnails (pictures, videos, documents) in the
    // folders panel and on the shelf, made on a thread (see ThumbnailThreadProc).
    bool islandFolderThumbnails;
    // The shelf: files dropped on the pill kept there (their paths) to be
    // dragged out later into another app (see ShelfPanel).
    bool islandShelf;
    // While a timer, Pomodoro or the stopwatch runs, the minimized line is a
    // small pill with the ring and the time of the one ending first (with
    // islandHideClock, the time beside the clock; see TimerLineWanted).
    bool islandTimerLine;
    // The external monitors' brightness is read and set over DDC/CI (their
    // sliders in the control center and on the pill). Some docks and MST hubs
    // make a monitor flicker, or reset, at every call: off, nothing goes over
    // the cable (the built-in screen keeps WMI, and a screen with HDR on its
    // SDR content brightness). Shared by all the islands (see
    // g_externalBrightness).
    bool islandExternalBrightness;
    // The Liquid Glass with the light and shadow of macOS 27: a sheen, a
    // beveled edge, light along its bottom, a soft shadow around it, and the
    // panels' cards as glass too (see GlassLayer and GlassFill).
    bool islandGlassLight;
    // Only an icon for the lyrics on the pill while the song has them
    // (#6684), instead of the line sung now; a click opens their panel.
    bool islandLyricsIcon;
    // With the line on, the minimize arrow pins this island open until it's
    // clicked again (#6725; see Island::m_pinned).
    bool islandArrowPins;
    // The edge zone that brings the pill back at least as long as the pill
    // (#6525; see Island::ActivationLength).
    bool islandZoneAsPill;
    // What's playing's note stays on the pill with nothing playing (#6905).
    bool islandMediaAlways;
    // Of the media buttons on the pill, only play and pause (#6907).
    bool islandMediaPlayOnly;
    // The Bar with the clock in the middle: the items before the clock in the
    // order stay on its one side and the others on its other side, at the
    // screen's corners, whatever comes and goes (#6639).
    bool islandBarFixedSides;
    // The power button's actions, each on or off (#6609; see PowerActionOn).
    bool islandPowerSleep;
    // (See islandPowerSleep; only when Windows allows it.)
    bool islandPowerHibernate;
    // (See islandPowerSleep.)
    bool islandPowerRestart;
    // (See islandPowerSleep.)
    bool islandPowerShutDown;
    // (See islandPowerSleep.)
    bool islandPowerLock;
    // (See islandPowerSleep.)
    bool islandPowerSignOut;
    // Restarting, shutting down and signing out ask first (see PowerAsks).
    bool islandPowerConfirm;
    // A shortcut (recorded, none until then) that makes the pill let clicks
    // through to what's under it while it stays shown (#6718; see
    // Island::SetClickThrough).
    bool islandClickThroughKey;
    // The island stays shown over borderless full-screen apps (#6740; exclusive
    // full screen draws over every window, see IsExclusiveFullscreen).
    bool islandOverFullscreen;
    // The calendar's events area under the month: the day's events, holidays
    // and the upcoming ones, and adding events (#6609). Off, only the clock and
    // the month; reminders and the countdown still use the events.
    bool islandCalendarEvents;
    // A panel opens when the mouse rests on its item a moment, and closes a
    // moment after the mouse leaves it and the pill (#6654). Only items whose
    // click just opens a panel (see Island::HoverPanel): never a button that
    // does something (a timer's start, media, a pinned command).
    bool islandHoverOpen;
    // A notch with nothing in it isn't shown (#6651): it comes back when an
    // item, a notice or a panel comes to it, and while items are dragged
    // between the notches in the settings. See Island::NotchGoneWanted.
    bool islandNotchHideEmpty;
    // A notification's long text stays on one line and scrolls under the mouse,
    // instead of opening on up to three lines (#6200; see BannerTextScrolls).
    bool islandBannerMarquee;
    // The see-through bar only on the desktop: its usual look while an app's
    // window is maximized on its monitor (#7005; see CheckBarClearWindow).
    bool islandBarClearDesktop;
    // The small pill with the time against the screen's edge, as thin as its
    // text (#6997; see HiddenClockRect).
    bool islandHideClockEdge;
    // Ctrl + drag on the island moves an item to another place on it, or into
    // another notch; with Ctrl held on the pill, its items jiggle (see
    // GroupDrag, Island::CheckOrderKeys).
    bool islandOrderDrag;
    // The apps launcher on the pill: its panel lists the Start menu's apps,
    // to search, open and keep as favorites (see LauncherPanel).
    bool islandLauncher;
    // Only the song's cover on the pill, without its title (#7038, see
    // Island::Layout and m_mediaTextRoom); under the cover and title option.
    bool islandMediaCoverOnly;
    // One switch for each kind of status notice, under the one for all of them
    // (islandStatusNotices): the charger plugged in (#7091).
    bool islandNoticeCharger;
    // The battery going under 20% and 10% (a status notice, #7091).
    bool islandNoticeLowBattery;
    // A Bluetooth audio device connecting (a status notice, #7091).
    bool islandNoticeBluetooth;
    // "Do not disturb" turned on or off (a status notice, #7091).
    bool islandNoticeDnd;
    // A virtual desktop switched to, as a short status notice with its number
    // and name (#7014; see Island::NoteDesktopSwitch).
    bool islandNoticeDesktop;
    // A click on the bell opens Windows' own notification center, not the
    // island's list (#7089; see Island::OpenWindowsNotifications).
    bool islandBellWindows;
    // The additional clocks aren't on the pill: the clock lists them under
    // the mouse (#7089; see Island::ItemTip).
    bool islandWorldClocksInClock;
    // VLC 3 shown from its window's title while it makes sound (#6164): it
    // tells no media controls what it plays (see AddVlcMedia,
    // Island::PollVlcTitle); under the What's playing option.
    bool islandVlcTitle;
    // What's playing on the minimized line (#7045): a thin pill with the
    // song's cover and the visualizer's bars instead of the line, while
    // something plays (see Island::MusicLineWanted).
    bool islandMusicLine;
    int islandNotchCurve;
    bool islandNotchEach;
    // Whose line opens the island (0 every one's, else 1 + the notch).
    int islandNotchOpen;
    // One icon on the pill for the notifications of one app, even when they
    // come under IDs of their own (see NotificationAppKey).
    bool islandGroupApps;
    // The apps with notifications on the pill (their icons and counts).
    bool islandApps;
    // komorebi's layout on the pill (its menu changes it), and the app in
    // focus on the island's monitor.
    bool komorebiLayout;
    bool islandFocusedApp;
    // komorebi's workspaces without windows left out of its dots (the one
    // shown always there).
    bool komorebiHideEmpty;
    bool islandVerticalSides;
    // The clock on the pill (on by default), kept in its middle (or the
    // bar's), and the power button (sleep, restart, shut down) on it.
    bool islandClock;
    bool islandClockCenter;
    bool islandPower;
    // Panels opening out of the pill as wide as it, when it's wider than
    // them (otherwise they drop out of the clicked item, at their own width).
    bool islandPanelsFollow;
    // A button switching Windows between light and dark mode, and how much
    // the processor, the memory and the video memory are used, on the pill.
    bool islandThemeButton;
    bool usageCpu;
    bool usageRam;
    bool usageVram;
    // A button muting the microphone, on the pill.
    bool islandMicrophone;
    // Public holidays in the calendar (goes online, see Holiday).
    bool calendarHolidays;
    // Notes, tasks and keyboard shortcuts, on the pill.
    bool islandNotes;
    bool islandTasks;
    bool islandShortcuts;
    // The weather on the pill (goes online, see WeatherThreadProc).
    bool islandWeather;
    // Updates (winget and Windows Update) on the pill.
    bool islandUpdates;
    // A button on the pill listing the settings' profiles.
    bool islandProfiles;
    // The island handles notifications itself (see UpdateWindowsQuiet).
    bool islandOwnsNotifications;
    // The island's size (its text, icons and width), in percent.
    int islandSize;
    // Its icons' own size (their room too, not the texts nor the island's
    // height), and its texts' own size, in percent.
    int islandIconSize;
    int islandTextSize;
    // The minimized line's opacity (percent; at 0 it's unseen, and the mouse
    // still brings the island back), the length of the strip along the edge
    // that brings it back (px at 100%), the panels' size (percent of the
    // screen's scaling) and the widest the playing title gets on the pill
    // (px at 100%).
    int islandLineOpacity;
    int islandActivationWidth;
    int islandPanelSize;
    // The pill's media buttons, and the media panel on top of the
    // panels' size, in % of the usual (#7041, see MediaButtonsFit and
    // MediaPanelScale).
    int islandMediaButtonsSize;
    int islandMediaPanelSize;
    int islandMediaTitleLimit;
    // The pill's height, how round its corners are and the room at its
    // ends, in % of the usual (see kPillHeightPctMin).
    int islandPillHeight;
    int islandPillCorners;
    int islandPillEnds;
    // How much the thin edge around the island, its panels, banners and
    // bubbles shows (glass's bright one too), in %; the minimized line keeps
    // its own.
    int islandEdge;
    // More blur on the glass than Windows' own, in % (0: Windows' own).
    int islandGlassBlur;
    // How many columns the tray's grid has (see TrayListPanel).
    int islandTrayColumns;
    // How much the visualizer's bars move, in % (see StepVisualizer).
    int islandVizSensitivity;
    // The visualizer's bars: their height, width and the room between
    // them, in % of the usual (#6924, see VizBarsLook).
    int islandVizHeight;
    int islandVizWidth;
    int islandVizSpacing;
    // The room between the island and the screen's edges (px at 100%).
    int islandGap;
    // On the monitor where the mouse is (several monitors).
    bool islandFollowMouse;
    double magnification;
    double magnificationRange;
    // The magnification, the bounces and hideWhen on the Windows taskbar
    // with only its apps too (see AppsTaskbarEffects).
    bool onlyAppsEffects;
    // The widest the dock gets, in % of its monitor (0: no limit): a box
    // past that, scrolled by the wheel (see g_dockScroll).
    int dockMaxWidth;
    bool bounceOnLaunch;
    bool keepOpenOnLaunch;
    int keepOpenDuration;
    bool dotIndicator;
    // A thin line between the dock's pinned apps and the others
    // (dock.separator).
    bool dockSeparator;
    AttentionMode attentionMode;
} g_settings;

// The island's colors: its background, and its foreground (texts, icons and
// the light fills over the background, drawn with some transparency).
struct IslandTheme {
    float background[3] = {0, 0, 0};
    // How opaque the background is (glass lets the windows show through).
    float backgroundAlpha = 1;
    float foreground[3] = {1, 1, 1};
    // The pill's icons (the texts' color, but in the custom colors).
    float icon[3] = {1, 1, 1};
    // Dark text on a light background needs more of it to read well (0 to 1,
    // in between while the colors change).
    float light = 0;
};
// The colors shown (blending from one theme to another while they change).
IslandTheme g_theme;
// The colors chosen, and the ones a change started from.
IslandTheme g_themeTarget, g_themeFrom;
// When the colors started changing (NowSeconds), or 0.
double g_themeChangeStart;
// Whether the colors changed on the island's last frame (the panels draw
// again too).
bool g_themeChanging;

// The foreground with an opacity.
D2D1_COLOR_F Fg(float alpha) {
    // On the light theme, texts and icons (drawn at 0.35 and up) get darker;
    // the light fills under them stay as they are.
    if (g_theme.light > 0 && alpha >= 0.35f) {
        alpha += (std::min(1.0f, 0.55f + alpha * 0.5f) - alpha) * g_theme.light;
    }
    return {g_theme.foreground[0], g_theme.foreground[1],
            g_theme.foreground[2], alpha};
}

// How opaque the backgrounds are, in percent (the island's settings): what's
// behind shows through below 100. Texts and icons stay as they are.
constexpr int kIslandOpacityMin = 30;
constexpr int kIslandOpacityMax = 100;
constexpr int kIslandOpacityDefault = 100;
constexpr int kIslandOpacityStep = 5;
int g_islandOpacity = kIslandOpacityDefault;

// The background with an opacity (times the theme's own, and the chosen
// one).
D2D1_COLOR_F Bg(float alpha) {
    return {g_theme.background[0], g_theme.background[1],
            g_theme.background[2],
            alpha * g_theme.backgroundAlpha * g_islandOpacity / 100.0f};
}

// The background with only this opacity (not the chosen one): the bubbles
// that ask or tell something (their texts over what's behind didn't read).
D2D1_COLOR_F BgSolid(float alpha) {
    return {g_theme.background[0], g_theme.background[1],
            g_theme.background[2], alpha};
}

// The pill's icons with an opacity (like Fg, in their own color).
D2D1_COLOR_F FgIcon(float alpha) {
    const D2D1_COLOR_F text = Fg(alpha);
    return {g_theme.icon[0], g_theme.icon[1], g_theme.icon[2], text.a};
}

// The themes, in the order the island's settings show them.
// Auto: black in dark mode, light in light mode (Windows' apps mode);
// inverted, the other way around. Custom: the colors chosen (see
// g_customColors).
enum class ThemeId {
    Black,
    Graphite,
    Light,
    Accent,
    Glass,
    Auto,
    AutoInverted,
    Custom,
    Count
};
int g_themeIndex;

// The color of the app in front (0xRRGGBB, see WindowColor), or -1: the
// island's background takes it when chosen (islandWindowColor).
int g_windowColor = -1;
int WindowColor(HWND hWnd);

// The island in the app in front's colors now (its highlight follows the
// icons' tint, like with your own colors).
bool UsesWindowColor() {
    return g_settings.islandWindowColor && g_windowColor >= 0;
}

// The custom colors (0xRRGGBB): the background, the texts and the pill's
// icons, chosen in the island's settings with Windows' color dialog.
enum CustomColor { kColorBackground, kColorText, kColorIcons, kCustomColors };
constexpr PCWSTR kCustomColorKeys[kCustomColors] = {
    L"islandColorBackground", L"islandColorText", L"islandColorIcons"};
constexpr int kCustomColorDefaults[kCustomColors] = {0x1C1C1E, 0xFFFFFF,
                                                     0x64D2FF};
// (Not one of them: the color dialogs for the pill's fill's own colors, one
// a kind, see kFillDownloads; the song lyrics', the visualizer's and an
// icon's own colors.)
constexpr int kFillColorDialog = kCustomColors;
constexpr int kLyricsColorDialog = kFillColorDialog + 3;
constexpr int kVisualizerColorDialog = kLyricsColorDialog + 1;
// (And an icon's own color: this plus its code.)
constexpr int kIconColorDialog = kVisualizerColorDialog + 1;
std::array<int, kCustomColors> g_customColors = {
    kCustomColorDefaults[0], kCustomColorDefaults[1], kCustomColorDefaults[2]};

void LoadCustomColors() {
    for (int i = 0; i < kCustomColors; i++) {
        g_customColors[i] =
            Wh_GetIntValue(kCustomColorKeys[i], kCustomColorDefaults[i]) &
            0xFFFFFF;
    }
}

// A custom color's red, green and blue, from 0 to 1.
void CustomColorParts(int color, float parts[3]) {
    parts[0] = ((color >> 16) & 0xFF) / 255.0f;
    parts[1] = ((color >> 8) & 0xFF) / 255.0f;
    parts[2] = (color & 0xFF) / 255.0f;
}

float Luminance(float r, float g, float b) {
    return 0.299f * r + 0.587f * g + 0.114f * b;
}

// How easy one color is to read on another (0xRRGGBB): the contrast ratio
// of the web's accessibility guidelines (WCAG), from 1 (the same) to 21.
float ContrastRatio(int a, int b) {
    auto relative = [](int color) {
        float parts[3];
        CustomColorParts(color, parts);
        for (float& value : parts) {
            value = value <= 0.04045f ? value / 12.92f
                                      : std::pow((value + 0.055f) / 1.055f,
                                                 2.4f);
        }
        return 0.2126f * parts[0] + 0.7152f * parts[1] + 0.0722f * parts[2];
    };
    float lighter = relative(a);
    float darker = relative(b);
    if (lighter < darker) {
        std::swap(lighter, darker);
    }
    return (lighter + 0.05f) / (darker + 0.05f);
}

// One of your own colors hard to see on the background: the texts or the
// icons (the guidelines' minimum for big texts and for icons: 3 and 2).
bool CustomColorHardToRead(int color) {
    const int background = g_customColors[kColorBackground];
    return color == kColorText
               ? ContrastRatio(g_customColors[kColorText], background) < 3
           : color == kColorIcons
               ? ContrastRatio(g_customColors[kColorIcons], background) < 2
               : false;
}

bool CustomColorsHardToRead() {
    return CustomColorHardToRead(kColorText) ||
           CustomColorHardToRead(kColorIcons);
}

// The highlight (switches and buttons on, the one chosen, a field being
// typed in): Windows' blue, or with your own colors, the icons' color made
// stronger (as vivid as it goes on a dark background, deeper on a light
// one), and pushed away from the background when they're too alike.
D2D1_COLOR_F Accent(float alpha) {
    if (g_themeIndex != (int)ThemeId::Custom && !UsesWindowColor()) {
        return {0.04f, 0.52f, 1.0f, alpha};
    }
    const float* back = g_theme.background;
    const float background = Luminance(back[0], back[1], back[2]);
    float c[3] = {g_theme.icon[0], g_theme.icon[1], g_theme.icon[2]};
    const float top = std::max({c[0], c[1], c[2]});
    for (float& value : c) {
        value = background >= 0.5f ? value * 0.75f
                : top > 0.01f      ? value / top
                                   : 1.0f;
    }
    if (std::fabs(Luminance(c[0], c[1], c[2]) - background) < 0.3f) {
        const float away = background < 0.5f ? 1.0f : 0.0f;
        for (float& value : c) {
            value += (away - value) * 0.5f;
        }
    }
    return {c[0], c[1], c[2], alpha};
}

// The highlight a bit lighter under the mouse (`lit` from 0 to 1).
D2D1_COLOR_F AccentLit(float alpha, float lit) {
    D2D1_COLOR_F color = Accent(alpha);
    color.r += (1 - color.r) * 0.12f * lit;
    color.g += (1 - color.g) * 0.1f * lit;
    return color;
}

// What's written on the highlight: white, or dark on a light one.
D2D1_COLOR_F AccentInk(float alpha) {
    const D2D1_COLOR_F accent = Accent(1);
    const float ink =
        Luminance(accent.r, accent.g, accent.b) > 0.62f ? 0.08f : 1.0f;
    return {ink, ink, ink, alpha};
}

// A switch's knob: white, turning to the highlight's ink as it goes on.
D2D1_COLOR_F KnobColor(float on) {
    const D2D1_COLOR_F ink = AccentInk(1);
    const float t = std::clamp(on, 0.0f, 1.0f);
    return {1 + (ink.r - 1) * t, 1 + (ink.g - 1) * t, 1 + (ink.b - 1) * t, 1};
}

double NowSeconds();

// How the mod animates (see LoadAnimationSettings), in both processes: the
// level (0 all, 1 partial: no bounces nor decorations, 2 none), the speed in
// percent, and the frame rate limit (0 the screen's, or frames a second).
std::atomic<int> g_animationLevel{0};
std::atomic<int> g_animationSpeed{100};
std::atomic<int> g_frameRateLimit{0};

int AnimationLevel() {
    return g_animationLevel.load(std::memory_order_relaxed);
}

// A real time step, as the animations take it (faster or slower).
double AnimationDt(double dt) {
    return dt * g_animationSpeed.load(std::memory_order_relaxed) / 100.0;
}

// How long a timed animation lasts at the chosen speed: 0 without
// animations, and for a decoration (a glow, a color blend, a number
// counting...) at the "partial" level too.
double AnimationSeconds(double seconds, bool decoration = false) {
    const int level = AnimationLevel();
    if (level >= 2 || (decoration && level >= 1)) {
        return 0;
    }
    return seconds * 100.0 / g_animationSpeed.load(std::memory_order_relaxed);
}

// An animation's length in milliseconds at the chosen speed (0, at once,
// without animations).
int AnimationMs(int ms) {
    return (int)std::lround(AnimationSeconds(ms / 1000.0) * 1000);
}

// The animation settings as chosen: on, level (0 all, 1 partial, 2 none),
// speed (percent) and frame rate (0 the screen's, 1 about 90, 2 about 60, 3
// about 30).
struct AnimationChoice {
    int on = 1;
    int level = 0;
    int speed = 125;
    int rate = 0;
};
constexpr int kAnimationSpeedMin = 50;
constexpr int kAnimationSpeedMax = 200;
constexpr int kAnimationSpeedDefault = 125;
constexpr int kAnimationSpeedStep = 10;
constexpr int kFrameRates[] = {0, 90, 60, 30};
AnimationChoice g_animationChoice;

int EncodeAnimations(const AnimationChoice& choice) {
    return 1 + choice.on + choice.level * 2 + choice.rate * 8 +
           choice.speed * 32;
}

AnimationChoice DecodeAnimations(int code) {
    code--;
    return {code & 1, (code >> 1) & 3, code >> 5, (code >> 3) & 3};
}

AnimationChoice AnimationsFromWindhawk() {
    AnimationChoice choice;
    choice.on = Wh_GetIntSetting(L"animations.enabled") != 0;
    const auto level = WindhawkUtils::StringSetting::make(L"animations.level");
    choice.level = wcscmp(level, L"partial") == 0 ? 1
                   : wcscmp(level, L"none") == 0  ? 2
                                                  : 0;
    choice.speed = Wh_GetIntSetting(L"animations.speed");
    const auto rate =
        WindhawkUtils::StringSetting::make(L"animations.frameRate");
    choice.rate = wcscmp(rate, L"fps90") == 0   ? 1
                  : wcscmp(rate, L"fps60") == 0 ? 2
                  : wcscmp(rate, L"fps30") == 0 ? 3
                                                : 0;
    return choice;
}

void ApplyAnimationChoice(AnimationChoice choice) {
    choice.on = choice.on ? 1 : 0;
    choice.level = std::clamp(choice.level, 0, 2);
    choice.speed =
        std::clamp(choice.speed, kAnimationSpeedMin, kAnimationSpeedMax);
    choice.rate = std::clamp(choice.rate, 0, 3);
    g_animationChoice = choice;
    g_animationLevel = choice.on ? choice.level : 2;
    g_animationSpeed = choice.speed;
    g_frameRateLimit = kFrameRates[choice.rate];
}

// Explorer (set first thing in Wh_ModInit), rather than the island's process.
bool g_isExplorer;

// The dock animates as Windhawk's settings say, the island as its own
// settings say. The island's start as Windhawk's were (they were the same
// ones up to 1.0), kept then.
void LoadAnimationSettings() {
    if (g_isExplorer) {
        ApplyAnimationChoice(AnimationsFromWindhawk());
        return;
    }
    int island = Wh_GetIntValue(L"animationsIsland", 0);
    if (island <= 0) {
        island = EncodeAnimations(AnimationsFromWindhawk());
        Wh_SetIntValue(L"animationsIsland", island);
    }
    ApplyAnimationChoice(DecodeAnimations(island));
}

// A setting a profile keeps (see CaptureProfile), stored: the profile in use
// takes it too, a moment later (see SaveActiveProfileSoon).
void SaveActiveProfileSoon();
// Whether the current island shows a profile of its own (another monitor's,
// see Island::SaveOwnProfile), and whether a stored value is part of what it
// shows (not what every island shares, see IsSharedPref).
bool OwnLookShown();
// Whether the island shown (its settings, its panels) is another
// monitor's, not the main one (see Island::HasMainSettings).
bool OtherIslandShown();
bool IsLookValue(PCWSTR name);
// The current island's own profile saved a moment later.
void SaveOwnLookSoon();
// Windhawk's portable storage (a file of its own) loses a stored text's line
// breaks: there they're stored as kStoredLineBreak instead, and read back as
// line breaks wherever stored (see GetStringValueIn). Asked once a process,
// by a text written and read back (named after the process: the island's
// and Explorer's ask at the same time).
constexpr WCHAR kStoredLineBreak = 0x1E;
bool StorageKeepsLineBreaks() {
    static const bool keeps = [] {
        const std::wstring probe =
            L"lineBreakProbe" + std::to_wstring(GetCurrentProcessId());
        Wh_SetStringValue(probe.c_str(), L"a\nb");
        WCHAR back[8] = L"";
        Wh_GetStringValue(probe.c_str(), back, ARRAYSIZE(back));
        Wh_DeleteValue(probe.c_str());
        return wcscmp(back, L"a\nb") == 0;
    }();
    return keeps;
}

// A text stored (see StorageKeepsLineBreaks).
void SetStoredString(PCWSTR name, PCWSTR value) {
    if (!wcschr(value, L'\n') || StorageKeepsLineBreaks()) {
        Wh_SetStringValue(name, value);
        return;
    }
    std::wstring kept(value);
    std::replace(kept.begin(), kept.end(), L'\n', kStoredLineBreak);
    Wh_SetStringValue(name, kept.c_str());
}

// A value of the island's settings: in the main settings (and the profile in
// use there), or, on an island showing a profile of its own, in that
// profile instead.
void StoreProfileInt(PCWSTR name, int value) {
    if (OwnLookShown() && IsLookValue(name)) {
        SaveOwnLookSoon();
        return;
    }
    Wh_SetIntValue(name, value);
    SaveActiveProfileSoon();
}
void StoreProfileString(PCWSTR name, PCWSTR value) {
    if (OwnLookShown() &&
        (wcscmp(name, L"islandOrder") == 0 ||
         wcscmp(name, L"islandNotchSides") == 0 ||
         wcscmp(name, L"trayPinned") == 0 || wcscmp(name, L"trayOrder") == 0 ||
         wcscmp(name, L"trayAnchors") == 0 ||
         wcscmp(name, L"islandIconFolder") == 0 ||
         wcscmp(name, L"islandIconFiles") == 0 ||
         wcscmp(name, L"islandTextFont") == 0 ||
         wcscmp(name, L"islandClockFont") == 0)) {
        SaveOwnLookSoon();
        return;
    }
    SetStoredString(name, value);
    SaveActiveProfileSoon();
}

// Changed in the island (`keep`: saved, not only shown while sliding).
void SetAnimationChoice(const AnimationChoice& choice, bool keep) {
    ApplyAnimationChoice(choice);
    if (keep) {
        StoreProfileInt(L"animationsIsland",
                        EncodeAnimations(g_animationChoice));
    }
}

// Moves `value` towards `target` like a spring, over about `seconds`.
// `damping` 1 settles without overshooting; lower values bounce a little, like
// the iPhone's Dynamic Island. Returns true while it's still moving.
bool SpringTowards(double& value, double& velocity, double target,
                   double seconds, double dt, double damping = 1.0) {
    // Without animations, it's there at once (told as moving that once:
    // what follows it, like a layout, still goes there); at the "partial"
    // level, it doesn't bounce.
    const int level = AnimationLevel();
    if (level >= 2) {
        const bool jumped = value != target || velocity != 0;
        value = target;
        velocity = 0;
        return jumped;
    }
    if (level == 1) {
        damping = std::max(damping, 1.0);
    }
    const double omega = 8.0 / seconds;
    constexpr double kStep = 1.0 / 480;
    for (double remaining = dt; remaining > 0; remaining -= kStep) {
        const double h = std::min(remaining, kStep);
        const double acceleration = omega * omega * (target - value) -
                                    2 * damping * omega * velocity;
        velocity += acceleration * h;
        value += velocity * h;
    }
    if (std::fabs(target - value) < 0.001 && std::fabs(velocity) < 0.01) {
        value = target;
        velocity = 0;
        return false;
    }
    return true;
}

// A decoration (a glow, a crossfade, an icon turning): like SpringTowards,
// but there at once from the "partial" level on (told as moving that once,
// like SpringTowards without animations).
bool SpringDecoration(double& value, double& velocity, double target,
                      double seconds, double dt, double damping = 1.0) {
    if (AnimationLevel() >= 1) {
        const bool jumped = value != target || velocity != 0;
        value = target;
        velocity = 0;
        return jumped;
    }
    return SpringTowards(value, velocity, target, seconds, dt, damping);
}

bool IsDarkMode();

// Reads the chosen theme. Chosen in the island (or Windows' mode switched
// with the automatic one), the colors blend into it (see StepTheme);
// otherwise, they're there right away.
void ApplyThemeIndex(bool blend);

void LoadTheme(bool blend = false) {
    g_themeIndex =
        std::clamp(Wh_GetIntValue(L"islandTheme", 0), 0, (int)ThemeId::Count - 1);
    LoadCustomColors();
    ApplyThemeIndex(blend);
}

// The colors of the theme in g_themeIndex (see LoadTheme).
void ApplyThemeIndex(bool blend) {
    ThemeId theme = (ThemeId)g_themeIndex;
    if (theme == ThemeId::Auto) {
        theme = IsDarkMode() ? ThemeId::Black : ThemeId::Light;
    } else if (theme == ThemeId::AutoInverted) {
        theme = IsDarkMode() ? ThemeId::Light : ThemeId::Black;
    }
    IslandTheme& target = g_themeTarget;
    target = {};
    if (theme == ThemeId::Custom) {
        CustomColorParts(g_customColors[kColorBackground], target.background);
        CustomColorParts(g_customColors[kColorText], target.foreground);
        // A light background takes the light theme's darker texts.
        const float* b = target.background;
        target.light = Luminance(b[0], b[1], b[2]) > 0.6f;
    } else if (theme == ThemeId::Graphite) {
        target.background[0] = 0.17f;
        target.background[1] = 0.17f;
        target.background[2] = 0.19f;
    } else if (theme == ThemeId::Light) {
        target.background[0] = 0.96f;
        target.background[1] = 0.96f;
        target.background[2] = 0.97f;
        target.foreground[0] = 0.02f;
        target.foreground[1] = 0.02f;
        target.foreground[2] = 0.03f;
        target.light = 1;
    } else if (theme == ThemeId::Accent) {
        // Darkened, so white reads well on it.
        DWORD color = 0;
        BOOL opaque = FALSE;
        if (SUCCEEDED(DwmGetColorizationColor(&color, &opaque))) {
            target.background[0] = ((color >> 16) & 0xFF) / 255.0f * 0.55f;
            target.background[1] = ((color >> 8) & 0xFF) / 255.0f * 0.55f;
            target.background[2] = (color & 0xFF) / 255.0f * 0.55f;
        }
    } else if (theme == ThemeId::Glass) {
        // Frosted: a gray haze over what's behind, thick enough to read on
        // any window (a layered window can't blur what's behind it).
        target.background[0] = 0.19f;
        target.background[1] = 0.19f;
        target.background[2] = 0.21f;
        target.backgroundAlpha = 0.94f;
    }
    if (theme == ThemeId::Custom) {
        CustomColorParts(g_customColors[kColorIcons], target.icon);
    } else {
        std::copy(target.foreground, target.foreground + 3, target.icon);
    }
    // The app in front's color: the background darkened like the accent's
    // theme (so white texts read well on it), and the icons in a light tint
    // of it (white for a dark color).
    if (UsesWindowColor()) {
        float color[3];
        CustomColorParts(g_windowColor, color);
        const bool dark = Luminance(color[0], color[1], color[2]) < 0.25f;
        for (int i = 0; i < 3; i++) {
            target.background[i] = color[i] * 0.55f;
            target.foreground[i] = 1;
            target.icon[i] = dark ? 1 : color[i] + (1 - color[i]) * 0.45f;
        }
        target.light = 0;
        target.backgroundAlpha = 1;
    }
    if (blend) {
        g_themeFrom = g_theme;
        g_themeChangeStart = NowSeconds();
    } else {
        g_theme = target;
        g_themeChangeStart = 0;
    }
}

// How long the colors take to blend into another theme.
constexpr double kThemeChangeSeconds = 0.45;

// Blends the shown colors a step further into the chosen theme (eased in and
// out). Returns whether they changed.
bool StepTheme() {
    g_themeChanging = false;
    if (!g_themeChangeStart) {
        return false;
    }
    const double length = AnimationSeconds(kThemeChangeSeconds, true);
    const double t =
        length > 0 ? std::clamp((NowSeconds() - g_themeChangeStart) / length,
                                0.0, 1.0)
                   : 1.0;
    const float k = (float)(t < 0.5 ? 4 * t * t * t
                                    : 1 - std::pow(-2 * t + 2, 3) / 2);
    auto mix = [k](float a, float b) { return a + (b - a) * k; };
    for (int i = 0; i < 3; i++) {
        g_theme.background[i] =
            mix(g_themeFrom.background[i], g_themeTarget.background[i]);
        g_theme.foreground[i] =
            mix(g_themeFrom.foreground[i], g_themeTarget.foreground[i]);
        g_theme.icon[i] = mix(g_themeFrom.icon[i], g_themeTarget.icon[i]);
    }
    g_theme.backgroundAlpha =
        mix(g_themeFrom.backgroundAlpha, g_themeTarget.backgroundAlpha);
    g_theme.light = mix(g_themeFrom.light, g_themeTarget.light);
    if (t >= 1) {
        g_theme = g_themeTarget;
        g_themeChangeStart = 0;
    }
    g_themeChanging = true;
    return true;
}

// Whether the taskbar was at the bottom when the settings were read.
std::atomic<bool> g_taskbarAtBottom{true};

// Explorer: the main taskbar has none of the parts the dock styles
// (Taskbar.TaskbarFrame), as with Windows' newer taskbar on some Insider
// builds (#6888). The taskbar is then left as Windows draws it, like the
// unchanged mode, until a restyle finds them (see CheckDockAvailable).
std::atomic<bool> g_dockUnavailable;

// The mod's dock (otherwise, the Windows taskbar, and the mod only adds the
// island).
bool IsDock() {
    return g_settings.taskbarMode == decltype(g_settings.taskbarMode)::Dock &&
           !g_dockUnavailable;
}

// The Windows taskbar, transparent, with only its apps.
bool IsTransparentTaskbar() {
    return g_settings.taskbarMode ==
           decltype(g_settings.taskbarMode)::WindowsTransparent;
}

// The taskbar hides itself, and slides in and out with the mod's animation:
// the dock, and the transparent Windows taskbar (at the bottom: on the other
// edges it stays as Windows has it, only transparent).
bool SlidesItself() {
    return IsDock() || (IsTransparentTaskbar() && g_taskbarAtBottom);
}

// The Windows taskbar with only its apps, with the dock's effects too
// (icons.onlyApps, at the bottom): its icons grow inside its height and
// bounce, and it hides when a window is in its way (with Windows' own
// auto-hide).
bool AppsTaskbarEffects() {
    return g_settings.taskbarMode ==
               decltype(g_settings.taskbarMode)::WindowsApps &&
           g_settings.onlyAppsEffects && g_taskbarAtBottom;
}

// The icons grow under the mouse and bounce: the dock, and the transparent
// Windows taskbar too (at the bottom), and the one with only its apps with
// that option.
bool AnimatesIcons() {
    return SlidesItself() || AppsTaskbarEffects();
}

// The transparent taskbar's soft shadow, rising from the bottom edge: a bit
// stronger over light windows (measured as it shows) and under the mouse.
std::atomic<double> g_backdropLight{0.5};

std::atomic<bool> g_unloading;

// The account's SID as text (empty if it can't be read).
const std::wstring& UserSid() {
    static const std::wstring sid = [] {
        std::wstring sid;
        HANDLE token = nullptr;
        if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) {
            alignas(TOKEN_USER) BYTE
                buffer[sizeof(TOKEN_USER) + SECURITY_MAX_SID_SIZE];
            DWORD size = 0;
            LPWSTR text = nullptr;
            if (GetTokenInformation(token, TokenUser, buffer, sizeof(buffer),
                                    &size) &&
                ConvertSidToStringSid(((TOKEN_USER*)buffer)->User.Sid,
                                      &text)) {
                sid = text;
                LocalFree(text);
            }
            CloseHandle(token);
        }
        return sid;
    }();
    return sid;
}

// The mod's storage is the computer's, shared by its accounts: what one
// account's session changed in Windows (its auto-hide, its Do not disturb),
// its explorer.exe part and what describes its own Windows (its
// notifications cleared here, its tray icons kept across a reload) are kept
// under a name with the account's SID, so another account never undoes or
// reads them. Values kept before under the plain name
// are read once and moved.
std::wstring UserValueName(PCWSTR name) {
    const std::wstring& sid = UserSid();
    return sid.empty() ? std::wstring(name) : name + (L"_" + sid);
}

// (`shared`: a value every account used before 2.1, like the timer's
// lengths: copied, not moved, so each account starts from it once.)
int GetUserIntValue(PCWSTR name, int defaultValue, bool shared = false) {
    const std::wstring userName = UserValueName(name);
    constexpr int kMissing = INT_MIN;
    const int value = Wh_GetIntValue(userName.c_str(), kMissing);
    if (value != kMissing) {
        return value;
    }
    const int legacy = Wh_GetIntValue(name, kMissing);
    if (legacy == kMissing || userName == name) {
        return defaultValue;
    }
    Wh_SetIntValue(userName.c_str(), legacy);
    if (!shared) {
        Wh_DeleteValue(name);
    }
    return legacy;
}

void SetUserIntValue(PCWSTR name, int value) {
    Wh_SetIntValue(UserValueName(name).c_str(), value);
}

// A stored text in a buffer of `size` characters (empty when it doesn't fit,
// like a missing one), its line breaks as written (see SetStoredString).
std::wstring GetStringValueIn(PCWSTR name, size_t size) {
    const auto value = std::make_unique_for_overwrite<WCHAR[]>(size);
    std::wstring text =
        Wh_GetStringValue(name, value.get(), size) ? value.get() : L"";
    std::replace(text.begin(), text.end(), kStoredLineBreak, L'\n');
    return text;
}

// A stored text, whole: Wh_GetStringValue reads a value larger than the
// buffer as empty, so a larger one is tried, up to 16 times `room` (the usual
// size; no stored text grows that far). A missing value costs those reads
// too: not for a value read often.
std::wstring GetWholeStringValue(PCWSTR name, size_t room) {
    const size_t most = std::max(room, std::min(room * 16, (size_t)1 << 20));
    for (size_t size = room; size <= most; size *= 2) {
        std::wstring value = GetStringValueIn(name, size);
        if (!value.empty()) {
            return value;
        }
    }
    return L"";
}

// Read once (on Explorer's taskbar thread too): its writers keep it within
// `room` (the kept tray icons, the cleared and dismissed notifications).
std::wstring GetUserStringValue(PCWSTR name, size_t room) {
    const std::wstring userName = UserValueName(name);
    std::wstring value = GetStringValueIn(userName.c_str(), room);
    if (!value.empty() || userName == name) {
        return value;
    }
    value = GetStringValueIn(name, room);
    if (!value.empty()) {
        SetStoredString(userName.c_str(), value.c_str());
        Wh_DeleteValue(name);
    }
    return value;
}

void SetUserStringValue(PCWSTR name, PCWSTR value) {
    SetStoredString(UserValueName(name).c_str(), value);
}

// The mark that the account has its own copy of a text every account used
// before 2.1 (see GetWholeUserStringValue), even an empty one.
std::wstring UserSeededName(PCWSTR name) {
    return UserValueName((std::wstring(name) + L"Seeded").c_str());
}

// The account's own text, whole (see GetWholeStringValue). The alarms and
// the folders' pins and looks were every account's before 2.1: the text kept
// under the plain name is copied, not moved, so each account starts from
// it, once (its mark then: an account that emptied its own doesn't get the
// old one back).
std::wstring GetWholeUserStringValue(PCWSTR name, size_t room) {
    const std::wstring userName = UserValueName(name);
    std::wstring value = GetWholeStringValue(userName.c_str(), room);
    if (!value.empty() || userName == name) {
        return value;
    }
    const std::wstring seeded = UserSeededName(name);
    if (Wh_GetIntValue(seeded.c_str(), 0)) {
        return value;
    }
    Wh_SetIntValue(seeded.c_str(), 1);
    value = GetWholeStringValue(name, room);
    if (!value.empty()) {
        SetStoredString(userName.c_str(), value.c_str());
    }
    return value;
}

// A first install, on this account: nothing of the island stored yet (its
// animations' value is stored as it first starts, see
// LoadAnimationSettings), What's new never told and the setup assistant
// never shown.
bool FirstInstall() {
    return Wh_GetIntValue(L"animationsIsland", 0) <= 0 &&
           GetUserStringValue(L"whatsNewTold", 32).empty() &&
           GetUserStringValue(L"setupDone", 32).empty();
}
// Read as the tool mod starts (before that value is stored), until the
// setup assistant opens (see Island::OpenSetup).
bool g_firstInstall;

// The mod's own module (set in Wh_ModInit), for its window classes.
HMODULE g_module;

// Runs `f`, keeping its errors from reaching the code that called it: XAML
// calls throw when an element isn't ready (the taskbar hiding for a
// full-screen app, for one), and an exception left uncaught in code that
// Windows calls (hooks, window procedures, XAML events) ends Explorer.
template <typename F>
void Safely(PCWSTR what, F&& f) {
    try {
        f();
    } catch (winrt::hresult_error const& e) {
        IslandLog(L"%s failed: %08X", what, (unsigned)e.code());
    } catch (...) {
        IslandLog(L"%s failed", what);
    }
}

double NowSeconds() {
    static const double frequency = [] {
        LARGE_INTEGER f;
        QueryPerformanceFrequency(&f);
        return (double)f.QuadPart;
    }();
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    return counter.QuadPart / frequency;
}

// When a taskbar button last started flashing (an app asking for attention),
// in NowSeconds() time.
std::atomic<double> g_lastFlashTime{0};
// Where the button of the app that last asked for attention is, horizontally,
// in screen pixels, and when that was measured (see RecordAttentionButton).
std::atomic<int> g_attentionButtonX{0};
std::atomic<double> g_attentionButtonTime{0};

// Until when the dock stays up no matter what, in NowSeconds() time, while an
// app clicked in it opens (see KeepDockShown).
std::atomic<double> g_keepShownUntil{0};
// The taskbar it's for (the other monitors' hide as usual). Taskbar thread
// only.
HWND g_keepShownWnd;

// Whether `taskbar` is the dock kept up for an app opening (see
// KeepDockShown): not another monitor's.
bool IsKeptShown(HWND taskbar) {
    return taskbar && taskbar == g_keepShownWnd &&
           NowSeconds() < g_keepShownUntil;
}

// Bounces come in groups of three, each one a little lower, like on macOS.
// Opening an app and asking for attention are one group each.
constexpr double kBounceTime = 0.42;
constexpr double kBounceGroupPause = 0.25;
constexpr int kBouncesPerGroup = 3;
constexpr double kBounceGroupLength =
    kBouncesPerGroup * kBounceTime + kBounceGroupPause;
constexpr int kLaunchBounceGroups = 1;
constexpr int kAttentionBounceGroups = 1;

// Height of a bounce sequence `elapsed` seconds into it, from 0 (resting) to
// 1 (highest). Each bounce is a parabola, like a thrown object. Sets `done`
// when the sequence is over.
double BounceSequence(double elapsed, int groups, bool* done) {
    *done = false;
    const int group = (int)(elapsed / kBounceGroupLength);
    if (group >= groups) {
        *done = true;
        return 0;
    }
    const double inGroup = elapsed - group * kBounceGroupLength;
    const int bounce = (int)(inGroup / kBounceTime);
    if (bounce >= kBouncesPerGroup) {
        return 0;  // The pause between groups.
    }
    const double phase = (inGroup - bounce * kBounceTime) / kBounceTime;
    return (1.0 - 0.18 * bounce) * 4 * phase * (1 - phase);
}

// Whether the mod turned auto-hide on, so it's turned off again on unload.
bool g_turnedAutoHideOn;

// The taskbar's internal timers: hiding after the mouse leaves, and showing
// after the mouse reaches the edge.
constexpr UINT_PTR kHideTimerId = 2;
constexpr UINT_PTR kUnhideTimerId = 3;

BOOL CALLBACK FindTaskbarProc(HWND hWnd, LPARAM lParam) {
    DWORD dwProcessId;
    WCHAR className[32];
    if (GetWindowThreadProcessId(hWnd, &dwProcessId) &&
        dwProcessId == GetCurrentProcessId() &&
        GetClassName(hWnd, className, ARRAYSIZE(className)) &&
        _wcsicmp(className, L"Shell_TrayWnd") == 0) {
        *reinterpret_cast<HWND*>(lParam) = hWnd;
        return FALSE;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////
// Finding the taskbar's XAML elements.

HWND FindCurrentProcessTaskbarWnd() {
    HWND hTaskbarWnd = nullptr;
    EnumWindows(
        FindTaskbarProc,
        reinterpret_cast<LPARAM>(&hTaskbarWnd));
    return hTaskbarWnd;
}

// There can be more than one explorer.exe (folders can open in a process of
// their own): only the one with the taskbar runs the watchers and the
// auto-hide setting.
// This process's main taskbar window, remembered (the sender of the
// island's messages).
std::atomic<HWND> g_ownTaskbarWnd;

HWND OwnTaskbarWnd() {
    HWND hWnd = g_ownTaskbarWnd;
    if (!hWnd || !IsWindow(hWnd)) {
        hWnd = FindCurrentProcessTaskbarWnd();
        g_ownTaskbarWnd = hWnd;
    }
    return hWnd;
}

bool OwnsTaskbar() {
    return FindCurrentProcessTaskbarWnd() != nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// The mod runs in two processes (see the tool mod implementation at the end):
// in explorer.exe, the dock and what only the taskbar knows (the apps' badges,
// the tray icons the apps send it); in a windhawk.exe process of its own, the
// island, so that nothing in it can take the shell down. They tell each other
// what changed with WM_COPYDATA, tagged, never waiting long for each other.

constexpr WCHAR kIslandClassName[] = L"WindhawkMacIslandDockIsland";
constexpr WCHAR kPanelClassName[] = L"WindhawkMacIslandDockPanel";
// The notification watcher's message-only window (the sender of the apps
// with new notifications, with the island off too).
constexpr WCHAR kNotifierClassName[] = L"WindhawkMacIslandDockNotifier";

enum IpcKind : ULONG_PTR {
    // Explorer to the island: the apps with a badge ('\n'-separated IDs).
    kIpcBadgeApps = 0x4D494401,
    // Explorer to the island: the tray icons (see SendTrayIcons).
    kIpcTrayIcons,
    // The island to explorer: it started, send everything.
    kIpcHello,
    // The island to explorer: where the tray icons are on the screen.
    kIpcTrayPlaces,
    // The island to explorer: apps with a new notification ('\n'-separated
    // IDs), so their icons bounce.
    kIpcNotifiedApps,
    // The island to explorer: an app's icon (an int size, then its ID). The
    // answer is the icon (an HICON), kept by explorer: the island copies it.
    // The shell gives packaged apps' icons in explorer, not always in the
    // island's process.
    kIpcAppIcon,
    // The island to explorer: whether an island fills with the apps'
    // progress (an int, 1 or 0): the taskbar's bars are watched only then.
    kIpcProgressWanted,
};
constexpr UINT kIpcTimeoutMs = 400;
// The ID the Widgets button's badge goes to the island under (its
// AutomationId; the Widgets board has news): it isn't an app, so the island
// shows it with its own name and icon, and a click opens the board.
constexpr WCHAR kWidgetsBadgeId[] = L"WidgetsButton";

// In explorer (the taskbar's thread), messages sent to it from other threads
// wait meanwhile (SMTO_BLOCK): the mod's own unloading sends it some (see
// ExplorerModBeforeUninit), and they must not run while this code is still
// on its stack. True once delivered; what the other side answered in
// `answer` (TRUE when the mod's part there took it: the taskbar not yet
// subclassed, after Explorer started again, answers something else).
bool SendIpc(HWND to,
             HWND from,
             IpcKind kind,
             const void* data,
             DWORD size,
             DWORD_PTR* answer = nullptr) {
    if (!to) {
        return false;
    }
    COPYDATASTRUCT copyData{kind, size, (PVOID)data};
    DWORD_PTR result = 0;
    const bool sent =
        SendMessageTimeout(to, WM_COPYDATA, (WPARAM)from, (LPARAM)&copyData,
                           SMTO_ABORTIFHUNG | SMTO_ERRORONEXIT |
                               (g_isExplorer ? SMTO_BLOCK : 0),
                           kIpcTimeoutMs, &result) != 0;
    if (answer) {
        *answer = sent ? result : 0;
    }
    return sent;
}

// The island's tray icon places, to explorer from a thread of their own: the
// taskbar may be busy for a moment (a window coming to the front, a panel
// opening), and the island's frames don't wait for it. Only the latest
// places are sent.
HWND FindTaskbarWnd();

struct TrayPlacesSender {
    SRWLOCK lock = SRWLOCK_INIT;
    CONDITION_VARIABLE wake = CONDITION_VARIABLE_INIT;
    std::vector<BYTE> pending;
    HWND from = nullptr;
    bool queued = false;
    bool stopping = false;
    HANDLE thread = nullptr;
};
TrayPlacesSender g_trayPlacesSender;

DWORD WINAPI TrayPlacesThreadProc(LPVOID) {
    TrayPlacesSender& sender = g_trayPlacesSender;
    for (;;) {
        AcquireSRWLockExclusive(&sender.lock);
        while (!sender.queued && !sender.stopping) {
            SleepConditionVariableSRW(&sender.wake, &sender.lock, INFINITE, 0);
        }
        if (sender.stopping) {
            ReleaseSRWLockExclusive(&sender.lock);
            return 0;
        }
        std::vector<BYTE> bytes = std::move(sender.pending);
        const HWND from = sender.from;
        sender.queued = false;
        ReleaseSRWLockExclusive(&sender.lock);
        SendIpc(FindTaskbarWnd(), from, kIpcTrayPlaces, bytes.data(),
                (DWORD)bytes.size());
    }
}

// (Not once stopped, until the main island is created again: an island
// going away after the main one doesn't start it again.)
void AllowTrayPlaces() {
    TrayPlacesSender& sender = g_trayPlacesSender;
    AcquireSRWLockExclusive(&sender.lock);
    sender.stopping = false;
    ReleaseSRWLockExclusive(&sender.lock);
}

void QueueTrayPlaces(HWND from, const std::vector<BYTE>& bytes) {
    TrayPlacesSender& sender = g_trayPlacesSender;
    AcquireSRWLockExclusive(&sender.lock);
    if (sender.stopping) {
        ReleaseSRWLockExclusive(&sender.lock);
        return;
    }
    sender.pending = bytes;
    sender.from = from;
    sender.queued = true;
    if (!sender.thread) {
        sender.thread =
            CreateThread(nullptr, 0, TrayPlacesThreadProc, nullptr, 0, nullptr);
    }
    ReleaseSRWLockExclusive(&sender.lock);
    WakeConditionVariable(&sender.wake);
}

void StopTrayPlacesSender() {
    TrayPlacesSender& sender = g_trayPlacesSender;
    AcquireSRWLockExclusive(&sender.lock);
    const HANDLE thread = sender.thread;
    sender.thread = nullptr;
    sender.stopping = true;
    sender.queued = false;
    sender.pending.clear();
    ReleaseSRWLockExclusive(&sender.lock);
    WakeConditionVariable(&sender.wake);
    if (thread) {
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
    }
}

// Whether a WM_COPYDATA came from the other part of the mod: the island's
// window (in explorer), or the taskbar (in the island's process).
bool IsIpcSender(HWND sender, PCWSTR className) {
    WCHAR name[64];
    return sender && GetClassName(sender, name, ARRAYSIZE(name)) &&
           wcscmp(name, className) == 0;
}

HWND FindIslandWnd() {
    return FindWindow(kIslandClassName, nullptr);
}

// The main taskbar, from any process.
HWND FindTaskbarWnd() {
    return FindWindow(L"Shell_TrayWnd", nullptr);
}

// Told to the taskbar by the island when it sees the monitors changed (see
// Island::Tick): restyled as after WM_DISPLAYCHANGE, which can be missed.
UINT DisplayChangedMessage() {
    static const UINT message =
        RegisterWindowMessage(L"WindhawkMacIslandDock_DisplayChanged");
    return message;
}

// Where Windows keeps the taskbar's edge (as for TaskbarEdge), read without
// asking the taskbar. Read again at most twice a second: the island lays
// itself out, and the taskbars find their monitor, with every frame.
UINT StoredTaskbarEdge() {
    static std::atomic<ULONGLONG> readAt{0};
    static std::atomic<UINT> stored{ABE_BOTTOM};
    const ULONGLONG now = GetTickCount64();
    const ULONGLONG last = readAt.load(std::memory_order_relaxed);
    if (last && now - last < 500) {
        return stored.load(std::memory_order_relaxed);
    }
    UINT edge = ABE_BOTTOM;
    BYTE data[64];
    DWORD size = sizeof(data);
    if (RegGetValue(HKEY_CURRENT_USER,
                    L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\"
                    L"StuckRects3",
                    L"Settings", RRF_RT_REG_BINARY, nullptr, data,
                    &size) == ERROR_SUCCESS &&
        size > 12 && data[12] <= ABE_BOTTOM) {
        edge = data[12];
    }
    stored.store(edge, std::memory_order_relaxed);
    readAt.store(now, std::memory_order_relaxed);
    return edge;
}

// The edge last seen from the taskbar's window all on its monitor (see
// TaskbarEdge), or UINT_MAX before. Moved in Settings, the taskbar keeps the
// edge stored for it as it was until explorer restarts.
std::atomic<UINT> g_seenTaskbarEdge{UINT_MAX};

// The edge last seen, or the stored one before it's been seen.
UINT KnownTaskbarEdge() {
    const UINT seen = g_seenTaskbarEdge.load(std::memory_order_relaxed);
    return seen != UINT_MAX ? seen : StoredTaskbarEdge();
}

// The edge of `monitor` a taskbar at `rect` is on, also while it's hidden
// (mostly past that edge): from its shape and which half its middle is in.
UINT RectSide(const RECT& rect, const RECT& monitor) {
    if (rect.right - rect.left < rect.bottom - rect.top) {
        return rect.left + rect.right < monitor.left + monitor.right
                   ? ABE_LEFT
                   : ABE_RIGHT;
    }
    return rect.top + rect.bottom < monitor.top + monitor.bottom ? ABE_TOP
                                                                 : ABE_BOTTOM;
}

// The edge a taskbar at `rect` is on, if it's all on a monitor (shown).
bool RectEdge(const RECT& rect, UINT* edge) {
    MONITORINFO info{sizeof(info)};
    if (!GetMonitorInfo(MonitorFromRect(&rect, MONITOR_DEFAULTTONEAREST),
                        &info) ||
        rect.left < info.rcMonitor.left || rect.top < info.rcMonitor.top ||
        rect.right > info.rcMonitor.right ||
        rect.bottom > info.rcMonitor.bottom) {
        return false;
    }
    // (Not a bar: almost square for a moment on its way to another edge.)
    const LONG width = rect.right - rect.left;
    const LONG height = rect.bottom - rect.top;
    if (height * 2 > width && width * 2 > height) {
        return false;
    }
    if (width < height) {
        *edge = rect.left + rect.right <
                        info.rcMonitor.left + info.rcMonitor.right
                    ? ABE_LEFT
                    : ABE_RIGHT;
    } else {
        *edge = rect.top + rect.bottom <
                        info.rcMonitor.top + info.rcMonitor.bottom
                    ? ABE_TOP
                    : ABE_BOTTOM;
    }
    return true;
}

// The edge of its monitor the taskbar is on (ABE_LEFT, ABE_TOP, ABE_RIGHT or
// ABE_BOTTOM; Windows 11 can put it on any). From where its window is only
// while it's all on its monitor: hidden or sliding, most of it is past the
// edge, maybe over another monitor (which made the dock and the taskbar as
// it is take turns). Otherwise from where Windows keeps it (asking the
// taskbar waits for it while it's busy, and from its own process could wait
// for a thread waiting for it), as last seen.
UINT TaskbarEdge() {
    HWND taskbar = FindTaskbarWnd();
    RECT rect;
    UINT edge;
    if (taskbar && GetWindowRect(taskbar, &rect) && RectEdge(rect, &edge)) {
        g_seenTaskbarEdge.store(edge, std::memory_order_relaxed);
        return edge;
    }
    return KnownTaskbarEdge();
}

// The monitor a taskbar belongs to: the one under its row next to the
// screen's inside (all of it when shown, the 2 pixels left of it when
// auto-hidden). Not MonitorFromWindow: a hidden taskbar is mostly past its
// edge, maybe over the next monitor (the one below a bottom taskbar), which
// that would take.
HMONITOR TaskbarMonitor(HWND taskbar) {
    RECT rect;
    if (!taskbar || !GetWindowRect(taskbar, &rect)) {
        return MonitorFromPoint({0, 0}, MONITOR_DEFAULTTOPRIMARY);
    }
    const LONG middleX = (rect.left + rect.right) / 2;
    const LONG middleY = (rect.top + rect.bottom) / 2;
    POINT inner;
    switch (KnownTaskbarEdge()) {
        case ABE_LEFT:
            inner = {rect.right - 1, middleY};
            break;
        case ABE_RIGHT:
            inner = {rect.left, middleY};
            break;
        case ABE_TOP:
            inner = {middleX, rect.bottom - 1};
            break;
        default:
            inner = {middleX, rect.top};
            break;
    }
    return MonitorFromPoint(inner, MONITOR_DEFAULTTONEAREST);
}

// Each monitor's choice with the dock's arrow (see ToggleDockPin): 0 as the
// settings say (hiding.autoHide), 1 kept shown, 2 hiding itself. Stored by
// the monitor's name, and kept here once read (taskbars' and settings'
// threads).
SRWLOCK g_dockPinLock = SRWLOCK_INIT;
[[clang::no_destroy]] std::unordered_map<std::wstring, int> g_dockPinStates;

std::wstring DockPinKey(HMONITOR monitor) {
    MONITORINFOEX info{};
    info.cbSize = sizeof(info);
    if (!monitor || !GetMonitorInfo(monitor, &info)) {
        return L"";
    }
    std::wstring key = L"dockPin_";
    for (const WCHAR* c = info.szDevice; *c; c++) {
        if (iswalnum(*c)) {
            key += *c;
        }
    }
    return key;
}

int DockPinState(HMONITOR monitor) {
    const std::wstring key = DockPinKey(monitor);
    if (key.empty()) {
        return 0;
    }
    AcquireSRWLockShared(&g_dockPinLock);
    const auto found = g_dockPinStates.find(key);
    const int cached = found != g_dockPinStates.end() ? found->second : -1;
    ReleaseSRWLockShared(&g_dockPinLock);
    if (cached >= 0) {
        return cached;
    }
    const int value = std::clamp(GetUserIntValue(key.c_str(), 0), 0, 2);
    AcquireSRWLockExclusive(&g_dockPinLock);
    g_dockPinStates[key] = value;
    ReleaseSRWLockExclusive(&g_dockPinLock);
    return value;
}

void SetDockPinState(HMONITOR monitor, int value) {
    const std::wstring key = DockPinKey(monitor);
    if (key.empty()) {
        return;
    }
    SetUserIntValue(key.c_str(), value);
    AcquireSRWLockExclusive(&g_dockPinLock);
    g_dockPinStates[key] = value;
    ReleaseSRWLockExclusive(&g_dockPinLock);
}

// Whether the dock on `monitor` hides itself: its arrow's choice, or the
// settings'.
bool DockHidesOnMonitor(HMONITOR monitor) {
    if (!g_settings.dockPinButton) {
        return g_settings.autoHide;
    }
    const int state = DockPinState(monitor);
    return state == 2 || (state == 0 && g_settings.autoHide);
}

bool DockHidesOn(HWND taskbar) {
    return DockHidesOnMonitor(TaskbarMonitor(taskbar));
}

// Windows' auto-hide is needed while a dock hides itself on any monitor (it
// is one setting for all the taskbars: the kept ones stay up, see
// CTaskListWnd_PermitAutoHide_Hook).
BOOL CALLBACK DockHidesOnMonitorProc(HMONITOR monitor,
                                     HDC,
                                     LPRECT,
                                     LPARAM data) {
    if (DockHidesOnMonitor(monitor)) {
        *(bool*)data = true;
        return FALSE;
    }
    return TRUE;
}

bool WantsAutoHide() {
    if (!g_settings.dockPinButton || !IsDock()) {
        return g_settings.autoHide;
    }
    bool any = false;
    EnumDisplayMonitors(nullptr, nullptr, DockHidesOnMonitorProc,
                        (LPARAM)&any);
    return any;
}


// The part of a taskbar's window on its own monitor, in the window's
// pixels (empty if none); `at`: with the window there.
RECT TaskbarOwnPart(HWND taskbar, const RECT* at = nullptr) {
    RECT window{};
    RECT part{};
    MONITORINFO info{sizeof(info)};
    if ((at ? (window = *at, true) : GetWindowRect(taskbar, &window)) &&
        GetMonitorInfo(TaskbarMonitor(taskbar), &info) &&
        IntersectRect(&part, &window, &info.rcMonitor)) {
        OffsetRect(&part, -window.left, -window.top);
    }
    return part;
}

// Whether the taskbar is at the bottom of its monitor.
bool IsTaskbarAtBottom() {
    return TaskbarEdge() == ABE_BOTTOM;
}

std::wstring JoinLines(const std::vector<std::wstring>& lines) {
    std::wstring joined;
    for (const auto& line : lines) {
        joined += line + L"\n";
    }
    return joined;
}

std::vector<std::wstring> SplitLines(const COPYDATASTRUCT* copyData) {
    std::vector<std::wstring> lines;
    const auto* text = (const WCHAR*)copyData->lpData;
    const size_t length = copyData->cbData / sizeof(WCHAR);
    size_t start = 0;
    for (size_t i = 0; i < length; i++) {
        if (text[i] == L'\n') {
            if (i > start) {
                lines.emplace_back(text + start, i - start);
            }
            start = i + 1;
        }
    }
    return lines;
}

bool SendLines(HWND to, HWND from, IpcKind kind,
               const std::vector<std::wstring>& lines) {
    const std::wstring joined = JoinLines(lines);
    return SendIpc(to, from, kind, joined.data(),
                   (DWORD)(joined.size() * sizeof(WCHAR)));
}

// Plain values and strings, one after another.
struct IpcWriter {
    std::vector<BYTE> bytes;
    template <typename T>
    void Put(const T& value) {
        const BYTE* data = (const BYTE*)&value;
        bytes.insert(bytes.end(), data, data + sizeof(T));
    }
    void PutString(const std::wstring& text) {
        Put<UINT32>((UINT32)text.size());
        const BYTE* data = (const BYTE*)text.data();
        bytes.insert(bytes.end(), data, data + text.size() * sizeof(WCHAR));
    }
};

struct IpcReader {
    const BYTE* at;
    const BYTE* end;
    explicit IpcReader(const COPYDATASTRUCT* copyData)
        : at((const BYTE*)copyData->lpData), end(at + copyData->cbData) {}
    template <typename T>
    bool Get(T* value) {
        if (end - at < (ptrdiff_t)sizeof(T)) {
            return false;
        }
        memcpy(value, at, sizeof(T));
        at += sizeof(T);
        return true;
    }
    bool GetString(std::wstring* text) {
        UINT32 length = 0;
        if (!Get(&length) || length > (size_t)(end - at) / sizeof(WCHAR)) {
            return false;
        }
        text->assign((const WCHAR*)at, length);
        at += length * sizeof(WCHAR);
        return true;
    }
};

// Breadth-first search, so the shallowest match wins.
FrameworkElement FindDescendant(
    FrameworkElement root,
    std::function<bool(FrameworkElement const&)> predicate,
    int maxDepth = 12) {
    std::vector<FrameworkElement> level{root};
    for (int depth = 0; depth < maxDepth && !level.empty(); depth++) {
        std::vector<FrameworkElement> next;
        for (const auto& element : level) {
            const int count = Media::VisualTreeHelper::GetChildrenCount(element);
            for (int i = 0; i < count; i++) {
                auto child = Media::VisualTreeHelper::GetChild(element, i)
                                 .try_as<FrameworkElement>();
                if (!child) {
                    continue;
                }
                if (predicate(child)) {
                    return child;
                }
                next.push_back(child);
            }
        }
        level = std::move(next);
    }
    return nullptr;
}

FrameworkElement FindByClassName(FrameworkElement root, PCWSTR className) {
    return FindDescendant(root, [className](FrameworkElement const& element) {
        return winrt::get_class_name(element) == className;
    });
}

FrameworkElement FindByName(FrameworkElement root, PCWSTR name) {
    return FindDescendant(root, [name](FrameworkElement const& element) {
        return element.Name() == name;
    });
}

// Windows' taskbar frame: inside the XAML content or, on newer builds
// (26320), the content itself (FindByClassName only looks below it).
FrameworkElement FindTaskbarFrame(FrameworkElement content) {
    if (content &&
        winrt::get_class_name(content) == L"Taskbar.TaskbarFrame") {
        return content;
    }
    return FindByClassName(content, L"Taskbar.TaskbarFrame");
}

void* CTaskBand_ITaskListWndSite_vftable;
void* CSecondaryTaskBand_ITaskListWndSite_vftable;

using CTaskBand_GetTaskbarHost_t = void*(WINAPI*)(void* pThis, void** result);
CTaskBand_GetTaskbarHost_t CTaskBand_GetTaskbarHost_Original;

void* TaskbarHost_FrameHeight_Original;

using CSecondaryTaskBand_GetTaskbarHost_t = void*(WINAPI*)(void* pThis,
                                                           void** result);
CSecondaryTaskBand_GetTaskbarHost_t CSecondaryTaskBand_GetTaskbarHost_Original;

using std__Ref_count_base__Decref_t = void(WINAPI*)(void* pThis);
std__Ref_count_base__Decref_t std__Ref_count_base__Decref_Original;

XamlRoot XamlRootFromTaskbarHostSharedPtr(void* taskbarHostSharedPtr[2]) {
    if (!taskbarHostSharedPtr[0] && !taskbarHostSharedPtr[1]) {
        return nullptr;
    }

    size_t taskbarElementIUnknownOffset = 0x10;

#if defined(_M_X64)
    {
        // 48:83EC 28 | sub rsp,28
        // 48:83C1 48 | add rcx,48
        const BYTE* b = (const BYTE*)TaskbarHost_FrameHeight_Original;
        if (b[0] == 0x48 && b[1] == 0x83 && b[2] == 0xEC && b[4] == 0x48 &&
            b[5] == 0x83 && b[6] == 0xC1 && b[7] <= 0x7F) {
            taskbarElementIUnknownOffset = b[7];
        } else {
            IslandLog(L"Unsupported TaskbarHost::FrameHeight");
        }
    }
#elif defined(_M_ARM64)
    {
        // 7f2303d5 pacibsp
        // fd7bbfa9 stp     fp, lr, [sp, #-0x10]!
        // fd030091 mov     fp, sp
        // 080c41f8 ldr     x8, [x0, #0x10]!
        const DWORD* p = (const DWORD*)TaskbarHost_FrameHeight_Original;
        if (p[0] == 0xD503237F && (p[1] & 0xFFC07FFF) == 0xA9807BFD &&
            p[2] == 0x910003FD && (p[3] & 0xFFF00FE0) == 0xF8400C00) {
            taskbarElementIUnknownOffset = (p[3] >> 12) & 0xFF;
        } else {
            IslandLog(L"Unsupported TaskbarHost::FrameHeight");
        }
    }
#else
    // 32-bit: only the island's process (windhawk.exe) is, and the taskbar
    // part never runs there (Windows 11's explorer.exe is 64-bit).
#endif

    auto* taskbarElementIUnknown =
        *(IUnknown**)((BYTE*)taskbarHostSharedPtr[0] +
                      taskbarElementIUnknownOffset);

    FrameworkElement taskbarElement = nullptr;
    taskbarElementIUnknown->QueryInterface(winrt::guid_of<FrameworkElement>(),
                                           winrt::put_abi(taskbarElement));

    auto result = taskbarElement ? taskbarElement.XamlRoot() : nullptr;

    std__Ref_count_base__Decref_Original(taskbarHostSharedPtr[1]);

    return result;
}

XamlRoot GetTaskbarXamlRoot(HWND hTaskbarWnd) {
    HWND hTaskSwWnd = (HWND)GetProp(hTaskbarWnd, L"TaskbandHWND");
    if (!hTaskSwWnd) {
        return nullptr;
    }

    void* taskBand = (void*)GetWindowLongPtr(hTaskSwWnd, 0);
    void* taskBandForTaskListWndSite = taskBand;
    for (int i = 0; *(void**)taskBandForTaskListWndSite !=
                    CTaskBand_ITaskListWndSite_vftable;
         i++) {
        if (i == 20) {
            return nullptr;
        }
        taskBandForTaskListWndSite = (void**)taskBandForTaskListWndSite + 1;
    }

    void* taskbarHostSharedPtr[2]{};
    CTaskBand_GetTaskbarHost_Original(taskBandForTaskListWndSite,
                                      taskbarHostSharedPtr);
    return XamlRootFromTaskbarHostSharedPtr(taskbarHostSharedPtr);
}

XamlRoot GetSecondaryTaskbarXamlRoot(HWND hSecondaryTaskbarWnd) {
    HWND hTaskSwWnd =
        (HWND)FindWindowEx(hSecondaryTaskbarWnd, nullptr, L"WorkerW", nullptr);
    if (!hTaskSwWnd) {
        return nullptr;
    }

    void* taskBand = (void*)GetWindowLongPtr(hTaskSwWnd, 0);
    void* taskBandForTaskListWndSite = taskBand;
    for (int i = 0; *(void**)taskBandForTaskListWndSite !=
                    CSecondaryTaskBand_ITaskListWndSite_vftable;
         i++) {
        if (i == 20) {
            return nullptr;
        }
        taskBandForTaskListWndSite = (void**)taskBandForTaskListWndSite + 1;
    }

    void* taskbarHostSharedPtr[2]{};
    CSecondaryTaskBand_GetTaskbarHost_Original(taskBandForTaskListWndSite,
                                               taskbarHostSharedPtr);
    return XamlRootFromTaskbarHostSharedPtr(taskbarHostSharedPtr);
}

////////////////////////////////////////////////////////////////////////////////
// The dock style (taskbar thread).

// Every property the mod sets, with the value it had before, so that it can
// be put back.
struct StyledProperty {
    winrt::weak_ref<DependencyObject> element;
    DependencyProperty property{nullptr};
    // DependencyProperty::UnsetValue() if it had no local value.
    winrt::Windows::Foundation::IInspectable original{nullptr};
};
// The globals below hold XAML objects. They're released on the taskbar's
// thread when the mod unloads (see ApplySettingsFromTaskbarThread), and never
// destroyed at process exit, when XAML is already gone (Windhawk wiki: "Global
// objects and process shutdown").
[[clang::no_destroy]] std::vector<StyledProperty> g_styledProperties;

// Keeps the dock's width automatic, because the taskbar sets the frame's width
// itself.
struct WidthWatch {
    winrt::weak_ref<FrameworkElement> element;
    int64_t token;
};
[[clang::no_destroy]] std::vector<WidthWatch> g_widthWatches;

void SetStyled(DependencyObject const& element,
               DependencyProperty const& property,
               winrt::Windows::Foundation::IInspectable const& value) {
    const bool known =
        std::any_of(g_styledProperties.begin(), g_styledProperties.end(),
                    [&](const StyledProperty& entry) {
                        return entry.property == property &&
                               entry.element.get() == element;
                    });
    if (!known) {
        g_styledProperties.push_back({winrt::make_weak(element), property,
                                      element.ReadLocalValue(property)});
    }
    element.SetValue(property, value);
}

void ResetDockBehavior();

void ClearStyles() {
    ResetDockBehavior();

    for (const auto& watch : g_widthWatches) {
        if (auto element = watch.element.get()) {
            Safely(L"Releasing the taskbar width watch", [&] {
                element.UnregisterPropertyChangedCallback(
                    FrameworkElement::WidthProperty(), watch.token);
            });
        }
    }
    g_widthWatches.clear();

    // In reverse, in case a property was recorded twice.
    for (auto it = g_styledProperties.rbegin(); it != g_styledProperties.rend();
         ++it) {
        auto element = it->element.get();
        if (!element) {
            continue;
        }
        Safely(L"Restoring a taskbar property", [&] {
            if (it->original == DependencyProperty::UnsetValue()) {
                element.ClearValue(it->property);
            } else {
                element.SetValue(it->property, it->original);
            }
        });
    }
    g_styledProperties.clear();
}

bool IsLightTheme() {
    DWORD value = 0;
    DWORD size = sizeof(value);
    if (RegGetValue(HKEY_CURRENT_USER,
                    L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\"
                    L"Personalize",
                    L"SystemUsesLightTheme", RRF_RT_REG_DWORD, nullptr, &value,
                    &size) != ERROR_SUCCESS) {
        return false;
    }
    return value != 0;
}

// The dock's tint, in the theme's color.
winrt::Windows::UI::Color DockTint() {
    if (g_settings.dockIslandStyle) {
        return {255, 0, 0, 0};
    }
    return IsLightTheme() ? winrt::Windows::UI::Color{255, 255, 255, 255}
                          : winrt::Windows::UI::Color{255, 30, 30, 36};
}

// The dock's background (its shelf, and the tray's pill): the tint, as
// see-through as chosen; none without the background. (XAML's acrylic can't
// blur behind the taskbar: it drew its fallback color, and black once the
// taskbar had the focus.)
Media::Brush CreateDockBackground() {
    winrt::Windows::UI::Color tint = DockTint();
    tint.A = g_settings.dockBackground
                 ? (uint8_t)std::lround(255 * g_settings.backgroundOpacity)
                 : 0;
    return Media::SolidColorBrush(tint);
}

// Its thin edge: a faint white line (a stronger one on the light theme, like
// light caught by the glass); none without the background.
winrt::Windows::UI::Color DockEdgeColor() {
    if (!g_settings.dockBackground) {
        return {0, 255, 255, 255};
    }
    return IsLightTheme() ? winrt::Windows::UI::Color{0xB3, 255, 255, 255}
                          : winrt::Windows::UI::Color{0x21, 255, 255, 255};
}

Media::Brush CreateDockBorder() {
    return Media::SolidColorBrush(DockEdgeColor());
}

// Styles a Grid or StackPanel as a rounded pill, on the dock's background.
void StylePill(FrameworkElement const& element, Thickness margin) {
    const auto radius =
        CornerRadiusHelper::FromUniformRadius(g_settings.cornerRadius);
    const auto border = ThicknessHelper::FromUniformLength(1);

    SetStyled(element, Controls::Panel::BackgroundProperty(),
              CreateDockBackground());
    SetStyled(element, FrameworkElement::MarginProperty(),
              winrt::box_value(margin));

    if (element.try_as<Controls::Grid>()) {
        SetStyled(element, Controls::Grid::CornerRadiusProperty(),
                  winrt::box_value(radius));
        SetStyled(element, Controls::Grid::BorderThicknessProperty(),
                  winrt::box_value(border));
        SetStyled(element, Controls::Grid::BorderBrushProperty(),
                  CreateDockBorder());
    } else if (element.try_as<Controls::StackPanel>()) {
        SetStyled(element, Controls::StackPanel::CornerRadiusProperty(),
                  winrt::box_value(radius));
        SetStyled(element, Controls::StackPanel::BorderThicknessProperty(),
                  winrt::box_value(border));
        SetStyled(element, Controls::StackPanel::BorderBrushProperty(),
                  CreateDockBorder());
    }
}

// The dock's shelf: the rounded glass under its icons, on a canvas of the
// mod's own behind everything in the taskbar's XAML (see ApplyStyleUnscoped),
// moved and sized each frame as the icons grow (see CreateDockBackground).
struct DockShelf {
    Controls::Border border{nullptr};
    // With the island style: its shape instead (the border is hidden), its
    // bottom corners curving out into the screen's edge.
    Shapes::Path path{nullptr};
    // The arrow that pins or hides the dock (dock.pinButton), where it takes
    // clicks (the XAML root's coordinates), what it shows (1 down: the dock
    // is kept shown; 2 up: it hides itself), and whether the mouse is on it.
    Controls::FontIcon pin{nullptr};
    winrt::Windows::Foundation::Rect pinRect{};
    int pinShows = 0;
    bool pinHovered = false;
    // Where it was last put, in its canvas's coordinates, and its corners.
    winrt::Windows::Foundation::Rect placed{};
    double radius = -1;
    // The line between the pinned apps and the others (dock.separator), on
    // the same canvas (none while the option is off), and where it was last
    // put.
    Shapes::Rectangle separator{nullptr};
    double separatorX = 0;
    double separatorTop = 0;
    double separatorHeight = 0;
};

DockShelf MakeDockShelf(Controls::Canvas const& host) {
    DockShelf shelf;
    shelf.border = Controls::Border();
    shelf.border.Background(CreateDockBackground());
    shelf.border.BorderBrush(CreateDockBorder());
    shelf.border.BorderThickness(ThicknessHelper::FromUniformLength(1));
    shelf.border.Width(0);
    shelf.border.Height(0);
    if (!g_settings.dockBackground) {
        shelf.border.Visibility(Visibility::Collapsed);
    }
    host.Children().Append(shelf.border);
    if (g_settings.dockIslandStyle) {
        shelf.border.Opacity(0);
        shelf.path = Shapes::Path();
        shelf.path.Fill(CreateDockBackground());
        shelf.path.IsHitTestVisible(false);
        if (!g_settings.dockBackground) {
            shelf.path.Visibility(Visibility::Collapsed);
        }
        host.Children().Append(shelf.path);
    }
    if (g_settings.dockPinButton) {
        shelf.pin = Controls::FontIcon();
        shelf.pin.FontFamily(Media::FontFamily(L"Segoe Fluent Icons"));
        shelf.pin.Glyph(L"\uE70D");
        const bool lightGlyph = g_settings.dockIslandStyle || !IsLightTheme();
        shelf.pin.Foreground(Media::SolidColorBrush(
            lightGlyph ? winrt::Windows::UI::Color{255, 255, 255, 255}
                       : winrt::Windows::UI::Color{255, 0, 0, 0}));
        shelf.pin.Opacity(0.6);
        shelf.pin.IsHitTestVisible(false);
        shelf.pin.Visibility(Visibility::Collapsed);
        host.Children().Append(shelf.pin);
    }
    if (g_settings.dockSeparator) {
        shelf.separator = Shapes::Rectangle();
        shelf.separator.Fill(Media::SolidColorBrush(DockEdgeColor()));
        shelf.separator.Width(1);
        shelf.separator.Height(0);
        shelf.separator.IsHitTestVisible(false);
        shelf.separator.Visibility(Visibility::Collapsed);
        host.Children().Append(shelf.separator);
    }
    return shelf;
}

// The island style's shape for the shelf at `r`: round top corners, and
// the bottom ones curving out (`ear` wide) into the edge under it.
Media::PathGeometry DockShelfGeometry(winrt::Windows::Foundation::Rect r,
                                      double radius,
                                      double ear) {
    const float x = r.X;
    const float y = r.Y;
    const float w = std::max(0.0f, r.Width);
    const float b = r.Y + std::max(0.0f, r.Height);
    const float rad = (float)std::max(0.0, std::min(radius, (double)w / 2));
    const float e =
        (float)std::max(0.0, std::min(ear, (double)(b - y) - rad));
    Media::PathFigure figure;
    figure.IsClosed(true);
    figure.IsFilled(true);
    auto segments = figure.Segments();
    auto arc = [&](winrt::Windows::Foundation::Point to, float size,
                   Media::SweepDirection direction) {
        Media::ArcSegment segment;
        segment.Point(to);
        segment.Size({size, size});
        segment.SweepDirection(direction);
        segments.Append(segment);
    };
    auto line = [&](winrt::Windows::Foundation::Point to) {
        Media::LineSegment segment;
        segment.Point(to);
        segments.Append(segment);
    };
    figure.StartPoint({x - e, b});
    if (e > 0) {
        arc({x, b - e}, e, Media::SweepDirection::Counterclockwise);
    }
    line({x, y + rad});
    if (rad > 0) {
        arc({x + rad, y}, rad, Media::SweepDirection::Clockwise);
    }
    line({x + w - rad, y});
    if (rad > 0) {
        arc({x + w, y + rad}, rad, Media::SweepDirection::Clockwise);
    }
    line({x + w, b - e});
    if (e > 0) {
        arc({x + w + e, b}, e, Media::SweepDirection::Counterclockwise);
    }
    Media::PathGeometry geometry;
    geometry.Figures().Append(figure);
    return geometry;
}

// Puts the shelf at `rect` (its canvas's coordinates).
void PlaceDockShelf(DockShelf& shelf,
                    winrt::Windows::Foundation::Rect rect,
                    double radius) {
    if (!shelf.border ||
        (std::fabs(rect.X - shelf.placed.X) < 0.05f &&
         std::fabs(rect.Y - shelf.placed.Y) < 0.05f &&
         std::fabs(rect.Width - shelf.placed.Width) < 0.05f &&
         std::fabs(rect.Height - shelf.placed.Height) < 0.05f &&
         radius == shelf.radius)) {
        return;
    }
    shelf.placed = rect;
    Controls::Canvas::SetLeft(shelf.border, rect.X);
    Controls::Canvas::SetTop(shelf.border, rect.Y);
    shelf.border.Width(std::max(0.0f, rect.Width));
    shelf.border.Height(std::max(0.0f, rect.Height));
    if (radius != shelf.radius) {
        shelf.radius = radius;
        shelf.border.CornerRadius(CornerRadiusHelper::FromUniformRadius(radius));
    }
    if (shelf.path) {
        shelf.path.Data(
            DockShelfGeometry(rect, radius, std::min(12.0, radius)));
    }
}

// Puts the separator line at `x` (its middle, in its canvas's coordinates),
// `top` and `height` tall, or hides it.
void PlaceDockSeparator(DockShelf& shelf,
                        bool shown,
                        double x,
                        double top,
                        double height) {
    if (!shelf.separator) {
        return;
    }
    const Visibility wanted =
        shown ? Visibility::Visible : Visibility::Collapsed;
    if (shelf.separator.Visibility() != wanted) {
        shelf.separator.Visibility(wanted);
    }
    if (!shown || (std::fabs(x - shelf.separatorX) < 0.05 &&
                   std::fabs(top - shelf.separatorTop) < 0.05 &&
                   std::fabs(height - shelf.separatorHeight) < 0.05)) {
        return;
    }
    shelf.separatorX = x;
    shelf.separatorTop = top;
    shelf.separatorHeight = height;
    Controls::Canvas::SetLeft(shelf.separator, x - 0.5);
    Controls::Canvas::SetTop(shelf.separator, top);
    shelf.separator.Height(std::max(0.0, height));
}

// The taskbar's background, under the dock's shelf (see DockShelf): nothing
// of its own shows.
void StyleDockBackground(Shapes::Rectangle const& fill) {
    SetStyled(fill, UIElement::VisibilityProperty(),
              winrt::box_value(Visibility::Visible));
    SetStyled(fill, Shapes::Shape::FillProperty(),
              Media::SolidColorBrush(winrt::Windows::UI::Colors::Transparent()));
    SetStyled(fill, Shapes::Shape::StrokeThicknessProperty(),
              winrt::box_value(0.0));
}

// The tray's pill's height, when it's shown beside the dock.
constexpr double kDockTrayHeight = 40;
// The element the dock's shelf is drawn on (see ApplyStyleUnscoped).
constexpr WCHAR kDockShelfHostName[] = L"WindhawkMacIslandDockShelf";

// Gives an element a height at the bottom of the taskbar.
void SetDockGeometry(FrameworkElement const& element,
                     double height,
                     double rightMargin) {
    SetStyled(element, FrameworkElement::HeightProperty(),
              winrt::box_value(height));
    SetStyled(element, FrameworkElement::VerticalAlignmentProperty(),
              winrt::box_value(VerticalAlignment::Bottom));
    SetStyled(element, FrameworkElement::MarginProperty(),
              winrt::box_value(ThicknessHelper::FromLengths(
                  0, 0, rightMargin, g_settings.bottomGap)));
}

void WatchFrameWidth(FrameworkElement const& frame) {
    const bool watched =
        std::any_of(g_widthWatches.begin(), g_widthWatches.end(),
                    [&](const WidthWatch& watch) {
                        return watch.element.get() == frame;
                    });
    if (watched) {
        return;
    }
    const int64_t token = frame.RegisterPropertyChangedCallback(
        FrameworkElement::WidthProperty(),
        [](DependencyObject const& sender, DependencyProperty const&) {
            if (g_unloading) {
                return;
            }
            Safely(L"Keeping the frame's width", [&] {
                auto element = sender.as<FrameworkElement>();
                if (!std::isnan(element.Width())) {
                    element.Width(std::numeric_limits<double>::quiet_NaN());
                }
            });
        });
    g_widthWatches.push_back({winrt::make_weak(frame), token});
}

////////////////////////////////////////////////////////////////////////////////
// Dock behavior: magnification, bouncing and dots (taskbar thread).

struct DockIcon {
    // The button grows and bounces as a whole.
    winrt::weak_ref<FrameworkElement> button;
    // The icon image inside it, used to line the icon up with the dock.
    winrt::weak_ref<FrameworkElement> image;
    Media::ScaleTransform scale{nullptr};
    Media::TranslateTransform lift{nullptr};
    // Eased towards the size the mouse position asks for, times the dock's
    // icon size over the taskbar's (dockIconSize; 1 on the transparent
    // taskbar).
    double magnification = 1;
    double baseScale = 1;
    // Where it takes the mouse: its own room in the row, so a magnified
    // icon's neighbors don't take its clicks (see OnRenderingUnsafe).
    Media::RectangleGeometry clip{nullptr};
    winrt::Windows::Foundation::Rect clipRect{};
    // An app's button (not Start or the search), and its picture: the app's
    // own icon as big as it's shown magnified, in place of the taskbar's
    // small one, which is put back when the mod lets go (see UseBigIcon).
    bool app = false;
    Media::ImageSource bigSource{nullptr};
    Media::ImageSource ownSource{nullptr};
    std::wstring ownAppId;
    // When the taskbar set its own picture again over the big one of the
    // same app (0 if not): maybe for another app the button is being reused
    // for, its ID changing a moment later (see UseBigIcon).
    double ownFreshAt = 0;
    // The taskbar had no picture on it when the big one was put (none is
    // put back).
    bool ownEmpty = false;
    // The size of the picture in bigSource (see BigIconPixels), and the app
    // it's for.
    int bigPixels = 0;
    std::wstring bigAppId;
    // The app's overlay icon (like Discord's red counter) drawn from the
    // app's own picture, and the taskbar's in its place before (see
    // UseBigOverlay).
    winrt::weak_ref<Controls::Image> overlayImage;
    Media::ImageSource overlayBig{nullptr};
    Media::ImageSource overlayOwn{nullptr};
    std::wstring overlayAppId;
    // An overlay that's a picture (like a browser profile's photo, 16
    // pixels): kept at its own size as the icon grows, sharp, rather than
    // magnified and blurred; a count drawn big grows with it (see
    // OnRenderingUnsafe).
    Media::ScaleTransform overlayKeep{nullptr};
    bool overlayCounted = false;
    bool overlayLooked = false;
    // Looked for in vain this many times (see kOverlayMostLooks), and when
    // last after those.
    int overlayLooks = 0;
    double overlayLookAt = 0;
    // An app opened: its button grows in (0 to 1, a bit more while
    // bouncing).
    double appear = 1;
    double appearVelocity = 0;
    // Moved by the taskbar (an app opened or closed next to it, or the dock
    // centered again): it slides from where it was (its layout middle last
    // time, NAN before the first frame).
    double slide = 0;
    double slideVelocity = 0;
    double lastCenter = NAN;
    // Bouncing: when it started (0 when not bouncing) and how many groups of
    // bounces it has (see BounceSequence).
    double bounceStart = 0;
    int bounceGroups = 0;
    // Whether the app is open, and whether it's asking for attention, to
    // notice when that changes.
    bool open = false;
    bool attention = false;
    // Whether the app is pinned to the taskbar (1), isn't (0), or isn't known
    // (-1), as of that version of the pinned list (see g_pinnedVersion).
    int pinned = -1;
    unsigned pinnedVersion = 0;
    // The app's notification badge (the count on the icon), once it exists
    // (see CheckBadge): the one watched, its text and whether it was shown
    // when last checked, for which app (buttons are reused for other apps),
    // and when it last counted as a notification.
    winrt::weak_ref<FrameworkElement> badge;
    std::wstring badgeText;
    bool badgeShown = false;
    std::wstring badgeAppId;
    double lastNotified = 0;
    // The small parts drawn over the icon's corners, sticking out of it (the
    // badge, an app's own overlay icon like Discord's red one): their highest
    // top and rightmost edge, in the button's coordinates (0 for none). See
    // MeasureDockExtras.
    double extrasTop = 0;
    double extrasRight = 0;
    // The running indicators turned into dots (see UpdateDots).
    struct Dot {
        winrt::weak_ref<Shapes::Rectangle> rectangle;
        Media::ScaleTransform scale{nullptr};
        Media::TranslateTransform move{nullptr};
    };
    std::vector<Dot> dots;
};

[[clang::no_destroy]] std::vector<DockIcon> g_dockIcons;
void UseBigIcon(DockIcon& icon, FrameworkElement const& button, int pixels);
void UseBigOverlay(DockIcon& icon,
                   FrameworkElement const& button,
                   double factor);
void RestoreDockIcon(DockIcon& icon);
HWND g_dockWnd;
winrt::weak_ref<FrameworkElement> g_dockFrame;
winrt::weak_ref<FrameworkElement> g_dockRepeater;
// The taskbar's background, which the dock's shelf is drawn on (see
// DockShelf).
winrt::weak_ref<FrameworkElement> g_dockBackground;
[[clang::no_destroy]] DockShelf g_dockShelf;
// The shelf at rest, in the window's pixels (see ClipDockWindow), and the
// last frame's, in its XAML coordinates (where the mouse makes it grow).
RECT g_dockShelfRest{};
winrt::Windows::Foundation::Rect g_dockShelfNow{};
// Whether the dock's room above the taskbar takes the mouse (the mouse on the
// dock, or its icons moving): see ClipDockWindow.
bool g_dockRoomOpen;
// The transparent taskbar's shadow, and how strong it's shown.
winrt::weak_ref<UIElement> g_shadowFill;
double g_shadowStrength = 0.6;
// The transparent taskbar only takes the mouse around its apps: its window is
// cut down to them (a window region), so clicks elsewhere reach the windows
// behind it, and the bottom edge brings it up only there. In the window's
// pixels, and on the screen for the bottom edge (see EdgeThreadProc).
RECT g_appsRegion{};
// The apps' extent it was made for (XAML coordinates), to make it again.
double g_appsLeft = 0;
double g_appsRight = 0;
// The monitor it was cut on (see g_appsAreas).
HMONITOR g_appsAreaMonitor;
// The span the shadow was last put behind.
double g_shadowLeft = 0;
double g_shadowRight = 0;
// Room around the apps that still counts as theirs, and the shadow's (which
// fades out before its edges).
constexpr double kAppsAreaMargin = 34;
constexpr double kShadowMargin = 30;
// The shadow's visual, drawn on its element.
[[clang::no_destroy]] winrt::Windows::UI::Composition::SpriteVisual
    g_shadowVisual{nullptr};
int g_dockItemCount = -1;
double g_dockSince;
double g_lastRenderTime;
// The dock as a box (dock.maxWidth): how far its row is scrolled (DIPs from
// its start), how far it can be (0: it all fits), and an app's room in it
// (a wheel notch scrolls one). Its wheel handler, kept to remove it again.
double g_dockScroll;
double g_dockScrollMax;
double g_dockScrollStep = 40;
[[clang::no_destroy]] winrt::Windows::Foundation::IInspectable
    g_wheelHandler{nullptr};
// When the taskbar's scale last changed (WM_DPICHANGED: hidden past its edge
// over a monitor with another scaling, then shown again): the icons take
// their new places at once for a moment, instead of sliding there.
double g_dockScaleChangedAt;
constexpr double kDockScaleSettleSeconds = 1.0;
// The taskbar's buttons are moved by its repeater's animator, one by one:
// when its scale changes, that's every button at once, out of order (Windows'
// own taskbar does it too). Meanwhile the animator is taken out: the value
// it had (DependencyProperty::UnsetValue() if none of its own), put back a
// moment later (see kAnimatorTimerId).
[[clang::no_destroy]] winrt::Windows::Foundation::IInspectable
    g_animatorKept{nullptr};
bool g_animatorPaused;
// The animator also leaves an implicit animation on each button's visual,
// which moves it on every layout change by itself: taken out meanwhile too,
// and put back on the buttons still there.
struct KeptImplicitAnimations {
    winrt::weak_ref<UIElement> element;
    winrt::Windows::UI::Composition::ImplicitAnimationCollection animations{
        nullptr};
};
[[clang::no_destroy]] std::vector<KeptImplicitAnimations> g_implicitKept;
// Until the taskbar is laid out again at its new scale (its buttons move
// once, a moment after WM_DPICHANGED), and while its scale isn't its own
// monitor's (hidden, mostly over a monitor with another scaling), its icons
// are drawn at the wrong size and places: its frame is see-through
// meanwhile (it still takes the mouse), its own opacity kept.
bool g_dockScaleSettled = true;
bool g_dockScaleMoved;
bool g_dockContentHidden;
[[clang::no_destroy]] winrt::Windows::Foundation::IInspectable
    g_dockOpacityKept{nullptr};
// (Windows lays it out again in about 0.15 s.)
constexpr double kDockScaleHideSeconds = 0.3;
// (Not one of the taskbar's own timers.)
constexpr UINT_PTR kAnimatorTimerId = 0x4D49;
constexpr UINT_PTR kDisplayRestyleTimerId = 0x4D4A;
constexpr UINT kAnimatorPauseMs = 1000;
// The repeater's Animator property, found by its name (the repeater is
// Microsoft.UI.Xaml's, which has no header here) as a style's setter, like
// the taskbar stylers do; null if it couldn't be.
[[clang::no_destroy]] DependencyProperty g_animatorProperty{nullptr};
bool g_animatorPropertyTried;

DependencyProperty RepeaterAnimatorProperty() {
    if (!g_animatorPropertyTried) {
        g_animatorPropertyTried = true;
        try {
            auto resources =
                Markup::XamlReader::Load(
                    LR"(<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:muxc="using:Microsoft.UI.Xaml.Controls">
    <Style x:Key="repeater" TargetType="muxc:ItemsRepeater">
        <Setter Property="Animator" Value="{x:Null}"/>
    </Style>
</ResourceDictionary>)")
                    .as<ResourceDictionary>();
            auto style =
                resources.Lookup(winrt::box_value(L"repeater")).as<Style>();
            g_animatorProperty =
                style.Setters().GetAt(0).as<Setter>().Property();
        } catch (const winrt::hresult_error& e) {
            IslandLog(L"The taskbar's animator isn't reachable: %08X",
                   (unsigned)e.code());
        }
    }
    return g_animatorProperty;
}

void PauseRepeaterAnimations() {
    auto repeater = g_dockRepeater.get();
    if (g_animatorPaused || !repeater ||
        winrt::get_class_name(repeater) !=
            L"Microsoft.UI.Xaml.Controls.ItemsRepeater") {
        return;
    }
    if (auto property = RepeaterAnimatorProperty()) {
        g_animatorKept = repeater.ReadLocalValue(property);
        repeater.SetValue(property, nullptr);
        g_animatorPaused = true;
    }
    const int count = Media::VisualTreeHelper::GetChildrenCount(repeater);
    for (int i = 0; i < count; i++) {
        auto child = Media::VisualTreeHelper::GetChild(repeater, i)
                         .try_as<UIElement>();
        if (!child) {
            continue;
        }
        auto visual =
            Hosting::ElementCompositionPreview::GetElementVisual(child);
        if (auto animations = visual.ImplicitAnimations()) {
            g_implicitKept.push_back({winrt::make_weak(child), animations});
            visual.ImplicitAnimations(nullptr);
            g_animatorPaused = true;
        }
    }
}

void ResumeRepeaterAnimations() {
    if (!g_animatorPaused) {
        return;
    }
    // (Each on its own: a retired element failing mustn't keep the rest, or
    // the kept animations, after the unload.)
    auto repeater = g_dockRepeater.get();
    if (repeater && g_animatorProperty && g_animatorKept) {
        Safely(L"Restoring the dock's animator", [&] {
            if (g_animatorKept == DependencyProperty::UnsetValue()) {
                repeater.ClearValue(g_animatorProperty);
            } else {
                repeater.SetValue(g_animatorProperty, g_animatorKept);
            }
        });
    }
    for (const auto& kept : g_implicitKept) {
        if (auto element = kept.element.get()) {
            Safely(L"Restoring an icon's animations", [&] {
                Hosting::ElementCompositionPreview::GetElementVisual(element)
                    .ImplicitAnimations(kept.animations);
            });
        }
    }
    std::vector<KeptImplicitAnimations>().swap(g_implicitKept);
    g_animatorPaused = false;
    g_animatorKept = nullptr;
}

// The boxed handler, kept to remove it again.
[[clang::no_destroy]] winrt::Windows::Foundation::IInspectable
    g_pointerHandler{nullptr};
[[clang::no_destroy]] winrt::Windows::Foundation::IInspectable
    g_pressedHandler{nullptr};
winrt::weak_ref<FrameworkElement> g_pointerTarget;
[[clang::no_destroy]] FrameworkElement::LayoutUpdated_revoker g_layoutRevoker;
[[clang::no_destroy]] Media::CompositionTarget::Rendering_revoker
    g_renderingRevoker;
[[clang::no_destroy]] DispatcherTimer g_badgeTimer{nullptr};
// The whole dock shown for a notification (see ShowDockForNotification).
[[clang::no_destroy]] DispatcherTimer g_notificationTimer{nullptr};
// The dock shown for a notification (see ShowDockForNotification), and where
// it goes back to: each taskbar's own (see DockState).
bool g_shownForNotification;
RECT g_notificationHiddenRect;
[[clang::no_destroy]] std::vector<
    VisualStateGroup::CurrentStateChanged_revoker>
    g_stateRevokers;
[[clang::no_destroy]] std::vector<FrameworkElement::SizeChanged_revoker>
    g_dotRevokers;
// Weak references: safe to destroy at exit.
std::vector<winrt::weak_ref<FrameworkElement>> g_watchedButtons;

// Property callbacks on the notification badges, to remove them again.
struct BadgeWatch {
    winrt::weak_ref<DependencyObject> element;
    DependencyProperty property{nullptr};
    int64_t token;
};
[[clang::no_destroy]] std::vector<BadgeWatch> g_badgeWatches;
double g_lastBadgeScan;

// Whether the dock state in the globals above is the main taskbar's.
bool g_dockIsMain = true;

// The other monitors' taskbars have the same behavior as the main one
// (magnification, sliding and growing icons, dots, the transparent taskbar's
// cut and shadow), with a state of their own each, kept here. All taskbars
// are on one thread: the code above works on the globals, and a DockScope
// puts another taskbar's state in them while that taskbar is handled (its
// XAML events, its frames, its slides). The badges and the icon peeking out
// for attention are the main taskbar's only (the same apps are on each).
struct DockState {
    std::vector<DockIcon> icons;
    HWND wnd = nullptr;
    winrt::weak_ref<FrameworkElement> frame;
    winrt::weak_ref<FrameworkElement> repeater;
    winrt::weak_ref<FrameworkElement> background;
    DockShelf shelf;
    RECT shelfRest{};
    winrt::Windows::Foundation::Rect shelfNow{};
    bool roomOpen = false;
    winrt::weak_ref<UIElement> shadowFill;
    double shadowStrength = 0.6;
    winrt::Windows::UI::Composition::SpriteVisual shadowVisual{nullptr};
    RECT appsRegion{};
    double appsLeft = 0;
    double appsRight = 0;
    HMONITOR appsAreaMonitor = nullptr;
    double shadowLeft = 0;
    double shadowRight = 0;
    int itemCount = -1;
    double since = 0;
    double scaleChangedAt = 0;
    winrt::Windows::Foundation::IInspectable animatorKept{nullptr};
    bool animatorPaused = false;
    std::vector<KeptImplicitAnimations> implicitKept;
    bool scaleSettled = true;
    bool scaleMoved = false;
    bool contentHidden = false;
    winrt::Windows::Foundation::IInspectable opacityKept{nullptr};
    winrt::Windows::Foundation::IInspectable pointerHandler{nullptr};
    winrt::Windows::Foundation::IInspectable pressedHandler{nullptr};
    winrt::Windows::Foundation::IInspectable wheelHandler{nullptr};
    double scroll = 0;
    double scrollMax = 0;
    winrt::weak_ref<FrameworkElement> pointerTarget;
    FrameworkElement::LayoutUpdated_revoker layoutRevoker;
    bool isMain = false;
    bool shownForNotification = false;
    RECT notificationHiddenRect{};
    DispatcherTimer notificationTimer{nullptr};
};

[[clang::no_destroy]] std::vector<std::unique_ptr<DockState>> g_otherDocks;

void SwapDockState(DockState& state) {
    std::swap(g_dockIcons, state.icons);
    std::swap(g_dockWnd, state.wnd);
    std::swap(g_dockFrame, state.frame);
    std::swap(g_dockRepeater, state.repeater);
    std::swap(g_dockBackground, state.background);
    std::swap(g_dockShelf, state.shelf);
    std::swap(g_dockShelfRest, state.shelfRest);
    std::swap(g_dockShelfNow, state.shelfNow);
    std::swap(g_dockRoomOpen, state.roomOpen);
    std::swap(g_shadowFill, state.shadowFill);
    std::swap(g_shadowStrength, state.shadowStrength);
    std::swap(g_shadowVisual, state.shadowVisual);
    std::swap(g_appsRegion, state.appsRegion);
    std::swap(g_appsLeft, state.appsLeft);
    std::swap(g_appsRight, state.appsRight);
    std::swap(g_appsAreaMonitor, state.appsAreaMonitor);
    std::swap(g_shadowLeft, state.shadowLeft);
    std::swap(g_shadowRight, state.shadowRight);
    std::swap(g_dockItemCount, state.itemCount);
    std::swap(g_dockSince, state.since);
    std::swap(g_dockScaleChangedAt, state.scaleChangedAt);
    std::swap(g_animatorKept, state.animatorKept);
    std::swap(g_animatorPaused, state.animatorPaused);
    std::swap(g_implicitKept, state.implicitKept);
    std::swap(g_dockScaleSettled, state.scaleSettled);
    std::swap(g_dockScaleMoved, state.scaleMoved);
    std::swap(g_dockContentHidden, state.contentHidden);
    std::swap(g_dockOpacityKept, state.opacityKept);
    std::swap(g_pointerHandler, state.pointerHandler);
    std::swap(g_pressedHandler, state.pressedHandler);
    std::swap(g_wheelHandler, state.wheelHandler);
    std::swap(g_dockScroll, state.scroll);
    std::swap(g_dockScrollMax, state.scrollMax);
    std::swap(g_pointerTarget, state.pointerTarget);
    std::swap(g_layoutRevoker, state.layoutRevoker);
    std::swap(g_dockIsMain, state.isMain);
    std::swap(g_shownForNotification, state.shownForNotification);
    std::swap(g_notificationHiddenRect, state.notificationHiddenRect);
    std::swap(g_notificationTimer, state.notificationTimer);
}

DockState* FindOtherDock(HWND wnd) {
    for (auto& state : g_otherDocks) {
        if (state->wnd == wnd) {
            return state.get();
        }
    }
    return nullptr;
}

// Another taskbar's state in the globals for as long as it lives (nothing
// for the main taskbar, or inside another scope).
class DockScope {
   public:
    explicit DockScope(HWND wnd) {
        if (!s_active && wnd && wnd != g_dockWnd) {
            m_state = FindOtherDock(wnd);
            if (m_state) {
                SwapDockState(*m_state);
                s_active = true;
            }
        }
    }
    ~DockScope() {
        if (m_state) {
            SwapDockState(*m_state);
            s_active = false;
        }
    }
    DockScope(const DockScope&) = delete;
    DockScope& operator=(const DockScope&) = delete;

   private:
    DockState* m_state = nullptr;
    static inline bool s_active = false;
};

// The taskbars cut by ClipToOwnMonitor (their regions go when the mod does).
[[clang::no_destroy]] std::vector<HWND> g_ownClips;

// Where each transparent taskbar takes the mouse at the bottom edge (its
// apps, on the screen), by monitor, for the edge thread.
struct AppsArea {
    HMONITOR monitor;
    int left;
    int right;
};
SRWLOCK g_appsAreasLock = SRWLOCK_INIT;
std::vector<AppsArea> g_appsAreas;

// (An empty span forgets it.)
void SetAppsArea(HMONITOR monitor, int left, int right) {
    AcquireSRWLockExclusive(&g_appsAreasLock);
    std::erase_if(g_appsAreas, [&](const AppsArea& area) {
        return area.monitor == monitor;
    });
    if (monitor && right > left) {
        g_appsAreas.push_back({monitor, left, right});
    }
    ReleaseSRWLockExclusive(&g_appsAreasLock);
}

bool GetAppsArea(HMONITOR monitor, int* left, int* right) {
    AcquireSRWLockShared(&g_appsAreasLock);
    bool found = false;
    for (const auto& area : g_appsAreas) {
        if (area.monitor == monitor) {
            *left = area.left;
            *right = area.right;
            found = true;
        }
    }
    ReleaseSRWLockShared(&g_appsAreasLock);
    return found;
}

// Defined further down.
bool IsTaskbarHidden(HWND hTaskbarWnd, const RECT& monitorRect);
HBITMAP LoadAppIconBitmap(HWND hWnd, std::wstring appId, int size);
HBITMAP PinnedShortcutIconBitmap(const std::wstring& appId, int size);
HBITMAP AppWindowIconBitmap(const std::wstring& appId, HWND window);
HWND FindTaskbarAppWindow(const std::wstring& appId);

// An app's icon kept by the island or a panel (see LoadAppIcon). One explorer
// didn't give (none, or the island's own try: a blank square for some
// packaged apps while explorer starts again) is looked up again later.
struct KeptAppIcon {
    std::wstring appId;
    winrt::com_ptr<ID2D1Bitmap> bitmap;
    double retryAt = 0;
    // Looked up in vain this many times in a row.
    int misses = 0;
};
constexpr double kAppIconRetrySeconds = 30;
// (None found, like just after the island or explorer started again: asked
// again soon, not after a gray square for half a minute; then later each
// time, up to kMissingIconLongestSeconds: an app whose icon never comes
// isn't asked of explorer every few seconds forever.)
constexpr double kMissingIconRetrySeconds = 3;
constexpr double kMissingIconLongestSeconds = 120;

// When an icon kept is looked up again (see KeptAppIcon): never explorer's,
// after a while the island's own, a missing one sooner (`misses` before).
double AppIconRetryAt(bool fromExplorer, bool found, int misses, double now) {
    if (fromExplorer) {
        return 0;
    }
    if (found) {
        return now + kAppIconRetrySeconds;
    }
    return now + std::min(kMissingIconRetrySeconds * (1 << std::min(misses, 6)),
                          kMissingIconLongestSeconds);
}

// A rounded inner corner where a bar meets the screen, in the brush's
// color: the square of `radius` at `corner` (going `along` the bar's edge and
// `out` into the screen) without the quarter circle facing away from it.
void FillInnerCorner(ID2D1RenderTarget* target,
                     ID2D1Brush* brush,
                     D2D1_POINT_2F corner,
                     D2D1_POINT_2F along,
                     D2D1_POINT_2F out,
                     float radius) {
    winrt::com_ptr<ID2D1Factory> factory;
    target->GetFactory(factory.put());
    winrt::com_ptr<ID2D1PathGeometry> path;
    winrt::com_ptr<ID2D1GeometrySink> sink;
    if (!factory || FAILED(factory->CreatePathGeometry(path.put())) ||
        FAILED(path->Open(sink.put()))) {
        return;
    }
    const D2D1_POINT_2F a{corner.x + along.x * radius,
                          corner.y + along.y * radius};
    const D2D1_POINT_2F b{corner.x + out.x * radius,
                          corner.y + out.y * radius};
    // (The quarter turn from `a` to `b` around the square's far corner, the
    // way that passes by `corner`.)
    const float turn = (-out.x) * (-along.y) - (-out.y) * (-along.x);
    sink->BeginFigure(corner, D2D1_FIGURE_BEGIN_FILLED);
    sink->AddLine(a);
    sink->AddArc({b,
                  {radius, radius},
                  0,
                  turn > 0 ? D2D1_SWEEP_DIRECTION_CLOCKWISE
                           : D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE,
                  D2D1_ARC_SIZE_SMALL});
    sink->EndFigure(D2D1_FIGURE_END_CLOSED);
    if (SUCCEEDED(sink->Close())) {
        target->FillGeometry(path.get(), brush);
    }
}

// The smooth way of drawing a picture smaller (see DrawBitmapSmooth) is
// Direct2D's only effect here, and the only drawing that needs a picture of
// its own on the way: some graphics drivers can't make it
// (D2DERR_INTERMEDIATE_TOO_LARGE, #6638: whole frames lost, the island left
// empty). Then pictures are made smaller the usual way from there on.
constexpr HRESULT kIntermediateTooLarge = (HRESULT)0x88990027;
std::atomic<bool> g_plainScaling{false};
// True if `hr` (a drawing's end) just turned the smooth way off.
bool PlainScalingAfter(HRESULT hr) {
    return hr == kIntermediateTooLarge && !g_plainScaling.exchange(true);
}

// A picture drawn smaller than it is (app icons, covers, photos): smoothly,
// with every pixel counted (Direct2D's usual way skips some, and small icons
// look jagged); as big or bigger, the usual way.
void DrawBitmapSmooth(ID2D1RenderTarget* target,
                      ID2D1Bitmap* bitmap,
                      const D2D1_RECT_F& rect,
                      float opacity = 1) {
    const D2D1_SIZE_F size = bitmap->GetSize();
    winrt::com_ptr<ID2D1DeviceContext> context;
    if ((rect.right - rect.left < size.width - 0.5f ||
         rect.bottom - rect.top < size.height - 0.5f) &&
        !g_plainScaling &&
        SUCCEEDED(target->QueryInterface(IID_PPV_ARGS(context.put())))) {
        context->DrawBitmap(bitmap, &rect, opacity,
                            D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC, nullptr,
                            nullptr);
        return;
    }
    target->DrawBitmap(bitmap, rect, opacity);
}

// A brush painting a picture (scaled by its transform) the same smooth way.
winrt::com_ptr<ID2D1BitmapBrush> SmoothBitmapBrush(ID2D1RenderTarget* target,
                                                   ID2D1Bitmap* bitmap) {
    winrt::com_ptr<ID2D1BitmapBrush> brush;
    winrt::com_ptr<ID2D1DeviceContext> context;
    winrt::com_ptr<ID2D1BitmapBrush1> smooth;
    const D2D1_BITMAP_BRUSH_PROPERTIES1 properties{
        D2D1_EXTEND_MODE_CLAMP, D2D1_EXTEND_MODE_CLAMP,
        D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC};
    if (!g_plainScaling &&
        SUCCEEDED(target->QueryInterface(IID_PPV_ARGS(context.put()))) &&
        SUCCEEDED(context->CreateBitmapBrush(bitmap, &properties, nullptr,
                                             smooth.put()))) {
        brush.copy_from(smooth.get());
    } else {
        target->CreateBitmapBrush(bitmap, brush.put());
    }
    return brush;
}
std::wstring GetWindowAppId(HWND hWnd);
std::wstring WindowAppKey(HWND hWnd);
void PostAttentionRequest(HWND app, std::wstring appId);
void ScheduleTaskbarHide(HWND hTaskbarWnd, UINT delayMs);
void SlideTo(HWND hWnd, const RECT& target, int durationMs, bool show);

// Whether the taskbar itself has the dock shown: it calls SlideWindow to
// show and hide it (see TrayUI_SlideWindow_Hook).
bool g_trayShown;

// How long the dock waits at most for a clicked app to open, in seconds.
constexpr double kLaunchWaitSeconds = 6;
// The groups an app clicked in the dock bounces for while it opens, as long
// as that wait (see OnDockPressed).
constexpr int kLaunchWaitBounceGroups =
    (int)(kLaunchWaitSeconds / kBounceGroupLength) + 1;

// Keeps the dock up for `seconds` from now, replacing any earlier wait. The
// taskbar asks PermitAutoHide before hiding (see
// CTaskListWnd_PermitAutoHide_Hook), and its hide timer is set to try again
// right after.
void KeepDockShown(double seconds) {
    if (!g_dockWnd) {
        return;
    }
    g_keepShownUntil = NowSeconds() + seconds;
    g_keepShownWnd = g_dockWnd;
    ScheduleTaskbarHide(g_dockWnd, (UINT)(seconds * 1000) + 100);
}

// How fast the magnification follows the mouse (higher is snappier).
constexpr double kMagnificationFollow = 18;
// Diameter of the open-app dot, and its distance below the icon, in pixels.
constexpr double kDotSize = 4;
constexpr double kDotGap = 3;

// The dock's measures around its icons, like the dock on the mod's site
// (46-pixel icons, 6 pixels apart, the shelf 8 pixels above them, 10 beside
// and 9 under the dots): the margins grow and shrink with the icons.
struct DockMetrics {
    double icon;
    double gap;
    double padTop;
    double padSide;
    double padBottom;
    double bottomGap;
    // The open apps' dots, under the icons.
    double dotRoom;
    double Height() const { return padTop + icon + dotRoom + padBottom; }
};

// How high an icon bounces, for its size at rest.
constexpr double kDockBounce = 0.55;

// Whether the taskbar hides itself (read on the taskbar's thread as it's
// styled): otherwise the dock at rest fits in its own height.
std::atomic<bool> g_taskbarAutoHides{true};

// The dock's measures for the chosen icon size and space between the icons,
// within `room` (the taskbar's own height, in DIPs) if it isn't 0: all
// smaller but the dots.
DockMetrics GetDockMetrics(double room) {
    const double icon = g_settings.dockIconSize;
    const double f = icon / 46;
    // (#7103: above the icons, nearly the room under them with the dots, so
    // they sit close to the middle, as in macOS's dock.)
    DockMetrics m{icon,         g_settings.dockIconGap, 12 * f, 10 * f, 9 * f,
                  g_settings.bottomGap, kDotGap + kDotSize};
    const double whole = m.bottomGap + m.Height();
    if (room > 0 && whole > room) {
        const double k =
            std::max(0.3, (room - m.dotRoom) / (whole - m.dotRoom));
        for (double* part : {&m.icon, &m.gap, &m.padTop, &m.padSide,
                             &m.padBottom, &m.bottomGap}) {
            *part *= k;
        }
    }
    // The end icons' top corners clear the shelf's round corners (small
    // icons make it almost a pill), with as much room as above them.
    const double radius = std::min(g_settings.cornerRadius, m.Height() / 2);
    if (m.padTop < radius) {
        const double curve = radius - m.padTop;
        const double inset =
            radius - std::sqrt(std::max(0.0, radius * radius - curve * curve));
        m.padSide = std::max(m.padSide, inset + m.padTop);
    }
    return m;
}

// The dock's room above the taskbar: the dock is taller than the taskbar (its
// icons magnified and bouncing, and the dock itself around big icons), so its
// window is made taller upwards (see GrowTaskbarWindow), shown or hidden
// (hidden, the room goes down past the screen's edge with the rest), so a
// slide never lays it out again. The taskbar keeps its own height for what it
// reserves on the screen, and the room takes no clicks while the dock rests
// (see ClipDockWindow). Taskbar thread only.
struct GrownTaskbar {
    HWND wnd;
    // The taskbar's own height and the room added, in DIPs.
    double baseDips;
    double extraDips;
    // The room was added upwards (shown) or downwards (hidden), and how
    // much higher it is hidden (see HiddenLift), in pixels.
    bool up;
    int lift = 0;
    // The top of the dock's shelf on the screen, as last drawn (0 before).
    LONG shelfTop = 0;
};
std::vector<GrownTaskbar> g_grownTaskbars;

GrownTaskbar* FindGrownTaskbar(HWND wnd) {
    for (auto& grown : g_grownTaskbars) {
        if (grown.wnd == wnd) {
            return &grown;
        }
    }
    return nullptr;
}

// The room the dock needs above the taskbar's own height, in DIPs (none but
// for the dock).
double DockRoomDips(double baseDips) {
    if (!IsDock() || !g_taskbarAtBottom || g_unloading) {
        return 0;
    }
    const DockMetrics m = GetDockMetrics(g_taskbarAutoHides ? 0 : baseDips);
    const double tallest = m.icon * (g_settings.magnification + kDockBounce);
    // (A few pixels more above the bounce.)
    return std::max(0.0, std::ceil(m.bottomGap + m.padBottom + m.dotRoom +
                                   tallest + 4 - baseDips));
}

// The mouse is on this dock (the shelf, or its magnified icons): the
// taskbar doesn't hide meanwhile (see CTaskListWnd_PermitAutoHide_Hook).
HWND g_dockHovered;
// The taskbar the mod's own slide is moving right now (see SlideTo), and
// whether it goes away: each frame is cut before and after its move there,
// so the taskbar's handlers leave that to the slide (they'd cut it again and
// again, and paint its whole window black for every frame of a hide, which
// shows nothing new). Taskbar thread only (the taskbars all live on it).
HWND g_slidingTaskbar;
bool g_slidingHides;
// A show Windows makes at once (no animation) with the user not reaching for
// the dock: its window goes up cut to nothing, and the dock shows only if it's
// still up this long after (see TrayUI_SlideWindow_Hook). Styling it again,
// or turning its auto-hide on (see UpdateAutoHide), Windows shows the taskbar
// so and hides it again right after, over and over for a few seconds
// (measured: up to 15 times in 4 seconds, each hide 2 to 93 ms after its
// show), and each one popped up and slid away: none of that shows now.
constexpr UINT kQuietShowDelayMs = 150;
// (Not one of the taskbar's own timers.)
constexpr UINT_PTR kQuietShowTimerId = 0x4D4C;
// The dock shown so that still waits, or null. Taskbar thread only.
HWND g_quietShownWnd;
// Whether cutting a taskbar's window (SetWindowRgn) redraws it: not while the
// slide moves it, which would redraw it with every frame (the slide's end
// draws it once).
bool RedrawsWithCut(HWND taskbar) {
    return taskbar != g_slidingTaskbar;
}
// The taskbar whose hide timer is being handled, so what the taskbar asks
// meanwhile (see CTaskListWnd_PermitAutoHide_Hook) is about that one and not
// the main one's. Taskbar thread only.
HWND g_hideTimerTaskbar;
// When a taskbar was last clicked (see HandFocusBack), and right-clicked
// (see JumpListOpen), and which one that was.
double g_dockPressedAt;
double g_dockRightPressedAt;
HWND g_dockRightPressedWnd;
// Where (screen X) the dock's icon was right-clicked: its jump list is
// moved above it (see JumpListMoveThreadProc).
volatile LONG g_dockRightPressedX;

// The dock's arrow clicked: pins or hides it (defined further down).
void ToggleDockPin(HWND taskbar);

// Cuts the dock's window to what it shows (defined further down).
void ClipDockWindow(HWND hWnd, const RECT* next = nullptr);

// The taskbar's thumbnails of an app's windows (shown with the mouse on its
// button): the taskbar puts them above its window, whose top is the dock's
// room (see GrownTaskbar), far above the icons, and the mouse couldn't get
// to them without leaving the dock; they're moved down to right above the
// shelf. Classic ones have a window of their own; Windows 11's draw in a XAML
// window as big as the monitor, above the taskbar's top, which Windows keeps
// shown (empty) and shows again without placing it: that window is moved down
// by as much as the shelf's top is below the taskbar's while the mouse is on
// the dock or right above it (on its thumbnails), and put back otherwise as
// it shows or moves, when the mouse leaves the dock and when the dock hides
// (other parts of Windows may show in it).
std::vector<HWND> g_thumbnailWindows;

// Whether `at` is the monitor's rectangle moved down.
bool MovedDownMonitor(const RECT& at, const RECT& monitor) {
    return at.top > monitor.top && at.left == monitor.left &&
           at.right == monitor.right &&
           at.bottom - at.top == monitor.bottom - monitor.top;
}

// Whether the mouse is on the dock `room` (whose window is at `taskbar`), or
// above it where its thumbnails show.
bool MouseOnDockOrThumbnails(const GrownTaskbar& room, const RECT& taskbar) {
    if (g_dockHovered == room.wnd) {
        return true;
    }
    POINT pt{};
    return GetCursorPos(&pt) && pt.x >= taskbar.left && pt.x < taskbar.right &&
           pt.y < room.shelfTop &&
           pt.y >= room.shelfTop - MulDiv(420, GetDpiForWindow(room.wnd), 96);
}

// Where the thumbnails' window `at` goes on the screen (unchanged if it isn't
// above a dock).
RECT PlaceThumbnails(const RECT& at) {
    RECT placed = at;
    // (Empty: nothing shows in it yet.)
    if (at.right <= at.left || at.bottom <= at.top) {
        return placed;
    }
    const HMONITOR monitor = MonitorFromRect(&at, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info{sizeof(info)};
    if (!GetMonitorInfo(monitor, &info)) {
        return placed;
    }
    const bool monitorSized = EqualRect(&at, &info.rcMonitor) ||
                              MovedDownMonitor(at, info.rcMonitor);
    for (const auto& room : g_grownTaskbars) {
        RECT taskbar{};
        if (!room.shelfTop || !GetWindowRect(room.wnd, &taskbar) ||
            TaskbarMonitor(room.wnd) != monitor) {
            continue;
        }
        // Its window's top with it shown (it may be on its way up), where
        // Windows puts the thumbnails above (see GrownTaskbar::shelfTop).
        const LONG shownTop =
            info.rcMonitor.bottom - (taskbar.bottom - taskbar.top);
        if (monitorSized) {
            placed = info.rcMonitor;
            if (room.shelfTop > shownTop &&
                MouseOnDockOrThumbnails(room, taskbar)) {
                OffsetRect(&placed, 0, room.shelfTop - shownTop);
            }
        } else if (const LONG wanted = room.shelfTop -
                                       MulDiv(8, GetDpiForWindow(room.wnd), 96);
                   at.bottom <= shownTop + 2 && at.bottom < wanted) {
            // (Only the ones put above the taskbar's window.)
            OffsetRect(&placed, 0, wanted - at.bottom);
        }
        break;
    }
    return placed;
}

LRESULT CALLBACK ThumbnailSubclassProc(HWND hWnd,
                                       UINT uMsg,
                                       WPARAM wParam,
                                       LPARAM lParam,
                                       DWORD_PTR) {
    if (uMsg == WM_WINDOWPOSCHANGING && lParam && !g_unloading && IsDock()) {
        auto* pos = (WINDOWPOS*)lParam;
        // (Also shown again where it was, without a move.)
        if (!(pos->flags & SWP_NOMOVE) || (pos->flags & SWP_SHOWWINDOW)) {
            RECT now{};
            GetWindowRect(hWnd, &now);
            const POINT to = (pos->flags & SWP_NOMOVE)
                                 ? POINT{now.left, now.top}
                                 : POINT{pos->x, pos->y};
            const int height =
                (pos->flags & SWP_NOSIZE) ? now.bottom - now.top : pos->cy;
            const int width =
                (pos->flags & SWP_NOSIZE) ? now.right - now.left : pos->cx;
            const RECT placed =
                PlaceThumbnails({to.x, to.y, to.x + width, to.y + height});
            if (placed.top != to.y) {
                pos->x = to.x;
                pos->y = placed.top;
                pos->flags &= ~SWP_NOMOVE;
            }
        }
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

// Places the watched thumbnails' windows again (see PlaceThumbnails).
void PlaceThumbnailWindows() {
    for (HWND thumbnails : g_thumbnailWindows) {
        RECT at{};
        if (IsWindowVisible(thumbnails) && GetWindowRect(thumbnails, &at)) {
            const RECT placed = PlaceThumbnails(at);
            if (placed.top != at.top) {
                SetWindowPos(thumbnails, nullptr, placed.left, placed.top, 0, 0,
                             SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
            }
        }
    }
}

// Finds the thumbnails' windows (made the first time they show: the classic
// one, and the XAML ones of newer Windows 11 builds) and watches them. Taskbar
// thread only.
void WatchThumbnails() {
    // (Not the "_WASDK" XAML window: the desktop's context menu shows in
    // it. Only the ones of this thread, the taskbar's, which shows the
    // thumbnails: Alt+Tab, Task View and the desktops' switcher show in
    // windows of the same class on a thread of their own, and
    // PlaceThumbnails reads the taskbar thread's g_grownTaskbars.)
    for (PCWSTR className :
         {L"TaskListThumbnailWnd", L"XamlExplorerHostIslandWindow"}) {
        HWND thumbnails = nullptr;
        while ((thumbnails = FindWindowEx(nullptr, thumbnails, className,
                                          nullptr))) {
            DWORD processId = 0;
            const DWORD threadId =
                GetWindowThreadProcessId(thumbnails, &processId);
            if (processId != GetCurrentProcessId() ||
                threadId != GetCurrentThreadId() ||
                std::find(g_thumbnailWindows.begin(), g_thumbnailWindows.end(),
                          thumbnails) != g_thumbnailWindows.end()) {
                continue;
            }
            if (!WindhawkUtils::SetWindowSubclassFromAnyThread(
                    thumbnails, ThumbnailSubclassProc, 0)) {
                continue;
            }
            g_thumbnailWindows.push_back(thumbnails);
        }
    }
}

void UnwatchThumbnails() {
    for (HWND thumbnails : g_thumbnailWindows) {
        // (A monitor-sized one moved down goes back in place.)
        RECT at{};
        MONITORINFO info{sizeof(info)};
        if (GetWindowRect(thumbnails, &at) &&
            GetMonitorInfo(MonitorFromRect(&at, MONITOR_DEFAULTTONEAREST),
                           &info) &&
            MovedDownMonitor(at, info.rcMonitor)) {
            SetWindowPos(thumbnails, nullptr, info.rcMonitor.left,
                         info.rcMonitor.top, 0, 0,
                         SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    for (HWND thumbnails : g_thumbnailWindows) {
        if (IsWindow(thumbnails)) {
            WindhawkUtils::RemoveWindowSubclassFromAnyThread(
                thumbnails, ThumbnailSubclassProc);
        }
    }
    g_thumbnailWindows.clear();
}

void OnRendering(winrt::Windows::Foundation::IInspectable const&,
                 winrt::Windows::Foundation::IInspectable const&);

void StartRendering() {
    if (!g_renderingRevoker && !g_unloading) {
        g_lastRenderTime = NowSeconds();
        Safely(L"Starting to draw", [] {
            g_renderingRevoker = Media::CompositionTarget::Rendering(
                winrt::auto_revoke, OnRendering);
        });
    }
}

DockIcon* FindDockIcon(FrameworkElement const& button) {
    for (auto& icon : g_dockIcons) {
        if (icon.button.get() == button) {
            return &icon;
        }
    }
    return nullptr;
}

// Collects every element of the given classes under `root`, without looking
// inside the ones found.
void FindAllByClassName(FrameworkElement const& root,
                        std::initializer_list<PCWSTR> classNames,
                        std::vector<FrameworkElement>& found,
                        int depth = 0) {
    if (depth > 14) {
        return;
    }
    const int count = Media::VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < count; i++) {
        auto child = Media::VisualTreeHelper::GetChild(root, i)
                         .try_as<FrameworkElement>();
        if (!child) {
            continue;
        }
        const auto className = winrt::get_class_name(child);
        if (std::any_of(classNames.begin(), classNames.end(),
                        [&](PCWSTR name) { return className == name; })) {
            found.push_back(child);
        } else {
            FindAllByClassName(child, classNames, found, depth + 1);
        }
    }
}

// Remembers where an app's button is on the screen, for the icon that peeks
// out while the dock is hidden (see RunAttentionIcon).
void RecordAttentionButton(FrameworkElement const& button) {
    auto parent =
        Media::VisualTreeHelper::GetParent(button).try_as<UIElement>();
    if (!parent || !g_dockWnd || !g_dockIsMain) {
        return;
    }
    const auto offset = button.ActualOffset();
    const double center =
        parent.TransformToVisual(nullptr)
            .TransformPoint({offset.x, offset.y})
            .X +
        button.ActualWidth() / 2;
    POINT pt{MulDiv((int)std::lround(center), GetDpiForWindow(g_dockWnd), 96),
             0};
    ClientToScreen(g_dockWnd, &pt);
    g_attentionButtonX = pt.x;
    g_attentionButtonTime = NowSeconds();
}

void MakeDots(DockIcon& icon, FrameworkElement const& button);

// The running state comes from the button's "RunningIndicatorStates" visual
// states: NoRunningIndicator (closed), Active/InactiveRunningIndicator (open)
// and RequestingAttention... (asking for attention).
void OnRunningStateChanged(winrt::weak_ref<FrameworkElement> weakButton,
                           std::wstring_view oldState,
                           std::wstring_view newState) {
    auto button = weakButton.get();
    DockIcon* icon = button ? FindDockIcon(button) : nullptr;
    if (!icon) {
        return;
    }

    const bool wasClosed = oldState == L"NoRunningIndicator" ||
                           // A new button for an app that wasn't pinned.
                           (oldState.empty() && NowSeconds() - g_dockSince > 5);
    const bool attention =
        newState.find(L"RequestingAttention") != std::wstring_view::npos;
    const bool open = !newState.empty() && newState != L"NoRunningIndicator";

    if (attention && !icon->attention) {
        RecordAttentionButton(button);
        // (The dock bounces; the transparent taskbar doesn't, see
        // OnAppFlashed.)
        if (IsDock()) {
            icon->bounceStart = NowSeconds();
            icon->bounceGroups = kAttentionBounceGroups;
            StartRendering();
        }
    }
    icon->attention = attention;

    icon->open = open;
    // Its line, made by Windows only now for a pinned app: a dot too (see
    // UpdateDots).
    if (open) {
        MakeDots(*icon, button);
        StartRendering();
    }

    if (wasClosed && open && !attention) {
        if (g_settings.bounceOnLaunch) {
            if (icon->bounceStart &&
                icon->bounceGroups == kLaunchWaitBounceGroups) {
                // Bouncing since it was clicked (see OnDockPressed): it
                // opened, so the bounce in progress is the last one.
                icon->bounceGroups = std::min(
                    icon->bounceGroups,
                    (int)(AnimationDt(NowSeconds() - icon->bounceStart) /
                          kBounceGroupLength) +
                        1);
            } else {
                icon->bounceStart = NowSeconds();
                icon->bounceGroups = kLaunchBounceGroups;
            }
            StartRendering();
        }
        // Only if it was clicked in the dock (see OnDockPressed), so the
        // dock is up.
        if (g_settings.keepOpenOnLaunch && IsKeptShown(g_dockWnd)) {
            KeepDockShown(g_settings.keepOpenDuration / 1000.0);
        }
    }
}

// A click on a closed app's button: the dock waits for the app to open, and
// its icon bounces meanwhile (the bounce that shows once its window is there
// is easy to miss, over the new window and with the dock about to hide).
void OnDockPressed(Input::PointerRoutedEventArgs const& args) {
    if (!AnimatesIcons()) {
        return;
    }
    if (!g_settings.keepOpenOnLaunch && !g_settings.bounceOnLaunch) {
        return;
    }
    auto element = args.OriginalSource().try_as<DependencyObject>();
    while (element) {
        auto frameworkElement = element.try_as<FrameworkElement>();
        if (frameworkElement && winrt::get_class_name(frameworkElement) ==
                                    L"Taskbar.TaskListButton") {
            DockIcon* icon = FindDockIcon(frameworkElement);
            if (icon && !icon->open) {
                if (g_settings.keepOpenOnLaunch) {
                    KeepDockShown(kLaunchWaitSeconds);
                }
                if (g_settings.bounceOnLaunch &&
                    args.GetCurrentPoint(nullptr)
                        .Properties()
                        .IsLeftButtonPressed()) {
                    icon->bounceStart = NowSeconds();
                    icon->bounceGroups = kLaunchWaitBounceGroups;
                    StartRendering();
                }
            }
            return;
        }
        element = Media::VisualTreeHelper::GetParent(element);
    }
}

// How long the whole dock stays up for a notification, when that's the
// setting, in milliseconds.
constexpr UINT kNotificationShowMs = 3500;

// An app's ID without what the taskbar-grouping mod adds to keep each window
// apart ("~Wh~", a letter and 8 hex digits, #7029): the app's own icons.
std::wstring WithoutGroupingSuffix(std::wstring id) {
    constexpr std::wstring_view kMark = L"~Wh~";
    constexpr size_t kSuffix = kMark.size() + 9;
    if (id.size() > kSuffix) {
        const size_t at = id.size() - kSuffix;
        if (std::wstring_view(id).substr(at, kMark.size()) == kMark &&
            iswalpha(id[at + kMark.size()]) &&
            std::all_of(id.begin() + at + kMark.size() + 1, id.end(),
                        [](WCHAR c) { return iswxdigit(c) != 0; })) {
            id.erase(at);
        }
    }
    return id;
}

// The app a taskbar button belongs to: its AppUserModelID, which the button
// carries as its automation ID (with an "Appid: " prefix on some builds).
std::wstring GetButtonAppId(FrameworkElement const& button) {
    std::wstring id{Automation::AutomationProperties::GetAutomationId(button)};
    constexpr std::wstring_view kPrefix = L"Appid: ";
    if (id.starts_with(kPrefix)) {
        id.erase(0, kPrefix.size());
    }
    return WithoutGroupingSuffix(std::move(id));
}

// Shows the whole dock for a moment, for a notification. The taskbar only
// shows itself for the mouse at the edge, so the mod slides it in itself, and
// back out after a while unless the mouse is on it. If the taskbar shows
// itself meanwhile (the mouse went there), it takes over.
void ShowDockForNotification() {
    if (g_shownForNotification || g_trayShown || !g_dockWnd) {
        return;
    }
    RECT rect;
    MONITORINFO monitor{sizeof(monitor)};
    if (!GetWindowRect(g_dockWnd, &rect) ||
        !GetMonitorInfo(TaskbarMonitor(g_dockWnd), &monitor)) {
        return;
    }
    g_notificationHiddenRect = rect;
    RECT shown = rect;
    OffsetRect(&shown, 0, monitor.rcMonitor.bottom - rect.bottom);
    g_shownForNotification = true;
    SlideTo(g_dockWnd, shown, AnimationMs(g_settings.showDuration), true);

    if (g_notificationTimer) {
        g_notificationTimer.Stop();
    }
    g_notificationTimer = DispatcherTimer();
    g_notificationTimer.Interval(std::chrono::milliseconds(kNotificationShowMs));
    // (The tick comes outside any dock's scope: this dock's state then.)
    g_notificationTimer.Tick(
        [wnd = g_dockWnd](winrt::Windows::Foundation::IInspectable const& sender,
                          winrt::Windows::Foundation::IInspectable const&) {
            DockScope scope(wnd);
            auto timer = sender.as<DispatcherTimer>();
            // (A dock already let go: its window isn't the one in the
            // globals, so nothing of another dock is touched.)
            if (g_dockWnd != wnd) {
                timer.Stop();
                return;
            }
            if (!g_shownForNotification || g_trayShown || g_unloading) {
                timer.Stop();
                g_shownForNotification = false;
                return;
            }
            // Stays while the mouse is on it; asked again on the next tick.
            POINT pt;
            RECT rect;
            if (GetCursorPos(&pt) && GetWindowRect(g_dockWnd, &rect) &&
                PtInRect(&rect, pt)) {
                return;
            }
            timer.Stop();
            g_shownForNotification = false;
            SlideTo(g_dockWnd, g_notificationHiddenRect,
                    AnimationMs(g_settings.hideDuration), false);
        });
    g_notificationTimer.Start();
}

// An app has something new: a new count on its badge, or its button started
// flashing. The icon bounces in the dock if it's on screen. Otherwise, it
// depends on the setting: only the icon peeks out, the whole dock shows up,
// or nothing happens.
void OnAppNotified(FrameworkElement const& button) {
    DockIcon* icon = FindDockIcon(button);
    const double now = NowSeconds();
    if (!icon || !g_dockWnd || now - icon->lastNotified < 1.0) {
        return;
    }
    icon->lastNotified = now;

    const std::wstring appId = GetButtonAppId(button);
    // On the Windows taskbar (and the transparent one), the button shows it
    // itself; only the dock bounces.
    if (!AnimatesIcons() || !IsDock()) {
        return;
    }
    // Not for the app the user is looking at.
    if (!appId.empty() && GetWindowAppId(GetForegroundWindow()) == appId) {
        return;
    }
    RecordAttentionButton(button);

    MONITORINFO monitor{sizeof(monitor)};
    GetMonitorInfo(TaskbarMonitor(g_dockWnd), &monitor);
    const bool hidden = IsTaskbarHidden(g_dockWnd, monitor.rcMonitor);
    if (hidden && g_settings.attentionMode == AttentionMode::Icon) {
        PostAttentionRequest(nullptr, appId);
        return;
    }
    if (hidden && g_settings.attentionMode == AttentionMode::None) {
        return;
    }
    icon->bounceStart = now;
    icon->bounceGroups = kAttentionBounceGroups;
    StartRendering();
    if (hidden) {
        ShowDockForNotification();
    }
}

bool IsBadgeShown(const DockIcon& icon) {
    auto badge = icon.badge.get();
    return badge && badge.Visibility() == Visibility::Visible &&
           badge.Opacity() > 0;
}

// The apps with a notification badge right now, by AppUserModelID, for the
// island (see Island::UpdateApps). Written on the taskbar thread. In explorer,
// each line is the ID, a tab and the badge's count (0 without a number); the
// island keeps the IDs here, and their counts in g_badgeCounts.
SRWLOCK g_badgeAppsLock = SRWLOCK_INIT;
std::vector<std::wstring> g_badgeApps;
std::vector<int> g_badgeCounts;
// The apps' overlay icons (ITaskbarList3::SetOverlayIcon, like Discord's red
// counter, which isn't a badge), as the taskbar gets them (see
// CTaskBand__HandleOverlayIcon_Hook): the app's own picture (a copy; the
// taskbar draws it at 16 pixels, blurry magnified) and its text (where an
// app says how many, like "3 unread"). They count as the app's badge (see
// PublishBadgeApps) and are drawn sharp in the dock (see UseBigOverlay).
struct OverlayIcon {
    HWND wnd;
    std::wstring appId;
    HICON icon = nullptr;
    // Its picture's width, in pixels.
    int size = 0;
    // Changed with every new picture (see UseBigOverlay).
    unsigned serial = 0;
    std::wstring description;
};
SRWLOCK g_overlayIconsLock = SRWLOCK_INIT;
std::vector<OverlayIcon> g_overlayIcons;
unsigned g_overlaySerial = 0;

// Whether an overlay's text has a count in it (like "0 notifications"):
// apps also show their status with one (presence, "recording"), without.
bool OverlayHasCount(const std::wstring& description) {
    return description.find_first_of(L"0123456789") != std::wstring::npos;
}

// The count an overlay's text gives (its first number, "99+" as 99), or 0.
int OverlayCount(const std::wstring& description) {
    const size_t digit = description.find_first_of(L"0123456789");
    return digit == std::wstring::npos ? 0
                                       : _wtoi(description.c_str() + digit);
}

// The count an app's overlay icon shows. Discord's text ("N notifications",
// in its own language) says the count before the newest one (its first
// notification comes with "0 notifications", its picture showing 1): one
// more.
int OverlayShownCount(const OverlayIcon& overlay) {
    const int count = OverlayCount(overlay.description);
    const bool discord = overlay.icon &&
                         StrStrI(overlay.appId.c_str(), L"Discord") &&
                         OverlayHasCount(overlay.description);
    return discord ? count + 1 : count;
}

// The island's window, told when they change.
std::atomic<HWND> g_islandWnd;
// The apps' progress as explorer last told it (see PublishProgress; the
// island's thread).
int g_downloadState = 0;
int g_downloadPermille = 0;
// (kProgressKindCopy: a file copy.)
int g_downloadKind = 0;
// Only browsers have it (kProgressFromBrowsers), and since when its value
// hasn't moved: standing still this long, it shows as paused
// (islandDownloadStalled; Chromium's bar moves 1% at a time, so a big slow
// download stands still for a while).
bool g_downloadBrowsers = false;
double g_downloadMovedAt = 0;
constexpr double kDownloadStalledSeconds = 30;
// Right after Windows starts, apps restoring themselves tell the taskbar a
// progress they don't have: none fills the pill until then (NowSeconds()).
constexpr double kBootProgressSeconds = 30;
constexpr ULONGLONG kBootUptimeMs = 5 * 60 * 1000;
double g_progressFrom = 0;
// The message that tells it.
constexpr UINT WM_APP_BADGES = WM_APP + 51;

// To the island, in its own process.
void SendBadgeApps() {
    HWND island = FindIslandWnd();
    if (!island) {
        return;
    }
    AcquireSRWLockShared(&g_badgeAppsLock);
    const std::vector<std::wstring> apps = g_badgeApps;
    ReleaseSRWLockShared(&g_badgeAppsLock);
    SendLines(island, OwnTaskbarWnd(), kIpcBadgeApps, apps);
}

void PublishBadgeApps() {
    if (!g_dockIsMain) {
        return;
    }
    std::vector<std::wstring> ids;
    std::vector<std::wstring> apps;
    for (const auto& icon : g_dockIcons) {
        auto button = icon.button.get();
        if (!button || !icon.badgeShown) {
            continue;
        }
        // Apps' buttons, and the Widgets button (not Start, search or task
        // view, which aren't apps either).
        std::wstring appId = GetButtonAppId(button);
        if (winrt::get_class_name(button) != L"Taskbar.TaskListButton" &&
            appId != kWidgetsBadgeId) {
            continue;
        }
        if (!appId.empty() &&
            std::find(ids.begin(), ids.end(), appId) == ids.end()) {
            apps.push_back(appId + L"\t" +
                           std::to_wstring(
                               std::max(0, _wtoi(icon.badgeText.c_str()))));
            ids.push_back(std::move(appId));
        }
    }
    // The apps' overlay icons too (their windows still open), with the count
    // their text gives: only the ones with a count (not a status).
    AcquireSRWLockExclusive(&g_overlayIconsLock);
    std::erase_if(g_overlayIcons, [](const OverlayIcon& overlay) {
        if (IsWindow(overlay.wnd)) {
            return false;
        }
        DestroyIcon(overlay.icon);
        return true;
    });
    for (const auto& overlay : g_overlayIcons) {
        if (overlay.icon && !overlay.appId.empty() &&
            OverlayHasCount(overlay.description) &&
            std::find(ids.begin(), ids.end(), overlay.appId) == ids.end()) {
            apps.push_back(overlay.appId + L"\t" +
                           std::to_wstring(OverlayShownCount(overlay)));
            ids.push_back(overlay.appId);
        }
    }
    ReleaseSRWLockExclusive(&g_overlayIconsLock);
    AcquireSRWLockExclusive(&g_badgeAppsLock);
    const bool changed = apps != g_badgeApps;
    if (changed) {
        g_badgeApps = std::move(apps);
    }
    ReleaseSRWLockExclusive(&g_badgeAppsLock);
    if (changed) {
        SendBadgeApps();
    }
}

// The badge (Taskbar.Badge#BadgeControl, with TextBlock#BadgeText inside) is
// only created with an app's first notification.
FrameworkElement FindBadge(FrameworkElement const& button) {
    return FindDescendant(button, [](FrameworkElement const& e) {
        return std::wstring_view{winrt::get_class_name(e)}.find(L"Badge") !=
                   std::wstring_view::npos ||
               std::wstring_view{e.Name()}.find(L"Badge") !=
                   std::wstring_view::npos;
    });
}

Controls::TextBlock FindBadgeText(FrameworkElement const& badge) {
    if (auto found = FindDescendant(badge, [](FrameworkElement const& e) {
            return (bool)e.try_as<Controls::TextBlock>();
        })) {
        return found.as<Controls::TextBlock>();
    }
    return nullptr;
}

void CheckBadgeOf(winrt::weak_ref<FrameworkElement> const& weakButton);

// Asks to be told when the badge's text, visibility or opacity change.
void WatchBadge(DockIcon& icon,
                FrameworkElement const& button,
                FrameworkElement const& badge,
                Controls::TextBlock const& text) {
    icon.badge = winrt::make_weak(badge);
    const auto weakButton = winrt::make_weak(button);
    auto watch = [&](DependencyObject const& element,
                     DependencyProperty const& property) {
        g_badgeWatches.push_back(
            {winrt::make_weak(element), property,
             element.RegisterPropertyChangedCallback(
                 property, [weakButton](DependencyObject const&,
                                        DependencyProperty const&) {
                     Safely(L"Checking a badge",
                            [&] { CheckBadgeOf(weakButton); });
                 })});
    };
    watch(text, Controls::TextBlock::TextProperty());
    watch(badge, UIElement::VisibilityProperty());
    watch(badge, UIElement::OpacityProperty());
}

// Compares the badge with how it was last seen. News: it appeared with a
// count, or the count changed (but not to a smaller number: fewer unread
// items isn't news; "99+" reads as 99). Nothing is news for a moment after the
// mod starts (the badges already there), or when the button now shows another
// app.
void CheckBadge(DockIcon& icon) {
    auto button = icon.button.get();
    if (!button) {
        return;
    }
    auto badge = FindBadge(button);
    Controls::TextBlock text = badge ? FindBadgeText(badge) : nullptr;
    if (badge && text && badge != icon.badge.get()) {
        WatchBadge(icon, button, badge, text);
    }

    const std::wstring appId = GetButtonAppId(button);
    const std::wstring newText = text ? std::wstring{text.Text()} : L"";
    const bool shown = text && !newText.empty() &&
                       badge.Visibility() == Visibility::Visible &&
                       badge.Opacity() > 0;

    bool news = false;
    if (appId == icon.badgeAppId && shown) {
        if (!icon.badgeShown) {
            news = true;
        } else if (newText != icon.badgeText) {
            const int count = _wtoi(newText.c_str());
            const int oldCount = _wtoi(icon.badgeText.c_str());
            news = !(count > 0 && oldCount > 0 && count < oldCount);
        }
    }
    icon.badgeAppId = appId;
    icon.badgeText = newText;
    icon.badgeShown = shown;
    if (news && NowSeconds() - g_dockSince > 5) {
        OnAppNotified(button);
    }
}

void CheckBadgeOf(winrt::weak_ref<FrameworkElement> const& weakButton) {
    auto button = weakButton.get();
    if (DockIcon* icon = button ? FindDockIcon(button) : nullptr) {
        CheckBadge(*icon);
        PublishBadgeApps();
    }
}

// The badges are created, replaced, faded in and out by the taskbar, so they're
// checked again as it changes, and every second.
void WatchBadges() {
    for (auto& icon : g_dockIcons) {
        CheckBadge(icon);
    }
}

// Widens `top` and `right` with the parts under `element` smaller than
// `limit` (the icon's size) that show, in `button`'s coordinates.
void FindIconExtras(FrameworkElement const& button,
                    FrameworkElement const& element,
                    double limit,
                    double& top,
                    double& right,
                    int depth = 0) {
    const int count = Media::VisualTreeHelper::GetChildrenCount(element);
    for (int i = 0; i < count; i++) {
        auto child = Media::VisualTreeHelper::GetChild(element, i)
                         .try_as<FrameworkElement>();
        if (!child || child.Visibility() != Visibility::Visible ||
            child.Opacity() <= 0) {
            continue;
        }
        const double width = child.ActualWidth();
        const double height = child.ActualHeight();
        if (width > 0 && height > 0 && width < limit && height < limit) {
            const auto bounds = child.TransformToVisual(button).TransformBounds(
                {0, 0, (float)width, (float)height});
            top = top ? std::min(top, (double)bounds.Y) : bounds.Y;
            right = std::max(right, (double)(bounds.X + bounds.Width));
        } else if (depth < 8) {
            FindIconExtras(button, child, limit, top, right, depth + 1);
        }
    }
}

// Measures each dock's icons' extras (see DockIcon::extrasTop), every second
// (they come and go): the dock is cut around them (see OnRenderingUnsafe).
// Every dock's (its badges are only followed on the main one) and also hidden
// (ready as it shows), every icon (an overlay icon set before the mod started
// isn't known, see g_overlayIcons).
void MeasureDockExtras() {
    const auto measure = [] {
        bool changed = false;
        for (auto& icon : g_dockIcons) {
            auto button = icon.button.get();
            auto image = icon.image.get();
            if (!button || !image || image.ActualHeight() <= 0) {
                continue;
            }
            double top = 0;
            double right = 0;
            FindIconExtras(button, button, image.ActualHeight() * 0.95, top,
                           right);
            if (top != icon.extrasTop || right != icon.extrasRight) {
                icon.extrasTop = top;
                icon.extrasRight = right;
                changed = true;
            }
        }
        if (changed) {
            StartRendering();
        }
    };
    measure();
    for (auto& state : g_otherDocks) {
        DockScope scope(state->wnd);
        measure();
    }
}

void WatchBadgesAndPublish() {
    if (!g_dockIsMain) {
        return;
    }
    WatchBadges();
    PublishBadgeApps();
}

// (Defined further down.)
void WatchProgressBar(FrameworkElement const& button);
void StopWatchingProgressBars();
void RecheckProgress();
void SetProgressWanted(bool wanted);

void WatchRunningState(FrameworkElement const& button) {
    WatchProgressBar(button);
    auto panel = FindByName(button, L"IconPanel");
    if (!panel) {
        return;
    }
    for (const auto& group : VisualStateManager::GetVisualStateGroups(panel)) {
        if (group.Name() != L"RunningIndicatorStates") {
            continue;
        }
        // (Its state now too: one already asking for attention, like an app
        // flashing before the taskbar's style changed, still lets the
        // transparent taskbar hide, see CTaskListWnd_PermitAutoHide_Hook.)
        if (DockIcon* icon = FindDockIcon(button)) {
            const auto state = group.CurrentState();
            const std::wstring name = state ? state.Name().c_str() : L"";
            icon->open = state && name != L"NoRunningIndicator";
            icon->attention =
                name.find(L"RequestingAttention") != std::wstring::npos;
        }
        g_stateRevokers.push_back(group.CurrentStateChanged(
            winrt::auto_revoke,
            [weakButton = winrt::make_weak(button), taskbar = g_dockWnd](
                winrt::Windows::Foundation::IInspectable const&,
                VisualStateChangedEventArgs const& args) {
                DockScope scope(taskbar);
                Safely(L"Following an app's state", [&] {
                    const auto oldState = args.OldState()
                                              ? args.OldState().Name()
                                              : winrt::hstring{};
                    const auto newState = args.NewState()
                                              ? args.NewState().Name()
                                              : winrt::hstring{};
                    OnRunningStateChanged(weakButton, oldState, newState);
                });
            }));
    }
}

void FindAllByName(FrameworkElement const& root,
                   PCWSTR name,
                   std::vector<FrameworkElement>& found,
                   int depth = 0) {
    if (depth > 14) {
        return;
    }
    const int count = Media::VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < count; i++) {
        auto child = Media::VisualTreeHelper::GetChild(root, i)
                         .try_as<FrameworkElement>();
        if (!child) {
            continue;
        }
        if (child.Name() == name) {
            found.push_back(child);
        }
        FindAllByName(child, name, found, depth + 1);
    }
}

// Where a button is drawn this frame, in the taskbar's coordinates, for
// UpdateDots.
struct IconPlacement {
    double buttonTop;   // Layout position, before the mod's transforms.
    double originY;     // Scaling origin, in the button's coordinates.
    double offsetY;     // The button's vertical move (alignment + bounce).
    double iconBottom;  // The resting icon's bottom edge.
    double dockBottom;  // The dock background's bottom edge.
};

// Keeps the icon's dots round, small, just below the icon, and still while
// the icon grows and bounces, like on macOS. The dots are inside the button
// that grows and bounces, so they're moved and scaled back.
void UpdateDots(DockIcon& icon, const IconPlacement& place) {
    auto button = icon.button.get();
    if (!button || g_unloading) {
        return;
    }
    // An open app without its dot yet: its line came after the button was
    // seen (a pinned app opened from the dock), made a dot now.
    if (icon.open && std::none_of(icon.dots.begin(), icon.dots.end(),
                                  [](const DockIcon::Dot& dot) {
                                      return dot.rectangle.get() != nullptr;
                                  })) {
        MakeDots(icon, button);
    }
    const double magnification =
        std::max(icon.magnification * icon.baseScale, 0.01);
    const double dotCenter =
        std::min(place.iconBottom + kDotGap + kDotSize / 2,
                 place.dockBottom - kDotSize / 2 - 1);

    for (auto& dot : icon.dots) {
        auto rectangle = dot.rectangle.get();
        if (!rectangle) {
            continue;
        }
        const double width = rectangle.ActualWidth();
        const double height = rectangle.ActualHeight();
        auto parent =
            Media::VisualTreeHelper::GetParent(rectangle).try_as<UIElement>();
        if (width <= 0 || height <= 0 || !parent) {
            continue;
        }

        // Rounded fully before scaling, so it's a circle after. Only set when
        // it changes: a new radius makes the taskbar lay itself out again,
        // which would render another frame, and so on.
        if (rectangle.RadiusX() != width / 2 ||
            rectangle.RadiusY() != height / 2) {
            SetStyled(rectangle, Shapes::Rectangle::RadiusXProperty(),
                      winrt::box_value(width / 2));
            SetStyled(rectangle, Shapes::Rectangle::RadiusYProperty(),
                      winrt::box_value(height / 2));
        }
        dot.scale.ScaleX(kDotSize / (width * magnification));
        dot.scale.ScaleY(kDotSize / (height * magnification));

        // The line's center, in the button's coordinates.
        const auto offset = rectangle.ActualOffset();
        const double center = parent.TransformToVisual(button)
                                  .TransformPoint({offset.x, offset.y})
                                  .Y +
                              height / 2;
        // A point `y` of the button is drawn at
        //   buttonTop + originY + (y - originY) * magnification + offsetY.
        // This is the move that puts the line's center at `dotCenter`.
        dot.move.Y((dotCenter - place.buttonTop - place.originY -
                    place.offsetY) /
                       magnification +
                   place.originY - center);
    }
}

void MakeDots(DockIcon& icon, FrameworkElement const& button) {
    std::vector<FrameworkElement> indicators;
    FindAllByName(button, L"RunningIndicator", indicators);

    // (Again later for new lines: the ones gone let go, the ones already
    // dots left as they are.)
    std::erase_if(icon.dots, [](const DockIcon::Dot& dot) {
        return !dot.rectangle.get();
    });
    for (const auto& element : indicators) {
        auto rectangle = element.try_as<Shapes::Rectangle>();
        if (!rectangle || std::any_of(icon.dots.begin(), icon.dots.end(),
                                      [&](const DockIcon::Dot& dot) {
                                          return dot.rectangle.get() ==
                                                 rectangle;
                                      })) {
            continue;
        }
        DockIcon::Dot dot;
        dot.rectangle = winrt::make_weak(rectangle);
        Media::TransformGroup transforms;
        transforms.Children().Append(dot.scale = Media::ScaleTransform());
        transforms.Children().Append(dot.move = Media::TranslateTransform());
        SetStyled(rectangle, UIElement::RenderTransformProperty(), transforms);
        SetStyled(rectangle, UIElement::RenderTransformOriginProperty(),
                  winrt::box_value(winrt::Windows::Foundation::Point{0.5f, 0.5f}));
        icon.dots.push_back(dot);

        // The line changes size with the app's state.
        g_dotRevokers.push_back(rectangle.SizeChanged(
            winrt::auto_revoke,
            [weakButton = winrt::make_weak(button)](
                winrt::Windows::Foundation::IInspectable const&,
                SizeChangedEventArgs const&) {
                if (weakButton.get()) {
                    StartRendering();
                }
            }));
    }
}

// The apps pinned to the taskbar (their AppUserModelIDs), for the dock's
// separator (dock.separator): read from its shortcuts when Windows' pinned
// list changes (see RefreshPinnedApps), on the taskbar's thread out of a
// frame. A new version number makes each button look itself up again.
std::vector<std::wstring> g_pinnedApps;
bool g_pinnedRead;
unsigned g_pinnedVersion = 1;
FILETIME g_pinnedStamp{};
double g_pinnedCheckAt;
// How much room the line takes between the icons, besides their gap.
constexpr double kDockSeparatorRoom = 12;

// (Defined further down.)
std::vector<std::wstring> ReadPinnedAppIds();

// When Windows' pinned list was last written (its key's time in the
// registry); 0 if there's none.
FILETIME PinnedListStamp() {
    FILETIME stamp{};
    HKEY key = nullptr;
    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\"
                     L"Taskband",
                     0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS) {
        RegQueryInfoKey(key, nullptr, nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr, nullptr, &stamp);
        RegCloseKey(key);
    }
    return stamp;
}

// The pinned apps read again when the list is read for the first time or
// Windows changed it (looked at once a second at most; only with the
// option on).
void RefreshPinnedApps() {
    if (!g_settings.dockSeparator) {
        return;
    }
    const double now = NowSeconds();
    if (g_pinnedRead && now - g_pinnedCheckAt < 1) {
        return;
    }
    g_pinnedCheckAt = now;
    const FILETIME stamp = PinnedListStamp();
    if (g_pinnedRead && CompareFileTime(&stamp, &g_pinnedStamp) == 0) {
        return;
    }
    g_pinnedStamp = stamp;
    g_pinnedApps = ReadPinnedAppIds();
    g_pinnedRead = true;
    g_pinnedVersion++;
    StartRendering();
}

// 1 for an app pinned to the taskbar, 0 for one that isn't, -1 for a button
// that isn't an app (or an app not known yet).
int DockIconKind(DockIcon& icon, FrameworkElement const& button) {
    if (!icon.app || !g_pinnedRead) {
        return -1;
    }
    if (icon.pinnedVersion != g_pinnedVersion) {
        const std::wstring id = GetButtonAppId(button);
        if (id.empty()) {
            return -1;
        }
        icon.pinnedVersion = g_pinnedVersion;
        icon.pinned = std::any_of(g_pinnedApps.begin(), g_pinnedApps.end(),
                                  [&](const std::wstring& pinned) {
                                      return _wcsicmp(pinned.c_str(),
                                                      id.c_str()) == 0;
                                  })
                          ? 1
                          : 0;
    }
    return icon.pinned;
}

// Where the dock's line goes: the index of the first app that isn't pinned
// after the last one that is, or kinds.size() for none. `kinds`: each button
// as DockIconKind says, in the order shown.
size_t DockSeparatorIndex(const std::vector<int>& kinds) {
    size_t lastPinned = kinds.size();
    for (size_t i = 0; i < kinds.size(); i++) {
        if (kinds[i] == 1) {
            lastPinned = i;
        }
    }
    if (lastPinned == kinds.size()) {
        return kinds.size();
    }
    for (size_t i = lastPinned + 1; i < kinds.size(); i++) {
        if (kinds[i] == 0) {
            return i;
        }
    }
    return kinds.size();
}

// Finds the dock's buttons and prepares the ones it hasn't seen yet. Called
// again whenever the number of buttons changes.
void RescanDockIcons() {
    auto frame = g_dockFrame.get();
    if (!frame) {
        return;
    }

    std::erase_if(g_dockIcons, [](const DockIcon& icon) {
        return !icon.button.get();
    });

    std::vector<FrameworkElement> buttons;
    FindAllByClassName(frame,
                       {L"Taskbar.TaskListButton",
                        L"Taskbar.ExperienceToggleButton",
                        L"Taskbar.SearchBoxButton",
                        L"Taskbar.AugmentedEntryPointButton"},
                       buttons);

    // A button that comes once the dock is set up is an app opening: it
    // grows in (not the ones there from the start).
    const bool opening = g_dockItemCount >= 0 && NowSeconds() - g_dockSince > 1;
    bool added = false;
    for (const auto& button : buttons) {
        if (FindDockIcon(button)) {
            continue;
        }

        // The whole button grows and bounces. The icon image inside it isn't
        // touched, because the taskbar animates it itself when it's pressed,
        // and replacing its transform breaks that.
        DockIcon icon;
        icon.button = winrt::make_weak(button);
        if (auto image = FindByName(button, L"Icon")) {
            icon.image = winrt::make_weak(image);
        }
        Media::TransformGroup transforms;
        transforms.Children().Append(icon.scale = Media::ScaleTransform());
        transforms.Children().Append(icon.lift = Media::TranslateTransform());
        if (AnimatesIcons()) {
            SetStyled(button, UIElement::RenderTransformProperty(), transforms);
        }
        // The scaling origin is set in pixels on the scale itself (see
        // OnRendering), so the relative origin stays at the corner.
        if (AnimatesIcons()) {
            SetStyled(button, UIElement::RenderTransformOriginProperty(),
                      winrt::box_value(winrt::Windows::Foundation::Point{0, 0}));
        }
        // (Its room in the row, set each frame.)
        if (AnimatesIcons()) {
            icon.clip = Media::RectangleGeometry();
            SetStyled(button, UIElement::ClipProperty(), icon.clip);
        }
        icon.app = winrt::get_class_name(button) == L"Taskbar.TaskListButton";
        if (opening && icon.app) {
            icon.appear = 0;
            added = true;
        }
        g_dockIcons.push_back(icon);
        DockIcon& newIcon = g_dockIcons.back();

        const bool watched =
            std::any_of(g_watchedButtons.begin(), g_watchedButtons.end(),
                        [&](const auto& weak) { return weak.get() == button; });
        if (!watched &&
            winrt::get_class_name(button) == L"Taskbar.TaskListButton") {
            g_watchedButtons.push_back(winrt::make_weak(button));
            WatchRunningState(button);
        }
        if (g_settings.dotIndicator && IsDock()) {
            MakeDots(newIcon, button);
        }

        // No highlight behind the icon on hover or for the active app, nor
        // the plate stacked behind it for an app with more windows, like on
        // macOS. Hidden rather than recolored, because the button's visual
        // states set their color.
        std::vector<FrameworkElement> highlights;
        if (AnimatesIcons()) {
            FindAllByName(button, L"BackgroundElement", highlights);
            FindAllByName(button, L"MultiWindowElement", highlights);
        }
        for (const auto& highlight : highlights) {
            SetStyled(highlight, UIElement::VisibilityProperty(),
                      winrt::box_value(Visibility::Collapsed));
        }
    }
    if (added && AnimatesIcons()) {
        StartRendering();
    }
}

// Height of the icon's bounce right now, in pixels (negative is up), for a
// bounce at most `maxHeight` high.
double BounceOffset(DockIcon& icon, double now, double maxHeight) {
    if (!icon.bounceStart) {
        return 0;
    }
    // Bounces are decorations (none from the "partial" level on), at the
    // chosen speed.
    if (AnimationLevel() >= 1) {
        icon.bounceStart = 0;
        return 0;
    }
    bool done;
    const double height = BounceSequence(
        AnimationDt(now - icon.bounceStart), icon.bounceGroups, &done);
    if (done) {
        icon.bounceStart = 0;
        return 0;
    }
    return -std::max(maxHeight, 0.0) * height;
}

// Cuts the transparent taskbar's window down to its apps (and a margin), and
// puts its shadow behind them. `left` and `right` are the apps' extent, in
// the taskbar's XAML coordinates. Only done when it changes (an app opened or
// closed): the shadow's size is part of the layout.
void PlaceShadow(double left, double right) {
    if (left == g_shadowLeft && right == g_shadowRight) {
        return;
    }
    Safely(L"Placing the shadow", [&] {
        auto fill = g_shadowFill.get().try_as<FrameworkElement>();
        if (!fill) {
            return;
        }
        double parentLeft = 0;
        if (auto parent =
                Media::VisualTreeHelper::GetParent(fill).try_as<UIElement>()) {
            parentLeft = parent.TransformToVisual(nullptr)
                             .TransformPoint({0, 0})
                             .X;
        }
        SetStyled(fill, FrameworkElement::HorizontalAlignmentProperty(),
                  winrt::box_value(HorizontalAlignment::Left));
        SetStyled(fill, FrameworkElement::MarginProperty(),
                  winrt::box_value(ThicknessHelper::FromLengths(
                      std::max(0.0, left - kShadowMargin - parentLeft), 0, 0,
                      0)));
        SetStyled(fill, FrameworkElement::WidthProperty(),
                  winrt::box_value(right - left + kShadowMargin * 2));
        g_shadowLeft = left;
        g_shadowRight = right;
    });
}

// `withShadow`: also puts the shadow behind the apps (XAML, so only from the
// taskbar's own drawing, not while Windows moves it). `own`: the part of the
// window it may show (see ClipSlideStep), or the one on its monitor.
void UpdateAppsArea(double left,
                    double right,
                    bool withShadow,
                    const RECT* own = nullptr) {
    if (!g_dockWnd) {
        return;
    }
    if (withShadow) {
        PlaceShadow(left, right);
    }
    const double scale = GetDpiForWindow(g_dockWnd) / 96.0;
    RECT window{};
    if (!GetWindowRect(g_dockWnd, &window)) {
        return;
    }
    RECT region{(LONG)std::floor((left - kAppsAreaMargin) * scale), 0,
                (LONG)std::ceil((right + kAppsAreaMargin) * scale),
                window.bottom - window.top};
    region.left = std::max(region.left, 0L);
    region.right = std::min(region.right, window.right - window.left);
    // Laid out again at a new scale (see g_dockScaleSettled): its apps'
    // places are stale for a moment, and Windows would take the mouse past
    // them for leaving and hide it again at once. Its whole width meanwhile
    // (nothing of it shows yet).
    if (!g_dockScaleSettled) {
        region.left = 0;
        region.right = window.right - window.left;
    }
    // Only what's on its own monitor (hidden, the rest is past its edge,
    // maybe over the next monitor: Windows' own clip, which this region
    // replaces, leaves only that part too).
    const RECT shown = own ? *own : TaskbarOwnPart(g_dockWnd);
    region.top = std::max(region.top, shown.top);
    region.bottom = std::min(region.bottom, shown.bottom);
    if (region.right <= region.left || region.bottom <= region.top) {
        return;
    }
    g_appsLeft = left;
    g_appsRight = right;
    // Already in place (Windows sometimes sets the taskbar's region itself,
    // which drops this one: then it's made again).
    RECT current{};
    const int kind = GetWindowRgnBox(g_dockWnd, &current);
    if (EqualRect(&region, &g_appsRegion) && kind != ERROR &&
        kind != NULLREGION && EqualRect(&current, &region)) {
        return;
    }
    // (Also when Windows dropped it, as its own moves do: set again.)
    HRGN handle = CreateRectRgnIndirect(&region);
    if (!handle) {
        return;
    }
    // The system owns the region once it's set.
    if (!SetWindowRgn(g_dockWnd, handle, RedrawsWithCut(g_dockWnd))) {
        DeleteObject(handle);
        return;
    }
    g_appsRegion = region;
    g_appsAreaMonitor = TaskbarMonitor(g_dockWnd);
    SetAppsArea(g_appsAreaMonitor, window.left + region.left,
                window.left + region.right);
}

// The shadow: an ellipse centered on the bottom edge, dark in its middle and
// fading out to nothing at its edges, so it has no corners.
void MakeShadow(UIElement const& element) {
    namespace Composition = winrt::Windows::UI::Composition;
    try {
        auto compositor =
            Hosting::ElementCompositionPreview::GetElementVisual(element)
                .Compositor();
        auto gradient = compositor.CreateRadialGradientBrush();
        gradient.EllipseCenter({0.5f, 1.0f});
        gradient.EllipseRadius({0.5f, 1.0f});
        const std::pair<float, uint8_t> kStops[] = {
            {0.0f, 0xC4}, {0.35f, 0x98}, {0.65f, 0x4C}, {0.85f, 0x1A},
            {1.0f, 0x00}};
        for (const auto& [offset, alpha] : kStops) {
            gradient.ColorStops().Append(compositor.CreateColorGradientStop(
                offset, winrt::Windows::UI::Color{alpha, 0, 0, 0}));
        }
        auto visual = compositor.CreateSpriteVisual();
        visual.Brush(gradient);
        // As big as the element, whatever its size.
        visual.RelativeSizeAdjustment({1.0f, 1.0f});
        Hosting::ElementCompositionPreview::SetElementChildVisual(element,
                                                                 visual);
        g_shadowVisual = visual;
    } catch (const winrt::hresult_error& e) {
        IslandLog(L"The shadow couldn't be made: %08X", (unsigned)e.code());
    }
}

void ResetAppsArea() {
    if (g_dockWnd && (g_appsRegion.right > g_appsRegion.left)) {
        SetWindowRgn(g_dockWnd, nullptr, TRUE);
    }
    g_appsRegion = {};
    g_appsLeft = g_appsRight = 0;
    g_shadowLeft = g_shadowRight = 0;
    SetAppsArea(g_appsAreaMonitor, 0, 0);
    g_appsAreaMonitor = nullptr;
}

bool OnRenderingUnsafe(double now, double dt);
void RaiseOverWindows(HWND hTaskbarWnd);

// The frame's own opacity back (see g_dockScaleSettled).
void RestoreDockOpacity(FrameworkElement const& frame) {
    if (!g_dockOpacityKept ||
        g_dockOpacityKept == DependencyProperty::UnsetValue()) {
        frame.ClearValue(UIElement::OpacityProperty());
    } else {
        frame.SetValue(UIElement::OpacityProperty(), g_dockOpacityKept);
    }
    g_dockOpacityKept = nullptr;
}

// A frame for every taskbar (the main one and the other monitors'): stops
// once none is moving anymore.
void OnRendering(winrt::Windows::Foundation::IInspectable const&,
                 winrt::Windows::Foundation::IInspectable const&) {
    const double now = NowSeconds();
    // Under a frame rate limit, some of the taskbar's frames are skipped.
    if (const int limit = g_frameRateLimit.load(std::memory_order_relaxed);
        limit && now - g_lastRenderTime < 1.0 / limit - 0.002) {
        return;
    }
    const double dt =
        AnimationDt(std::clamp(now - g_lastRenderTime, 0.0, 0.05));
    g_lastRenderTime = now;
    bool failed = true;
    bool busy = false;
    Safely(L"Drawing the icons", [&] {
        busy = OnRenderingUnsafe(now, dt);
        // (Taskbars gone with their monitor are let go, with their apps
        // area and their clip.)
        std::erase_if(g_otherDocks, [](const auto& state) {
            if (IsWindow(state->wnd)) {
                return false;
            }
            SetAppsArea(state->appsAreaMonitor, 0, 0);
            std::erase(g_ownClips, state->wnd);
            if (state->notificationTimer) {
                state->notificationTimer.Stop();
            }
            return true;
        });
        for (auto& state : g_otherDocks) {
            DockScope scope(state->wnd);
            busy = OnRenderingUnsafe(now, dt) || busy;
        }
        failed = false;
    });
    // Tried again on the next change, not every frame.
    if (failed || !busy) {
        g_renderingRevoker.revoke();
    }
}

// One taskbar's frame; whether it's still moving.
bool OnRenderingUnsafe(double now, double dt) {
    auto frame = g_dockFrame.get();
    if (!frame || g_unloading || !AnimatesIcons()) {
        if (frame && g_dockContentHidden) {
            RestoreDockOpacity(frame);
            g_dockContentHidden = false;
        }
        g_dockScaleSettled = true;
        return false;
    }

    // The mouse, in the taskbar's XAML coordinates, and the XAML's size: its
    // own layout's, pixels per DIP from its width against the window's (its
    // scale can lag behind the window's as it moves over a monitor with
    // another scale, and its RasterizationScale can be the monitor's below,
    // where the hidden taskbar mostly was).
    auto xamlRoot = frame.XamlRoot();
    RECT client{};
    GetClientRect(g_dockWnd, &client);
    auto content =
        xamlRoot ? xamlRoot.Content().try_as<FrameworkElement>() : nullptr;
    // (Build 26320: the content is the frame itself, centered and as wide as
    // its icons; the window's size is then the XamlRoot's.)
    double rootWidth = content ? content.ActualWidth() : 0;
    double rootHeight = content ? content.ActualHeight() : 0;
    if (content && xamlRoot &&
        winrt::get_class_name(content) == L"Taskbar.TaskbarFrame") {
        rootWidth = xamlRoot.Size().Width;
        rootHeight = xamlRoot.Size().Height;
    }
    double scale = GetDpiForWindow(g_dockWnd) / 96.0;
    if (rootWidth > 0 && client.right > 0) {
        scale = client.right / rootWidth;
    } else if (xamlRoot) {
        scale = xamlRoot.RasterizationScale();
    }
    POINT pt;
    double mouseX = 0, mouseY = -1;
    if (GetCursorPos(&pt) && ScreenToClient(g_dockWnd, &pt)) {
        mouseX = pt.x / scale;
        mouseY = pt.y / scale;
    }
    const double clientWidth = rootWidth > 0
                                   ? rootWidth
                                   : client.right / scale;
    const double clientHeight = rootHeight > 0
                                    ? rootHeight
                                    : client.bottom / scale;

    // The dock: its measures (within the taskbar's own height when it doesn't
    // hide itself, see GrownTaskbar), and the line its icons stand on, above
    // their dots. The transparent taskbar's icons rest on its middle line.
    const bool dock = IsDock();
    const GrownTaskbar* grown = FindGrownTaskbar(g_dockWnd);
    const DockMetrics metrics = GetDockMetrics(
        g_taskbarAutoHides ? 0
                           : clientHeight - (grown ? grown->extraDips : 0));
    const double shelfBottom = clientHeight - metrics.bottomGap;
    const double restBottom = shelfBottom - metrics.padBottom - metrics.dotRoom;
    const double middle = clientHeight / 2;

    struct Placed {
        DockIcon* icon;
        FrameworkElement button{nullptr};
        double center;
        double buttonTop;
        double buttonWidth;
        // The icon image, in the button's coordinates.
        double iconTop;
        double iconHeight;
        // The highest part drawn with the icon: its top, or the top of the
        // notification badge on it; and the badge's right edge (0 without
        // one). In the button's coordinates.
        double contentTop;
        double badgeRight;
        // Its size at rest (the dock's icon size over the taskbar's), how
        // wide it's drawn then (its icon, or its whole button with its
        // name), its room in the row (the gap after it included), and where
        // its middle is then.
        double base = 1;
        double width = 0;
        double slot = 0;
        double restCenter = 0;
        // How much wider than at rest it's drawn now.
        double grow = 0;
        // Room before it for the separator (see dock.separator).
        double lead = 0;
    };
    std::vector<Placed> placed;
    placed.reserve(g_dockIcons.size());
    double left = std::numeric_limits<double>::max();
    double right = std::numeric_limits<double>::lowest();
    for (auto& icon : g_dockIcons) {
        auto button = icon.button.get();
        if (!button || button.ActualWidth() <= 0) {
            continue;
        }
        auto parent =
            Media::VisualTreeHelper::GetParent(button).try_as<UIElement>();
        if (!parent) {
            continue;
        }
        // The layout position, without the mod's own transforms.
        const auto offset = button.ActualOffset();
        const auto origin = parent.TransformToVisual(nullptr).TransformPoint(
            {offset.x, offset.y});
        const double width = button.ActualWidth();
        const double height = button.ActualHeight();
        // Windows keeps some buttons far off the window (like a hidden
        // Snipping Tool one): not among the apps.
        if (origin.X + width < 0 || origin.X > clientWidth ||
            button.Visibility() != Visibility::Visible) {
            continue;
        }

        // Buttons without an icon image (like Start) use their middle part.
        double iconTop = height * 0.2;
        double iconHeight = height * 0.6;
        // The layout position, not the drawn one: the taskbar's own press
        // animation shrinks the image, which mustn't move the icon around.
        if (auto image = icon.image.get(); image && image.ActualHeight() > 0) {
            if (auto imageParent = Media::VisualTreeHelper::GetParent(image)
                                       .try_as<UIElement>()) {
                const auto imageOffset = image.ActualOffset();
                iconTop = imageParent.TransformToVisual(button)
                              .TransformPoint({imageOffset.x, imageOffset.y})
                              .Y;
                iconHeight = image.ActualHeight();
            }
        }
        if (iconHeight <= 0) {
            continue;
        }

        left = std::min(left, (double)origin.X);
        right = std::max(right, origin.X + width);
        // The badge sits on the icon's top corner and grows with it.
        double contentTop = iconTop;
        double badgeRight = 0;
        // (Where it's drawn: the taskbar moves it with its own transform.)
        if (auto badge = icon.badge.get(); badge && IsBadgeShown(icon)) {
            const auto bounds = badge.TransformToVisual(button).TransformBounds(
                {0, 0, (float)badge.ActualWidth(),
                 (float)badge.ActualHeight()});
            contentTop = std::min(contentTop, (double)bounds.Y);
            badgeRight = bounds.X + bounds.Width;
        }
        // (And the other small parts over its corners, measured every second:
        // an app's overlay icon, the badges of the other monitors' docks.)
        if (icon.extrasRight > 0) {
            contentTop = std::min(contentTop, icon.extrasTop);
            badgeRight = std::max(badgeRight, icon.extrasRight);
        }

        Placed item{&icon,      button,     origin.X + width / 2,
                    origin.Y,   width,      iconTop,
                    iconHeight, contentTop, badgeRight};
        placed.push_back(item);
    }

    // At rest, the dock's icons are side by side at its icon size, centered
    // where the taskbar centers its buttons; the transparent taskbar's stay
    // where the taskbar puts them.
    std::sort(placed.begin(), placed.end(),
              [](const Placed& a, const Placed& b) { return a.center < b.center; });
    double rowWidth = 0;
    for (auto& item : placed) {
        // (With their names shown, "Combine taskbar buttons" off, buttons are
        // wide: drawn whole.)
        // (Those keep the taskbar's size.)
        const bool wide = item.buttonWidth > item.iconHeight * 3;
        item.base = dock && !wide
                        ? std::max(0.5, metrics.icon / item.iconHeight)
                        : 1.0;
        item.width = wide ? item.buttonWidth : item.iconHeight * item.base;
        item.slot = dock ? item.width + metrics.gap : item.buttonWidth;
        rowWidth += item.slot;
    }
    // The line between the pinned apps and the others (dock.separator): the
    // first one after them gets room before it, where the line goes.
    size_t separatorAt = placed.size();
    if (dock && g_settings.dockSeparator && g_pinnedRead) {
        std::vector<int> kinds;
        for (auto& item : placed) {
            kinds.push_back(DockIconKind(*item.icon, item.button));
        }
        separatorAt = DockSeparatorIndex(kinds);
        if (separatorAt < placed.size()) {
            placed[separatorAt].lead = kDockSeparatorRoom;
            rowWidth += kDockSeparatorRoom;
        }
    }
    // (A box, with more apps than fit in the widest the dock gets: its ends,
    // where the row is cut; far off otherwise.)
    constexpr double kNoBox = 1e9;
    // The arrow that pins or hides the dock, after its last icon: the row
    // and it are centered together.
    const double pinSize =
        dock && g_settings.dockPinButton && g_dockShelf.pin
            ? std::max(12.0, metrics.icon * 0.5)
            : 0;
    const double pinRoom = pinSize > 0 ? metrics.gap + pinSize : 0;
    double boxLeft = -kNoBox;
    double boxRight = kNoBox;
    g_dockScrollMax = 0;
    if (dock && !placed.empty()) {
        rowWidth -= placed.back().slot - placed.back().width;
        const auto bounds = frame.TransformToVisual(nullptr).TransformBounds(
            {0, 0, (float)frame.ActualWidth(), (float)frame.ActualHeight()});
        const double widest =
            g_settings.dockMaxWidth > 0
                ? bounds.Width * g_settings.dockMaxWidth / 100.0 -
                      metrics.padSide * 2
                : 0;
        double shown = rowWidth;
        if (widest > metrics.icon && rowWidth > widest) {
            shown = widest;
            g_dockScrollMax = rowWidth - widest;
            boxLeft = bounds.X + bounds.Width / 2 - (shown + pinRoom) / 2;
            boxRight = boxLeft + shown;
        }
        g_dockScrollStep = metrics.icon + metrics.gap;
        g_dockScroll = std::clamp(g_dockScroll, 0.0, g_dockScrollMax);
        double x = bounds.X + bounds.Width / 2 - (shown + pinRoom) / 2 -
                   g_dockScroll;
        for (auto& item : placed) {
            x += item.lead;
            item.restCenter = x + item.width / 2;
            x += item.slot;
        }
    } else {
        for (auto& item : placed) {
            item.restCenter = item.center;
        }
    }
    // The dock's shelf at rest, around its icons.
    double restLeft = placed.empty() ? 0
                                     : placed.front().restCenter -
                                           placed.front().width / 2 -
                                           metrics.padSide;
    double restRight = placed.empty() ? 0
                                      : placed.back().restCenter +
                                            placed.back().width / 2 +
                                            metrics.padSide;
    // (In a box, its ends.)
    if (boxLeft > -kNoBox) {
        restLeft = boxLeft - metrics.padSide;
        restRight = boxRight + metrics.padSide;
    }
    if (!placed.empty()) {
        restRight += pinRoom;
    }
    const double restTop = restBottom - metrics.icon - metrics.padTop;

    // After a scale change: settled one frame after its buttons moved (see
    // g_dockScaleSettled), or after a while if they never do.
    if (!g_dockScaleSettled) {
        bool moved = false;
        for (const auto& item : placed) {
            if (!std::isnan(item.icon->lastCenter) &&
                std::fabs(item.restCenter - item.icon->lastCenter) > 0.5) {
                moved = true;
            }
        }
        if ((g_dockScaleMoved && !moved) ||
            now - g_dockScaleChangedAt > kDockScaleHideSeconds) {
            g_dockScaleSettled = true;
        }
        g_dockScaleMoved = g_dockScaleMoved || moved;
    }
    bool ownScale = true;
    if (const HMONITOR monitor = TaskbarMonitor(g_dockWnd)) {
        UINT dpiX = 0;
        UINT dpiY = 0;
        MONITORINFO info{sizeof(info)};
        RECT window{};
        const bool inside = GetMonitorInfo(monitor, &info) &&
                            GetWindowRect(g_dockWnd, &window) &&
                            window.top >= info.rcMonitor.top &&
                            window.bottom <= info.rcMonitor.bottom;
        if (!inside && SUCCEEDED(GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI,
                                                  &dpiX, &dpiY))) {
            ownScale = dpiX == GetDpiForWindow(g_dockWnd);
        }
    }
    const bool hideContent = !g_dockScaleSettled || !ownScale;
    if (hideContent != g_dockContentHidden) {
        g_dockContentHidden = hideContent;
        if (hideContent) {
            g_dockOpacityKept =
                frame.ReadLocalValue(UIElement::OpacityProperty());
            frame.Opacity(0);
        } else {
            RestoreDockOpacity(frame);
        }
        // (The shelf with the icons: it's not in their frame.)
        if (auto host = g_dockBackground.get();
            host && host.Name() == kDockShelfHostName) {
            host.Opacity(hideContent ? 0 : 1);
        }
    }

    // The mouse on the dock: on its shelf, as big as it grew last frame (its
    // magnified icons included); on the transparent taskbar, over its apps.
    bool hovering = false;
    if (!placed.empty() && mouseY <= clientHeight + 2) {
        if (dock) {
            const double shelfLeft = std::min(restLeft, (double)g_dockShelfNow.X);
            const double shelfRight = std::max(
                restRight, (double)(g_dockShelfNow.X + g_dockShelfNow.Width));
            const double shelfTop = g_dockShelfNow.Height > 0
                                        ? std::min(restTop,
                                                   (double)g_dockShelfNow.Y)
                                        : restTop;
            hovering = mouseX >= shelfLeft - 2 && mouseX <= shelfRight + 2 &&
                       mouseY >= shelfTop - 2;
        } else {
            hovering = mouseY >= 0 && mouseX >= left - 16 &&
                       mouseX <= right + 16;
        }
    }
    const double follow = AnimationLevel() >= 2
                              ? 1.0
                              : 1 - std::exp(-dt * kMagnificationFollow);

    bool busy = hovering || !g_dockScaleSettled;
    // The icons still moving (growing, sliding, bouncing).
    bool moving = false;

    // The transparent taskbar's shadow: stronger over light windows, and
    // with the mouse on the taskbar.
    if (auto fill = g_shadowFill.get()) {
        const bool over = mouseY >= 0 && mouseY <= clientHeight + 2 &&
                          mouseX >= 0 && mouseX <= clientWidth;
        const double target =
            g_dockContentHidden
                ? 0.0
                : std::min(1.0, 0.66 + 0.28 * g_backdropLight +
                                    (over ? 0.12 : 0.0));
        if (g_dockContentHidden) {
            g_shadowStrength = 0;
        }
        g_shadowStrength += (target - g_shadowStrength) * (1 - std::exp(-dt * 8));
        if (std::fabs(target - g_shadowStrength) < 0.003) {
            g_shadowStrength = target;
        } else {
            busy = true;
        }
        if (std::fabs(fill.Opacity() - g_shadowStrength) > 0.002) {
            fill.Opacity(g_shadowStrength);
        }
        if (over) {
            busy = true;
        }
    }

    // A wave around the mouse, measured from where the icons rest (not from
    // where they're pushed to, which would chase the mouse): the icon under
    // it grows the most. Each icon grows from its bottom edge, and its
    // neighbors make room for it, so it never covers them.
    double rowGrow = 0;
    for (auto& item : placed) {
        DockIcon& icon = *item.icon;
        icon.baseScale = item.base;
        // The icon's bottom edge, which stays put.
        const double iconBottom =
            dock ? restBottom : middle + item.iconHeight / 2;
        // Never taller than the space up to the top of the window, badge
        // included. `reach` is how far the content goes above the bottom.
        const double reach =
            (item.iconTop + item.iconHeight - item.contentTop) * item.base;
        double maxScale = std::max(
            1.0, std::min(g_settings.magnification, (iconBottom - 1) / reach));
        // Wide buttons grow with their text: only a few pixels.
        if (item.buttonWidth > item.iconHeight * 3) {
            maxScale = std::min(maxScale, 1 + 12 / item.buttonWidth);
        }
        // (As big as it's drawn: last frame's size, see BigAppIcon.)
        if (icon.app) {
            UseBigIcon(icon, item.button,
                       (int)std::ceil(item.iconHeight * item.base *
                                      std::max(1.0, icon.magnification) *
                                      scale));
            UseBigOverlay(icon, item.button,
                          item.base * std::max(1.0, icon.magnification) *
                              scale);
        }

        double target = 1;
        if (hovering && maxScale > 1 && item.restCenter >= boxLeft &&
            item.restCenter <= boxRight) {
            const double distance = std::fabs(mouseX - item.restCenter) /
                                    g_settings.magnificationRange;
            if (distance < 1) {
                const double bell = 0.5 + 0.5 * std::cos(3.14159265 * distance);
                target = 1 + (maxScale - 1) * bell;
            }
        }
        icon.magnification += (target - icon.magnification) * follow;
        if (std::fabs(target - icon.magnification) < 0.002) {
            icon.magnification = target;
        } else {
            moving = true;
        }
        item.grow = item.width * (icon.magnification - 1);
        rowGrow += item.grow;
    }

    double before = 0;
    // (The line's middle: between the icon before it and the one after, as
    // they're drawn.)
    double separatorX = NAN;
    double separatorPrevRight = 0;
    double drawnLeft = std::numeric_limits<double>::max();
    double drawnRight = std::numeric_limits<double>::lowest();
    double tallest = metrics.icon;
    const double edgeLeft = boxLeft - rowGrow / 2;
    const double edgeRight = boxRight + rowGrow / 2;
    for (auto& item : placed) {
        DockIcon& icon = *item.icon;
        const double base = item.base;
        const double iconBottom =
            dock ? restBottom : middle + item.iconHeight / 2;
        // Moves the icon's bottom edge to where it rests.
        const double align =
            iconBottom - (item.buttonTop + item.iconTop + item.iconHeight);
        const double reach =
            (item.iconTop + item.iconHeight - item.contentTop) * base;

        // Grows upwards from the icon's bottom edge, around the button's
        // middle, like on macOS.
        const double originY = item.iconTop + item.iconHeight;
        // Growing in when its app opened.
        if (SpringTowards(icon.appear, icon.appearVelocity, 1, 0.42, dt,
                          0.72)) {
            moving = true;
        }
        const double appear = std::max(icon.appear, 0.0);
        const double drawnScale = icon.magnification * base * appear;
        icon.scale.CenterX(item.buttonWidth / 2);
        icon.scale.CenterY(originY);
        icon.scale.ScaleX(drawnScale);
        icon.scale.ScaleY(drawnScale);
        if (icon.overlayKeep) {
            const double keep =
                icon.overlayCounted || drawnScale <= 0.01 ? 1 : 1 / drawnScale;
            if (std::fabs(icon.overlayKeep.ScaleX() - keep) > 0.001) {
                icon.overlayKeep.ScaleX(keep);
                icon.overlayKeep.ScaleY(keep);
            }
        }

        // Moved (an app opened or closed next to it, or the taskbar's
        // buttons centered again): it slides there from where it was (not
        // while an icon is dragged, which the taskbar moves itself, nor just
        // after its scale changed: see g_dockScaleChangedAt).
        if (!std::isnan(icon.lastCenter) &&
            std::fabs(item.restCenter - icon.lastCenter) > 0.5 &&
            !(GetAsyncKeyState(VK_LBUTTON) & 0x8000) &&
            now - g_dockScaleChangedAt > kDockScaleSettleSeconds) {
            icon.slide += icon.lastCenter - item.restCenter;
        }
        icon.lastCenter = item.restCenter;
        if (SpringTowards(icon.slide, icon.slideVelocity, 0, 0.36, dt)) {
            moving = true;
        }
        // Its middle now: pushed aside by the icons growing before it, the
        // whole row widening on both sides.
        const double center =
            item.restCenter + before + item.grow / 2 - rowGrow / 2 + icon.slide;
        before += item.grow;
        icon.lift.X(center - item.center);

        // The bounce uses what's left above the (possibly magnified) icon.
        const double bounceRoom = iconBottom - 1 - reach * icon.magnification;
        const double bounceHeight =
            dock ? std::min(item.width * kDockBounce, bounceRoom)
                 : std::min({item.iconHeight * 0.6, 14.0, bounceRoom});
        const double bounce = BounceOffset(icon, now, bounceHeight);
        icon.lift.Y(align + bounce);
        if (icon.bounceStart) {
            moving = true;
        }

        UpdateDots(icon, {item.buttonTop, originY, align + bounce, iconBottom,
                          dock ? shelfBottom : clientHeight});

        // It takes the mouse only in its own room in the row (its neighbors
        // take theirs), its badge included: in the button's coordinates,
        // before the scale.
        if (icon.clip && drawnScale > 0.05) {
            const double half =
                (item.slot + item.grow) / 2 / drawnScale;
            const double middleX = item.buttonWidth / 2;
            // (A little more for the badge's antialiased edge.)
            // (In a box, cut at its ends.)
            const double clipLeft = std::max(
                middleX - half, middleX + (edgeLeft - center) / drawnScale);
            const double clipRight = std::min(
                std::max(middleX + half,
                         item.badgeRight > 0
                             ? item.badgeRight + 2 / drawnScale
                             : 0.0),
                middleX + (edgeRight - center) / drawnScale);
            const winrt::Windows::Foundation::Rect rect{
                (float)clipLeft, -2000.0f,
                (float)std::max(clipRight - clipLeft, 0.0), 4000.0f};
            if (std::fabs(rect.X - icon.clipRect.X) > 0.05f ||
                std::fabs(rect.Width - icon.clipRect.Width) > 0.05f) {
                icon.clipRect = rect;
                icon.clip.Rect(rect);
            }
        }

        const double drawnHalf = item.width * icon.magnification * appear / 2;
        const size_t position = (size_t)(&item - placed.data());
        if (position + 1 == separatorAt) {
            separatorPrevRight = center + drawnHalf;
        }
        if (position == separatorAt) {
            separatorX = (separatorPrevRight + center - drawnHalf) / 2;
        }
        drawnLeft = std::max(std::min(drawnLeft, center - drawnHalf), edgeLeft);
        drawnRight =
            std::min(std::max(drawnRight, center + drawnHalf), edgeRight);
        tallest = std::max(tallest, item.iconHeight * base *
                                        icon.magnification * appear);
    }
    busy = busy || moving;
    // (The arrow after the last icon as it's drawn.)
    double pinCenter = NAN;
    if (pinRoom > 0 && !placed.empty()) {
        pinCenter = drawnRight + metrics.gap + pinSize / 2;
        drawnRight += pinRoom;
    }

    // The transparent taskbar takes the mouse around its apps, magnified
    // ones included (in steps, not set again every frame), and puts its
    // shadow behind them.
    if (IsTransparentTaskbar() && !placed.empty()) {
        PlaceShadow(left, right);
        UpdateAppsArea(std::min(left, std::floor(drawnLeft / 8) * 8),
                       std::max(right, std::ceil(drawnRight / 8) * 8), false);
    }

    if (dock) {
        // The shelf around the icons as they're drawn, as high as the
        // tallest one.
        const winrt::Windows::Foundation::Rect shelf =
            placed.empty()
                ? winrt::Windows::Foundation::Rect{}
                : winrt::Windows::Foundation::Rect{
                      (float)(drawnLeft - metrics.padSide),
                      (float)(restBottom - tallest - metrics.padTop),
                      (float)(drawnRight - drawnLeft + metrics.padSide * 2),
                      (float)(shelfBottom -
                              (restBottom - tallest - metrics.padTop))};
        g_dockShelfNow = shelf;
        if (auto background = g_dockBackground.get()) {
            const auto origin =
                background.TransformToVisual(nullptr).TransformPoint({0, 0});
            PlaceDockShelf(
                g_dockShelf,
                {shelf.X - origin.X, shelf.Y - origin.Y, shelf.Width,
                 shelf.Height},
                std::min(g_settings.cornerRadius, (double)shelf.Height / 2));
            if (auto pin = g_dockShelf.pin) {
                if (std::isnan(pinCenter)) {
                    if (pin.Visibility() != Visibility::Collapsed) {
                        pin.Visibility(Visibility::Collapsed);
                    }
                    g_dockShelf.pinRect = {};
                } else {
                    const double pinMiddle = restBottom - metrics.icon / 2;
                    g_dockShelf.pinRect = {
                        (float)(pinCenter - pinSize / 2 - metrics.gap / 2),
                        (float)restTop,
                        (float)(pinSize + metrics.gap / 2 + metrics.padSide),
                        (float)(shelfBottom - restTop)};
                    const int shows = DockHidesOn(g_dockWnd) ? 2 : 1;
                    if (shows != g_dockShelf.pinShows) {
                        g_dockShelf.pinShows = shows;
                        // (Down: hide it. Up: keep it.)
                        pin.Glyph(shows == 1 ? L"\uE70D" : L"\uE70E");
                    }
                    const auto& r = g_dockShelf.pinRect;
                    const bool hovered = mouseX >= r.X &&
                                         mouseX <= r.X + r.Width &&
                                         mouseY >= r.Y &&
                                         mouseY <= r.Y + r.Height;
                    if (hovered != g_dockShelf.pinHovered) {
                        g_dockShelf.pinHovered = hovered;
                        pin.Opacity(hovered ? 1.0 : 0.6);
                    }
                    if (pin.Visibility() != Visibility::Visible) {
                        pin.Visibility(Visibility::Visible);
                    }
                    pin.Width(pinSize);
                    pin.Height(pinSize);
                    pin.FontSize(pinSize * 0.8);
                    Controls::Canvas::SetLeft(
                        pin, pinCenter - pinSize / 2 - origin.X);
                    Controls::Canvas::SetTop(
                        pin, pinMiddle - pinSize / 2 - origin.Y);
                }
            }
            // The line between the pinned apps and the others, as tall as
            // the icons at rest (not past the ends of a box).
            if (g_settings.dockSeparator) {
                PlaceDockSeparator(
                    g_dockShelf,
                    separatorAt < placed.size() && !std::isnan(separatorX) &&
                        separatorX > edgeLeft && separatorX < edgeRight,
                    separatorX - origin.X,
                    restBottom - metrics.icon * 0.85 - origin.Y,
                    metrics.icon * 0.7);
            }
        }

        // The window takes the mouse only on the taskbar's own height and
        // the shelf at rest, and on its whole room while the mouse is on the
        // dock or its icons move (see ClipDockWindow).
        // (The apps' badges on the icons' top corners stick out of it.)
        RECT rest{};
        if (!placed.empty()) {
            double top = restTop;
            double right = restRight;
            for (const auto& item : placed) {
                if (item.badgeRight > 0) {
                    top = std::min(top, restBottom - (item.iconTop +
                                                      item.iconHeight -
                                                      item.contentTop) *
                                                         item.base);
                    right = std::max(
                        right, item.restCenter + (item.badgeRight -
                                                  item.buttonWidth / 2) *
                                                     item.base);
                }
            }
            // (In a box, nothing past its end.)
            if (boxLeft > -kNoBox) {
                right = std::min(right, restRight);
            }
            rest = {(LONG)std::floor(restLeft * scale) - 1,
                    (LONG)std::floor(top * scale) - 2,
                    (LONG)std::ceil(right * scale) + 2, client.bottom};
        }
        const bool open = hovering || moving;
        if (open != g_dockRoomOpen || !EqualRect(&rest, &g_dockShelfRest)) {
            g_dockRoomOpen = open;
            g_dockShelfRest = rest;
            ClipDockWindow(g_dockWnd);
        }
        // Where the shelf's top is on the screen with the dock shown (it may
        // be on its way up), for the apps' thumbnails (see PlaceThumbnails).
        RECT window{};
        MONITORINFO shownOn{sizeof(shownOn)};
        if (GrownTaskbar* room = FindGrownTaskbar(g_dockWnd);
            room && GetWindowRect(g_dockWnd, &window) &&
            GetMonitorInfo(TaskbarMonitor(g_dockWnd), &shownOn)) {
            room->shelfTop =
                shownOn.rcMonitor.bottom - (window.bottom - window.top) +
                (LONG)std::floor(std::min((double)shelf.Y, restTop) * scale);
        }
    }

    // The mouse left the dock with the taskbar holding the focus (a click on
    // the open app's icon minimized it): the taskbar's hide timer hands the
    // focus on, so it hides (see HandFocusBack).
    if (hovering) {
        if (dock && g_dockHovered != g_dockWnd) {
            RaiseOverWindows(g_dockWnd);
        }
        g_dockHovered = g_dockWnd;
        // (Windows shows them in its window as it is: placed beforehand.)
        if (dock) {
            WatchThumbnails();
            PlaceThumbnailWindows();
        }
    } else if (g_dockHovered == g_dockWnd) {
        g_dockHovered = nullptr;
        PlaceThumbnailWindows();
        if (g_taskbarAutoHides && GetForegroundWindow() == g_dockWnd) {
            ScheduleTaskbarHide(g_dockWnd,
                                (UINT)std::max(g_settings.hideDelay, 10));
        }
    }

    return busy;
}

// Taskbar buttons are recycled: a saved native picture belongs to an app,
// not just to the Image object which happens to still be alive.
bool SameDockIconApp(const std::wstring& saved, const std::wstring& current) {
    return !saved.empty() && !current.empty() &&
           _wcsicmp(saved.c_str(), current.c_str()) == 0;
}

// The app's own icon, as big as its button shows it now (the taskbar's
// picture is decoded at its small size and blurs magnified; a much bigger one
// shrunk to the icon at rest looks jagged), in steps of 16 pixels so a few
// sizes are made. Kept for each app and size (nullptr if it has none the
// shell knows). Taskbar thread only.
constexpr int kBigIconStep = 16;

int BigIconPixels(int pixels) {
    return std::clamp((pixels + kBigIconStep - 1) / kBigIconStep * kBigIconStep,
                      kBigIconStep, 256);
}

// The apps' pictures by app and size, as XAML pictures (made at their first
// use, freed whole while unloading, see FreeXamlGlobals). Taskbar thread
// only.
using DockPictures = std::vector<std::pair<std::wstring, Media::ImageSource>>;
[[clang::no_destroy]] std::optional<DockPictures> g_bigIcons;

// A 32-bit picture for XAML (nullptr if it can't be read).
Media::ImageSource PictureFromBitmap(HBITMAP bitmap) {
    BITMAP info{};
    GetObject(bitmap, sizeof(info), &info);
    const int width = info.bmWidth;
    const int height = std::abs(info.bmHeight);
    if (width <= 0 || height <= 0) {
        return nullptr;
    }
    Media::ImageSource source{nullptr};
    Media::Imaging::WriteableBitmap picture(width, height);
    BITMAPINFO header{};
    header.bmiHeader = {sizeof(BITMAPINFOHEADER), width, -height, 1, 32,
                        BI_RGB};
    HDC screen = GetDC(nullptr);
    uint8_t* pixels = picture.PixelBuffer().data();
    if (GetDIBits(screen, bitmap, 0, height, pixels, &header,
                  DIB_RGB_COLORS) == height) {
        // The picture takes its colors premultiplied by their alpha; the
        // shell's come as they are for most apps (a color brighter than its
        // alpha says so). Without any alpha, it's all solid.
        const size_t count = (size_t)width * height * 4;
        bool alpha = false;
        for (size_t i = 3; i < count && !alpha; i += 4) {
            alpha = pixels[i] != 0;
        }
        for (size_t i = 3; !alpha && i < count; i += 4) {
            pixels[i] = 255;
        }
        bool straight = false;
        for (size_t i = 0; i < count && !straight; i += 4) {
            straight = std::max({pixels[i], pixels[i + 1], pixels[i + 2]}) >
                       pixels[i + 3];
        }
        for (size_t i = 0; straight && i < count; i += 4) {
            for (int c = 0; c < 3; c++) {
                pixels[i + c] = (uint8_t)(pixels[i + c] * pixels[i + 3] / 255);
            }
        }
        picture.Invalidate();
        source = picture;
    }
    ReleaseDC(nullptr, screen);
    return source;
}

// The apps' overlay icons as XAML pictures, by app, the picture they come
// from (its serial, see OverlayIcon) and their size (like g_bigIcons).
// Taskbar thread only.
[[clang::no_destroy]] std::optional<DockPictures> g_overlaySources;

// The bubble's red, for an app whose badge has no color of its own.
constexpr D2D1_COLOR_F kBadgeRed = {0.95f, 0.25f, 0.26f, 1};

// The color of an app's own badge: its solid pixels' average, leaving out
// the light ones (the number's white). Red when it has none.
D2D1_COLOR_F OverlayBadgeColor(HICON icon) {
    ICONINFO info{};
    if (!icon || !GetIconInfo(icon, &info)) {
        return kBadgeRed;
    }
    D2D1_COLOR_F color = kBadgeRed;
    BITMAP bm{};
    if (info.hbmColor && GetObject(info.hbmColor, sizeof(bm), &bm) &&
        bm.bmWidth > 0 && bm.bmHeight > 0) {
        BITMAPINFOHEADER header{sizeof(header), bm.bmWidth, -bm.bmHeight, 1,
                                32, BI_RGB};
        std::vector<uint8_t> pixels((size_t)bm.bmWidth * bm.bmHeight * 4);
        HDC screen = GetDC(nullptr);
        double sum[3] = {};
        int solid = 0;
        if (GetDIBits(screen, info.hbmColor, 0, bm.bmHeight, pixels.data(),
                      (BITMAPINFO*)&header, DIB_RGB_COLORS) == bm.bmHeight) {
            for (size_t i = 0; i < pixels.size(); i += 4) {
                const uint8_t b = pixels[i], g = pixels[i + 1],
                              r = pixels[i + 2];
                if (pixels[i + 3] >= 200 && std::min({r, g, b}) < 200) {
                    sum[0] += r;
                    sum[1] += g;
                    sum[2] += b;
                    solid++;
                }
            }
        }
        ReleaseDC(nullptr, screen);
        if (solid) {
            color = {(float)(sum[0] / solid / 255),
                     (float)(sum[1] / solid / 255),
                     (float)(sum[2] / solid / 255), 1};
        }
    }
    if (info.hbmColor) {
        DeleteObject(info.hbmColor);
    }
    if (info.hbmMask) {
        DeleteObject(info.hbmMask);
    }
    return color;
}

// A bubble with `count` (a smaller dot in its corner for 0), `pixels` wide,
// in the color of the app's badge, for an app's overlay icon the app draws
// small (see UseBigOverlay).
Media::ImageSource CountBadgePicture(int count,
                                     int pixels,
                                     D2D1_COLOR_F color) {
    winrt::com_ptr<IWICImagingFactory> wic;
    winrt::com_ptr<ID2D1Factory> d2d;
    winrt::com_ptr<IDWriteFactory> dwrite;
    winrt::com_ptr<IWICBitmap> bitmap;
    winrt::com_ptr<ID2D1RenderTarget> target;
    if (FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                                CLSCTX_INPROC_SERVER,
                                IID_PPV_ARGS(wic.put()))) ||
        FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
                                 d2d.put())) ||
        FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
                                   __uuidof(IDWriteFactory),
                                   (IUnknown**)dwrite.put())) ||
        FAILED(wic->CreateBitmap(pixels, pixels, GUID_WICPixelFormat32bppPBGRA,
                                 WICBitmapCacheOnLoad, bitmap.put())) ||
        FAILED(d2d->CreateWicBitmapRenderTarget(
            bitmap.get(),
            D2D1::RenderTargetProperties(
                D2D1_RENDER_TARGET_TYPE_DEFAULT,
                D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,
                                  D2D1_ALPHA_MODE_PREMULTIPLIED)),
            target.put()))) {
        return nullptr;
    }
    winrt::com_ptr<ID2D1SolidColorBrush> brush;
    if (FAILED(target->CreateSolidColorBrush(color, brush.put()))) {
        return nullptr;
    }
    const float size = (float)pixels;
    const float radius = count > 0 ? size / 2 : size * 0.3f;
    target->BeginDraw();
    target->Clear(D2D1::ColorF(0, 0, 0, 0));
    target->FillEllipse({{size - radius, size - radius}, radius, radius},
                        brush.get());
    if (count > 0) {
        const std::wstring number =
            count > 99 ? L"99+" : std::to_wstring(count);
        winrt::com_ptr<IDWriteTextFormat> format;
        if (SUCCEEDED(dwrite->CreateTextFormat(
                L"Segoe UI", nullptr, DWRITE_FONT_WEIGHT_BOLD,
                DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
                size * (number.size() > 1 ? 0.48f : 0.66f), L"",
                format.put()))) {
            format->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            format->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
            brush->SetColor(D2D1::ColorF(1, 1, 1));
            target->DrawText(number.c_str(), (UINT32)number.size(),
                             format.get(), D2D1::RectF(0, 0, size, size),
                             brush.get());
        }
    }
    if (FAILED(target->EndDraw())) {
        return nullptr;
    }
    Media::Imaging::WriteableBitmap picture(pixels, pixels);
    if (FAILED(bitmap->CopyPixels(nullptr, (UINT)pixels * 4,
                                  (UINT)(pixels * pixels * 4),
                                  picture.PixelBuffer().data()))) {
        return nullptr;
    }
    picture.Invalidate();
    return picture;
}

// The app's overlay icon drawn sharp, also magnified: as a bubble with the
// count its text gives, in its badge's color (like Discord's "3 notifications"; its own
// picture is only as big as its window's DPI makes it), as big as it's
// shown (`factor` turns its size into pixels), or from the app's own
// picture when its text has no count and it's bigger than the taskbar's
// (16 pixels). The taskbar's back when the app has none.
void UseBigOverlay(DockIcon& icon,
                   FrameworkElement const& button,
                   double factor) {
    // (Every frame: nothing to do while no app has one.)
    if (!icon.overlayBig) {
        AcquireSRWLockShared(&g_overlayIconsLock);
        const bool none = g_overlayIcons.empty();
        ReleaseSRWLockShared(&g_overlayIconsLock);
        if (none) {
            return;
        }
    }
    const std::wstring appId = GetButtonAppId(button);
    // (No ID for a moment, being laid out again: left as it is.)
    if (appId.empty()) {
        return;
    }
    bool has = false;
    unsigned serial = 0;
    int size = 0;
    int count = 0;
    bool counted = false;
    bool listed = false;
    AcquireSRWLockShared(&g_overlayIconsLock);
    for (const auto& overlay : g_overlayIcons) {
        if (overlay.appId == appId && overlay.icon) {
            listed = true;
            counted = OverlayHasCount(overlay.description);
            has = overlay.size > 16 || counted;
            serial = overlay.serial;
            size = overlay.size;
            count = OverlayShownCount(overlay);
            break;
        }
    }
    ReleaseSRWLockShared(&g_overlayIconsLock);
    icon.overlayCounted = counted;
    // (Kept at its size from when it's found, here or below.)
    auto keepSize = [&](Controls::Image const& found) {
        icon.overlayImage = winrt::make_weak(found);
        icon.overlayKeep = Media::ScaleTransform();
        SetStyled(found, UIElement::RenderTransformProperty(), icon.overlayKeep);
        SetStyled(found, UIElement::RenderTransformOriginProperty(),
                  winrt::box_value(winrt::Windows::Foundation::Point{0.5f, 0.5f}));
    };
    // (Its image found once it has one: the taskbar makes it then, maybe a
    // moment later, so it's looked for again a few times.)
    constexpr int kOverlayMostLooks = 10;
    constexpr double kOverlayLookSeconds = 0.25;
    const bool lookNow = listed && !icon.overlayLooked &&
                         icon.overlayLooks < kOverlayMostLooks;
    if (lookNow) {
        if (auto found =
                FindByName(button, L"OverlayIcon").try_as<Controls::Image>()) {
            icon.overlayLooked = true;
            keepSize(found);
        } else {
            icon.overlayLooks++;
        }
    }
    auto image = icon.overlayImage.get();
    if (!has) {
        if (image && icon.overlayBig && image.Source() == icon.overlayBig) {
            image.Source(SameDockIconApp(icon.overlayAppId, appId)
                             ? icon.overlayOwn : nullptr);
        }
        icon.overlayOwn = nullptr;
        icon.overlayBig = nullptr;
        icon.overlayAppId.clear();
        return;
    }
    if (!icon.overlayAppId.empty() &&
        !SameDockIconApp(icon.overlayAppId, appId)) {
        icon.overlayOwn = nullptr;
    }
    if (!image) {
        // (Not twice in one frame, nor every frame once those looks are
        // done: four times a second then.)
        const double now = NowSeconds();
        if (lookNow || now - icon.overlayLookAt < kOverlayLookSeconds) {
            return;
        }
        icon.overlayLookAt = now;
        image = FindByName(button, L"OverlayIcon").try_as<Controls::Image>();
        if (!image) {
            return;
        }
        keepSize(image);
    }
    const bool own = size > 16 && !counted;
    const int pixels =
        own ? size
            : BigIconPixels((int)std::ceil(image.ActualWidth() * factor));
    const std::wstring key = appId + L"|" + std::to_wstring(serial) + L"|" +
                             std::to_wstring(own ? 0 : pixels);
    Media::ImageSource big{nullptr};
    bool made = false;
    auto& sources =
        g_overlaySources ? *g_overlaySources : g_overlaySources.emplace();
    for (const auto& [id, source] : sources) {
        if (id == key) {
            big = source;
            made = true;
        }
    }
    if (!made) {
        HICON copy = nullptr;
        AcquireSRWLockShared(&g_overlayIconsLock);
        for (const auto& overlay : g_overlayIcons) {
            if (overlay.appId == appId && overlay.serial == serial &&
                overlay.icon) {
                copy = CopyIcon(overlay.icon);
            }
        }
        ReleaseSRWLockShared(&g_overlayIconsLock);
        if (own) {
            ICONINFO info{};
            if (copy && GetIconInfo(copy, &info)) {
                if (info.hbmColor) {
                    big = PictureFromBitmap(info.hbmColor);
                    DeleteObject(info.hbmColor);
                }
                if (info.hbmMask) {
                    DeleteObject(info.hbmMask);
                }
            }
        } else {
            big = CountBadgePicture(count, pixels, OverlayBadgeColor(copy));
        }
        if (copy) {
            DestroyIcon(copy);
        }
        // (A few sizes of a few apps' kept.)
        constexpr size_t kMaxOverlaySources = 16;
        if (sources.size() >= kMaxOverlaySources) {
            sources.erase(sources.begin(),
                          sources.begin() + kMaxOverlaySources / 2);
        }
        sources.push_back({key, big});
    }
    const auto source = image.Source();
    if (!big || !source || source == big ||
        image.ReadLocalValue(Controls::Image::SourceProperty())
            .try_as<Data::BindingExpression>()) {
        return;
    }
    // (At the size it has: a bigger picture mustn't make it bigger.)
    if (std::isnan(image.Width()) || std::isnan(image.Height())) {
        SetStyled(image, FrameworkElement::WidthProperty(),
                  winrt::box_value(image.ActualWidth()));
        SetStyled(image, FrameworkElement::HeightProperty(),
                  winrt::box_value(image.ActualHeight()));
    }
    if (source != icon.overlayBig) {
        icon.overlayOwn = source;
    }
    icon.overlayAppId = appId;
    icon.overlayBig = big;
    image.Source(big);
}

// The big icons are read from the shell on a thread of their own (it can
// take longer than a frame, more for a packaged app): asked for by
// BigAppIcon, which takes them once read; the dock draws again then (see
// TaskbarSubclassProc). Each one asked for once: -1 its window still looked
// for, 0 waiting, 1 being read, 2 read (`bitmap` nullptr if the shell has
// none).
struct BigIconJob {
    std::wstring key;
    std::wstring appId;
    int pixels = 0;
    int state = 0;
    HBITMAP bitmap = nullptr;
    // The app's window, found on the taskbar's thread (see
    // FindBigIconWindows).
    HWND window = nullptr;
};
SRWLOCK g_bigIconJobsLock = SRWLOCK_INIT;
std::vector<BigIconJob> g_bigIconJobs;
// (Made by the taskbar's thread under the lock, stopped by the unloading
// one, see StopBigIcons.)
HANDLE g_bigIconThread;
HANDLE g_bigIconWake;
HANDLE g_bigIconStop;
const UINT g_bigIconsReadMessage =
    RegisterWindowMessage(L"WindhawkMacIslandDock_BigIconsRead");

DWORD WINAPI BigIconThreadProc(LPVOID) {
    const HRESULT com = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    const HANDLE events[] = {g_bigIconStop, g_bigIconWake};
    while (WaitForMultipleObjects(2, events, FALSE, INFINITE) ==
           WAIT_OBJECT_0 + 1) {
        for (;;) {
            std::wstring key;
            std::wstring appId;
            int pixels = 0;
            HWND window = nullptr;
            AcquireSRWLockExclusive(&g_bigIconJobsLock);
            for (auto& job : g_bigIconJobs) {
                if (job.state == 0) {
                    job.state = 1;
                    key = job.key;
                    appId = job.appId;
                    pixels = job.pixels;
                    window = job.window;
                    break;
                }
            }
            ReleaseSRWLockExclusive(&g_bigIconJobsLock);
            if (key.empty() ||
                WaitForSingleObject(g_bigIconStop, 0) == WAIT_OBJECT_0) {
                break;
            }
            // (A pinned shortcut's icon of its own first: the taskbar shows
            // that one. Then the shell's, its windows' relaunch icon among
            // them (a browser profile's picture); only then its window's
            // program, for an app without any like TeamViewer; not for a
            // packaged app: its window may be the frame of another process.)
            HBITMAP bitmap = PinnedShortcutIconBitmap(appId, pixels);
            if (!bitmap) {
                bitmap = LoadAppIconBitmap(nullptr, appId, pixels);
            }
            if (!bitmap && window &&
                appId.find(L'!') == std::wstring::npos) {
                bitmap = LoadAppIconBitmap(window, appId, pixels);
            }
            // (None from the shell: its window's own, as the taskbar shows.)
            if (!bitmap) {
                bitmap = AppWindowIconBitmap(appId, window);
            }
            AcquireSRWLockExclusive(&g_bigIconJobsLock);
            auto it = std::find_if(
                g_bigIconJobs.begin(), g_bigIconJobs.end(),
                [&](const BigIconJob& job) { return job.key == key; });
            if (it != g_bigIconJobs.end()) {
                it->bitmap = std::exchange(bitmap, nullptr);
                it->state = 2;
            }
            ReleaseSRWLockExclusive(&g_bigIconJobsLock);
            if (bitmap) {
                DeleteObject(bitmap);
            }
            if (HWND taskbar = FindCurrentProcessTaskbarWnd()) {
                PostMessage(taskbar, g_bigIconsReadMessage, 0, 0);
            }
        }
    }
    if (SUCCEEDED(com)) {
        CoUninitialize();
    }
    return 0;
}

// The windows of the apps whose big icons were just asked for (see
// TakeBigIcon), looked for on the taskbar's thread out of a frame (a posted
// message): the shell's app resolver (for an app that sets its ID on its
// process) isn't used from the big icon thread (measured: Explorer hung as
// TeamViewer opened). `look` false: they're read without one.
void FindBigIconWindows(bool look) {
    std::vector<std::wstring> appIds;
    AcquireSRWLockExclusive(&g_bigIconJobsLock);
    for (const auto& job : g_bigIconJobs) {
        if (job.state == -1) {
            appIds.push_back(job.appId);
        }
    }
    ReleaseSRWLockExclusive(&g_bigIconJobsLock);
    if (appIds.empty()) {
        return;
    }
    std::vector<HWND> windows;
    for (const auto& appId : appIds) {
        windows.push_back(look ? FindTaskbarAppWindow(appId) : nullptr);
    }
    AcquireSRWLockExclusive(&g_bigIconJobsLock);
    for (auto& job : g_bigIconJobs) {
        for (size_t i = 0; job.state == -1 && i < appIds.size(); i++) {
            if (appIds[i] == job.appId) {
                job.window = windows[i];
                job.state = 0;
            }
        }
    }
    const HANDLE wake = g_bigIconWake;
    ReleaseSRWLockExclusive(&g_bigIconJobsLock);
    if (wake) {
        SetEvent(wake);
    }
}

// Asks for an app's big icon at `pixels` (see BigIconJob); its picture if
// it's been read (true; nullptr for none), taken out of the jobs.
bool TakeBigIcon(const std::wstring& key,
                 const std::wstring& appId,
                 int pixels,
                 HBITMAP* bitmap) {
    *bitmap = nullptr;
    bool read = false;
    bool asked = false;
    AcquireSRWLockExclusive(&g_bigIconJobsLock);
    auto it =
        std::find_if(g_bigIconJobs.begin(), g_bigIconJobs.end(),
                     [&](const BigIconJob& job) { return job.key == key; });
    if (it != g_bigIconJobs.end()) {
        if (it->state == 2) {
            *bitmap = it->bitmap;
            g_bigIconJobs.erase(it);
            read = true;
        }
    } else if (!g_unloading) {
        // (Its thread made the first time, never once unloading.)
        if (!g_bigIconThread) {
            g_bigIconWake = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            g_bigIconStop = CreateEvent(nullptr, TRUE, FALSE, nullptr);
            if (g_bigIconWake && g_bigIconStop) {
                g_bigIconThread = CreateThread(nullptr, 0, BigIconThreadProc,
                                               nullptr, 0, nullptr);
            }
        }
        if (g_bigIconThread) {
            g_bigIconJobs.push_back({key, appId, pixels, -1});
            asked = true;
        }
    }
    ReleaseSRWLockExclusive(&g_bigIconJobsLock);
    // (Its window looked for after this frame, see FindBigIconWindows;
    // without the taskbar's window to post to, read without it.)
    if (asked) {
        const HWND taskbar = FindCurrentProcessTaskbarWnd();
        if (!taskbar || !PostMessage(taskbar, g_bigIconsReadMessage, 1, 0)) {
            FindBigIconWindows(false);
        }
    }
    return read;
}

// Its thread stopped and what it read let go (unloading).
void StopBigIcons() {
    AcquireSRWLockExclusive(&g_bigIconJobsLock);
    const HANDLE thread = std::exchange(g_bigIconThread, nullptr);
    ReleaseSRWLockExclusive(&g_bigIconJobsLock);
    if (thread) {
        SetEvent(g_bigIconStop);
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
    }
    AcquireSRWLockExclusive(&g_bigIconJobsLock);
    for (const auto& job : g_bigIconJobs) {
        if (job.bitmap) {
            DeleteObject(job.bitmap);
        }
    }
    std::vector<BigIconJob>().swap(g_bigIconJobs);
    for (HANDLE* event : {&g_bigIconWake, &g_bigIconStop}) {
        if (*event) {
            CloseHandle(*event);
            *event = nullptr;
        }
    }
    ReleaseSRWLockExclusive(&g_bigIconJobsLock);
}

Media::ImageSource BigAppIcon(const std::wstring& appId, int pixels) {
    pixels = BigIconPixels(pixels);
    const std::wstring key = std::to_wstring(pixels) + L"|" + appId;
    auto& icons = g_bigIcons ? *g_bigIcons : g_bigIcons.emplace();
    for (const auto& [id, source] : icons) {
        if (id == key) {
            return source;
        }
    }
    // (Not read yet: the taskbar's own picture meanwhile.)
    HBITMAP bitmap = nullptr;
    if (!TakeBigIcon(key, appId, pixels, &bitmap)) {
        return nullptr;
    }
    Media::ImageSource source{nullptr};
    if (bitmap) {
        source = PictureFromBitmap(bitmap);
        DeleteObject(bitmap);
    }
    // The oldest go past a limit (the icons showing keep theirs).
    constexpr size_t kMaxBigIcons = 64;
    if (icons.size() >= kMaxBigIcons) {
        icons.erase(icons.begin(), icons.begin() + kMaxBigIcons / 2);
    }
    icons.push_back({key, source});
    return source;
}

// Shows the app's big icon on its button, unless it already does. The
// taskbar sets its picture again when the app's icon changes (or the button
// is reused for another app): the new one is replaced in turn. Not when the
// picture is bound to the taskbar's data (replacing it would drop that).
void UseBigIcon(DockIcon& icon, FrameworkElement const& button, int pixels) {
    auto image = icon.image.get().try_as<Controls::Image>();
    if (!image) {
        return;
    }
    // (The button reused for another app may keep the big picture of the one
    // before: the taskbar doesn't always set its own again. Measured at
    // sign-in: Discord's stayed on Windhawk's button.)
    const std::wstring appId = GetButtonAppId(button);
    // Reused for another app (not a button without an ID for a moment): the
    // taskbar's own picture kept is the other app's, none to put back.
    // Unless the taskbar set it just before, over the other app's big one,
    // the ID changing a moment after the picture (measured: the Terminal's
    // big icon left on TeamViewer's button, taken when the Terminal
    // closed): this app's then, shown again.
    if (!appId.empty() && !icon.bigAppId.empty() && appId != icon.bigAppId) {
        if (icon.ownSource && icon.ownFreshAt &&
            NowSeconds() - icon.ownFreshAt < 2) {
            if (icon.bigSource && image.Source() == icon.bigSource) {
                image.Source(icon.ownSource);
            }
            icon.ownAppId = appId;
            icon.bigSource = nullptr;
            icon.bigPixels = 0;
            icon.bigAppId.clear();
        } else {
            icon.ownSource = nullptr;
            icon.ownAppId.clear();
            icon.ownEmpty = false;
        }
        icon.ownFreshAt = 0;
    }
    const auto source = image.Source();
    const bool shownBig = icon.bigSource && source == icon.bigSource;
    const bool sameApp = appId == icon.bigAppId;
    // (Also with no picture from the taskbar: measured for a window whose
    // app sets its ID on its process, its button left empty.)
    if (shownBig && sameApp && icon.bigPixels == BigIconPixels(pixels)) {
        return;
    }
    if (image.ReadLocalValue(Controls::Image::SourceProperty())
            .try_as<Data::BindingExpression>()) {
        return;
    }
    auto big = appId.empty() ? nullptr : BigAppIcon(appId, pixels);
    if (!big) {
        // The button reused for this app still showing the big picture of
        // the one before, and this one has none (read, nothing found): not
        // left on it (the Riot Client's button showed FileZilla's, closed
        // before it opened).
        const std::wstring key =
            std::to_wstring(BigIconPixels(pixels)) + L"|" + appId;
        const bool none =
            !appId.empty() && g_bigIcons &&
            std::any_of(g_bigIcons->begin(), g_bigIcons->end(),
                        [&](const auto& entry) {
                            return entry.first == key && !entry.second;
                        });
        if (shownBig && !sameApp && none) {
            image.Source(nullptr);
            icon.bigSource = nullptr;
            icon.bigPixels = 0;
            icon.bigAppId.clear();
        }
        return;
    }
    // (At the size it has: a bigger picture mustn't make it bigger. Without
    // a picture it has none: another app's icon's, all of one size.)
    if (std::isnan(image.Width()) || std::isnan(image.Height())) {
        double width = image.ActualWidth();
        double height = image.ActualHeight();
        for (const auto& other : g_dockIcons) {
            if (width > 0 && height > 0) {
                break;
            }
            if (auto otherImage = other.image.get();
                other.app && otherImage && otherImage.ActualWidth() > 0 &&
                otherImage.ActualHeight() > 0) {
                width = otherImage.ActualWidth();
                height = otherImage.ActualHeight();
            }
        }
        if (width <= 0 || height <= 0) {
            return;
        }
        SetStyled(image, FrameworkElement::WidthProperty(),
                  winrt::box_value(width));
        SetStyled(image, FrameworkElement::HeightProperty(),
                  winrt::box_value(height));
    }
    // (Another size of it: the taskbar's own is still the one kept. Set
    // again over this app's big one: maybe the next app's, see above.)
    if (!shownBig) {
        icon.ownFreshAt = icon.bigSource && sameApp ? NowSeconds() : 0;
        icon.ownSource = source;
        icon.ownAppId = appId;
        icon.ownEmpty = !source;
    }
    icon.bigSource = big;
    icon.bigPixels = BigIconPixels(pixels);
    icon.bigAppId = appId;
    image.Source(big);
}

// The taskbar's own picture back.
void RestoreDockIcon(DockIcon& icon) {
    // (Put back unless the button shows another app now; one without an ID
    // at the moment is taken as the same.)
    auto button = icon.button.get();
    const std::wstring appId = button ? GetButtonAppId(button) : std::wstring();
    const auto sameApp = [&](const std::wstring& saved) {
        return appId.empty() || SameDockIconApp(saved, appId);
    };
    if (auto image = icon.image.get().try_as<Controls::Image>();
        image && (icon.ownSource || icon.ownEmpty) && icon.bigSource &&
        image.Source() == icon.bigSource && sameApp(icon.ownAppId)) {
        image.Source(icon.ownSource);
    }
    icon.ownSource = nullptr;
    icon.ownAppId.clear();
    icon.ownFreshAt = 0;
    icon.ownEmpty = false;
    icon.bigSource = nullptr;
    icon.bigPixels = 0;
    icon.bigAppId.clear();
    if (auto image = icon.overlayImage.get();
        image && icon.overlayBig && image.Source() == icon.overlayBig) {
        image.Source(sameApp(icon.overlayAppId) ? icon.overlayOwn : nullptr);
    }
    icon.overlayOwn = nullptr;
    icon.overlayBig = nullptr;
    icon.overlayAppId.clear();
}

void CheckDockItems() {
    auto repeater = g_dockRepeater.get();
    if (!repeater) {
        return;
    }
    const int count = Media::VisualTreeHelper::GetChildrenCount(repeater);
    if (count != g_dockItemCount) {
        g_dockItemCount = count;
        RescanDockIcons();
        WatchBadgesAndPublish();
    }
}

void SetupDockBehavior(HWND hWnd,
                       FrameworkElement const& frame,
                       FrameworkElement const& background) {
    g_dockWnd = hWnd;
    g_dockFrame = winrt::make_weak(frame);
    g_dockBackground = winrt::make_weak(background);
    auto repeater = FindByName(frame, L"TaskbarFrameRepeater");
    g_dockRepeater = winrt::make_weak(repeater ? repeater : frame);
    g_dockItemCount = -1;
    g_dockSince = NowSeconds();

    // Pointer events reach the frame even when a button handles them.
    g_pointerHandler = winrt::box_value(Input::PointerEventHandler(
        [](winrt::Windows::Foundation::IInspectable const&,
           Input::PointerRoutedEventArgs const&) { StartRendering(); }));
    frame.AddHandler(UIElement::PointerMovedEvent(), g_pointerHandler, true);
    g_pressedHandler = winrt::box_value(Input::PointerEventHandler(
        [hWnd](winrt::Windows::Foundation::IInspectable const&,
               Input::PointerRoutedEventArgs const& args) {
            g_dockPressedAt = NowSeconds();
            if (args.GetCurrentPoint(nullptr)
                    .Properties()
                    .IsRightButtonPressed()) {
                g_dockRightPressedAt = g_dockPressedAt;
                g_dockRightPressedWnd = hWnd;
                POINT cursor{};
                if (GetCursorPos(&cursor)) {
                    InterlockedExchange(&g_dockRightPressedX, cursor.x);
                }
            }
            DockScope scope(hWnd);
            if (g_dockShelf.pin && args.GetCurrentPoint(nullptr)
                                       .Properties()
                                       .IsLeftButtonPressed()) {
                const auto point = args.GetCurrentPoint(nullptr).Position();
                const auto& r = g_dockShelf.pinRect;
                if (r.Width > 0 && point.X >= r.X && point.X <= r.X + r.Width &&
                    point.Y >= r.Y && point.Y <= r.Y + r.Height) {
                    args.Handled(true);
                    Safely(L"The dock's arrow", [&] { ToggleDockPin(hWnd); });
                    return;
                }
            }
            Safely(L"A click on the taskbar", [&] { OnDockPressed(args); });
        }));
    frame.AddHandler(UIElement::PointerPressedEvent(), g_pressedHandler, true);
    // The wheel scrolls the dock's box (only when it has more apps than
    // fit: otherwise the taskbar keeps it).
    g_dockScroll = 0;
    g_dockScrollMax = 0;
    g_wheelHandler = winrt::box_value(Input::PointerEventHandler(
        [hWnd](winrt::Windows::Foundation::IInspectable const&,
               Input::PointerRoutedEventArgs const& args) {
            DockScope scope(hWnd);
            Safely(L"The wheel on the taskbar", [&] {
                if (g_dockScrollMax <= 0 || !IsDock()) {
                    return;
                }
                const int delta = args.GetCurrentPoint(nullptr)
                                      .Properties()
                                      .MouseWheelDelta();
                g_dockScroll = std::clamp(
                    g_dockScroll - delta / 120.0 * g_dockScrollStep, 0.0,
                    g_dockScrollMax);
                args.Handled(true);
                StartRendering();
            });
        }));
    frame.AddHandler(UIElement::PointerWheelChangedEvent(), g_wheelHandler,
                     true);
    g_pointerTarget = winrt::make_weak(frame);

    // New and closed apps change the number of buttons.
    g_layoutRevoker = frame.LayoutUpdated(
        winrt::auto_revoke,
        [hWnd](winrt::Windows::Foundation::IInspectable const&,
               winrt::Windows::Foundation::IInspectable const&) {
            DockScope scope(hWnd);
            Safely(L"Following the layout", [] {
                CheckDockItems();
                RefreshPinnedApps();
                // Positions may have changed: line the icons up again.
                // Moving them doesn't cause another layout pass.
                StartRendering();
                // Looking for new badges, at most twice a second.
                if (NowSeconds() - g_lastBadgeScan > 0.5) {
                    g_lastBadgeScan = NowSeconds();
                    WatchBadgesAndPublish();
                }
            });
        });
    CheckDockItems();
    Safely(L"Reading the pinned apps", [] { RefreshPinnedApps(); });
    StartRendering();
    if (!g_dockIsMain) {
        return;
    }

    // Badges fade in and out, so they're also checked every second.
    g_badgeTimer = DispatcherTimer();
    g_badgeTimer.Interval(std::chrono::seconds(1));
    g_badgeTimer.Tick([](winrt::Windows::Foundation::IInspectable const&,
                         winrt::Windows::Foundation::IInspectable const&) {
        if (!g_unloading) {
            Safely(L"Watching the badges", [] { WatchBadgesAndPublish(); });
            Safely(L"Measuring the icons' extras",
                   [] { MeasureDockExtras(); });
            Safely(L"Following the progress", [] { RecheckProgress(); });
        }
    });
    g_badgeTimer.Start();
}

void ResetDockOfTaskbar();

void ResetDockBehavior() {
    // The timer and the handlers that run on their own go first: a step
    // below failing mustn't leave them ticking after the unload.
    if (g_badgeTimer) {
        Safely(L"Stopping the badge timer", [&] { g_badgeTimer.Stop(); });
        g_badgeTimer = nullptr;
    }
    Safely(L"Removing the rendering handler",
           [&] { g_renderingRevoker.revoke(); });
    StopWatchingProgressBars();
    UnwatchThumbnails();
    for (auto& state : g_otherDocks) {
        DockScope scope(state->wnd);
        ResetDockOfTaskbar();
    }
    g_otherDocks.clear();
    // (A show Windows made at once still waiting, see kQuietShowDelayMs: its
    // timer mustn't tick after the unload; its cut goes with the others.)
    if (g_quietShownWnd) {
        KillTimer(g_quietShownWnd, kQuietShowTimerId);
        g_quietShownWnd = nullptr;
    }
    for (HWND hWnd : g_ownClips) {
        if (IsWindow(hWnd)) {
            SetWindowRgn(hWnd, nullptr, TRUE);
        }
    }
    g_ownClips.clear();

    AcquireSRWLockExclusive(&g_badgeAppsLock);
    g_badgeApps.clear();
    ReleaseSRWLockExclusive(&g_badgeAppsLock);
    g_stateRevokers.clear();
    g_dotRevokers.clear();
    for (const auto& watch : g_badgeWatches) {
        if (auto element = watch.element.get()) {
            Safely(L"Releasing a taskbar badge watch", [&] {
                element.UnregisterPropertyChangedCallback(watch.property,
                                                          watch.token);
            });
        }
    }
    g_badgeWatches.clear();
    g_watchedButtons.clear();
    ResetDockOfTaskbar();
}

// The mod's shelf canvases in `panel` taken out, all of them: one left by an
// earlier style, or by an earlier load of the mod (its weak reference gone),
// would keep drawing its shelf where it was, in the dock's color, seen as a
// white band whenever the dock's room opens.
void RemoveDockShelfHosts(Controls::Panel const& panel) {
    auto children = panel.Children();
    for (uint32_t i = children.Size(); i-- > 0;) {
        if (auto element = children.GetAt(i).try_as<FrameworkElement>();
            element && element.Name() == kDockShelfHostName) {
            children.RemoveAt(i);
        }
    }
}

// The taskbar in the globals (see DockScope): its handlers, icons, shadow
// and cut go. A dock shown for a notification goes back down, and its timer
// stops (a started DispatcherTimer would tick on after the unload).
void ResetDockOfTaskbar() {
    if (g_notificationTimer) {
        g_notificationTimer.Stop();
        g_notificationTimer = nullptr;
    }
    if (g_shownForNotification) {
        g_shownForNotification = false;
        if (g_dockWnd) {
            const RECT& hidden = g_notificationHiddenRect;
            SetWindowPos(g_dockWnd, nullptr, hidden.left, hidden.top,
                         hidden.right - hidden.left,
                         hidden.bottom - hidden.top,
                         SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    g_layoutRevoker.revoke();
    // (Each part on its own: a retired element failing mustn't leave the
    // rest, its timers above all, running after the unload.)
    if (auto target = g_pointerTarget.get()) {
        Safely(L"Removing the taskbar pointer handlers", [&] {
            if (g_pointerHandler) {
                target.RemoveHandler(UIElement::PointerMovedEvent(),
                                     g_pointerHandler);
            }
            if (g_pressedHandler) {
                target.RemoveHandler(UIElement::PointerPressedEvent(),
                                     g_pressedHandler);
            }
            if (g_wheelHandler) {
                target.RemoveHandler(UIElement::PointerWheelChangedEvent(),
                                     g_wheelHandler);
            }
        });
    }
    g_pointerHandler = nullptr;
    g_pressedHandler = nullptr;
    g_wheelHandler = nullptr;
    g_pointerTarget = nullptr;
    for (auto& icon : g_dockIcons) {
        Safely(L"Restoring a taskbar icon", [&] { RestoreDockIcon(icon); });
    }
    g_dockIcons.clear();
    if (g_dockHovered == g_dockWnd) {
        g_dockHovered = nullptr;
    }
    if (g_dockWnd) {
        KillTimer(g_dockWnd, kAnimatorTimerId);
    }
    Safely(L"Resuming the dock's animations", [] { ResumeRepeaterAnimations(); });
    if (auto frame = g_dockFrame.get(); frame && g_dockContentHidden) {
        Safely(L"Restoring the dock's opacity",
               [&] { RestoreDockOpacity(frame); });
    }
    g_dockContentHidden = false;
    g_dockScaleSettled = true;
    g_dockScaleMoved = false;
    g_dockOpacityKept = nullptr;
    g_dockFrame = nullptr;
    g_dockRepeater = nullptr;
    // (The mod's own canvas, see ApplyStyleUnscoped.)
    if (auto background = g_dockBackground.get()) {
        Safely(L"Removing the dock's canvas", [&] {
            if (background.Name() == kDockShelfHostName) {
                if (auto panel = Media::VisualTreeHelper::GetParent(background)
                                     .try_as<Controls::Panel>()) {
                    RemoveDockShelfHosts(panel);
                }
            }
        });
    }
    g_dockShelf = {};
    g_dockShelfRest = {};
    g_dockShelfNow = {};
    g_dockRoomOpen = false;
    g_dockBackground = nullptr;
    if (auto fill = g_shadowFill.get(); fill && g_shadowVisual) {
        Safely(L"Removing the dock's shadow", [&] {
            Hosting::ElementCompositionPreview::SetElementChildVisual(fill,
                                                                     nullptr);
        });
    }
    g_shadowVisual = nullptr;
    g_shadowFill = nullptr;
    ResetAppsArea();
    g_dockItemCount = -1;
    g_dockWnd = nullptr;
}

bool ApplyStyleUnscoped(XamlRoot xamlRoot, HWND hWnd, bool mainTaskbar);

// Another monitor's taskbar gets a dock state of its own (see DockState).
bool ApplyStyle(XamlRoot xamlRoot, HWND hWnd, bool mainTaskbar) {
    if (mainTaskbar) {
        return ApplyStyleUnscoped(xamlRoot, hWnd, true);
    }
    // (Styled again, as when its monitor comes back: its old handlers go.)
    const bool again = FindOtherDock(hWnd) != nullptr;
    if (!again) {
        auto state = std::make_unique<DockState>();
        state->wnd = hWnd;
        g_otherDocks.push_back(std::move(state));
    }
    DockScope scope(hWnd);
    if (again) {
        ResetDockOfTaskbar();
        g_dockWnd = hWnd;
    }
    return ApplyStyleUnscoped(xamlRoot, hWnd, false);
}

bool ApplyStyleUnscoped(XamlRoot xamlRoot, HWND hWnd, bool mainTaskbar) {
    auto content = xamlRoot.Content().try_as<FrameworkElement>();
    if (!content) {
        return false;
    }

    auto frame = FindTaskbarFrame(content);
    if (!frame) {
        // (Told once, see CheckDockAvailable.)
        if (!g_dockUnavailable) {
            IslandLog(L"TaskbarFrame not found");
        }
        return false;
    }
    auto rootGrid = FindByName(frame, L"RootGrid");
    if (!rootGrid) {
        IslandLog(L"RootGrid not found");
        return false;
    }

    // The Windows taskbar: as it is (maybe without its tray), or without what
    // the island shows (the tray on the right, the widgets on the left). The
    // apps' badges are still watched, for the island.
    if (!IsDock()) {
        const bool onlyApps =
            g_settings.taskbarMode ==
                decltype(g_settings.taskbarMode)::WindowsApps ||
            IsTransparentTaskbar();
        if (onlyApps ||
            (g_settings.windowsHideTray && g_settings.showIsland)) {
            if (auto tray =
                    FindByClassName(content, L"SystemTray.SystemTrayFrame")) {
                SetStyled(tray, UIElement::VisibilityProperty(),
                          winrt::box_value(Visibility::Collapsed));
            }
        }
        if (onlyApps) {
            std::vector<FrameworkElement> widgets;
            FindAllByClassName(frame, {L"Taskbar.AugmentedEntryPointButton"},
                               widgets);
            for (const auto& widget : widgets) {
                SetStyled(widget, UIElement::VisibilityProperty(),
                          winrt::box_value(Visibility::Collapsed));
            }
        }
        // Transparent: no background and no line on top, only a soft shadow
        // rising from the bottom edge, so the icons still stand out over
        // light windows.
        if (IsTransparentTaskbar()) {
            if (auto background =
                    FindByClassName(rootGrid, L"Taskbar.TaskbarBackground")) {
                if (auto fill = FindByName(background, L"BackgroundFill")) {
                    SetStyled(fill, Shapes::Shape::FillProperty(),
                              Media::SolidColorBrush(
                                  winrt::Windows::UI::Colors::Transparent()));
                    SetStyled(fill, UIElement::OpacityProperty(),
                              winrt::box_value(g_shadowStrength));
                    // (The shadow rises from the bottom edge: not on the
                    // other edges.)
                    if (g_taskbarAtBottom) {
                        g_shadowFill = winrt::make_weak(fill.as<UIElement>());
                        MakeShadow(fill);
                    }
                }
                if (auto stroke = FindByName(background, L"BackgroundStroke")) {
                    SetStyled(stroke, UIElement::VisibilityProperty(),
                              winrt::box_value(Visibility::Collapsed));
                }
            } else {
                IslandLog(L"TaskbarBackground not found");
            }
        }
        SetupDockBehavior(hWnd, frame, nullptr);
        return true;
    }

    // Only as wide as the icons, centered, at the bottom of the window (its
    // room above is the dock's, see GrownTaskbar).
    // (Build 26320: the frame is the XAML content itself. Windows places an
    // app's jump list from where its button is in the frame, so the frame
    // keeps the window's width and its RootGrid is centered instead: centering
    // the frame put the jump lists at the screen's left.)
    const FrameworkElement centered = frame == content ? rootGrid : frame;
    SetStyled(centered, FrameworkElement::HorizontalAlignmentProperty(),
              winrt::box_value(HorizontalAlignment::Center));
    SetStyled(centered, FrameworkElement::VerticalAlignmentProperty(),
              winrt::box_value(VerticalAlignment::Bottom));
    SetStyled(centered, FrameworkElement::WidthProperty(),
              winrt::box_value(std::numeric_limits<double>::quiet_NaN()));
    WatchFrameWidth(centered);

    // The dock has its own height, at the bottom of the taskbar. Whatever the
    // taskbar has above it stays transparent: room for the magnified icons,
    // and the strip that stays on screen while the taskbar is hidden.
    SetStyled(rootGrid, Controls::Grid::PaddingProperty(),
              winrt::box_value(ThicknessHelper::FromLengths(8, 0, 8, 0)));

    // The dock's shelf is drawn on the taskbar's own background rectangle,
    // which lies behind the icons (see DockShelf). Rounding the panel that
    // holds the icons would also cut off the magnified icons at its edges.
    Shapes::Rectangle fill{nullptr};
    if (auto background =
            FindByClassName(rootGrid, L"Taskbar.TaskbarBackground")) {
        fill = FindByName(background, L"BackgroundFill")
                   .try_as<Shapes::Rectangle>();
        if (auto stroke = FindByName(background, L"BackgroundStroke")) {
            SetStyled(stroke, UIElement::VisibilityProperty(),
                      winrt::box_value(Visibility::Collapsed));
        }
    }
    // The buttons keep their place, and their icons are lined up with the
    // shelf (see OnRendering).
    FrameworkElement dockBackground{nullptr};
    if (fill) {
        StyleDockBackground(fill);
    }
    // The shelf goes on a canvas of its own, behind everything in the
    // taskbar's XAML and as big as it: the background is cut to the
    // taskbar's own height, the shelf isn't (see DockShelf).
    // (Build 26320: the content is the frame itself, not a panel; the shelf
    // then goes in the frame's RootGrid, behind its icons.)
    auto shelfPanel = content.try_as<Controls::Panel>();
    if (!shelfPanel) {
        shelfPanel = rootGrid.try_as<Controls::Panel>();
    }
    if (auto panel = shelfPanel; fill && panel) {
        RemoveDockShelfHosts(panel);
        Controls::Canvas shelfHost;
        shelfHost.Name(kDockShelfHostName);
        shelfHost.IsHitTestVisible(false);
        panel.Children().InsertAt(0, shelfHost);
        g_dockShelf = MakeDockShelf(shelfHost);
        dockBackground = shelfHost;
    } else {
        IslandLog(L"BackgroundFill not found, rounding the panel instead");
        StylePill(rootGrid, ThicknessHelper::FromLengths(
                                0, 0, 0, g_settings.bottomGap));
        SetDockGeometry(rootGrid, GetDockMetrics(0).Height(), 0);
    }

    if (auto tray = FindByClassName(content, L"SystemTray.SystemTrayFrame")) {
        if (g_settings.hideTray || g_settings.showIsland) {
            SetStyled(tray, UIElement::VisibilityProperty(),
                      winrt::box_value(Visibility::Collapsed));
        } else if (auto trayGrid = FindByName(tray, L"SystemTrayFrameGrid")) {
            SetStyled(tray, FrameworkElement::VerticalAlignmentProperty(),
                      winrt::box_value(VerticalAlignment::Bottom));
            StylePill(trayGrid, ThicknessHelper::FromLengths(
                                    0, 0, 6, g_settings.bottomGap));
            SetDockGeometry(trayGrid, kDockTrayHeight, 6);
        }
    }

    // Magnification and bouncing follow the mouse, on every taskbar.
    SetupDockBehavior(hWnd, frame, dockBackground);
    return true;
}

// Whether the main taskbar got its style (it may not be ready yet when the
// mod loads with Explorer; see LateStartThreadProc).
std::atomic<bool> g_mainTaskbarStyled;

void ApplyToTaskbar(HWND hWnd, XamlRoot xamlRoot, bool mainTaskbar) {
    if (!xamlRoot) {
        IslandLog(L"Getting XamlRoot failed for %p", hWnd);
        return;
    }
    bool applied = false;
    Safely(L"Styling the taskbar",
           [&] { applied = ApplyStyle(xamlRoot, hWnd, mainTaskbar); });
    if (!applied) {
        IslandLog(L"ApplyStyle failed for %p", hWnd);
        return;
    }
    if (mainTaskbar) {
        g_mainTaskbarStyled = true;
    }
}

using RunFromWindowThreadProc_t = void(WINAPI*)(void* parameter);

// Runs a function on a window's thread (with a hook on that thread for the
// message sent to the window), and returns once it ran.
const UINT g_runFromWindowThreadMessage =
    RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);

struct RunFromWindowThreadParam {
    RunFromWindowThreadProc_t proc;
    void* procParam;
};

LRESULT CALLBACK RunFromWindowThreadHookProc(int nCode,
                                             WPARAM wParam,
                                             LPARAM lParam) {
    if (nCode == HC_ACTION) {
        const CWPSTRUCT* cwp = (const CWPSTRUCT*)lParam;
        if (cwp->message == g_runFromWindowThreadMessage) {
            auto* param = (RunFromWindowThreadParam*)cwp->lParam;
            Safely(L"Running on the taskbar thread", [&] {
                param->proc(param->procParam);
            });
        }
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

bool RunFromWindowThread(HWND hWnd,
                         RunFromWindowThreadProc_t proc,
                         void* procParam) {
    DWORD dwThreadId = GetWindowThreadProcessId(hWnd, nullptr);
    if (dwThreadId == 0) {
        return false;
    }

    if (dwThreadId == GetCurrentThreadId()) {
        Safely(L"Running on the taskbar thread", [&] { proc(procParam); });
        return true;
    }

    HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, RunFromWindowThreadHookProc,
                                  nullptr, dwThreadId);
    if (!hook) {
        return false;
    }

    RunFromWindowThreadParam param{proc, procParam};
    SendMessage(hWnd, g_runFromWindowThreadMessage, 0, (LPARAM)&param);

    UnhookWindowsHookEx(hook);
    return true;
}

// Styles a taskbar window of this thread.
BOOL CALLBACK ApplyToTaskbarWindowProc(HWND hWnd, LPARAM) {
    WCHAR className[32];
    if (!GetClassName(hWnd, className, ARRAYSIZE(className))) {
        return TRUE;
    }
    if (_wcsicmp(className, L"Shell_TrayWnd") == 0) {
        ApplyToTaskbar(hWnd, GetTaskbarXamlRoot(hWnd), true);
    } else if (_wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0) {
        ApplyToTaskbar(hWnd, GetSecondaryTaskbarXamlRoot(hWnd), false);
    }
    return TRUE;
}

// Restyles every taskbar from the taskbar thread, or removes the style while
// unloading.
// Unloading: what the XAML globals still hold goes, on the taskbar's thread
// (their destructors never run, see g_styledProperties).
void FreeXamlGlobals() {
    g_otherDocks.clear();
    g_dockShelf = {};
    g_bigIcons.reset();
    g_overlaySources.reset();
    // (The overlay icons' copies too.)
    AcquireSRWLockExclusive(&g_overlayIconsLock);
    for (const auto& overlay : g_overlayIcons) {
        DestroyIcon(overlay.icon);
    }
    std::vector<OverlayIcon>().swap(g_overlayIcons);
    ReleaseSRWLockExclusive(&g_overlayIconsLock);
    g_animatorKept = nullptr;
    g_animatorProperty = nullptr;
    g_animatorPropertyTried = false;
    std::vector<StyledProperty>().swap(g_styledProperties);
    std::vector<WidthWatch>().swap(g_widthWatches);
    std::vector<DockIcon>().swap(g_dockIcons);
    std::vector<VisualStateGroup::CurrentStateChanged_revoker>().swap(
        g_stateRevokers);
    std::vector<FrameworkElement::SizeChanged_revoker>().swap(g_dotRevokers);
    std::vector<BadgeWatch>().swap(g_badgeWatches);
    StopWatchingProgressBars();
    g_layoutRevoker = {};
    g_renderingRevoker = {};
}

// The dock's room above the taskbars made again (see GrownTaskbar), defined
// further down.
void WINAPI RefreshDockRoomProc(void*);

// Whether the main taskbar has the parts the dock styles (see
// g_dockUnavailable), before any taskbar is styled: all of them then follow
// the same mode. Not ready yet (no content): as it was.
void CheckDockAvailable() {
    HWND taskbar = FindCurrentProcessTaskbarWnd();
    if (!taskbar) {
        return;
    }
    XamlRoot xamlRoot = GetTaskbarXamlRoot(taskbar);
    if (!xamlRoot) {
        return;
    }
    auto content = xamlRoot.Content().try_as<FrameworkElement>();
    if (!content) {
        return;
    }
    const bool missing = !FindTaskbarFrame(content);
    if (g_dockUnavailable.exchange(missing) != missing && missing) {
        IslandLog(L"No TaskbarFrame: the taskbar is left as Windows draws it");
    }
}

void ApplySettingsFromTaskbarThread() {
    IslandLog(L"Applying settings");

    // Without the dock now (or unloading), the taskbars get their own height
    // back first: the styles going would otherwise move a window still
    // grown for a dock that isn't there.
    if (!IsDock() || g_unloading) {
        Safely(L"Giving the taskbars their height back",
               [] { RefreshDockRoomProc(nullptr); });
    }
    // (Whatever fails in there, the globals below are still freed.)
    Safely(L"Removing the taskbar styles", [] { ClearStyles(); });
    g_mainTaskbarStyled = false;
    if (g_unloading) {
        // (Its timer is this thread's: stopped here, not by the unloading
        // thread.)
        if (HWND taskbar = FindCurrentProcessTaskbarWnd()) {
            KillTimer(taskbar, kDisplayRestyleTimerId);
        }
        FreeXamlGlobals();
        return;
    }

    Safely(L"Checking the taskbar's parts", [] { CheckDockAvailable(); });
    EnumThreadWindows(GetCurrentThreadId(), ApplyToTaskbarWindowProc, 0);
    // (Also gives the room back when the dock can't style them now, see
    // RegrowTaskbarProc.)
    RefreshDockRoomProc(nullptr);
}

void WINAPI ApplySettingsProc(void*) {
    ApplySettingsFromTaskbarThread();
}

void ApplySettings() {
    if (HWND hTaskbarWnd = FindCurrentProcessTaskbarWnd()) {
        RunFromWindowThread(
            hTaskbarWnd, ApplySettingsProc, nullptr);
    }
}

using TrayUI_StartTaskbar_t = void(WINAPI*)(void* pThis);
TrayUI_StartTaskbar_t TrayUI_StartTaskbar_Original;
void WINAPI TrayUI_StartTaskbar_Hook(void* pThis) {
    IslandLog(L">");
    TrayUI_StartTaskbar_Original(pThis);
    Safely(L"Styling the new taskbar", [] { ApplySettingsFromTaskbarThread(); });
}

using CSecondaryTray_GetTrayWindow_t = HWND(WINAPI*)(void* pThis);
CSecondaryTray_GetTrayWindow_t CSecondaryTray_GetTrayWindow_Original;

using CSecondaryTray_InitModelAndHost_t = void(WINAPI*)(void* pThis,
                                                        void* taskbarModel);
CSecondaryTray_InitModelAndHost_t CSecondaryTray_InitModelAndHost_Original;
// Defined further down.
void SubclassTaskbars();

void WINAPI CSecondaryTray_InitModelAndHost_Hook(void* pThis,
                                                 void* taskbarModel) {
    IslandLog(L">");
    CSecondaryTray_InitModelAndHost_Original(pThis, taskbarModel);
    if (g_unloading) {
        return;
    }
    HWND taskbarWnd = CSecondaryTray_GetTrayWindow_Original(pThis);
    ApplyToTaskbar(taskbarWnd, GetSecondaryTaskbarXamlRoot(taskbarWnd), false);
    SubclassTaskbars();
}

////////////////////////////////////////////////////////////////////////////////
// Showing and hiding (taskbar thread).

// A slightly springy settle, like the macOS dock: fast at first, a hint of
// overshoot, then at rest. `t` goes from 0 to 1 over the animation.
double SpringOut(double t) {
    constexpr double kDamping = 0.78;
    // Settles within the duration.
    constexpr double kOmega = 5.2 / kDamping;
    const double dampedOmega = kOmega * std::sqrt(1 - kDamping * kDamping);
    return 1 - std::exp(-kDamping * kOmega * t) *
                   (std::cos(dampedOmega * t) +
                    kDamping * kOmega / dampedOmega * std::sin(dampedOmega * t));
}

double EaseInOutCubic(double t) {
    const double u = -2 * t + 2;
    return t < 0.5 ? 4 * t * t * t : 1 - u * u * u / 2;
}

int LerpInt(int a, int b, double t) {
    return a + (int)std::lround((b - a) * t);
}

// Waits for the next frame of an animation: one refresh of the screen after
// the last one (or the frame rate limit's interval), on a high-resolution
// timer. Not DwmFlush: waiting for the compositor after drawing puts the
// drawing and the refresh one after the other, which halves the frames on
// fast screens (as macOS minimize animation found too). A frame running late
// starts the next interval from now, not from when it should have started.
// Each animation loop has its own timer (a local: none is left behind on
// explorer's threads when the mod unloads).
struct FrameTimer {
    HANDLE handle = nullptr;
    double next = 0;
    double rate = 60;
    double rateReadAt = -100;
    FrameTimer() = default;
    FrameTimer(const FrameTimer&) = delete;
    FrameTimer& operator=(const FrameTimer&) = delete;
    ~FrameTimer() {
        if (handle) {
            CloseHandle(handle);
        }
    }
};

void WaitForAnimationFrame(FrameTimer& timer) {
    if (!timer.handle) {
        timer.handle = CreateWaitableTimerExW(
            nullptr, nullptr, CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,
            TIMER_MODIFY_STATE | SYNCHRONIZE);
    }
    const double now = NowSeconds();
    if (now - timer.rateReadAt > 5) {
        timer.rateReadAt = now;
        DWM_TIMING_INFO timing{sizeof(timing)};
        if (SUCCEEDED(DwmGetCompositionTimingInfo(nullptr, &timing)) &&
            timing.rateRefresh.uiDenominator &&
            timing.rateRefresh.uiNumerator) {
            timer.rate = (double)timing.rateRefresh.uiNumerator /
                         timing.rateRefresh.uiDenominator;
        }
    }
    const int limit = g_frameRateLimit.load(std::memory_order_relaxed);
    const double interval =
        1.0 / (limit ? std::min((double)limit, timer.rate) : timer.rate);
    timer.next = std::max(timer.next + interval, now);
    const double wait = timer.next - now;
    if (wait <= 0.0005) {
        return;
    }
    LARGE_INTEGER due;
    due.QuadPart = -(LONGLONG)(wait * 10'000'000);
    if (timer.handle && SetWaitableTimer(timer.handle, &due, 0, nullptr,
                                         nullptr, FALSE)) {
        WaitForSingleObject(timer.handle, 100);
    } else {
        Sleep((DWORD)std::ceil(wait * 1000));
    }
}

// The part of a taskbar it shows: on its own monitor, and before it moves to
// `next`, on it both where it is and where it goes (cut after the move, a
// frame would show it past the edge in between).
RECT TaskbarShownPart(HWND hWnd, const RECT* next) {
    RECT own = TaskbarOwnPart(hWnd);
    if (next) {
        const RECT there = TaskbarOwnPart(hWnd, next);
        if (!IntersectRect(&own, &own, &there)) {
            own = {};
        }
    }
    return own;
}

// A taskbar (not the transparent one, cut down to its apps) shows only its
// part on its own monitor while some of it is past its edge (hidden, or
// sliding: with a monitor past that edge, the rest would show there), and
// its whole window again once it's all on it. `next`: before it moves there.
void ClipToOwnMonitor(HWND hWnd, const RECT* next = nullptr) {
    RECT window;
    if (!GetWindowRect(hWnd, &window)) {
        return;
    }
    const RECT own = TaskbarShownPart(hWnd, next);
    const bool whole = own.left <= 0 && own.top <= 0 &&
                       own.right >= window.right - window.left &&
                       own.bottom >= window.bottom - window.top;
    const bool ours = std::find(g_ownClips.begin(), g_ownClips.end(), hWnd) !=
                      g_ownClips.end();
    if (whole) {
        // (Before a move, its cut stays until after it.)
        if (!next && ours) {
            std::erase(g_ownClips, hWnd);
            SetWindowRgn(hWnd, nullptr, RedrawsWithCut(hWnd));
        }
        return;
    }
    RECT current{};
    const int kind = GetWindowRgnBox(hWnd, &current);
    // (Unloading: none set again, see ClipDockWindow.)
    if (g_unloading ||
        (ours && kind == SIMPLEREGION && EqualRect(&current, &own))) {
        return;
    }
    if (HRGN region = CreateRectRgnIndirect(&own)) {
        // The system owns the region once it's set.
        if (!SetWindowRgn(hWnd, region, RedrawsWithCut(hWnd))) {
            DeleteObject(region);
        } else if (!ours) {
            g_ownClips.push_back(hWnd);
        }
    }
}

// The monitor a taskbar at `rect` belongs to (the row of it nearest the
// screen's inside, see TaskbarMonitor), and its scale: the dock's room is
// measured with it, the same whether the taskbar is shown or hidden (hidden,
// it's mostly over the next monitor, maybe with another scale, which the
// window takes then).
HMONITOR TaskbarMonitorAt(const RECT& rect) {
    return MonitorFromPoint({(rect.left + rect.right) / 2, rect.top},
                            MONITOR_DEFAULTTONEAREST);
}

double TaskbarScaleAt(const RECT& rect) {
    UINT dpiX = 96;
    UINT dpiY = 96;
    if (FAILED(GetDpiForMonitor(TaskbarMonitorAt(rect), MDT_EFFECTIVE_DPI,
                                &dpiX, &dpiY))) {
        dpiX = 96;
    }
    return dpiX / 96.0;
}

// The room of a grown taskbar, in pixels.
int GrownExtra(HWND hWnd, const GrownTaskbar& grown) {
    RECT now{};
    GetWindowRect(hWnd, &now);
    return (int)std::lround(grown.extraDips * TaskbarScaleAt(now));
}

// How close to the bottom edge the mouse brings the taskbar up (DIPs; see
// EdgeThreadProc): the height chosen (hiding.revealHeight), or as high as
// the dock's icons over its gap at the bottom (with a monitor below, the
// mouse easily goes past the last row), a few pixels for the transparent
// taskbar.
double EdgeShowDips() {
    if (g_settings.revealHeight > 0) {
        return g_settings.revealHeight;
    }
    return IsDock() ? g_settings.dockIconSize + g_settings.bottomGap : 8;
}

// The rows over the bottom edge of `monitor` (`bottom`) at `x` that bring
// the taskbar up, in pixels: the height chosen on every monitor, or
// automatically the whole strip (see EdgeShowDips) only with a monitor right
// below, where the mouse goes past the last row; otherwise the mouse stops
// at the edge and only its last rows count, like Windows' own (the dock came
// up as the mouse got near the bottom, #6472).
LONG EdgeStripPixels(LONG x, LONG bottom, UINT dpi) {
    const double dips =
        g_settings.revealHeight > 0 ||
                MonitorFromPoint({x, bottom}, MONITOR_DEFAULTTONULL)
            ? EdgeShowDips()
            : 2;
    return (LONG)std::lround(dips * dpi / 96);
}

// The mouse came down past the bottom of a monitor with another one right
// below it, under the dock's icons (or the transparent taskbar's apps): the
// first rows of the monitor below count as that edge as long as it stays in
// them (the mouse easily goes past the last row), shown and kept up (see
// EdgeThreadProc, TrayUI__ShouldAutoHideTray_Hook). Only coming from above:
// the top of the monitor below is used as it is otherwise. Set by the edge's
// thread.
std::atomic<HMONITOR> g_edgeCapture;

// The monitor right above `pt` whose bottom edge it counts for (see
// g_edgeCapture), or nullptr: `pt` in the first rows of the monitor `below`
// (as many as the strip over the edge, see EdgeShowDips), under the dock's
// icons or the apps there.
HMONITOR EdgeCaptureAbove(POINT pt, const RECT& below) {
    const HMONITOR above =
        MonitorFromPoint({pt.x, below.top - 1}, MONITOR_DEFAULTTONULL);
    MONITORINFO info{sizeof(info)};
    UINT dpiX = 96;
    UINT dpiY = 96;
    if (!above || !GetMonitorInfo(above, &info) ||
        info.rcMonitor.bottom != below.top ||
        FAILED(GetDpiForMonitor(above, MDT_EFFECTIVE_DPI, &dpiX, &dpiY)) ||
        pt.y >= below.top + (LONG)std::lround(EdgeShowDips() * dpiX / 96)) {
        return nullptr;
    }
    int appsLeft = 0;
    int appsRight = 0;
    if ((IsTransparentTaskbar() || IsDock()) &&
        GetAppsArea(above, &appsLeft, &appsRight) &&
        (pt.x < appsLeft || pt.x >= appsRight)) {
        return nullptr;
    }
    return above;
}

// Whether the mouse is in the rows past `taskbar`'s bottom edge that count
// for it now (see g_edgeCapture).
bool EdgeCaptureHolds(HWND taskbar) {
    const HMONITOR captured = g_edgeCapture;
    POINT pt{};
    MONITORINFO info{sizeof(info)};
    return captured && taskbar && TaskbarMonitor(taskbar) == captured &&
           GetCursorPos(&pt) &&
           GetMonitorInfo(MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST),
                          &info) &&
           EdgeCaptureAbove(pt, info.rcMonitor) == captured;
}

// Whether another monitor is right below `monitor` at `x`.
bool MonitorBelow(const RECT& monitor, LONG x) {
    return MonitorFromPoint({x, monitor.bottom}, MONITOR_DEFAULTTONULL) !=
           nullptr;
}

// How much higher the hidden dock's window (`base` with the room `extra`
// below) is than Windows puts it, in pixels (the rows above its last 2 on
// the screen are cut away, see ClipDockWindow): Windows shows a hidden
// taskbar only with the mouse on its window. With a monitor below, more than
// half of it stays on its own monitor: it keeps that monitor's scale, or it
// would change scale on its way up (its content hidden meanwhile, see
// g_dockContentHidden) whenever the one below has another.
int HiddenLift(const RECT& base, int extra) {
    const HMONITOR monitor = TaskbarMonitorAt(base);
    UINT dpiX = 96;
    UINT dpiY = 96;
    if (FAILED(GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI, &dpiX, &dpiY))) {
        dpiX = 96;
    }
    int lift = (int)std::lround((EdgeShowDips() - 2) * dpiX / 96);
    MONITORINFO info{sizeof(info)};
    if (GetMonitorInfo(monitor, &info) &&
        MonitorBelow(info.rcMonitor, (base.left + base.right) / 2)) {
        lift = std::max(lift, (int)(base.bottom - base.top + extra) / 2 +
                                  MulDiv(4, dpiX, 96));
    }
    return std::max(0, lift);
}

// The room of a dock's window that hides over a monitor below, in DIPs, at
// least (`baseDips`: the taskbar's own height): hidden, more than half of its
// window stays on its own monitor (see HiddenLift), and only with this much
// room above the dock is all of the dock past the edge there, so it slides
// away past the edge like the docks with no monitor below (with only the room
// for its magnified icons, part of it stayed above the edge and was cut away
// on its way down: it went into a line above the edge).
double RoomOverMonitorBelowDips(double baseDips) {
    const DockMetrics m = GetDockMetrics(0);
    // The dock at rest, with its apps' badges sticking out of it.
    const double rest = m.bottomGap + m.Height() + 8;
    // (Past the lift, half the window and a few pixels, or the rows the mouse
    // brings it up from, and the strip the taskbar keeps on the screen.)
    return std::max(2 * rest + 12, rest + EdgeShowDips() + 6) - baseDips;
}

// The taskbar's window with the dock's room (see GrownTaskbar), from where
// the taskbar puts itself: the room up while all of it is on its monitor
// (shown), down otherwise (hidden, past the screen's edge with the rest, a
// little higher: see HiddenLift).
RECT GrownRect(const RECT& base, int extra, bool* up) {
    MONITORINFO info{sizeof(info)};
    const HMONITOR monitor = TaskbarMonitorAt(base);
    *up = GetMonitorInfo(monitor, &info) && base.bottom <= info.rcMonitor.bottom;
    RECT grown = base;
    if (*up) {
        grown.top -= extra;
    } else {
        grown.bottom += extra;
        OffsetRect(&grown, 0, -HiddenLift(base, extra));
    }
    return grown;
}

// The taskbar placing itself (after its own handling of
// WM_WINDOWPOSCHANGING): with the dock's room added. A move with the
// window's size as it is (the room in it) is the taskbar's own height there.
// A size with the room already in it (the mod's own moves, or Windows' for a
// new scaling) is left as it is.
void GrowTaskbarWindow(HWND hWnd, WINDOWPOS* pos) {
    RECT now;
    if (!GetWindowRect(hWnd, &now)) {
        return;
    }
    if ((pos->flags & (SWP_NOMOVE | SWP_NOSIZE)) == (SWP_NOMOVE | SWP_NOSIZE)) {
        // Not grown yet (see RegrowTaskbarProc): the main taskbar's own
        // handler turns a move it didn't ask for into none at all (measured:
        // after the mod loaded, only the other monitors' taskbars grew).
        if (FindGrownTaskbar(hWnd)) {
            return;
        }
        pos->x = now.left;
        pos->y = now.top;
        pos->cx = now.right - now.left;
        pos->cy = now.bottom - now.top;
        pos->flags &= ~(SWP_NOMOVE | SWP_NOSIZE);
    }
    // (Upright or almost square: on its way to the left or right edge, see
    // below.)
    if (!(pos->flags & SWP_NOSIZE) && pos->cy * 2 > pos->cx) {
        // Its thickness: its width upright, or its own height (without the
        // room) at the bottom.
        LONG thickness = now.bottom - now.top;
        if (now.right - now.left < now.bottom - now.top) {
            thickness = now.right - now.left;
        } else if (const GrownTaskbar* grown = FindGrownTaskbar(hWnd)) {
            thickness -= GrownExtra(hWnd, *grown);
        }
        std::erase_if(g_grownTaskbars, [hWnd](const GrownTaskbar& taskbar) {
            return taskbar.wnd == hWnd;
        });
        // Never wider than a third of its monitor, nor higher than it: until
        // the dock's look goes (see WatchTaskbarPlace), Windows makes the
        // main taskbar as big as the screen on its way to a side (1920 by
        // 1920), keeps that size for the bottom edge too, and everything
        // freezes.
        MONITORINFO info{sizeof(info)};
        if (thickness > 0 &&
            GetMonitorInfo(TaskbarMonitor(hWnd), &info)) {
            const RECT& monitor = info.rcMonitor;
            if (pos->cx > (monitor.right - monitor.left) / 3) {
                // (On the right: against the monitor's right edge.)
                if (!(pos->flags & SWP_NOMOVE) && pos->x > monitor.left) {
                    pos->x = monitor.right - thickness;
                }
                pos->cx = thickness;
            }
            if (pos->cy > monitor.bottom - monitor.top) {
                if (!(pos->flags & SWP_NOMOVE)) {
                    pos->y = monitor.top;
                }
                pos->cy = monitor.bottom - monitor.top;
            }
        }
        return;
    }
    const double scale = TaskbarScaleAt(now);
    GrownTaskbar* grown = FindGrownTaskbar(hWnd);
    const int extraNow = grown ? GrownExtra(hWnd, *grown) : 0;
    RECT base;
    if (!(pos->flags & SWP_NOSIZE)) {
        if (grown && pos->cy / scale > grown->baseDips + grown->extraDips / 2) {
            return;
        }
        base.left = (pos->flags & SWP_NOMOVE) ? now.left : pos->x;
        base.top = (pos->flags & SWP_NOMOVE)
                       ? now.top + (!grown       ? 0
                                    : grown->up ? extraNow
                                                : grown->lift)
                       : pos->y;
        base.right = base.left + pos->cx;
        base.bottom = base.top + pos->cy;
    } else {
        const int height = now.bottom - now.top - extraNow;
        base = {pos->x, pos->y, pos->x + (now.right - now.left),
                pos->y + height};
    }
    // Moved to another edge (the dock goes away once that's noticed, see
    // WatchTaskbarPlace, which needs it all on its monitor): no room, and the
    // size the taskbar chose for that edge left as it is (`base` is measured
    // the bottom's way).
    // (Nor a shape that isn't a bar: on its way to a side, Windows sizes it
    // almost square for a moment.)
    MONITORINFO info{sizeof(info)};
    if ((base.bottom - base.top) * 2 > base.right - base.left ||
        (GetMonitorInfo(TaskbarMonitorAt(base), &info) &&
         RectSide(base, info.rcMonitor) != ABE_BOTTOM)) {
        std::erase_if(g_grownTaskbars, [hWnd](const GrownTaskbar& taskbar) {
            return taskbar.wnd == hWnd;
        });
        return;
    }
    const double baseDips = (base.bottom - base.top) / scale;
    double extraDips = DockRoomDips(baseDips);
    if (extraDips <= 0) {
        std::erase_if(g_grownTaskbars, [hWnd](const GrownTaskbar& taskbar) {
            return taskbar.wnd == hWnd;
        });
        if (pos->flags & SWP_NOSIZE) {
            pos->cy = base.bottom - base.top;
            pos->cx = base.right - base.left;
            pos->flags &= ~SWP_NOSIZE;
        }
        return;
    }
    if (g_taskbarAutoHides && GetMonitorInfo(TaskbarMonitorAt(base), &info) &&
        MonitorBelow(info.rcMonitor, (base.left + base.right) / 2)) {
        extraDips = std::max(extraDips, RoomOverMonitorBelowDips(baseDips));
    }
    bool up = false;
    const RECT target =
        GrownRect(base, (int)std::lround(extraDips * scale), &up);
    const int lift = up ? 0 : base.top - target.top;
    if (!grown) {
        g_grownTaskbars.push_back({hWnd, baseDips, extraDips, up, lift});
    } else {
        *grown = {hWnd, baseDips, extraDips, up, lift};
    }
    pos->x = target.left;
    pos->y = target.top;
    pos->cx = target.right - target.left;
    pos->cy = target.bottom - target.top;
    pos->flags &= ~(SWP_NOMOVE | SWP_NOSIZE);
}

// The taskbars' room made again for the settings now (or taken away: another
// taskbar mode, or the mod unloading): each window is put back at its own
// height, and grows again through GrowTaskbarWindow, like the taskbar's own
// moves.
BOOL CALLBACK RegrowTaskbarProc(HWND hWnd, LPARAM) {
    WCHAR className[32];
    RECT now;
    if (!GetClassName(hWnd, className, ARRAYSIZE(className)) ||
        (_wcsicmp(className, L"Shell_TrayWnd") != 0 &&
         _wcsicmp(className, L"Shell_SecondaryTrayWnd") != 0) ||
        !GetWindowRect(hWnd, &now)) {
        return TRUE;
    }
    RECT base = now;
    if (const GrownTaskbar* grown = FindGrownTaskbar(hWnd)) {
        const int extra = GrownExtra(hWnd, *grown);
        if (grown->up) {
            base.top += extra;
        } else {
            base.bottom -= extra;
            OffsetRect(&base, 0, grown->lift);
        }
        std::erase_if(g_grownTaskbars, [hWnd](const GrownTaskbar& taskbar) {
            return taskbar.wnd == hWnd;
        });
    } else if (!IsDock()) {
        return TRUE;
    }
    SetWindowPos(hWnd, nullptr, base.left, base.top, base.right - base.left,
                 base.bottom - base.top, SWP_NOZORDER | SWP_NOACTIVATE);
    return TRUE;
}

// Whether the taskbar hides itself (Windows' setting): see
// g_taskbarAutoHides. On the taskbar's thread.
void ReadTaskbarAutoHide() {
    APPBARDATA data{sizeof(data)};
    g_taskbarAutoHides =
        (SHAppBarMessage(ABM_GETSTATE, &data) & ABS_AUTOHIDE) != 0;
}

// Defined further down.
void WatchTaskbarWay();

void WINAPI RefreshDockRoomProc(void*) {
    std::erase_if(g_grownTaskbars, [](const GrownTaskbar& taskbar) {
        return !IsWindow(taskbar.wnd);
    });
    if (!g_unloading) {
        ReadTaskbarAutoHide();
    }
    EnumThreadWindows(GetCurrentThreadId(), RegrowTaskbarProc, 0);
    WatchTaskbarWay();
    StartRendering();
}

void RefreshDockRoom() {
    if (HWND hTaskbarWnd = FindCurrentProcessTaskbarWnd()) {
        RunFromWindowThread(hTaskbarWnd, RefreshDockRoomProc, nullptr);
    }
}

// Whether an app's jump list is open, opened from this dock (defined further
// down).
bool JumpListOpen(HWND dock);

// Whether the dock shows the tray (its other end, see ClipDockWindow).
bool DockTrayShown() {
    return !g_settings.hideTray && !g_settings.showIsland;
}

// The shown dock's window may hide with the mouse still on it but off what
// takes the mouse (see ClipDockWindow): beside the dock, over what's behind.
// Only while the taskbar hides itself: Windows asks this also with its
// auto-hide off (as Start closes), and the dock would go.
bool DockMayHide(HWND hWnd) {
    if (g_unloading || !g_taskbarAutoHides || !IsDock() || hWnd != g_dockWnd ||
        g_dockRoomOpen ||
        g_dockHovered || IsRectEmpty(&g_dockShelfRest) || DockTrayShown() ||
        IsKeptShown(hWnd) || JumpListOpen(hWnd) || !DockHidesOn(hWnd)) {
        return false;
    }
    RECT window{};
    RECT cut{};
    POINT pt{};
    if (!GetWindowRect(hWnd, &window) || !GetCursorPos(&pt) ||
        !PtInRect(&window, pt) ||
        GetWindowRgnBox(hWnd, &cut) == ERROR) {
        return false;
    }
    // Not in the strip along the edge under its icons, which brings it up
    // (see EdgeThreadProc): it would come up and go again, over and over.
    const HMONITOR monitor = TaskbarMonitor(hWnd);
    MONITORINFO info{sizeof(info)};
    int appsLeft = 0;
    int appsRight = 0;
    if (GetMonitorInfo(monitor, &info) &&
        GetAppsArea(monitor, &appsLeft, &appsRight) && pt.x >= appsLeft &&
        pt.x < appsRight &&
        pt.y >= info.rcMonitor.bottom -
                    EdgeStripPixels(pt.x, info.rcMonitor.bottom,
                                    GetDpiForWindow(hWnd))) {
        return false;
    }
    HRGN region = CreateRectRgn(0, 0, 0, 0);
    if (!region) {
        return false;
    }
    const bool off = GetWindowRgn(hWnd, region) != ERROR &&
                     !PtInRegion(region, pt.x - window.left, pt.y - window.top);
    DeleteObject(region);
    return off;
}

// The dock's window cut to what it shows: its part on its own monitor (see
// ClipToOwnMonitor), and once all of it is there, the taskbar's own height
// and the dock's shelf at rest, unless the mouse is on the dock or its icons
// move (they grow into its whole room then). Windows' own moves drop a
// region: cut again after them.
void ClipDockWindow(HWND hWnd, const RECT* next) {
    // (Unloading: the clips were taken off, none is set again: a last frame
    // would leave one the next load doesn't know, see ResetDockBehavior.)
    if (g_unloading) {
        return;
    }
    // Shown at once by Windows a moment ago: nothing of it shows (nor takes
    // the mouse) yet, see kQuietShowDelayMs.
    if (hWnd == g_quietShownWnd) {
        RECT current{};
        if (GetWindowRgnBox(hWnd, &current) != NULLREGION) {
            if (HRGN none = CreateRectRgn(0, 0, 0, 0)) {
                // (The system owns the region once it's set.)
                if (!SetWindowRgn(hWnd, none, RedrawsWithCut(hWnd))) {
                    DeleteObject(none);
                } else if (std::find(g_ownClips.begin(), g_ownClips.end(),
                                     hWnd) == g_ownClips.end()) {
                    g_ownClips.push_back(hWnd);
                }
            }
        }
        return;
    }
    DockScope scope(hWnd);
    RECT window;
    const GrownTaskbar* grown = FindGrownTaskbar(hWnd);
    if (!grown || hWnd != g_dockWnd || !GetWindowRect(hWnd, &window)) {
        ClipToOwnMonitor(hWnd, next);
        return;
    }
    const LONG width = window.right - window.left;
    const LONG height = window.bottom - window.top;
    const RECT own = TaskbarShownPart(hWnd, next);
    if (own.left > 0 || own.top > 0 || own.right < width ||
        own.bottom < height) {
        // (Hidden, the mouse isn't on its room: shown again, it's cut to the
        // taskbar's height until a frame finds the mouse on it. Left open,
        // its whole room showed with the dock up, painted white above it.)
        g_dockRoomOpen = false;
        // Hidden (only the strip at the edge left): it shows with the mouse
        // at the edge only under the dock's icons, like the transparent
        // taskbar under its apps (with the tray shown, all along the edge:
        // the tray is at the other end).
        // (No thumbnails with the dock going away: their window goes back.)
        if (!next) {
            PlaceThumbnailWindows();
        }
        // Only its last 2 pixels show (the rows above, see HiddenLift, take
        // no clicks), once it's there.
        const UINT dpi = GetDpiForWindow(hWnd);
        const bool trayShown = DockTrayShown();
        if (!next && !grown->up &&
            own.bottom - own.top <= grown->lift + MulDiv(4, dpi, 96)) {
            RECT under = own;
            under.top = std::max(own.top, own.bottom - MulDiv(2, dpi, 96));
            const bool onlyIcons =
                !trayShown && !IsRectEmpty(&g_dockShelfRest);
            if (onlyIcons) {
                const int margin = MulDiv((int)kAppsAreaMargin, dpi, 96);
                under.left = std::max(own.left, g_dockShelfRest.left - margin);
                under.right =
                    std::min(own.right, g_dockShelfRest.right + margin);
            }
            RECT current{};
            const bool same = GetWindowRgnBox(hWnd, &current) == SIMPLEREGION &&
                              EqualRect(&current, &under);
            if (under.right > under.left && !same) {
                if (HRGN region = CreateRectRgnIndirect(&under)) {
                    // (The system owns the region once it's set.)
                    if (SetWindowRgn(hWnd, region, RedrawsWithCut(hWnd))) {
                        if (std::find(g_ownClips.begin(), g_ownClips.end(),
                                      hWnd) == g_ownClips.end()) {
                            g_ownClips.push_back(hWnd);
                        }
                    } else {
                        DeleteObject(region);
                    }
                }
            }
            // (For the edge's own check, see EdgeThreadProc.)
            if (onlyIcons) {
                g_appsAreaMonitor = TaskbarMonitor(hWnd);
                SetAppsArea(g_appsAreaMonitor, window.left + under.left,
                            window.left + under.right);
            }
            return;
        }
        ClipToOwnMonitor(hWnd, next);
        return;
    }
    // (Shown, with the mouse on it or its icons moving: its whole room. Not
    // while hidden, above: its rows above the edge are on screen then, an
    // app opening or asking for attention would show the dock there.)
    if (g_dockRoomOpen) {
        ClipToOwnMonitor(hWnd, next);
        return;
    }
    const int extra = GrownExtra(hWnd, *grown);
    // The taskbar's own height: all along with the tray shown (it's at the
    // other end), otherwise only under the shelf, so the mouse gets past the
    // dock's sides to what's behind (see DockMayHide).
    RECT band{0, extra, width, height};
    if (!IsRectEmpty(&g_dockShelfRest) && !DockTrayShown()) {
        const int margin =
            MulDiv((int)kAppsAreaMargin, GetDpiForWindow(hWnd), 96);
        band.left = std::max(0L, g_dockShelfRest.left - margin);
        band.right = std::min(width, g_dockShelfRest.right + margin);
    }
    HRGN region = CreateRectRgnIndirect(&band);
    if (!region) {
        return;
    }
    if (!IsRectEmpty(&g_dockShelfRest)) {
        if (HRGN shelf = CreateRectRgnIndirect(&g_dockShelfRest)) {
            CombineRgn(region, region, shelf, RGN_OR);
            DeleteObject(shelf);
        }
    }
    // Already cut so.
    HRGN current = CreateRectRgn(0, 0, 0, 0);
    const bool same = current && GetWindowRgn(hWnd, current) != ERROR &&
                      EqualRgn(current, region);
    if (current) {
        DeleteObject(current);
    }
    // (The system owns the region once it's set.)
    if (!same && !SetWindowRgn(hWnd, region, RedrawsWithCut(hWnd))) {
        DeleteObject(region);
        return;
    }
    if (same) {
        DeleteObject(region);
    }
    // (Kept as the mod's also when it was already cut so, like by the mod
    // before it was turned off and on: the whole room opens again with the
    // mouse on it, see ClipToOwnMonitor.)
    if (std::find(g_ownClips.begin(), g_ownClips.end(), hWnd) ==
        g_ownClips.end()) {
        g_ownClips.push_back(hWnd);
    }
}

// Each step of a slide shows only the part of the taskbar on its own monitor,
// as Windows' own slide does: cut down to its apps (the transparent taskbar),
// or to that part. `next`: before the step, to where it goes.
void ClipSlideStep(HWND hWnd, const RECT* next) {
    DockScope scope(hWnd);
    if (hWnd == g_dockWnd && IsTransparentTaskbar() &&
        g_appsRight > g_appsLeft) {
        const RECT shown = TaskbarShownPart(hWnd, next);
        UpdateAppsArea(g_appsLeft, g_appsRight, false, &shown);
        return;
    }
    if (IsDock()) {
        ClipDockWindow(hWnd, next);
        return;
    }
    ClipToOwnMonitor(hWnd, next);
}

// The wait of a show Windows made at once (see kQuietShowDelayMs) ends: the
// caller cuts the window again, as it shows now or goes.
void EndQuietShow(HWND hWnd) {
    if (hWnd && hWnd == g_quietShownWnd) {
        g_quietShownWnd = nullptr;
        KillTimer(hWnd, kQuietShowTimerId);
    }
}

// Defined further down.
bool TaskbarSeeThrough();
void PaintTaskbarClear(HWND hWnd);

// Slides the window from where it is to `target`, one step per display frame,
// timed by the clock so a slow frame doesn't slow the whole animation down.
// Showing settles like a spring; hiding eases in and out.
void SlideTo(HWND hWnd, const RECT& target, int durationMs, bool show) {
    RECT start;
    if (!GetWindowRect(hWnd, &start) || EqualRect(&start, &target)) {
        return;
    }
    // A slide asked for during another one's step (the taskbar reacting to
    // its own move, like a new scale over another monitor): there at once,
    // or each would start another inside it, and the taskbar would never get
    // back to its messages.
    static int sliding = 0;
    if (sliding) {
        durationMs = 0;
    }
    sliding++;
    struct Done {
        ~Done() { sliding--; }
    } done;
    // Without an animation, it's there at once.
    if (durationMs <= 0) {
        ClipSlideStep(hWnd, &target);
        SetWindowPos(hWnd, nullptr, target.left, target.top,
                     target.right - target.left, target.bottom - target.top,
                     SWP_NOZORDER | SWP_NOACTIVATE);
        ClipSlideStep(hWnd, nullptr);
        return;
    }

    // The taskbar's handlers leave to the slide what it does itself with each
    // frame (see g_slidingTaskbar). Its window is painted black (see
    // PaintTaskbarClear) as the taskbar's moves do: with every frame only
    // while it shows, where each frame opens more of the window (the paint
    // reaches only what's cut open); hiding, once before the first and once
    // after the last, since no row comes out that wasn't there.
    struct Sliding {
        HWND wnd;
        HWND previousWnd;
        bool previousHides;
        Sliding(HWND wnd, bool hides)
            : wnd(wnd), previousWnd(g_slidingTaskbar),
              previousHides(g_slidingHides) {
            g_slidingTaskbar = wnd;
            g_slidingHides = hides;
        }
        ~Sliding() {
            g_slidingTaskbar = previousWnd;
            g_slidingHides = previousHides;
            // (What the frames' cuts and moves left to draw, once.)
            if (TaskbarSeeThrough()) {
                PaintTaskbarClear(wnd);
                RedrawWindow(wnd, nullptr, nullptr,
                             RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            }
        }
        Sliding(const Sliding&) = delete;
        Sliding& operator=(const Sliding&) = delete;
    };
    if (!show && TaskbarSeeThrough()) {
        PaintTaskbarClear(hWnd);
    }
    Sliding slidingNow(hWnd, !show);

    const double begin = NowSeconds();
    const double duration = durationMs / 1000.0;
    FrameTimer frames;
    for (;;) {
        const double t =
            std::min((NowSeconds() - begin) / duration, 1.0);
        const double p = t >= 1 ? 1 : show ? SpringOut(t) : EaseInOutCubic(t);
        const int left = LerpInt(start.left, target.left, p);
        const int top = LerpInt(start.top, target.top, p);
        const RECT step{left, top,
                        left + LerpInt(start.right - start.left,
                                       target.right - target.left, p),
                        top + LerpInt(start.bottom - start.top,
                                      target.bottom - target.top, p)};
        ClipSlideStep(hWnd, &step);
        SetWindowPos(hWnd, nullptr, step.left, step.top,
                     step.right - step.left, step.bottom - step.top,
                     SWP_NOZORDER | SWP_NOACTIVATE);
        ClipSlideStep(hWnd, nullptr);
        if (t >= 1) {
            break;
        }
        WaitForAnimationFrame(frames);
    }
}

// How long after an app asks for attention a "show" counts as the taskbar
// showing itself for it, in seconds.
constexpr double kAttentionShowWindow = 1.0;

// Whether the user is reaching for the taskbar right now: the mouse on it or
// at the bottom edge, or the Windows key held.
bool UserIsReachingForTaskbar(HWND hWnd) {
    if (((GetAsyncKeyState(VK_LWIN) | GetAsyncKeyState(VK_RWIN)) & 0x8000) ||
        EdgeCaptureHolds(hWnd)) {
        return true;
    }
    POINT pt;
    RECT rect;
    if (!GetCursorPos(&pt) || !GetWindowRect(hWnd, &rect)) {
        return true;
    }
    // (Cut down to a part, like the hidden dock's window to the edge under
    // its icons: only that part's width counts, all the way up the window,
    // where the mouse brings the dock, see EdgeShowDips.)
    RECT cut{};
    if (GetWindowRgnBox(hWnd, &cut) != ERROR && !IsRectEmpty(&cut)) {
        rect.left = std::max(rect.left, rect.left + cut.left);
        rect.right = std::min(rect.right, rect.left + (cut.right - cut.left));
    }
    // Only on its own monitor: hidden, the rest of its window is past the
    // edge, over the top of a monitor below, which counts for it only coming
    // from above (see EdgeCaptureHolds). The mouse resting there let an app
    // asking for attention bring it up (see KeepsDownForAttention).
    MONITORINFO info{sizeof(info)};
    const bool monitorKnown = GetMonitorInfo(TaskbarMonitor(hWnd), &info);
    if (monitorKnown) {
        IntersectRect(&rect, &rect, &info.rcMonitor);
        // (Hidden, its window is higher than that, see HiddenLift.)
        if (const GrownTaskbar* grown = FindGrownTaskbar(hWnd);
            grown && !grown->up) {
            rect.top = std::max(
                rect.top,
                info.rcMonitor.bottom -
                    (LONG)std::lround(EdgeShowDips() *
                                      GetDpiForWindow(hWnd) / 96.0));
        }
    }
    if (PtInRect(&rect, pt)) {
        return true;
    }
    // (At the bottom of its own monitor: another monitor can be below it.)
    return monitorKnown && PtInRect(&info.rcMonitor, pt) &&
           pt.y >= info.rcMonitor.bottom - 2;
}

// How light the screen is where the taskbar is about to show (0 dark, 1
// light), for the transparent taskbar's shadow: the area, shrunk to a few
// pixels, averaged.
void SampleBackdrop(const RECT& rect) {
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;
    if (width <= 0 || height <= 0) {
        return;
    }
    constexpr int kSampleWidth = 16;
    constexpr int kSampleHeight = 2;
    HDC screen = GetDC(nullptr);
    if (!screen) {
        return;
    }
    HDC memory = CreateCompatibleDC(screen);
    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = kSampleWidth;
    info.bmiHeader.biHeight = -kSampleHeight;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HBITMAP bitmap =
        memory ? CreateDIBSection(screen, &info, DIB_RGB_COLORS, &bits,
                                  nullptr, 0)
               : nullptr;
    if (bitmap && bits) {
        HGDIOBJ old = SelectObject(memory, bitmap);
        SetStretchBltMode(memory, HALFTONE);
        if (StretchBlt(memory, 0, 0, kSampleWidth, kSampleHeight, screen,
                       rect.left, rect.top, width, height, SRCCOPY)) {
            GdiFlush();
            double total = 0;
            const auto* pixels = (const BYTE*)bits;
            for (int i = 0; i < kSampleWidth * kSampleHeight; i++) {
                const BYTE* pixel = pixels + i * 4;
                total += (0.0722 * pixel[0] + 0.7152 * pixel[1] +
                          0.2126 * pixel[2]) /
                         255;
            }
            g_backdropLight = total / (kSampleWidth * kSampleHeight);
        }
        SelectObject(memory, old);
    }
    if (bitmap) {
        DeleteObject(bitmap);
    }
    if (memory) {
        DeleteDC(memory);
    }
    ReleaseDC(nullptr, screen);
    StartRendering();
}

// A taskbar kept down for an app asking for attention, logged once in a
// while (the app asks again every second).
void LogKeptDown() {
    static std::atomic<double> logged{-100.0};
    const double now = NowSeconds();
    if (now - logged >= 10) {
        logged = now;
        IslandLog(L"Not showing the taskbar for an app asking for attention");
    }
}

// TrayUI::Unhide's request (TrayCommon::UnhideRequest) for an app asking for
// attention: measured, the one that comes right after a flash.
constexpr int kUnhideForAttention = 17;
// When a taskbar was last asked to show itself for something else (the main
// one, see TrayUI_Unhide_Hook, or any by the mod, see UnhideTaskbar), which
// one, and for how long that wins: for that one only, or the other monitor's
// taskbar with the app's button came up too whenever the mouse brought the
// main one up (measured: with the mouse resting at the main one's edge, half
// a second after it showed).
std::atomic<double> g_otherUnhideAt{-100.0};
std::atomic<HWND> g_otherUnhideWnd{nullptr};
constexpr double kOtherUnhideSeconds = 1.0;

// Another request than kUnhideForAttention right after a flash, logged once
// in a while (like LogKeptDown).
void LogUnhideAfterFlash(int flags, int request) {
    static std::atomic<double> logged{-100.0};
    const double now = NowSeconds();
    if (now - logged >= 10) {
        logged = now;
        IslandLog(L"Taskbar asked up right after a flash: request %d, flags 0x%X",
               request, (unsigned)flags);
    }
}

// Unless the whole dock is wanted, the taskbar doesn't show itself when an
// app asks for attention: only the app's icon peeks out (or nothing). The
// transparent taskbar never does (its button shows it, once up). Not when
// the user is reaching for it, nor when it was just asked up for something
// else (like Start opening).
bool KeepsDownForAttention(HWND hTaskbarWnd) {
    // (A button asking for attention counts too: an app like Discord gets
    // the taskbar up before its flash reaches the mod.)
    return !g_unloading && SlidesItself() &&
           (!IsDock() || g_settings.attentionMode != AttentionMode::Dock) &&
           (NowSeconds() - g_lastFlashTime < kAttentionShowWindow ||
            std::any_of(g_dockIcons.begin(), g_dockIcons.end(),
                        [](const DockIcon& icon) { return icon.attention; })) &&
           (hTaskbarWnd != g_otherUnhideWnd ||
            NowSeconds() - g_otherUnhideAt >= kOtherUnhideSeconds) &&
           !UserIsReachingForTaskbar(hTaskbarWnd);
}

// The main taskbar asked to show itself: not for an app asking for attention
// (see KeepsDownForAttention); any other reason goes through, and its show
// too (see TrayUI_SlideWindow_Hook).
using TrayUI_Unhide_t = void(WINAPI*)(void* pThis, int flags, int request);
TrayUI_Unhide_t TrayUI_Unhide_Original;
void WINAPI TrayUI_Unhide_Hook(void* pThis, int flags, int request) {
    if (request != kUnhideForAttention) {
        g_otherUnhideWnd = OwnTaskbarWnd();
        g_otherUnhideAt = NowSeconds();
        // (kUnhideForAttention was measured on one build: another one that
        // numbers it otherwise shows here, right after a flash.)
        if (NowSeconds() - g_lastFlashTime < kAttentionShowWindow) {
            LogUnhideAfterFlash(flags, request);
        }
    } else if (HWND taskbar = FindCurrentProcessTaskbarWnd();
               taskbar && KeepsDownForAttention(taskbar)) {
        LogKeptDown();
        return;
    }
    TrayUI_Unhide_Original(pThis, flags, request);
}

// To show a taskbar from the mod (see UnhideTaskbar), as the
// taskbar-auto-hide-when-maximized mod does: the main one's TrayUI (its
// ITrayComponentHost part, found by that vtable) and each secondary one's
// CSecondaryTray, noted from their window procedures. (On the taskbars'
// thread.)
void* TrayUI_ITrayComponentHost_vftable;
void* g_trayUiHost;
std::vector<std::pair<HWND, void*>> g_secondaryTrays;

using CSecondaryTray__Unhide_t = void(WINAPI*)(void* pThis,
                                               int flags,
                                               int request);
CSecondaryTray__Unhide_t CSecondaryTray__Unhide_Original;

using TrayUI_WndProc_t = LRESULT(WINAPI*)(void* pThis,
                                          HWND hWnd,
                                          UINT Msg,
                                          WPARAM wParam,
                                          LPARAM lParam,
                                          bool* flag);
TrayUI_WndProc_t TrayUI_WndProc_Original;
LRESULT WINAPI TrayUI_WndProc_Hook(void* pThis,
                                   HWND hWnd,
                                   UINT Msg,
                                   WPARAM wParam,
                                   LPARAM lParam,
                                   bool* flag) {
    if (Msg == WM_NCDESTROY) {
        g_trayUiHost = nullptr;
    } else if (!g_trayUiHost && TrayUI_ITrayComponentHost_vftable) {
        void* part = pThis;
        for (int i = 0; i < 64; i++, part = (void**)part + 1) {
            if (*(void**)part == TrayUI_ITrayComponentHost_vftable) {
                g_trayUiHost = part;
                break;
            }
        }
    }
    return TrayUI_WndProc_Original(pThis, hWnd, Msg, wParam, lParam, flag);
}

using CSecondaryTray_v_WndProc_t = LRESULT(WINAPI*)(void* pThis,
                                                    HWND hWnd,
                                                    UINT Msg,
                                                    WPARAM wParam,
                                                    LPARAM lParam);
CSecondaryTray_v_WndProc_t CSecondaryTray_v_WndProc_Original;
LRESULT WINAPI CSecondaryTray_v_WndProc_Hook(void* pThis,
                                             HWND hWnd,
                                             UINT Msg,
                                             WPARAM wParam,
                                             LPARAM lParam) {
    auto it = std::find_if(g_secondaryTrays.begin(), g_secondaryTrays.end(),
                           [hWnd](const auto& tray) {
                               return tray.first == hWnd;
                           });
    if (Msg == WM_NCDESTROY) {
        if (it != g_secondaryTrays.end()) {
            g_secondaryTrays.erase(it);
        }
    } else if (it == g_secondaryTrays.end()) {
        g_secondaryTrays.push_back({hWnd, pThis});
    }
    return CSecondaryTray_v_WndProc_Original(pThis, hWnd, Msg, wParam, lParam);
}

// A taskbar shown by the mod as the taskbar itself shows it (flags and
// request 0, as taskbar-auto-hide-when-maximized calls it). Without what
// that needs on this build: the message its own "show" timer sends (taken
// only with the mouse over the hidden taskbar).
void UnhideTaskbar(HWND taskbar) {
    WCHAR className[32] = L"";
    GetClassName(taskbar, className, ARRAYSIZE(className));
    // (Up for the mod's own reason, like nothing in its way anymore: not
    // kept down for an app asking for attention meanwhile, see
    // KeepsDownForAttention.)
    g_otherUnhideWnd = taskbar;
    g_otherUnhideAt = NowSeconds();
    if (_wcsicmp(className, L"Shell_TrayWnd") == 0) {
        if (g_trayUiHost && TrayUI_Unhide_Original) {
            TrayUI_Unhide_Original(g_trayUiHost, 0, 0);
            return;
        }
    } else if (CSecondaryTray__Unhide_Original) {
        for (const auto& [wnd, tray] : g_secondaryTrays) {
            if (wnd == taskbar) {
                CSecondaryTray__Unhide_Original(tray, 0, 0);
                return;
            }
        }
    }
    PostMessage(taskbar, WM_TIMER, kUnhideTimerId, 0);
}

// From the edge's thread to a taskbar's: the mouse is still where it brings
// the taskbar up, and the message of its own "show" timer didn't (see
// EdgeThreadProc): it's shown as the mod shows it (see UnhideTaskbar). That
// message is taken only with the mouse over the hidden taskbar as Windows
// saw it come there, not after sliding in along the edge from beside the
// strip under the dock's icons (#6816).
const UINT g_edgeUnhideMessage =
    RegisterWindowMessage(L"WindhawkMacIslandDock_EdgeUnhide");

// Whether the taskbar hides now (its hide timer): also with the mouse
// beside the shown dock, over what's behind it (see DockMayHide). The
// argument is forwarded as it came (two registers for an object passed by
// value on ARM64).
using TrayUI__ShouldAutoHideTray_t = bool(WINAPI*)(void* pThis,
                                                   void* telemetry,
                                                   void* telemetryMore);
TrayUI__ShouldAutoHideTray_t TrayUI__ShouldAutoHideTray_Original;
bool WINAPI TrayUI__ShouldAutoHideTray_Hook(void* pThis,
                                            void* telemetry,
                                            void* telemetryMore) {
    if (SlidesItself() && g_dockWnd && DockMayHide(g_dockWnd)) {
        return true;
    }
    // The mouse just past its bottom edge, on the monitor below (see
    // g_edgeCapture): it stays up.
    if (SlidesItself() && g_edgeCapture.load() &&
        EdgeCaptureHolds(FindCurrentProcessTaskbarWnd())) {
        return false;
    }
    return TrayUI__ShouldAutoHideTray_Original(pThis, telemetry,
                                               telemetryMore);
}

using TrayUI_SlideWindow_t = void(WINAPI*)(void* pThis,
                                           HWND hWnd,
                                           const RECT* rect,
                                           HMONITOR monitor,
                                           bool show,
                                           bool animate);
TrayUI_SlideWindow_t TrayUI_SlideWindow_Original;
// Defined further down.
bool IsFullscreenAppOnMonitor(HWND hTaskbarWnd);
void WINAPI TrayUI_SlideWindow_Hook(void* pThis,
                                    HWND hWnd,
                                    const RECT* rect,
                                    HMONITOR monitor,
                                    bool show,
                                    bool animate) {
    if (!SlidesItself()) {
        TrayUI_SlideWindow_Original(pThis, hWnd, rect, monitor, show, animate);
        return;
    }
    // (Usually stopped earlier, see CTaskBand_UnhideTray_Hook.)
    if (show && KeepsDownForAttention(hWnd)) {
        LogKeptDown();
        // The taskbar now takes itself for shown. Its hide timer puts that
        // right, without moving anything.
        PostMessage(hWnd, WM_TIMER, kHideTimerId, 0);
        return;
    }

    if (hWnd == g_dockWnd) {
        g_trayShown = show;
        // The taskbar takes over from a dock shown for a notification.
        g_shownForNotification = false;
    }

    if (show && IsTransparentTaskbar()) {
        SampleBackdrop(*rect);
    }

    // The window has the dock's room (see GrownTaskbar): it slides with it.
    RECT target = *rect;
    if (const GrownTaskbar* grown = FindGrownTaskbar(hWnd);
        grown && IsDock() && !g_unloading) {
        bool up = false;
        target = GrownRect(*rect, GrownExtra(hWnd, *grown), &up);
    }

    // After a full screen app (like a video in a browser), Windows sometimes
    // leaves the taskbar below other windows, so it would show behind them,
    // even with its "topmost" style still set: on top whenever it shows.
    if (show && !g_unloading && !IsFullscreenAppOnMonitor(hWnd)) {
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    }

    // A hide while a show made at once still waits: nothing of the dock
    // showed, it goes at once. Any other move ends the wait too (a show: up
    // already, it shows now).
    const bool quietlyShown = hWnd == g_quietShownWnd;
    EndQuietShow(hWnd);
    if (!animate || g_unloading || (!show && quietlyShown)) {
        // A show at once with the user not reaching for the dock waits a
        // moment, cut to nothing (see kQuietShowDelayMs).
        if (show && !animate && !g_unloading && IsDock() &&
            FindGrownTaskbar(hWnd) && !UserIsReachingForTaskbar(hWnd)) {
            g_quietShownWnd = hWnd;
            SetTimer(hWnd, kQuietShowTimerId, kQuietShowDelayMs, nullptr);
        }
        TrayUI_SlideWindow_Original(pThis, hWnd, rect, monitor, show,
                                    animate && !quietlyShown);
        if (!g_unloading) {
            ClipSlideStep(hWnd, nullptr);
        }
        return;
    }

    // The window is moved by the mod's own animation, then the taskbar
    // finishes the move without its animation, which keeps its state right.
    SlideTo(hWnd, target,
            AnimationMs(show ? g_settings.showDuration
                             : g_settings.hideDuration),
            show);
    TrayUI_SlideWindow_Original(pThis, hWnd, rect, monitor, show, false);
    // Still cut down to its apps, or to its monitor (the taskbar's own move
    // drops a region), and to its strip once it's hidden.
    ClipSlideStep(hWnd, nullptr);
}

using SetTimer_t = decltype(&SetTimer);
SetTimer_t SetTimer_Original;
UINT_PTR WINAPI SetTimer_Hook(HWND hWnd,
                              UINT_PTR nIDEvent,
                              UINT uElapse,
                              TIMERPROC lpTimerFunc) {
    if (hWnd && !g_unloading && SlidesItself() &&
        (nIDEvent == kHideTimerId || nIDEvent == kUnhideTimerId)) {
        WCHAR className[32];
        if (GetClassName(hWnd, className, ARRAYSIZE(className)) &&
            (_wcsicmp(className, L"Shell_TrayWnd") == 0 ||
             _wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0)) {
            int delay = nIDEvent == kUnhideTimerId ? g_settings.showDelay
                                                   : g_settings.hideDelay;
            // While the dock is kept up, hiding is tried right after that
            // (the other monitors' taskbars hide as usual).
            const double keep = g_keepShownUntil - NowSeconds();
            if (nIDEvent == kHideTimerId && hWnd == g_keepShownWnd &&
                keep > 0) {
                delay = std::max(delay, (int)(keep * 1000) + 100);
            }
            // A timer can't be shorter than 10 ms anyway.
            uElapse = (UINT)std::max(delay, 10);
        }
    }
    return SetTimer_Original(hWnd, nIDEvent, uElapse, lpTimerFunc);
}

// Starts the taskbar's own hide timer with a delay of the mod's choosing.
void ScheduleTaskbarHide(HWND hTaskbarWnd, UINT delayMs) {
    SetTimer_Original(hTaskbarWnd, kHideTimerId, delayMs, nullptr);
}

// (Defined further down.)
void UpdateAutoHide();

// While Windows' auto-hide is on for a dock hiding on one monitor, the
// docks kept shown on the others still need their room on the screen (as
// Windows reserves it for a taskbar that doesn't hide): an app bar of the
// mod's own on each of those monitors' bottom edge, never shown, as tall as
// the dock at rest, so maximized windows stop above it. On a thread of its
// own (app bars ask the taskbar's thread), which checks them again every
// few seconds (monitors and taskbars come and go).
constexpr UINT kPinnedBarSync = WM_APP + 1;
constexpr UINT kPinnedBarCallback = WM_APP + 2;
constexpr UINT kPinnedBarCheckMs = 2000;
constexpr WCHAR kPinnedBarClass[] = L"WindhawkMacDockPinnedRoom";
HANDLE g_pinnedBarThread;
DWORD g_pinnedBarThreadId;

struct PinnedBar {
    HMONITOR monitor;
    HWND wnd;
    RECT rect;
};
// (Its thread's only.)
[[clang::no_destroy]] std::vector<PinnedBar> g_pinnedBars;

BOOL CALLBACK CollectTaskbarsProc(HWND hWnd, LPARAM data) {
    DWORD processId = 0;
    GetWindowThreadProcessId(hWnd, &processId);
    if (processId != GetCurrentProcessId()) {
        return TRUE;
    }
    WCHAR className[32] = L"";
    GetClassName(hWnd, className, ARRAYSIZE(className));
    if (_wcsicmp(className, L"Shell_TrayWnd") == 0 ||
        _wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0) {
        ((std::vector<HWND>*)data)->push_back(hWnd);
    }
    return TRUE;
}

LRESULT CALLBACK PinnedBarWndProc(HWND hWnd,
                                  UINT msg,
                                  WPARAM wParam,
                                  LPARAM lParam) {
    if (msg == kPinnedBarCallback) {
        if (wParam == ABN_POSCHANGED) {
            PostThreadMessage(GetCurrentThreadId(), kPinnedBarSync, 0, 0);
        }
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void RemovePinnedBar(const PinnedBar& bar) {
    APPBARDATA data{sizeof(data)};
    data.hWnd = bar.wnd;
    SHAppBarMessage(ABM_REMOVE, &data);
    DestroyWindow(bar.wnd);
}

void SetPinnedBarPos(PinnedBar& bar, const RECT& rect) {
    APPBARDATA data{sizeof(data)};
    data.hWnd = bar.wnd;
    data.uEdge = ABE_BOTTOM;
    data.rc = rect;
    SHAppBarMessage(ABM_QUERYPOS, &data);
    data.rc.top = data.rc.bottom - (rect.bottom - rect.top);
    SHAppBarMessage(ABM_SETPOS, &data);
    bar.rect = rect;
}

void SyncPinnedBars(bool all) {
    std::vector<std::pair<HMONITOR, RECT>> wanted;
    APPBARDATA state{sizeof(state)};
    const bool autoHides =
        !all && IsDock() && g_settings.dockPinButton && g_taskbarAtBottom &&
        (SHAppBarMessage(ABM_GETSTATE, &state) & ABS_AUTOHIDE) != 0;
    if (autoHides) {
        std::vector<HWND> taskbars;
        EnumWindows(CollectTaskbarsProc, (LPARAM)&taskbars);
        const DockMetrics metrics = GetDockMetrics(0);
        const double dips = metrics.bottomGap + metrics.Height();
        for (HWND taskbar : taskbars) {
            const HMONITOR monitor = TaskbarMonitor(taskbar);
            MONITORINFO info{sizeof(info)};
            if (DockHidesOnMonitor(monitor) ||
                !GetMonitorInfo(monitor, &info)) {
                continue;
            }
            const int height =
                (int)std::ceil(dips * GetDpiForWindow(taskbar) / 96.0);
            wanted.push_back(
                {monitor,
                 {info.rcMonitor.left, info.rcMonitor.bottom - height,
                  info.rcMonitor.right, info.rcMonitor.bottom}});
        }
    }
    std::erase_if(g_pinnedBars, [&](const PinnedBar& bar) {
        const bool keep = std::any_of(
            wanted.begin(), wanted.end(),
            [&](const auto& want) { return want.first == bar.monitor; });
        if (!keep) {
            RemovePinnedBar(bar);
        }
        return !keep;
    });
    for (const auto& [monitor, rect] : wanted) {
        auto found = std::find_if(
            g_pinnedBars.begin(), g_pinnedBars.end(),
            [&](const PinnedBar& bar) { return bar.monitor == monitor; });
        if (found == g_pinnedBars.end()) {
            HWND wnd = CreateWindowEx(
                WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, kPinnedBarClass, L"",
                WS_POPUP, rect.left, rect.top, rect.right - rect.left,
                rect.bottom - rect.top, nullptr, nullptr,
                GetModuleHandle(nullptr), nullptr);
            if (!wnd) {
                continue;
            }
            APPBARDATA data{sizeof(data)};
            data.hWnd = wnd;
            data.uCallbackMessage = kPinnedBarCallback;
            if (!SHAppBarMessage(ABM_NEW, &data)) {
                DestroyWindow(wnd);
                continue;
            }
            g_pinnedBars.push_back({monitor, wnd, {}});
            SetPinnedBarPos(g_pinnedBars.back(), rect);
            IslandLog(L"Room kept for the pinned dock (%d px)",
                      (int)(rect.bottom - rect.top));
            continue;
        }
        // Moved, or the room was lost (the work area reaches past it).
        MONITORINFO info{sizeof(info)};
        const bool lost =
            GetMonitorInfo(monitor, &info) && info.rcWork.bottom > rect.top;
        if (!EqualRect(&found->rect, &rect) || lost) {
            SetPinnedBarPos(*found, rect);
        }
    }
}

DWORD WINAPI PinnedBarThreadProc(LPVOID started) {
    MSG msg;
    PeekMessage(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    SetEvent((HANDLE)started);
    WNDCLASS wc{};
    wc.lpfnWndProc = PinnedBarWndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = kPinnedBarClass;
    RegisterClass(&wc);
    const UINT_PTR timer = SetTimer(nullptr, 0, kPinnedBarCheckMs, nullptr);
    SyncPinnedBars(false);
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        if (!msg.hwnd &&
            (msg.message == kPinnedBarSync ||
             (msg.message == WM_TIMER && msg.wParam == timer))) {
            SyncPinnedBars(g_unloading);
            continue;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    KillTimer(nullptr, timer);
    SyncPinnedBars(true);
    UnregisterClass(kPinnedBarClass, GetModuleHandle(nullptr));
    return 0;
}

void StartPinnedBars() {
    if (g_pinnedBarThread) {
        return;
    }
    HANDLE started = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (!started) {
        return;
    }
    g_pinnedBarThread = CreateThread(nullptr, 0, PinnedBarThreadProc, started,
                                     0, &g_pinnedBarThreadId);
    if (g_pinnedBarThread) {
        WaitForSingleObject(started, INFINITE);
    } else {
        g_pinnedBarThreadId = 0;
    }
    CloseHandle(started);
}

void SyncPinnedBarsSoon() {
    if (g_pinnedBarThreadId) {
        PostThreadMessage(g_pinnedBarThreadId, kPinnedBarSync, 0, 0);
    }
}

void StopPinnedBars() {
    if (!g_pinnedBarThread) {
        return;
    }
    PostThreadMessage(g_pinnedBarThreadId, WM_QUIT, 0, 0);
    WaitForSingleObject(g_pinnedBarThread, 5000);
    CloseHandle(g_pinnedBarThread);
    g_pinnedBarThread = nullptr;
    g_pinnedBarThreadId = 0;
}

DWORD WINAPI DockPinAutoHideThreadProc(LPVOID) {
    if (!g_unloading) {
        UpdateAutoHide();
        RefreshDockRoom();
        SyncPinnedBarsSoon();
    }
    return 0;
}

// The dock's arrow clicked (on its taskbar's thread): the dock on that
// monitor is kept shown, or hides itself from now on, and Windows' auto-hide
// follows (on a thread of its own: it asks the taskbar's thread).
void ToggleDockPin(HWND taskbar) {
    const HMONITOR monitor = TaskbarMonitor(taskbar);
    const bool hid = DockHidesOnMonitor(monitor);
    SetDockPinState(monitor, hid ? 1 : 2);
    IslandLog(L"The dock's arrow: %s", hid ? L"kept shown" : L"hiding");
    if (HANDLE thread = CreateThread(nullptr, 0, DockPinAutoHideThreadProc,
                                     nullptr, 0, nullptr)) {
        CloseHandle(thread);
    }
    if (hid) {
        UnhideTaskbar(taskbar);
    } else {
        ScheduleTaskbarHide(taskbar, 600);
    }
    StartRendering();
}

////////////////////////////////////////////////////////////////////////////////
// Full-screen apps.

bool IsShellWindow(HWND hWnd) {
    WCHAR className[32];
    if (!GetClassName(hWnd, className, ARRAYSIZE(className))) {
        return false;
    }
    for (PCWSTR shellClass : {L"Progman", L"WorkerW", L"Shell_TrayWnd",
                              L"Shell_SecondaryTrayWnd"}) {
        if (_wcsicmp(className, shellClass) == 0) {
            return true;
        }
    }
    return false;
}

// What WindowInTheWayProc looks for (the island's way, see
// Island::WindowInTheWay, or a taskbar's, see WindowInTaskbarWay), and the
// window found. `self`: a process left out (the island's), or 0.
struct WindowInTheWaySearch {
    HMONITOR monitor;
    RECT place;
    bool maximizedOnly;
    DWORD self;
    bool found;
};

bool IsAppWindow(HWND hWnd);
bool IsCloakedWindow(HWND window);

BOOL CALLBACK WindowInTheWayProc(HWND hWnd, LPARAM lParam) {
    auto& search = *reinterpret_cast<WindowInTheWaySearch*>(lParam);
    DWORD processId = 0;
    GetWindowThreadProcessId(hWnd, &processId);
    if ((search.self && processId == search.self) || !IsAppWindow(hWnd) ||
        IsIconic(hWnd) || IsCloakedWindow(hWnd) || IsShellWindow(hWnd)) {
        return TRUE;
    }
    if (search.maximizedOnly) {
        search.found =
            IsZoomed(hWnd) &&
            MonitorFromWindow(hWnd, MONITOR_DEFAULTTONULL) == search.monitor;
    } else {
        // (Its visible frame: not the invisible resize borders.)
        RECT rect;
        RECT overlap;
        search.found = (SUCCEEDED(DwmGetWindowAttribute(
                            hWnd, DWMWA_EXTENDED_FRAME_BOUNDS, &rect,
                            sizeof(rect))) ||
                        GetWindowRect(hWnd, &rect)) &&
                       IntersectRect(&overlap, &rect, &search.place);
    }
    return !search.found;
}

// Windows' events that can change what's in the way (an app's window made,
// closed, shown, hidden, moved or sized, cloaked or uncloaked, brought to
// the front), as the taskbar-auto-hide-when-maximized mod watches them: the
// windows are looked at again only after one (see TaskbarWayThreadProc and
// Island::UpdateWindowEvents), not every few moments.
constexpr std::pair<DWORD, DWORD> kWindowEventRanges[] = {
    {EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND},
    {EVENT_OBJECT_CREATE, EVENT_OBJECT_HIDE},
    {EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE},
    {0x8017, 0x8018},  // EVENT_OBJECT_CLOAKED, EVENT_OBJECT_UNCLOAKED
};

// Whether an event is about an app's window: a top-level one, not the
// desktop's nor a taskbar's.
bool IsWindowEventForApp(HWND hWnd, LONG idObject, LONG idChild) {
    if (idObject != OBJID_WINDOW || idChild != CHILDID_SELF || !hWnd ||
        (GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD)) {
        return false;
    }
    const HWND parent = GetAncestor(hWnd, GA_PARENT);
    return (!parent || parent == GetDesktopWindow()) && !IsShellWindow(hWnd);
}

// "When it hides" (hiding.hideWhen, #6202 #6368): the dock, or the
// transparent taskbar, stays up on the desktop and hides only while an app's
// window is in its way, like the island (see Island::WindowInTheWay); the
// mouse at the bottom edge still brings it up over the window. Each taskbar
// looks again after Windows' events, once for a burst of them (see
// TaskbarWayThreadProc and CheckTaskbarWay).
// (Not one of the taskbar's own timers: posted to it.)
constexpr UINT_PTR kTaskbarWayTimerId = 0x4D4B;
constexpr UINT kTaskbarWayBatchMs = 200;
// Its own hide timer started again once a window is in its way (it decides
// with the mouse, as always), this long after.
constexpr UINT kTaskbarWayHideMs = 50;

bool TaskbarWayWatched() {
    return g_settings.hideWhen > 0 &&
           (SlidesItself() || AppsTaskbarEffects()) && g_taskbarAutoHides &&
           !g_unloading;
}

// An app's window in the taskbar's way: maximized on its monitor (hideWhen
// 1), or over where it shows (2, maximized ones too); a full-screen app
// always.
bool WindowInTaskbarWay(HWND taskbar) {
    // (This taskbar's own dock, not the main one's.)
    DockScope scope(taskbar);
    const HMONITOR monitor = TaskbarMonitor(taskbar);
    MONITORINFO info{sizeof(info)};
    RECT window;
    if (!GetMonitorInfo(monitor, &info) || !GetWindowRect(taskbar, &window)) {
        return false;
    }
    // Where it shows: at the bottom edge, as tall as its window, over its
    // apps; the dock, only its shelf (not the room above it the magnified
    // icons take).
    const LONG height = window.bottom - window.top;
    RECT place{window.left, info.rcMonitor.bottom - height, window.right,
               info.rcMonitor.bottom};
    int appsLeft = 0;
    int appsRight = 0;
    if (taskbar == g_dockWnd && IsDock() && !IsRectEmpty(&g_dockShelfRest)) {
        place.left = window.left + g_dockShelfRest.left;
        place.right = window.left + g_dockShelfRest.right;
        // (Its shelf's top as last drawn up: with a monitor below, its window
        // goes past its monitor's bottom, see RoomOverMonitorBelowDips.)
        const GrownTaskbar* grown = FindGrownTaskbar(taskbar);
        place.top = grown && grown->shelfTop > 0
                        ? grown->shelfTop
                        : info.rcMonitor.bottom - (height - g_dockShelfRest.top);
    } else if (GetAppsArea(monitor, &appsLeft, &appsRight)) {
        place.left = appsLeft;
        place.right = appsRight;
    }
    WindowInTheWaySearch search{monitor, place, g_settings.hideWhen == 1, 0,
                                IsFullscreenAppOnMonitor(taskbar)};
    if (!search.found) {
        EnumWindows(WindowInTheWayProc, reinterpret_cast<LPARAM>(&search));
    }
    return search.found;
}

// After Windows' events (see TaskbarWayThreadProc): back up once nothing is
// in its way (as the mouse at the bottom edge brings it, see
// EdgeThreadProc), or its own hide timer started again once a window is
// (stopped while nothing was, see TaskbarSubclassProc).
void CheckTaskbarWay(HWND taskbar) {
    MONITORINFO info{sizeof(info)};
    if (!TaskbarWayWatched() ||
        !GetMonitorInfo(TaskbarMonitor(taskbar), &info)) {
        return;
    }
    const bool hidden = IsTaskbarHidden(taskbar, info.rcMonitor);
    const bool inTheWay = WindowInTaskbarWay(taskbar);
    if (hidden && !inTheWay) {
        UnhideTaskbar(taskbar);
    } else if (!hidden && inTheWay) {
        ScheduleTaskbarHide(taskbar, kTaskbarWayHideMs);
    }
}

// Whether a process's program is one of these ("name.exe").
bool ProcessIsOneOf(DWORD processId, std::initializer_list<PCWSTR> programs) {
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (!process) {
        return false;
    }
    WCHAR path[MAX_PATH];
    DWORD length = ARRAYSIZE(path);
    const bool named = QueryFullProcessImageName(process, 0, path, &length);
    CloseHandle(process);
    if (!named) {
        return false;
    }
    PCWSTR name = PathFindFileName(path);
    for (PCWSTR program : programs) {
        if (_wcsicmp(name, program) == 0) {
            return true;
        }
    }
    return false;
}

// The screenshot's selection (Win+Shift+S) (see Island::Tick).
constexpr std::initializer_list<PCWSTR> kSnippingPrograms = {
    L"ScreenClippingHost.exe", L"SnippingTool.exe"};

// Windows' own screens over everything for a moment, not apps: the
// screenshot's selection, the desktops' switch and task view, Start, search
// and the quick settings.
bool IsShellOverlay(DWORD processId) {
    return ProcessIsOneOf(processId, kSnippingPrograms) ||
           ProcessIsOneOf(processId,
                          {L"explorer.exe", L"ShellExperienceHost.exe",
                           L"StartMenuExperienceHost.exe", L"SearchHost.exe"});
}

// Whether a window is the screenshot's selection covering a monitor.
bool IsSnippingSelection(HWND window, HMONITOR monitor) {
    window = GetAncestor(window, GA_ROOT);
    MONITORINFO info{sizeof(info)};
    RECT rect;
    DWORD processId = 0;
    return window && IsWindowVisible(window) &&
           GetMonitorInfo(monitor, &info) &&
           GetWindowRect(window, &rect) && !IsZoomed(window) &&
           rect.left <= info.rcMonitor.left && rect.top <= info.rcMonitor.top &&
           rect.right >= info.rcMonitor.right &&
           rect.bottom >= info.rcMonitor.bottom &&
           GetWindowThreadProcessId(window, &processId) &&
           ProcessIsOneOf(processId, kSnippingPrograms);
}

// Whether the screenshot's selection covers a monitor (in front).
bool IsSnippingOn(HMONITOR monitor) {
    return IsSnippingSelection(GetForegroundWindow(), monitor);
}

// The island's process, told by its hello (see WatchIslandProcess).
extern DWORD g_islandProcessId;

// Whether a window covers the whole monitor like a full-screen app (games
// in exclusive or borderless full screen, videos in full screen).
// `windowsSaysBusy`: Windows itself takes a full-screen app to be running (a
// browser's video in full screen, for one), so a window with a title bar
// counts even if its size isn't exactly the screen's.
bool CoversMonitor(HWND hWnd,
                   HMONITOR monitor,
                   const RECT& monitorRect,
                   bool windowsSaysBusy = false) {
    if (!hWnd || !IsWindowVisible(hWnd) || IsShellWindow(hWnd) ||
        IsCloakedWindow(hWnd) ||
        MonitorFromWindow(hWnd, MONITOR_DEFAULTTONULL) != monitor) {
        return false;
    }
    DWORD processId = 0;
    // Not the mod's own windows (the dock's here; the island's, its panels
    // and the wallpaper's transition, which covers the whole monitor).
    if (GetWindowThreadProcessId(hWnd, &processId) &&
        (processId == GetCurrentProcessId() ||
         processId == g_islandProcessId)) {
        return false;
    }
    RECT rect;
    if (!GetWindowRect(hWnd, &rect) || rect.left > monitorRect.left ||
        rect.top > monitorRect.top || rect.right < monitorRect.right ||
        rect.bottom < monitorRect.bottom || IsShellOverlay(processId)) {
        return false;
    }
    // Exactly the screen: full screen, whatever its style (a browser keeps
    // its window "maximized" while it plays a video in full screen).
    if (EqualRect(&rect, &monitorRect)) {
        return true;
    }
    // Bigger than the screen: a maximized window (with the taskbar hidden,
    // its borders go past the screen's edges) isn't full screen, and neither
    // is one with a title bar stretched over it (like File Explorer), unless
    // Windows itself takes it for a full-screen app.
    if (IsZoomed(hWnd)) {
        return false;
    }
    if ((GetWindowLongPtr(hWnd, GWL_STYLE) & WS_CAPTION) == WS_CAPTION) {
        return windowsSaysBusy;
    }
    return true;
}

// Whether a full-screen app (a game, a video) is on this taskbar's monitor,
// whichever app is in front (a video full screen on one monitor while the
// user works on another): see IsFullscreenAppOn.
bool IsFullscreenAppOn(HMONITOR monitor);

bool IsFullscreenAppOnMonitor(HWND hTaskbarWnd) {
    return IsFullscreenAppOn(TaskbarMonitor(hTaskbarWnd));
}

// Windows sometimes leaves a taskbar under a window with its "topmost" style
// still set (seen at sign-in: an app opening maximized on the second monitor
// came out above that monitor's taskbar until Start opened), and the guards
// that keep it on top (TrayUI_SlideWindow_Hook, TaskbarSubclassProc) only run
// where the mod hides it: the magnified icons in the dock's room would show
// behind that window. Raised as the mouse comes in, unless an app is in full
// screen there.
void RaiseOverWindows(HWND hTaskbarWnd) {
    RECT bar{};
    if (!GetWindowRect(hTaskbarWnd, &bar) ||
        IsFullscreenAppOnMonitor(hTaskbarWnd)) {
        return;
    }
    for (HWND w = GetWindow(hTaskbarWnd, GW_HWNDPREV); w;
         w = GetWindow(w, GW_HWNDPREV)) {
        RECT rect{}, both{};
        if (!(GetWindowLongPtr(w, GWL_EXSTYLE) & WS_EX_TOPMOST) &&
            IsWindowVisible(w) && GetWindowRect(w, &rect) &&
            IntersectRect(&both, &rect, &bar)) {
            SetWindowPos(hTaskbarWnd, HWND_TOPMOST, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            return;
        }
    }
}

// Exclusive full screen (Direct3D) or a presentation, as reported by Windows:
// nothing of another app shows over them.
bool IsExclusiveFullscreen() {
    QUERY_USER_NOTIFICATION_STATE state = QUNS_ACCEPTS_NOTIFICATIONS;
    return SUCCEEDED(SHQueryUserNotificationState(&state)) &&
           (state == QUNS_RUNNING_D3D_FULL_SCREEN ||
            state == QUNS_PRESENTATION_MODE);
}

// A full-screen app on a monitor: the window in front, the one at the top of
// the screen (in front may be something small, like a browser's "press Esc"
// hint), or the window covering the monitor's middle (the app in front is on
// another monitor, or small).
bool IsFullscreenAppOn(HMONITOR monitor) {
    // Exclusive full screen (Direct3D) and presentations, as reported by
    // Windows.
    QUERY_USER_NOTIFICATION_STATE state = QUNS_ACCEPTS_NOTIFICATIONS;
    if (SUCCEEDED(SHQueryUserNotificationState(&state)) &&
        (state == QUNS_RUNNING_D3D_FULL_SCREEN ||
         state == QUNS_PRESENTATION_MODE)) {
        return true;
    }
    // "Busy": Windows sees a full-screen app (not only Direct3D ones).
    const bool busy = state == QUNS_BUSY;

    MONITORINFO info{sizeof(info)};
    if (!GetMonitorInfo(monitor, &info)) {
        return false;
    }
    HWND foreground = GetForegroundWindow();
    if (CoversMonitor(GetAncestor(foreground, GA_ROOT), monitor,
                      info.rcMonitor, busy)) {
        return true;
    }
    // Only when the window in front is that one's (a hint over a video),
    // not any window behind the one being used.
    const POINT top{(info.rcMonitor.left + info.rcMonitor.right) / 2,
                    info.rcMonitor.top + 1};
    HWND atTop = GetAncestor(WindowFromPoint(top), GA_ROOT);
    if (atTop && atTop != foreground) {
        DWORD topProcess = 0, foregroundProcess = 0;
        GetWindowThreadProcessId(atTop, &topProcess);
        GetWindowThreadProcessId(foreground, &foregroundProcess);
        if (topProcess == foregroundProcess &&
            CoversMonitor(atTop, monitor, info.rcMonitor, busy)) {
            return true;
        }
    }
    const POINT middle{(info.rcMonitor.left + info.rcMonitor.right) / 2,
                       (info.rcMonitor.top + info.rcMonitor.bottom) / 2};
    return CoversMonitor(GetAncestor(WindowFromPoint(middle), GA_ROOT), monitor,
                         info.rcMonitor);
}

////////////////////////////////////////////////////////////////////////////////
// Taskbar windows: subclassing, focus and helpers.

// A process's program file when the process can't be opened (a service's,
// like NVIDIA's display container, or an elevated app's): Windows tells any
// process's file by its ID (the system information class
// SystemProcessIdInformation), as a device's path
// ("\Device\HarddiskVolume3\..."), turned here into its drive's. Empty if
// not found.
std::wstring ProcessImagePathById(DWORD processId) {
    using NtQuerySystemInformation_t = LONG(NTAPI*)(ULONG, PVOID, ULONG,
                                                    PULONG);
    static const auto query =
        (NtQuerySystemInformation_t)GetProcAddress(
            GetModuleHandle(L"ntdll.dll"), "NtQuerySystemInformation");
    constexpr ULONG kSystemProcessIdInformation = 88;
    struct {
        HANDLE processId;
        USHORT length;
        USHORT room;
        PWSTR buffer;
    } info{};
    WCHAR name[MAX_PATH * 2];
    info.processId = (HANDLE)(ULONG_PTR)processId;
    info.room = sizeof(name);
    info.buffer = name;
    if (!query ||
        query(kSystemProcessIdInformation, &info, sizeof(info), nullptr) < 0) {
        return {};
    }
    const std::wstring device(name, info.length / sizeof(WCHAR));
    WCHAR drive[] = L"A:";
    WCHAR target[MAX_PATH];
    for (WCHAR letter = L'A'; letter <= L'Z'; letter++) {
        drive[0] = letter;
        if (!QueryDosDevice(drive, target, ARRAYSIZE(target))) {
            continue;
        }
        const size_t length = wcslen(target);
        if (device.size() > length && device[length] == L'\\' &&
            device.compare(0, length, target) == 0) {
            return drive + device.substr(length);
        }
    }
    return {};
}
// Defined further down.
void WatchTaskbarPlace();
void StopWatchingTaskbarPlace();
void PublishProgress(bool force);

void WatchIslandProcess(HWND island);
void StopWatchingIslandProcess();

// When an app's window closes, Windows gives the focus back to the window
// that had it before: often the taskbar, clicked to open that app. A taskbar
// that hides itself stays up while it has the focus, so it would stay until
// the user clicked elsewhere. Then the focus goes to the next window, like
// Alt+Esc (or the desktop), and the taskbar hides as usual.
std::atomic<double> g_appClosedAt{0};

bool IsWindowToFocus(HWND hWnd) {
    if (!IsWindowVisible(hWnd) || IsIconic(hWnd) || IsShellWindow(hWnd)) {
        return false;
    }
    const LONG_PTR exStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
    if ((exStyle &
         (WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_TRANSPARENT)) ||
        (GetWindow(hWnd, GW_OWNER) && !(exStyle & WS_EX_APPWINDOW))) {
        return false;
    }
    BOOL cloaked = FALSE;
    if (SUCCEEDED(DwmGetWindowAttribute(hWnd, DWMWA_CLOAKED, &cloaked,
                                        sizeof(cloaked))) &&
        cloaked) {
        return false;
    }
    RECT rect;
    return GetWindowRect(hWnd, &rect) && rect.right > rect.left &&
           rect.bottom > rect.top;
}

// On the taskbar's hide timer, right after an app closed. Returns whether
// the focus was moved.
// (How long after a click on it the taskbar's focus counts as the click's.)
constexpr double kFocusClickSeconds = 600;

bool HandFocusBack(HWND hWnd) {
    const double now = NowSeconds();
    if (g_unloading || !SlidesItself() || IsKeptShown(hWnd)) {
        return false;
    }
    // Also when the taskbar has the focus from a click on it (on the open
    // app's icon, which minimized it): Windows keeps a taskbar that hides
    // itself up while it has the focus (not when it got it from the
    // keyboard, to be used with it).
    const HWND foreground = GetForegroundWindow();
    const bool clicked = g_taskbarAutoHides && foreground == hWnd &&
                         now - g_dockPressedAt < kFocusClickSeconds;
    if ((now - g_appClosedAt > 8 && !clicked) ||
        (foreground && foreground != hWnd) || UserIsReachingForTaskbar(hWnd)) {
        return false;
    }
    g_appClosedAt = 0;
    HWND next = nullptr;
    for (HWND window = GetTopWindow(nullptr); window;
         window = GetWindow(window, GW_HWNDNEXT)) {
        if (IsWindowToFocus(window)) {
            next = window;
            break;
        }
    }
    if (!next) {
        next = FindWindow(L"Progman", nullptr);
    }
    return next && SetForegroundWindow(next);
}

// The taskbar shows what's behind it where the mod took its background away:
// the dock (its room and beside its shelf) and the transparent Windows
// taskbar.
bool TaskbarSeeThrough() {
    return IsDock() || IsTransparentTaskbar();
}

// The taskbar's own window painted black, which its glass shows as nothing,
// under its XAML too. Explorer paints it white below its top 2 rows while
// Windows hides the XAML (as the taskbar hides itself), and that white stays
// under the XAML once it's back: it showed wherever the taskbar is see-through
// (see TaskbarSeeThrough), a band as wide as the screen with the dock's room
// open.
void PaintTaskbarClear(HWND hWnd) {
    RECT client;
    // (Not clipped by its child windows, unlike its own painting: the XAML's
    // window covers it all.)
    const HDC dc =
        GetClientRect(hWnd, &client) ? GetDCEx(hWnd, nullptr, DCX_CACHE)
                                     : nullptr;
    if (!dc) {
        return;
    }
    FillRect(dc, &client, (HBRUSH)GetStockObject(BLACK_BRUSH));
    ReleaseDC(hWnd, dc);
}

// Marks the taskbar whose hide timer is being handled for as long as it lives
// (see g_hideTimerTaskbar). Taskbar thread only.
class HideTimerScope {
   public:
    HideTimerScope(HWND taskbar, bool active) : m_active(active) {
        if (active) {
            m_previous = g_hideTimerTaskbar;
            g_hideTimerTaskbar = taskbar;
        }
    }
    ~HideTimerScope() {
        if (m_active) {
            g_hideTimerTaskbar = m_previous;
        }
    }
    HideTimerScope(const HideTimerScope&) = delete;
    HideTimerScope& operator=(const HideTimerScope&) = delete;

   private:
    bool m_active;
    HWND m_previous = nullptr;
};

// Also swallows the "show" timer while a full-screen app is in front, so the
// mouse at the bottom edge doesn't bring the taskbar up. Other ways of showing
// it, like the Windows key, aren't affected.
LRESULT CALLBACK TaskbarSubclassProc(HWND hWnd,
                                     UINT uMsg,
                                     WPARAM wParam,
                                     LPARAM lParam,
                                     DWORD_PTR) {
    // What the taskbar asks while it handles its hide timer is about it (see
    // CTaskListWnd_PermitAutoHide_Hook).
    HideTimerScope hideTimerScope(hWnd,
                                  uMsg == WM_TIMER && wParam == kHideTimerId);
    const bool displayChanged =
        DisplayChangedMessage() && uMsg == DisplayChangedMessage();
    // (Windows' transparency effects or its light or dark mode switched: the
    // dock's glass and colors follow.)
    // (Its own hiding switched too: the dock's room follows, see
    // GrownTaskbar.)
    const bool colorsChanged =
        uMsg == WM_SETTINGCHANGE && lParam && IsDock() &&
        (wcscmp((PCWSTR)lParam, L"ImmersiveColorSet") == 0 ||
         wcscmp((PCWSTR)lParam, L"TraySettings") == 0);
    if ((uMsg == WM_DISPLAYCHANGE || displayChanged || colorsChanged) &&
        !g_unloading) {
        if (hWnd == FindCurrentProcessTaskbarWnd()) {
            SetTimer(hWnd, kDisplayRestyleTimerId, 200, nullptr);
        }
    }
    // (The mod's own: not for explorer.)
    if (displayChanged) {
        return 0;
    }
    // See-through, its own window stays black (see PaintTaskbarClear): instead
    // of Explorer's paint, and again once it moved or its cut changed (what
    // was there before shows where the cut opens). (Also while unloading:
    // the background comes back after.)
    if (TaskbarSeeThrough()) {
        if (uMsg == WM_ERASEBKGND) {
            return 1;
        }
        if (uMsg == WM_PAINT) {
            PAINTSTRUCT ps;
            if (BeginPaint(hWnd, &ps)) {
                EndPaint(hWnd, &ps);
            }
            PaintTaskbarClear(hWnd);
            return 0;
        }
        // (Not with each frame of the slide hiding it, see SlideTo.)
        if (uMsg == WM_WINDOWPOSCHANGED &&
            !(hWnd == g_slidingTaskbar && g_slidingHides)) {
            PaintTaskbarClear(hWnd);
        }
    }
    if (uMsg == WM_TIMER && wParam == kDisplayRestyleTimerId) {
        KillTimer(hWnd, kDisplayRestyleTimerId);
        if (!g_unloading) {
            Safely(L"Restyling taskbars after a display change", [] {
                ApplySettingsFromTaskbarThread();
                SubclassTaskbars();
            });
        }
        return 0;
    }
    if (uMsg == WM_DPICHANGED) {
        DockScope scope(hWnd);
        if (hWnd == g_dockWnd) {
            g_dockScaleChangedAt = NowSeconds();
            g_dockScaleSettled = false;
            g_dockScaleMoved = false;
            // (Not as it turns to another orientation, see below.)
            const auto* suggested = (const RECT*)lParam;
            RECT now;
            const bool turning =
                suggested && GetWindowRect(hWnd, &now) &&
                (suggested->right - suggested->left <
                 suggested->bottom - suggested->top) !=
                    (now.right - now.left < now.bottom - now.top);
            if (!turning) {
                Safely(L"Pausing the taskbar's animator",
                       [] { PauseRepeaterAnimations(); });
            }
            StartRendering();
            if (!turning &&
                !SetTimer(hWnd, kAnimatorTimerId, kAnimatorPauseMs, nullptr)) {
                Safely(L"Resuming the taskbar's animator",
                       [] { ResumeRepeaterAnimations(); });
            }
        }
    }
    // Moved to another edge (in Settings) while its animator is out: put
    // back first, or explorer lays the taskbar out there without it and
    // crashes.
    if (uMsg == WM_WINDOWPOSCHANGING && lParam && !g_unloading &&
        (((const WINDOWPOS*)lParam)->flags & (SWP_NOMOVE | SWP_NOSIZE)) !=
            (SWP_NOMOVE | SWP_NOSIZE)) {
        const auto* pos = (const WINDOWPOS*)lParam;
        DockScope scope(hWnd);
        RECT now;
        if (hWnd == g_dockWnd && g_animatorPaused &&
            GetWindowRect(hWnd, &now)) {
            RECT next = now;
            if (!(pos->flags & SWP_NOMOVE)) {
                OffsetRect(&next, pos->x - now.left, pos->y - now.top);
            }
            if (!(pos->flags & SWP_NOSIZE)) {
                next.right = next.left + pos->cx;
                next.bottom = next.top + pos->cy;
            }
            // (Hidden too: on its own monitor's halves.)
            MONITORINFO info{sizeof(info)};
            if (GetMonitorInfo(TaskbarMonitor(hWnd), &info) &&
                RectSide(next, info.rcMonitor) !=
                    RectSide(now, info.rcMonitor)) {
                KillTimer(hWnd, kAnimatorTimerId);
                Safely(L"Resuming the taskbar's animator",
                       [] { ResumeRepeaterAnimations(); });
            }
        }
    }
    if (uMsg == WM_TIMER && wParam == kAnimatorTimerId) {
        KillTimer(hWnd, kAnimatorTimerId);
        DockScope scope(hWnd);
        if (hWnd == g_dockWnd) {
            Safely(L"Resuming the taskbar's animator",
                   [] { ResumeRepeaterAnimations(); });
        }
        return 0;
    }
    // Windows sometimes takes a window for a full-screen app when it isn't
    // (one it once saw covering its monitor keeps that mark until it closes)
    // and keeps the taskbar under it, even while it's shown: its own handler
    // turns a request to be on top into one to go under. Kept on top while
    // it's shown (or asked to be) and no app on its monitor is in full
    // screen (see IsFullscreenAppOn). Only in the modes where the
    // mod shows and hides it (the unchanged taskbar is left as it is).
    if (uMsg == WM_WINDOWPOSCHANGING && lParam && !g_unloading &&
        SlidesItself()) {
        auto* pos = (WINDOWPOS*)lParam;
        const bool askedTop = !(pos->flags & SWP_NOZORDER) &&
                              pos->hwndInsertAfter == HWND_TOPMOST;
        const LRESULT result = DefSubclassProc(hWnd, uMsg, wParam, lParam);
        // The dock's room above the taskbar (see GrownTaskbar), once the
        // taskbar placed itself.
        if (IsDock()) {
            GrowTaskbarWindow(hWnd, pos);
        }
        bool goesUnder = askedTop;
        if (!(pos->flags & SWP_NOZORDER)) {
            const HWND after = pos->hwndInsertAfter;
            goesUnder = after == HWND_NOTOPMOST || after == HWND_BOTTOM ||
                        (after != HWND_TOPMOST && after != HWND_TOP &&
                         !(GetWindowLongPtr(after, GWL_EXSTYLE) &
                           WS_EX_TOPMOST));
        }
        MONITORINFO info{sizeof(info)};
        if (goesUnder &&
            (askedTop || (GetMonitorInfo(TaskbarMonitor(hWnd), &info) &&
                          !IsTaskbarHidden(hWnd, info.rcMonitor))) &&
            !IsFullscreenAppOnMonitor(hWnd)) {
            pos->hwndInsertAfter = HWND_TOPMOST;
            pos->flags &= ~SWP_NOZORDER;
        }
        return result;
    }
    // Brought up while under a window (Windows shows it where it was, behind
    // the one in front): on top as it shows, kept there by the above.
    if (uMsg == WM_WINDOWPOSCHANGED && !g_unloading && SlidesItself() &&
        !(GetWindowLongPtr(hWnd, GWL_EXSTYLE) & WS_EX_TOPMOST)) {
        static bool raising;
        MONITORINFO info{sizeof(info)};
        if (!raising && GetMonitorInfo(TaskbarMonitor(hWnd), &info) &&
            !IsTaskbarHidden(hWnd, info.rcMonitor) &&
            !IsFullscreenAppOnMonitor(hWnd)) {
            raising = true;
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            raising = false;
        }
    }
    // Moved to another edge of the screen (or back to the bottom): before
    // the dock's own handling below, which ends here.
    // (Not during the mod's own slide: it can't change the edge.)
    if (uMsg == WM_WINDOWPOSCHANGED && lParam && !g_unloading &&
        hWnd != g_slidingTaskbar &&
        (((const WINDOWPOS*)lParam)->flags & (SWP_NOMOVE | SWP_NOSIZE)) !=
            (SWP_NOMOVE | SWP_NOSIZE) &&
        IsTaskbarAtBottom() != g_taskbarAtBottom) {
        WatchTaskbarPlace();
    }
    // The dock: never shown past its monitor, nor taking the mouse in its
    // room at rest (see ClipDockWindow), whoever moved it.
    if (uMsg == WM_WINDOWPOSCHANGED && IsDock() && !g_unloading) {
        const LRESULT result = DefSubclassProc(hWnd, uMsg, wParam, lParam);
        // (Not during the mod's own slide, which cuts it before and after
        // each move itself, see SlideTo.)
        if (hWnd != g_slidingTaskbar) {
            ClipDockWindow(hWnd);
        }
        return result;
    }
    // An app closed and the taskbar got the focus back (see HandFocusBack):
    // once the focus moved, it tries to hide again right after.
    if (uMsg == WM_TIMER && wParam == kHideTimerId && HandFocusBack(hWnd)) {
        const LRESULT result = DefSubclassProc(hWnd, uMsg, wParam, lParam);
        ScheduleTaskbarHide(hWnd, 50);
        return result;
    }
    // Up on the desktop (hiding.hideWhen): its hide timer stopped while
    // nothing is in its way (or it fires again and again), and started again
    // once a window is (see CheckTaskbarWay).
    if (uMsg == WM_TIMER && wParam == kHideTimerId && TaskbarWayWatched() &&
        !WindowInTaskbarWay(hWnd)) {
        KillTimer(hWnd, kHideTimerId);
        return 0;
    }
    if (uMsg == WM_TIMER && wParam == kTaskbarWayTimerId) {
        CheckTaskbarWay(hWnd);
        return 0;
    }
    // Shown at once by Windows and still up a moment later: the dock shows
    // now (see kQuietShowDelayMs).
    if (uMsg == WM_TIMER && wParam == kQuietShowTimerId) {
        KillTimer(hWnd, kQuietShowTimerId);
        if (hWnd == g_quietShownWnd) {
            g_quietShownWnd = nullptr;
        }
        // (Also one that another monitor's show took the place of while it
        // waited: it's cut to nothing until here.)
        ClipSlideStep(hWnd, nullptr);
        return 0;
    }
    if (uMsg == WM_TIMER && wParam == kUnhideTimerId && SlidesItself() &&
        g_settings.fullscreenGuard && IsFullscreenAppOnMonitor(hWnd)) {
        static ULONGLONG lastLogged;
        if (GetTickCount64() - lastLogged > 5000) {
            lastLogged = GetTickCount64();
            IslandLog(L"Full-screen app in front, not showing the taskbar");
        }
        // (The taskbar's own handler is what stops it: stopped here, or it
        // fires every few milliseconds for as long as the app stays.)
        KillTimer(hWnd, kUnhideTimerId);
        return 0;
    }
    // The mouse is where it brings the taskbar up, from the edge's thread
    // (hidden still: it may have come up meanwhile).
    if (uMsg == g_edgeUnhideMessage && g_edgeUnhideMessage) {
        MONITORINFO info{sizeof(info)};
        if (!g_unloading && GetMonitorInfo(TaskbarMonitor(hWnd), &info) &&
            IsTaskbarHidden(hWnd, info.rcMonitor)) {
            UnhideTaskbar(hWnd);
        }
        return 0;
    }
    // Big icons read (see BigIconJob): the dock drawn again with them.
    // (wParam 1: asked for, their windows looked for first.)
    if (uMsg == g_bigIconsReadMessage && g_bigIconsReadMessage) {
        if (!g_unloading) {
            if (wParam == 1) {
                FindBigIconWindows(true);
            } else {
                StartRendering();
            }
        }
        return 0;
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

// The shell hook message, and its code for a flashing window (lParam is the
// window).
UINT g_shellHookMessage;
constexpr WPARAM kShellHookFlash = 0x8006;  // HSHELL_FLASH

void OnAppFlashed(HWND hWnd);

LRESULT CALLBACK TaskbandSubclassProc(HWND hWnd,
                                      UINT uMsg,
                                      WPARAM wParam,
                                      LPARAM lParam,
                                      DWORD_PTR) {
    // Recorded before the taskbar handles it, since that's when it decides to
    // show itself (see TrayUI_SlideWindow_Hook).
    if (g_shellHookMessage && uMsg == g_shellHookMessage &&
        wParam == kShellHookFlash) {
        g_lastFlashTime = NowSeconds();
        OnAppFlashed((HWND)lParam);
    }
    // An app's window closed: if that leaves the focus on the shown taskbar,
    // its hide timer hands it on (see HandFocusBack), after any wait for an
    // app opening.
    if (g_shellHookMessage && uMsg == g_shellHookMessage &&
        wParam == HSHELL_WINDOWDESTROYED && SlidesItself() && g_trayShown) {
        g_appClosedAt = NowSeconds();
        if (HWND taskbar = GetAncestor(hWnd, GA_ROOT)) {
            const double keep =
                taskbar == g_keepShownWnd ? g_keepShownUntil - NowSeconds()
                                          : 0.0;
            ScheduleTaskbarHide(
                taskbar, std::max(300u, (UINT)(std::max(keep, 0.0) * 1000) +
                                            150));
        }
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

// Subclassed from several threads (the engine's, the late start, the taskbar's
// for a new secondary taskbar): the lists are only touched under this lock,
// never held while subclassing (that waits for the taskbar's thread).
SRWLOCK g_subclassedLock = SRWLOCK_INIT;
std::vector<HWND> g_subclassedTaskbars;
std::vector<HWND> g_subclassedTaskbands;

bool AnyTaskbarSubclassed() {
    AcquireSRWLockShared(&g_subclassedLock);
    const bool any = !g_subclassedTaskbars.empty();
    ReleaseSRWLockShared(&g_subclassedLock);
    return any;
}

bool IsListed(const std::vector<HWND>& list, HWND hWnd) {
    AcquireSRWLockShared(&g_subclassedLock);
    const bool listed = std::find(list.begin(), list.end(), hWnd) != list.end();
    ReleaseSRWLockShared(&g_subclassedLock);
    return listed;
}

// Every subclassed taskbar told to look at its way (see CheckTaskbarWay).
void PostTaskbarWayChecks() {
    AcquireSRWLockShared(&g_subclassedLock);
    const std::vector<HWND> taskbars = g_subclassedTaskbars;
    ReleaseSRWLockShared(&g_subclassedLock);
    for (HWND taskbar : taskbars) {
        PostMessage(taskbar, WM_TIMER, kTaskbarWayTimerId, 0);
    }
}

// Windows' events about the apps' windows (see kWindowEventRanges), on a
// thread of its own (not the taskbars': moving windows send many), while
// the taskbars' way is watched: the taskbars told once for a burst of them,
// kTaskbarWayBatchMs after the first.
// (Started on the taskbars' thread, also stopped by the unloading one: the
// lock only guards the handles, the thread is waited for outside it.)
HANDLE g_taskbarWayThread;
DWORD g_taskbarWayThreadId;
SRWLOCK g_taskbarWayLock = SRWLOCK_INIT;
// (Its thread's only.)
UINT_PTR g_taskbarWayBatch;

void CALLBACK TaskbarWayEventProc(HWINEVENTHOOK,
                                  DWORD,
                                  HWND hWnd,
                                  LONG idObject,
                                  LONG idChild,
                                  DWORD,
                                  DWORD) {
    if (!g_taskbarWayBatch && IsWindowEventForApp(hWnd, idObject, idChild)) {
        g_taskbarWayBatch = SetTimer(nullptr, 0, kTaskbarWayBatchMs, nullptr);
    }
}

DWORD WINAPI TaskbarWayThreadProc(LPVOID parameter) {
    // Create the message queue before the creator continues.
    MSG msg;
    PeekMessage(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    SetEvent((HANDLE)parameter);

    HWINEVENTHOOK hooks[std::size(kWindowEventRanges)] = {};
    for (size_t i = 0; i < std::size(kWindowEventRanges); i++) {
        hooks[i] = SetWinEventHook(
            kWindowEventRanges[i].first, kWindowEventRanges[i].second, nullptr,
            TaskbarWayEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    }
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        if (msg.message == WM_TIMER && !msg.hwnd && g_taskbarWayBatch &&
            msg.wParam == g_taskbarWayBatch) {
            KillTimer(nullptr, g_taskbarWayBatch);
            g_taskbarWayBatch = 0;
            PostTaskbarWayChecks();
            continue;
        }
        DispatchMessage(&msg);
    }
    if (g_taskbarWayBatch) {
        KillTimer(nullptr, g_taskbarWayBatch);
        g_taskbarWayBatch = 0;
    }
    for (HWINEVENTHOOK hook : hooks) {
        if (hook) {
            UnhookWinEvent(hook);
        }
    }
    return 0;
}

void StartTaskbarWayThread() {
    AcquireSRWLockExclusive(&g_taskbarWayLock);
    HANDLE started = g_taskbarWayThread || g_unloading
                         ? nullptr
                         : CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (started) {
        g_taskbarWayThread = CreateThread(nullptr, 0, TaskbarWayThreadProc,
                                          started, 0, &g_taskbarWayThreadId);
        if (g_taskbarWayThread) {
            // (It takes no lock.)
            WaitForSingleObject(started, INFINITE);
        } else {
            g_taskbarWayThreadId = 0;
        }
        CloseHandle(started);
    }
    ReleaseSRWLockExclusive(&g_taskbarWayLock);
}

void StopTaskbarWayThread() {
    AcquireSRWLockExclusive(&g_taskbarWayLock);
    const HANDLE thread = g_taskbarWayThread;
    const DWORD threadId = g_taskbarWayThreadId;
    g_taskbarWayThread = nullptr;
    g_taskbarWayThreadId = 0;
    ReleaseSRWLockExclusive(&g_taskbarWayLock);
    if (thread) {
        PostThreadMessage(threadId, WM_QUIT, 0, 0);
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
    }
}

// The taskbars' way watched or not with the settings (on the taskbars'
// thread): each one looks once now; no longer watched, their own hide
// timers start again (stopped while nothing was in the way), so they hide
// with the mouse away as before.
void WatchTaskbarWay() {
    if (!TaskbarWayWatched()) {
        AcquireSRWLockShared(&g_taskbarWayLock);
        const bool watched = g_taskbarWayThread != nullptr;
        ReleaseSRWLockShared(&g_taskbarWayLock);
        if (!watched) {
            return;
        }
        StopTaskbarWayThread();
        AcquireSRWLockShared(&g_subclassedLock);
        const std::vector<HWND> taskbars = g_subclassedTaskbars;
        ReleaseSRWLockShared(&g_subclassedLock);
        for (HWND taskbar : taskbars) {
            ScheduleTaskbarHide(taskbar, kTaskbarWayHideMs);
        }
        return;
    }
    StartTaskbarWayThread();
    PostTaskbarWayChecks();
}

void AddToList(std::vector<HWND>& list, HWND hWnd) {
    AcquireSRWLockExclusive(&g_subclassedLock);
    if (std::find(list.begin(), list.end(), hWnd) == list.end()) {
        list.push_back(hWnd);
    }
    ReleaseSRWLockExclusive(&g_subclassedLock);
}

BOOL CALLBACK SubclassTaskbarProc(HWND hWnd, LPARAM) {
    DWORD processId = 0;
    WCHAR className[32] = L"";
    if (GetWindowThreadProcessId(hWnd, &processId) &&
        processId == GetCurrentProcessId() &&
        GetClassName(hWnd, className, ARRAYSIZE(className)) &&
        (_wcsicmp(className, L"Shell_TrayWnd") == 0 ||
         _wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0) &&
        !IsListed(g_subclassedTaskbars, hWnd)) {
        if (WindhawkUtils::SetWindowSubclassFromAnyThread(
                hWnd, TaskbarSubclassProc, 0)) {
            AddToList(g_subclassedTaskbars, hWnd);
        }
    }
    // (What Explorer painted on it before goes, see PaintTaskbarClear: also
    // once the settings make it see-through.)
    if (TaskbarSeeThrough() && IsListed(g_subclassedTaskbars, hWnd)) {
        InvalidateRect(hWnd, nullptr, FALSE);
    }
    // The main taskbar's buttons live in its taskband window (made a
    // moment after the taskbar, when Explorer starts).
    if (processId == GetCurrentProcessId() &&
        _wcsicmp(className, L"Shell_TrayWnd") == 0) {
        HWND taskband = (HWND)GetProp(hWnd, L"TaskbandHWND");
        if (taskband && !IsListed(g_subclassedTaskbands, taskband) &&
            WindhawkUtils::SetWindowSubclassFromAnyThread(
                taskband, TaskbandSubclassProc, 0)) {
            AddToList(g_subclassedTaskbands, taskband);
        }
    }
    return TRUE;
}

void SubclassTaskbars() {
    EnumWindows(
        SubclassTaskbarProc,
        0);
}

void UnsubclassTaskbars() {
    AcquireSRWLockExclusive(&g_subclassedLock);
    std::vector<HWND> taskbars = std::move(g_subclassedTaskbars);
    std::vector<HWND> taskbands = std::move(g_subclassedTaskbands);
    g_subclassedTaskbars.clear();
    g_subclassedTaskbands.clear();
    ReleaseSRWLockExclusive(&g_subclassedLock);
    for (HWND hWnd : taskbars) {
        if (IsWindow(hWnd)) {
            WindhawkUtils::RemoveWindowSubclassFromAnyThread(
                hWnd, TaskbarSubclassProc);
            // (Painted by Windows again: in the see-through modes the
            // subclass painted it clear, see PaintTaskbarClear.)
            RedrawWindow(hWnd, nullptr, nullptr,
                         RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
        }
    }

    for (HWND hWnd : taskbands) {
        if (IsWindow(hWnd)) {
            WindhawkUtils::RemoveWindowSubclassFromAnyThread(
                hWnd, TaskbandSubclassProc);
        }
    }
}

// Loaded with Explorer (or while it restarts), the taskbar isn't ready yet:
// tries again every second, for up to two minutes, until it's styled, then
// asks the apps for their tray icons again (they sent them before the mod
// could see them).
HANDLE g_lateStartThread;
HANDLE g_lateStartStop;

// The parts that need the taskbar's process (see OwnsTaskbar): started with
// the mod, or once the taskbar is ready.
void StartAttentionThread();
void StartEdgeWatch();
void StartTaskbarParts() {
    StartAttentionThread();
    StartEdgeWatch();
}

void UpdateAutoHide();

DWORD WINAPI LateStartThreadProc(LPVOID) {
    for (int tries = 0; tries < 120; tries++) {
        if (WaitForSingleObject(g_lateStartStop, 1000) != WAIT_TIMEOUT) {
            return 0;
        }
        if (!FindCurrentProcessTaskbarWnd()) {
            continue;
        }
        SubclassTaskbars();
        if (!g_mainTaskbarStyled) {
            ApplySettings();
        }
        if (g_mainTaskbarStyled) {
            IslandLog(L"Taskbar ready after %d s", tries + 1);
            UpdateAutoHide();
            RefreshDockRoom();
            StartTaskbarParts();
            return 0;
        }
    }
    IslandLog(L"Taskbar still not ready, giving up");
    return 0;
}

// Started when the taskbar wasn't ready.
void StartLateStart() {
    if (g_lateStartThread || g_mainTaskbarStyled) {
        return;
    }
    g_lateStartStop = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (!g_lateStartStop) {
        return;
    }
    g_lateStartThread =
        CreateThread(nullptr, 0, LateStartThreadProc, nullptr, 0, nullptr);
    if (!g_lateStartThread) {
        CloseHandle(g_lateStartStop);
        g_lateStartStop = nullptr;
    }
}

void StopLateStart() {
    if (g_lateStartThread) {
        SetEvent(g_lateStartStop);
        WaitForSingleObject(g_lateStartThread, INFINITE);
        CloseHandle(g_lateStartThread);
        g_lateStartThread = nullptr;
    }
    if (g_lateStartStop) {
        CloseHandle(g_lateStartStop);
        g_lateStartStop = nullptr;
    }
}

// Whether an app's jump list is in front, opened from the dock: Windows
// shows them from its Start menu's process (or the shell experience host on
// older builds), after a right-click on the icon.
constexpr UINT kJumpListRetryMs = 300;

bool JumpListOpen(HWND dock) {
    // (Only the dock whose icon was right-clicked: the other monitors' hide.)
    if (dock != g_dockRightPressedWnd ||
        NowSeconds() - g_dockRightPressedAt > 60) {
        return false;
    }
    DWORD processId = 0;
    HWND foreground = GetForegroundWindow();
    if (!foreground || !GetWindowThreadProcessId(foreground, &processId)) {
        return false;
    }
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (!process) {
        return false;
    }
    WCHAR path[MAX_PATH];
    DWORD length = ARRAYSIZE(path);
    const bool named = QueryFullProcessImageName(process, 0, path, &length);
    CloseHandle(process);
    const PCWSTR name = named ? PathFindFileName(path) : L"";
    return _wcsicmp(name, L"StartMenuExperienceHost.exe") == 0 ||
           _wcsicmp(name, L"ShellExperienceHost.exe") == 0;
}

// Windows places an app's jump list where the icon would be in its own
// (left-aligned) taskbar, not under the dock's centered icon: moved, for a
// moment after a right-click on the dock, so it's centered above the icon.
constexpr double kJumpListMoveSeconds = 2.5;
HANDLE g_jumpListMoveThread;
DWORD g_jumpListMoveThreadId;

bool IsJumpListWindow(HWND hWnd) {
    WCHAR className[64];
    if (!GetClassName(hWnd, className, ARRAYSIZE(className)) ||
        wcscmp(className, L"Windows.UI.Core.CoreWindow") != 0) {
        return false;
    }
    DWORD processId = 0;
    if (!GetWindowThreadProcessId(hWnd, &processId)) {
        return false;
    }
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (!process) {
        return false;
    }
    WCHAR path[MAX_PATH];
    DWORD length = ARRAYSIZE(path);
    const bool named = QueryFullProcessImageName(process, 0, path, &length);
    CloseHandle(process);
    const PCWSTR name = named ? PathFindFileName(path) : L"";
    return _wcsicmp(name, L"StartMenuExperienceHost.exe") == 0 ||
           _wcsicmp(name, L"ShellExperienceHost.exe") == 0;
}

void MoveJumpListAboveIcon(HWND hWnd) {
    if (g_unloading || !g_dockRightPressedWnd ||
        NowSeconds() - g_dockRightPressedAt > kJumpListMoveSeconds ||
        !IsWindowVisible(hWnd) || !IsJumpListWindow(hWnd)) {
        return;
    }
    RECT rect{};
    if (!GetWindowRect(hWnd, &rect) || rect.right <= rect.left) {
        return;
    }
    const LONG x = g_dockRightPressedX;
    MONITORINFO monitor{sizeof(monitor)};
    if (!GetMonitorInfo(MonitorFromWindow(g_dockRightPressedWnd,
                                          MONITOR_DEFAULTTONEAREST),
                        &monitor)) {
        return;
    }
    const LONG width = rect.right - rect.left;
    LONG left = x - width / 2;
    left = std::min(left, monitor.rcMonitor.right - width);
    left = std::max(left, monitor.rcMonitor.left);
    if (std::abs(left - rect.left) <= 1) {
        return;
    }
    SetWindowPos(hWnd, nullptr, left, rect.top, 0, 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE |
                     SWP_NOOWNERZORDER | SWP_ASYNCWINDOWPOS);
}

void CALLBACK JumpListEventProc(HWINEVENTHOOK,
                                DWORD,
                                HWND hWnd,
                                LONG idObject,
                                LONG idChild,
                                DWORD,
                                DWORD) {
    if (hWnd && idObject == OBJID_WINDOW && idChild == CHILDID_SELF) {
        MoveJumpListAboveIcon(hWnd);
    }
}

DWORD WINAPI JumpListMoveThreadProc(LPVOID) {
    MSG msg;
    PeekMessage(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    const HWINEVENTHOOK hooks[] = {
        SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND,
                        nullptr, JumpListEventProc, 0, 0,
                        WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS),
        SetWinEventHook(EVENT_OBJECT_SHOW, EVENT_OBJECT_SHOW, nullptr,
                        JumpListEventProc, 0, 0,
                        WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS),
        SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE,
                        EVENT_OBJECT_LOCATIONCHANGE, nullptr,
                        JumpListEventProc, 0, 0,
                        WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS),
    };
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        DispatchMessage(&msg);
    }
    for (HWINEVENTHOOK hook : hooks) {
        if (hook) {
            UnhookWinEvent(hook);
        }
    }
    return 0;
}

void StartJumpListMove() {
    if (!g_jumpListMoveThread) {
        g_jumpListMoveThread =
            CreateThread(nullptr, 0, JumpListMoveThreadProc, nullptr, 0,
                         &g_jumpListMoveThreadId);
    }
}

void StopJumpListMove() {
    if (g_jumpListMoveThread) {
        PostThreadMessage(g_jumpListMoveThreadId, WM_QUIT, 0, 0);
        if (WaitForSingleObject(g_jumpListMoveThread, 2000) == WAIT_TIMEOUT) {
            // (Its queue may not exist yet: asked again.)
            PostThreadMessage(g_jumpListMoveThreadId, WM_QUIT, 0, 0);
            WaitForSingleObject(g_jumpListMoveThread, 2000);
        }
        CloseHandle(g_jumpListMoveThread);
        g_jumpListMoveThread = nullptr;
        g_jumpListMoveThreadId = 0;
    }
}

// Whether the taskbar may hide now. A button asking for attention keeps it
// up; unless the whole dock is wanted for that, it hides as usual. An app
// clicked in the dock that's still opening keeps it up too.
using CTaskListWnd_PermitAutoHide_t = BOOL(WINAPI*)(void* pThis);
CTaskListWnd_PermitAutoHide_t CTaskListWnd_PermitAutoHide_Original;
BOOL WINAPI CTaskListWnd_PermitAutoHide_Hook(void* pThis) {
    if (!SlidesItself()) {
        return CTaskListWnd_PermitAutoHide_Original(pThis);
    }
    // Each taskbar answers for itself: the one whose hide timer asked (the
    // main one when something else did), with its own dock's state, so the
    // mouse on one monitor's dock doesn't keep the other monitor's up.
    const HWND asking = g_hideTimerTaskbar ? g_hideTimerTaskbar : g_dockWnd;
    // (A taskbar the mod hasn't styled yet has no state of its own: the main
    // one's would answer for it, so Windows' own answer stands.)
    if (asking != g_dockWnd && !FindOtherDock(asking)) {
        return CTaskListWnd_PermitAutoHide_Original(pThis);
    }
    DockScope scope(asking);
    const HWND dock = g_dockWnd;
    // Kept shown on its monitor with its arrow (see ToggleDockPin).
    if (!g_unloading && IsDock() && !DockHidesOn(dock)) {
        return FALSE;
    }
    // An app clicked in the dock is opening (see KeepDockShown), the mouse
    // is on the dock (its magnified icons may be above the taskbar's own
    // height), or an app's jump list is open (its icon right-clicked): tried
    // again a moment later, as Windows' own taskbar stays up for it.
    if (!g_unloading && IsDock() && JumpListOpen(dock)) {
        ScheduleTaskbarHide(dock, kJumpListRetryMs);
        return FALSE;
    }
    // (The mouse is off its window already: under the thumbnails' window, as
    // big as the monitor, the taskbar stops drawing the frames that notice
    // it, see OnRenderingUnsafe.)
    if (g_dockHovered) {
        RECT window{};
        POINT pt{};
        if (GetWindowRect(g_dockHovered, &window) && GetCursorPos(&pt) &&
            !PtInRect(&window, pt)) {
            g_dockHovered = nullptr;
        }
    }
    if (!g_unloading && IsKeptShown(dock)) {
        // Windows doesn't ask again: tried right after the wait.
        if (!UserIsReachingForTaskbar(dock)) {
            ScheduleTaskbarHide(
                dock,
                (UINT)std::max(0.0, (g_keepShownUntil - NowSeconds()) * 1000) +
                    100);
        }
        return FALSE;
    }
    if (!g_unloading && IsDock() && g_dockHovered == dock) {
        return FALSE;
    }
    if (!g_unloading && IsDock() &&
        g_settings.attentionMode != AttentionMode::Dock &&
        std::any_of(g_dockIcons.begin(), g_dockIcons.end(),
                    [](const DockIcon& icon) { return icon.attention; })) {
        return TRUE;
    }
    // On the transparent taskbar, Windows would keep it up as long as a
    // button asks for attention (until that app is looked at): it hides as
    // usual, unless the user is on it or in something of the taskbar's (a
    // jump list, a thumbnail).
    if (!g_unloading && !IsDock() && g_dockWnd &&
        std::any_of(g_dockIcons.begin(), g_dockIcons.end(),
                    [](const DockIcon& icon) { return icon.attention; }) &&
        !UserIsReachingForTaskbar(g_dockWnd)) {
        POINT pt;
        HWND under = GetCursorPos(&pt) ? WindowFromPoint(pt) : nullptr;
        DWORD underProcess = 0;
        DWORD foregroundProcess = 0;
        if (under) {
            GetWindowThreadProcessId(under, &underProcess);
        }
        if (HWND foreground = GetForegroundWindow()) {
            GetWindowThreadProcessId(foreground, &foregroundProcess);
        }
        if (underProcess != GetCurrentProcessId() &&
            foregroundProcess != GetCurrentProcessId()) {
            return TRUE;
        }
    }
    return CTaskListWnd_PermitAutoHide_Original(pThis);
}

////////////////////////////////////////////////////////////////////////////////
// Bottom edge.
//
// While hidden, the taskbar keeps a thin strip on screen to notice the mouse.
// With the dock style that strip is transparent, and transparent parts don't
// always receive the mouse, so the bottom edge is watched here as well.
// Only while the mod slides the taskbar itself, and only often when the mouse
// is near the bottom (10 times a second otherwise).

HANDLE g_edgeThread;
HANDLE g_edgeStopEvent;

constexpr DWORD kEdgePollMs = 15;
// Far from the bottom edge, the mouse is looked at less often: it takes more
// than this long to get there.
constexpr DWORD kEdgeIdlePollMs = 100;
constexpr int kEdgeNearPixels = 300;
// While the mouse stays at the edge, the request is repeated in case it got
// lost.
constexpr DWORD kEdgeRetryMs = 150;

// Looking for the taskbar of a monitor.
struct TaskbarSearch {
    HMONITOR monitor;
    HWND result;
};

BOOL CALLBACK FindTaskbarForMonitorProc(HWND hWnd, LPARAM lParam) {
    auto* context = reinterpret_cast<TaskbarSearch*>(lParam);
    DWORD processId = 0;
    WCHAR className[32];
    if (GetWindowThreadProcessId(hWnd, &processId) &&
        processId == GetCurrentProcessId() &&
        GetClassName(hWnd, className, ARRAYSIZE(className)) &&
        (_wcsicmp(className, L"Shell_TrayWnd") == 0 ||
         _wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0) &&
        TaskbarMonitor(hWnd) == context->monitor) {
        context->result = hWnd;
        return FALSE;
    }
    return TRUE;
}

HWND FindTaskbarForMonitor(HMONITOR monitor) {
    TaskbarSearch context{monitor, nullptr};
    EnumWindows(
        FindTaskbarForMonitorProc,
        reinterpret_cast<LPARAM>(&context));
    return context.result;
}

// A taskbar showing itself for an app asking for attention: it slides up on
// its own (before TrayUI::SlideWindow), so it's stopped here, or it would
// come up and go back down with every flash (see KeepsDownForAttention).
using CTaskBand_UnhideTray_t = HRESULT(WINAPI*)(void* pThis);
CTaskBand_UnhideTray_t CTaskBand_UnhideTray_Original;
HRESULT WINAPI CTaskBand_UnhideTray_Hook(void* pThis) {
    if (HWND taskbar = FindCurrentProcessTaskbarWnd();
        taskbar && KeepsDownForAttention(taskbar)) {
        LogKeptDown();
        return S_OK;
    }
    return CTaskBand_UnhideTray_Original(pThis);
}

// The same for the other monitors' taskbars (the one where the mouse is,
// for whether the user is reaching for it).
CTaskBand_UnhideTray_t CSecondaryTaskBand_UnhideTray_Original;
HRESULT WINAPI CSecondaryTaskBand_UnhideTray_Hook(void* pThis) {
    POINT pt{};
    GetCursorPos(&pt);
    HWND taskbar =
        FindTaskbarForMonitor(MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST));
    if (!taskbar) {
        taskbar = FindCurrentProcessTaskbarWnd();
    }
    if (taskbar && KeepsDownForAttention(taskbar)) {
        LogKeptDown();
        return S_OK;
    }
    return CSecondaryTaskBand_UnhideTray_Original(pThis);
}

// Hidden: less than half of the taskbar is on its monitor, or the hidden
// dock's window, higher (see HiddenLift), cut down to its last pixels.
bool IsTaskbarHidden(HWND hTaskbarWnd, const RECT& monitorRect) {
    RECT rect, visible;
    if (!GetWindowRect(hTaskbarWnd, &rect)) {
        return false;
    }
    if (!IntersectRect(&visible, &rect, &monitorRect)) {
        return true;
    }
    if (!EqualRect(&visible, &rect)) {
        RECT cut{};
        if (GetWindowRgnBox(hTaskbarWnd, &cut) == SIMPLEREGION &&
            cut.bottom - cut.top <=
                MulDiv(6, GetDpiForWindow(hTaskbarWnd), 96)) {
            return true;
        }
    }
    return (visible.bottom - visible.top) < (rect.bottom - rect.top) / 2;
}

DWORD WINAPI EdgeThreadProc(LPVOID) {
    ULONGLONG atEdgeSince = 0;
    ULONGLONG lastRequest = 0;
    // Where the mouse was last time (see g_edgeCapture).
    HMONITOR lastMonitor = nullptr;

    DWORD wait = kEdgeIdlePollMs;
    while (WaitForSingleObject(g_edgeStopEvent, wait) == WAIT_TIMEOUT) {
        wait = kEdgeIdlePollMs;
        POINT pt;
        if (!GetCursorPos(&pt)) {
            continue;
        }
        HMONITOR monitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
        MONITORINFO info{sizeof(info)};
        if (!GetMonitorInfo(monitor, &info)) {
            atEdgeSince = 0;
            g_edgeCapture = nullptr;
            continue;
        }
        // Just past the bottom edge of the monitor above, come from it: that
        // edge (see g_edgeCapture).
        HMONITOR above = EdgeCaptureAbove(pt, info.rcMonitor);
        if (above && above != g_edgeCapture && above != lastMonitor) {
            above = nullptr;
        }
        g_edgeCapture = above;
        lastMonitor = monitor;
        if (above) {
            wait = kEdgePollMs;
            monitor = above;
            if (!GetMonitorInfo(monitor, &info)) {
                atEdgeSince = 0;
                continue;
            }
        } else {
            if (pt.y >= info.rcMonitor.bottom - kEdgeNearPixels) {
                wait = kEdgePollMs;
            }
            UINT dpiX = 96;
            UINT dpiY = 96;
            if (FAILED(GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI, &dpiX,
                                        &dpiY))) {
                dpiX = 96;
            }
            if (pt.y < info.rcMonitor.bottom -
                           EdgeStripPixels(pt.x, info.rcMonitor.bottom,
                                           dpiX)) {
                atEdgeSince = 0;
                continue;
            }
            // The transparent taskbar: only under its apps (that monitor's);
            // the dock, under its icons (see ClipDockWindow).
            int appsLeft = 0;
            int appsRight = 0;
            if ((IsTransparentTaskbar() || IsDock()) &&
                GetAppsArea(monitor, &appsLeft, &appsRight) &&
                (pt.x < appsLeft || pt.x >= appsRight)) {
                atEdgeSince = 0;
                continue;
            }
        }

        const ULONGLONG now = GetTickCount64();
        if (!atEdgeSince) {
            atEdgeSince = now;
        }
        if (now - atEdgeSince < (ULONGLONG)g_settings.showDelay ||
            now - lastRequest < kEdgeRetryMs) {
            continue;
        }

        HWND hTaskbarWnd = FindTaskbarForMonitor(monitor);
        if (!hTaskbarWnd || !IsTaskbarHidden(hTaskbarWnd, info.rcMonitor) ||
            (g_settings.fullscreenGuard &&
             IsFullscreenAppOnMonitor(hTaskbarWnd))) {
            continue;
        }

        // The same message the taskbar's own "show" timer sends; asked again
        // (still hidden), as the mod shows it (see g_edgeUnhideMessage).
        if (lastRequest >= atEdgeSince) {
            PostMessage(hTaskbarWnd, g_edgeUnhideMessage, 0, 0);
        } else {
            PostMessage(hTaskbarWnd, WM_TIMER, kUnhideTimerId, 0);
        }
        lastRequest = now;
    }
    return 0;
}

void StartEdgeWatch() {
    // A transparent taskbar, hidden, doesn't get the mouse either.
    if (g_edgeThread || !SlidesItself() || !OwnsTaskbar()) {
        return;
    }
    g_edgeStopEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (!g_edgeStopEvent) {
        return;
    }
    g_edgeThread = CreateThread(nullptr, 0, EdgeThreadProc, nullptr, 0, nullptr);
    if (!g_edgeThread) {
        CloseHandle(g_edgeStopEvent);
        g_edgeStopEvent = nullptr;
    }
}

void StopEdgeWatch() {
    if (g_edgeThread) {
        SetEvent(g_edgeStopEvent);
        WaitForSingleObject(g_edgeThread, INFINITE);
        CloseHandle(g_edgeThread);
        g_edgeThread = nullptr;
    }
    g_edgeCapture = nullptr;
    if (g_edgeStopEvent) {
        CloseHandle(g_edgeStopEvent);
        g_edgeStopEvent = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////
// The attention icon (its own thread).
//
// When an app asks for attention while the dock is hidden, only its icon peeks
// out from the bottom edge, bounces, and goes away again. The dock's buttons
// are off screen then, so the icon is drawn in a small window of its own.

HANDLE g_attentionThread;
DWORD g_attentionThreadId;
std::atomic<bool> g_attentionClicked;

constexpr UINT WM_APP_ATTENTION = WM_APP + 30;  // lParam: the app's window.
constexpr WCHAR kAttentionClassName[] = L"WindhawkMacDockAttentionIcon";

// Sizes in pixels at 100% scaling: the icon, how high it bounces, and how far
// above the bottom edge it rests.
constexpr int kAttentionIconSize = 48;
constexpr int kAttentionBounceHeight = 22;
constexpr int kAttentionRestGap = 10;
// How long it takes to come out and to go back, in seconds.
constexpr double kAttentionRiseTime = 0.28;
constexpr double kAttentionSinkTime = 0.24;
// The same app doesn't bounce again this soon after, in seconds.
constexpr double kAttentionRepeatDelay = 4;

constexpr GUID kFOLDERID_AppsFolder = {
    0x1e87508d,
    0x89c2,
    0x42f0,
    {0x8a, 0x7e, 0x64, 0x5a, 0x0f, 0x50, 0xca, 0x58}};
constexpr GUID kFOLDERID_LocalAppData = {
    0xf1b32785,
    0x6fba,
    0x4fcf,
    {0x9d, 0x55, 0x7b, 0x8e, 0x7f, 0x15, 0x70, 0x91}};
// The shell's handler giving an item's data, for dragging it (BHID_DataObject).
constexpr GUID kBHID_DataObject = {
    0xb8c0bd9f,
    0xed24,
    0x455c,
    {0x83, 0xe6, 0xd5, 0x39, 0x0c, 0x4f, 0xe8, 0xc4}};
// The shell's handler of an item's own objects (BHID_SFUIObject): a folder's
// drop target, the one Explorer uses for files dropped on it.
constexpr GUID kBHID_SFUIObject = {
    0x3981e225,
    0xf559,
    0x11d3,
    {0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5}};
// Windows' picture of the files dragged, kept over a window they're dragged
// over (CLSID_DragDropHelper).
constexpr GUID kCLSID_DragDropHelper = {
    0x4657278a,
    0x411b,
    0x11d2,
    {0x83, 0x9a, 0x00, 0xc0, 0x4f, 0xd9, 0x18, 0xd0}};
constexpr PROPERTYKEY kPKEY_AppUserModel_ID = {
    {0x9f4c2855,
     0x9f79,
     0x4b39,
     {0xa8, 0xd0, 0xe1, 0xd4, 0x2d, 0xe1, 0xd5, 0xf3}},
    5};

// What RunAttentionIcon shows: the app's window (a flashing button), or its
// AppUserModelID (a badge, see OnAppNotified).
struct AttentionRequest {
    HWND app;
    std::wstring appId;
};

void PostAttentionRequest(HWND app, std::wstring appId) {
    if (!g_attentionThreadId) {
        return;
    }
    auto* request = new AttentionRequest{app, std::move(appId)};
    if (!PostThreadMessage(g_attentionThreadId, WM_APP_ATTENTION, 0,
                           (LPARAM)request)) {
        delete request;
    }
}

void OnAppFlashed(HWND hWnd) {
    if (IsDock() && g_settings.attentionMode == AttentionMode::Icon) {
        PostAttentionRequest(hWnd, {});
    }
}

std::wstring GetWindowAppId(HWND hWnd) {
    std::wstring appId;
    winrt::com_ptr<IPropertyStore> store;
    if (hWnd && SUCCEEDED(SHGetPropertyStoreForWindow(
                    hWnd, IID_PPV_ARGS(store.put())))) {
        PROPVARIANT value;
        PropVariantInit(&value);
        if (SUCCEEDED(store->GetValue(kPKEY_AppUserModel_ID, &value)) &&
            value.vt == VT_LPWSTR && value.pwszVal) {
            appId = value.pwszVal;
        }
        PropVariantClear(&value);
    }
    // Packaged apps (installed from the Store, like WhatsApp) have theirs on
    // their process, not on their windows.
    if (appId.empty() && hWnd) {
        DWORD processId = 0;
        GetWindowThreadProcessId(hWnd, &processId);
        if (HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION,
                                         FALSE, processId)) {
            // An AppUserModelID has at most 130 characters.
            WCHAR id[256] = L"";
            UINT32 length = ARRAYSIZE(id);
            if (GetApplicationUserModelId(process, &length, id) ==
                ERROR_SUCCESS) {
                appId = id;
            }
            CloseHandle(process);
        }
    }
    return appId;
}

// A text a window gives about its app for the taskbar
// (PKEY_AppUserModel_*: 2 the command that starts it again, 4 its name), or
// empty.
std::wstring GetWindowAppText(HWND hWnd, DWORD id) {
    std::wstring text;
    winrt::com_ptr<IPropertyStore> store;
    if (hWnd && SUCCEEDED(SHGetPropertyStoreForWindow(
                    hWnd, IID_PPV_ARGS(store.put())))) {
        PROPERTYKEY key = kPKEY_AppUserModel_ID;
        key.pid = id;
        PROPVARIANT value;
        PropVariantInit(&value);
        if (SUCCEEDED(store->GetValue(key, &value)) && value.vt == VT_LPWSTR &&
            value.pwszVal) {
            text = value.pwszVal;
        }
        PropVariantClear(&value);
    }
    return text;
}

// An app to remember things for (its place): its ID, or its program's path
// when it has none.
std::wstring WindowAppKey(HWND hWnd) {
    std::wstring key = GetWindowAppId(hWnd);
    if (!key.empty() || !hWnd) {
        return key;
    }
    DWORD processId = 0;
    GetWindowThreadProcessId(hWnd, &processId);
    if (HANDLE process =
            OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId)) {
        WCHAR path[MAX_PATH];
        DWORD length = ARRAYSIZE(path);
        if (QueryFullProcessImageName(process, 0, path, &length)) {
            key = path;
        }
        CloseHandle(process);
    }
    return key;
}

// CLSID_StartMenuCacheAndAppResolver and IApplicationResolver (Windows 8
// and later), as the taskbar uses them: the AppUserModelID it gives a window
// or a shortcut.
constexpr GUID kCLSID_AppResolver = {
    0x660b90c8,
    0x73a9,
    0x4b58,
    {0x8c, 0xae, 0x35, 0x5b, 0x7f, 0x55, 0x34, 0x1b}};
constexpr GUID kIID_AppResolver8 = {
    0xde25675a,
    0x72de,
    0x44b4,
    {0x93, 0x73, 0x05, 0x17, 0x04, 0x50, 0xc1, 0x40}};
struct IAppResolver8 : IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetAppIDForShortcut(IShellItem* item,
                                                          PWSTR* appId) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetAppIDForShortcutObject() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetAppIDForWindow(HWND hWnd,
                                                        PWSTR* appId,
                                                        void* unknown1,
                                                        void* unknown2,
                                                        void* unknown3) = 0;
};

// The AppUserModelID the taskbar gives a window's button (its automation ID,
// see GetButtonAppId), as the shell's app resolver works it out: also for an
// app that sets it on its process rather than on its windows (like
// Discord). Its window's own ID if the resolver can't be had.
std::wstring TaskbarAppIdOfWindow(HWND hWnd) {
    std::wstring appId;
    winrt::com_ptr<IAppResolver8> resolver;
    if (SUCCEEDED(CoCreateInstance(kCLSID_AppResolver, nullptr,
                                   CLSCTX_INPROC_SERVER, kIID_AppResolver8,
                                   resolver.put_void()))) {
        PWSTR id = nullptr;
        if (SUCCEEDED(resolver->GetAppIDForWindow(hWnd, &id, nullptr, nullptr,
                                                  nullptr)) &&
            id) {
            appId = id;
        }
        CoTaskMemFree(id);
    }
    return appId.empty() ? GetWindowAppId(hWnd) : appId;
}

// An app's overlay icon set or cleared (see OverlayIcon): its picture copied
// (the taskbar keeps its own). Not while unloading: the copies are freed then
// (see FreeXamlGlobals), and the hooks stay until the unload ends.
void KeepOverlayIcon(HWND hWnd, HICON icon) {
    if (g_unloading) {
        return;
    }
    HICON copy = icon ? CopyIcon(icon) : nullptr;
    int size = 0;
    ICONINFO info{};
    if (copy && GetIconInfo(copy, &info)) {
        BITMAP bitmap{};
        if (GetObject(info.hbmColor ? info.hbmColor : info.hbmMask,
                      sizeof(bitmap), &bitmap)) {
            size = bitmap.bmWidth;
        }
        if (info.hbmColor) {
            DeleteObject(info.hbmColor);
        }
        if (info.hbmMask) {
            DeleteObject(info.hbmMask);
        }
    }
    const std::wstring appId =
        copy ? TaskbarAppIdOfWindow(hWnd) : std::wstring();
    AcquireSRWLockExclusive(&g_overlayIconsLock);
    auto it = std::find_if(
        g_overlayIcons.begin(), g_overlayIcons.end(),
        [&](const OverlayIcon& overlay) { return overlay.wnd == hWnd; });
    if (it != g_overlayIcons.end()) {
        DestroyIcon(it->icon);
        it->icon = nullptr;
    }
    if (!copy) {
        if (it != g_overlayIcons.end()) {
            g_overlayIcons.erase(it);
        }
    } else {
        if (it == g_overlayIcons.end()) {
            g_overlayIcons.push_back({hWnd});
            it = g_overlayIcons.end() - 1;
        }
        it->appId = appId;
        it->icon = copy;
        it->size = size;
        it->serial = ++g_overlaySerial;
    }
    ReleaseSRWLockExclusive(&g_overlayIconsLock);
}

// The apps' progress on their taskbar buttons (ITaskbarList3::
// SetProgressState and SetProgressValue: downloads, copies, installs), for
// the island's pill filling like a loading bar (islandDownloadFill), read
// from the bars the taskbar draws under the buttons (ProgressIndicator):
// their value as shown (whatever scale the app used) and their state by
// their look (see ProgressBarState), the one furthest behind told to the
// island (see PublishProgress). The taskbar's calls for a window's progress
// (CTaskBand::_OnSetProgressState and _OnSetProgressValue) say when to look
// again, and their state stands in when no bar is found at all: their value
// isn't on the bars' scale (it stayed 0 through a whole download). Taskbar
// thread only.
struct ProgressBarWatch {
    winrt::weak_ref<Controls::Primitives::RangeBase> bar;
    Controls::Primitives::RangeBase::ValueChanged_revoker valueChanged;
    VisualStateGroup::CurrentStateChanged_revoker stateChanged;
    int64_t visibilityToken = 0;
};
[[clang::no_destroy]] std::vector<ProgressBarWatch> g_progressBars;
// Each window's state as the taskbar was told (see above).
std::vector<std::pair<HWND, int>> g_windowProgress;
// When the progress the bars show now started (0 none): it's told only
// once it has lasted kProgressSureSeconds (see PublishProgress).
double g_progressSeenAt = 0;
constexpr double kProgressSureSeconds = 5;
// Whether an island fills with the apps' progress (kIpcProgressWanted): the
// bars are watched and read only then.
bool g_progressWanted = false;
// What the island was told last (its state, and per mille).
int g_progressSentState = -1;
int g_progressSentValue = -1;
// What it is, told with the state (its next byte): only Windows' file
// copies (its copy dialog's windows), or anything else (a download, an
// install).
constexpr int kProgressKindCopy = 1;
int g_progressSentKind = -1;
// The windows the kind was worked out for, and it (see PublishProgress).
std::vector<HWND> g_progressKindWindows;
int g_progressKind = 0;
// Only browsers' windows (their next bit): they never tell a download paused
// or failed, so the island takes one standing still as paused (see
// islandDownloadStalled).
constexpr int kProgressFromBrowsers = 1 << 4;
bool g_progressBrowsers = false;
// TBPF_* (shobjidl's): none, going on without a value, normal, error,
// paused.
constexpr int kProgressIndeterminate = 1;
constexpr int kProgressNormal = 2;
constexpr int kProgressError = 4;
constexpr int kProgressPaused = 8;
// To the island (posted: nothing waits): wParam the state, lParam per mille.
constexpr UINT WM_APP_PROGRESS = WM_APP + 98;

bool IsAppWindow(HWND hWnd);

// Whether the windows with progress are Windows' file copies: every one
// Explorer's (its copy dialog, or the folder window the taskbar shows it on:
// its class isn't the dialog's). Another app's window without a taskbar
// button doesn't count: a state it never cleared.
bool ProgressFromCopies(const std::vector<std::pair<HWND, int>>& windows) {
    bool copies = false;
    for (const auto& window : windows) {
        DWORD processId = 0;
        GetWindowThreadProcessId(window.first, &processId);
        if (ProcessIsOneOf(processId, {L"explorer.exe"})) {
            copies = true;
        } else if (IsAppWindow(window.first)) {
            return false;
        }
    }
    return copies;
}

// Whether every window with progress is a browser's (Edge, Chrome, Firefox,
// Brave, Opera, Vivaldi).
bool ProgressFromBrowsers(const std::vector<std::pair<HWND, int>>& windows) {
    if (windows.empty()) {
        return false;
    }
    for (const auto& window : windows) {
        DWORD processId = 0;
        GetWindowThreadProcessId(window.first, &processId);
        if (!ProcessIsOneOf(processId,
                            {L"msedge.exe", L"chrome.exe", L"firefox.exe",
                             L"brave.exe", L"opera.exe", L"vivaldi.exe"})) {
            return false;
        }
    }
    return true;
}

// A bar's state by its look: the visual state its template is in
// (Determinate, Updating, Indeterminate, Error, Paused, IndeterminateError,
// IndeterminatePaused), normal when it can't be read.
int ProgressBarState(Controls::Primitives::RangeBase const& bar) {
    if (Media::VisualTreeHelper::GetChildrenCount(bar) < 1) {
        return kProgressNormal;
    }
    auto root =
        Media::VisualTreeHelper::GetChild(bar, 0).try_as<FrameworkElement>();
    if (!root) {
        return kProgressNormal;
    }
    for (const auto& group : VisualStateManager::GetVisualStateGroups(root)) {
        const auto state = group.CurrentState();
        if (group.Name() != L"CommonStates" || !state) {
            continue;
        }
        const std::wstring name = state.Name().c_str();
        return name.find(L"Error") != std::wstring::npos    ? kProgressError
               : name.find(L"Paused") != std::wstring::npos ? kProgressPaused
               : name.find(L"Indeterminate") != std::wstring::npos
                   ? kProgressIndeterminate
                   : kProgressNormal;
    }
    return kProgressNormal;
}

// The one furthest behind (an error first, then paused, normal and going
// on without a value), to the island when it changed (`force`: anyway,
// when it starts).
void PublishProgress(bool force) {
    if (!g_dockIsMain || g_unloading || !g_progressWanted) {
        return;
    }
    auto rank = [](int state) {
        return state == kProgressError    ? 4
               : state == kProgressPaused ? 3
               : state == kProgressNormal ? 2
               : state == kProgressIndeterminate ? 1
                                                 : 0;
    };
    int state = 0;
    int value = 1000;
    auto add = [&](int barState, int permille) {
        if (rank(barState) > rank(state)) {
            state = barState;
            value = permille;
        } else if (rank(barState) == rank(state)) {
            value = std::min(value, permille);
        }
    };
    std::erase_if(g_progressBars, [](const ProgressBarWatch& watch) {
        return !watch.bar.get();
    });
    for (auto& watch : g_progressBars) {
        auto bar = watch.bar.get();
        // (Shown only while its app has progress.)
        if (bar.Visibility() != Visibility::Visible || bar.Opacity() < 0.01 ||
            bar.ActualWidth() < 1) {
            continue;
        }
        // (Its template's state, once it has one.)
        if (!watch.stateChanged &&
            Media::VisualTreeHelper::GetChildrenCount(bar) > 0) {
            if (auto root = Media::VisualTreeHelper::GetChild(bar, 0)
                                .try_as<FrameworkElement>()) {
                for (const auto& group :
                     VisualStateManager::GetVisualStateGroups(root)) {
                    if (group.Name() == L"CommonStates") {
                        watch.stateChanged = group.CurrentStateChanged(
                            winrt::auto_revoke,
                            [](winrt::Windows::Foundation::IInspectable const&,
                               VisualStateChangedEventArgs const&) {
                                Safely(L"Following a progress bar", [] {
                                    PublishProgress(false);
                                });
                            });
                    }
                }
            }
        }
        const double range = bar.Maximum() - bar.Minimum();
        const int permille =
            range > 0 ? (int)std::clamp(std::lround((bar.Value() -
                                                     bar.Minimum()) *
                                                    1000 / range),
                                        0L, 1000L)
                      : 0;
        add(ProgressBarState(bar), permille);
    }
    // (Only what the taskbar's buttons show: a state told and never
    // cleared, or told by a hidden window, isn't a progress.)
    std::erase_if(g_windowProgress, [](const auto& window) {
        return !IsWindow(window.first) || window.second == 0;
    });
    if (state == 0) {
        value = 0;
    }
    // (Worked out again only when other windows tell one: it opens their
    // processes.)
    std::vector<HWND> windows;
    for (const auto& window : g_windowProgress) {
        windows.push_back(window.first);
    }
    if (windows != g_progressKindWindows) {
        g_progressKindWindows = std::move(windows);
        g_progressKind =
            ProgressFromCopies(g_windowProgress) ? kProgressKindCopy : 0;
        g_progressBrowsers = ProgressFromBrowsers(g_windowProgress);
    }
    const int kind =
        g_progressKind | (g_progressBrowsers ? kProgressFromBrowsers : 0);
    // A new one shows once it has lasted a few seconds (an app showing one
    // for a moment, starting or restoring itself, doesn't fill the pill);
    // Windows' file copies at once (see RecheckProgress).
    const double now = NowSeconds();
    if (state == 0) {
        g_progressSeenAt = 0;
    } else if (!g_progressSeenAt) {
        g_progressSeenAt = now;
    }
    if (state != 0 && kind != kProgressKindCopy &&
        now - g_progressSeenAt < kProgressSureSeconds) {
        state = 0;
        value = 0;
    }
    if (!force && state == g_progressSentState && kind == g_progressSentKind &&
        std::abs(value - g_progressSentValue) < 2) {
        return;
    }
    // (Which programs it comes from, in the log, as a fill starts.)
    if (state != 0 && g_progressSentState <= 0) {
        std::wstring programs;
        for (const auto& window : g_windowProgress) {
            DWORD processId = 0;
            GetWindowThreadProcessId(window.first, &processId);
            const std::wstring path = ProcessImagePathById(processId);
            const std::wstring name = PathFindFileName(path.c_str());
            if (!name.empty() && programs.find(name) == std::wstring::npos) {
                programs += (programs.empty() ? L"" : L", ") + name;
            }
        }
        IslandLog(L"The pill fills with a progress (state %d, %d per mille) "
                  L"from: %s",
                  state, value, programs.empty() ? L"?" : programs.c_str());
    }
    g_progressSentState = state;
    g_progressSentValue = value;
    g_progressSentKind = kind;
    if (HWND island = FindIslandWnd()) {
        PostMessage(island, WM_APP_PROGRESS, (WPARAM)(state | kind << 8),
                    (LPARAM)value);
    }
}

// A taskbar button's bar watched (its value, whether it shows), once: it
// may come only with the app's first progress, so looked for again then.
void WatchProgressBar(FrameworkElement const& button) {
    if (!g_progressWanted) {
        return;
    }
    auto element = FindByName(button, L"ProgressIndicator");
    auto bar = element ? element.try_as<Controls::Primitives::RangeBase>()
                       : nullptr;
    if (!bar || std::any_of(g_progressBars.begin(), g_progressBars.end(),
                            [&](const ProgressBarWatch& watch) {
                                return watch.bar.get() == bar;
                            })) {
        return;
    }
    ProgressBarWatch watch;
    watch.bar = winrt::make_weak(bar);
    watch.valueChanged = bar.ValueChanged(
        winrt::auto_revoke,
        [](winrt::Windows::Foundation::IInspectable const&,
           Controls::Primitives::RangeBaseValueChangedEventArgs const&) {
            Safely(L"Following a progress bar",
                   [] { PublishProgress(false); });
        });
    watch.visibilityToken = bar.RegisterPropertyChangedCallback(
        UIElement::VisibilityProperty(),
        [](DependencyObject const&, DependencyProperty const&) {
            Safely(L"Following a progress bar",
                   [] { PublishProgress(false); });
        });
    g_progressBars.push_back(std::move(watch));
}

// The bars let go (the dock reset, or the mod going).
void StopWatchingProgressBars() {
    for (auto& watch : g_progressBars) {
        if (auto bar = watch.bar.get()) {
            Safely(L"Releasing a progress bar watch", [&] {
                bar.UnregisterPropertyChangedCallback(
                    UIElement::VisibilityProperty(), watch.visibilityToken);
            });
        }
    }
    std::vector<ProgressBarWatch>().swap(g_progressBars);
}

// The buttons' bars looked for (a new one) and read.
void LookAtProgressBars() {
    for (const auto& weak : g_watchedButtons) {
        if (auto button = weak.get()) {
            WatchProgressBar(button);
        }
    }
    PublishProgress(false);
}

// A window's progress changed as the taskbar was told: its state kept; for
// a new window or another state, the buttons' bars looked for (a new one)
// and read. A value alone comes through its bar's own handler once one is
// shown: looked for then at most every kProgressLookSeconds; before (a new
// window's bar comes a moment after its first values), each time.
// RecheckProgress also looks each second.
constexpr double kProgressLookSeconds = 0.5;
double g_progressLookedAt = 0;

void OnWindowProgress(HWND hWnd, int state) {
    if (g_unloading) {
        return;
    }
    // (Windows gone, or whose progress ended, let go here too: with no
    // island filling, PublishProgress doesn't run.)
    std::erase_if(g_windowProgress, [](const auto& window) {
        return !IsWindow(window.first) || window.second == 0;
    });
    bool changed = false;
    if (state >= 0) {
        auto it = std::find_if(
            g_windowProgress.begin(), g_windowProgress.end(),
            [&](const auto& window) { return window.first == hWnd; });
        if (it != g_windowProgress.end()) {
            changed = it->second != state;
            it->second = state;
        } else if (state != 0) {
            g_windowProgress.push_back({hWnd, state});
            changed = true;
        }
    } else if (std::none_of(
                   g_windowProgress.begin(), g_windowProgress.end(),
                   [&](const auto& window) { return window.first == hWnd; })) {
        // (A value set alone means it's going normally.)
        g_windowProgress.push_back({hWnd, kProgressNormal});
        changed = true;
    }
    // (Kept either way: an island turning its fill on sees what's going.)
    const double now = NowSeconds();
    if (g_progressWanted &&
        (changed || g_progressSentState <= 0 ||
         now - g_progressLookedAt >= kProgressLookSeconds)) {
        g_progressLookedAt = now;
        LookAtProgressBars();
    }
}

// An island fills with the apps' progress, or none does anymore (see
// kIpcProgressWanted): the bars watched and read from now, or let go.
void SetProgressWanted(bool wanted) {
    if (wanted == g_progressWanted) {
        return;
    }
    g_progressWanted = wanted;
    if (wanted) {
        LookAtProgressBars();
        PublishProgress(true);
    } else {
        StopWatchingProgressBars();
        g_progressSentState = -1;
    }
}

// Each second while a window has progress, one is waiting to be told, or
// the island shows one (see g_badgeTimer): the bars read again. A new
// window's button, and its bar, may come or show only after the taskbar's
// call; and the taskbar may hide a finished one without telling (no
// change of its bar's visibility), so it's never left filling the pill.
void RecheckProgress() {
    if (g_progressWanted &&
        (!g_windowProgress.empty() || g_progressSeenAt > 0 ||
         g_progressSentState > 0)) {
        LookAtProgressBars();
    }
}

using CTaskBand__OnSetProgressState_t = void(WINAPI*)(void* pThis,
                                                      HWND hWnd,
                                                      int state);
CTaskBand__OnSetProgressState_t CTaskBand__OnSetProgressState_Original;
void WINAPI CTaskBand__OnSetProgressState_Hook(void* pThis,
                                               HWND hWnd,
                                               int state) {
    CTaskBand__OnSetProgressState_Original(pThis, hWnd, state);
    Safely(L"Following the progress", [&] { OnWindowProgress(hWnd, state); });
}

using CTaskBand__OnSetProgressValue_t = void(WINAPI*)(void* pThis,
                                                      HWND hWnd,
                                                      DWORD value);
CTaskBand__OnSetProgressValue_t CTaskBand__OnSetProgressValue_Original;
void WINAPI CTaskBand__OnSetProgressValue_Hook(void* pThis,
                                               HWND hWnd,
                                               DWORD value) {
    CTaskBand__OnSetProgressValue_Original(pThis, hWnd, value);
    Safely(L"Following the progress", [&] { OnWindowProgress(hWnd, -1); });
}

// (Before the taskbar takes it.)
using CTaskBand__HandleOverlayIcon_t = void(WINAPI*)(void* pThis,
                                                     HWND hWnd,
                                                     HICON icon);
CTaskBand__HandleOverlayIcon_t CTaskBand__HandleOverlayIcon_Original;
void WINAPI CTaskBand__HandleOverlayIcon_Hook(void* pThis,
                                              HWND hWnd,
                                              HICON icon) {
    KeepOverlayIcon(hWnd, icon);
    CTaskBand__HandleOverlayIcon_Original(pThis, hWnd, icon);
}

// An app's overlay icon's text set (it may come before the picture). Not
// while unloading (see KeepOverlayIcon).
void KeepOverlayText(HWND hWnd, PCWSTR text) {
    if (g_unloading) {
        return;
    }
    AcquireSRWLockExclusive(&g_overlayIconsLock);
    auto it = std::find_if(
        g_overlayIcons.begin(), g_overlayIcons.end(),
        [&](const OverlayIcon& overlay) { return overlay.wnd == hWnd; });
    if (it == g_overlayIcons.end()) {
        g_overlayIcons.push_back({hWnd});
        it = g_overlayIcons.end() - 1;
    }
    const std::wstring description = text ? text : L"";
    if (it->description != description) {
        it->description = description;
        it->serial = ++g_overlaySerial;
    }
    ReleaseSRWLockExclusive(&g_overlayIconsLock);
}

// An app's overlay icon's text: the taskbar hands it to its item (see
// CTaskItem_SetOverlayIconDescription_Hook) while this runs, for this
// window. Taskbar thread only.
HWND g_overlayTextWnd;
using CTaskBand__HandleOverlayIconDescription_t =
    void(WINAPI*)(void* pThis, HWND hWnd, void* text);
CTaskBand__HandleOverlayIconDescription_t
    CTaskBand__HandleOverlayIconDescription_Original;
void WINAPI CTaskBand__HandleOverlayIconDescription_Hook(void* pThis,
                                                         HWND hWnd,
                                                         void* text) {
    g_overlayTextWnd = hWnd;
    CTaskBand__HandleOverlayIconDescription_Original(pThis, hWnd, text);
    g_overlayTextWnd = nullptr;
}

using CTaskItem_SetOverlayIconDescription_t = HRESULT(WINAPI*)(void* pThis,
                                                               PCWSTR text);
CTaskItem_SetOverlayIconDescription_t
    CTaskItem_SetOverlayIconDescription_Original;
HRESULT WINAPI CTaskItem_SetOverlayIconDescription_Hook(void* pThis,
                                                        PCWSTR text) {
    if (HWND hWnd = g_overlayTextWnd) {
        KeepOverlayText(hWnd, text);
    }
    return CTaskItem_SetOverlayIconDescription_Original(pThis, text);
}

// The apps' overlay icons set before the mod started (like Discord's counter
// from before the mod was turned on or updated), read from the taskbar's
// items as if they came now: otherwise they'd stay as the taskbar draws them
// (see UseBigOverlay) until they change. Through the task band's
// ITaskListManager (found like its ITaskListWndSite, see
// GetTaskbarXamlRoot); only the taskbar's own items are read (a window's
// or a Store app's, by their tables).
void* CTaskBand_ITaskListManager_vftable;
void* CWindowTaskItem_ITaskItem_vftable;
void* CImmersiveTaskItem_ITaskItem_vftable;
using CTaskBand_GetTaskFromWindow_t = HRESULT(WINAPI*)(void* pThis,
                                                       HWND hWnd,
                                                       IUnknown** group,
                                                       IUnknown** item);
CTaskBand_GetTaskFromWindow_t CTaskBand_GetTaskFromWindow_Original;
using CTaskItem_GetOverlayIcon_t = HICON(WINAPI*)(void* pThis);
CTaskItem_GetOverlayIcon_t CTaskItem_GetOverlayIcon_Original;
using CTaskItem_GetOverlayIconDescription_t = PCWSTR(WINAPI*)(void* pThis);
CTaskItem_GetOverlayIconDescription_t
    CTaskItem_GetOverlayIconDescription_Original;

BOOL CALLBACK ReadOverlayIconProc(HWND hWnd, LPARAM lParam) {
    if (!IsWindowVisible(hWnd) && !IsIconic(hWnd)) {
        return TRUE;
    }
    AcquireSRWLockShared(&g_overlayIconsLock);
    const bool known = std::any_of(
        g_overlayIcons.begin(), g_overlayIcons.end(),
        [&](const OverlayIcon& overlay) { return overlay.wnd == hWnd; });
    ReleaseSRWLockShared(&g_overlayIconsLock);
    IUnknown* group = nullptr;
    IUnknown* item = nullptr;
    if (known ||
        FAILED(CTaskBand_GetTaskFromWindow_Original((void*)lParam, hWnd, &group,
                                                    &item)) ||
        !item) {
        if (group) {
            group->Release();
        }
        return TRUE;
    }
    const void* table = *(void**)item;
    if (table && (table == CWindowTaskItem_ITaskItem_vftable ||
                  table == CImmersiveTaskItem_ITaskItem_vftable)) {
        if (HICON icon = CTaskItem_GetOverlayIcon_Original(item)) {
            KeepOverlayText(hWnd,
                            CTaskItem_GetOverlayIconDescription_Original(item));
            KeepOverlayIcon(hWnd, icon);
        }
    }
    item->Release();
    if (group) {
        group->Release();
    }
    return TRUE;
}

void WINAPI ReadOverlayIconsProc(void*) {
    if (!CTaskBand_ITaskListManager_vftable ||
        (!CWindowTaskItem_ITaskItem_vftable &&
         !CImmersiveTaskItem_ITaskItem_vftable) ||
        !CTaskBand_GetTaskFromWindow_Original ||
        !CTaskItem_GetOverlayIcon_Original ||
        !CTaskItem_GetOverlayIconDescription_Original) {
        return;
    }
    HWND hTaskbarWnd = FindCurrentProcessTaskbarWnd();
    HWND hTaskSwWnd =
        hTaskbarWnd ? (HWND)GetProp(hTaskbarWnd, L"TaskbandHWND") : nullptr;
    void* manager =
        hTaskSwWnd ? (void*)GetWindowLongPtr(hTaskSwWnd, 0) : nullptr;
    for (int i = 0;
         manager && *(void**)manager != CTaskBand_ITaskListManager_vftable;
         i++) {
        manager = i == 20 ? nullptr : (void**)manager + 1;
    }
    if (manager) {
        EnumWindows(ReadOverlayIconProc, (LPARAM)manager);
        StartRendering();
    }
}

void ReadOverlayIcons() {
    if (HWND hTaskbarWnd = FindCurrentProcessTaskbarWnd()) {
        RunFromWindowThread(hTaskbarWnd, ReadOverlayIconsProc, nullptr);
    }
}

// A value of an app's registration as a notification sender
// (Software\Classes\AppUserModelId\<ID>, the user's then the machine's, as
// Windows' notification center reads it), with environment variables and
// "@file,-id" or "@{...}" resources resolved. `registered` (optional) tells
// whether the app has one.
std::wstring RegisteredAppValue(const std::wstring& appId,
                                PCWSTR name,
                                bool* registered = nullptr) {
    if (registered) {
        *registered = false;
    }
    if (appId.empty() || appId.size() > 256 ||
        appId.find(L'\\') != std::wstring::npos) {
        return {};
    }
    const std::wstring key = L"Software\\Classes\\AppUserModelId\\" + appId;
    for (HKEY root : {HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE}) {
        HKEY app = nullptr;
        if (RegOpenKeyEx(root, key.c_str(), 0, KEY_QUERY_VALUE, &app) !=
            ERROR_SUCCESS) {
            continue;
        }
        if (registered) {
            *registered = true;
        }
        WCHAR value[1024];
        DWORD size = sizeof(value);
        const bool read =
            RegGetValue(app, nullptr, name,
                        RRF_RT_REG_SZ | RRF_RT_REG_EXPAND_SZ, nullptr, value,
                        &size) == ERROR_SUCCESS;
        RegCloseKey(app);
        if (!read || !value[0]) {
            continue;
        }
        if (value[0] != L'@') {
            return value;
        }
        WCHAR resolved[1024];
        if (SUCCEEDED(SHLoadIndirectString(value, resolved,
                                           ARRAYSIZE(resolved), nullptr))) {
            return resolved;
        }
    }
    return {};
}

// A full path on one of this computer's drives (not a share, nor a drive
// letter mapped to one: no connection to another computer).
bool IsLocalDrivePath(const std::wstring& path) {
    if (path.size() < 4 || !iswalpha(path[0]) || path[1] != L':' ||
        path[2] != L'\\') {
        return false;
    }
    const WCHAR root[] = {path[0], L':', L'\\', 0};
    return GetDriveType(root) != DRIVE_REMOTE;
}

// The picture a notification sender registered (IconUri: a file, or a
// resource of a package or of Windows), as a file; Windows' default picture
// for its own notifications for one registered without any. Only a file on
// a drive (never a share: no connection to another computer). Empty if the
// app isn't registered.
std::wstring RegisteredAppPicture(const std::wstring& appId) {
    bool registered = false;
    std::wstring uri = RegisteredAppValue(appId, L"IconUri", &registered);
    if (!registered) {
        return {};
    }
    if (uri.empty()) {
        uri =
            L"ms-resource://Windows.UI.ShellCommon/Files/Images/"
            L"DefaultSystemNotification.png";
    }
    // (Windows' resources, by the same name as in a package's.)
    if (uri.starts_with(L"ms-resource://")) {
        WCHAR resolved[1024];
        const std::wstring resource = L"@{Windows?" + uri + L"}";
        uri = SUCCEEDED(SHLoadIndirectString(resource.c_str(), resolved,
                                             ARRAYSIZE(resolved), nullptr))
                  ? resolved
                  : L"";
    }
    if (!IsLocalDrivePath(uri)) {
        return {};
    }
    return uri;
}

// A picture file as a 32-bit bitmap with premultiplied alpha, fit in a
// square of `size` pixels (like an icon).
HBITMAP LoadPictureBitmap(PCWSTR path, int size) {
    winrt::com_ptr<IWICImagingFactory> wic;
    winrt::com_ptr<IWICBitmapDecoder> decoder;
    winrt::com_ptr<IWICBitmapFrameDecode> frame;
    UINT width = 0, height = 0;
    if (size <= 0 ||
        FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                                CLSCTX_INPROC_SERVER, IID_PPV_ARGS(wic.put()))) ||
        FAILED(wic->CreateDecoderFromFilename(path, nullptr, GENERIC_READ,
                                              WICDecodeMetadataCacheOnDemand,
                                              decoder.put())) ||
        FAILED(decoder->GetFrame(0, frame.put())) ||
        FAILED(frame->GetSize(&width, &height)) || !width || !height) {
        return nullptr;
    }
    const double fit = std::min((double)size / width, (double)size / height);
    const UINT shownWidth = std::max<UINT>(1, (UINT)std::lround(width * fit));
    const UINT shownHeight = std::max<UINT>(1, (UINT)std::lround(height * fit));
    winrt::com_ptr<IWICBitmapScaler> scaler;
    winrt::com_ptr<IWICFormatConverter> converter;
    if (FAILED(wic->CreateBitmapScaler(scaler.put())) ||
        FAILED(scaler->Initialize(frame.get(), shownWidth, shownHeight,
                                  WICBitmapInterpolationModeFant)) ||
        FAILED(wic->CreateFormatConverter(converter.put())) ||
        FAILED(converter->Initialize(scaler.get(),
                                     GUID_WICPixelFormat32bppPBGRA,
                                     WICBitmapDitherTypeNone, nullptr, 0,
                                     WICBitmapPaletteTypeMedianCut))) {
        return nullptr;
    }
    BITMAPINFO header{};
    header.bmiHeader = {sizeof(BITMAPINFOHEADER), size, -size, 1, 32, BI_RGB};
    void* bits = nullptr;
    HBITMAP bitmap = CreateDIBSection(nullptr, &header, DIB_RGB_COLORS, &bits,
                                      nullptr, 0);
    if (!bitmap) {
        return nullptr;
    }
    // (Transparent around it; in the middle.)
    ZeroMemory(bits, (size_t)size * size * 4);
    const UINT stride = (UINT)size * 4;
    BYTE* start = (BYTE*)bits + ((size - shownHeight) / 2) * stride +
                  ((size - shownWidth) / 2) * 4;
    if (FAILED(converter->CopyPixels(
            nullptr, stride, (shownHeight - 1) * stride + shownWidth * 4,
            start))) {
        DeleteObject(bitmap);
        return nullptr;
    }
    return bitmap;
}

// An icon as a 32-bit bitmap with premultiplied alpha (nullptr without
// colors of its own). An old one without an alpha channel (fewer colors, or
// 32 bits all at 0) shows where its mask says, as Windows draws it.
HBITMAP IconBitmap(HICON icon) {
    ICONINFO info{};
    if (!GetIconInfo(icon, &info)) {
        return nullptr;
    }
    HBITMAP result = nullptr;
    BITMAP color{};
    if (info.hbmColor && GetObject(info.hbmColor, sizeof(color), &color) &&
        color.bmWidth > 0 && color.bmHeight > 0) {
        const int width = color.bmWidth;
        const int height = std::abs(color.bmHeight);
        BITMAPINFO header{};
        header.bmiHeader = {sizeof(BITMAPINFOHEADER), width, -height, 1, 32,
                            BI_RGB};
        void* bits = nullptr;
        HDC screen = GetDC(nullptr);
        result = CreateDIBSection(screen, &header, DIB_RGB_COLORS, &bits,
                                  nullptr, 0);
        if (result && bits &&
            GetDIBits(screen, info.hbmColor, 0, height, bits, &header,
                      DIB_RGB_COLORS) == height) {
            // (Icons keep their colors as they are: premultiplied here.)
            auto* pixels = static_cast<uint8_t*>(bits);
            const size_t count = (size_t)width * height * 4;
            bool alpha = false;
            for (size_t i = 3; i < count && !alpha; i += 4) {
                alpha = pixels[i] != 0;
            }
            if (!alpha) {
                // (The mask's white is what doesn't show.)
                std::vector<uint8_t> mask(count);
                const bool masked =
                    info.hbmMask &&
                    GetDIBits(screen, info.hbmMask, 0, height, mask.data(),
                              &header, DIB_RGB_COLORS) == height;
                for (size_t i = 0; i < count; i += 4) {
                    pixels[i + 3] = masked && mask[i] ? 0 : 255;
                }
            }
            for (size_t i = 0; i < count; i += 4) {
                for (int c = 0; c < 3; c++) {
                    pixels[i + c] =
                        (uint8_t)(pixels[i + c] * pixels[i + 3] / 255);
                }
            }
        } else if (result) {
            DeleteObject(result);
            result = nullptr;
        }
        ReleaseDC(nullptr, screen);
    }
    if (info.hbmColor) {
        DeleteObject(info.hbmColor);
    }
    if (info.hbmMask) {
        DeleteObject(info.hbmMask);
    }
    return result;
}

BOOL CALLBACK FindAppIdWindowProc(HWND hWnd, LPARAM lParam) {
    auto* search = reinterpret_cast<std::pair<const std::wstring*, HWND>*>(
        lParam);
    if (IsWindowVisible(hWnd) &&
        _wcsicmp(GetWindowAppId(hWnd).c_str(), search->first->c_str()) == 0) {
        search->second = hWnd;
        return FALSE;
    }
    return TRUE;
}

// The program an app's window gives the taskbar to start it again
// (PKEY_AppUserModel_RelaunchCommand), when it's a file that's there. The
// command may be a path with spaces and no quotes, like Steam's
// "C:\Program Files (x86)\Steam\steam.exe": the whole of it first.
std::wstring WindowRelaunchProgram(HWND window) {
    auto isProgram = [](const std::wstring& path) {
        const DWORD attributes =
            IsLocalDrivePath(path) ? GetFileAttributes(path.c_str())
                                   : INVALID_FILE_ATTRIBUTES;
        return attributes != INVALID_FILE_ATTRIBUTES &&
               !(attributes & FILE_ATTRIBUTE_DIRECTORY);
    };
    const std::wstring command = GetWindowAppText(window, 2);
    if (command.empty() || isProgram(command)) {
        return command;
    }
    std::wstring program;
    int count = 0;
    if (LPWSTR* parts = CommandLineToArgvW(command.c_str(), &count)) {
        if (count > 0 && isProgram(parts[0])) {
            program = parts[0];
        }
        LocalFree(parts);
    }
    return program;
}

// The icon an app's window gives the taskbar for its own ID (its
// PKEY_AppUserModel_RelaunchIconResource, "path,index"), like the profile's
// picture of a browser's second profile, which has no Start menu entry; or,
// without one (like Steam's window), its relaunch program's or its process
// file's, as big as asked (the taskbar's own is small).
HBITMAP WindowRelaunchIconBitmap(const std::wstring& appId, int size) {
    std::pair<const std::wstring*, HWND> search{&appId, nullptr};
    EnumWindows(FindAppIdWindowProc, reinterpret_cast<LPARAM>(&search));
    if (!search.second) {
        return nullptr;
    }
    const std::wstring resource = GetWindowAppText(search.second, 3);
    if (const size_t comma = resource.rfind(L',');
        comma != std::wstring::npos && comma != 0) {
        WCHAR path[MAX_PATH];
        HICON icon = nullptr;
        if (ExpandEnvironmentStrings(resource.substr(0, comma).c_str(), path,
                                     ARRAYSIZE(path)) &&
            IsLocalDrivePath(path) &&
            PrivateExtractIcons(path, _wtoi(resource.c_str() + comma + 1),
                                size, size, &icon, nullptr, 1, 0) == 1 &&
            icon) {
            HBITMAP bitmap = IconBitmap(icon);
            DestroyIcon(icon);
            return bitmap;
        }
    }
    std::wstring program = WindowRelaunchProgram(search.second);
    // (Nor a program: its process's file. Not a packaged app's: its window
    // may be the frame of another process.)
    DWORD processId = 0;
    if (program.empty() && appId.find(L'!') == std::wstring::npos &&
        GetWindowThreadProcessId(search.second, &processId)) {
        if (HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION,
                                         FALSE, processId)) {
            WCHAR path[MAX_PATH];
            DWORD length = ARRAYSIZE(path);
            if (QueryFullProcessImageName(process, 0, path, &length)) {
                program = path;
            }
            CloseHandle(process);
        }
    }
    winrt::com_ptr<IShellItemImageFactory> factory;
    HBITMAP bitmap = nullptr;
    if (program.empty() ||
        FAILED(SHCreateItemFromParsingName(program.c_str(), nullptr,
                                           IID_PPV_ARGS(factory.put()))) ||
        FAILED(factory->GetImage({size, size},
                                 SIIGBF_ICONONLY | SIIGBF_BIGGERSIZEOK,
                                 &bitmap))) {
        return nullptr;
    }
    return bitmap;
}

// The icon an app's window has (the one it gives with WM_GETICON, or its
// class's), for an app the shell has no icon for: what the taskbar draws.
// Its window as found on the taskbar's thread (see TakeBigIcon), else one
// with its ID.
HBITMAP AppWindowIconBitmap(const std::wstring& appId, HWND window) {
    std::pair<const std::wstring*, HWND> search{&appId, window};
    if (!search.second) {
        EnumWindows(FindAppIdWindowProc, reinterpret_cast<LPARAM>(&search));
    }
    if (!search.second || !IsWindow(search.second)) {
        return nullptr;
    }
    HICON icon = nullptr;
    for (WPARAM kind : {(WPARAM)ICON_BIG, (WPARAM)ICON_SMALL2,
                        (WPARAM)ICON_SMALL}) {
        DWORD_PTR result = 0;
        if (SendMessageTimeout(search.second, WM_GETICON, kind, 0,
                               SMTO_ABORTIFHUNG, 200, &result) &&
            result) {
            icon = (HICON)result;
            break;
        }
    }
    if (!icon) {
        icon = (HICON)GetClassLongPtr(search.second, GCLP_HICON);
    }
    if (!icon) {
        icon = (HICON)GetClassLongPtr(search.second, GCLP_HICONSM);
    }
    // (The window's own: a copy is drawn and let go.)
    HICON copy = icon ? CopyIcon(icon) : nullptr;
    if (!copy) {
        return nullptr;
    }
    HBITMAP bitmap = IconBitmap(copy);
    DestroyIcon(copy);
    return bitmap;
}

// FOLDERID_UserPinned: the shortcuts pinned to the taskbar are in its
// "TaskBar" folder.
constexpr GUID kFOLDERID_UserPinned = {
    0x9e3995ab,
    0x1f9c,
    0x4f13,
    {0xb8, 0x27, 0x48, 0xb2, 0x4b, 0x6c, 0x71, 0x74}};
// CLSID_ShellLink: reads a shortcut's file.
constexpr GUID kCLSID_ShellLink = {
    0x00021401,
    0x0000,
    0x0000,
    {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};

std::wstring KnownFolderPath(const GUID& folder);

// The icon given to an app's shortcut pinned to the taskbar (like one changed
// in its properties), which the taskbar shows in place of the app's own, as
// big as asked; nullptr when it has none of its own (its program's first
// icon) or isn't pinned. The app is the shortcut's as the taskbar works it
// out (see TaskbarAppIdOfWindow).
HBITMAP PinnedShortcutIconBitmap(const std::wstring& appId, int size) {
    const std::wstring folder = KnownFolderPath(kFOLDERID_UserPinned);
    winrt::com_ptr<IAppResolver8> resolver;
    if (appId.empty() || folder.empty() ||
        FAILED(CoCreateInstance(kCLSID_AppResolver, nullptr,
                                CLSCTX_INPROC_SERVER, kIID_AppResolver8,
                                resolver.put_void()))) {
        return nullptr;
    }
    const std::wstring pinned = folder + L"\\TaskBar\\";
    WIN32_FIND_DATA data;
    HANDLE find =
        FindFirstFileEx((pinned + L"*.lnk").c_str(), FindExInfoBasic, &data,
                        FindExSearchNameMatch, nullptr, 0);
    if (find == INVALID_HANDLE_VALUE) {
        return nullptr;
    }
    HBITMAP bitmap = nullptr;
    do {
        const std::wstring path = pinned + data.cFileName;
        winrt::com_ptr<IShellItem> item;
        PWSTR id = nullptr;
        const bool same =
            SUCCEEDED(SHCreateItemFromParsingName(path.c_str(), nullptr,
                                                  IID_PPV_ARGS(item.put()))) &&
            SUCCEEDED(resolver->GetAppIDForShortcut(item.get(), &id)) && id &&
            _wcsicmp(id, appId.c_str()) == 0;
        CoTaskMemFree(id);
        if (!same) {
            continue;
        }
        winrt::com_ptr<IShellLinkW> link;
        winrt::com_ptr<IPersistFile> file;
        WCHAR icon[MAX_PATH] = L"";
        WCHAR program[MAX_PATH] = L"";
        WCHAR iconPath[MAX_PATH];
        int index = 0;
        if (SUCCEEDED(CoCreateInstance(kCLSID_ShellLink, nullptr,
                                       CLSCTX_INPROC_SERVER,
                                       IID_PPV_ARGS(link.put()))) &&
            (file = link.try_as<IPersistFile>()) &&
            SUCCEEDED(file->Load(path.c_str(), STGM_READ)) &&
            SUCCEEDED(link->GetIconLocation(icon, ARRAYSIZE(icon), &index)) &&
            icon[0] &&
            ExpandEnvironmentStrings(icon, iconPath, ARRAYSIZE(iconPath)) &&
            IsLocalDrivePath(iconPath)) {
            // (Its program's own first icon: the app's, as without it.)
            const bool own =
                index == 0 &&
                SUCCEEDED(link->GetPath(program, ARRAYSIZE(program), nullptr,
                                        0)) &&
                _wcsicmp(program, iconPath) == 0;
            HICON picture = nullptr;
            if (!own &&
                PrivateExtractIcons(iconPath, index, size, size, &picture,
                                    nullptr, 1, 0) == 1 &&
                picture) {
                bitmap = IconBitmap(picture);
                DestroyIcon(picture);
            }
        }
        break;
    } while (FindNextFile(find, &data));
    FindClose(find);
    return bitmap;
}

// The AppUserModelIDs of the apps pinned to the taskbar, as the taskbar works
// them out from its shortcuts (see PinnedShortcutIconBitmap); empty when
// they can't be read (the folder isn't on a drive of this computer, or none
// are pinned). On the taskbar's thread, out of a frame (see
// RefreshPinnedApps).
std::vector<std::wstring> ReadPinnedAppIds() {
    std::vector<std::wstring> ids;
    const std::wstring folder = KnownFolderPath(kFOLDERID_UserPinned);
    winrt::com_ptr<IAppResolver8> resolver;
    if (folder.empty() || !IsLocalDrivePath(folder) ||
        FAILED(CoCreateInstance(kCLSID_AppResolver, nullptr,
                                CLSCTX_INPROC_SERVER, kIID_AppResolver8,
                                resolver.put_void()))) {
        return ids;
    }
    const std::wstring pinned = folder + L"\\TaskBar\\";
    WIN32_FIND_DATA data;
    HANDLE find =
        FindFirstFileEx((pinned + L"*.lnk").c_str(), FindExInfoBasic, &data,
                        FindExSearchNameMatch, nullptr, 0);
    if (find == INVALID_HANDLE_VALUE) {
        return ids;
    }
    do {
        winrt::com_ptr<IShellItem> item;
        PWSTR id = nullptr;
        if (SUCCEEDED(SHCreateItemFromParsingName(
                (pinned + data.cFileName).c_str(), nullptr,
                IID_PPV_ARGS(item.put()))) &&
            SUCCEEDED(resolver->GetAppIDForShortcut(item.get(), &id)) && id) {
            ids.emplace_back(id);
        }
        CoTaskMemFree(id);
    } while (FindNextFile(find, &data));
    FindClose(find);
    return ids;
}

DWORD SessionProcessId(PCWSTR exe);
std::wstring ProcessImagePath(DWORD processId);

// An app known only by its program's file name (a media app without an ID of
// its own, like "Spotify.exe" or "vlc.exe"): that program's path while it
// runs in this session, or empty.
std::wstring RunningProgramPath(const std::wstring& appId) {
    if (appId.size() < 5 || appId.find(L'\\') != std::wstring::npos ||
        _wcsicmp(appId.c_str() + appId.size() - 4, L".exe") != 0) {
        return {};
    }
    const DWORD processId = SessionProcessId(appId.c_str());
    return processId ? ProcessImagePath(processId) : std::wstring();
}

// The app's icon as a 32-bit bitmap with premultiplied alpha, from the shell:
// by the app's AppUserModelID if it has one, by its program file otherwise.
HBITMAP LoadAppIconBitmap(HWND hWnd, std::wstring appId, int size) {
    winrt::com_ptr<IShellItemImageFactory> factory;

    if (appId.empty()) {
        appId = GetWindowAppId(hWnd);
    }
    if (!appId.empty()) {
        SHCreateItemInKnownFolder(kFOLDERID_AppsFolder, 0, appId.c_str(),
                                  IID_PPV_ARGS(factory.put()));
    }
    // Notifications of a packaged app may come under an ID of their own (like
    // Phone Link's, one for each phone app): its package's app then.
    if (const size_t bang = appId.find(L'!');
        !factory && bang != std::wstring::npos) {
        const std::wstring packageApp = appId.substr(0, bang) + L"!App";
        if (packageApp != appId) {
            SHCreateItemInKnownFolder(kFOLDERID_AppsFolder, 0,
                                      packageApp.c_str(),
                                      IID_PPV_ARGS(factory.put()));
        }
    }

    // An app known by its program file (a window without an ID of its own,
    // like Discord's): that file's icon (on a drive only, never a network
    // path).
    if (!factory && IsLocalDrivePath(appId)) {
        SHCreateItemFromParsingName(appId.c_str(), nullptr,
                                    IID_PPV_ARGS(factory.put()));
    }
    // (Or only by its file's name: the one running.)
    if (!factory) {
        if (const std::wstring path = RunningProgramPath(appId);
            IsLocalDrivePath(path)) {
            SHCreateItemFromParsingName(path.c_str(), nullptr,
                                        IID_PPV_ARGS(factory.put()));
        }
    }
    if (!factory && hWnd) {
        DWORD processId = 0;
        GetWindowThreadProcessId(hWnd, &processId);
        HANDLE process =
            OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
        if (process) {
            WCHAR path[MAX_PATH];
            DWORD length = ARRAYSIZE(path);
            if (QueryFullProcessImageName(process, 0, path, &length)) {
                SHCreateItemFromParsingName(path, nullptr,
                                            IID_PPV_ARGS(factory.put()));
            }
            CloseHandle(process);
        }
    }

    // (No Start menu entry: the icon its windows give the taskbar.)
    if (!factory && !appId.empty()) {
        if (HBITMAP icon = WindowRelaunchIconBitmap(appId, size)) {
            return icon;
        }
    }
    HBITMAP bitmap = nullptr;
    if (factory &&
        FAILED(factory->GetImage({size, size},
                                 SIIGBF_ICONONLY | SIIGBF_BIGGERSIZEOK,
                                 &bitmap))) {
        bitmap = nullptr;
    }
    // A sender with no Start menu entry (Windows' own, like Windows
    // Security's, or an app registered only for its notifications): the
    // picture it registered.
    if (!factory && !appId.empty()) {
        const std::wstring picture = RegisteredAppPicture(appId);
        if (!picture.empty()) {
            bitmap = LoadPictureBitmap(picture.c_str(), size);
        }
    }
    return bitmap;
}

// The app a notification is shown under on the pill: its sender, or (see
// islandGroupApps) the package's app when the sender is one of its own IDs
// without a Start menu entry of its own (like Phone Link's, one for each
// phone app: they'd all be the same icon), so its notifications are one icon
// with their counts together. Asked once for each ID (the island's thread).
std::unordered_map<std::wstring, std::wstring> g_notificationAppKeys;

std::wstring NotificationAppKey(const std::wstring& appId) {
    const size_t bang = appId.find(L'!');
    if (!g_settings.islandGroupApps || bang == std::wstring::npos) {
        return appId;
    }
    const std::wstring packageApp = appId.substr(0, bang) + L"!App";
    if (_wcsicmp(packageApp.c_str(), appId.c_str()) == 0) {
        return appId;
    }
    if (const auto it = g_notificationAppKeys.find(appId);
        it != g_notificationAppKeys.end()) {
        return it->second;
    }
    winrt::com_ptr<IShellItem> own;
    winrt::com_ptr<IShellItem> package;
    const bool grouped =
        FAILED(SHCreateItemInKnownFolder(kFOLDERID_AppsFolder, 0, appId.c_str(),
                                         IID_PPV_ARGS(own.put()))) &&
        SUCCEEDED(SHCreateItemInKnownFolder(kFOLDERID_AppsFolder, 0,
                                            packageApp.c_str(),
                                            IID_PPV_ARGS(package.put())));
    const std::wstring key = grouped ? packageApp : appId;
    g_notificationAppKeys[appId] = key;
    return key;
}

bool SameNotificationApp(const std::wstring& appId, const std::wstring& key) {
    return _wcsicmp(appId.c_str(), key.c_str()) == 0 ||
           _wcsicmp(NotificationAppKey(appId).c_str(), key.c_str()) == 0;
}

// The icons given to the island (see kIpcAppIcon), by app and size. Only used
// on the taskbar's thread.
std::vector<std::pair<std::wstring, HICON>> g_islandAppIcons;

HICON AppIconForIsland(const COPYDATASTRUCT* copyData) {
    IpcReader reader(copyData);
    int size = 0;
    std::wstring appId;
    if (!reader.Get(&size) || !reader.GetString(&appId) || appId.empty() ||
        size <= 0 || size > 256) {
        return nullptr;
    }
    const std::wstring key = std::to_wstring(size) + L"|" + appId;
    for (const auto& [id, icon] : g_islandAppIcons) {
        if (id == key) {
            return icon;
        }
    }
    HICON icon = nullptr;
    if (HBITMAP bitmap = LoadAppIconBitmap(nullptr, appId, size)) {
        // An icon's colors aren't premultiplied by their alpha.
        BITMAP info{};
        GetObject(bitmap, sizeof(info), &info);
        const int width = info.bmWidth;
        const int height = std::abs(info.bmHeight);
        BITMAPINFO header{};
        header.bmiHeader = {sizeof(BITMAPINFOHEADER), width, -height, 1, 32,
                            BI_RGB};
        void* bits = nullptr;
        HDC screen = GetDC(nullptr);
        HBITMAP color = width > 0 && height > 0
                            ? CreateDIBSection(screen, &header, DIB_RGB_COLORS,
                                               &bits, nullptr, 0)
                            : nullptr;
        if (color &&
            GetDIBits(screen, bitmap, 0, height, bits, &header,
                      DIB_RGB_COLORS) == height) {
            auto* pixel = (BYTE*)bits;
            for (int i = 0; i < width * height; i++, pixel += 4) {
                if (const BYTE alpha = pixel[3]; alpha && alpha < 255) {
                    for (int c = 0; c < 3; c++) {
                        pixel[c] = (BYTE)std::min(255, pixel[c] * 255 / alpha);
                    }
                }
            }
            HBITMAP mask = CreateBitmap(width, height, 1, 1, nullptr);
            ICONINFO iconInfo{TRUE, 0, 0, mask, color};
            icon = CreateIconIndirect(&iconInfo);
            if (mask) {
                DeleteObject(mask);
            }
        }
        if (color) {
            DeleteObject(color);
        }
        ReleaseDC(nullptr, screen);
        DeleteObject(bitmap);
    }
    // Remembered even when missing, so it isn't looked up again; the oldest
    // go past a limit (the island has copied them already).
    constexpr size_t kMaxIslandAppIcons = 128;
    if (g_islandAppIcons.size() >= kMaxIslandAppIcons) {
        for (size_t i = 0; i < kMaxIslandAppIcons / 2; i++) {
            if (g_islandAppIcons[i].second) {
                DestroyIcon(g_islandAppIcons[i].second);
            }
        }
        g_islandAppIcons.erase(g_islandAppIcons.begin(),
                               g_islandAppIcons.begin() +
                                   kMaxIslandAppIcons / 2);
    }
    g_islandAppIcons.push_back({key, icon});
    return icon;
}

void FreeIslandAppIcons() {
    for (const auto& [id, icon] : g_islandAppIcons) {
        if (icon) {
            DestroyIcon(icon);
        }
    }
    g_islandAppIcons.clear();
}

// A window brought back from minimized (see ActivateApp), checked a few
// times after: some (consoles) stay minimized at first.
thread_local HWND t_restoreWindow;
thread_local int t_restoreTries;
thread_local UINT_PTR t_restoreTimer;

void CALLBACK RestoreCheckProc(HWND, UINT, UINT_PTR, DWORD) {
    const HWND hWnd = t_restoreWindow;
    if (!IsWindow(hWnd) || !IsIconic(hWnd) || ++t_restoreTries > 3) {
        KillTimer(nullptr, t_restoreTimer);
        t_restoreTimer = 0;
        t_restoreWindow = nullptr;
        return;
    }
    // Asked the way its own title bar does, then directly (not when it
    // doesn't answer: that would wait for it).
    if (t_restoreTries == 1) {
        PostMessage(hWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
    } else if (!IsHungAppWindow(hWnd)) {
        ShowWindow(hWnd, SW_RESTORE);
    }
}

// Brings a window to the front: first the right to (the island or the
// taskbar was just clicked), then restored if minimized. Restored first, a
// console window could end up active but still minimized.
void ActivateApp(HWND hWnd) {
    if (!IsWindow(hWnd)) {
        return;
    }
    HWND popup = GetLastActivePopup(hWnd);
    SetForegroundWindow(popup && IsWindowVisible(popup) ? popup : hWnd);
    if (IsIconic(hWnd)) {
        ShowWindowAsync(hWnd, SW_RESTORE);
        t_restoreWindow = hWnd;
        t_restoreTries = 0;
        if (t_restoreTimer) {
            KillTimer(nullptr, t_restoreTimer);
        }
        t_restoreTimer = SetTimer(nullptr, 0, 150, RestoreCheckProc);
    }
}

// Whether a window belongs to the app with this AppUserModelID. Apps without
// one of their own are told apart by their program file, which the taskbar
// then uses as their ID.
bool WindowMatchesApp(HWND hWnd, const std::wstring& appId) {
    const std::wstring id = GetWindowAppId(hWnd);
    if (!id.empty()) {
        return _wcsicmp(id.c_str(), appId.c_str()) == 0;
    }
    // (An app that sets its ID on its process, like Discord: as the taskbar
    // works it out.)
    if (appId.find(L'\\') == std::wstring::npos) {
        return _wcsicmp(TaskbarAppIdOfWindow(hWnd).c_str(), appId.c_str()) ==
               0;
    }
    DWORD processId = 0;
    GetWindowThreadProcessId(hWnd, &processId);
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (!process) {
        return false;
    }
    WCHAR path[MAX_PATH];
    DWORD length = ARRAYSIZE(path);
    const bool matches =
        QueryFullProcessImageName(process, 0, path, &length) &&
        _wcsicmp(path, appId.c_str()) == 0;
    CloseHandle(process);
    return matches;
}

// Looking for an app's window.
struct AppWindowSearch {
    const std::wstring* appId;
    HWND found;
};

BOOL CALLBACK FindAppWindowProc(HWND hWnd, LPARAM lParam) {
    auto* context = reinterpret_cast<AppWindowSearch*>(lParam);
    if (!IsWindowVisible(hWnd) || GetWindow(hWnd, GW_OWNER) ||
        (GetWindowLongPtr(hWnd, GWL_EXSTYLE) & WS_EX_TOOLWINDOW)) {
        return TRUE;
    }
    if (WindowMatchesApp(hWnd, *context->appId)) {
        context->found = hWnd;
        return FALSE;
    }
    return TRUE;
}

// An app's window with a button of its own, told apart as the taskbar does
// (see WindowMatchesApp), or nullptr.
HWND FindTaskbarAppWindow(const std::wstring& appId) {
    AppWindowSearch search{&appId, nullptr};
    EnumWindows(FindAppWindowProc, reinterpret_cast<LPARAM>(&search));
    return search.found;
}

// Whether a process runs elevated (`unknown` when it can't be told).
bool ProcessElevated(DWORD processId, bool unknown = true) {
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    HANDLE token = nullptr;
    TOKEN_ELEVATION elevation{};
    DWORD size = 0;
    const bool known =
        process && OpenProcessToken(process, TOKEN_QUERY, &token) &&
        GetTokenInformation(token, TokenElevation, &elevation,
                            sizeof(elevation), &size);
    if (token) {
        CloseHandle(token);
    }
    if (process) {
        CloseHandle(process);
    }
    return known ? elevation.TokenIsElevated != 0 : unknown;
}

// Whether explorer runs elevated: with UAC off, every process does. (Only
// when read as elevated: it lifts the block on elevated tray icons' owners.)
bool ExplorerElevated() {
    DWORD explorer = 0;
    return GetWindowThreadProcessId(FindTaskbarWnd(), &explorer) &&
           ProcessElevated(explorer, false);
}

// CLSID_ShellWindows and SID_STopLevelBrowser.
constexpr GUID kCLSID_ShellWindows = {
    0x9ba05972,
    0xf6a8,
    0x11cf,
    {0xa4, 0x42, 0x00, 0xa0, 0xc9, 0x0a, 0x8f, 0x39}};
constexpr GUID kSID_STopLevelBrowser = {
    0x4c96be40,
    0x915c,
    0x11cf,
    {0x99, 0xd3, 0x00, 0xaa, 0x00, 0x4a, 0xe8, 0x37}};

// A program, file or app (shell:AppsFolder\...) started by Explorer's own
// shell, as the user and unelevated: the desktop's view, its shell's
// IShellDispatch2::ShellExecute (see "How can I launch an unelevated
// process from my elevated process", The Old New Thing). On a thread with
// COM. False if it can't be.
bool ShellExecuteAsUser(const std::wstring& target) {
    winrt::com_ptr<IShellWindows> windows;
    winrt::com_ptr<IDispatch> desktop;
    VARIANT none;
    VariantInit(&none);
    long found = 0;
    if (FAILED(CoCreateInstance(kCLSID_ShellWindows, nullptr, CLSCTX_ALL,
                                IID_PPV_ARGS(windows.put()))) ||
        windows->FindWindowSW(&none, &none, SWC_DESKTOP, &found,
                              SWFO_NEEDDISPATCH, desktop.put()) != S_OK ||
        !desktop) {
        return false;
    }
    winrt::com_ptr<IShellBrowser> browser;
    winrt::com_ptr<IShellView> view;
    winrt::com_ptr<IDispatch> background;
    winrt::com_ptr<IDispatch> application;
    const auto provider = desktop.try_as<IServiceProvider>();
    if (!provider ||
        FAILED(provider->QueryService(kSID_STopLevelBrowser,
                                      IID_PPV_ARGS(browser.put()))) ||
        FAILED(browser->QueryActiveShellView(view.put())) ||
        FAILED(view->GetItemObject(SVGIO_BACKGROUND,
                                   IID_PPV_ARGS(background.put())))) {
        return false;
    }
    const auto folderView = background.try_as<IShellFolderViewDual>();
    if (!folderView || FAILED(folderView->get_Application(application.put()))) {
        return false;
    }
    const auto shell = application.try_as<IShellDispatch2>();
    if (!shell) {
        return false;
    }
    BSTR file = SysAllocString(target.c_str());
    VARIANT show;
    VariantInit(&show);
    show.vt = VT_I4;
    show.lVal = SW_SHOWNORMAL;
    const HRESULT hr =
        file ? shell->ShellExecute(file, none, none, none, show)
             : E_OUTOFMEMORY;
    SysFreeString(file);
    return SUCCEEDED(hr);
}

// Brings an app to the front by its AppUserModelID: its window if it has one
// (restored if minimized), otherwise it's started, or brought back from the
// tray, through the shell. With Windhawk run as administrator, the island
// never starts it itself: the ID comes from explorer.exe's message, which a
// lower process can send too, and what the island starts would run
// elevated; Explorer starts it, as the user (see ShellExecuteAsUser).
void OpenApp(const std::wstring& appId) {
    if (appId.empty()) {
        return;
    }
    AppWindowSearch context{&appId, nullptr};
    EnumWindows(
        FindAppWindowProc,
        (LPARAM)&context);
    if (context.found) {
        ActivateApp(context.found);
        return;
    }
    const std::wstring target = appId.find(L'\\') != std::wstring::npos
                                    ? appId
                                    : L"shell:AppsFolder\\" + appId;
    static const bool elevated = ProcessElevated(GetCurrentProcessId());
    if (elevated) {
        if (!ShellExecuteAsUser(target)) {
            IslandLog(L"An app couldn't be started through Explorer");
        }
        return;
    }
    ShellExecute(nullptr, L"open", target.c_str(), nullptr, nullptr,
                 SW_SHOWNORMAL);
}

LRESULT CALLBACK AttentionWndProc(HWND hWnd,
                                  UINT uMsg,
                                  WPARAM wParam,
                                  LPARAM lParam) {
    switch (uMsg) {
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
        case WM_LBUTTONDOWN:
            g_attentionClicked = true;
            return 0;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// Whether the app is the one in front, so it doesn't need the icon.
bool IsAppInFront(const AttentionRequest& request) {
    HWND foreground = GetForegroundWindow();
    if (request.app) {
        return foreground == request.app;
    }
    return !request.appId.empty() &&
           GetWindowAppId(foreground) == request.appId;
}

// Shows the app's icon peeking out and bouncing, then hides it. Returns false
// if the thread should quit.
bool RunAttentionIcon(HWND window, const AttentionRequest& request) {
    static std::wstring lastKey;
    static double lastEnd;

    const HWND app = request.app;
    const std::wstring key =
        app ? L"#" + std::to_wstring((ULONG_PTR)app) : request.appId;
    if (g_settings.attentionMode != AttentionMode::Icon ||
        (app && !IsWindow(app)) || (!app && request.appId.empty()) ||
        IsAppInFront(request) ||
        (key == lastKey && NowSeconds() - lastEnd < kAttentionRepeatDelay)) {
        return true;
    }

    HWND taskbar = FindCurrentProcessTaskbarWnd();
    MONITORINFO monitor{sizeof(monitor)};
    if (!taskbar || !GetMonitorInfo(TaskbarMonitor(taskbar), &monitor)) {
        return true;
    }
    // With the dock on screen, the icon bounces in it instead. Full-screen
    // apps aren't disturbed.
    if (!IsTaskbarHidden(taskbar, monitor.rcMonitor) ||
        (g_settings.fullscreenGuard && IsFullscreenAppOnMonitor(taskbar))) {
        return true;
    }

    // Above the app's button, measured by the taskbar when the app started
    // asking for attention. That can come a little after this.
    const double asked = NowSeconds();
    int centerX = (monitor.rcMonitor.left + monitor.rcMonitor.right) / 2;
    for (int i = 0; i < 30; i++) {
        if (g_attentionButtonTime >= asked - 1.0) {
            centerX = g_attentionButtonX;
            break;
        }
        Sleep(10);
    }

    const UINT dpi = GetDpiForWindow(taskbar);
    const int iconSize = MulDiv(kAttentionIconSize, dpi, 96);
    const int bounceHeight = MulDiv(kAttentionBounceHeight, dpi, 96);
    const int restGap = MulDiv(kAttentionRestGap, dpi, 96);

    HBITMAP icon = LoadAppIconBitmap(app, request.appId, iconSize);
    if (!icon) {
        return true;
    }
    BITMAP iconInfo{};
    GetObject(icon, sizeof(iconInfo), &iconInfo);

    const SIZE size{iconSize, iconSize + bounceHeight + restGap};
    const POINT position{centerX - size.cx / 2,
                         monitor.rcMonitor.bottom - size.cy};
    // The icon's top edge, in the window: hidden below it, and resting.
    const double hiddenTop = size.cy;
    const double restTop = size.cy - restGap - iconSize;

    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = size.cx;
    info.bmiHeader.biHeight = -size.cy;  // Top-down.
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HDC screen = GetDC(nullptr);
    HDC canvas = CreateCompatibleDC(screen);
    HDC iconDc = CreateCompatibleDC(screen);
    HBITMAP canvasBitmap =
        CreateDIBSection(screen, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    ReleaseDC(nullptr, screen);
    if (!canvas || !iconDc || !canvasBitmap) {
        if (canvasBitmap) {
            DeleteObject(canvasBitmap);
        }
        if (canvas) {
            DeleteDC(canvas);
        }
        if (iconDc) {
            DeleteDC(iconDc);
        }
        DeleteObject(icon);
        return true;
    }
    HGDIOBJ oldCanvas = SelectObject(canvas, canvasBitmap);
    HGDIOBJ oldIcon = SelectObject(iconDc, icon);

    const BLENDFUNCTION blend{AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    g_attentionClicked = false;
    bool keepRunning = true;
    bool shown = false;
    FrameTimer frames;
    const double start = NowSeconds();
    // When it starts going back, once the bounces are over or it's not needed
    // anymore.
    double sinkStart = 0;
    // The app in front is only looked up when the foreground window changes.
    HWND lastForeground = nullptr;
    bool appInFront = false;

    for (;;) {
        const double now = NowSeconds();
        if (HWND foreground = GetForegroundWindow();
            foreground != lastForeground) {
            lastForeground = foreground;
            appInFront = IsAppInFront(request);
        }
        if (!sinkStart &&
            (g_attentionClicked || appInFront ||
             !IsTaskbarHidden(taskbar, monitor.rcMonitor) || g_unloading)) {
            if (g_attentionClicked) {
                if (app) {
                    ActivateApp(app);
                } else {
                    OpenApp(request.appId);
                }
            }
            sinkStart = now;
        }

        double top;
        const double elapsed = now - start;
        if (!sinkStart && elapsed < kAttentionRiseTime) {
            top = hiddenTop + (restTop - hiddenTop) *
                                  SpringOut(elapsed / kAttentionRiseTime);
        } else if (!sinkStart) {
            bool done;
            const double height =
                BounceSequence(elapsed - kAttentionRiseTime,
                               kAttentionBounceGroups, &done);
            top = restTop - bounceHeight * height;
            if (done) {
                sinkStart = now;
            }
        } else {
            const double t = std::min((now - sinkStart) / kAttentionSinkTime, 1.0);
            top = restTop + (hiddenTop - restTop) * EaseInOutCubic(t);
            if (t >= 1) {
                break;
            }
        }

        ZeroMemory(bits, size.cx * size.cy * 4);
        AlphaBlend(canvas, 0, (int)std::lround(top), iconSize, iconSize, iconDc,
                   0, 0, iconInfo.bmWidth, std::abs(iconInfo.bmHeight), blend);
        POINT source{0, 0};
        UpdateLayeredWindow(window, nullptr, (POINT*)&position, (SIZE*)&size,
                            canvas, &source, 0, (BLENDFUNCTION*)&blend,
                            ULW_ALPHA);
        if (!shown) {
            SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE |
                             SWP_SHOWWINDOW);
            shown = true;
        }

        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                keepRunning = false;
                break;
            }
            // Another app asking meanwhile is skipped.
            if (msg.message == WM_APP_ATTENTION && !msg.hwnd) {
                delete (AttentionRequest*)msg.lParam;
                continue;
            }
            DispatchMessage(&msg);
        }
        if (!keepRunning) {
            break;
        }
        WaitForAnimationFrame(frames);
    }

    ShowWindow(window, SW_HIDE);
    SelectObject(iconDc, oldIcon);
    SelectObject(canvas, oldCanvas);
    DeleteObject(canvasBitmap);
    DeleteDC(iconDc);
    DeleteDC(canvas);
    DeleteObject(icon);

    lastKey = key;
    lastEnd = NowSeconds();
    return keepRunning;
}

DWORD WINAPI AttentionThreadProc(LPVOID parameter) {
    // Create the message queue before the creator continues.
    MSG msg;
    PeekMessage(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    SetEvent((HANDLE)parameter);

    SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    const HRESULT comResult =
        CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    WNDCLASS windowClass{};
    windowClass.lpfnWndProc = AttentionWndProc;
    windowClass.hInstance = g_module;
    windowClass.hCursor = LoadCursor(nullptr, IDC_HAND);
    windowClass.lpszClassName = kAttentionClassName;
    RegisterClass(&windowClass);

    HWND window = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
        kAttentionClassName, L"", WS_POPUP, 0, 0, 0, 0, nullptr, nullptr,
        g_module, nullptr);
    if (!window) {
        IslandLog(L"CreateWindowEx failed: %u", GetLastError());
    }

    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        if (msg.message == WM_APP_ATTENTION && !msg.hwnd) {
            std::unique_ptr<AttentionRequest> request{
                (AttentionRequest*)msg.lParam};
            if (window && !RunAttentionIcon(window, *request)) {
                break;
            }
            continue;
        }
        DispatchMessage(&msg);
    }

    // Requests that came in after the end.
    while (PeekMessage(&msg, nullptr, WM_APP_ATTENTION, WM_APP_ATTENTION,
                       PM_REMOVE)) {
        if (!msg.hwnd) {
            delete (AttentionRequest*)msg.lParam;
        }
    }

    if (window) {
        DestroyWindow(window);
    }
    UnregisterClass(kAttentionClassName, g_module);
    if (SUCCEEDED(comResult)) {
        CoUninitialize();
    }
    return 0;
}

void StartAttentionThread() {
    if (g_attentionThread || !OwnsTaskbar()) {
        return;
    }
    GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                          GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                      (LPCWSTR)&AttentionWndProc, &g_module);
    HANDLE started = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (!started) {
        return;
    }
    g_attentionThread = CreateThread(nullptr, 0, AttentionThreadProc, started,
                                     0, &g_attentionThreadId);
    if (g_attentionThread) {
        WaitForSingleObject(started, INFINITE);
    } else {
        g_attentionThreadId = 0;
    }
    CloseHandle(started);
}

void StopAttentionThread() {
    if (!g_attentionThread) {
        return;
    }
    PostThreadMessage(g_attentionThreadId, WM_QUIT, 0, 0);
    WaitForSingleObject(g_attentionThread, INFINITE);
    CloseHandle(g_attentionThread);
    g_attentionThread = nullptr;
    g_attentionThreadId = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Auto-hide.

bool SetAutoHide(bool on) {
    APPBARDATA data{sizeof(data)};
    data.hWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (!data.hWnd) {
        return false;
    }
    const UINT state = (UINT)SHAppBarMessage(ABM_GETSTATE, &data);
    if (((state & ABS_AUTOHIDE) != 0) != on) {
        data.lParam = on ? (state | ABS_AUTOHIDE) : (state & ~ABS_AUTOHIDE);
        // ABM_SETSTATE always returns TRUE. Read back the actual state,
        // rather than forgetting ownership when the shell rejected it.
        SHAppBarMessage(ABM_SETSTATE, &data);
    }
    return IsWindow(data.hWnd) &&
           (((SHAppBarMessage(ABM_GETSTATE, &data) & ABS_AUTOHIDE) != 0) == on);
}

// Another app's auto-hide bar on the taskbar's edge (a dock, a launcher, a
// taskbar tool), or null: Windows allows one per side and answers the
// taskbar's own with a dialog ("only one auto-hide toolbar per side").
HWND OtherAutoHideBar(HWND taskbar) {
    APPBARDATA position{sizeof(position)};
    position.hWnd = taskbar;
    if (!SHAppBarMessage(ABM_GETTASKBARPOS, &position)) {
        return nullptr;
    }
    MONITORINFO monitor{sizeof(monitor)};
    if (!GetMonitorInfo(MonitorFromRect(&position.rc, MONITOR_DEFAULTTONEAREST),
                        &monitor)) {
        return nullptr;
    }
    APPBARDATA asked{sizeof(asked)};
    asked.uEdge = position.uEdge;
    asked.rc = monitor.rcMonitor;
    HWND bar = (HWND)SHAppBarMessage(ABM_GETAUTOHIDEBAREX, &asked);
    if (!bar || !IsWindow(bar)) {
        return nullptr;
    }
    WCHAR className[64] = L"";
    GetClassName(bar, className, ARRAYSIZE(className));
    return _wcsicmp(className, L"Shell_TrayWnd") == 0 ||
                   _wcsicmp(className, L"Shell_SecondaryTrayWnd") == 0
               ? nullptr
               : bar;
}

// A persisted flag means the user's original setting was OFF. Set it before
// changing Windows and clear it only after a confirmed restoration. If the
// user already had auto-hide on, the mod never takes ownership of it.
void UpdateAutoHide() {
    if (!OwnsTaskbar()) {
        return;
    }
    g_turnedAutoHideOn = g_turnedAutoHideOn ||
        GetUserIntValue(L"turnedAutoHideOn", 0) != 0;
    if (WantsAutoHide() && !g_unloading) {
        SetUserIntValue(L"explorerPartPid", (int)GetCurrentProcessId());
        APPBARDATA data{sizeof(data)};
        data.hWnd = FindCurrentProcessTaskbarWnd();
        if (!(SHAppBarMessage(ABM_GETSTATE, &data) & ABS_AUTOHIDE)) {
            // (Another app's auto-hide bar there: Windows would refuse with
            // its dialog; the taskbar stays as it is, and the log says
            // whose it is.)
            if (HWND other = OtherAutoHideBar(data.hWnd)) {
                WCHAR className[64] = L"";
                GetClassName(other, className, ARRAYSIZE(className));
                DWORD processId = 0;
                GetWindowThreadProcessId(other, &processId);
                IslandLog(L"Another app's auto-hide bar is on the taskbar's "
                          L"edge (%s, process %u): the taskbar's auto-hide "
                          L"is left as it is",
                          className, (unsigned)processId);
                return;
            }
            g_turnedAutoHideOn = true;
            SetUserIntValue(L"turnedAutoHideOn", 1);
            if (!SetAutoHide(true)) {
                IslandLog(L"The taskbar auto-hide setting could not be applied");
            }
        }
    } else if (g_turnedAutoHideOn) {
        if (SetAutoHide(false)) {
            g_turnedAutoHideOn = false;
            SetUserIntValue(L"turnedAutoHideOn", 0);
        } else {
            IslandLog(L"Taskbar auto-hide restoration is still pending");
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Mod lifetime.

bool HookTaskbarDllSymbols() {
    HMODULE module =
        LoadLibraryEx(L"taskbar.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!module) {
        IslandLog(L"Failed to load taskbar.dll");
        return false;
    }

    WindhawkUtils::SYMBOL_HOOK taskbarDllHooks[] = {
        {
            {LR"(const CTaskBand::`vftable'{for `ITaskListWndSite'})"},
            &CTaskBand_ITaskListWndSite_vftable,
        },
        {
            {LR"(const CSecondaryTaskBand::`vftable'{for `ITaskListWndSite'})"},
            &CSecondaryTaskBand_ITaskListWndSite_vftable,
        },
        {
            {LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CTaskBand::GetTaskbarHost(void)const )"},
            &CTaskBand_GetTaskbarHost_Original,
        },
        {
            {LR"(public: int __cdecl TaskbarHost::FrameHeight(void)const )"},
            &TaskbarHost_FrameHeight_Original,
        },
        {
            {LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CSecondaryTaskBand::GetTaskbarHost(void)const )"},
            &CSecondaryTaskBand_GetTaskbarHost_Original,
        },
        {
            {LR"(public: void __cdecl std::_Ref_count_base::_Decref(void))"},
            &std__Ref_count_base__Decref_Original,
        },
        {
            {LR"(public: virtual void __cdecl TrayUI::StartTaskbar(void))"},
            &TrayUI_StartTaskbar_Original,
            TrayUI_StartTaskbar_Hook,
        },
        {
            {LR"(public: virtual struct HWND__ * __cdecl CSecondaryTray::GetTrayWindow(void))"},
            &CSecondaryTray_GetTrayWindow_Original,
        },
        {
            {LR"(public: virtual void __cdecl CSecondaryTray::InitModelAndHost(struct winrt::WindowsUdk::UI::Shell::TaskbarModel))"},
            &CSecondaryTray_InitModelAndHost_Original,
            CSecondaryTray_InitModelAndHost_Hook,
        },
        {
            {LR"(public: virtual void __cdecl TrayUI::SlideWindow(struct HWND__ *,struct tagRECT const *,struct HMONITOR__ *,bool,bool))"},
            &TrayUI_SlideWindow_Original,
            TrayUI_SlideWindow_Hook,
        },
        // Without it, the shown dock stays up with the mouse beside it.
        {
            {LR"(public: bool __cdecl TrayUI::_ShouldAutoHideTray(class AutoHideTelemetry::TaskbarAutoHideTelemetry::AutoHideOnTaskbarHide))"},
            &TrayUI__ShouldAutoHideTray_Original,
            TrayUI__ShouldAutoHideTray_Hook,
            true,
        },
        // Without these, a taskbar may still come up for an instant when an
        // app asks for attention (SlideWindow sends it back down).
        {
            {LR"(public: virtual void __cdecl TrayUI::Unhide(enum TrayCommon::TrayUnhideFlags,enum TrayCommon::UnhideRequest))"},
            &TrayUI_Unhide_Original,
            TrayUI_Unhide_Hook,
            true,
        },
        {
            {LR"(public: virtual long __cdecl CTaskBand::UnhideTray(void))"},
            &CTaskBand_UnhideTray_Original,
            CTaskBand_UnhideTray_Hook,
            true,
        },
        {
            {LR"(public: virtual long __cdecl CSecondaryTaskBand::UnhideTray(void))"},
            &CSecondaryTaskBand_UnhideTray_Original,
            CSecondaryTaskBand_UnhideTray_Hook,
            true,
        },
        {
            {LR"(public: virtual int __cdecl CTaskListWnd::PermitAutoHide(void))"},
            &CTaskListWnd_PermitAutoHide_Original,
            CTaskListWnd_PermitAutoHide_Hook,
            // Without it, the taskbar just shows itself for attention as
            // usual.
            true,
        },
        // Without these, the pill doesn't fill with downloads (see
        // PublishProgress).
        {
            {LR"(protected: void __cdecl CTaskBand::_OnSetProgressState(struct HWND__ * const,enum TBPFLAG))"},
            &CTaskBand__OnSetProgressState_Original,
            CTaskBand__OnSetProgressState_Hook,
            true,
        },
        {
            {LR"(protected: void __cdecl CTaskBand::_OnSetProgressValue(struct HWND__ * const,unsigned long))"},
            &CTaskBand__OnSetProgressValue_Original,
            CTaskBand__OnSetProgressValue_Hook,
            true,
        },
        // Without these, apps' overlay icons (like Discord's counter) don't
        // count as badges and stay as the taskbar draws them.
        {
            {LR"(protected: void __cdecl CTaskBand::_HandleOverlayIcon(struct HWND__ *,struct HICON__ *))"},
            &CTaskBand__HandleOverlayIcon_Original,
            CTaskBand__HandleOverlayIcon_Hook,
            true,
        },
        {
            {LR"(protected: void __cdecl CTaskBand::_HandleOverlayIconDescription(struct HWND__ *,void *))"},
            &CTaskBand__HandleOverlayIconDescription_Original,
            CTaskBand__HandleOverlayIconDescription_Hook,
            true,
        },
        {
            {LR"(public: virtual long __cdecl CTaskItem::SetOverlayIconDescription(unsigned short const *))"},
            &CTaskItem_SetOverlayIconDescription_Original,
            CTaskItem_SetOverlayIconDescription_Hook,
            true,
        },
        // Without these, an overlay icon set before the mod started stays as
        // the taskbar draws it until it changes (see ReadOverlayIcons).
        {
            {LR"(const CTaskBand::`vftable'{for `ITaskListManager'})"},
            &CTaskBand_ITaskListManager_vftable,
            nullptr,
            true,
        },
        {
            {LR"(const CWindowTaskItem::`vftable'{for `ITaskItem'})"},
            &CWindowTaskItem_ITaskItem_vftable,
            nullptr,
            true,
        },
        {
            {LR"(const CImmersiveTaskItem::`vftable'{for `ITaskItem'})"},
            &CImmersiveTaskItem_ITaskItem_vftable,
            nullptr,
            true,
        },
        {
            {LR"(public: virtual long __cdecl CTaskBand::GetTaskFromWindow(struct HWND__ *,struct ITaskGroup * *,struct ITaskItem * *))"},
            &CTaskBand_GetTaskFromWindow_Original,
            nullptr,
            true,
        },
        {
            {LR"(public: virtual struct HICON__ * __cdecl CTaskItem::GetOverlayIcon(void))"},
            &CTaskItem_GetOverlayIcon_Original,
            nullptr,
            true,
        },
        {
            {LR"(public: virtual unsigned short const * __cdecl CTaskItem::GetOverlayIconDescription(void))"},
            &CTaskItem_GetOverlayIconDescription_Original,
            nullptr,
            true,
        },
        // Without these, a taskbar hidden for a window in its way
        // (hiding.hideWhen) comes back only with the mouse at the bottom
        // edge (see UnhideTaskbar).
        {
            {LR"(const TrayUI::`vftable'{for `ITrayComponentHost'})"},
            &TrayUI_ITrayComponentHost_vftable,
            nullptr,
            true,
        },
        {
            {LR"(public: virtual __int64 __cdecl TrayUI::WndProc(struct HWND__ *,unsigned int,unsigned __int64,__int64,bool *))"},
            &TrayUI_WndProc_Original,
            TrayUI_WndProc_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl CSecondaryTray::_Unhide(enum TrayCommon::TrayUnhideFlags,enum TrayCommon::UnhideRequest))"},
            &CSecondaryTray__Unhide_Original,
            nullptr,
            true,
        },
        {
            {LR"(private: virtual __int64 __cdecl CSecondaryTray::v_WndProc(struct HWND__ *,unsigned int,unsigned __int64,__int64))"},
            &CSecondaryTray_v_WndProc_Original,
            CSecondaryTray_v_WndProc_Hook,
            true,
        },
    };

    if (!HookSymbols(module, taskbarDllHooks, ARRAYSIZE(taskbarDllHooks))) {
        IslandLog(L"HookSymbols failed");
        return false;
    }
    return true;
}

void LoadSettings() {
    LoadTheme();
    LoadAnimationSettings();
    // Dock-only mod: always the dock, never the island.
    g_settings.taskbarMode = decltype(g_settings.taskbarMode)::Dock;
    g_settings.showIsland = false;
    // The dock is made for the bottom: with the taskbar elsewhere, it stays
    // as Windows has it until it's back at the bottom (see WatchTaskbarPlace).
    g_taskbarAtBottom = IsTaskbarAtBottom();
    if (!g_taskbarAtBottom) {
        IslandLog(L"The taskbar isn't at the bottom: leaving it as it is");
        g_settings.taskbarMode = decltype(g_settings.taskbarMode)::Windows;
    }
    g_settings.autoHide = Wh_GetIntSetting(L"hiding.autoHide") != 0;
    g_settings.cornerRadius =
        std::clamp(Wh_GetIntSetting(L"dock.cornerRadius"), 0, 32);
    g_settings.dockIconSize =
        std::clamp(Wh_GetIntSetting(L"dock.iconSize"), 24, 64);
    g_settings.dockIconGap =
        std::clamp(Wh_GetIntSetting(L"dock.iconGap"), 0, 32);
    g_settings.bottomGap = std::clamp(Wh_GetIntSetting(L"dock.bottomGap"), 0, 24);
    g_settings.dockIslandStyle = Wh_GetIntSetting(L"dock.islandStyle") != 0;
    g_settings.dockPinButton = Wh_GetIntSetting(L"dock.pinButton") != 0;
    if (g_settings.dockIslandStyle) {
        g_settings.bottomGap = 0;
    }
    g_settings.dockBackground = Wh_GetIntSetting(L"dock.background") != 0;
    g_settings.backgroundOpacity =
        std::clamp(Wh_GetIntSetting(L"dock.backgroundOpacity"), 0, 100) / 100.0;
    g_settings.showDuration =
        std::clamp(Wh_GetIntSetting(L"hiding.showDuration"), 0, 1000);
    g_settings.hideDuration =
        std::clamp(Wh_GetIntSetting(L"hiding.hideDuration"), 0, 1000);
    g_settings.showDelay = std::clamp(Wh_GetIntSetting(L"hiding.showDelay"), 0, 2000);
    g_settings.hideDelay = std::clamp(Wh_GetIntSetting(L"hiding.hideDelay"), 0, 5000);
    {
        const auto hideWhen =
            WindhawkUtils::StringSetting::make(L"hiding.hideWhen");
        g_settings.hideWhen = wcscmp(hideWhen, L"maximized") == 0    ? 1
                              : wcscmp(hideWhen, L"windowOver") == 0 ? 2
                                                                    : 0;
    }
    g_settings.revealHeight =
        std::clamp(Wh_GetIntSetting(L"hiding.revealHeight"), 0, 120);
    g_settings.fullscreenGuard = Wh_GetIntSetting(L"hiding.fullscreenGuard") != 0;
    g_settings.hideTray = Wh_GetIntSetting(L"dock.hideTray") != 0;
    g_settings.magnification =
        std::clamp(Wh_GetIntSetting(L"icons.magnification"), 100, 200) / 100.0;
    g_settings.magnificationRange =
        std::clamp(Wh_GetIntSetting(L"icons.magnificationRange"), 40, 300);
    g_settings.onlyAppsEffects = Wh_GetIntSetting(L"icons.onlyApps") != 0;
    {
        const int widest = Wh_GetIntSetting(L"dock.maxWidth");
        g_settings.dockMaxWidth = widest <= 0 ? 0 : std::clamp(widest, 30, 100);
    }
    g_settings.bounceOnLaunch = Wh_GetIntSetting(L"icons.bounceOnLaunch") != 0;
    g_settings.keepOpenOnLaunch = Wh_GetIntSetting(L"icons.keepOpenOnLaunch") != 0;
    g_settings.keepOpenDuration =
        std::clamp(Wh_GetIntSetting(L"icons.keepOpenDuration"), 0, 5000);
    g_settings.dotIndicator = Wh_GetIntSetting(L"dock.dotIndicator") != 0;
    g_settings.dockSeparator = Wh_GetIntSetting(L"dock.separator") != 0;
    // Options that only work with another one: as if off without it.
    if (!g_settings.autoHide) {
        g_settings.keepOpenOnLaunch = false;
    }
    const auto attentionMode =
        WindhawkUtils::StringSetting::make(L"dock.attentionMode");
    g_settings.attentionMode = wcscmp(attentionMode, L"dock") == 0
                                   ? AttentionMode::Dock
                               : wcscmp(attentionMode, L"none") == 0
                                   ? AttentionMode::None
                                   : AttentionMode::Icon;
}

////////////////////////////////////////////////////////////////////////////////
// The explorer.exe part: the dock, and what the taskbar knows for the island.

BOOL ExplorerModInit() {
    IslandLog(L">");

    LoadSettings();
    // Turned on by the mod before Explorer last stopped (maybe a crash).
    g_turnedAutoHideOn = GetUserIntValue(L"turnedAutoHideOn", 0) != 0;

    if (!HookTaskbarDllSymbols()) {
        return FALSE;
    }

    WindhawkUtils::SetFunctionHook(SetTimer, SetTimer_Hook,
                                   &SetTimer_Original);
    return TRUE;
}

void ExplorerModAfterInit() {
    IslandLog(L">");

    g_shellHookMessage = RegisterWindowMessage(L"SHELLHOOK");
    StartAttentionThread();
    ApplySettings();
    SubclassTaskbars();
    UpdateAutoHide();
    RefreshDockRoom();
    StartEdgeWatch();
    ReadOverlayIcons();
    StartLateStart();
    StartJumpListMove();
    StartPinnedBars();
}

void ExplorerModBeforeUninit() {
    IslandLog(L">");

    g_unloading = true;
    StopJumpListMove();
    StopPinnedBars();
    StopWatchingTaskbarPlace();
    StopLateStart();
    StopEdgeWatch();
    StopAttentionThread();
    // Restore Windows before XAML cleanup, even if a retired element fails.
    UpdateAutoHide();
    StopBigIcons();
    ApplySettings();
    // (Stopped by the settings' apply on the taskbars' thread, which also
    // starts their hide timers again; here too in case it didn't run.)
    StopTaskbarWayThread();
    UnsubclassTaskbars();
    // (One may have started in the subclass meanwhile.)
    StopWatchingTaskbarPlace();
    FreeIslandAppIcons();
    if (GetUserIntValue(L"explorerPartPid", 0) == (int)GetCurrentProcessId()) {
        SetUserIntValue(L"explorerPartPid", 0);
    }
}

// The taskbar moved to another edge: once it has settled, the settings
// apply again (the dock goes away, or comes back at the bottom). On a thread
// of its own, since applying them waits for the taskbar's thread.
HANDLE g_taskbarPlaceThread;
HANDLE g_taskbarPlaceStop;
// (Started on the taskbar's thread, stopped by the unloading one. The lock
// only guards the handles: the thread is waited for outside it, since it may
// be sending to the taskbar's thread, which may be waiting for the lock.)
SRWLOCK g_taskbarPlaceLock = SRWLOCK_INIT;

void ExplorerModSettingsChanged();

// (Its stop event is its parameter.)
DWORD WINAPI TaskbarPlaceThreadProc(LPVOID parameter) {
    // (Soon: the dock's look on a taskbar at another edge makes Windows lay
    // it out wrong, see GrowTaskbarWindow.)
    if (WaitForSingleObject((HANDLE)parameter, 150) == WAIT_TIMEOUT &&
        !g_unloading && IsTaskbarAtBottom() != g_taskbarAtBottom) {
        ExplorerModSettingsChanged();
    }
    return 0;
}

void StopWatchingTaskbarPlace() {
    AcquireSRWLockExclusive(&g_taskbarPlaceLock);
    const HANDLE thread = std::exchange(g_taskbarPlaceThread, nullptr);
    const HANDLE stop = std::exchange(g_taskbarPlaceStop, nullptr);
    ReleaseSRWLockExclusive(&g_taskbarPlaceLock);
    if (thread) {
        SetEvent(stop);
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
    }
    if (stop) {
        CloseHandle(stop);
    }
}

// On the taskbar's thread (not once unloading has begun: g_unloading is set
// before the first StopWatchingTaskbarPlace, so none starts after it).
void WatchTaskbarPlace() {
    AcquireSRWLockExclusive(&g_taskbarPlaceLock);
    // (One that has ended is only closed.)
    if (g_taskbarPlaceThread &&
        WaitForSingleObject(g_taskbarPlaceThread, 0) == WAIT_OBJECT_0) {
        CloseHandle(std::exchange(g_taskbarPlaceThread, nullptr));
        CloseHandle(std::exchange(g_taskbarPlaceStop, nullptr));
    }
    if (!g_unloading && !g_taskbarPlaceThread) {
        g_taskbarPlaceStop = CreateEvent(nullptr, TRUE, FALSE, nullptr);
        if (g_taskbarPlaceStop) {
            g_taskbarPlaceThread =
                CreateThread(nullptr, 0, TaskbarPlaceThreadProc,
                             g_taskbarPlaceStop, 0, nullptr);
            if (!g_taskbarPlaceThread) {
                CloseHandle(std::exchange(g_taskbarPlaceStop, nullptr));
            }
        }
    }
    ReleaseSRWLockExclusive(&g_taskbarPlaceLock);
}

// Windhawk's settings change and the taskbar moving to another edge (see
// TaskbarPlaceThreadProc) apply them one at a time.
SRWLOCK g_explorerSettingsLock = SRWLOCK_INIT;

void ExplorerModSettingsChanged() {
    IslandLog(L">");

    AcquireSRWLockExclusive(&g_explorerSettingsLock);

    StopLateStart();
    LoadSettings();
    ApplySettings();
    SubclassTaskbars();
    UpdateAutoHide();
    // The bottom edge is only watched for the dock.
    StopEdgeWatch();
    StartEdgeWatch();
    StartLateStart();
    SyncPinnedBarsSoon();
    ReleaseSRWLockExclusive(&g_explorerSettingsLock);
}

////////////////////////////////////////////////////////////////////////////////
// Helpers the dock uses, kept from the island's part of the original mod.

// (The island's profiles and looks are gone: nothing to save or show.)
bool OwnLookShown() { return false; }
bool IsLookValue(PCWSTR) { return false; }
void SaveOwnLookSoon() {}
void SaveActiveProfileSoon() {}
// (No island process: never one to tell apart.)
DWORD g_islandProcessId = 0;

// Windows' dark mode (apps and the system), switched like its settings do:
// the two registry values, then telling the windows.
bool IsDarkMode() {
    DWORD light = 1;
    DWORD size = sizeof(light);
    RegGetValue(HKEY_CURRENT_USER,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\"
                L"Personalize",
                L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &light, &size);
    return light == 0;
}

// A known folder's path now (it moves with the user's choice), or "".
std::wstring KnownFolderPath(const GUID& folder) {
    PWSTR path = nullptr;
    std::wstring result;
    if (SUCCEEDED(SHGetKnownFolderPath(folder, 0, nullptr, &path))) {
        result = path;
    }
    CoTaskMemFree(path);
    return result;
}

// Whether a window in front is an app's own window, not one of its menus
// (Windows', or a popup without a title bar it owns, like a tray icon's
// menu drawn by the app) nor a hidden or tool window it takes the focus
// with for one.
bool IsAppWindow(HWND hWnd) {
    if (!IsWindowVisible(hWnd)) {
        return false;
    }
    WCHAR className[16] = L"";
    GetClassName(hWnd, className, ARRAYSIZE(className));
    if (wcscmp(className, L"#32768") == 0) {
        return false;
    }
    const LONG style = GetWindowLong(hWnd, GWL_STYLE);
    const LONG exStyle = GetWindowLong(hWnd, GWL_EXSTYLE);
    if ((exStyle & WS_EX_TOOLWINDOW) && !(exStyle & WS_EX_APPWINDOW)) {
        return false;
    }
    return !(GetWindow(hWnd, GW_OWNER) && (style & WS_POPUP) &&
             (style & WS_CAPTION) != WS_CAPTION);
}

// Whether a window is hidden by Windows (another virtual desktop, a
// suspended app).
bool IsCloakedWindow(HWND window) {
    BOOL cloaked = FALSE;
    return SUCCEEDED(DwmGetWindowAttribute(window, DWMWA_CLOAKED, &cloaked,
                                           sizeof(cloaked))) &&
           cloaked;
}

// A program's process in this session (its file's name), or 0 if it doesn't
// run.
DWORD SessionProcessId(PCWSTR exe) {
    DWORD session = 0;
    ProcessIdToSessionId(GetCurrentProcessId(), &session);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }
    DWORD found = 0;
    PROCESSENTRY32 entry{};
    entry.dwSize = sizeof(entry);
    for (BOOL more = Process32First(snapshot, &entry); more && !found;
         more = Process32Next(snapshot, &entry)) {
        DWORD its = 0;
        if (_wcsicmp(entry.szExeFile, exe) == 0 &&
            ProcessIdToSessionId(entry.th32ProcessID, &its) &&
            its == session) {
            found = entry.th32ProcessID;
        }
    }
    CloseHandle(snapshot);
    return found;
}

// A process's program file, or empty.
std::wstring ProcessImagePath(DWORD processId) {
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (!process) {
        return {};
    }
    std::wstring result;
    WCHAR path[MAX_PATH * 2];
    DWORD size = ARRAYSIZE(path);
    if (QueryFullProcessImageName(process, 0, path, &size)) {
        result.assign(path, size);
    }
    CloseHandle(process);
    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Windhawk entry points (explorer.exe only: no island).

BOOL Wh_ModInit() { return ExplorerModInit(); }
void Wh_ModAfterInit() { ExplorerModAfterInit(); }
void Wh_ModBeforeUninit() { ExplorerModBeforeUninit(); }
void Wh_ModSettingsChanged() { ExplorerModSettingsChanged(); }
void Wh_ModUninit() {}
