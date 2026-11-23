import re
def load():
    enc={};dec={}
    for line in open('/home/claude/hns/charmap.txt',encoding='utf-8'):
        m=re.match(r"^'(.)'\s*=\s*([0-9A-Fa-f]{2})\s*$",line.split('@')[0].strip())
        if m:
            c,b=m.group(1),int(m.group(2),16)
            enc.setdefault(c,b)
    return enc
