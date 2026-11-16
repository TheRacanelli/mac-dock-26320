# Checks that the extension embedded in the mod (what "Instalar" writes out) is
# the same as extension/, then packs extension/ as dist/mac-dock-downloads.zip
# (to be signed on addons.mozilla.org for Zen). Run with PowerShell 7.
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$mod = Get-Content -Raw -Encoding UTF8 (Join-Path $root 'mac-dock-26320.wh.cpp')
$files = 'manifest.json', 'protocol.js', 'background.js'
$failed = $false

foreach ($name in $files) {
    $pattern = '(?s)// EXTENSION-FILE ' + [regex]::Escape($name) + '\r?\n[^\n]*R"MDX\((.*?)\)MDX"'
    $match = [regex]::Match($mod, $pattern)
    if (-not $match.Success) {
        Write-Output "FAIL: $name is not embedded in the mod"
        $failed = $true
        continue
    }
    $embedded = $match.Groups[1].Value -replace "`r`n", "`n"
    $source = (Get-Content -Raw -Encoding UTF8 (Join-Path $root "extension/$name")) -replace "`r`n", "`n"
    if ($embedded -ne $source) {
        Write-Output "FAIL: $name embedded in the mod differs from extension/$name"
        $failed = $true
    } else {
        Write-Output "OK $name"
    }
}
if ($failed) { exit 1 }

$dist = Join-Path $root 'dist'
New-Item -ItemType Directory -Force $dist | Out-Null
$zip = Join-Path $dist 'mac-dock-downloads.zip'
Remove-Item $zip -ErrorAction SilentlyContinue
Compress-Archive -Path ($files | ForEach-Object { Join-Path $root "extension/$_" }) -DestinationPath $zip
Write-Output "OK packed $zip"
exit 0
