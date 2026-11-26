# story_kanto.py : カントー編（ファイアレッドのカントー）の　てじゅん
ROM = '/tmp/play/rom.gba'
START_STATE = '/tmp/play2/new.ss'; START_SAV = '/tmp/play2/new.sav'
TEST_MOVES = [57, 89, 58, 85]  # なみのり　じしん　れいとうビーム　10まんボルト（テスト　よう）
AVOID = ['MAP_ROUTE18_EAST_ENTRANCE_1F', 'MAP_ROUTE16_NORTH_ENTRANCE_1F']  # サイクリングロード（じてんしゃ　なし）
ON_BOOT_VARS = [(0x40B3, 6), (0x40BE, 2)]  # オーキドの　けんきゅうじょ・ライバルの　いえ（DexNav と　かぶって　いたのを　うつした）
BOOST = 100  # 3つめの　バッジの　あとは　テストを　はやく　する　ため　つよく　する
PC = {'viridian': 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F', 'pewter': 'MAP_PEWTER_CITY_POKEMON_CENTER_1F'}

def oak_intro(b):
    # 1ばんどうろへ　でようと　すると　オーキドが　とめる
    b.go_map('MAP_ROUTE1'); b.handle_busy()
    return b.mapkey() == b.mapid['MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB']

def pallet_lady(b):
    # 看板の　女の人：メニューを　ひらくと　どいて　くれる（ファイアレッドどおり）
    b.goto([(13, 3)]); b.step('U'); b.handle_busy()
    b.press('S', 2, 30); b.press('B', 2, 30)
    b.go_map('MAP_PALLET_TOWN_PLAYERS_HOUSE_1F'); b.handle_busy(); b.go_map('MAP_PALLET_TOWN')
    return True

def bill(b):
    o = [x for x in b.objects() if x['lid'] == 2]
    if o: b.talk_at(o[0]['x'], o[0]['y'])
    for i in range(10): b.press('A', 2, 20)
    b.handle_busy()
    b.talk_at(4, 5)
    for i in range(10): b.press('A', 2, 20)
    b.handle_busy(); b.wait(120); b.handle_busy()
    o = [x for x in b.objects() if x['lid'] == 1]
    if o: b.talk_at(o[0]['x'], o[0]['y'])
    for i in range(10): b.press('A', 2, 20)
    b.handle_busy()
    return bool(b.flag('FLAG_KJ_GOT_SS_TICKET'))

def surge_cans(b):
    # ゴミ箱：VAR_TEMP_0 / 1 に　スイッチの　ばんごう
    pos = lambda n: (1 + 2 * ((n - 1) % 5), 10 + 2 * ((n - 1) // 5))
    for t in range(6):
        if b.flag('FLAG_KJ_FOUND_BOTH_VERMILION_GYM_SWITCHES'): return True
        s1, s2 = b.var(0x4000), b.var(0x4001)
        b.log('CANS', s1, s2)
        if not (1 <= s1 <= 15): return False
        for n in (s1, s2):
            b.talk_at(*pos(n))
            for i in range(6): b.press('B', 2, 20)
            b.handle_busy()
    return bool(b.flag('FLAG_KJ_FOUND_BOTH_VERMILION_GYM_SWITCHES'))

def elevator(b, to='B4F'):
    # アジトの　エレベーター
    if not b.go_map('MAP_ROCKET_HIDEOUT_ELEVATOR'): return False
    b.goto([(0, 3)]); b.face('U'); b.press('A', 2, 90)
    frm = b.maps.get(getattr(b, 'prevmap', None), {}).get('id', '')
    fl = ['B1F', 'B2F', 'B4F']
    d0 = {3: 0, 2: 1, 0: 2}.get(b.var(b.F['VAR_ELEVATOR_FLOOR']), 1)
    b.log('ELEV', frm, '->', to)
    for i in range((fl.index(to) - d0) % 4): b.cmd('p D 8', 'w 40')
    b.press('A', 4, 60)
    for i in range(12): b.press('B', 2, 30)
    b.handle_busy(); b.wait(60)
    for t in range(3):
        b.goto([(2, 4)]); b.step('D'); b.cmd('p D 20', 'w 90'); b.handle_busy()
        if b.mapkey() != b.mapid['MAP_ROCKET_HIDEOUT_ELEVATOR']: break
    b.check_map()
    return b.mapkey() == b.mapid['MAP_ROCKET_HIDEOUT_' + to]

def mansion(b, out=False):
    # ポケモンやしき：像の　スイッチで　とびらが　かわる。とどかなければ　おして　ためす
    import itertools
    tgt = b.mapid['MAP_POKEMON_MANSION_B1F']
    floors = itertools.cycle(['MAP_POKEMON_MANSION_1F', 'MAP_POKEMON_MANSION_2F', 'MAP_POKEMON_MANSION_3F', 'MAP_POKEMON_MANSION_B1F'])
    presses = {}
    reach = (lambda: b.go_map('MAP_CINNABAR_ISLAND', limit=15, explore=False)) if out else (lambda: b.go_tile(tgt, 5, 8))
    for i in range(30):
        if reach(): return True
        info = b.maps.get(b.mapkey(), {})
        st = [g for g in info.get('bgs', []) if (g.get('script') or '').endswith('EventScript_Statue')]
        st.sort(key=lambda g: presses.get((info.get('id'), g['x'], g['y']), 0))  # おした　かいすうが　すくない　ものから
        pressed = False
        for g in st:
            if b.bfs([(g['x'] + dx, g['y'] + dy) for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0))]) is None: continue
            presses[(info.get('id'), g['x'], g['y'])] = presses.get((info.get('id'), g['x'], g['y']), 0) + 1
            b.use_bg(g['x'], g['y'])  # はい　は　handle_busy の　A で　えらばれる。よけいな　A は　もういちど　おして　しまう
            b.handle_busy(); pressed = True; b.log('STATUE', info['id'], g['x'], g['y'])
            for k2 in [k for k in list(b.LIVE) if 'MANSION' in b.maps[k]['id']]: del b.LIVE[k2]
            break
        if reach(): return True
        if (b.mapkey() == tgt or out) and i % 3 != 2: continue  # ちかに　いる　あいだは　ここで　おしなおす
        b.go_map(next(floors), limit=10, explore=False)
    return False

def victory(b):
    # かいりきの　いわの　なぞときは　テストを　はやく　する　ため　スイッチを　おした　ことに　する（FRLG のまま　の　しかけ）
    b.go_map('MAP_ROUTE23', limit=5, explore=False)  # 23ばんどうろに　はいると　1F の　スイッチは　もどる
    for v in ('VAR_MAP_SCENE_VICTORY_ROAD_1F', 'VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1', 'VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2', 'VAR_MAP_SCENE_VICTORY_ROAD_3F'):
        b.set_var(v, 100)
    b.log('VR switches set')
    b.go_map('MAP_VICTORY_ROAD_1F_FRLG', limit=5, explore=False)
    import itertools
    floors = itertools.cycle(['MAP_VICTORY_ROAD_1F_FRLG', 'MAP_VICTORY_ROAD_2F', 'MAP_VICTORY_ROAD_3F'])
    for i in range(12):
        if b.go_map('MAP_INDIGO_PLATEAU_EXTERIOR', limit=20, explore=False): return True
        if 'VICTORY_ROAD' in b.maps[b.mapkey()]['id'] and b.do_boulders():
            b.LIVE.pop(b.mapkey(), None); continue
        b.go_map(next(floors), limit=10, explore=False)
    return False

def credits(b):
    # でんどういり　→　スタッフロール　→　タイトル　→　つづきから
    for i in range(3000):
        if b.in_overworld() and not b.busy(): break
        b.press('A', 2, 30)
        if i % 200 == 0: b.log('CREDITS', i, hex(b.cb2()))
    b.wait(120)
    for i in range(400):
        if b.in_overworld() and not b.busy() and i > 40: break
        b.press('A', 2, 20)
    b.check_map(); b.shot_now('after_hof')
    return b.in_overworld()

def champion(b):
    b.go_map('MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM', limit=3, explore=False)
    credits(b)
    b.log('AFTER HOF', b.maps.get(b.mapkey(), {}).get('id'), b.player())
    return bool(b.flag('FLAG_KJ_KANTO_CHAMPION'))

STEPS = [
    ('oak_intro',),
    ('talk', 'BulbasaurBall'),
    ('busy',),
    ('map', 'MAP_PALLET_TOWN'),          # でようとすると　ライバルせん
    ('pallet_lady',),
    ('map', 'MAP_VIRIDIAN_CITY_MART'),   # おとどけもの
    ('map', 'MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB'),
    ('talk', 'ProfOak'),                 # ずかん
    ('busy',),
    ('grind', 9, 'MAP_ROUTE1', 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_VIRIDIAN_FOREST'),
    ('grind', 13, 'MAP_VIRIDIAN_FOREST', 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F'),
    ('heal', 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_ROUTE2_VIRIDIAN_FOREST_NORTH_ENTRANCE'),
    ('heal', 'MAP_PEWTER_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_PEWTER_CITY_GYM'),
    ('talk', 'Brock'),
    ('busy',),
    ('flag', 'FLAG_BADGE09_GET'),
    ('heal', 'MAP_PEWTER_CITY_POKEMON_CENTER_1F'),
    ('grind', 18, 'MAP_VIRIDIAN_FOREST', 'MAP_PEWTER_CITY_POKEMON_CENTER_1F'),
    ('heal', 'MAP_PEWTER_CITY_POKEMON_CENTER_1F'),
    ('heal', 'MAP_ROUTE4_POKEMON_CENTER_1F'),
    ('grind', 17, 'MAP_ROUTE3', 'MAP_ROUTE4_POKEMON_CENTER_1F'),
    ('heal', 'MAP_ROUTE4_POKEMON_CENTER_1F'),
    ('map', 'MAP_MT_MOON_B2F'),
    ('talk', 'Miguel'),
    ('busy',),
    ('talk', 'DomeFossil'),
    ('busy',),
    ('map', 'MAP_CERULEAN_CITY'),
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('grind', 25, 'MAP_ROUTE4', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_ROUTE24'),                 # ライバル
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_ROUTE25_SEA_COTTAGE'),     # ゴールデンボールばし
    ('bill',),
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('grind', 22, 'MAP_ROUTE24', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_CERULEAN_CITY_GYM'),
    ('talk', 'Misty'),
    ('busy',),
    ('flag', 'FLAG_BADGE10_GET'),
    ('heal', 'MAP_CERULEAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_VERMILION_CITY'),
    ('heal', 'MAP_VERMILION_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_SSANNE_CAPTAINS_OFFICE'),
    ('talk', 'Captain'),
    ('busy',),
    ('map', 'MAP_VERMILION_CITY'),
    ('busy',),
    ('heal', 'MAP_VERMILION_CITY_POKEMON_CENTER_1F'),
    ('clear',),
    ('map', 'MAP_VERMILION_CITY_GYM'),
    ('surge_cans',),
    ('talk', 'LtSurge'),
    ('busy',),
    ('flag', 'FLAG_BADGE11_GET'),
    ('heal', 'MAP_VERMILION_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_LAVENDER_TOWN'),              # 9・10ばんどうろ　イワヤマトンネル
    ('heal', 'MAP_LAVENDER_TOWN_POKEMON_CENTER_1F'),
    ('map', 'MAP_CELADON_CITY'),               # 8ばんどうろ　ちかつうろ　7ばんどうろ
    ('heal', 'MAP_CELADON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_CELADON_CITY_GYM'),
    ('talk', 'Erika_Kj'),
    ('busy',),
    ('flag', 'FLAG_BADGE12_GET'),
    ('heal', 'MAP_CELADON_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_CELADON_CITY_GAME_CORNER'),
    ('talk', 'RocketGrunt'),
    ('busy',),
    ('at', 11, 1),                              # ポスターの　スイッチ
    ('busy',),
    ('heal', 'MAP_CELADON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('tile', 'MAP_ROCKET_HIDEOUT_B4F', 3, 3),
    ('talk', 'JJ_HIDEOUT'),                     # ムサシと　コジロウ
    ('busy',),
    ('talk', 'LiftKey'),
    ('busy',),
    ('elevator',),
    ('talk', 'Grunt2'),                          # とびらの　まえの　したっぱ　ふたり
    ('busy',),
    ('talk', 'Grunt3'),
    ('busy',),
    ('talk', 'Giovanni'),
    ('busy',),
    ('talk', 'SilphScope'),
    ('busy',),
    ('elevator', 'B1F'),
    ('talk', 'Grunt5'),                          # バリアの　まえの　したっぱ
    ('busy',),
    ('heal', 'MAP_CELADON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_LAVENDER_TOWN'),
    ('heal', 'MAP_LAVENDER_TOWN_POKEMON_CENTER_1F'),
    ('fight', True),                             # ガラガラの　ゆうれいとは　たたかう
    ('map', 'MAP_POKEMON_TOWER_7F'),
    ('fight', False),
    ('talk', 'JJ_TOWER'),
    ('busy',),
    ('talk', 'MrFuji'),
    ('busy',),
    ('map', 'MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE'),
    ('talk', 'MrFuji'),                         # ポケモンのふえ
    ('busy',),
    ('heal', 'MAP_LAVENDER_TOWN_POKEMON_CENTER_1F'),
    ('report',),
    ('tile', 'MAP_ROUTE12', 14, 68),
    ('talk', 'Snorlax'),
    ('busy',),
    ('map', 'MAP_FUCHSIA_CITY'),
    ('heal', 'MAP_FUCHSIA_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_FUCHSIA_CITY_GYM'),
    ('talk', 'Koga'),
    ('busy',),
    ('flag', 'FLAG_BADGE13_GET'),
    ('heal', 'MAP_FUCHSIA_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_SAFARI_ZONE_WEST'),            # サファリゾーン（はいる　ときは　はい）
    ('talk', 'ItemGoldTeeth'),
    ('busy',),
    ('map', 'MAP_SAFARI_ZONE_SECRET_HOUSE'),
    ('talk', 'Attendant'),                      # なみのり
    ('busy',),
    ('flag', 'FLAG_KJ_RECEIVED_HM_SURF'),
    ('map', 'MAP_FUCHSIA_CITY'),
    ('map', 'MAP_FUCHSIA_CITY_WARDENS_HOUSE'),
    ('talk', 'Warden'),                         # きんのいれば　→　かいりき
    ('busy',),
    ('flag', 'FLAG_KJ_RECEIVED_HM_STRENGTH'),
    ('heal', 'MAP_FUCHSIA_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_CELADON_CITY_CONDOMINIUMS_1F'),
    ('talk', 'TeaWoman'),                        # おちゃ
    ('busy',),
    ('flag', 'FLAG_KJ_GOT_TEA'),
    ('unblock',),
    ('map', 'MAP_SAFFRON_CITY'),
    ('heal', 'MAP_SAFFRON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('tile', 'MAP_SILPH_CO_5F', 22, 21),
    ('talk', 'ItemCardKey'),
    ('busy',),
    ('map', 'MAP_SILPH_CO_11F'),
    ('talk', 'JJ_SILPH'),
    ('busy',),
    ('xy', 6, 15),                               # サカキ
    ('busy',),
    ('talk', 'President'),
    ('busy',),
    ('heal', 'MAP_SAFFRON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_SAFFRON_CITY_GYM'),
    ('talk', 'Sabrina'),
    ('busy',),
    ('flag', 'FLAG_BADGE14_GET'),
    ('heal', 'MAP_SAFFRON_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_CINNABAR_ISLAND'),               # なみのり
    ('heal', 'MAP_CINNABAR_ISLAND_POKEMON_CENTER_1F'),
    ('report',),
    ('mansion',),
    ('talk', 'ItemSecretKey'),
    ('busy',),
    ('mansion', True),                            # やしきから　でる
    ('heal', 'MAP_CINNABAR_ISLAND_POKEMON_CENTER_1F'),
    ('map', 'MAP_CINNABAR_ISLAND_GYM'),
    ('talk', 'Blaine'),
    ('busy',),
    ('flag', 'FLAG_BADGE15_GET'),
    ('heal', 'MAP_CINNABAR_ISLAND_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_VIRIDIAN_CITY'),
    ('heal', 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F'),
    ('map', 'MAP_VIRIDIAN_CITY_GYM'),
    ('xy', 2, 3),                                # かいてんゆかの　ジム
    ('talk', 'Giovanni'),
    ('busy',),
    ('flag', 'FLAG_BADGE16_GET'),
    ('heal', 'MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_ROUTE23'),                      # 22ばんどうろで　ライバル
    ('map', 'MAP_VICTORY_ROAD_1F_FRLG'),
    ('victory',),
    ('heal', 'MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F'),
    ('report',),
    ('map', 'MAP_POKEMON_LEAGUE_LORELEIS_ROOM'),
    ('talk', 'Lorelei'),
    ('busy',),
    ('map', 'MAP_POKEMON_LEAGUE_BRUNOS_ROOM'),
    ('talk', 'Bruno_Kj'),
    ('busy',),
    ('map', 'MAP_POKEMON_LEAGUE_AGATHAS_ROOM'),
    ('talk', 'Agatha'),
    ('busy',),
    ('map', 'MAP_POKEMON_LEAGUE_LANCES_ROOM'),
    ('talk', 'Lance'),
    ('busy',),
    ('champion',),                                  # ライバル（シゲル）→　でんどういり　→　スタッフロール
    ('flag', 'FLAG_KJ_KANTO_CHAMPION'),
    ('map', 'MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB'),  # オーキドから　ジョウトいきの　チケット
    ('talk', 'ProfOak'),
    ('busy',),
    ('flag', 'FLAG_KJ_GOT_JOHTO_TICKET'),
    ('avoid', 'MAP_SEAFOAM_ISLANDS', 'MAP_ROUTE2_EAST_BUILDING'),
    ('map', 'MAP_VERMILION_CITY'),
    ('avoid', 'MAP_SEAFOAM_ISLANDS'),
    ('xy', 23, 32),
    ('step', 'D'),                                  # ふねに　のる（はい）→　3ねんご
    ('busy',),
    ('flag', 'FLAG_KJ_JOHTO_STARTED'),
]
