# Checks the dock's browser bridge (Windhawk mod running, dock.browserBridge
# on): an extension's origin gets in and can talk; a web page's is refused.
# Run with PowerShell 7: pwsh -File tools/bridge-test.ps1
$ErrorActionPreference = 'Stop'
$uri = [Uri]'ws://127.0.0.1:47821'
$failed = $false

function Connect([string]$origin) {
    $socket = [System.Net.WebSockets.ClientWebSocket]::new()
    $socket.Options.SetRequestHeader('Origin', $origin)
    $socket.ConnectAsync($uri, [Threading.CancellationToken]::None).Wait(5000) | Out-Null
    return $socket
}

function SendText($socket, [string]$text) {
    $bytes = [Text.Encoding]::UTF8.GetBytes($text)
    $socket.SendAsync([ArraySegment[byte]]::new($bytes),
        [System.Net.WebSockets.WebSocketMessageType]::Text, $true,
        [Threading.CancellationToken]::None).Wait(5000) | Out-Null
}

# (a) An extension: connects, says hello and sends a download, closes cleanly.
try {
    $socket = Connect 'chrome-extension://bridgetest'
    if ($socket.State -ne 'Open') { throw "state $($socket.State)" }
    SendText $socket '{"type":"hello","browser":"chrome","version":1}'
    SendText $socket ('{"type":"downloads","items":[{"id":1,"path":"C:\\Temp\\teste.zip",' +
        '"name":"teste.zip","bytes":500,"total":1000,"state":"in_progress","paused":false,"canResume":true}]}')
    Start-Sleep -Milliseconds 300
    $socket.CloseAsync([System.Net.WebSockets.WebSocketCloseStatus]::NormalClosure, 'bye',
        [Threading.CancellationToken]::None).Wait(5000) | Out-Null
    Write-Output 'OK accept'
} catch {
    Write-Output "FAIL accept: $($_.Exception.InnerException.Message ?? $_.Exception.Message)"
    $failed = $true
}

# (c) Wrongly typed fields: the dock (Explorer) must survive and keep talking.
try {
    $socket = Connect 'chrome-extension://bridgetest'
    SendText $socket '{"type":5}'
    SendText $socket '{"type":"hello","browser":7}'
    SendText $socket '{"type":"downloads","items":[{"id":null,"name":"x","paused":"no"}]}'
    SendText $socket '{"type":"downloads","items":"nope"}'
    Start-Sleep -Milliseconds 500
    $again = Connect 'chrome-extension://bridgetest2'
    if ($again.State -ne 'Open') { throw 'the dock stopped answering' }
    $again.Dispose()
    Write-Output 'OK malformed'
} catch {
    Write-Output "FAIL malformed: $($_.Exception.Message)"
    $failed = $true
}

# (b) A web page's origin: refused.
try {
    $socket = Connect 'https://example.com'
    if ($socket.State -eq 'Open') {
        Write-Output 'FAIL reject: a web page got in'
        $failed = $true
    } else {
        Write-Output 'OK reject'
    }
} catch {
    Write-Output 'OK reject'
}

if ($failed) { exit 1 }
exit 0
