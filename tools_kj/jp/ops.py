# pokefirered の event.inc から、命令ごとの引数の大きさを取り出す
import re
src = open('/home/claude/pokefirered/asm/macros/event.inc').read()
OPS = {}
for m in re.finditer(r'\.macro (\w+)([^\n]*)\n(.*?)\.endm', src, re.S):
    name, body = m.group(1), m.group(3)
    lines = [l.strip() for l in body.splitlines() if l.strip() and not l.strip().startswith('@')]
    if not lines: continue
    mm = re.match(r'\.byte (0x[0-9a-fA-F]+|\d+)$', lines[0])
    if not mm: continue
    op = int(mm.group(1), 0)
    if any(l.startswith('.if') or l.startswith('.ifb') for l in lines): cond = True
    else: cond = False
    sizes = []
    for l in lines[1:]:
        k = re.match(r'\.(byte|2byte|4byte)\b', l)
        if k: sizes.append({'byte': 1, '2byte': 2, '4byte': 4}[k.group(1)])
        else: sizes.append(None)
    if op not in OPS or not cond: OPS[op] = (name, sizes, cond)
if __name__ == '__main__':
    for op in sorted(OPS):
        n, s, c = OPS[op]
        if c or None in s: print(hex(op), n, s, c)
    print(len(OPS))
