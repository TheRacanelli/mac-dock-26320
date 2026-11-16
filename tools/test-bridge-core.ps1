# Builds and runs tools/bridge_core_test.cpp against the BRIDGE-CORE region
# of mac-dock-26320.wh.cpp, with Windhawk's compiler.
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$mod = Join-Path $root 'mac-dock-26320.wh.cpp'
$work = Join-Path $env:TEMP 'mac-dock-bridge-test'
New-Item -ItemType Directory -Force $work | Out-Null

$text = Get-Content -Raw -Encoding UTF8 $mod
$match = [regex]::Match($text, '(?s)// BRIDGE-CORE-BEGIN(.*?)// BRIDGE-CORE-END')
if (-not $match.Success) {
    Write-Output 'FAIL: no BRIDGE-CORE region in the mod'
    exit 1
}
Set-Content -Encoding UTF8 -Path (Join-Path $work 'bridge_core.inc') -Value $match.Groups[1].Value

$clang = 'C:\Program Files\Windhawk\Compiler\bin\clang++.exe'
$exe = Join-Path $work 'bridge_core_test.exe'
& $clang -std=c++23 -O1 -target x86_64-w64-mingw32 -DUNICODE -D_UNICODE `
    -I $work (Join-Path $PSScriptRoot 'bridge_core_test.cpp') -lbcrypt -static -o $exe 2>&1 |
    Select-String 'error' | ForEach-Object { $_.Line }
if ($LASTEXITCODE -ne 0) {
    Write-Output 'FAIL: build'
    exit 1
}
& $exe
exit $LASTEXITCODE
