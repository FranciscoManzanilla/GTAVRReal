$bytes = [System.IO.File]::ReadAllBytes('c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\d3d11.dll')
$stringContent = [System.Text.Encoding]::ASCII.GetString($bytes)
$matches = [regex]::Matches($stringContent, '[A-Za-z][A-Za-z0-9_]{5,}')
$matches | Select-Object -ExpandProperty Value | Out-File 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\d3d11_strings.txt' -Encoding ascii
