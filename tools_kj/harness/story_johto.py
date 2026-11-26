from bot import DIRS, OPP
from bot import SRC
# story_johto.py : 3ねんごの　ジョウト編（ハート＆ソウルの　ジョウト）
ROM = '/tmp/play/rom.gba'
START_STATE = '/tmp/dbg/johto1.ss'; START_SAV = '/tmp/dbg/johto1.sav'
BOOST = 100
TEST_MOVES = [57, 89, 58, 85]
CAPTURE = 'cap'

def trainer(b, name):
    # トレーナー：みつかって　むこうから　くる　ことも　ある。2かい　ためして　たたかえれば　よし
    for i in range(2):
        b.talk(name); b.handle_busy()
    return True

def ride_puzzle(b, tx, ty, out=False):
    # のりもの（アリアドス　など）の　しかけ：トリガーを　ふむと　べつの　ばしょへ　はこばれる。
    #   どこに　ついたかを　セーブステートで　しらべて、(tx, ty) の　となりへ　いける　ばしょを　さがす
    import json, collections
    info = b.maps[b.mapkey()]
    trig = [(c['x'], c['y']) for c in json.load(open(f"{SRC}/data/maps/{info['name']}/map.json")).get('coord_events', [])]
    trig = sorted(set(trig))
    goal = [(tx + dx, ty + dy) for dx, dy in ((0, 1), (1, 0), (-1, 0), (0, -1))]
    if out: goal = [(w['x'], w['y']) for w in info['warps']]  # でぐちへ
    n = 0; path = f'{__import__("os").environ.get("PLAYDIR", "/tmp/play")}/ride{n}.ss'; b.save(path)
    q = collections.deque([(path, b.player()[:2])]); seen = {b.player()[:2]}
    while q:
        st, pos = q.popleft(); b.load(st); b.wait(2)
        if b.bfs(goal) is not None:
            b.log('RIDE OK from', pos)
            if out: b.goto(goal); b.handle_busy(); return True
            return b.talk_at(tx, ty)
        for t in trig:
            b.load(st); b.wait(2)
            if b.player()[:2] == t:  # いま　トリガーの　うえ：いちど　おりて　ふみなおす
                for d in 'UDLR':
                    if b.step(d) is True and b.player()[:2] != t: break
                b.handle_busy()
            if b.bfs([t]) is None: continue
            b.goto([t]); b.handle_busy(); b.wait(10); b.handle_busy()
            np = b.player()[:2]
            if np not in seen:
                seen.add(np); n += 1; p2 = f'{__import__("os").environ.get("PLAYDIR", "/tmp/play")}/ride{n}.ss'; b.save(p2); q.append((p2, np))
                b.log('RIDE', pos, '->', t, '->', np)
    b.log('RIDE FAIL', seen); return False

def farfetchd(b):
    # ウバメのもり：カモネギを　すみびごやの　おやかたの　ところへ　おいかえす（はなす　むきで　にげる　ほうこうが　かわる）
    #   セーブステートで　ためして　VAR_ILEX_FOREST_FARFETCHD が　2 に　なる　てじゅんを　さがす
    import collections
    V = b.F['VAR_ILEX_FOREST_FARFETCHD']
    FF = [b.lid_of(f'Farfetchd_{i}A') for i in range(1, 5)]
    def key():
        return (b.var(V), tuple(sorted((o['lid'], o['x'], o['y']) for o in b.objects() if o['lid'] in FF and not o['invisible'])))
    n = 0; st = f'{__import__("os").environ.get("PLAYDIR", "/tmp/play")}/ff{n}.ss'; b.save(st)
    q = collections.deque([st]); seen = {key()}
    while q and n < 60:
        st = q.popleft()
        b.load(st); b.wait(2)
        if b.var(V) >= 2: break
        tmpl = b.maps[b.mapkey()]['objs']
        cands = []
        for lid in FF:  # みえて　いない　カモネギは　もとの　ばしょの　ちかくへ　いって　さがす
            if b.flag(tmpl[lid - 1].get('flag')) if tmpl[lid - 1].get('flag') not in (None, '0') else False: continue
            vis = [o for o in b.objects() if o['lid'] == lid and not o['invisible']]
            if not vis:
                tx, ty = tmpl[lid - 1]['x'], tmpl[lid - 1]['y']
                b.goto([(tx + dx, ty + dy) for dx in range(-3, 4) for dy in range(-3, 4) if (dx, dy) != (0, 0)]); b.handle_busy()
                vis = [o for o in b.objects() if o['lid'] == lid and not o['invisible']]
                b.load(st); b.wait(2)
            cands += vis
        for o in cands:
            for d, (dx, dy) in DIRS.items():
                b.load(st); b.wait(2)
                if not any(p['lid'] == o['lid'] for p in b.objects()):
                    b.goto([(o['x'] + dx, o['y'] + dy) for dx in range(-3, 4) for dy in range(-3, 4) if (dx, dy) != (0, 0)]); b.handle_busy()
                t = (o['x'] - dx, o['y'] - dy)  # そこから　d むきに　はなす
                if b.bfs([t]) is None: continue
                if not b.goto([t]): continue
                b.face(d); b.press('A', 2, 10); b.handle_busy(); b.wait(20); b.handle_busy()
                k = key()
                if k not in seen:
                    seen.add(k); n += 1; s2 = f'{__import__("os").environ.get("PLAYDIR", "/tmp/play")}/ff{n}.ss'; b.save(s2); q.append(s2)
                    b.log('FF', o['lid'], (o['x'], o['y']), d, '->', k)
                    if k[0] >= 2: q.appendleft(s2); break
    b.load(st); b.wait(2)
    for s_ in list(q): pass
    ok = b.var(V) >= 2
    if not ok:
        for s_ in q:
            b.load(s_); b.wait(2)
            if b.var(V) >= 2: ok = True; break
    b.log('FF result', ok, b.var(V)); return ok

def radio_quiz(b):
    # ラジオとう1かい：クイズ（はい・はい・はい・いいえ・はい・いいえ）で　ラジオカード。アカネが　ジムへ　もどる
    lid = b.lid_of('RadioTower1F_EventScript_Reception')
    o = [x for x in b.objects() if x['lid'] == lid]
    if not o: b.talk('RadioTower1F_EventScript_Reception'); return b.flag('FLAG_ENABLE_RADIO')
    x, y = o[0]['x'], o[0]['y']
    for t, d in (((x, y + 1), 'U'), ((x, y - 1), 'D'), ((x, y + 2), 'U'), ((x, y - 2), 'D'), ((x - 1, y), 'R'), ((x + 1, y), 'L')):
        if b.bfs([t]) is not None and b.goto([t]): b.face(d); break
    b.press('A', 2, 10)
    b.answer('YYYNYN')
    return bool(b.flag('FLAG_ENABLE_RADIO'))

def chase_wild(b, name, flag):
    # うごきまわる　やせいの　ポケモン（みずうみの　ギャラドス　など）：おいかけて　はなし、たおす
    lid = b.lid_of(name)
    for t in range(40):
        if b.flag(flag): return True
        o = [x for x in b.objects() if x['lid'] == lid]
        if not o:
            tm = b.maps[b.mapkey()]['objs'][lid - 1]
            b.goto([(tm['x'] + dx, tm['y'] + dy) for dx in range(-3, 4) for dy in range(-3, 4) if (dx, dy) != (0, 0)]); continue
        x, y = o[0]['x'], o[0]['y']
        adj = [(x + dx, y + dy, d) for d, (dx, dy) in DIRS.items()]
        adj = [(a, c, OPP[d]) for a, c, d in adj]
        if not b.goto([(a, c) for a, c, _ in adj]): b.wait(10); continue
        px, py, _ = b.player()
        for a, c, d in adj:
            if (a, c) == (px, py): b.face(d)
        b.grinding = True
        try: b.press('A', 2, 10); b.handle_busy()
        finally: b.grinding = False
    return bool(b.flag(flag))

def wild_event(b, name):
    # その　ばで　たたかう　やせいの　ポケモン：ちかくまでは　にげながら　いき、はなす　ときだけ　たたかう
    lid = b.lid_of(name); o = b.maps[b.mapkey()]['objs'][lid - 1]
    b.goto([(o['x'] + dx, o['y'] + dy) for dx in range(-2, 3) for dy in range(-2, 3) if (dx, dy) != (0, 0)])
    b.grinding = True
    try: b.talk(name); b.handle_busy()
    finally: b.grinding = False
    return True

def explore_talk(b, script, out=False):
    # おなじ　マップの　なかの　ワープ（かいだん・あな）や　トリガーを　じっさいに　ふんで、
    #   どこに　でるかを　セーブステートで　しらべ、(script の　人) に　はなせる　ばしょを　さがす
    import json, collections
    D = __import__("os").environ.get("PLAYDIR", "/tmp/play")
    info = b.maps[b.mapkey()]; key0 = b.mapkey()
    if out:
        goal = [(w['x'], w['y']) for w in info['warps'] if w['dest_map'] != info['id']]
    else:
        lid = b.lid_of(script); o = info['objs'][lid - 1]; tx, ty = o['x'], o['y']
        goal = [(tx + dx, ty + dy) for dx, dy in ((0, 1), (1, 0), (-1, 0), (0, -1))]
    cand = sorted({(c['x'], c['y']) for c in json.load(open(f"{SRC}/data/maps/{info['name']}/map.json")).get('coord_events', [])}
                  | {(w['x'], w['y']) for w in info['warps'] if w['dest_map'] == info['id']})
    n = 0; st = f'{D}/ex{n}.ss'; b.save(st)
    q = collections.deque([st]); seen = {b.player()[:2]}
    while q and n < 80:
        st = q.popleft(); b.load(st); b.wait(2)
        if b.bfs(goal) is not None:
            b.log('EXPLORE OK', b.player())
            if out:
                w = goal[0]; b.take_warp(*w); b.handle_busy()
                for d in 'DDLRU':  # でぐちの　マットの　うえに　いる　とき
                    if b.mapkey() != key0: break
                    b.cmd(f'p {d} 16', 'w 40'); b.handle_busy()
                return b.mapkey() != key0
            return b.talk_at(tx, ty)
        for t in cand:
            b.load(st); b.wait(2)
            if t in {(w['x'], w['y']) for w in info['warps']}:
                b.take_warp(*t)  # かいだんは　むきが　ある
            else:
                if b.bfs([t]) is None: continue
                b.goto([t])
            b.handle_busy(); b.wait(20); b.handle_busy()
            if b.mapkey() != key0 or b.player()[:2] == t: continue
            np = b.player()[:2]
            if np not in seen:
                seen.add(np); n += 1; s2 = f'{D}/ex{n}.ss'; b.save(s2); q.append(s2)
                b.log('EXPLORE', t, '->', np)
    b.log('EXPLORE FAIL'); return False

def strength_talk(b, script):
    # かいりきの　いわを　おして　(script の　人) まで　みちを　あける
    lid = b.lid_of(script); o = b.maps[b.mapkey()]['objs'][lid - 1]; tx, ty = o['x'], o['y']
    goal = {(tx + dx, ty + dy) for dx, dy in DIRS.values()}
    b.goto([(tx + dx, ty + dy) for dx in range(-2, 3) for dy in range(3, 9)])  # ちかづいて　いわを　カメラに　いれる
    if b.bfs(list(goal)) is None:
        mv = b.solve_boulders(lambda rs, bs: bool(goal & rs))
        b.log('STRENGTH moves', None if mv is None else len(mv))
        if mv: b.push_moves(mv)
    return b.talk(script)

def advance(b, var, target, *maps):
    # var が　target に　なるまで：いまの　あたいで　うごく　トリガーを　ふむ　→　まだ　はなして　いない　人・とびらに　はなす
    #   → ほかの　マップへ（maps の　じゅんに）
    import json
    talked = set(); tries = {}; V = b.F[var]
    b.grinding = True  # マルマイン　など　その　ばの　やせいせんは　たたかう
    for it in range(60):
        val = b.var(V)
        if val >= target: b.grinding = False; return True
        b.log('ADVANCE', var, val, b.maps[b.mapkey()]['id'], b.player()[:2])
        acted = False
        for mid in [b.maps[b.mapkey()]['id']] + [m for m in maps if m != b.maps[b.mapkey()]['id']]:
            key = b.mapid[mid]; info = b.maps[key]
            j = json.load(open(f"{SRC}/data/maps/{info['name']}/map.json"))
            trig = [(c['x'], c['y']) for c in j.get('coord_events', []) if c.get('var') == var and str(c.get('var_value')) == str(val)]
            tk = (val, mid, 'trig'); tries[tk] = tries.get(tk, 0) + 1
            if trig and tries[tk] <= 2:  # おなじ　トリガーを　なんども　ふまない（おしもどされる　だけの　ことも　ある）
                if b.mapkey() != key: b.go_map(mid)
                if b.bfs(trig) is not None:
                    b.goto(trig); b.handle_busy(); b.wait(20); b.handle_busy(); acted = True; break
            if b.mapkey() != key: continue
            # まだ　はなして　いない　人（アイテムでない。カメラの　そとの　人は　ちかくまで　いく）
            px, py, _ = b.player(); cands = []
            for i, t in enumerate(info['objs']):
                lid = i + 1; sc = t.get('script', 'NULL')
                if sc in ('NULL', '0') or 'Item' in sc or (val, key, lid) in talked: continue
                fl = t.get('flag', '0')
                if fl not in ('0', None) and fl.startswith('FLAG_') and b.flag(fl): continue
                cands.append((abs(t['x'] - px) + abs(t['y'] - py), lid, t))
            for _, lid, t in sorted(cands):
                tries[(val, key, lid)] = tries.get((val, key, lid), 0) + 1
                if tries[(val, key, lid)] >= 3: talked.add((val, key, lid))
                if not any(o['lid'] == lid for o in b.objects()):
                    near = [(t['x'] + dx, t['y'] + dy) for dx in range(-3, 4) for dy in range(-3, 4) if (dx, dy) != (0, 0)]
                    if b.bfs(near) is not None: b.goto(near)
                    else: b.go_tile(key, t['x'], t['y']); b.handle_busy()  # べつの　かいだんから　まわる
                    if b.mapkey() != key: continue
                if any(o['lid'] == lid for o in b.objects()) and b.talk_lid(lid): talked.add((val, key, lid)); acted = True; break
            if acted: break
            for e in j.get('bg_events', []):
                sc = e.get('script', '')
                if ('Door' in sc or 'Switch' in sc) and (val, key, sc, e['x'], e['y']) not in talked:
                    talked.add((val, key, sc, e['x'], e['y']))
                    if b.bfs([(e['x'] + dx, e['y'] + dy) for dx, dy in DIRS.values()]) is not None:
                        b.talk_at(e['x'], e['y']); acted = True; break
            if acted: break
        if not acted:  # ほかの　マップへ　いって　みる（はいった　ときの　イベント）
            for mid in maps:
                if (val, mid) in talked or mid == b.maps[b.mapkey()]['id']: continue
                talked.add((val, mid)); b.go_map(mid); b.handle_busy(); acted = True; break
        if not acted:
            b.log('ADVANCE stuck', val); b.grinding = False; return False
    b.grinding = False
    return b.var(V) >= target

def talk_obj(b, mid, lid):
    # mid の　マップの　lid ばんの　人に　はなす（べつの　かいだんから　まわる　ことも　ある）
    key = b.mapid[mid]; t = b.maps[key]['objs'][lid - 1]
    for i in range(3):
        if b.mapkey() != key or not any(o['lid'] == lid for o in b.objects()):
            near = [(t['x'] + dx, t['y'] + dy) for dx in range(-3, 4) for dy in range(-3, 4) if (dx, dy) != (0, 0)]
            if b.mapkey() == key and b.bfs(near) is not None: b.goto(near)
            else: b.go_tile(key, t['x'], t['y'])
            b.handle_busy()
        if b.mapkey() == key and any(o['lid'] == lid for o in b.objects()):
            r = b.talk_lid(lid); b.handle_busy()
            if any(o['lid'] == lid for o in b.objects()): b.talk_lid(lid); b.handle_busy()  # みつかって　たたかった　あとの　セリフ
            return r
    return False

STEPS = [
    ('map', 'MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_1F_HNS'),
    ('busy',),
    ('map', 'MAP_NEW_BARK_TOWN_LAB_HNS'),
    ('talk', 'Elm'),
    ('busy',),
    ('talk', 'CyndaquilBall'),
    ('busy',),
    ('talk', 'Elm'),
    ('busy',),
    ('map', 'MAP_ROUTE30_MR_POKEMONS_HOUSE_HNS'),
    ('talk', 'MrPokemon'),
    ('busy',),
    ('map', 'MAP_NEW_BARK_TOWN_LAB_HNS'),
    ('busy',),
    ('talk', 'Elm'),
    ('busy',),
    ('busy',),
    ('flag', 'FLAG_KJ_GOT_JOHTO_STARTER'),
    ('map', 'MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_1F_HNS'),  # ウツギの　あと　ママに　あう（でないと　むらを　でられない）
    ('talk', 'Mom'),
    ('busy',),
    ('heal', 'MAP_CHERRYGROVE_CITY_POKEMON_CENTER_HNS'),
    ('map', 'MAP_SPROUT_TOWER_3F_HNS'),            # マダツボミのとう
    ('talk', 'SageLi'),
    ('busy',),
    ('heal', 'MAP_VIOLET_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_VIOLET_CITY_GYM_HNS'),
    ('talk', 'Falkner'),
    ('busy',),
    ('flag', 'FLAG_BADGE01_GET'),
    ('heal', 'MAP_VIOLET_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('talk', 'Aide'),                              # たまご（トゲピー）
    ('busy',),
    ('heal', 'MAP_AZALEA_TOWN_POKEMON_CENTER_HNS'),  # 32ばんどうろ・つながりのどうくつ
    ('report',),
    ('map', 'MAP_AZALEA_TOWN_KURTS_HOUSE_HNS'),
    ('talk', 'KurtBefore'),
    ('busy',),
    ('map', 'MAP_SLOWPOKE_WELL_B1F_HNS'),           # ヤドンのいど
    ('trainer', 'Grunt21'),
    ('busy',),
    ('talk', 'JJ_WELL'),                            # ムサシ・コジロウ
    ('busy',),
    ('trainer', 'Eto'),
    ('busy',),
    ('talk', 'Proton'),
    ('busy',),
    ('flag', 'FLAG_HIDE_AZALEA_TOWN_ROCKETS'),
    ('heal', 'MAP_AZALEA_TOWN_POKEMON_CENTER_HNS'),
    ('map', 'MAP_AZALEA_TOWN_GYM_HNS'),
    ('ride_puzzle', 11, 6),                        # ツクシ（アリアドスの　しかけ）
    ('busy',),
    ('flag', 'FLAG_BADGE02_GET'),
    ('ride_puzzle', 0, 0, True),                   # ジムの　でぐちへ
    ('heal', 'MAP_AZALEA_TOWN_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_ILEX_FOREST_HNS'),                # ウバメのもり（とちゅうで　ライバル）
    ('farfetchd',),
    ('xy', 26, 44),                                # すみやきの　おやかた：いあいぎり
    ('busy',),
    ('flag', 'FLAG_RECEIVED_HM_CUT'),
    ('map', 'MAP_ROUTE34_HNS'),
    ('heal', 'MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_GOLDENROD_CITY_RADIO_TOWER_1F_HNS'),  # ラジオとうの　クイズ（アカネが　ジムに　もどる）
    ('radio_quiz',),
    ('map', 'MAP_GOLDENROD_CITY_GYM_HNS'),          # アカネ
    ('talk', 'Whitney'),
    ('busy',),
    ('xy', 15, 11),                                # なきだした　あと：トレーナーが　はなしかける
    ('busy',),
    ('talk', 'Whitney'),
    ('busy',),
    ('flag', 'FLAG_BADGE03_GET'),
    ('heal', 'MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_GOLDENROD_CITY_FLOWER_SHOP_HNS'),  # ゼニガメじょうろ
    ('talk', 'Owner'),
    ('busy',),
    ('flag', 'FLAG_RECEIVED_SQUIRTBOTTLE'),
    ('map', 'MAP_ROUTE36_HNS'),                    # ウソッキー
    ('wild_event', 'SudoWoodo'),                   # にげずに　たおす
    ('flag', 'FLAG_HIDE_SUDOWOODO'),
    ('heal', 'MAP_ECRUTEAK_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_BURNED_TOWER_1F_HNS'),             # やけたとう：ミナキ・ライバル
    ('busy',),
    ('xy', 15, 12),
    ('busy',),
    ('map', 'MAP_BURNED_TOWER_B1F_HNS'),
    ('busy',),
    ('flag', 'FLAG_RELEASED_BEASTS'),
    ('heal', 'MAP_ECRUTEAK_CITY_POKEMON_CENTER_HNS'),
    ('map', 'MAP_ECRUTEAK_CITY_GYM_HNS'),           # マツバ
    ('talk', 'Morty'),
    ('busy',),
    ('flag', 'FLAG_BADGE04_GET'),
    ('heal', 'MAP_ECRUTEAK_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('heal', 'MAP_OLIVINE_CITY_POKEMON_CENTER_HNS'),  # 38・39ばんどうろ（アサギで　ライバル）
    ('report',),
    ('map', 'MAP_OLIVINE_CITY_LIGHTHOUSE_HNS'),     # とうだい：ミカンと　アカリちゃん
    ('explore_talk', 'OlivineLighthouse_EventScript_Jasmine'),
    ('busy',),
    ('explore_talk', None, True),                  # とうだいの　でぐちへ
    ('heal', 'MAP_CIANWOOD_POKECENTER_HNS'),         # 40・41ばんどうろ（なみのり）
    ('report',),
    ('map', 'MAP_CIANWOOD_GYM_HNS'),                 # シジマ
    ('strength_talk', 'CianwoodGym_EventScript_Chuck'),
    ('busy',),
    ('flag', 'FLAG_BADGE05_GET'),
    ('heal', 'MAP_CIANWOOD_POKECENTER_HNS'),
    ('map', 'MAP_CIANWOOD_SHOP_HNS'),                # ひでんの　くすり
    ('talk', 'CianwoodCity_EventScript_Pharmacist'),
    ('busy',),
    ('heal', 'MAP_OLIVINE_CITY_POKEMON_CENTER_HNS'),
    ('map', 'MAP_OLIVINE_CITY_LIGHTHOUSE_HNS'),
    ('explore_talk', 'OlivineLighthouse_EventScript_Jasmine'),
    ('busy',),
    ('explore_talk', None, True),                  # とうだいの　でぐちへ
    ('heal', 'MAP_OLIVINE_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_OLIVINE_CITY_GYM_HNS'),             # ミカン
    ('xy', 8, 14),
    ('busy',),
    ('xy', 8, 10),
    ('busy',),
    ('talk', 'OlivineCity_Gym_EventScript_Jasmine'),
    ('busy',),
    ('flag', 'FLAG_BADGE06_GET'),
    ('heal', 'MAP_OLIVINE_CITY_POKEMON_CENTER_HNS'),
    ('report',),
    ('heal', 'MAP_MAHOGANY_TOWN_POKEMON_CENTER_HNS'),  # 42ばんどうろ（スリバチやま）
    ('report',),
    ('map', 'MAP_LAKE_OF_RAGE_HNS'),                # いかりのみずうみ：あかい　ギャラドス
    ('chase_wild', 'LakeOfRage_EventScript_Gyarados', 'FLAG_HIDE_LAKE_OF_RAGE_GYARADOS'),
    ('flag', 'FLAG_HIDE_LAKE_OF_RAGE_GYARADOS'),
    ('trainer', 'LakeOfRage_EventScript_Lance'),   # ワタル
    ('busy',),
    ('flag', 'FLAG_HIDE_LAKE_OF_RAGE_LANCE'),
    ('heal', 'MAP_MAHOGANY_TOWN_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_MAHOGANY_TOWN_SHOP_HNS'),          # みやげやの　ちかの　アジト
    ('busy',),
    ('map', 'MAP_ROCKET_HIDEOUT_B1F_HNS'),
    ('map', 'MAP_ROCKET_HIDEOUT_B2F_HNS'),
    ('busy',),
    ('report',),
    ('advance', 'VAR_MAHOGANY_TOWN_STATE', 8, 'MAP_ROCKET_HIDEOUT_B2F_HNS', 'MAP_ROCKET_HIDEOUT_B3F_HNS', 'MAP_ROCKET_HIDEOUT_B1F_HNS'),
    ('talk_obj', 'MAP_ROCKET_HIDEOUT_B3F_HNS', 1),   # あいことば（したっぱ）
    ('talk_obj', 'MAP_ROCKET_HIDEOUT_B3F_HNS', 10),  # あいことば（エト）
    ('flag', 'FLAG_GOT_PASSWORD_FROM_ETO'),
    ('tile', 'MAP_ROCKET_HIDEOUT_B3F_HNS', 12, 13),
    ('at', 12, 12),                                # とびら
    ('flag', 'FLAG_HIDE_ROCKETHIDEOUT3_GATE'),
    ('talk_obj', 'MAP_ROCKET_HIDEOUT_B3F_HNS', 16),  # ボス
    ('busy',),
    ('advance', 'VAR_MAHOGANY_TOWN_STATE', 14, 'MAP_ROCKET_HIDEOUT_B3F_HNS', 'MAP_ROCKET_HIDEOUT_B2F_HNS', 'MAP_ROCKET_HIDEOUT_B1F_HNS'),
    ('report',),
    ('heal', 'MAP_MAHOGANY_TOWN_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_MAHOGANY_TOWN_GYM_HNS'),           # ヤナギ（こおりの　ゆか）
    ('talk', 'MahoganyTown_Gym_EventScript_Pryce'),
    ('busy',),
    ('flag', 'FLAG_BADGE07_GET'),
    ('heal', 'MAP_MAHOGANY_TOWN_POKEMON_CENTER_HNS'),
    ('report',),
    ('map', 'MAP_MAHOGANYTOWN_HNS'),                # ウツギから　でんわ：ラジオとうが　のっとられた
    ('busy',),
    ('advance', 'VAR_GOLDENROD_CITY_STATE', 11, 'MAP_GOLDENROD_CITY_RADIO_TOWER_1F_HNS', 'MAP_GOLDENROD_CITY_RADIO_TOWER_2F_HNS',
     'MAP_GOLDENROD_CITY_RADIO_TOWER_3F_HNS', 'MAP_GOLDENROD_CITY_RADIO_TOWER_4F_HNS', 'MAP_GOLDENROD_CITY_RADIO_TOWER_5F_HNS',
     'MAP_GOLDENROD_CITY_UNDERGROUND_TUNNEL_HNS', 'MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES_HNS', 'MAP_GOLDENROD_CITY_UNDERGROUND_STORAGE_HNS'),
    ('heal', 'MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS'),
    ('report',),
]
