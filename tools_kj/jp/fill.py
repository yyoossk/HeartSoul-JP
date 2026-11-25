# walk の結果の間を、text.inc の並びで うめる
import json, re, glob
exec(open('/home/claude/fr/jptext.py').read().split('# --- pokefirered')[0])
PF = '/home/claude/pokefirered'
W = {k: int(v, 16) for k, v in json.load(open('/home/claude/fr/jp_walk.json')).items()}
out = dict(W); added = 0
def nxt(a): return decode(a)[1]
for f in glob.glob(PF + '/data/maps/*/text.inc') + glob.glob(PF + '/data/text/*.inc'):
    labs = re.findall(r'(?m)^(\w+)::\n\s*\.string', open(f).read())
    idx = [i for i, l in enumerate(labs) if l in W]
    if not idx: continue
    # あいだ
    for x, y in zip(idx, idx[1:]):
        if y - x <= 1: continue
        a = W[labs[x]]; addrs = []
        for k in range(y - x):
            a = nxt(a); addrs.append(a)
        if addrs[-1] == W[labs[y]] and all(decode(b)[2] == 0 for b in addrs[:-1]):
            for k, b in enumerate(addrs[:-1]): out[labs[x + 1 + k]] = b; added += 1
    # うしろ
    a = W[labs[idx[-1]]]
    for l in labs[idx[-1] + 1:]:
        a = nxt(a); s, _, bad = decode(a)
        if bad or len(s) < 2: break
        out[l] = a; added += 1
    # まえ
    a = W[labs[idx[0]]]
    for l in reversed(labs[:idx[0]]):
        if R[a - 1] != 0xFF: break
        q = a - 2
        while R[q] != 0xFF and a - q < 600: q -= 1
        a = q + 1; s, e, bad = decode(a)
        if bad or len(s) < 2: break
        out[l] = a; added += 1
# 並べ合わせの結果: 前後の文とつながる（次の文の番地になる）ものだけ使う
A = {k: int(v['addr'], 16) for k, v in json.load(open('/home/claude/fr/jp_align.json')).items()}
added2 = 0
for f in glob.glob(PF + '/data/maps/*/text.inc') + glob.glob(PF + '/data/text/*.inc'):
    labs = re.findall(r'(?m)^(\w+)::\n\s*\.string', open(f).read())
    for _ in range(3):
        for i, l in enumerate(labs):
            if l in out or l not in A: continue
            a = A[l]
            if decode(a)[2]: continue
            nx = labs[i + 1] if i + 1 < len(labs) else None
            pv = labs[i - 1] if i else None
            ok_next = nx is not None and ((nx in out and out[nx] == nxt(a)) or (nx in A and A[nx] == nxt(a)))
            ok_prev = pv is not None and ((pv in out and nxt(out[pv]) == a) or (pv in A and nxt(A[pv]) == a))
            if ok_next or ok_prev: out[l] = a; added2 += 1
print('align added', added2)
res = {k: {'addr': hex(v), 'jp': decode(v)[0]} for k, v in out.items()}
json.dump(res, open('/home/claude/fr/jp_final.json', 'w'), ensure_ascii=False, indent=0)
print('walk', len(W), 'added', added, 'total', len(res))
