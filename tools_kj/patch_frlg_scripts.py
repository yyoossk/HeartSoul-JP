# FRLG のカントーのスクリプトを hns 用に書きかえる（何度動かしても同じ）
#  ・バッジ 1〜8 → hns のカントーのバッジ 9〜16
import re, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S
n = 0
for f in S.files():
    s = open(f).read()
    t = re.sub(r'\bFLAG_BADGE0([1-8])_GET\b', lambda m: f'FLAG_BADGE{int(m.group(1))+8:02d}_GET', s)
    if t != s: open(f, 'w').write(t); n += 1
# ひでんマシンをもらったら hns のフラグも立てる（hns のひでんわざのスクリプトが見るため）
HM = {'01': 'CUT', '03': 'SURF', '04': 'STRENGTH', '05': 'FLASH'}
for f in S.files():
    s = open(f).read()
    t = re.sub(r'(?m)^(\tgiveitem_msg [^\n]*ITEM_HM(0[1345])\b[^\n]*\n)(?!\tsetflag FLAG_(?:KJ_)?RECEIVED_HM_)',
               lambda m: m.group(1) + f'\tsetflag FLAG_RECEIVED_HM_{HM[m.group(2)]} @ カントー＆ジョウト\n', s)
    if t != s: open(f, 'w').write(t); n += 1
# カントーの殿堂入りは FLAG_SYS_GAME_CLEAR（ジョウトの殿堂入り）ではなく FLAG_KJ_KANTO_CHAMPION
for f in S.files() + ['data/scripts/hall_of_fame_frlg.inc']:
    s = open(f).read(); t = re.sub(r'\bFLAG_SYS_GAME_CLEAR\b', 'FLAG_KJ_KANTO_CHAMPION', s)
    if t != s: open(f, 'w').write(t); n += 1
print('patched', n)
