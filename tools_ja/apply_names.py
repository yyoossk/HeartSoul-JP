import re,json,sys
D=json.load(open('/home/claude/work/names.json'))
extra=json.load(open('/home/claude/work/extra.json')) if len(sys.argv)>1 else {}
files={'species':'src/data/text/species_names.h','moves':'src/data/text/move_names.h','abilities':'src/data/text/abilities.h','items':'src/data/items.h'}
miss={}
for k,f in files.items():
    p='/home/claude/hns/'+f; t=open(p,encoding='utf-8').read()
    d=dict(D[k]); d.update(extra.get(k,{}))
    norm={re.sub(r'[^A-Z0-9]','',a.upper()):b for a,b in d.items()}
    m=[]
    def rep(mo):
        pre,name=mo.group(1),mo.group(2)
        if k=='abilities' and 'Description' in pre: return mo.group(0)
        key=re.sub(r'[^A-Z0-9]','',name.upper())
        if key in norm and norm[key]: return pre+'_("'+norm[key]+'")'
        if not re.search(r'[A-Za-z]',name): return mo.group(0)
        m.append(name); return mo.group(0)
    if k=='items': pat=r'(\.name = )_\("([^"]*)"\)'
    elif k=='abilities': pat=r'(\[ABILITY_\w+\] = |static const u8 s\w+Description\[\] = )_\("([^"]*)"\)'
    else: pat=r'(\[\w+\] = )_\("([^"]*)"\)'
    t=re.sub(pat,rep,t)
    if len(sys.argv)>1: open(p,'w',encoding='utf-8').write(t)
    miss[k]=m; print(k,'unmatched',len(m))
json.dump(miss,open('/home/claude/work/missing.json','w'),ensure_ascii=False,indent=0)
