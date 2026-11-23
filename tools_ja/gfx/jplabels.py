# Redraw English label graphics (summary headers, type icons) with the Japanese bold font.
import re,sys
from PIL import Image
R='/home/claude/hns2/'
CM={}
for l in open(R+'charmap.txt',encoding='utf-8'):
    m=re.match(r"^'(.)'\s*=\s*([0-9A-Fa-f]{2})\s*$",l.strip())
    if m and m.group(1) not in CM: CM[m.group(1)]=int(m.group(2),16)
BOLD=Image.open(R+'graphics/fonts/japanese_bold.png'); BP=BOLD.load()
H=8
def glyph(ch):
    i=CM[ch]; cx=(i%16)*8; cy=(i//16)*16
    if H==12:
        g=[[BP[cx+x,cy+4+y] for x in range(8)] for y in range(12)]
    else:
        g=[[BP[cx+x,cy+8+y] for x in range(8)] for y in range(8)]
        # fold the (dakuten) marks of rows 4-7 onto the top rows where the body is empty
        for y in range(4):
            for x in range(8):
                v=BP[cx+x,cy+4+y]
                if v and not g[y][x]: g[y][x]=v
    cols=[x for x in range(8) if any(g[y][x] for y in range(len(g)))]
    if not cols: return [[0]*4 for _ in range(len(g))]
    a,b=cols[0],cols[-1]
    return [r[a:b+1] for r in g]
def strip(text):
    rows=[[] for _ in range(H)]
    for ch in text:
        g=glyph(ch)
        for y in range(H): rows[y]+=g[y]
    return rows
def squeeze(rows,w):
    W=len(rows[0])
    if W<=w: return rows
    return [[r[int(x*W/w)] for x in range(w)] for r in rows]
def draw(px,rows,x0,y0,fg,sh):
    for y in range(len(rows)):
        for x,v in enumerate(rows[y]):
            if v==1: px[x0+x,y0+y]=fg
            elif v==2: px[x0+x,y0+y]=sh
def label(px,x0,x1,y0,text,align='left'):
    # bg = most common index in the area, text=bg-row|2, shadow=bg-row|6
    from collections import Counter
    c=Counter(px[x,y] for x in range(x0,x1+1) for y in range(y0,y0+8) if px[x,y]&15 not in (2,6))
    bg=c.most_common(1)[0][0]; base=bg&0xF0
    for x in range(x0,x1+1):
        for y in range(y0,y0+8): px[x,y]=bg
    rows=squeeze(strip(text),x1-x0+1)
    draw(px,rows,x0,y0,base|2,base|6)

if __name__=='__main__':
    p=R+'graphics/summary_screen/hns/tiles.png'
    im=Image.open(p); px=im.load()
    L=[(2,47,64,'プロフィール'),(74,103,64,'もちもの'),(2,47,72,'とくせい'),(74,111,72,'リボン'),
       (74,103,80,'つよさ'),(2,30,88,'じょうたい'),(2,31,96,'わざ'),(82,119,96,'こうか'),
       (2,71,104,'せつめい'),(102,127,104,'こたい'),(2,71,112,'トレーナーメモ'),(102,127,112,'どりょく')]
    for x0,x1,y0,t in L: label(px,x0,x1,y0,t)
    im.save(p)
    # type icons
    T={'normal':'ノーマル','fight':'かくとう','flying':'ひこう','poison':'どく','ground':'じめん','rock':'いわ',
       'bug':'むし','ghost':'ゴースト','steel':'はがね','fire':'ほのお','water':'みず','grass':'くさ','electric':'でんき',
       'psychic':'エスパー','ice':'こおり','dragon':'ドラゴン','dark':'あく','fairy':'フェアリー','stellar':'ステラ','mystery':'？？？',
       'contest_cool':'かっこよさ','contest_beauty':'うつくしさ','contest_cute':'かわいさ','contest_smart':'かしこさ','contest_tough':'たくましさ'}
    for f,t in T.items():
        p=R+'graphics/types/%s.png'%f; im=Image.open(p); px=im.load()
        bg=px[16,3]; fg=sh=None
        from collections import Counter
        # find text colors from old text: the brightest/most frequent non-bg inside rows 4..11
        c=Counter(px[x,y] for x in range(3,29) for y in range(4,12) if px[x,y]!=bg)
        cols=[k for k,_ in c.most_common(2)]
        pal=im.getpalette()
        lum=lambda i:sum(pal[i*3:i*3+3])
        if len(cols)==2: fg,sh=(cols[0],cols[1]) if lum(cols[0])>lum(cols[1]) else (cols[1],cols[0])
        for x in range(2,30):
            for y in range(3,13): px[x,y]=bg
        H=12; rows=squeeze(strip(t),30); H=8
        w=len(rows[0]); x0=1+(30-w)//2
        for x in range(1,31):
            for y in range(2,14): px[x,y]=bg
        draw(px,rows,x0,2,fg,sh)
        im.save(p)
    print('ok')
    # trainer card (HnS uses the Hoenn tiles)
    p=R+'graphics/trainer_card/tiles.png'; im=Image.open(p); px=im.load()
    def put(x0,x1,y0,y1,text,fg,sh,bgc,ty):
        for x in range(x0,x1+1):
            for y in range(y0,y1+1): px[x,y]=(px[x,y]&0xF0)|bgc
        rows=squeeze(strip(text),x1-x0+1)
        for y in range(8):
            for x,v in enumerate(rows[y]):
                if v==1: px[x0+x,ty+y]=(px[x0+x,ty+y]&0xF0)|fg
                elif v==2 and sh is not None: px[x0+x,ty+y]=(px[x0+x,ty+y]&0xF0)|sh
    put(49,88,1,6,'バッジ',0x1,None,0xa,0)
    put(2,90,68,75,'トレーナーカード',0xf,0x8,0xd,68)
    im.save(p)
    print('card ok')
