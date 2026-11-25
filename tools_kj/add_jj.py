# ピカチュウ版のように、ムサシとコジロウを 4か所の ロケット団員と入れかえる（何度動かしても同じ）
import json, re, struct
def passable(mp, x, y, objs):
    m = json.load(open(f'data/maps/{mp}/map.json'))
    L = {l['id']: l for l in json.load(open('data/layouts/layouts.json'))['layouts'] if l}[m['layout']]
    d = open(L['blockdata_filepath'], 'rb').read(); w, h = L['width'], L['height']
    if not (0 <= x < w and 0 <= y < h): return False
    if any(o['x'] == x and o['y'] == y for o in objs): return False
    return not (struct.unpack_from('<H', d, 2 * (x + y * w))[0] >> 10) & 3
SITES = [
    # map, 団員のスクリプト, コジロウの位置(dx,dy), トレーナー, 名前, 戦いのあとに呼ぶもの
    ('MtMoon_B2F_Frlg', 'MtMoon_B2F_EventScript_Grunt1', (1, 0), 1, 'MTMOON', None),
    ('RocketHideout_B4F_Frlg', 'RocketHideout_B4F_EventScript_Grunt1', (1, 0), 2, 'HIDEOUT', 'KJ_EventScript_JJ_HideoutLiftKey'),
    ('PokemonTower_7F_Frlg', 'PokemonTower_7F_EventScript_Grunt1', (0, 1), 3, 'TOWER', None),
    ('SilphCo_11F_Frlg', 'SilphCo_11F_EventScript_Grunt1', (1, 0), 4, 'SILPH', None),
    # ジョウト（3ねんご）
    ('SlowpokeWell_B1F_hns', 'SlowpokeWell_B1F_EventScript_Grunt22F', (1, 0), 5, 'WELL', None),
    ('RocketHideout_B2F_hns', 'RocketHideout_B2F_EventScript_Grunt16', (1, 0), 6, 'MAHOGANY', None),
    ('GoldenrodCity_RadioTower_3F_hns', 'GoldenrodRaidoTower3_EventScript_Grunt8', (-1, 0), 7, 'RADIO', None),
]
# ジョウトでは　もとの　だんいんと　おなじ　ときだけ　でる（この　フラグが　たって　いたら　かくす）
STORY = {'WELL': 'FLAG_HIDE_AZALEA_TOWN_ROCKETS', 'MAHOGANY': 'FLAG_HIDE_MAHOGANY_ROCKETS', 'RADIO': 'FLAG_HIDE_GOLDENROD_ROCKETS'}
TEXT = {
 1: ('ムサシ“ちょっと　まったー！\\pコジロウ“この　やまの　カセキは\\nロケットだんが　いただくぜ！\\pムサシ“じゃまする　こは\\nおしおき　よ！$',
     'ムサシ“うそ！\\nまけちゃった……$',
     'コジロウ“おぼえてろよー！\\pムサシ・コジロウ“やなかんじー！$'),
 2: ('ムサシ“また　あんたね！\\pコジロウ“サカキさまの　ところへは\\nいかせないぜ！$',
     'コジロウ“くっ……\\nなんて　つよさだ……$',
     'ムサシ“リフトキーなら\\nそのへんに　おとしちゃったわ！\\pムサシ・コジロウ“やなかんじー！$'),
 3: ('ムサシ“あーら　また　あったわね\\pコジロウ“この　タワーは\\nロケットだんが　いただいたぜ！$',
     'ムサシ“もう！\\nなんで　かてないのよ！$',
     'コジロウ“フジろうじんは\\nかえして　やるよ……\\pムサシ・コジロウ“やなかんじー！$'),
 5: ('ムサシ“ちょっと　まったー！\\pコジロウ“ヤドンの　シッポは\\nロケットだんの　だいじな\\lしきんげん　なのさ！\\pムサシ“あら‥？　あんた\\nもしかして‥\\pコジロウ“3ねんまえの\\nあの　ジャリボーイ！？\\pムサシ“ここで　あったが\\n3ねんめ！　おしおき　よ！$',
     'コジロウ“3ねん　たっても\\nかてないのか……$',
     'ムサシ“きょうの　ところは\\nひいて　あげるわ！\\pムサシ・コジロウ“やなかんじー！$'),
 6: ('ムサシ“また　あんたね\\nジャリボーイ！\\pコジロウ“この　アジトの\\nひみつは　わたさないぜ！$',
     'ムサシ“もう！\\nなんで　かてないのよ！$',
     'コジロウ“いかりのみずうみの\\nけいかくも　だいなしだ……\\pムサシ・コジロウ“やなかんじー！$'),
 7: ('ムサシ“ここまで　きたのね！\\pコジロウ“ラジオとうは\\nロケットだんが　いただいたぜ！\\pムサシ“サカキさまに　とどける\\nこの　でんぱ‥\\lじゃまは　させないわ！$',
     'コジロウ“また　まけた……$',
     'ムサシ“こんどこそ‥\\nこんどこそ　かつんだから！\\pムサシ・コジロウ“やなかんじー！$'),
 4: ('ムサシ“こんな　ところまで\\nきたのね！\\pコジロウ“しゃちょうしつへは\\nいかせないぜ！$',
     'コジロウ“また　まけた……$',
     'ムサシ“サカキさまに\\nおこられちゃう……\\pムサシ・コジロウ“やなかんじー！$'),
}
out = ['@ カントー＆ジョウト: ムサシとコジロウ（ピカチュウ版の場面。tools_kj/add_jj.py で作成）', '']
for mp, grunt, (dx, dy), n, key, after in SITES:
    p = f'data/maps/{mp}/map.json'; j = json.load(open(p))
    objs = j['object_events']
    mus = next(o for o in objs if o.get('script') in (grunt, f'KJ_EventScript_JJ_{key}'))
    flag = f'FLAG_KJ_HIDE_JJ_{key}'
    mid = mus.get('local_id') or f'LOCALID_KJ_MUSASHI_{key}'
    mus.update({'local_id': mid, 'graphics_id': 'OBJ_EVENT_GFX_KJ_MUSASHI',
                'script': f'KJ_EventScript_JJ_{key}', 'flag': flag})
    if not any(o.get('local_id') == f'LOCALID_KJ_KOJIRO_{key}' for o in objs):
        cands = [(dx, dy), (1, 0), (-1, 0), (0, -1), (0, 1)]
        dx, dy = next(c for c in cands if passable(mp, mus['x'] + c[0], mus['y'] + c[1], objs))
        ko = dict(mus); ko.update({'local_id': f'LOCALID_KJ_KOJIRO_{key}', 'graphics_id': 'OBJ_EVENT_GFX_KJ_KOJIRO',
                                   'x': mus['x'] + dx, 'y': mus['y'] + dy, 'trainer_type': 'TRAINER_TYPE_NONE',
                                   'trainer_sight_or_berry_tree_id': '0', 'script': f'KJ_EventScript_JJ_{key}_Kojiro'})
        objs.append(ko)
    open(p, 'w').write(json.dumps(j, indent=2, ensure_ascii=False) + '\n')
    if key in STORY:
        out += [f'KJ_EventScript_JJ_Sync_{key}::',
                f'\tgoto_if_set {STORY[key]}, KJ_EventScript_JJ_Hide_{key}',
                f'\tgoto_if_defeated TRAINER_KJ_JJ_{n}, KJ_EventScript_JJ_Hide_{key}',
                f'\tclearflag {flag}', '\tend', '',
                f'KJ_EventScript_JJ_Hide_{key}::', f'\tsetflag {flag}', '\tend', '']
        sp = f'data/maps/{mp}/scripts.inc'; t = open(sp).read()
        line = f'\tmap_script MAP_SCRIPT_ON_TRANSITION, KJ_EventScript_JJ_Sync_{key}\n'
        if line not in t:
            t = t.replace(f'{mp}_MapScripts::\n', f'{mp}_MapScripts::\n' + line, 1)
            open(sp, 'w').write(t)
    intro, defeat, post = TEXT[n]
    out += [f'KJ_EventScript_JJ_{key}::',
            f'\ttrainerbattle_single TRAINER_KJ_JJ_{n}, KJ_Text_JJ_{key}_Intro, KJ_Text_JJ_{key}_Defeat, KJ_EventScript_JJ_{key}_After',
            '\tend', '',
            f'KJ_EventScript_JJ_{key}_Kojiro::',
            f'\tgoto KJ_EventScript_JJ_{key}', '\tend', '',
            f'KJ_EventScript_JJ_{key}_After::',
            f'\tmsgbox KJ_Text_JJ_{key}_Post',
            '\tclosemessage',
            f'\tapplymovement {mid}, Common_Movement_JumpInPlaceDownKj',
            f'\tapplymovement LOCALID_KJ_KOJIRO_{key}, Common_Movement_JumpInPlaceDownKj',
            '\twaitmovement 0',
            '\tplayse SE_FLEE',
            '\tfadescreen FADE_TO_BLACK',
            f'\tremoveobject {mid}',
            f'\tremoveobject LOCALID_KJ_KOJIRO_{key}',
            f'\tsetflag {flag}',
            '\tfadescreen FADE_FROM_BLACK',
            f'\tgoto {after}' if after else '\trelease',
            '\tend', '',
            f'KJ_Text_JJ_{key}_Intro::', f'\t.string "{intro}"', '',
            f'KJ_Text_JJ_{key}_Defeat::', f'\t.string "{defeat}"', '',
            f'KJ_Text_JJ_{key}_Post::', f'\t.string "{post}"', '']
out += ['KJ_EventScript_JJ_HideoutLiftKey::',
        '\taddobject LOCALID_LIFT_KEY', '\tclearflag FLAG_KJ_HIDE_LIFT_KEY', '\trelease', '\tend', '',
        'Common_Movement_JumpInPlaceDownKj::', '\tjump_in_place_down', '\tjump_in_place_down', '\tstep_end', '']
open('data/scripts/kj_jj.inc', 'w').write('\n'.join(out))
# フラグの一覧に足す
# セーブの並びを変えないため、新しいフラグは後ろに足す
lst = 'tools_kj/kj_flags.txt'; names = open(lst).read().split()
names += [f for f in (f'FLAG_HIDE_JJ_{s[4]}' for s in SITES) if f not in names]
open(lst, 'w').write('\n'.join(names) + '\n')
print('ok')
