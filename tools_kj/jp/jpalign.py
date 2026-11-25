# 英語（pokefirered）と日本版ファイアレッドの会話を、マップごとに並びで対応させる（特徴で DP）
import sys, re, json, math
src = open('/home/claude/fr/jptext.py').read().split('result = {}; report = []')[0]
exec(src)
gtab = 0x316758
def en_strings(m):
    t = open(f'{PF}/data/maps/{m}/text.inc').read()
    out = []
    for lb, body in re.findall(r'(?m)^(\w+)::\n((?:[ \t]*\.string[^\n]*\n?)+)', t):
        s = ''.join(re.findall(r'\.string\s+"(.*)"', body)); out.append((lb, s))
    return out
def prev_start(p):
    q = p - 2
    while q > 0 and R[q] != 0xFF: q -= 1
    return q + 1
def feats(s):
    ph = tuple(sorted(set(re.findall(r'\{(PLAYER|RIVAL|STR_VAR_\d)\}', s))))
    return ph, s.count('\\p'), len(re.sub(r'\{[^}]*\}|\\.', 'x', s))
def sim(e, j, jbad):
    if jbad: return -6
    pe, pp, le = feats(e); je, jp, lj = feats(j)
    sc = 3 if pe == je else -4
    sc += 2 if pp == jp else -1.5 * abs(pp - jp)
    r = (lj + 1) / (le + 1)
    sc -= 2 * abs(math.log(r / 0.55))
    return sc
def align(E, J):
    n, m = len(E), len(J); G_E, G_J = -5, -1.5
    D = [[-1e9] * (m + 1) for _ in range(n + 1)]; B = [[None] * (m + 1) for _ in range(n + 1)]
    D[0][0] = 0
    for j in range(1, m + 1): D[0][j] = 0; B[0][j] = 'j'   # 先頭の余りはただ
    for i in range(1, n + 1):
        for j in range(0, m + 1):
            best = D[i-1][j] + G_E; b = 'e'
            if j:
                v = D[i-1][j-1] + sim(E[i-1][1], J[j-1][1], J[j-1][2])
                if v > best: best, b = v, 'm'
                v = D[i][j-1] + (0 if i == n else G_J)
                if v > best: best, b = v, 'j'
            D[i][j] = best; B[i][j] = b
    i, j = n, m; pairs = []; score = []
    while i > 0:
        b = B[i][j]
        if b == 'm': pairs.append((E[i-1][0], J[j-1])); score.append(sim(E[i-1][1], J[j-1][1], J[j-1][2])); i -= 1; j -= 1
        elif b == 'e': i -= 1
        else: j -= 1
    return pairs[::-1], score[::-1]
import numpy as np
REFS = sorted(int(x) for x in np.load('/home/claude/fr/refs.npy'))
res = {}; rep = []
for gi, gname in enumerate(groups['group_order']):
    gp = off(u32(gtab + 4*gi))
    for mi, m in enumerate(groups[gname]):
        try: E = en_strings(m)
        except FileNotFoundError: continue
        if not E: continue
        h = off(u32(gp + 4*mi)); st = script_ptrs(h)
        refs = sorted(text_refs(st))
        refs = [r for r in refs if decode(r)[2] == 0]
        if not refs: rep.append((m, 'norefs')); continue
        # 参照のまわりで、どこかから参照されていて、きれいに読める文
        lo = refs[0] - 0x2000; hi = refs[-1] + 0x2000
        if hi - lo > 0x10000: hi = lo + 0x10000
        J = []
        import bisect
        for r in REFS[bisect.bisect_left(REFS, lo):bisect.bisect_left(REFS, hi)]:
            s2, _, bad = decode(r)
            if bad == 0 and len(s2) > 2: J.append((r, s2, bad))
        pairs, sc = align(E, J)
        good = [(lb, j) for (lb, j), s in zip(pairs, sc) if s > -4.5]
        for lb, j in good: res[lb] = {'jp': j[1], 'addr': hex(j[0])}
        rep.append((m, len(E), len(good)))
json.dump(res, open('/home/claude/fr/jp_align.json', 'w'), ensure_ascii=False, indent=0)
tot = sum(r[1] for r in rep if len(r) == 3); got = sum(r[2] for r in rep if len(r) == 3)
print('labels', tot, 'matched', got)
print('weak', [r for r in rep if len(r) != 3 or r[2] < r[1] * 0.8][:40])
