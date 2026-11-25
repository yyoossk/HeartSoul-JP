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
print('patched', n)
