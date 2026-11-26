import json,sys
for m in sys.argv[1:]:
    d=json.load(open(f'/home/claude/src/HeartSoul-JP/data/maps/{m}/map.json'))
    print('==',m,d['id'])
    for i,o in enumerate(d['object_events']):
        print(' ',i+1,o['x'],o['y'],o.get('script','').split('EventScript_')[-1],o.get('flag',''))
    for w in d['warp_events']: print('  W',w['x'],w['y'],w['dest_map'])
