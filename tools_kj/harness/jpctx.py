import re,sys
inv={};cm={}
for l in open('charmap.txt',encoding='utf-8'):
    m=re.match(r"'(.)'\s*=\s*([0-9A-F]{2})\s*$",l)
    if m:
        c,v=m.group(1),int(m.group(2),16)
        if c not in cm: cm[c]=v
        if '\u3040'<=c<='\u30ff' or c in '！？、。　ー‥『』「」・…' or v not in inv: inv[v]=c
cm['　']=0x00
rom=open('/home/claude/fr/frj.gba','rb').read()
def dec(t): return ''.join('\\n' if b==0xFE else '\\p' if b==0xFB else '\\l' if b==0xFA else '$' if b==0xFF else '{FD}' if b==0xFD else inv.get(b,f'[{b:02x}]') for b in t)
for lab in sys.argv[1:]:
    f,l=lab.split(':')
    s=open(f'data/maps/{f}/scripts.inc',encoding='utf-8').read()
    m=re.search(r'(?m)^'+l+r'::?\n((?:\t\.string "[^\n]*"\n)+)',s)
    t=''.join(re.findall(r'"(.*)"',m.group(1)))
    t=t.replace('\\n','\n').replace('\\p','\x01').replace('\\l','\x02').rstrip('$')
    tail=t[-6:]
    try: pat=bytes({'\n':0xFE,'\x01':0xFB,'\x02':0xFA}.get(c, cm.get(c,0)) for c in tail)
    except Exception as e: print(lab,'enc fail',e); continue
    i=rom.find(pat)
    if i<0: print(lab,'notfound',repr(tail)); continue
    end=rom.index(b'\xff',i)
    j=end
    # 前の　0xFF か　スクリプトの　おわり（0x02/0x03）まで　さかのぼる
    k=i
    while k>0 and rom[k-1]!=0xFF and end-k<400: k-=1
    print('==',lab, hex(k), hex(i))
    print('   ', dec(rom[k:end+1]))
