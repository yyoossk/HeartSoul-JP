# savchk.py SAV : エメラルド系のセーブの区画を調べる
import sys, struct
d = open(sys.argv[1], 'rb').read()
def cks(b, n):
    s = 0
    for i in range(0, n, 4): s = (s + struct.unpack_from('<I', b, i)[0]) & 0xFFFFFFFF
    return ((s >> 16) + s) & 0xFFFF
for slot in range(2):
    out = []
    for k in range(14):
        o = (slot * 14 + k) * 0x1000
        sid, ck, sig, cnt = struct.unpack_from('<HHII', d, o + 0xFF4)
        out.append((sid, ck, hex(sig), cnt, o))
    print('slot', slot, [(x[0], x[3]) for x in out], 'sig ok' if all(x[2] == '0x8012025' for x in out) else 'BADSIG')
    for sid, ck, sig, cnt, o in out:
        ok = [n for n in (0xF80, 0xF2C, 0xEB4, 0x3D0, 0x4D0, 0x3DEC - 0xF80 * 3) if cks(d[o:], n) == ck]
        if not ok: print('  sector', sid, 'checksum mismatch', hex(ck))
