# わざの　いりょく・タイプ　と　タイプあいしょう（ボットの　わざえらび　よう）
import re
SRC = '/home/claude/src/HeartSoul-JP'
T = {n: i for i, n in enumerate('NONE NORMAL FIGHTING FLYING POISON GROUND ROCK BUG GHOST STEEL MYSTERY FIRE WATER GRASS ELECTRIC PSYCHIC ICE DRAGON DARK FAIRY'.split())}
def load():
    ids = {}
    for m in re.finditer(r'^\s*(MOVE_\w+) = (\d+),', open(f'{SRC}/include/constants/moves.h').read(), re.M):
        ids[m.group(1)] = int(m.group(2))
    info = {}
    txt = open(f'{SRC}/src/data/moves_info.h').read()
    for m in re.finditer(r'\[(MOVE_\w+)\]\s*=\s*\{(.*?)\n    \},', txt, re.S):
        body = m.group(2)
        pw = re.search(r'\.power\s*=\s*([^,\n]+)', body)
        p = 0
        if pw:
            e = pw.group(1)
            nums = re.findall(r'\?\s*(\d+)', e) or re.findall(r'\d+', e)
            p = int(nums[0]) if nums else 0
        ty = re.search(r'\.type\s*=\s*[^,\n]*?TYPE_(\w+)', body)
        cat = 'STATUS' not in (re.search(r'\.category\s*=\s*([^,\n]+)', body) or [None, ''])[1] if re.search(r'\.category', body) else True
        if m.group(1) in ids:
            info[ids[m.group(1)]] = (p if cat else 0, T.get(ty.group(1), 0) if ty else 0, m.group(1))
    return info
SE = {  # こうげき: {ぼうぎょ: ばいりつ}
 'NORMAL': {'ROCK': .5, 'GHOST': 0, 'STEEL': .5},
 'FIGHTING': {'NORMAL': 2, 'FLYING': .5, 'POISON': .5, 'ROCK': 2, 'BUG': .5, 'GHOST': 0, 'STEEL': 2, 'PSYCHIC': .5, 'ICE': 2, 'DARK': 2, 'FAIRY': .5},
 'FLYING': {'FIGHTING': 2, 'ROCK': .5, 'BUG': 2, 'STEEL': .5, 'GRASS': 2, 'ELECTRIC': .5},
 'POISON': {'POISON': .5, 'GROUND': .5, 'ROCK': .5, 'GHOST': .5, 'STEEL': 0, 'GRASS': 2, 'FAIRY': 2},
 'GROUND': {'FLYING': 0, 'POISON': 2, 'ROCK': 2, 'BUG': .5, 'STEEL': 2, 'FIRE': 2, 'GRASS': .5, 'ELECTRIC': 2},
 'ROCK': {'FIGHTING': .5, 'FLYING': 2, 'GROUND': .5, 'BUG': 2, 'STEEL': .5, 'FIRE': 2, 'ICE': 2},
 'BUG': {'FIGHTING': .5, 'FLYING': .5, 'POISON': .5, 'GHOST': .5, 'STEEL': .5, 'FIRE': .5, 'GRASS': 2, 'PSYCHIC': 2, 'DARK': 2, 'FAIRY': .5},
 'GHOST': {'NORMAL': 0, 'GHOST': 2, 'PSYCHIC': 2, 'DARK': .5},
 'STEEL': {'ROCK': 2, 'STEEL': .5, 'FIRE': .5, 'WATER': .5, 'ELECTRIC': .5, 'ICE': 2, 'FAIRY': 2},
 'FIRE': {'ROCK': .5, 'BUG': 2, 'STEEL': 2, 'FIRE': .5, 'WATER': .5, 'GRASS': 2, 'ICE': 2, 'DRAGON': .5},
 'WATER': {'GROUND': 2, 'ROCK': 2, 'FIRE': 2, 'WATER': .5, 'GRASS': .5, 'DRAGON': .5},
 'GRASS': {'FLYING': .5, 'POISON': .5, 'GROUND': 2, 'ROCK': 2, 'BUG': .5, 'STEEL': .5, 'FIRE': .5, 'WATER': 2, 'GRASS': .5, 'DRAGON': .5},
 'ELECTRIC': {'FLYING': 2, 'GROUND': 0, 'WATER': 2, 'GRASS': .5, 'ELECTRIC': .5, 'DRAGON': .5},
 'PSYCHIC': {'FIGHTING': 2, 'POISON': 2, 'STEEL': .5, 'PSYCHIC': .5, 'DARK': 0},
 'ICE': {'FLYING': 2, 'GROUND': 2, 'STEEL': .5, 'FIRE': .5, 'WATER': .5, 'GRASS': 2, 'ICE': .5, 'DRAGON': 2},
 'DRAGON': {'STEEL': .5, 'DRAGON': 2, 'FAIRY': 0},
 'DARK': {'FIGHTING': .5, 'GHOST': 2, 'PSYCHIC': 2, 'DARK': .5, 'FAIRY': .5},
 'FAIRY': {'FIGHTING': 2, 'POISON': .5, 'STEEL': .5, 'FIRE': .5, 'DRAGON': 2, 'DARK': 2},
}
N = {v: k for k, v in T.items()}
def eff(atk, defs):
    r = 1.0
    for d in defs:
        if d in (0, 10): continue
        r *= SE.get(N.get(atk, ''), {}).get(N.get(d, ''), 1)
    return r
