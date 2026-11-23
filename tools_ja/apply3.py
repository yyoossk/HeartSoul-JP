import re,sys,os
sys.path.insert(0,'/home/claude/work')
import reinsert as R
ROOT='/home/claude/hns2/'
write='write' in sys.argv
tr=R.load_multi(sys.argv[1])
lab=re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::?\s*(@.*)?$')
blk=re.compile(r'^\s*(\.string\s+"|\.if\b|\.else\b|\.endif\b)')
PH=re.compile(r'\{[^}]*\}')
tot=0;bad=0
for rel,t in tr.items():
    p=ROOT+rel; L=open(p,encoding='utf-8').read().split('\n'); out=[]; i=0; done=set()
    while i<len(L):
        ln=L[i]; out.append(ln); m=lab.match(ln.strip()); i+=1
        if m and m.group(1) in t:
            j=i; en=''
            while j<len(L) and blk.match(L[j]):
                mm=re.search(r'\.string\s+"(.*)"',L[j]);
                if mm: en+=mm.group(1)
                j+=1
            jp=t[m.group(1)]
            body=PH.sub('',jp.replace('\\n','').replace('\\p','').replace('\\l',''))
            badc=[c for c in body if c not in R.cm]
            a=set(x for x in PH.findall(en) if not x.startswith('{PAUSE'))
            b=set(x for x in PH.findall(jp) if not x.startswith('{PAUSE'))
            wide=[l for l in re.split(r'\\[npl]',jp) if R.width(l)>26]
            if badc or (a-b) or wide: print(rel,m.group(1),badc,a-b,wide); bad+=1
            out.append('\t.string "%s$"'%jp); i=j; done.add(m.group(1))
    miss=set(t)-done
    if miss: print('MISS',rel,miss)
    tot+=len(done)
    if write and not bad: open(p,'w',encoding='utf-8').write('\n'.join(out))
print('ok',tot,'bad',bad)
