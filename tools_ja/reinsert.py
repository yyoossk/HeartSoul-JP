import re,json,glob,sys,os
ROOT='/home/claude/hns2/'
cm=set()
for line in open(ROOT+'charmap.txt',encoding='utf-8'):
    m=re.match(r"^'(.)'",line.strip())
    if m: cm.add(m.group(1))
src=json.load(open('/home/claude/work/strings_data.json'))
PH=re.compile(r'\{[^}]*\}')
W={'{PLAYER}':7,'{RIVAL}':7,'{KUN}':3,'{STR_VAR_1}':10,'{STR_VAR_2}':10,'{STR_VAR_3}':10}
def width(line):
    n=0
    for p in PH.split(line): n+=len(p)
    for p in PH.findall(line): n+=W.get(p,0 if p.startswith('{COLOR') or p.startswith('{SHADOW') or p.startswith('{PAUSE') or p.startswith('{FONT') else 6)
    return n
def check(rel,lab,jp,maxw):
    errs=[]
    en=src.get(rel,{}).get(lab)
    if en is None: errs.append('label not in source')
    else:
        a=sorted(x for x in PH.findall(en) if not x.startswith('{PAUSE'))
        b=sorted(x for x in PH.findall(jp) if not x.startswith('{PAUSE'))
        if [x for x in a if x not in b]: errs.append('placeholder missing %s'%[x for x in a if x not in b])
    body=PH.sub('',jp.replace('\\n','').replace('\\p','').replace('\\l',''))
    bad=[c for c in body if c not in cm and c not in '\\']
    if bad: errs.append('chars '+''.join(sorted(set(bad))))
    for ln in re.split(r'\\[npl]',jp):
        if width(ln)>maxw: errs.append('wide(%d) %s'%(width(ln),ln))
    return errs
def apply(rel,tr,write):
    p=ROOT+rel; lines=open(p,encoding='utf-8').read().split('\n')
    lab=re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::?\s*$'); st=re.compile(r'^\s*\.string\s+"')
    out=[];i=0;done=set()
    while i<len(lines):
        ln=lines[i]; out.append(ln); m=lab.match(ln); i+=1
        if m and m.group(1) in tr:
            j=i
            while j<len(lines) and (st.match(lines[j]) or (not lines[j].strip() and False)): j+=1
            if j>i:
                en=src.get(rel,{}).get(m.group(1),'$')
                out.append('\t.string "%s%s"'%(tr[m.group(1)].replace('"','\\"'),'$' if en.endswith('$') else '')); i=j; done.add(m.group(1))
    if write: open(p,'w',encoding='utf-8').write('\n'.join(out))
    return done
def load_multi(f):
    res={};rel=re.sub(r'(\.\d+)?\.txt$','',os.path.basename(f)).replace('__','/');cur=None
    for ln in open(f,encoding='utf-8').read().split('\n'):
        if ln.startswith('## '): rel=ln[3:].strip(); cur=None; continue
        if ln.startswith('@@'): cur=ln[2:].strip(); res.setdefault(rel,{})[cur]=''; continue
        if cur is not None: res[rel][cur]+=ln.strip()
    return res
def load_tr(f):
    tr={};cur=None
    for ln in open(f,encoding='utf-8').read().split('\n'):
        if ln.startswith('@@'): cur=ln[2:].strip(); tr[cur]=''; continue
        if cur is not None: tr[cur]+=ln.strip()
    return tr
if __name__=='__main__':
    write='write' in sys.argv; maxw=int(os.environ.get('MAXW','26'))
    total=0
    allt={}
    for f in sorted(glob.glob('/home/claude/work/tr/*.txt')):
        for rel,tr in load_multi(f).items(): allt.setdefault(rel,{}).update(tr)
    bad=False
    for rel,tr in allt.items():
        for lab,jp in tr.items():
            e=check(rel,lab,jp,maxw)
            if e: print(rel,lab,e)
            if any(x.startswith('chars') or x.startswith('placeholder') for x in e): bad=True
    if bad and write: print('ABORT: fix errors first'); raise SystemExit(1)
    for rel,tr in allt.items():
        d=apply(rel,tr,write); total+=len(d)
        miss=set(tr)-d
        if miss: print('NOT APPLIED',rel,miss)
    print('applied',total)
