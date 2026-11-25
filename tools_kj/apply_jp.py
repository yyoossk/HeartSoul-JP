# 日本版ファイアレッドから取り出した会話（jp_align.json）を、hns の FRLG マップのスクリプトの .string に入れる
import re, json, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import symscan as S
D = json.load(open(sys.argv[1] if len(sys.argv) > 1 else '/home/claude/fr/jp_align.json'))
def conv(s):
    def fc(m):
        b = m.group(1).split()
        if b[0] in ('06', '1D'): return ''            # 字の種類の切りかえは使わない
        return ''.join('{0x%s}' % x for x in ['FC'] + b)
    s = re.sub(r'\{FC ([0-9A-F ]+)\}', fc, s)
    return s
def to_lines(s):
    # \n \l \p のあとで行を分ける
    parts = re.split(r'(?<=\\[nlp])', s)
    return ''.join(f'\t.string "{p}"\n' for p in parts if p)
done = set(); files = 0
for f in S.files():
    t = open(f).read()
    def rep(m):
        lb = m.group(1); key = lb[:-3] if lb.endswith('_Kj') else lb
        if key not in D and key.endswith('_Frlg') and key[:-5] in D: key = key[:-5]
        if key not in D: return m.group(0)
        done.add(lb[:-3] if lb.endswith('_Kj') else lb)
        return f'{lb}::\n' + to_lines(conv(D[key]['jp']))
    t2 = re.sub(r'(?m)^(\w+)::\n((?:[ \t]*\.string[^\n]*\n)+)', rep, t)
    if t2 != t: open(f, 'w').write(t2); files += 1
left = []
for f in S.files():
    for lb in re.findall(r'(?m)^(\w+)::\n[ \t]*\.string', open(f).read()):
        if lb not in done and (lb[:-3] if lb.endswith('_Kj') else lb) not in done: left.append(lb)
print('files', files, 'labels', len(done), 'still english', len(left))
open('/tmp/kj_left.txt', 'w').write('\n'.join(left))
