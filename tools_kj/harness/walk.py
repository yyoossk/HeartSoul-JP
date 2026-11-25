# python3 walk.py ROM 名前 "R3 U2 D1 L4" : 1マスずつ歩く（向きを変えるだけのときは押しなおす）。最後に位置を出す
import sys, subprocess, re
rom, name, path = sys.argv[1], sys.argv[2], sys.argv[3]
G = '/home/claude/harness/g.py'
def run(ops):
    out = subprocess.run(['python3', G, rom, name, ops], capture_output=True, text=True).stdout
    m = re.findall(r'pos x=(-?\d+) y=(-?\d+) map=(\d+)\.(\d+)', out)
    return tuple(map(int, m[-1])) if m else None
cur = run('pos')
for tok in path.split():
    d, n = tok[0], int(tok[1:] or 1)
    for _ in range(n):
        for tries in range(3):
            new = run(f'h{d}:8 w8 pos')
            if new != cur: cur = new; break
        else:
            print('blocked at', cur, 'dir', d); sys.exit(1)
print('pos', cur)
