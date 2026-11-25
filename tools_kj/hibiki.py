# hibiki.py : シロガネやまの　レッドを　ヒビキに（サトシMODと同じ）。何度実行しても同じ結果
# サトシ（レッドの絵）が　シロガネやまで　ハート＆ソウルの主人公　ヒビキと　たたかう
import sys, os, re, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from settext import set_text

PARTY = 'src/data/trainers_hns.party'
IV = 'IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe'
def mon(head, lv, moves, extra=''):
    return f'{head}\nLevel: {lv}\n{IV}\n{extra}' + ''.join(f'- {m}\n' for m in moves) + '\n'
def block(tid, ai, lvs):
    a, b, c, d, e, f = lvs
    return (f'=== {tid} ===\nName: ヒビキ\nClass: Pkmn Trainer 1 Hns\nPic: Gold Hns\nGender: Male\n'
            f'Music: Hg Champion\nDouble Battle: No\nAI: {ai}\nItems: Full Restore / Full Restore\n\n'
            + mon('Typhlosion @ Charcoal', a, ['Eruption', 'Flamethrower', 'Focus Blast', 'Earthquake'])
            + mon('Ampharos @ Magnet', b, ['Thunderbolt', 'Power Gem', 'Focus Blast', 'Dazzling Gleam'])
            + mon('Heracross @ Choice Band', c, ['Megahorn', 'Close Combat', 'Stone Edge', 'Earthquake'])
            + mon('Gyarados @ Leftovers', d, ['Waterfall', 'Dragon Dance', 'Ice Fang', 'Earthquake'])
            + mon('Togekiss @ Sitrus Berry', e, ['Air Slash', 'Dazzling Gleam', 'Aura Sphere', 'Roost'])
            + mon('Umbreon @ Leftovers', f, ['Foul Play', 'Moonlight', 'Toxic', 'Protect']))

def main():
    s = open(PARTY, encoding='utf-8').read()
    for tid, ai, lvs in [('TRAINER_RED_HNS', 'Basic Trainer', (93, 77, 79, 79, 79, 80)),
                         ('TRAINER_RED_POSTOBC_HNS', 'Smart Trainer / Prediction', (95, 85, 87, 87, 86, 85))]:
        m = re.search(r'(?ms)^=== ' + tid + r' ===\n.*?(?=^=== |\Z)', s)
        assert m, tid
        s = s[:m.start()] + block(tid, ai, lvs) + s[m.end():]
    open(PARTY, 'w', encoding='utf-8').write(s)
    # 見た目：ハート＆ソウルの主人公（ヒビキ）
    for mp in ['MtSilver_SummitDay_hns', 'MtSilver_SummitNight_hns']:
        p = f'data/maps/{mp}/map.json'
        t = open(p, encoding='utf-8').read().replace('"OBJ_EVENT_GFX_RED_NORMAL_HNS"', '"OBJ_EVENT_GFX_GOLD_NORMAL_HNS"')
        open(p, 'w', encoding='utf-8').write(t)
    # セリフ
    p = 'data/maps/MtSilver_SummitDay_hns/scripts.inc'
    t = open(p, encoding='utf-8').read()
    if 'MtSilver_SummitDay_Text_HibikiAfter' not in t:
        old = '\tplayse SE_M_BLIZZARD\n\tsetrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS\n\tmsgbox MtSilver_SummitDay_Text_Red, MSGBOX_DEFAULT\n'
        assert old in t
        t = t.replace(old, '\tplayse SE_M_BLIZZARD\n\tsetrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS\n'
                      '\tmsgbox MtSilver_SummitDay_Text_HibikiAfter, MSGBOX_DEFAULT\n')
        t = t.rstrip('\n') + '\n\nMtSilver_SummitDay_Text_HibikiAfter:\n\t.string "x$"\n'
        open(p, 'w', encoding='utf-8').write(t)
    set_text(p, 'MtSilver_SummitDay_Text_Red', [
        '‥‥！\\n{PLAYER}さん　ですよね？\\p',
        'ぼくは　ヒビキ\\nワカバタウンから　きました\\p',
        'カントーの　チャンピオンの\\n{PLAYER}さんと　いつか\\lたたかって　みたかったんだ！\\p',
        'さあ　しょうぶ　です！$'])
    set_text(p, 'MtSilver_SummitDay_Text_RedBeaten', ['‥‥　まいったなあ！\\nやっぱり　つよいや！$'])
    set_text(p, 'MtSilver_SummitDay_Text_HibikiAfter', [
        'ありがとう　{PLAYER}さん！\\p',
        'もっと　もっと　つよく　なって\\nまた　あいに　いきます！\\p',
        'かあさんに　よろしく！$'])
    # ヒビキの　ママ：ジョウトの　でんどういりの　あと／ヒビキに　あった　あと
    H1 = 'data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc'
    t = open(H1, encoding='utf-8').read()
    old = '\tmsgbox NewBarkTown_PlayersHouse_1F_Text_KjMomRest, MSGBOX_DEFAULT\n'
    if 'KjMomTalk::' not in t:
        t = t.replace(old, '\tcall NewBarkTown_PlayersHouse_1F_EventScript_KjMomTalk\n', 1)
        t = t.rstrip('\n') + ('\n\nNewBarkTown_PlayersHouse_1F_EventScript_KjMomTalk::\n'
            '\tgoto_if_set FLAG_DEFEATED_RED, NewBarkTown_PlayersHouse_1F_EventScript_KjMomMetHibiki\n'
            '\tgoto_if_set FLAG_SYS_GAME_CLEAR, NewBarkTown_PlayersHouse_1F_EventScript_KjMomHibikiSilver\n'
            '\tmsgbox NewBarkTown_PlayersHouse_1F_Text_KjMomRest, MSGBOX_DEFAULT\n\treturn\n\n'
            'NewBarkTown_PlayersHouse_1F_EventScript_KjMomHibikiSilver::\n'
            '\tmsgbox NewBarkTown_PlayersHouse_1F_Text_KjMomHibikiSilver, MSGBOX_DEFAULT\n\treturn\n\n'
            'NewBarkTown_PlayersHouse_1F_EventScript_KjMomMetHibiki::\n'
            '\tmsgbox NewBarkTown_PlayersHouse_1F_Text_KjMomMetHibiki, MSGBOX_DEFAULT\n\treturn\n\n'
            'NewBarkTown_PlayersHouse_1F_Text_KjMomHibikiSilver:\n\t.string "x$"\n\n'
            'NewBarkTown_PlayersHouse_1F_Text_KjMomMetHibiki:\n\t.string "x$"\n')
        open(H1, 'w', encoding='utf-8').write(t)
    set_text(H1, 'NewBarkTown_PlayersHouse_1F_Text_KjMomHibikiSilver', [
        'ヒビキのママ『あら　{PLAYER}くん！\\p',
        'ヒビキったら　シロガネやまに\\nこもって　しゅぎょう\\lしてるらしいの\\p',
        'もし　あったら　たまには\\nかえって　きなさいって\\lつたえてね！\\p',
        'つかれたでしょう？\\nすこし　やすんで　いって！$'])
    set_text(H1, 'NewBarkTown_PlayersHouse_1F_Text_KjMomMetHibiki', [
        'ヒビキのママ『あら　{PLAYER}くん！\\nヒビキに　あったの？\\p',
        'そう‥　げんきに　してたのね\\p',
        'あのこったら　{PLAYER}くんと\\nしょうぶ　できて　きっと\\lうれしかったと　おもうわ\\p',
        'つかれたでしょう？\\nすこし　やすんで　いって！$'])

if __name__ == '__main__':
    main()
