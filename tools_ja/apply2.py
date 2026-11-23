import re,json,sys,glob
ROOT='/home/claude/hns2/'
D=json.load(open('/home/claude/work/names.json'))
extra={}
for f in sorted(glob.glob('/home/claude/work/extra*.json')):
    for k,v in json.load(open(f)).items(): extra.setdefault(k,{}).update(v)
spec={'species':(glob.glob(ROOT+'src/data/pokemon/species_info/gen_*_families.h'),r'(\.speciesName = _\(")([^"]*)("\))'),
 'moves':([ROOT+'src/data/moves_info.h'],r'(\.name = COMPOUND_STRING\(")([^"]*)("\))'),
 'abilities':([ROOT+'src/data/abilities.h'],r'(\.name = _\(")([^"]*)("\))'),
 'items':([ROOT+'src/data/items.h'],r'(\.name = ITEM_NAME\(")([^"]*)("\))')}
N=lambda s:re.sub(r'[^A-Z0-9]','',s.upper().replace('É','E').replace('é','E'))
miss={}
for k,(files,pat) in spec.items():
    d={N(a):b for a,b in D[k].items() if N(a)}
    d.update({N(a):b for a,b in extra.get(k,{}).items()})
    m=[]
    for p in files:
        t=open(p,encoding='utf-8').read()
        def rep(mo):
            nm=mo.group(2)
            if not re.search(r'[A-Za-z]',nm): return mo.group(0)
            if N(nm) in d: return mo.group(1)+d[N(nm)]+mo.group(3)
            b=re.sub(r'-[AGHP]$','',nm)
            if b!=nm and N(b) in d: return mo.group(1)+d[N(b)]+mo.group(3)
            m.append(nm); return mo.group(0)
        t2=re.sub(pat,rep,t)
        if 'write' in sys.argv and t2!=t: open(p,'w',encoding='utf-8').write(t2)
    miss[k]=sorted(set(m)); print(k,'missing',len(miss[k]))
json.dump(miss,open('/home/claude/work/missing2.json','w'),ensure_ascii=False,indent=0)
