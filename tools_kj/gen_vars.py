# FRLG のカントーで使う変数を、ジョウトのマップだけで使う hns の変数と共用にする（ジョウトに着いたら 0 に戻す）
import re, sys, os, glob
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S
fr = open('include/constants/vars_frlg.h').read(); hn = open('include/constants/vars_hns.h').read(); vb = open('include/constants/vars.h').read()
used = set()
for f in S.files(): used |= set(re.findall(r'\bVAR_\w+', open(f).read()))
need = sorted(v for v in used if re.search(r'#define\s+' + v + r'\b', fr) and not re.search(r'#define\s+' + v + r'\b', vb)
              and 'ONE_ISLAND' not in v)
# 候補1: hns の安全な空き（VAR_UNUSED_HNS_*、UNSAFE でないもの）
# 候補2: ジョウトの *_hns マップのスクリプトだけで使う hns の変数（ジョウトに着いたら 0 に戻す）
JOHTO = re.compile(r'NewBark|Cherrygrove|Violet|Azalea|Goldenrod|Ecruteak|Olivine|Cianwood|Mahogany|Blackthorn|Ilex|Ruins|Sprout|Union|Slowpoke|BurnedTower|TinTower|LakeOfRage|IcePath|DragonsDen|NationalPark|Route(29|3\d|4[0-6])_|Route(29|3\d|4[0-6])$|DarkCave|MtMortar|WhirlIsland|Lighthouse|RadioTower|Underground|BellTower')
csrc = ''.join(open(f, errors='ignore').read() for f in glob.glob('src/**/*.c', recursive=True) + glob.glob('include/**/*.h', recursive=True) if 'vars' not in f)
scripts = {f: open(f, errors='ignore').read() for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc') + glob.glob('data/maps/*/map.json')}
cands = [(n, num, False) for l in hn.splitlines() for n, num in re.findall(r'#define\s+(VAR_UNUSED_HNS_\w+)\s+(0x\w+)', l) if 'UNSAFE' not in l and not re.search(r'\b' + n + r'\b', csrc)]  # DexNav などの　設定で　つかわれている　ものは　のぞく
for m in re.finditer(r'#define\s+(VAR_\w+)\s+(0x4[0-9A-Fa-f]{3})\b', hn):
    v = m.group(1)
    if v.startswith('VAR_UNUSED') or re.search(r'\b' + v + r'\b', csrc): continue
    users = [f for f, t in scripts.items() if re.search(r'\b' + v + r'\b', t)]
    if not users: continue
    if any(not (f.split('/')[-2].endswith('_hns') and JOHTO.search(f.split('/')[-2])) for f in users): continue
    cands.append((v, m.group(2), True))
print('need', len(need), 'cands', len(cands))
if len(cands) < len(need): sys.exit('足りない')
out = ['#ifndef GUARD_CONSTANTS_VARS_KJ_H', '#define GUARD_CONSTANTS_VARS_KJ_H',
       '// カントー＆ジョウト: FRLG のカントーの変数は ジョウトのマップの変数と共用（tools_kj/gen_vars.py で作成）',
       '// カントー編では ジョウトのマップに行かない。ジョウトに着いたら KJ_ResetKantoVars で 0 に戻す']
shared = []
# セーブの　なかみを　かえないため、まえの　わりあてを　そのまま　つかう（つかえなく　なった　ものだけ　あいている　ところへ）
prev = {}
if os.path.exists('include/constants/vars_kj.h'):
    prev = dict((v, hv) for v, hv in re.findall(r'#define (VAR_\w+) 0x\w+ // = (\w+)', open('include/constants/vars_kj.h').read()))
byname = {c[0]: c for c in cands}
taken = set(prev[v] for v in need if v in prev and prev[v] in byname)
rest = iter(c for c in cands if c[0] not in taken)
assign = [(v, byname[prev[v]] if v in prev and prev[v] in byname else next(rest)) for v in need]
for (v, (hv, num, sh)) in assign:
    out.append(f'#undef {v}\n#define {v} {num} // = {hv}')
    if sh: shared.append(v)
out.append('// ジョウトに着いたら 0 に戻す変数\n#define KJ_SHARED_VARS_LIST \\\n' + ' \\\n'.join(f'    X({v})' for v in shared))
print('shared', shared)
out += ['#endif', '']
open('include/constants/vars_kj.h', 'w').write('\n'.join(out))
