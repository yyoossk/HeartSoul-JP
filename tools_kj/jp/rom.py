import struct
R=open('/home/claude/fr/frj.gba','rb').read()
def u32(a): return struct.unpack_from('<I',R,a)[0]
def u16(a): return struct.unpack_from('<H',R,a)[0]
def isptr(v): return 0x08000000<=v<0x09000000
def off(v): return v-0x08000000
def is_header(a):
    if a+0x1c>len(R): return False
    return isptr(u32(a)) and isptr(u32(a+4)) and isptr(u32(a+8)) and (u32(a+12)==0 or isptr(u32(a+12)))
