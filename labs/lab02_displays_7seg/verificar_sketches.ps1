# Compila todos os sketches de codigo_base/ para o Arduino UNO R3.
# Uso: ./verificar_sketches.ps1   (saida 0 = todos compilaram)
$ErrorActionPreference = 'Continue'
$base = Join-Path $PSScriptRoot 'codigo_base'
$sketches = @()
if (Test-Path $base) {
    $sketches = Get-ChildItem -Path $base -Recurse -Filter *.ino
}
if ($sketches.Count -eq 0) {
    Write-Host 'FALHA: nenhum sketch encontrado em codigo_base' -ForegroundColor Red
    exit 1
}
$falhas = 0
foreach ($s in $sketches) {
    $pasta = $s.DirectoryName
    $saida = & arduino-cli compile --fqbn arduino:avr:uno $pasta 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "OK    $($s.Name)"
    } else {
        Write-Host "FALHA $($s.Name)" -ForegroundColor Red
        $saida | ForEach-Object { Write-Host "      $_" }
        $falhas++
    }
}
Write-Host "$($sketches.Count - $falhas) de $($sketches.Count) sketches compilados"
if ($falhas -gt 0) { exit 1 }
exit 0
