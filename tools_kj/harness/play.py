# play.py STORY START : てじゅんを　じゅんに　すすめる（1てじゅん　ごとに　じょうたいを　ほぞん）
import faulthandler, signal
faulthandler.register(signal.SIGUSR1)
import sys, importlib, shutil, os
sys.path.insert(0, '/home/claude/kjtest')
from bot import Bot
story = importlib.import_module(sys.argv[1])
start = int(sys.argv[2]) if len(sys.argv) > 2 else 0
D = __import__('os').environ.get('PLAYDIR', '/tmp/play')
boot = sys.argv[3] if len(sys.argv) > 3 else None  # .sav から　つづきから　はじめる（ROM を　つくりなおした　とき）
E = __import__('os').environ
st = '-' if boot else (f'{D}/step{start:03d}.ss' if start else E.get('START_SS', story.START_STATE))
shutil.copy(boot or (f'{D}/step{start:03d}.sav' if start else E.get('START_SAV', story.START_SAV)), f'{D}/cur.sav')
b = Bot(__import__('os').environ.get('ROMGBA') or story.ROM, f'{D}/cur.sav', st)
b.wait(2)
if boot:
    for i in range(400):
        if b.in_overworld() and not b.busy() and i > 40: break
        b.press('A', 2, 20)
    b.wait(60); b.log('BOOTED', b.maps.get(b.mapkey(), {}).get('id'), b.player())
b.fast_opts()
for v, val in getattr(story, 'ON_BOOT_VARS', []) if boot else []: b.set_var(v, val)  # ROM を　つくりなおして　かわった　変数の　ばしょへ
b.capture = getattr(story, 'CAPTURE', None)
if getattr(story, 'AVOID', None): type(b).AVOID = tuple(story.AVOID)  # じてんしゃが　ない　あいだ　とおれない　ゲート　など
for i, s in enumerate(story.STEPS):
    if i < start: continue
    b.log(f'== STEP {i}', s)
    b.BAD.clear(); b.SEENOBJ.clear()  # とおれなかった　えだは　てじゅん　ごとに　わすれる
    if b.in_overworld() and not b.busy() and b.need_heal(): b.heal_nearest()
    if getattr(story, 'BOOST', None) and b.in_overworld() and b.party_hp() and not b.busy(): b.TEST_MOVES = getattr(story, 'TEST_MOVES', None); b.boost(story.BOOST)
    op, *a = s
    if op == 'map': ok = b.go_map(*a)
    elif op == 'talk': ok = b.talk(*a)
    elif op == 'xy':
        if b.bfs([tuple(a)]) is None: b.clear_obstacles()  # カードキーの　ドア　など
        if b.bfs([tuple(a)]) is None: b.go_tile(b.mapkey(), *a)
        ok = b.goto([tuple(a)])
    elif op == 'at': ok = b.talk_at(*a)
    elif op == 'press': [b.press(k, 2, 20) for k in a[0]]; b.handle_busy(); ok = True
    elif op == 'step': ok = all(b.step(d) for d in a[0]); b.handle_busy()
    elif op == 'grind': ok = b.grind(*a)
    elif op == 'heal': ok = b.heal(*a)
    elif op == 'tile': ok = b.go_tile(b.mapid[a[0]], a[1], a[2])
    elif op == 'fight': b.grinding = bool(a[0]); ok = True
    elif op == 'avoid': type(b).AVOID = tuple(a); ok = True
    elif op == 'unblock': b.BAD.clear(); b.TBLOCK.clear(); ok = True
    elif op == 'report': ok = b.report()
    elif op == 'clear': ok = b.clear_obstacles() or True
    elif op == 'flag': ok = bool(b.flag(a[0]))
    elif op == 'busy': b.handle_busy(); ok = True
    elif op == 'surf': b.surfing = a[0]; ok = True
    else: ok = getattr(story, op)(b, *a)
    b.save(f'{D}/step{i + 1:03d}.ss'); shutil.copy(f'{D}/cur.sav', f'{D}/step{i + 1:03d}.sav')
    b.log('   ->', ok, b.maps.get(b.mapkey(), {}).get('id') if b.in_overworld() else 'notfield', b.player()[:2], 'party', b.party_hp())
    if not ok: b.log('FAILED at', i); b.shot_now('FAIL'); break
try: b.cmd('quit')
except RuntimeError: pass
