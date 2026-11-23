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
    # ---- Pokedex (HGSS style) ----
    import sys as _s; _s.path.insert(0,R+'tools_ja/gfx'); import tmap
    D=R+'graphics/pokedex/hgss/'
    def glyph_rows(text,top):
        # rows `top`..15 of each bold glyph cell (no dakuten folding)
        rows=None
        for ch in text:
            i=CM[ch]; cx=(i%16)*8; cy=(i//16)*16
            g=[[BP[cx+x,cy+y] for x in range(8)] for y in range(top,16)]
            cols=[x for x in range(8) if any(r[x] for r in g)] or [0,3]
            g=[r[cols[0]:cols[-1]+1] for r in g]
            rows=g if rows is None else [a+b for a,b in zip(rows,g)]
        return rows
    def tm_label(tm,ts,x0,x1,y0,y1,text,fg,sh,ty):
        im,info=tmap.load(D+tm,D+ts); px=im.load()
        from collections import Counter
        for y in range(y0,y1+1):
            c=Counter(px[x,y]&15 for x in range(x0,x1+1) if px[x,y]&15 not in (fg,sh))
            b=c.most_common(1)[0][0] if c else 1
            for x in range(x0,x1+1): px[x,y]=(px[x,y]&0xF0)|b
        rows=glyph_rows(text,16-(y1-ty+1)); rows=squeeze(rows,x1-x0+1)
        xs=x0+(x1-x0+1-len(rows[0]))//2
        for y,r in enumerate(rows):
            for x,v in enumerate(r):
                if v==1: px[xs+x,ty+y]=(px[xs+x,ty+y]&0xF0)|fg
                elif v==2: px[xs+x,ty+y]=(px[xs+x,ty+y]&0xF0)|sh
        cells=set((x//8,y//8) for x in range(x0,x1+1) for y in range(y0,y1+1))
        tmap.writeback(im,info,D+ts,cells)
    for ts in ['tileset_menu_list.png','tileset_menu_list_DECA.png']:
        tm_label('tilemap_list_screen.bin',ts,114,141,149,159,'メニュー',0xf,0x4,150)
        tm_label('tilemap_list_screen.bin',ts,149,183,149,159,'けんさく',0xf,0x4,150)
    def spr_text(ts,y0,y1,x0,x1,text,fg,sh,fold=False,top=6):
        im=Image.open(D+ts); px=im.load(); bg=px[31,200]
        for y in range(y0,y1+1):
            for x in range(x0,x1+1): px[x,y]=bg
        if fold:
            global H
            rows=strip(text)
        else:
            rows=glyph_rows(text,top)
        rows=squeeze(rows,x1-x0+1)
        for y,r in enumerate(rows[:y1-y0+1]):
            for x,v in enumerate(r):
                if v==1: px[x0+x,y0+y]=(px[x0+x,y0+y]&0xF0)|fg
                elif v==2: px[x0+x,y0+y]=(px[x0+x,y0+y]&0xF0)|sh
        im.save(D+ts)
    def spr64(ts,y0,text,fg,sh):
        # 64x32 sprite stored as 1D tiles in a 32px wide sheet: compose, draw, decompose
        im=Image.open(D+ts); px=im.load(); bg=px[31,200]
        base=(y0//8)*4
        def pos(sx,sy):
            t=base+(sy//8)*8+(sx//8); return (t%4)*8+sx%8,(t//4)*8+sy%8
        for sy in range(5,15):
            for sx in range(14,64):
                p=pos(sx,sy); px[p]=bg
        rows=strip(text)
        for y in range(8):
            for x,v in enumerate(rows[y]):
                if v:
                    p=pos(16+x,6+y); px[p]=(px[p]&0xF0)|(fg if v==1 else sh)
        im.save(D+ts)
    for ts in ['tileset_interface_hns.png','tileset_interface_DECA_hns.png']:
        spr_text(ts,83,92,0,31,'けんさく',0x1,0xf)
        spr_text(ts,115,124,0,31,'メニュー',0x1,0xf)
        spr_text(ts,324,331,0,31,'ジョウト',0xf,0x4,fold=True)
        spr_text(ts,340,347,0,31,'ぜんこく',0xf,0x4,fold=True)
        spr64(ts,128,'みつけた',0xf,0x4)
        spr64(ts,192,'つかまえた',0xf,0x4)
    print('dex ok')
    # ---- battle "MOVE INFO" buttons ----
    B=R+'graphics/battle_interface/'
    for f,(y0,y1) in {'move_info_window_start':(13,23),'move_info_window_l':(11,21),'move_info_window_r':(11,21)}.items():
        im=Image.open(B+f+'.png'); px=im.load()
        for y in range(y0,y1+1):
            for x in range(4,28): px[x,y]=(px[x,y]&0xF0)|0xd
        rows=squeeze(strip('せつめい'),24)
        ty=y0+(y1-y0+1-8)//2; tx=4+(24-len(rows[0]))//2
        for y in range(8):
            for x,v in enumerate(rows[y]):
                if v==1: px[tx+x,ty+y]=(px[tx+x,ty+y]&0xF0)|0x5
        im.save(B+f+'.png')
    print('btn ok')
