import json,glob,os,re
d=json.load(open('/home/claude/work/strings_data.json'))
done=set()
for f in glob.glob('/home/claude/work/tr/*.txt'):
    rel=re.sub(r'(\.\d+)?\.txt$','',os.path.basename(f)).replace('__','/')
    for ln in open(f,encoding='utf-8'):
        if ln.startswith('## '): rel=ln[3:].strip()
        if ln.startswith('@@'): done.add((rel,ln[2:].strip()))
rels=['data/maps/%s/scripts.inc'%l.split()[0] for l in open('/home/claude/work/map_order.txt').read().split('\n') if l]
tot=rem=0
for r in rels:
    for lab,s in d.get(r,{}).items():
        tot+=len(s)
        if (r,lab) not in done: rem+=len(s)
print('hns maps: total',tot,'remaining',rem,'done %.1f%%'%(100*(tot-rem)/tot))
