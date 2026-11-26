# mont.py START END OUT : 巡回の写真を 8x8 に並べる（番号つき）
import sys, json
from PIL import Image, ImageDraw
a, b, out = int(sys.argv[1]), int(sys.argv[2]), sys.argv[3]
L = json.load(open('/tmp/maplist_sel.json'))
W, H = 160, 107
im = Image.new('RGB', (W * 8, (H + 10) * 8), 'white'); d = ImageDraw.Draw(im)
for k, i in enumerate(range(a, min(b, len(L)))):
    try: t = Image.open(f'/tmp/mapt/w1_m{i:04d}.png').resize((W, H))
    except Exception: continue
    x, y = (k % 8) * W, (k // 8) * (H + 10)
    im.paste(t, (x, y + 10)); d.text((x + 2, y), f'{i} {L[i][0][4:30]}', fill='black')
im.save(out)
