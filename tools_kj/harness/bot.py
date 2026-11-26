# bot.py : カントー＆ジョウト版を自動で歩かせる（通しテスト用）
# エミュレーター（harness/srv）を起動したまま命令を送り、マップの当たり判定を読んで道を探して歩く。
import subprocess, json, re, os, collections, time

SRC = '/home/claude/src/HeartSoul-JP'
DIRS = {'U': (0, -1), 'D': (0, 1), 'L': (-1, 0), 'R': (1, 0)}
OPP = {'U': 'D', 'D': 'U', 'L': 'R', 'R': 'L'}

def load_syms():
    syms = {}
    out = subprocess.run(['/home/claude/tc/xpack-arm-none-eabi-gcc-14.2.1-1.1/bin/arm-none-eabi-nm', os.environ.get('ROMELF') or ('/tmp/play/rom.elf' if os.path.exists('/tmp/play/rom.elf') else f'{SRC}/pokehns.elf')], capture_output=True, text=True).stdout
    for l in out.splitlines():
        p = l.split()
        if len(p) == 3: syms.setdefault(p[2], int(p[0], 16))
    return syms

def load_mb():
    s = open(f'{SRC}/include/constants/metatile_behaviors.h').read()
    names = re.findall(r'^\s+(MB_\w+)', s, re.M)
    return {n: i for i, n in enumerate(names)}

def load_flags():
    import re, glob
    raw = {}
    for fn in sorted(glob.glob('/home/claude/src/HeartSoul-JP/include/constants/*.h'), key=lambda f: (0 if ('_hns' in f or '_kj' in f) else 1, f)):
        for m in re.finditer(r'^#define\s+(\w+)\s+([^\n/]+)', open(fn).read(), re.M):
            raw.setdefault(m.group(1), m.group(2).strip())
    cache = {}
    def ev(n, d=0):
        if n in cache: return cache[n]
        if d > 30 or n not in raw: raise KeyError(n)
        e = re.sub(r'\b([A-Za-z_]\w*)\b', lambda m: str(ev(m.group(1), d + 1)), raw[n])
        v = int(eval(e, {})); cache[n] = v; return v
    class L(dict):
        def __missing__(self, k): return ev(k)
    return L()

def load_maps():
    hdr = open(f'{SRC}/include/constants/map_groups.h').read()
    consts = {m.group(1): (int(m.group(2)), int(m.group(3))) for m in re.finditer(r'(MAP_\w+)\s*=\s*\((\d+) \| \((\d+) << 8\)\)', hdr)}
    g = json.load(open(f'{SRC}/data/maps/map_groups.json'))
    info = {}
    for gname in g['group_order']:
        for name in g[gname]:
            p = f'{SRC}/data/maps/{name}/map.json'
            if not os.path.exists(p): continue
            j = json.load(open(p))
            if j['id'] not in consts: continue
            info[consts[j['id']]] = dict(id=j['id'], name=name, warps=j.get('warp_events') or [],
                                         conns=j.get('connections') or [], objs=j.get('object_events') or [],
                                         bgs=j.get('bg_events') or [])
    byid = {v['id']: k for k, v in info.items()}
    return info, byid

class Bot:
    def __init__(self, rom, sav, state='-', outdir=None, log=None):
        outdir = outdir or os.environ.get('PLAYDIR', '/tmp/play'); log = log or outdir + '/log.txt'
        os.makedirs(outdir, exist_ok=True)
        self.outdir = outdir
        self.p = subprocess.Popen(['/home/claude/harness/srv', rom, sav, state, outdir], stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE, text=True, bufsize=1)
        self.S = load_syms(); self.MB = load_mb(); self.maps, self.mapid = load_maps(); self.F = load_flags()
        self.logf = open(log, 'a'); self.shotn = 0; self.lastmap = None
        self.surfing = False
        mb = self.MB
        self.WATER = {mb[n] for n in mb if n in ('MB_POND_WATER', 'MB_INTERIOR_DEEP_WATER', 'MB_DEEP_WATER', 'MB_OCEAN_WATER',
                      'MB_SEMI_DEEP_WATER', 'MB_FAST_WATER', 'MB_SOOTOPOLIS_DEEP_WATER', 'MB_NO_SURFACING', 'MB_EASTWARD_CURRENT',
                      'MB_WESTWARD_CURRENT', 'MB_NORTHWARD_CURRENT', 'MB_SOUTHWARD_CURRENT', 'MB_WATERFALL')}
        self.JUMP = {mb['MB_JUMP_EAST']: 'R', mb['MB_JUMP_WEST']: 'L', mb['MB_JUMP_NORTH']: 'U', mb['MB_JUMP_SOUTH']: 'D'}
        self.BLOCK = {mb[n] for n in mb if n in ('MB_COUNTER', 'MB_IMPASSABLE_EAST')}
        self.ARROW = {mb['MB_EAST_ARROW_WARP']: 'R', mb['MB_WEST_ARROW_WARP']: 'L', mb['MB_NORTH_ARROW_WARP']: 'U',
                      mb['MB_SOUTH_ARROW_WARP']: 'D', mb.get('MB_WATER_SOUTH_ARROW_WARP', -1): 'D'}
        for n, v in mb.items():
            if 'STAIR_WARP' in n: self.ARROW[v] = 'L' if 'LEFT' in n else 'R'
        self.attr_cache = {}
        self.SPIN = {mb['MB_SPIN_RIGHT']: 'R', mb['MB_SPIN_LEFT']: 'L', mb['MB_SPIN_UP']: 'U', mb['MB_SPIN_DOWN']: 'D'}

    # ---------------- 低いところ
    def cmd(self, *lines):
        out = []
        for l in lines:
            self.p.stdin.write(l + '\n')
        self.p.stdin.flush()
        n = len(lines)
        while n:
            r = self.p.stdout.readline()
            if not r: raise RuntimeError('emulator died')
            r = r.rstrip('\n')
            if r == '.': n -= 1
            else: out.append(r)
        return out
    def wait(self, n): self.cmd(f'w {n}')
    capture = None
    def press(self, k, n=4, after=4):
        self.cmd(f'p {k} {n}', f'w {after}')
        if self.capture and k in 'AB' and not self.in_battle():
            self._capn = getattr(self, '_capn', 0) + 1
            if self._capn % 3 == 0: self.shot(f'{self.capture}_{self._capn:06d}')
    def r8(self, a): return int(self.cmd(f'r8 {a:x}')[0].split()[1], 16)
    def r16(self, a): return int(self.cmd(f'r16 {a:x}')[0].split()[1], 16)
    def r32(self, a): return int(self.cmd(f'r32 {a:x}')[0].split()[1], 16)
    def rd(self, a, n): return bytes.fromhex(self.cmd(f'rd {a:x} {n:x}')[0])
    def save(self, path): self.cmd(f'save {path}')
    def load(self, path): self.cmd(f'load {path}')
    def shot(self, name):
        self.cmd(f'shot {name}')
        return f'{self.outdir}/{name}.ppm'
    def log(self, *a):
        s = ' '.join(str(x) for x in a); print(s, flush=True); self.logf.write(s + '\n'); self.logf.flush()

    # ---------------- じょうたい
    def cb2(self): return self.r32(self.S['gMain'] + 4) & ~1
    def in_overworld(self): return self.cb2() in (self.S['CB2_Overworld'], self.S['CB2_OverworldBasic'])
    def in_battle(self):
        c = self.cb2()
        return c in (self.S['BattleMainCB2'], self.S['CB2_InitBattle'], self.S['CB2_InitBattleInternal'], self.S['CB2_HandleStartBattle'])
    def script_running(self):
        b = self.rd(self.S['sGlobalScriptContextStatus'], 2)
        return b[0] != 2 or b[1] != 0 or self.r8(self.S['sFieldMessageBoxMode']) != 0
    def player(self):
        idx = self.r8(self.S['gPlayerAvatar'] + 5)
        o = self.S['gObjectEvents'] + idx * 0x24
        b = self.rd(o, 0x24)
        x = int.from_bytes(b[0x10:0x12], 'little', signed=True) - 7
        y = int.from_bytes(b[0x12:0x14], 'little', signed=True) - 7
        sb = self.r32(self.S['gSaveBlock1Ptr'])
        loc = self.rd(sb + 8, 2)  # location.mapGroup, mapNum
        return x, y, (loc[1], loc[0])  # mapNum, mapGroup
    def mapkey(self):
        x, y, (n, g) = self.player(); return (n, g)
    def objects(self):
        b = self.rd(self.S['gObjectEvents'], 0x24 * 16)
        res = []
        for i in range(16):
            e = b[i * 0x24:(i + 1) * 0x24]
            if not (e[0] & 1): continue
            lid = e[8]
            x = int.from_bytes(e[0x10:0x12], 'little', signed=True) - 7
            y = int.from_bytes(e[0x12:0x14], 'little', signed=True) - 7
            inv = (int.from_bytes(e[0:4], 'little') >> 13) & 1  # invisible
            res.append(dict(lid=lid, x=x, y=y, gfx=int.from_bytes(e[4:6], 'little'), invisible=inv))
        return res
    def party(self):
        n = self.r8(self.S['gPlayerPartyCount'])
        res = []
        for i in range(n):
            b = self.rd(self.S['gPlayerParty'] + i * 0x64 + 0x56, 6)  # level(0x54?)
            res.append(b)
        return n

    # ---------------- マップ
    def grid(self):
        S = self.S
        w, h, ptr = int.from_bytes(self.rd(S['gBackupMapLayout'], 4), 'little'), int.from_bytes(self.rd(S['gBackupMapLayout'] + 4, 4), 'little'), self.r32(S['gBackupMapLayout'] + 8)
        raw = self.rd(ptr, w * h * 2)
        cells = [int.from_bytes(raw[i:i + 2], 'little') for i in range(0, len(raw), 2)]
        lay = self.r32(S['gMapHeader'])
        lb = self.rd(lay, 0x1C)
        prim, sec = int.from_bytes(lb[0x10:0x14], 'little'), int.from_bytes(lb[0x14:0x18], 'little')
        ver = lb[0x18]
        key = (prim, sec, ver)
        if key not in self.attr_cache:
            sz = 4 if ver == 1 else 2
            nprim = 512 if ver == 0 else 640
            pa = self.r32(prim + 0x10); sa = self.r32(sec + 0x10)
            pr = self.rd(pa, nprim * sz); sr = self.rd(sa, (1024 - nprim) * sz)
            def dec(r):
                return [int.from_bytes(r[i:i + sz], 'little') for i in range(0, len(r), sz)]
            mask = 0x1FF if ver == 1 else 0xFF
            self.attr_cache[key] = ([a & mask for a in dec(pr)], [a & mask for a in dec(sr)], nprim)
        pa, sa, nprim = self.attr_cache[key]
        def beh(c):
            m = c & 0x3FF
            if m < nprim: return pa[m] if m < len(pa) else 0
            m -= nprim
            return sa[m] if m < len(sa) else 0
        return dict(w=w, h=h, cells=cells, beh=beh)

    def tile(self, g, x, y):
        X, Y = x + 7, y + 7
        if X < 0 or Y < 0 or X >= g['w'] or Y >= g['h']: return None
        return g['cells'][X + Y * g['w']]

    def can_enter(self, g, x, y, d, blocked):
        if not (0 <= x < g['w'] - 15 and 0 <= y < g['h'] - 14): return False  # マップの　そとは　だめ
        c = self.tile(g, x, y)
        if c is None: return False
        if (x, y) in blocked: return False
        b = g['beh'](c)
        if b in self.JUMP: return self.JUMP[b] == d
        dx, dy = DIRS[d]; pc = self.tile(g, x - dx, y - dy)
        if pc is not None and b not in self.JUMP and g['beh'](pc) not in self.JUMP and not (self.surfing and (b in self.WATER or g['beh'](pc) in self.WATER) and ((c >> 12) if b not in self.WATER else (pc >> 12)) in (0, 1, 3, 15)):
            e1, e2 = pc >> 12, c >> 12  # たかさ（はし・がけ）
            if not (e1 == e2 or e1 in (0, 15) or e2 in (0, 15)): return False
        if (c & 0x0C00) and b not in self.WATER: return False
        if b in self.WATER: return self.surfing and not (c & 0x0C00)
        return True

    def bfs(self, targets, avoid_objs=True, maxn=20000):
        g = self.grid(); x0, y0, _ = self.player()
        blocked = set()
        if avoid_objs:
            seen = Bot.SEENOBJ.setdefault(self.mapkey(), {})
            live = set()
            for o in self.objects():
                if o['lid'] in (0xFF, 0xFE) or o['invisible']: continue
                blocked.add((o['x'], o['y'])); seen[o['lid']] = (o['x'], o['y']); live.add(o['lid'])
            # カメラの　そとで　みえない　人も、さいごに　見た　ばしょに　いると　する
            px, py, _ = self.player()
            for lid, pos in seen.items():
                if lid not in live and (abs(pos[0] - px) > 7 or abs(pos[1] - py) > 5): blocked.add(pos)
        info = self.maps.get(self.mapkey())
        if info:  # ほかの　ワープの　マスは　ふまない
            for i, w in enumerate(info['warps']):
                try: self_w = w['dest_map'] == info['id'] and int(w['dest_warp_id']) == i
                except ValueError: self_w = False
                if not self_w: blocked.add((w['x'], w['y']))  # じぶんへの　ワープ（おちた　ときの　ついたばしょ）は　ふんで　よい
            import graph  # きれない　木・こわせない　岩（まだ　でて　いなくても）
            ab = self.abilities()
            blocked |= {t for t in graph.blocked_objs(info['objs'], ab[1], ab[2])
                        if not any(o['x'] == t[0] and o['y'] == t[1] and o.get('script', '').endswith('StrengthBoulder') for o in info['objs'])}
        blocked |= self.tmp_block | Bot.TBLOCK.get(self.mapkey(), set())
        tset = set(targets)
        prev = {(x0, y0): None}; q = collections.deque([(x0, y0)])
        while q:
            cur = q.popleft()
            if cur in tset and cur != (x0, y0) or (cur in tset and len(tset) == 1 and cur == (x0, y0)):
                path = []
                while prev[cur]:
                    pc, d = prev[cur]; path.append(d); cur = pc
                return path[::-1]
            x, y = cur
            for d, (dx, dy) in DIRS.items():
                nx, ny = x + dx, y + dy
                if (nx, ny) in prev: continue
                if not self.can_enter(g, nx, ny, d, blocked - tset): continue
                b = g['beh'](self.tile(g, nx, ny))
                if b in self.JUMP:  # とびおりる：2マス
                    nx, ny = nx + dx, ny + dy
                    if (nx, ny) in prev: continue
                k = 0
                ice = self.MB.get('MB_ICE')
                if b == ice:  # こおりの　ゆか：かべ（はいれない　マス）まで　おなじ　むきに　すべる
                    while k < 80:
                        k += 1
                        if g['beh'](self.tile(g, nx, ny)) != ice: break
                        if not self.can_enter(g, nx + dx, ny + dy, d, blocked - tset): break
                        nx, ny = nx + dx, ny + dy
                if b in self.SPIN:  # かいてんゆか：とまる　マスか　かべまで　すべる（やじるしで　むきが　かわる）
                    sd = self.SPIN[b]; stop = self.MB.get('MB_STOP_SPINNING')
                    while k < 80:
                        k += 1
                        sx, sy = DIRS[sd]
                        if not self.can_enter(g, nx + sx, ny + sy, sd, blocked - tset): break
                        nx, ny = nx + sx, ny + sy; b = g['beh'](self.tile(g, nx, ny))
                        if b == stop: break
                        if b in self.SPIN: sd = self.SPIN[b]
                if (nx, ny) in prev: continue
                prev[(nx, ny)] = ((x, y), d); q.append((nx, ny))
        return None

    # ---------------- うごく
    def on_water(self):
        return bool(self.r8(self.S['gPlayerAvatar']) & 8)
    def step(self, d):
        x, y, m = self.player()
        if self.surfing and not self.on_water():  # みずへ　はいる　ときは　なみのり
            g = self.grid(); dx, dy = DIRS[d]; c = self.tile(g, x + dx, y + dy)
            if c is not None and g['beh'](c) in self.WATER:
                self.face(d); self.press('A', 2, 40)
                for i in range(6): self.press('A', 2, 30)
                for k in range(30):
                    self.wait(10)
                    if not self.busy(): break
                if (self.player()[:2]) != (x, y): self.settle(); return True
        for t in range(6):
            self.cmd(f'p {d} 2')
            for k in range(12):
                self.wait(2)
                x2, y2, m2 = self.player()
                if (x2, y2, m2) != (x, y, m):
                    self.settle(); return True
            if self.busy(): self.handle_busy(); return 'event'
        return False

    def settle(self):
        self.wait(14)
    def moving(self):
        idx = self.r8(self.S['gPlayerAvatar'] + 5)
        f = self.r32(self.S['gObjectEvents'] + idx * 0x24)
        return bool(f & (1 << 2)) or bool(f & (1 << 1))  # heldMovementActive / singleMovementActive 付近

    def yesno_active(self):
        f = self.S.get('Task_HandleYesNoInput')
        if not f: return False
        d = self.rd(self.S['gTasks'], 40 * 16)
        for i in range(16):
            fn = int.from_bytes(d[i * 40:i * 40 + 4], 'little'); act = d[i * 40 + 4]
            if act and (fn & ~1) == (f & ~1): return True
        return False
    def answer(self, answers):
        # はい／いいえを　じゅんに　こたえる（'Y' / 'N'）
        for a in answers:
            for i in range(80):
                if self.yesno_active(): break
                self.press('A', 2, 10)
            else: return False
            self.wait(20)  # でた　ばかりの　まどは　キーを　うけつけない
            if a == 'N': self.press('D', 4, 15)  # B は　キャンセルで　いいえ　には　ならない
            self.press('A', 2, 30)
            for i in range(20):
                if not self.yesno_active(): break
                self.wait(5)
        self.handle_busy(); return True
    def busy(self):
        return (not self.in_overworld()) or self.script_running()

    def handle_busy(self, limit=4000, yes=True):
        n = 0
        while self.busy() and n < limit:
            n += 1
            if self.in_battle(): self.battle(); continue
            cb = self.cb2()
            if cb == self.S.get('CB2_NamingScreen') or cb == self.S.get('CB2_LoadNamingScreen'):
                self.press('S', 2, 10); self.press('A', 2, 30); continue
            if cb == self.S.get('CB2_WallClock'):  # とけいの　せってい：はい　を　えらぶ
                self.press('B', 4, 90); self.press('A', 4, 120); self.cmd('p U 8', 'w 40', 'p U 1', 'w 40'); self.press('A', 4, 120); continue
            if cb == self.S.get('CB2_UpdatePartyMenu'):  # ふたりがかりの　メンバーを　えらぶ：START で　けってい　へ
                self.press('S', 2, 20); self.press('A', 2, 40); continue
            if cb == self.S.get('CB2_WhiteOut'):
                self.log('WHITEOUT'); self.wait(60); continue
            self.press('A', 2, 10)
        self.check_map()
        return n

    def battle(self):
        self.evcount += 1
        self.log('battle start', 'trainer' if self.r32(self.S['gBattleTypeFlags']) & 8 else 'wild')
        self.shot_now('battle')
        t = 0; stall = 0; lasthp = None
        while self.in_battle() and t < 3000:
            t += 1
            trainer = self.r32(self.S['gBattleTypeFlags']) & 8
            if bytes([0x01, 0x07, 0x27, 0x22]) in self.rd(self.S['gDisplayedStringBattle'], 120):
                # 「〜を　おぼえさせるのを　あきらめますか？」（さいしょは　いいえ）：はい　を　えらぶ
                self.press('U', 2, 10); self.press('A', 2, 30); continue
            if not trainer and not self.grinding and t < 60:  # にげられない　ときは　たたかう
                self.cmd(f"w8 {self.S['gActionSelectionCursor']:x} 3"); self.press('A', 2, 20)
            else:
                hp = self.rd(self.S['gBattleMons'] + 0x88 + 0x2A, 2) + self.rd(self.S['gBattleMons'] + 0x88, 2)  # あいての　HP と　しゅるい
                if hp == lasthp: stall += 1
                else: stall = 0; lasthp = hp
                rank = self.best_move(rank=True)
                self.lead_pp = self.damage_pp()
                mv = rank[(stall // 10) % len(rank)] if rank else 0
                self.cmd(f"w8 {self.S['gActionSelectionCursor']:x} 0", f"w8 {self.S['gMoveSelectionCursor']:x} {mv}")
                self.press('A', 2, 12)
        self.wait(30)
        self.log('battle end')
    grinding = False
    evcount = 0
    MOVES = None
    lead_pp = 99
    def damage_pp(self):
        if Bot.MOVES is None: return 99
        me = self.rd(self.S['gBattleMons'], 0x30); t = 0
        for i in range(4):
            mv = int.from_bytes(me[0x0C + 2 * i:0x0E + 2 * i], 'little')
            if mv and Bot.MOVES.get(mv, (0,))[0] > 0: t += me[0x25 + i]
        return t
    def need_heal(self):
        hp = self.party_hp()
        if not hp: return False
        lv, h, m = hp[0]
        return (m and h * 10 < m * 4) or self.lead_pp < 8
    def heal_nearest(self):
        import graph
        comp = self.gcomp(); start = self.my_node(comp)
        if start is None: return False
        prev = {start: None}; q = collections.deque([start])
        while q:
            n = q.popleft()
            nm = self.maps[n[0]]['id']
            if nm.endswith('POKEMON_CENTER_1F') or nm.endswith('POKEMON_CENTER_HNS'):
                self.log('AUTOHEAL', nm)
                ok = self.heal(nm); self.lead_pp = 99; return ok
            for m, e in graph.out_edges(Bot.G, comp, n, self.live_ledges):
                if m not in prev: prev[m] = n; q.append(m)
        return False
    def best_move(self, rank=False):
        import moves
        if Bot.MOVES is None: Bot.MOVES = moves.load()
        b = self.rd(self.S['gBattleMons'], 0x88 * 2)
        me, en = b[:0x88], b[0x88:]
        mytypes = set(me[0x22:0x25]); entypes = list(en[0x22:0x25])
        sc = []
        for i in range(4):
            mv = int.from_bytes(me[0x0C + 2 * i:0x0E + 2 * i], 'little')
            if not mv or me[0x25 + i] == 0: continue
            pw, ty, _ = Bot.MOVES.get(mv, (0, 0, ''))
            sc.append((pw * (1.5 if ty in mytypes else 1) * moves.eff(ty, entypes) + 0.01, i))
        sc.sort(reverse=True)
        if rank: return [i for _, i in sc]
        return sc[0][1] if sc else 0

    def shot_now(self, tag):
        self.shotn += 1
        self.shot(f'{self.shotn:05d}_{tag}')

    def check_map(self):
        k = self.mapkey() if self.in_overworld() else None
        if k and k != self.lastmap:
            self.prevmap = self.lastmap
            self.lastmap = k
            self.cleared = set()
            name = self.maps.get(k, {}).get('id', str(k))
            self.wait(40)
            self.log('MAP', name, self.player()[:2])
            self.shot_now(name[4:24])

    def spinning(self):
        # すべって　いる　あいだは　いちが　かわりつづける
        a = self.player()[:2]; self.wait(20); return self.player()[:2] != a
    def walk_path(self, path):
        g = self.grid()
        for d in path:
            x, y, _ = self.player()
            r = self.step(d)
            if r is False:  # とおれなかった　マスは　さける（このマップでは　ずっと）
                t = (x + DIRS[d][0], y + DIRS[d][1])
                self.tmp_block.add(t); Bot.TBLOCK.setdefault(self.mapkey(), set()).add(t)
            if r is not True: return r
            c = self.tile(g, *self.player()[:2])
            if c is not None and (g['beh'](c) in self.SPIN or g['beh'](c) == self.MB.get('MB_ICE')) or self.spinning():  # すべりおわるまで　まつ
                last = None
                for k in range(60):
                    self.wait(8); p = self.player()[:2]
                    if p == last: break
                    last = p
                return 'resync'
        return True

    tmp_block = set()
    def goto(self, targets, tries=40):
        if isinstance(targets, tuple): targets = [targets]
        if not getattr(self, '_in_goto', False): self.tmp_block = set()
        for k in range(40):
            if not self.spinning(): break
        for t in range(tries):
            x, y, _ = self.player()
            if (x, y) in targets: return True
            path = self.bfs(targets)
            if path is None:
                if not getattr(self, '_clearing', False):
                    self._clearing = True
                    try: cl = self.clear_obstacles()
                    finally: self._clearing = False
                    if cl: continue
                path = self.bfs(targets, avoid_objs=False)
                if path is None:
                    self.log('NOPATH', targets, (x, y)); return False
            r = self.walk_path(path)
            if r is True: return True
            self.handle_busy()
        x, y, _ = self.player()
        return (x, y) in targets

    def face(self, d):
        self.cmd(f'p {d} 1', 'w 6')

    def use_bg(self, x, y):
        # しらべる　ばしょ（むきの　きまりが　あれば　それに　あわせる）
        bg = next((g for g in self.maps[self.mapkey()].get('bgs', []) if g['x'] == x and g['y'] == y), None)
        fd = (bg or {}).get('player_facing_dir', '')
        need = {'BG_EVENT_PLAYER_FACING_NORTH': ('U', (0, 1)), 'BG_EVENT_PLAYER_FACING_SOUTH': ('D', (0, -1)),
                'BG_EVENT_PLAYER_FACING_EAST': ('R', (-1, 0)), 'BG_EVENT_PLAYER_FACING_WEST': ('L', (1, 0))}.get(fd)
        if not need: return self.talk_at(x, y)
        d, (dx, dy) = need
        if not self.goto([(x + dx, y + dy)]): return False
        self.face(d); self.press('A', 2, 10); self.handle_busy(); return True
    def talk_at(self, x, y, yes=True):
        # (x,y) の 人・物の となりに 行って　話す
        adj = [(x + dx, y + dy, OPP[d]) for d, (dx, dy) in DIRS.items()]
        g = self.grid(); cnt = self.MB.get('MB_COUNTER', -1)
        for d, (dx, dy) in DIRS.items():  # カウンターごしに　はなす
            c = self.tile(g, x + dx, y + dy)
            if c is not None and g['beh'](c) == cnt: adj.append((x + 2 * dx, y + 2 * dy, OPP[d]))
        occ = {(o['x'], o['y']) for o in self.objects() if o['lid'] not in (0xFF, 0xFE) and not o['invisible']}
        adj = [t for t in adj if (t[0], t[1]) not in occ]
        if not self.goto([(a, b) for a, b, _ in adj]): return False
        px, py, _ = self.player()
        for a, b, d in adj:
            if (a, b) == (px, py): self.face(d); break
        self.press('A', 2, 10)
        self.handle_busy()
        return True

    def talk_lid(self, lid):
        for o in self.objects():
            if o['lid'] == lid: return self.talk_at(o['x'], o['y'])
        self.log('NOOBJ', lid); return False

    # ---------------- マップの　いどう
    def exits_to(self, cur, dest):
        info = self.maps[cur]; res = []
        for w in info['warps']:
            if w['dest_map'] == self.maps[dest]['id']: res.append(('warp', w['x'], w['y']))
        for c in info['conns']:
            if c['map'] == self.maps[dest]['id']: res.append(('conn', c['direction']))
        return res

    def route(self, dest):
        cur = self.mapkey(); prev = {cur: None}; q = collections.deque([cur])
        while q:
            m = q.popleft()
            if m == dest: break
            info = self.maps.get(m)
            if not info: continue
            nxt = [self.mapid.get(w['dest_map']) for w in info['warps']] + [self.mapid.get(c['map']) for c in info['conns']]
            for n in nxt:
                if n and n not in prev: prev[n] = m; q.append(n)
        if dest not in prev: return None
        path = []; m = dest
        while prev[m]: path.append(m); m = prev[m]
        return path[::-1]

    def mapdist(self, dest):
        # マップの　つながりだけで　みた　目的地までの　きょり
        if getattr(self, '_md_dest', None) == dest: return self._md
        rev = collections.defaultdict(set)
        for k, info in self.maps.items():
            for w in info['warps']:
                d = self.mapid.get(w['dest_map'])
                if d: rev[d].add(k)
            for c in info['conns']:
                d = self.mapid.get(c['map'])
                if d: rev[d].add(k)
        dist = {dest: 0}; q = collections.deque([dest])
        while q:
            m = q.popleft()
            for n in rev[m]:
                if n not in dist: dist[n] = dist[m] + 1; q.append(n)
        self._md_dest, self._md = dest, dist
        return dist

    def reachable_exits(self):
        cur = self.mapkey(); info = self.maps[cur]; res = []
        for i, w in enumerate(info['warps']):
            d = self.mapid.get(w['dest_map'])
            if not d: continue
            tgt = [(w['x'], w['y'])] + [(w['x'] + dx, w['y'] + dy) for dx, dy in DIRS.values()]
            if self.bfs(tgt) is not None or self.player()[:2] in tgt: res.append(('warp', w['x'], w['y'], d))
        for c in info['conns']:
            d = self.mapid.get(c['map'])
            if d: res.append(('conn', c['direction'], None, d))
        return res

    def go_map_explore(self, dest_id, avoid=(), limit=80):
        dest = self.mapid[dest_id]
        dist = self.mapdist(dest)
        failed = set(); uses = collections.Counter(); cleared_once = False
        for attempt in range(limit):
            cur = self.mapkey()
            if cur == dest: return True
            ex = [e for e in self.reachable_exits() if (cur, e[1], e[2]) not in failed and e[3] in dist]
            if not ex:
                if self.clear_obstacles() or not cleared_once:
                    failed = set(); cleared_once = True; continue
                self.log('STUCK in', self.maps[cur]['id'], 'to', dest_id); return False
            g = self.grid()
            def zero(e):  # まんなかの　マット　いがいの　ワープは　あとまわし
                if e[0] != 'warp': return 0
                c = self.tile(g, e[1], e[2]); return 0.5 if c is not None and g['beh'](c) == 0 else 0
            ex.sort(key=lambda e: dist[e[3]] + 4 * uses[(cur, e[1], e[2])] + zero(e))
            e = ex[0]; k = (cur, e[1], e[2]); uses[k] += 1
            if e[0] == 'warp': self.take_warp(e[1], e[2])
            else: self.take_conn(e[1])
            for t in range(10):
                if self.mapkey() != cur: break
                self.wait(10)
            self.handle_busy()
            if self.mapkey() == cur:
                failed.add(k); self.log('exit failed', self.maps[cur]['id'], e[:3])
        return self.mapkey() == dest

    G = None
    LIVE = {}
    TBLOCK = {}
    SEENOBJ = {}
    AVOID = ('MAP_SEAFOAM_ISLANDS',)  # とおらない　ところ（なぞときが　ある　ばしょ）
    BAD = set()  # とおれなかった　えだ（ストーリーが　すすむと　けす）
    def abilities(self):
        f = self.flag
        if not self.surfing and (f('FLAG_KJ_RECEIVED_HM_SURF') or f('FLAG_RECEIVED_HM_SURF')) and (f('FLAG_BADGE13_GET') or f('FLAG_BADGE04_GET')):
            self.surfing = True
        cut = (f('FLAG_RECEIVED_HM_CUT') or f('FLAG_KJ_RECEIVED_HM_CUT')) and (f('FLAG_BADGE10_GET') or f('FLAG_BADGE02_GET'))
        smash = f('FLAG_RECEIVED_HM_ROCK_SMASH') and (f('FLAG_BADGE14_GET') or f('FLAG_BADGE01_GET'))
        return bool(self.surfing), bool(cut), bool(smash)
    def gcomp(self):
        # しずかな　グラフ　＋　いま　いる　マップは　じっさいの　マップで
        import graph
        graph.SPIN = self.SPIN; graph.STOP = self.MB.get('MB_STOP_SPINNING')
        if Bot.G is None: Bot.G = graph.build(self)
        ab = self.abilities()
        comp = dict(Bot.G['comps'][ab])
        for k2, (ab2, c2, l2) in Bot.LIVE.items():  # まえに　いった　ときの　じっさいの　かたち
            if ab2 == ab: comp[k2] = c2
        key = self.mapkey(); g = self.grid(); W, H = g['w'] - 15, g['h'] - 14
        blk = graph.blocked_objs(self.maps[key]['objs'], ab[1], ab[2])
        live = {(o['x'], o['y']) for o in self.objects()}
        blk = {t for t in blk if t in live or abs(t[0] - self.player()[0]) > 8 or abs(t[1] - self.player()[1]) > 6}
        blk |= Bot.TBLOCK.get(key, set())
        blk |= {(wp['x'], wp['y']) for wp in self.maps[key]['warps']}  # ワープの　マスは　とおりぬけない
        objs = self.maps[key]['objs']
        def clearable(o):  # きれる　木・こわせる　岩は　かべに　しない
            if not (1 <= o['lid'] <= len(objs)): return False
            sc = objs[o['lid'] - 1].get('script', '')
            return (sc.endswith('CutTree') and ab[1]) or (sc.endswith('RockSmash') and ab[2])
        oblk = {(o['x'], o['y']) for o in self.objects() if o['lid'] not in (0xFF, 0xFE) and not o['invisible'] and not clearable(o)}
        def beh(c): return g['beh'](c)
        cells = [self.tile(g, x, y) or 0 for y in range(H) for x in range(W)]
        doors = {(bg['x'], bg['y']) for bg in self.maps[key]['bgs'] if 'EventScript_Door' in (bg.get('script') or '')} if self.flag('FLAG_KJ_HIDE_SILPH_CO_5F_CARD_KEY') else set()
        wf = (lambda c: beh(c) in self.WATER) if ab[0] else None
        base = graph.components(W, H, graph.make_ok(W, H, cells, beh, blk, ab[0], self.WATER, self.JUMP, allow=doors), cells, wf)
        comp[key] = graph.components(W, H, graph.make_ok(W, H, cells, beh, blk | oblk, ab[0], self.WATER, self.JUMP, allow=doors), cells, wf)
        walk = graph.make_ok(W, H, cells, beh, blk, ab[0], self.WATER, self.JUMP, spin_wall=False)
        lg = graph.ledges(W, H, cells, beh, self.JUMP, walk)
        Bot.LIVE[key] = (ab, base, lg)  # おぼえるのは　ひとを　のぞいた　かたち
        self.live_ledges = {k2: v[2] for k2, v in Bot.LIVE.items() if v[0] == ab}
        return comp
    def my_node(self, comp):
        x, y, _ = self.player(); k = self.mapkey(); cm = comp.get(k, {})
        for dx, dy in [(0, 0)] + list(DIRS.values()):
            c = cm.get((x + dx, y + dy))
            if c is not None: return (k, c)
        return None
    def go_tile(self, mapkey, x, y):
        import graph
        comp = self.gcomp()
        goals = {(mapkey, c) for c in graph.near(comp.get(mapkey, {}), x, y)}
        if not goals: return False
        return self.go_map(self.maps[mapkey]['id'], goals=goals)
    def go_map(self, dest_id, avoid=(), limit=60, goals=None, explore=True):
        import graph
        dest = self.mapid[dest_id]; bad = set(Bot.BAD); fails = collections.Counter()
        for attempt in range(limit):
            if self.need_heal() and not getattr(self, 'healing', False):
                self.healing = True
                try: self.heal_nearest()
                finally: self.healing = False
            comp = self.gcomp()
            start = self.my_node(comp)
            if goals is None and self.mapkey() == dest: return True
            if goals is not None and start in goals: return True
            if start is None:
                self.wait(30); self.handle_busy()
                comp = self.gcomp(); start = self.my_node(comp)
                if start is None: self.log('NO NODE', self.player()); break
            prev = {start: None}; q = collections.deque([start]); goal = None
            while q:
                n = q.popleft()
                if (goals is None and n[0] == dest) or (goals is not None and n in goals): goal = n; break
                for m, e in graph.out_edges(Bot.G, comp, n, self.live_ledges):
                    if m in prev or (n, e[0], e[1], e[2]) in bad: continue
                    if m[0] != dest and any(self.maps[m[0]]['id'].startswith(a) for a in Bot.AVOID): continue
                    prev[m] = (n, e); q.append(m)
            if goal is None: break
            n = goal; first = None; plan = []; nxt = None
            while prev[n]: first = prev[n][1]; nxt = n; plan.append((self.maps[n[0]]['id'][4:], n[1], first[0])); n = prev[n][0]
            if os.environ.get('PLANLOG'): self.log('PLAN', start, plan[::-1][:6])
            cur = self.mapkey(); ev0 = self.evcount
            if first[0] == 'warp': self.take_warp(first[1], first[2])
            elif first[0] == 'ledge':
                if self.goto([first[1]]):
                    self.step(first[2]); self.handle_busy()
                    for k in range(40):
                        if not self.spinning(): break
            else:
                cm0 = comp.get(cur, {}); cmd = comp.get(nxt[0], {})
                cands = [e[2] for e in Bot.G['exits'].get(cur, ()) if e[0] == 'conn' and e[1] == first[1]
                         and e[3] == nxt[0] and cm0.get(e[2]) == start[1] and cmd.get(e[4]) == nxt[1]]
                self.take_conn(first[1], cands or None)
            for t in range(10):
                if self.mapkey() != cur or first[0] == 'ledge': break
                self.wait(10)
            self.handle_busy()
            if self.my_node(self.gcomp()) == start:
                ek = (start, first[0], first[1], first[2])
                if self.evcount == ev0: fails[ek] += 1
                if fails[ek] >= 2: bad.add(ek); Bot.BAD.add(ek)
                self.log('edge failed', self.maps[cur]['id'], first)
                if self.clear_obstacles(): bad.discard((start, first[0], first[1], first[2]))
        if goals is not None: return self.my_node(self.gcomp()) in goals
        if self.mapkey() == dest: return True
        if not explore: return False
        self.log('graph route failed -> explore', dest_id)
        return self.go_map_explore(dest_id, avoid)

    def go_map_old(self, dest_id, avoid=()):
        dest = self.mapid[dest_id]
        for attempt in range(30):
            if self.mapkey() == dest: return True
            path = self.route(dest)
            if not path: self.log('NOROUTE', dest_id); return False
            nxt = path[0]; cur = self.mapkey()
            ok = False
            for ex in self.exits_to(cur, nxt):
                if ex[0] == 'warp': ok = self.take_warp(ex[1], ex[2])
                else: ok = self.take_conn(ex[1])
                if self.mapkey() != cur: break
            if self.mapkey() == cur:
                self.log('STUCK leaving', self.maps[cur]['id'], '->', self.maps[nxt]['id'])
                return False
        return self.mapkey() == dest

    def take_warp(self, wx, wy):
        g = self.grid(); cur = self.mapkey()
        b = g['beh'](self.tile(g, wx, wy) or 0)
        # まず　ワープの　マスへ（入れる　なら）、だめなら　となりから　はいる
        p = self.bfs([(wx, wy)])
        if p is not None:
            if len(p) > 1:
                nb = (wx - DIRS[p[-1]][0], wy - DIRS[p[-1]][1])
                self.goto([nb])
                p = self.bfs([(wx, wy)]) or p
            if p: self.step(p[-1])
            self.handle_busy()
            if self.mapkey() != cur: self.check_map(); return True
            # たっている　だけでは　だめ：やじるし　や　かいだん
            for d in ([self.ARROW[b]] if b in self.ARROW else []) + ['U', 'D', 'L', 'R']:
                if self.player()[:2] != (wx, wy):
                    p2 = self.bfs([(wx, wy)])
                    if p2 is None: break
                    self.walk_path(p2)
                    if self.mapkey() != cur: self.check_map(); return True
                self.cmd(f'p {d} 30', 'w 40'); self.handle_busy()
                if self.mapkey() != cur: self.check_map(); return True
        # ドア：したから　うえへ
        adj = [(wx + dx, wy + dy, OPP[d]) for d, (dx, dy) in DIRS.items()]
        for a, bb, d in adj:
            if self.bfs([(a, bb)]) is None and self.player()[:2] != (a, bb): continue
            if not self.goto([(a, bb)]): continue
            self.cmd(f'p {d} 20', 'w 40'); self.handle_busy()
            if self.mapkey() != cur: self.check_map(); return True
        return False

    def take_conn(self, direction, only=None):
        dmap = {'up': 'U', 'down': 'D', 'left': 'L', 'right': 'R'}[direction]
        g = self.grid(); cur = self.mapkey()
        W, H = g['w'] - 15, g['h'] - 14
        if dmap == 'U': cand = [(x, 0) for x in range(W)]
        elif dmap == 'D': cand = [(x, H - 1) for x in range(W)]
        elif dmap == 'L': cand = [(0, y) for y in range(H)]
        else: cand = [(W - 1, y) for y in range(H)]
        cand = [c for c in cand if self.tile(g, *c) is not None and not (self.tile(g, *c) & 0x0C00)]
        if only: cand = [c for c in cand if c in set(only)] or cand
        for t in range(4):
            if not self.goto(cand): return False
            for i in range(4):
                self.step(dmap)
                if self.mapkey() != cur: self.check_map(); return True
            x, y, _ = self.player()
            cand = [c for c in cand if c != (x, y)]
        return False

    def fast_opts(self):
        # はやい　テキスト・せんとう　アニメ　なし・いれかえ　なし（テストを　はやく　する）
        sb2 = self.r32(0x030041d8)
        v = self.r16(sb2 + 0x14)
        v = (v & ~7) | 2 | (1 << 9) | (1 << 10)
        self.cmd(f'w16 {sb2 + 0x14:x} {v:x}')
        sb3 = self.r32(self.S['gSaveBlock3Ptr'])  # けいけんち　2ばい（ゲームの　せっていに　ある　もの）
        e = self.r8(sb3 + 0x19); self.cmd(f'w8 {sb3 + 0x19:x} {(e & ~3) | 2:x}')
    ORD = ['GAEM','GAME','GEAM','GEMA','GMAE','GMEA','AGEM','AGME','AEGM','AEMG','AMGE','AMEG',
           'EGAM','EGMA','EAGM','EAMG','EMGA','EMAG','MGAE','MGEA','MAGE','MAEG','MEGA','MEAG']
    def set_exp(self, i, exp, moves=None, pp=60):
        a = self.S['gPlayerParty'] + i * 0x64
        b = bytearray(self.rd(a, 0x50))
        pid = int.from_bytes(b[0:4], 'little'); otid = int.from_bytes(b[4:8], 'little'); key = pid ^ otid
        sec = bytearray(48)
        for j in range(0, 48, 4):
            sec[j:j + 4] = (int.from_bytes(b[0x20 + j:0x24 + j], 'little') ^ key).to_bytes(4, 'little')
        if sum(int.from_bytes(sec[j:j + 2], 'little') for j in range(0, 48, 2)) & 0xFFFF != int.from_bytes(b[0x1C:0x1E], 'little'):
            self.log('CHECKSUM MISMATCH'); return False
        g = self.ORD[pid % 24].index('G') * 12
        old = int.from_bytes(sec[g + 4:g + 8], 'little')
        new = (old & ~0x1FFFFF) | (exp & 0x1FFFFF)
        sec[g + 4:g + 8] = new.to_bytes(4, 'little')
        if moves:  # わざ（テスト　よう）
            m = self.ORD[pid % 24].index('A') * 12
            for k, mv in enumerate(moves):
                o = int.from_bytes(sec[m + 2 * k:m + 2 * k + 2], 'little')
                sec[m + 2 * k:m + 2 * k + 2] = ((o & ~0x7FF) | mv).to_bytes(2, 'little')
                sec[m + 8 + k] = (sec[m + 8 + k] & 0x80) | pp
        ck = sum(int.from_bytes(sec[j:j + 2], 'little') for j in range(0, 48, 2)) & 0xFFFF
        out = bytearray(48)
        for j in range(0, 48, 4):
            out[j:j + 4] = (int.from_bytes(sec[j:j + 4], 'little') ^ key).to_bytes(4, 'little')
        cmds = [f'w16 {a + 0x1C:x} {ck:x}'] + [f'w32 {a + 0x20 + j:x} {int.from_bytes(out[j:j + 4], "little"):x}' for j in range(0, 48, 4)]
        self.cmd(*cmds)
        return True
    TEST_MOVES = None
    def boost(self, lv=60, st=190, hp=230):
        if lv >= 100: st, hp = 900, 999  # リーグ　よう
        # テストを　はやく　する　ため：てもちの　つよさを　あげる（のうりょくちを　ちょくせつ　かく）
        n = self.r8(self.S['gPlayerPartyCount'])
        for i in range(n):
            a = self.S['gPlayerParty'] + i * 0x64
            n3 = lv ** 3; self.set_exp(i, (6 * n3) // 5 - 15 * lv * lv + 100 * lv - 140, self.TEST_MOVES if i == 0 else None)
            self.cmd(f'w8 {a + 0x54:x} {lv:x}', f'w16 {a + 0x56:x} {hp:x}', f'w16 {a + 0x58:x} {hp:x}',
                     *[f'w16 {a + o:x} {st:x}' for o in (0x5A, 0x5C, 0x5E, 0x60, 0x62)])
        self.log('BOOST', self.party_hp())
    def report(self):
        # レポート（ゲームの　なかで　セーブ）
        self.handle_busy()
        self.press('S', 2, 40)
        n = self.r8(self.S['sNumStartMenuActions'])
        acts = list(self.rd(self.S['sCurrentStartMenuActions'], n))
        if 5 not in acts: self.press('B', 2, 20); self.log('NO SAVE MENU', acts); return False
        self.cmd(f"w8 {self.S['sStartMenuCursorPos']:x} {acts.index(5)}")
        self.press('A', 2, 60)
        for i in range(6): self.press('A', 2, 90)
        self.wait(300)
        for i in range(4): self.press('B', 2, 30)
        self.handle_busy()
        self.log('REPORT')
        return True
    def sb1(self): return self.r32(self.S['gSaveBlock1Ptr'])
    def flag(self, n):
        if isinstance(n, str): n = self.F[n]
        return (self.r8(self.sb1() + 0x198C + n // 8) >> (n % 8)) & 1
    def set_var(self, n, v):
        if isinstance(n, str): n = self.F[n]
        self.cmd(f'w16 {self.sb1() + 0x1B1C + (n - 0x4000) * 2:x} {v:x}')
    def var(self, n):
        if isinstance(n, str): n = self.F[n]
        return self.r16(self.sb1() + 0x1B1C + (n - 0x4000) * 2)
    def clear_obstacles(self):
        # いあいぎり の 木・いわくだき の 岩：となりへ 行けるものを ぜんぶ こわす
        info = self.maps[self.mapkey()]; done = False
        for o in self.objects():
            if not (1 <= o['lid'] <= len(info['objs'])): continue
            sc = info['objs'][o['lid'] - 1].get('script', '')
            item = '_EventScript_Item' in sc and abs(o['x'] - self.player()[0]) + abs(o['y'] - self.player()[1]) <= 6
            if sc.endswith('CutTree') or sc.endswith('RockSmash') or item:
                key = (self.mapkey(), o['lid'])
                if key in self.cleared: continue
                self.cleared.add(key)
                if self.talk_at(o['x'], o['y']):
                    for i in range(8 if item else 0): self.press('A', 2, 15)
                    for i in range(20): self.press('B', 2, 15)
                    self.handle_busy()
                    if not any(p['lid'] == o['lid'] for p in self.objects()):
                        done = True; self.log('CLEAR', sc, o['x'], o['y'])
                        Bot.TBLOCK.get(self.mapkey(), set()).discard((o['x'], o['y'])); Bot.SEENOBJ.get(self.mapkey(), {}).pop(o['lid'], None)
                    else: self.log('CANT CLEAR', sc, o['x'], o['y'])
        # シルフの　ドア（カードキー）
        if self.flag('FLAG_KJ_HIDE_SILPH_CO_5F_CARD_KEY') if 'FLAG_KJ_HIDE_SILPH_CO_5F_CARD_KEY' in str(list(self.F.keys())[:0]) or True else False:
            px, py, _ = self.player()
            seen = set()
            for bgv in sorted(info.get('bgs', []), key=lambda e: abs(e['x'] - px) + abs(e['y'] - py)):
                sc = bgv.get('script', '')
                kinds = ('EventScript_Door', 'EventScript_Quiz', 'EventScript_Quz')
                mansion = 'MANSION' in info['id'] and sc.endswith('EventScript_Statue')
                if not (any(k in sc for k in kinds) or mansion) or sc in seen: continue
                key = (self.mapkey(), sc)
                if key in self.cleared: continue
                if self.bfs([(bgv['x'] + dx, bgv['y'] + dy) for dx, dy in DIRS.values()]) is None: continue
                seen.add(sc); self.cleared.add(key)
                if self.use_bg(bgv['x'], bgv['y']):
                    for i in range(6): self.press('B', 2, 15)
                    self.handle_busy(); done = True; self.log('DOOR', sc)
                    if self.need_heal() and not getattr(self, 'healing', False):
                        self.heal_nearest(); return True
        return done
    cleared = set()

    # ---------------- ストーリーの　てじゅん　ようの　べんり　きのう
    def lid_of(self, sub, mapkey=None):
        info = self.maps[mapkey or self.mapkey()]
        for i, o in enumerate(info['objs']):
            sc = o.get('script', '')
            if sc.endswith(sub) or sc.replace('_Kj', '').endswith(sub): return i + 1
        return None
    def talk(self, sub):
        lid = self.lid_of(sub)
        if lid is None: self.log('NOSCRIPT', sub); return False
        if not any(o['lid'] == lid for o in self.objects()):
            o = self.maps[self.mapkey()]['objs'][lid - 1]
            tx, ty = o['x'], o['y']
            near = [(tx + dx, ty + dy) for dx in range(-3, 4) for dy in range(-3, 4)]
            for k in range(3):
                if self.need_heal() and not getattr(self, 'healing', False): self.heal_nearest()
                p = self.bfs(near)
                if p is None: self.go_tile(self.mapkey(), tx, ty)
                if self.goto(near) and any(o['lid'] == lid for o in self.objects()): break
                self.go_tile(self.mapkey(), tx, ty)
                if any(o['lid'] == lid for o in self.objects()): break
        return self.talk_lid(lid)
    def bg(self, x, y):
        return self.talk_at(x, y)
    def lead(self):
        b = self.rd(self.S['gPlayerParty'] + 0x54, 6)
        return b[0], int.from_bytes(b[2:4], 'little'), int.from_bytes(b[4:6], 'little')
    def party_hp(self):
        n = self.r8(self.S['gPlayerPartyCount']); res = []
        for i in range(n):
            b = self.rd(self.S['gPlayerParty'] + i * 0x64 + 0x54, 6)
            res.append((b[0], int.from_bytes(b[2:4], 'little'), int.from_bytes(b[4:6], 'little')))
        return res
    def heal(self, center):
        self.healing = True
        try: self.go_map(center)
        finally: self.healing = False
        self.lead_pp = 99
        ok = self.talk('Nurse') or self.talk('PokemonCenter_1F_EventScript_Nurse')
        for i in range(30): self.press('A', 2, 20)
        self.handle_busy()
        return ok
    def grass_tiles(self):
        g = self.grid(); res = []
        tg = {self.MB['MB_TALL_GRASS'], self.MB.get('MB_LONG_GRASS', -1)}
        for y in range(g['h'] - 14):
            for x in range(g['w'] - 15):
                c = self.tile(g, x, y)
                if c is not None and g['beh'](c) in tg and not (c & 0x0C00): res.append((x, y))
        return res
    def grind(self, level, area, center, maxbattles=400):
        self.log('GRIND', level, area)
        battles = 0
        while self.lead()[0] < level and battles < maxbattles:
            if self.mapkey() != self.mapid[area]: self.go_map(area)
            gt = self.grass_tiles()
            if not gt: self.log('NOGRASS', area); return False
            x, y, _ = self.player()
            pairs = [(a, b) for a, b in gt if (a + 1, b) in gt]
            pairs.sort(key=lambda t: abs(t[0] - x) + abs(t[1] - y))
            if not pairs or not self.goto([pairs[0]]): self.log('NOGRASSPATH'); return False
            self.grinding = True
            for k in range(60):
                self.step('R'); self.step('L')
                if self.in_battle() or self.script_running():
                    self.handle_busy(); battles += 1
                    lv, hp, mhp = self.lead()
                    if mhp and hp * 2 < mhp or battles % 6 == 0:
                        self.grinding = False; self.heal(center); break
                    if lv >= level: break
            self.grinding = False
        self.log('GRIND done', self.lead(), battles)
        return self.lead()[0] >= level

# ---------------- かいりきの　いわ（いわを　スイッチに　のせる）
def _boulder_methods():
    def boulder_tiles(self):
        info = self.maps[self.mapkey()]; res = {}
        for o in self.objects():
            if 1 <= o['lid'] <= len(info['objs']) and info['objs'][o['lid'] - 1].get('script', '').endswith('StrengthBoulder'):
                res[o['lid']] = (o['x'], o['y'])
        return res
    def solve_boulders(self, switch, maxstates=200000):
        g = self.grid(); W, H = g['w'] - 15, g['h'] - 14
        info = self.maps[self.mapkey()]
        warps = {(w['x'], w['y']) for w in info['warps']}
        others = {(o['x'], o['y']) for o in self.objects() if o['lid'] not in (0xFF, 0xFE) and not o['invisible']}
        bt = self.boulder_tiles()
        others -= set(bt.values())
        def free(x, y, d, prevc):
            if not (0 <= x < W and 0 <= y < H) or (x, y) in warps or (x, y) in others: return False
            c = self.tile(g, x, y)
            if c is None or (c & 0x0C00): return False
            b = g['beh'](c)
            if b in self.WATER or b in self.JUMP: return False
            e1, e2 = prevc >> 12, c >> 12
            return e1 == e2 or e1 in (0, 15) or e2 in (0, 15)
        def reach(p, boulders):
            seen = {p}; q = [p]
            while q:
                x, y = q.pop()
                for d, (dx, dy) in DIRS.items():
                    n = (x + dx, y + dy)
                    if n in seen or n in boulders: continue
                    if not free(n[0], n[1], d, self.tile(g, x, y) or 0): continue
                    seen.add(n); q.append(n)
            return seen
        lids = sorted(bt); bs0 = tuple(bt[l] for l in lids); p0 = self.player()[:2]
        k0 = (bs0, min(reach(p0, set(bs0))))
        prev = {k0: None}; q = collections.deque([(p0, bs0, k0)]); n = 0
        while q and n < maxstates:
            p, bs, key = q.popleft(); n += 1
            if (switch(reach(p, set(bs)), bs) if callable(switch) else switch in bs):
                moves = []; k = key
                while prev[k]: kp, mv = prev[k]; moves.append(mv); k = kp
                return moves[::-1]
            rs = reach(p, set(bs))
            for i, (bx, by) in enumerate(bs):
                for d, (dx, dy) in DIRS.items():
                    behind = (bx - dx, by - dy); dest = (bx + dx, by + dy)
                    if behind not in rs or dest in bs: continue
                    if not free(dest[0], dest[1], d, self.tile(g, bx, by) or 0): continue
                    nb = list(bs); nb[i] = dest; nb = tuple(nb)
                    nk = (nb, min(reach((bx, by), set(nb))))
                    if nk in prev: continue
                    prev[nk] = (key, (lids[i], behind, d)); q.append(((bx, by), nb, nk))
        return None
    def push_moves(self, mv):
        for lid, behind, d in mv:
            bt = self.boulder_tiles()
            if lid not in bt: return False
            if not self.goto([behind]): self.log('BOULDER goto fail', behind); return False
            self.face(d); self.press('A', 2, 20); self.handle_busy()
            for t in range(3):
                if self.boulder_tiles().get(lid) != bt[lid]: break
                self.cmd(f'p {d} 16', 'w 40'); self.handle_busy()
            self.wait(30)
        return True
    def do_boulders(self):
        # この　マップの　おされて　いない　スイッチに　いわを　のせる
        info = self.maps[self.mapkey()]; did = False
        sw = [c for c in json.load(open(f"{SRC}/data/maps/{info['name']}/map.json")).get('coord_events', []) if 'FloorSwitch' in c.get('script', '')]
        for c in sw:
            if self.var(self.F[c['var']]) == 100: continue
            mv = self.solve_boulders((c['x'], c['y']))
            self.log('BOULDER', c['x'], c['y'], 'moves', None if mv is None else len(mv))
            if not mv: continue
            for lid, behind, d in mv:
                bt = self.boulder_tiles()
                if lid not in bt: break
                if not self.goto([behind]): self.log('BOULDER goto fail', behind); break
                self.face(d); self.press('A', 2, 20); self.handle_busy()  # かいりき　を　つかう（はい）
                for t in range(3):
                    if self.boulder_tiles().get(lid) != bt[lid]: break
                    self.cmd(f'p {d} 16', 'w 40'); self.handle_busy()
                self.wait(30)
            did = True
        return did
    return boulder_tiles, solve_boulders, do_boulders, push_moves
Bot.boulder_tiles, Bot.solve_boulders, Bot.do_boulders, Bot.push_moves = _boulder_methods()
