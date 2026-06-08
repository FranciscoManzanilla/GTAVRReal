$scripts = Get-Content 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\generated_scripts.txt' -Raw
$header = Get-Content 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\include\ScriptHashes.h' -Raw
$pattern = '(?s)static const ScriptEntry kNotableScripts\[\] = \{.*?\};'
$replacement = "static const ScriptEntry kNotableScripts[] = {`n" + $scripts + "`n};"
$newHeader = $header -replace $pattern, $replacement
[System.IO.File]::WriteAllText('c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\include\ScriptHashes.h', $newHeader)
