# FRLG のトレーナーのうちカントー編で使うものを hns のトレーナー表のうしろに足す
#  -> include/constants/opponents_kj.h, src/data/trainers_kj.party
import re, sys, os, glob
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S
HNS_COUNT = 653          # もとの TRAINERS_COUNT_HNS
FLAG_SPLIT = 864         # これより後の番号は 拡張フラグ（KJ_TRAINER_FLAGS_START〜）
party = open('src/data/trainers_frlg.party').read()
blocks = re.split(r'(?m)^(?==== )', party)
byname = {}
order = []
for b in blocks:
    m = re.match(r'=== (TRAINER_\w+) ===', b)
    if m: byname[m.group(1)] = b; order.append(m.group(1))
used = set()
srcs = S.files() + glob.glob('data/scripts/*.inc') + ['data/event_scripts.s']
for f in srcs:
    if f.endswith('_hns.inc'): continue
    used |= set(re.findall(r'\bTRAINER_\w+', open(f).read()))
names = [n for n in order if n in used and n != 'TRAINER_NONE']
# カントー＆ジョウト専用のトレーナー（ムサシとコジロウ）
extra = open('src/data/trainers_kj_extra.party').read()
for b in re.split(r'(?m)^(?==== )', extra):
    m = re.match(r'=== (TRAINER_\w+) ===', b)
    if m: byname[m.group(1)] = b; names.append(m.group(1))
n = len(names)
total = HNS_COUNT + n
# セーブの並び（後ろのフラグの番号）を変えないため、トレーナーの数は KJ_RESERVED_MAX まで決まった枠を取る
KJ_RESERVED_MAX = 1112
assert total <= KJ_RESERVED_MAX, 'トレーナーの枠が足りない'
mx = KJ_RESERVED_MAX
h = ['#ifndef GUARD_CONSTANTS_OPPONENTS_KJ_H', '#define GUARD_CONSTANTS_OPPONENTS_KJ_H',
     '// カントー＆ジョウト: FRLG のトレーナー（tools_kj/gen_trainers.py で作成）',
     f'#define KJ_TRAINERS_START {HNS_COUNT}', f'#define KJ_TRAINERS_COUNT {n}',
     f'#define KJ_TRAINER_FLAG_SPLIT {FLAG_SPLIT}', f'#define KJ_MAX_TRAINERS_COUNT {mx}']
h += [f'#define {nm:50s} {HNS_COUNT + i}' for i, nm in enumerate(names)]
h += ['#endif', '']
open('include/constants/opponents_kj.h', 'w').write('\n'.join(h))
# 名前は日本版ファイアレッドの名前に（tools_kj/jp/trainer_names.json）
import json
JPN = json.load(open('tools_kj/jp/trainer_names.json'))
def jp_name(nm, b):
    j = JPN.get(nm)
    if not j or j in ('みてい', 'ダミー'): return b
    return re.sub(r'(?m)^Name: .*$', 'Name: ' + j, b, count=1)
open('src/data/trainers_kj.party', 'w').write(''.join(jp_name(nm, byname[nm]) for nm in names))
print('kj trainers', n, 'total', total, 'max', mx, 'extra flag bits', max(0, mx - FLAG_SPLIT))
