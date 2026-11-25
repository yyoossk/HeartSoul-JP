# 日本版ファイアレッドから、マップごとの会話を pokefirered のラベル順に取り出す
import sys, re, json, struct
sys.path.insert(0, '/home/claude/fr')
from rom import *
PF = '/home/claude/pokefirered'
HNS = '/home/claude/src/HeartSoul-JP'
# --- 文字の読み方（charmap の逆。全角を優先）
inv = {}
for line in open(HNS + '/charmap.txt', encoding='utf-8'):
    m = re.match(r"^'(.+?)'\s*=\s*([0-9A-Fa-f]{2})\s*$", line.split('@')[0].rstrip())
    if not m: continue
    ch, b = m.group(1), int(m.group(2), 16)
    if b not in inv or (ord(ch[0]) > 0x2000 and ord(inv[b][0]) < 0x2000): inv[b] = ch
inv[0x00] = '　'
PH = {0x01: '{PLAYER}', 0x02: '{STR_VAR_1}', 0x03: '{STR_VAR_2}', 0x04: '{STR_VAR_3}', 0x05: '{KUN}', 0x06: '{RIVAL}'}
FCLEN = {0x01: 1, 0x02: 1, 0x03: 1, 0x04: 3, 0x05: 1, 0x06: 1, 0x07: 0, 0x08: 1, 0x09: 0, 0x0A: 0, 0x0B: 2, 0x0C: 1, 0x0D: 1, 0x0E: 1, 0x0F: 0, 0x10: 2, 0x11: 1, 0x12: 1, 0x13: 1, 0x14: 1, 0x15: 0, 0x16: 0, 0x17: 0, 0x18: 0}
def decode(a):
    out = []; bad = 0
    while True:
        b = R[a]; a += 1
        if b == 0xFF: out.append('$'); break
        if b == 0xFE: out.append('\\n')
        elif b == 0xFA: out.append('\\l')
        elif b == 0xFB: out.append('\\p')
        elif b == 0xFD:
            c = R[a]; a += 1; out.append(PH.get(c, '{FD%02X}' % c)); bad += c not in PH
        elif b == 0xFC:
            c = R[a]; a += 1; n = FCLEN.get(c, 0)
            args = R[a:a + n]; a += n
            out.append('{FC %02X%s}' % (c, ''.join(' %02X' % x for x in args)))
        elif b in inv: out.append(inv[b])
        else: out.append('{%02X}' % b); bad += 1
        if len(out) > 2000: bad += 100; break
    return ''.join(out), a, bad
# --- pokefirered のマップ（グループ順）
groups = json.load(open(PF + '/data/maps/map_groups.json'))
def text_labels(m):
    try: t = open(f'{PF}/data/maps/{m}/text.inc').read()
    except FileNotFoundError: return []
    return re.findall(r'(?m)^(\w+)::', t)
def script_ptrs(h):
    ev = off(u32(h + 4)); ms = off(u32(h + 8))
    oc, wc, cc, bc = R[ev], R[ev+1], R[ev+2], R[ev+3]
    ptrs = []
    o = off(u32(ev + 4)) if oc else 0
    for i in range(oc): v = u32(o + 24*i + 0x10); ptrs.append(v)
    c = off(u32(ev + 12)) if cc else 0
    for i in range(cc): ptrs.append(u32(c + 16*i + 0xC))
    b = off(u32(ev + 16)) if bc else 0
    for i in range(bc):
        if R[b + 12*i + 5] < 5: ptrs.append(u32(b + 12*i + 8))
    a = ms
    while R[a] != 0:
        t, p = R[a], u32(a + 1); a += 5
        if t in (2, 4):
            q = off(p)
            while u16(q) != 0: ptrs.append(u32(q + 4)); q += 8
        else: ptrs.append(p)
    return [off(p) for p in ptrs if isptr(p)]
def text_refs(starts):
    refs = set()
    for s in starts:
        for a in range(s, min(s + 0x600, len(R) - 6)):
            if R[a] == 0x0F and R[a+1] == 0 and isptr(u32(a+2)): refs.add(off(u32(a+2)))
            elif R[a] == 0x67 and isptr(u32(a+1)): refs.add(off(u32(a+1)))
    return refs
result = {}; report = []
gtab = 0x316758
for gi, gname in enumerate(groups['group_order']):
    gp = off(u32(gtab + 4*gi))
    for mi, m in enumerate(groups[gname]):
        labs = text_labels(m)
        if not labs: continue
        h = off(u32(gp + 4*mi))
        starts = script_ptrs(h)
        refs = text_refs(starts)
        # 一番近いかたまり: スクリプトの後ろにある最初の参照
        cand = sorted(r for r in refs if min(starts or [0]) - 0x8000 < r < max(starts or [0]) + 0x40000)
        ok = False
        for st in cand[:8]:
            a = st; got = []
            for lb in labs:
                s, a, bad = decode(a)
                got.append((lb, s, bad))
            starts_set = set(); a = st
            for lb in labs:
                starts_set.add(a); _, a, _ = decode(a)
            hit = sum(1 for r in refs if r in starts_set)
            if hit >= max(1, len([r for r in refs if st <= r < a]) * 0.9) and sum(g[2] for g in got) == 0:
                ok = True; break
        if ok:
            for lb, s, _ in got: result[lb] = s
        report.append((m, len(labs), ok, hex(st) if cand else None))
json.dump(result, open('/home/claude/fr/jp_map_text.json', 'w'), ensure_ascii=False, indent=0)
print('ok', sum(1 for r in report if r[2]), 'ng', [r for r in report if not r[2]][:40], 'labels', len(result))

# ===== 2段目: スクリプトの中の参照の順番で対応させる
def code_hits(starts):
    hits = {}
    for s in starts:
        for a in range(s, min(s + 0x800, len(R) - 4)):
            v = u32(a)
            if isptr(v): hits[a] = off(v)
    return hits
result2 = {}; rep2 = []
alltextlabels = {}
for gname in groups['group_order']:
    for m in groups[gname]:
        for lb in text_labels(m): alltextlabels[lb] = m
for gi, gname in enumerate(groups['group_order']):
    gp = off(u32(gtab + 4*gi))
    for mi, m in enumerate(groups[gname]):
        labs = text_labels(m)
        if not labs: continue
        try: src = open(f'{PF}/data/maps/{m}/scripts.inc').read()
        except FileNotFoundError: continue
        labset = set(labs)
        S = [t for t in re.findall(r'\b(\w+_Text_\w+|Text_\w+)\b', src) if t in labset]
        h = off(u32(gp + 4*mi)); starts = script_ptrs(h)
        hits = code_hits(starts)
        refs = sorted(set(hits.values()))
        # 自分の会話のかたまり: 一番多く参照される 0x6000 の範囲
        best = (0, 0)
        for r in refs:
            n = sum(1 for x in refs if r <= x < r + 0x6000)
            if n > best[0]: best = (n, r)
        lo = best[1]; hi = lo + 0x6000
        P = []
        for a in sorted(hits):
            v = hits[a]
            if lo <= v < hi:
                s, _, bad = decode(v)
                if bad == 0 and len(s) > 1: P.append(v)
        # 同じ場所の重複（窓の重なり）は除いてあるので、そのまま比べる
        if len(P) == len(S):
            okm = True; pairs = {}
            for lb, p in zip(S, P):
                if lb in pairs and pairs[lb] != p: okm = False
                pairs[lb] = p
            if okm:
                for lb, p in pairs.items(): result2[lb] = decode(p)[0]
            rep2.append((m, okm, len(S), len(P)))
        else:
            rep2.append((m, False, len(S), len(P)))
json.dump(result2, open('/home/claude/fr/jp_map_text2.json', 'w'), ensure_ascii=False, indent=0)
print('2nd ok', sum(1 for r in rep2 if r[1]), 'ng', len([r for r in rep2 if not r[1]]), [r for r in rep2 if not r[1]][:30], len(result2))
agree = sum(1 for k in result2 if k in result and result[k] == result2[k]); dis = [k for k in result2 if k in result and result[k] != result2[k]]
print('agree', agree, 'disagree', len(dis), dis[:10])
