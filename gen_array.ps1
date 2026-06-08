$words = Get-Content 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\extracted_strings.txt'
$out = @()
foreach ($w in $words) {
    $w = $w.Trim()
    if ($w -match '^[a-z_0-9]{4,30}$') {
        if ('main','initial','startup','startup_install','startup_smoketest','d3d11' -notcontains $w) {
            $cat = 'SC_MISSION'
            if ($w -match 'tennis|darts|golf|triathlon') {
                $cat = 'SC_MINIGAME'
            } elseif ($w -match 'heli|plane|pilot|flight') {
                $cat = 'SC_FLIGHT'
            } elseif ($w -match 'heist|finale|cutscene|michael|trevor|franklin|armenian|chinese') {
                $cat = 'SC_CUTSCENE_HEAVY'
            }
            $out += '    { "' + $w + '", ' + $cat + ' },'
        }
    }
}
$out | Sort-Object -Unique | Out-File 'c:\Users\Frank\Downloads\GTAVRV SC\GTAVRVSC\generated_scripts.txt' -Encoding ASCII
