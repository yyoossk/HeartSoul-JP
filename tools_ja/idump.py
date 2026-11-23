import json,sys,re
d=json.load(open('/home/claude/work/strings_data.json'))
import glob,os
done=set()
for f in glob.glob('/home/claude/work/tr/*.txt'):
    rel=re.sub(r'(\.\d+)?\.txt$','',os.path.basename(f)).replace('__','/')
    for ln in open(f,encoding='utf-8'):
        if ln.startswith('## '): rel=ln[3:].strip()
        if ln.startswith('@@'): done.add((rel,ln[2:].strip()))
files=sys.argv[1:-1]; maxc=int(sys.argv[-1]); c=0
for rel in files:
    for lab,s in d.get(rel,{}).items():
        if (rel,lab) in done or not re.search(r'[A-Za-z]{2}',re.sub(r'\{[^}]*\}','',s)): continue
        print('##',rel) if c==0 or getattr(sys.modules[__name__],'last',None)!=rel else None
        sys.modules[__name__].last=rel
        print('@@'+lab); print(s); c+=len(s)
        if c>maxc: sys.exit()
