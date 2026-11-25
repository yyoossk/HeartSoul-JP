# python3 g.py ROM 名前 "操作" : 名前.ss から続け、名前.ss に残す。@写真名 で写真（名前_写真名.png）
# 操作: w600（待つ） A / B / S（START）/ s（SELECT）/ U D L R / l r（L R）  A3（3回） hD:32（32フレーム押し続ける）
import sys, os, subprocess, re, tempfile
from PIL import Image
H = os.path.dirname(os.path.abspath(__file__))
rom, name, ops = sys.argv[1], sys.argv[2], sys.argv[3]
KEY = {'A': 'A', 'B': 'B', 'S': 's', 's': 'S', 'U': 'U', 'D': 'D', 'L': 'l', 'R': 'r', 'l': 'L', 'r': 'R'}
# run の KEYS: A B s=START? -> run.c: 's'=SELECT(4) 'S'=START(8)
KEY = {c: c for c in 'ABSsUDLRlr'}  # R/L = 右/左、r/l = R/L ボタン
lines = []; shots = []
for t in ops.split():
    if t.startswith('@'): lines.append(f'shot {name}_{t[1:]}'); shots.append(f'{name}_{t[1:]}'); continue
    m = re.fullmatch(r'w(\d+)', t)
    if m: lines.append(f'w {m.group(1)}'); continue
    m = re.fullmatch(r'h([ABSsUDLRlr]+):(\d+)', t)
    if m: lines.append(f'p {"".join(KEY[c] for c in m.group(1))} {m.group(2)}'); continue
    m = re.fullmatch(r'([ABSsUDLRlr])(\d*)', t)
    if m:
        for _ in range(int(m.group(2) or 1)): lines += [f'p {KEY[m.group(1)]} 6', 'w 14']
        continue
    if t == 'pos': lines.append('pos 02001848 02001878'); continue
    m = re.fullmatch(r'(r8|r16|r32|w8|w16|w32)=(\w+)(?:=(\w+))?', t)
    if m: lines.append(' '.join(x for x in m.groups() if x)); continue
    sys.exit('bad op ' + t)
sc = tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False); sc.write('\n'.join(lines) + '\n'); sc.close()
st = name + '.ss'
r = subprocess.run([H + '/run', rom, name + '.sav', st if os.path.exists(st) else '-', st, sc.name, '.'], capture_output=True, text=True)
sys.stdout.write(r.stdout); sys.stderr.write(r.stderr[-2000:])
for s in shots:
    Image.open(s + '.ppm').resize((480, 320), Image.NEAREST).save(s + '.png'); os.remove(s + '.ppm')
