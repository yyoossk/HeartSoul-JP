# カントー編の FRLG レイアウトで使うタイルセットを hns ビルドに入れる -> src/data/tilesets/kj_frlg.h
import re, json
allow = set(open('data/layouts/kj_frlg_layouts.txt').read().split())
L = [l for l in json.load(open('data/layouts/layouts.json'))['layouts'] if l and l['id'] in allow]
need = sorted({l['primary_tileset'] for l in L} | {l['secondary_tileset'] for l in L})
def block(path, start, end):
    s = open(path).read(); a = s.index(start); b = s.index(end, a); return s[a:b]
H = block('src/data/tilesets/headers.h', '#elif IS_FRLG', '#elif IS_HNS')
G = block('src/data/tilesets/graphics.h', '#if IS_FRLG', '#elif IS_HNS')
M = block('src/data/tilesets/metatiles.h', '#elif IS_FRLG', '#elif IS_HNS')
def defs(text):
    out = {}; cur = None; buf = []; depth = 0
    for line in text.splitlines(True):
        if cur is None:
            m = re.match(r'(?:static\s+)?const\s+[\w ]+?\s+(?:ALIGNED\(\d+\)\s+)?(\w+)\s*(\[|=)', line)
            if not m: continue
            cur = m.group(1); buf = []; depth = 0
        buf.append(line); depth += line.count('{') - line.count('}')
        if depth <= 0 and line.rstrip().endswith(';'):
            out[cur] = ''.join(buf); cur = None
    return out
hd, gd, md = defs(H), defs(G), defs(M)
out = ['// カントー＆ジョウト: FRLG のタイルセット（tools_kj/gen_tilesets.py で作成）\n']
callbacks = set(); missing = []
gfx = []; hdr = []
for t in need:
    if t not in hd:
        if re.search(r'const struct Tileset ' + t + r' =', open('src/data/tilesets/headers.h').read()[:open('src/data/tilesets/headers.h').read().index('#if !IS_FRLG')]): continue
        missing.append(t); continue
    h = hd[t]; hdr.append(h)
    for sym in re.findall(r'\.(?:tiles|palettes|metatiles|metatileAttributes)\s*=\s*(\w+)', h):
        src = gd.get(sym) or md.get(sym)
        if src is None: missing.append(sym)
        elif src not in gfx: gfx.append(src)
    cb = re.search(r'\.callback\s*=\s*(\w+)', h).group(1)
    if cb != 'NULL': callbacks.add(cb)
body = ''.join(out + gfx + ['\n'] + hdr)
# FRLG の属性は u32 で読むので 4 バイトにそろえる
body = re.sub(r'const u16 (gMetatileAttributes_\w+)\[\]', r'const u16 ALIGNED(4) \1[]', body)
open('src/data/tilesets/kj_frlg.h', 'w').write(body)
open('src/data/tilesets/kj_frlg_callbacks.txt', 'w').write('\n'.join(sorted(callbacks)) + '\n')
print('tilesets', len(need), 'missing', missing, 'callbacks', len(callbacks))
