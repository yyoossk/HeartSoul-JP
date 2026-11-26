# maptour.py ROM 名前 : 一覧のマップへ順に飛び、写真と位置を記録する
import json, subprocess, sys
rom, name = sys.argv[1], sys.argv[2]
L = json.load(open('/tmp/maplist_sel.json'))
B = 10
START = int(sys.argv[3]) if len(sys.argv) > 3 else 0
import shutil
log = open('/tmp/mapt/log.txt', 'a')
for b in range(START, len(L), B):
    shutil.copy('/tmp/mapt/base0.ss', f'/tmp/mapt/{name}.ss')
    ops = []
    for i, (cid, grp, num, x, y) in enumerate(L[b:b + B], b):
        ops += [f'w32=03000bf0={(x & 0xFF) | (y & 0xFF) << 8:x}', f'w32=03000bec={0x10000 | num | grp << 8:x}', 'w150', f'@m{i:04d}', 'pos']
    r = subprocess.run(['python3', '/home/claude/harness/g.py', rom, name, ' '.join(ops)], capture_output=True, text=True, cwd='/tmp/mapt')
    poss = [l for l in r.stdout.splitlines() if l.startswith('pos')]
    for (cid, grp, num, x, y), p in zip(L[b:b + B], poss):
        log.write(f'{cid} {grp}.{num} want({x},{y}) {p}\n')
    if len(poss) < len(L[b:b + B]): log.write(f'BATCH {b} short {len(poss)} {r.stderr[-300:]}\n')
    log.flush(); print(b, flush=True)
