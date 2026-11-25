# hns ビルドに入れる FRLG カントーのスクリプトの include を作る（data/kj_frlg_scripts.inc）
import sys, os
sys.path.insert(0, os.path.dirname(__file__))
import kanto_maps as K, symscan as S
lines = ['@ カントー＆ジョウト: FRLG のカントー（tools_kj/gen_includes.py で作成。手で直さない）']
lines += [f'\t.include "data/maps/{m}/scripts.inc"' for m in K.kanto_maps()]
lines += [f'\t.include "{f}"' for f in S.COMMON]
open('data/kj_frlg_scripts.inc', 'w').write('\n'.join(lines) + '\n')
print(len(lines))
