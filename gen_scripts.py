import re

def process():
    with open('c:/Users/Frank/Downloads/GTAVRV SC/GTAVRVSC/extracted_strings.txt', 'r') as f:
        words = f.read().split()
        
    scripts = []
    for w in words:
        w = w.strip()
        if re.match(r'^[a-z_0-9]{4,30}$', w):
            if w not in ['main', 'initial', 'startup', 'startup_install', 'startup_smoketest']:
                # heuristically categorize
                cat = 'SC_MISSION'
                if 'tennis' in w or 'darts' in w or 'golf' in w or 'triathlon' in w:
                    cat = 'SC_MINIGAME'
                elif 'heli' in w or 'plane' in w or 'pilot' in w or 'flight' in w:
                    cat = 'SC_FLIGHT'
                elif 'heist' in w or 'finale' in w or 'cutscene' in w or 'michael' in w or 'trevor' in w or 'franklin' in w or 'armenian' in w or 'chinese' in w:
                    cat = 'SC_CUTSCENE_HEAVY'
                
                scripts.append(f'    {{ "{w}", {cat} }},')
                
    scripts = sorted(list(set(scripts)))
    with open('c:/Users/Frank/Downloads/GTAVRV SC/GTAVRVSC/generated_scripts.txt', 'w') as out:
        out.write('\n'.join(scripts))

if __name__ == '__main__':
    process()
