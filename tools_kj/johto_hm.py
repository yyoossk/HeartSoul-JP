# johto_hm.py : カントーで　もらった　ひでんマシンは　ジョウトで　もう　いちど　わたさない（サトシMODと同じ）
# giveitem ITEM_HM_X を call KJ_EventScript_GiveHM_X に　かえる。もって　いれば「もう　もっている」と　でて
# VAR_RESULT = TRUE（その　あとの　しらべも　とおる）。何度実行しても同じ結果
import glob, re
HMS = ['CUT', 'FLY', 'SURF', 'STRENGTH', 'FLASH']
for p in glob.glob('data/maps/*_hns/scripts.inc'):
    s = open(p, encoding='utf-8').read()
    t = re.sub(r'(?m)^\tgiveitem ITEM_HM_(' + '|'.join(HMS) + r')\s*$', r'\tcall KJ_EventScript_GiveHM_\1', s)
    if t != s: open(p, 'w', encoding='utf-8').write(t)
out = ['@ カントー＆ジョウト: ジョウトの　ひでんマシン（tools_kj/johto_hm.py で作成）', '']
for h in HMS:
    out += [f'KJ_EventScript_GiveHM_{h}::', f'\tcheckitem ITEM_HM_{h}',
            '\tgoto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave', f'\tgiveitem ITEM_HM_{h}', '\treturn', '']
out += ['KJ_EventScript_HMAlreadyHave::', '\tmsgbox KJ_Text_HMAlreadyHave', '\tsetvar VAR_RESULT, TRUE', '\treturn', '',
        'KJ_Text_HMAlreadyHave::', '\t.string "{PLAYER}は　その　ひでんマシンを\\n"',
        '\t.string "カントーで　もう　もらっていた！$"', '']
open('data/scripts/kj_johto_hm.inc', 'w', encoding='utf-8').write('\n'.join(out))
print('ok')
