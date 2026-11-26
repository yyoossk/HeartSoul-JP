# graph.py : マップの　なかの　つながり（あるける　ばしょの　かたまり）ごとの　グラフ
# ノード = (マップ, かたまり)。 えだ は　ワープ と　となりの　マップへの　つながり。
# いま　いる　マップだけは　じっさいの　メモリの　マップで　かたまりを　つくりなおす（スクリプトで　かわる　ため）
import json, os, collections, pickle, itertools
SRC = '/home/claude/src/HeartSoul-JP'
DIRS = {'U': (0, -1), 'D': (0, 1), 'L': (-1, 0), 'R': (1, 0)}

def elev_ok(c1, c2):
    e1, e2 = c1 >> 12, c2 >> 12
    return e1 == e2 or e1 in (0, 15) or e2 in (0, 15)

def surf_ok(c1, c2, water):
    # みず（たかさ1）と　りく（たかさ3）は　のりおり　できる。ほかの　たかさは　だめ
    if water(c1) and not water(c2): return (c2 >> 12) in (0, 1, 3, 15)
    if water(c2) and not water(c1): return (c1 >> 12) in (0, 1, 3, 15)
    return water(c1) and water(c2)

def components(w, h, ok, cells=None, water=None):
    cm = {}; n = 0
    for y in range(h):
        for x in range(w):
            if (x, y) in cm or not ok(x, y): continue
            q = [(x, y)]; cm[(x, y)] = n
            while q:
                cx, cy = q.pop()
                for dx, dy in DIRS.values():
                    nx, ny = cx + dx, cy + dy
                    if (nx, ny) not in cm and ok(nx, ny) and (cells is None or elev_ok(cells[cy * w + cx], cells[ny * w + nx]) or (water and surf_ok(cells[cy * w + cx], cells[ny * w + nx], water))):
                        cm[(nx, ny)] = n; q.append((nx, ny))
            n += 1
    return cm

SPIN = {}   # bot が　いれる（ばんごう → むき）
STOP = -1
def make_ok(w, h, cells, beh, blk, surf, WATER, JUMP, spin_wall=True, allow=()):
    def ok(x, y):
        if (x, y) in blk or not (0 <= x < w and 0 <= y < h): return False
        if (x, y) in allow: return True  # あけられる　ドア
        c = cells[y * w + x]; b = beh(c)
        if b in SPIN and spin_wall: return False  # かいてんゆかも　いっぽうつうこうの　えだ
        if b in WATER: return surf and not (c & 0x0C00)
        if b in JUMP: return False  # だんさは　べつの　えだ（いっぽうつうこう）
        return not (c & 0x0C00)
    return ok

def ledges(w, h, cells, beh, JUMP, walk=None):
    res = []  # (まえの　マス, むき, ちゃくちの　マス)
    for y in range(h):
        for x in range(w):
            b = beh(cells[y * w + x])
            if b in JUMP:
                d = JUMP[b]; dx, dy = DIRS[d]
                res.append(((x - dx, y - dy), d, (x + dx, y + dy)))
            elif b in SPIN and walk:
                for d, (dx, dy) in DIRS.items():
                    t = (x - dx, y - dy)
                    if not walk(*t) or beh(cells[t[1] * w + t[0]]) in SPIN: continue
                    cx, cy, sd = x, y, SPIN[b]
                    for k in range(80):
                        sx, sy = DIRS[sd]
                        if not walk(cx + sx, cy + sy): break
                        cx, cy = cx + sx, cy + sy; bb = beh(cells[cy * w + cx])
                        if bb == STOP: break
                        if bb in SPIN: sd = SPIN[bb]
                    if beh(cells[cy * w + cx]) not in SPIN or True:
                        res.append((t, d, (cx, cy)))
    return res

def blocked_objs(objs, cut, smash):
    blk = set()
    for o in objs:
        sc = o.get('script', '')
        if (sc.endswith('CutTree') and not cut) or (sc.endswith('RockSmash') and not smash) or sc.endswith('StrengthBoulder'):
            blk.add((o['x'], o['y']))
    return blk

def build(bot, cache=None):
    cache = cache or os.environ.get('PLAYDIR', '/tmp/play') + '/graph9.pkl'
    if os.path.exists(cache) and os.path.getmtime(cache) > os.path.getmtime(os.environ.get('ROMGBA') or '/tmp/play/rom.gba'):
        return pickle.load(open(cache, 'rb'))
    L = {l['id']: l for l in json.load(open(f'{SRC}/data/layouts/layouts.json'))['layouts'] if 'width' in l}
    attr = {}
    def attrs(name, n, ver):
        k = (name, ver)
        if k not in attr:
            a = bot.S.get(name)
            if a is None: attr[k] = []; return attr[k]
            sz = 4 if ver == 1 else 2
            p = bot.r32(a + 0x10); r = bot.rd(p, n * sz)
            mask = 0x1FF if ver == 1 else 0xFF
            attr[k] = [int.from_bytes(r[i:i + sz], 'little') & mask for i in range(0, len(r), sz)]
        return attr[k]
    grids = {}
    for key, info in bot.maps.items():
        j = json.load(open(f"{SRC}/data/maps/{info['name']}/map.json"))
        lay = L.get(j['layout'])
        if not lay: continue
        ver = {'emerald': 0, 'frlg': 1, 'hns': 2}.get(lay.get('layout_version'), 0)
        nprim = 512 if ver == 0 else 640
        pa = attrs(lay['primary_tileset'], nprim, ver); sa = attrs(lay['secondary_tileset'], 1024 - nprim, ver)
        raw = open(f"{SRC}/{lay['blockdata_filepath']}", 'rb').read()
        w, h = lay['width'], lay['height']
        cells = [int.from_bytes(raw[i:i + 2], 'little') for i in range(0, w * h * 2, 2)]
        grids[key] = (w, h, cells, pa, sa, nprim)
    def behf(pa, sa, nprim):
        def beh(c):
            m = c & 0x3FF
            if m < nprim: return pa[m] if m < len(pa) else 0
            m -= nprim; return sa[m] if m < len(sa) else 0
        return beh
    # でぐち（マップごと、うごかない）
    exits = {}
    for key, info in bot.maps.items():
        if key not in grids: continue
        w, h, cells, pa, sa, nprim = grids[key]; beh = behf(pa, sa, nprim)
        ex = []
        for wp in info['warps']:
            dk = bot.mapid.get(wp['dest_map'])
            if not dk or dk not in grids: continue
            try: di = int(wp['dest_warp_id'])
            except: di = 0
            dws = bot.maps[dk]['warps']
            if di >= len(dws): continue
            good = 0 <= wp['x'] < w and 0 <= wp['y'] < h and beh(cells[wp['y'] * w + wp['x']]) != 0
            ex.append(('warp', wp['x'], wp['y'], dk, (dws[di]['x'], dws[di]['y']), good))
        for cn in info['conns']:
            dk = bot.mapid.get(cn['map'])
            if not dk or dk not in grids: continue
            w2, h2 = grids[dk][0], grids[dk][1]; off = cn['offset']; d = cn['direction']
            if d in ('up', 'down'):
                for x in range(w): ex.append(('conn', d, (x, 0 if d == 'up' else h - 1), dk, (x - off, h2 - 1 if d == 'up' else 0), True))
            elif d in ('left', 'right'):
                for y in range(h): ex.append(('conn', d, (0 if d == 'left' else w - 1, y), dk, (w2 - 1 if d == 'left' else 0, y - off), True))
        exits[key] = ex
    ledge = {}
    for key, g in grids.items():
        bh = behf(g[3], g[4], g[5])
        walk = make_ok(g[0], g[1], g[2], bh, set(), False, bot.WATER, bot.JUMP, spin_wall=False)
        ledge[key] = ledges(g[0], g[1], g[2], bh, bot.JUMP, walk)
    comps = {}
    for surf, cut, smash in itertools.product((False, True), repeat=3):
        cc = {}
        for key, (w, h, cells, pa, sa, nprim) in grids.items():
            blk = blocked_objs(bot.maps[key]['objs'], cut, smash) | {(wp['x'], wp['y']) for i, wp in enumerate(bot.maps[key]['warps']) if not (wp['dest_map'] == bot.maps[key]['id'] and str(wp['dest_warp_id']) == str(i))}
            doors = {(bg['x'], bg['y']) for bg in bot.maps[key]['bgs'] if 'EventScript_Door' in (bg.get('script') or '')}
            cc[key] = components(w, h, make_ok(w, h, cells, behf(pa, sa, nprim), blk, surf, bot.WATER, bot.JUMP, allow=doors), cells, (lambda c, bh=behf(pa, sa, nprim): bh(c) in bot.WATER) if surf else None)
        comps[(surf, cut, smash)] = cc
    G = dict(exits=exits, comps=comps, ledges=ledge)
    pickle.dump(G, open(cache, 'wb'))
    return G

def near(cm, x, y):
    s = set()
    for dx, dy in [(0, 0)] + list(DIRS.values()):
        c = cm.get((x + dx, y + dy))
        if c is not None: s.add(c)
    return s

def out_edges(G, comp, node, live_ledges=None):
    key, c = node; cm = comp.get(key, {}); res = []
    seen = set()
    for a, d, b in (live_ledges if live_ledges is not None and key in live_ledges else G['ledges']).get(key, ()):
        if cm.get(a) == c and cm.get(b) is not None and cm.get(b) != c and (cm.get(b), d) not in seen:
            seen.add((cm.get(b), d)); res.append(((key, cm.get(b)), ('ledge', a, d, True)))
    for e in sorted(G['exits'].get(key, ()), key=lambda e: not e[5]):
        if e[0] == 'warp':
            if c not in near(cm, e[1], e[2]): continue
            dc = near(comp.get(e[3], {}), *e[4])
            for c2 in dc or {None}:
                k = (e[3], c2, 'warp', e[1], e[2])
                res.append(((e[3], c2), ('warp', e[1], e[2], e[5])))
        else:
            if cm.get(e[2]) != c: continue
            c2 = comp.get(e[3], {}).get(e[4])
            if c2 is None: continue
            k = (e[3], c2, e[1])
            if k in seen: continue
            seen.add(k); res.append(((e[3], c2), ('conn', e[1], None, True)))
    return res
