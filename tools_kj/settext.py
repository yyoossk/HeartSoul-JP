# settext.py : マップのセリフをラベル単位で差しかえる（カントー＆ジョウト用）
import re
def set_text(path, label, text):
    s = open(path, encoding='utf-8').read()
    pat = re.compile(r'(?m)^(' + re.escape(label) + r':\n)((?:\t\.string "[^\n]*"\n)+)')
    m = pat.search(s)
    assert m, (path, label)
    body = ''.join('\t.string "' + line + '"\n' for line in text)
    s = s[:m.start(2)] + body + s[m.end(2):]
    open(path, 'w', encoding='utf-8').write(s)
