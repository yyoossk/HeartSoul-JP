# FRLG のカントーで使うフラグを、hns とは別の場所（拡張フラグ）に割り当てる
#  スクリプト・map.json の FLAG_X を FLAG_KJ_X に書きかえ、include/constants/flags_kj_frlg.h を作る（何度動かしても同じ）
import re, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S, kanto_maps as K
LIST = 'tools_kj/kj_flags.txt'
KEEP = re.compile(r'FLAG_(TEMP_|SYS_|BADGE|WORLD_MAP_|HIDE_ARTICUNO|HIDE_ZAPDOS|HIDE_MOLTRES|HIDE_MEWTWO|DONT_TRANSITION_MUSIC|HIDE_MAP_NAME_POPUP|SAFE_FOLLOWER|OPENED_START_MENU|EVEN_FASTER_JOY|NURSE_UNION_ROOM_REMINDER|KJ_|UNUSED|ENABLE_MULTI_CORRIDOR)')
files = S.files() + ['data/scripts/hall_of_fame_frlg.inc'] + [f'data/maps/{m}/map.json' for m in K.kanto_maps()]
names = set(open(LIST).read().split()) if os.path.exists(LIST) else set()
for f in files:
    for n in re.findall(r'\bFLAG_\w+', open(f).read()):
        if not KEEP.match(n): names.add(n)
names = sorted(names)
open(LIST, 'w').write('\n'.join(names) + '\n')
pat = re.compile(r'\b(' + '|'.join(re.escape(n) for n in names) + r')\b')
for f in files:
    s = open(f).read(); t = pat.sub(lambda m: 'FLAG_KJ_' + m.group(1)[5:], s)
    if t != s: open(f, 'w').write(t)
ok = open('include/constants/opponents_kj.h').read()
mx = int(re.search(r'KJ_MAX_TRAINERS_COUNT (\d+)', ok).group(1)); sp = int(re.search(r'KJ_TRAINER_FLAG_SPLIT (\d+)', ok).group(1))
start = 0x980 + (mx - sp)   # ENGINE_FLAGS_END + 1 = 0x980 のあとに トレーナーの拡張フラグ、そのあと
start = (start + 7) // 8 * 8
h = ['#ifndef GUARD_CONSTANTS_FLAGS_KJ_FRLG_H', '#define GUARD_CONSTANTS_FLAGS_KJ_FRLG_H',
     '// カントー＆ジョウト: FRLG のカントーのフラグ（tools_kj/gen_flags.py で作成）',
     f'#define KJ_FRLG_FLAGS_START 0x{start:X}', f'#define KJ_FRLG_FLAGS_COUNT {len(names)}']
h += [f'#define FLAG_KJ_{n[5:]:60s} 0x{start + i:X}' for i, n in enumerate(names)]
h += ['#endif', '']
open('include/constants/flags_kj_frlg.h', 'w').write('\n'.join(h))
print('kj flags', len(names))
