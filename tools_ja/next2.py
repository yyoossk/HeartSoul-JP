import json,sys,re,glob,os
d=json.load(open('/home/claude/work/strings_data.json'))
used=json.load(open('/home/claude/work/used_common.json'))
done=set()
for f in glob.glob('/home/claude/work/tr/*.txt'):
    rel=None
    for ln in open(f,encoding='utf-8'):
        if ln.startswith('## '): rel=ln[3:].strip()
        if ln.startswith('@@'): done.add((rel,ln[2:].strip()))
maxc=int(sys.argv[1]) if len(sys.argv)>1 else 13000
c=0;last=None;tot=rem=0
for rel in [l for l in open('/home/claude/work/common_order.txt').read().split('\n') if l]:
    for lab in used.get(rel,[]):
        s=d[rel][lab]; tot+=len(s)
        if not s.endswith('$'): continue
        if (rel,lab) in done or not re.search(r'[A-Za-z]{2}',re.sub(r'\{[^}]*\}','',s)): continue
        rem+=len(s)
        if c>maxc: continue
        if last!=rel: print('##',rel); last=rel
        print('@@'+lab); print(s); c+=len(s)
print('#REMAIN',rem,'of',tot,file=sys.stderr)
