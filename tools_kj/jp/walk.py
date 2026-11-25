# pokefirered のスクリプトと 日本版ファイアレッドのスクリプトを並べて たどり、会話のラベル → 日本版の番地 を求める
import re, json, glob, sys
sys.path.insert(0, '/home/claude/fr')
from rom import *
import ops as O
PF = '/home/claude/pokefirered'
# --- 命令の長さ
SIZES = {}
for op, (name, sizes, cond) in O.OPS.items():
    lines = re.search(r'\.macro ' + name + r'\b[^\n]*\n(.*?)\.endm', O.src, re.S).group(1)
    ls = [l.strip() for l in lines.splitlines() if l.strip() and not l.strip().startswith('@')][1:]
    out = []
    for l in ls:
        k = re.match(r'\.(byte|2byte|4byte)\b', l)
        if k: out.append({'byte': 1, '2byte': 2, '4byte': 4}[k.group(1)])
        elif l.startswith('map '): out.append(2)
        elif l.startswith('formatwarp'): out.append(7)
        elif l.startswith('stringvar'): out.append(1)
    SIZES[op] = out
TB = {0: 2, 1: 3, 2: 3, 3: 1, 4: 3, 5: 2, 6: 4, 7: 3, 8: 4, 9: 2}
def jp_walk(a, limit=400):
    ptrs = []
    for _ in range(limit):
        op = R[a]; a += 1
        if op == 0x5C:
            t = R[a]; a += 5
            for i in range(TB.get(t, 0)): ptrs.append(off(u32(a))); a += 4
            continue
        if op not in SIZES: return ptrs, False
        for sz in SIZES[op]:
            if sz == 4:
                v = u32(a)
                if isptr(v): ptrs.append(off(v))
            a += sz
        if op in (0x02, 0x03, 0x05, 0x08): return ptrs, True
    return ptrs, False
# --- pokefirered のソース
labels = {}      # label -> (file, index)
items = []       # (kind, value) kind: label / cmd
texts = set(); scriptish = set()
for f in sorted(glob.glob(PF + '/data/maps/*/scripts.inc') + glob.glob(PF + '/data/maps/*/text.inc') + glob.glob(PF + '/data/scripts/*.inc') + glob.glob(PF + '/data/text/*.inc') + [PF + '/data/event_scripts.s']):
    cur = None
    for line in open(f, encoding='utf-8', errors='ignore'):
        s = line.split('@')[0].strip()
        if not s: continue
        m = re.match(r'(\w+)::?$', s)
        if m: cur = m.group(1); labels[cur] = len(items); items.append(('label', cur)); continue
        if s.startswith('.string'):
            if cur: texts.add(cur)
            items.append(('str', s)); continue
        items.append(('cmd', s))
TERM = {'end', 'return', 'goto', 'gotostd', 'releaseend'}
def src_walk(lb, limit=400):
    i = labels[lb] + 1; refs = []
    for _ in range(limit):
        if i >= len(items): break
        k, v = items[i]; i += 1
        if k == 'label': continue
        if k != 'cmd': break
        name = v.split()[0]
        if name.startswith('.'): break
        args = v[len(name):]
        for t in re.findall(r'\b[A-Za-z_]\w*\b', args):
            if t in labels: refs.append(t)
        if name in TERM: return refs, True
    return refs, False
result = {}; seen = set(); stats = {'ok': 0, 'ng': 0}
def visit(lb, a, depth=0):
    if (lb, a) in seen or depth > 40 or lb not in labels: return
    seen.add((lb, a))
    if lb in texts: result.setdefault(lb, a); return
    sr, _ = src_walk(lb); jr, _ = jp_walk(a)
    if len(sr) != len(jr): stats['ng'] += 1; return
    stats['ok'] += 1
    for s, j in zip(sr, jr):
        if s in texts: result.setdefault(s, j)
        else: visit(s, j, depth + 1)
# --- 種: マップのイベント
groups = json.load(open(PF + '/data/maps/map_groups.json'))
gtab = 0x316758
for gi, gname in enumerate(groups['group_order']):
    gp = off(u32(gtab + 4*gi))
    for mi, m in enumerate(groups[gname]):
        h = off(u32(gp + 4*mi)); mj = json.load(open(f'{PF}/data/maps/{m}/map.json'))
        ev = off(u32(h + 4)); oc, wc, cc, bc = R[ev], R[ev+1], R[ev+2], R[ev+3]
        if oc:
            o = off(u32(ev + 4))
            for i, obj in enumerate(mj.get('object_events', [])):
                if i < oc and obj.get('script') and obj['script'] != '0x0': visit(obj['script'], off(u32(o + 24*i + 0x10)))
        if cc:
            c = off(u32(ev + 12))
            for i, ce in enumerate(mj.get('coord_events', [])):
                if i < cc and ce.get('script'): visit(ce['script'], off(u32(c + 16*i + 0xC)))
        if bc:
            b = off(u32(ev + 16))
            for i, be in enumerate(mj.get('bg_events', [])):
                if i < bc and be.get('script') and isptr(u32(b + 12*i + 8)): visit(be['script'], off(u32(b + 12*i + 8)))
        # map scripts
        try: ms_src = open(f'{PF}/data/maps/{m}/scripts.inc').read()
        except FileNotFoundError: continue
        mm = re.search(r'(?m)^' + m + r'_MapScripts::\n((?:\s*(?:map_script|\.byte)[^\n]*\n)+)', ms_src)
        if not mm: continue
        ents = re.findall(r'map_script (\w+), (\w+)', mm.group(1))
        a = off(u32(h + 8)); k = 0
        while R[a] != 0 and k < len(ents):
            t, p = R[a], off(u32(a + 1)); a += 5
            lb = ents[k][1]; k += 1
            if t in (2, 4):
                tm = re.search(r'(?m)^' + lb + r'::\n((?:\s*(?:map_script_2|\.2byte)[^\n]*\n)+)', ms_src)
                if not tm: continue
                e2 = re.findall(r'map_script_2 \w+, \w+, (\w+)', tm.group(1)); q = p
                for lb2 in e2:
                    if u16(q) == 0: break
                    visit(lb2, off(u32(q + 4))); q += 8
            else: visit(lb, p)
print(stats, 'texts', len(result), 'of', len(texts))
json.dump({k: hex(v) for k, v in result.items()}, open('/home/claude/fr/jp_walk.json', 'w'), indent=0)
