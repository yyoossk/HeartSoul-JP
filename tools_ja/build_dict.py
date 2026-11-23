import sys,json;sys.path.insert(0,'/home/claude/work')
import cm
enc=cm.load(); dec={v:k for k,v in enc.items()}
J=open('/home/claude/roms/Pocket Monsters - Emerald (Japan).gba','rb').read()
U=open('/home/claude/roms/Pokemon - Emerald Version (USA, Europe).gba','rb').read()
# english decoding: charmap latin
def s(rom,o,n):
    out=''
    for b in rom[o:o+n]:
        if b==0xff: break
        out+=decE.get(b,'{%02X}'%b) if rom is U else dec.get(b,'{%02X}'%b)
    return out
import re
decE={}
for line in open('/home/claude/hns/charmap.txt',encoding='utf-8'):
    m=re.match(r"^'(.)'\s*=\s*([0-9A-Fa-f]{2})\s*$",line.split('@')[0].strip())
    if m:
        b=int(m.group(2),16)
        if b>=0xA1 or b==0: decE.setdefault(b,m.group(1))
decE[0]=' '
def fe(rom,w,table):
    return rom.find(bytes(table[c] for c in w)+b'\xff')
encE={v:k for k,v in decE.items()}
def tab(rom,start,size,count): return [s(rom,start+i*size,size) for i in range(count)]
out={}
specs=[('species','フシギダネ','BULBASAUR',6,11,412),('moves','はたく','POUND',8,13,355),('abilities','あくしゅう','STENCH',8,13,78),('items','マスターボール','MASTER BALL',0x28,0x2C,377)]
for name,jw,ew,js,es,n in specs:
    jo=fe(J,jw,enc)-js; eo=fe(U,ew,encE)-es
    jt=tab(J,jo,js,n); et=tab(U,eo,es,n)
    out[name]=dict(zip(et,jt))
    print(name,hex(jo),hex(eo),et[1:4],jt[1:4],et[-1],jt[-1])
json.dump(out,open('/home/claude/work/names.json','w'),ensure_ascii=False,indent=0)
