import glob,os,re,sys
sys.path.insert(0,'/home/claude/work')
import cstr
ROOT='/home/claude/hns2/'
cm=set()
for line in open(ROOT+'charmap.txt',encoding='utf-8'):
    m=re.match(r"^'(.)'",line.strip())
    if m: cm.add(m.group(1))
byfile={}
for f in sorted(glob.glob('/home/claude/work/trc/*.txt')):
    rel=re.sub(r'(\.\d+)?\.txt$','',os.path.basename(f)).replace('__','/')
    byfile.setdefault(rel,{}).update(cstr.load_tr(f))
write='write' in sys.argv
for rel,tr in byfile.items():
    for k,v in tr.items():
        body=re.sub(r'\{[^}]*\}','',v).replace('\\n','').replace('\\p','').replace('\\l','')
        bad=set(c for c in body if c not in cm)
        if bad: print('CHAR',rel,k,''.join(bad))
    # verify source strings unchanged since dump (still English) only apply to original snapshot
    cstr.apply(rel,tr,write)
    print(rel,len(tr))
