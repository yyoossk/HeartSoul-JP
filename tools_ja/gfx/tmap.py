# compose a GBA text-bg tilemap with an indexed tileset png (for locating/replacing label tiles)
import struct,sys
from PIL import Image
def load(tmap,tset,w=32,base=0):
    T=Image.open(tset); tw=T.width//8
    d=open(tmap,'rb').read(); n=len(d)//2
    ents=struct.unpack('<%dH'%n,d)
    h=n//w
    out=Image.new('P',(w*8,h*8)); out.putpalette(T.getpalette())
    pal_im=T.load(); op=out.load(); info={}
    for i,e in enumerate(ents):
        t=(e&0x3FF)-base; hf=e>>10&1; vf=e>>11&1; pal=e>>12
        x0,y0=(i%w)*8,(i//w)*8
        info[(i%w,i//w)]=(t,hf,vf,pal)
        if t<0 or t>=tw*(T.height//8): continue
        tx,ty=(t%tw)*8,(t//tw)*8
        for y in range(8):
            for x in range(8):
                sx=7-x if hf else x; sy=7-y if vf else y
                v=pal_im[tx+sx,ty+sy]
                op[x0+x,y0+y]=(v&15)|(pal<<4)
    return out,info
if __name__=='__main__':
    im,_=load(sys.argv[1],sys.argv[2],int(sys.argv[3]) if len(sys.argv)>3 else 32)
    im.convert('RGB').resize((im.width*2,im.height*2)).save(sys.argv[4] if len(sys.argv)>4 else '/tmp/t/tm.png')
def writeback(im,info,tset,cells):
    """copy pixels of given screen cells back into the tileset (no flips)"""
    T=Image.open(tset); tp=T.load(); tw=T.width//8; ip=im.load()
    for (cx,cy) in cells:
        t,hf,vf,pal=info[(cx,cy)]
        assert not hf and not vf
        tx,ty=(t%tw)*8,(t//tw)*8
        for y in range(8):
            for x in range(8):
                tp[tx+x,ty+y]=(tp[tx+x,ty+y]&0xF0)|(ip[cx*8+x,cy*8+y]&15)
    T.save(tset)
