# C string tool: list/apply translations of _("...") and COMPOUND_STRING("...") literals
import re,sys,os,json
ROOT='/home/claude/hns2/'
LIT=re.compile(r'(_|COMPOUND_STRING|ITEM_NAME|ITEM_PLURAL_NAME)\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)')
PART=re.compile(r'"((?:[^"\\]|\\.)*)"')
def items(path):
    t=open(ROOT+path,encoding='utf-8').read()
    res=[]
    for m in LIT.finditer(t):
        s=''.join(PART.findall(m.group(2)))
        res.append((m.start(),m.end(),m.group(1),s))
    return t,res
def needs(s):
    body=re.sub(r'\{[^}]*\}','',s)
    return re.search(r'[A-Za-z]{2,}',body) is not None
def dump(path,start=0,count=10**9,maxc=10**9):
    t,res=items(path); n=0;c=0
    for i,(a,b,k,s) in enumerate(res):
        if i<start or not needs(s): continue
        print('@@%d %s'%(i,s)); n+=1; c+=len(s)
        if n>=count or c>=maxc: break
def load_tr(f):
    tr={};cur=None
    for ln in open(f,encoding='utf-8').read().split('\n'):
        if ln.startswith('@@'): cur=int(ln[2:].split()[0]); tr[cur]=''; continue
        if cur is not None: tr[cur]+=ln.strip()
    return tr
def apply(path,tr,write):
    t,res=items(path); out=[];last=0
    for i,(a,b,k,s) in enumerate(res):
        if i in tr:
            out.append(t[last:a]); out.append('%s("%s")'%(k,tr[i].replace('"','\\"'))); last=b
    out.append(t[last:])
    if write: open(ROOT+path,'w',encoding='utf-8').write(''.join(out))
if __name__=='__main__':
    cmd=sys.argv[1]
    if cmd=='dump': dump(sys.argv[2],int(sys.argv[3]) if len(sys.argv)>3 else 0,10**9,int(sys.argv[4]) if len(sys.argv)>4 else 10**9)
    if cmd=='count':
        for p in sys.argv[2:]:
            t,res=items(p); print(p,sum(len(s) for *_,s in res if needs(s)),sum(1 for *_,s in res if needs(s)))
