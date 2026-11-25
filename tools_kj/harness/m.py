# python3 m.py 出力.png 画像1 画像2 ... : 並べて1枚に（横に cols 枚）
import sys
from PIL import Image
out = sys.argv[1]; fs = sys.argv[2:]; cols = 3 if len(fs) > 4 else 2
ims = [Image.open(f).resize((360, 240)) for f in fs]
rows = (len(ims) + cols - 1) // cols
c = Image.new('RGB', (360 * cols, 240 * rows), (40, 40, 40))
for i, im in enumerate(ims): c.paste(im, ((i % cols) * 360, (i // cols) * 240))
c.save(out)
