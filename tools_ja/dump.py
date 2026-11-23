import sys,json;sys.path.insert(0,'/home/claude/work')
import cm
enc=cm.load(); dec={v:k for k,v in enc.items()}
rom=open('/home/claude/roms/Pocket Monsters - Emerald (Japan).gba','rb').read()
def s(o,n):
    out=''
    for b in rom[o:o+n]:
        if b==0xff: break
        out+=dec.get(b,'{%02X}'%b)
    return out
def table(start,size,count): return [s(start+i*size,size) for i in range(count)]
def find(w): return rom.find(bytes(enc[c] for c in w)+b'\xff')
