$bytes = [System.IO.File]::ReadAllBytes('c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\RealVR.asi')
$stringContent = [System.Text.Encoding]::ASCII.GetString($bytes)
$matches = [regex]::Matches($stringContent, '[a-z][a-z0-9_]{5,}')
$matches | Select-Object -ExpandProperty Value | Out-File 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\extracted_strings.txt' -Encoding ascii
