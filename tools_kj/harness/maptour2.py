# maptour2.py ROM : redo.json の　マップを　1つずつ（毎回　はじめの　状態から）
import json, subprocess, shutil
rom = __import__('sys').argv[1]
L = json.load(open('/tmp/maplist_sel.json')); idx = json.load(open('/tmp/mapt/redo.json'))
log = open('/tmp/mapt/log2.txt', 'w')
for i in idx:
    cid, grp, num, x, y = L[i]
    shutil.copy('/tmp/mapt/base2.ss', '/tmp/mapt/v.ss')
    ops = f'w32=03000bf0={(x & 0xFF) | (y & 0xFF) << 8:x} w32=03000bec={0x10000 | num | grp << 8:x} w150 @r{i:04d} pos'
    r = subprocess.run(['python3', '/home/claude/harness/g.py', rom, 'v', ops], capture_output=True, text=True, cwd='/tmp/mapt')
    p = [l for l in r.stdout.splitlines() if l.startswith('pos')]
    log.write(f'{i} {cid} {grp}.{num} {p[0] if p else "NOPOS"}\n'); log.flush()
