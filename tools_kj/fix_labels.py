# FRLG のカントーのスクリプトのラベルが hns のラベルとぶつかるとき、FRLG 側を 〜_Kj にする（何度動かしても同じ）
import re, sys, os, glob, json
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S, kanto_maps as K
fr_files = S.files()
fr_json = [f'data/maps/{m}/map.json' for m in K.kanto_maps()]
lab = re.compile(r'(?m)^([A-Za-z_]\w*)::?')
fr_labels = set()
for f in fr_files: fr_labels |= set(lab.findall(open(f).read()))
# hns ビルドで組み立てられる ほかのファイルのラベル
others = set()
inc = re.compile(r'\.include\s+"([^"]+)"')
seen = set()
def walk(f):
    if f in seen or not os.path.exists(f) or f in fr_files or f == 'data/kj_frlg_scripts.inc': return
    seen.add(f); t = open(f, errors='ignore').read()
    others.update(lab.findall(t))
    for g in inc.findall(t): walk(g)
for top in glob.glob('data/*.s'): walk(top)
coll = sorted(l for l in fr_labels if l in others)
print('collisions', len(coll))
if coll:
    pat = re.compile(r'\b(' + '|'.join(map(re.escape, coll)) + r')\b(?!_Kj)')
    for f in fr_files + fr_json:
        s = open(f).read(); t = pat.sub(r'\1_Kj', s)
        if t != s: open(f, 'w').write(t)
