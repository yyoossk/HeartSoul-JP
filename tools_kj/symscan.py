# FRLG のスクリプトで使う定数のうち、hns ビルドで定義されていないものを調べる
import re, subprocess, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import kanto_maps as K
CPP = ['arm-none-eabi-cpp','-iquote','include','-Wno-trigraphs','-DMODERN=1','-DTESTING=0','-DPOKEMON_HNS','-std=gnu17','-I','include','-dM','-']
def hns_macros(extra_headers=()):
    hdr = ''.join(l for l in open('data/event_scripts.s') if l.startswith('#include'))
    hdr += ''.join(f'#include "{h}"\n' for h in extra_headers)
    out = subprocess.run(CPP, input=hdr, capture_output=True, text=True).stdout
    return set(re.findall(r'#define (\w+)', out))
COMMON = ['data/scripts/item_ball_scripts_frlg.inc','data/scripts/silphco_doors.inc','data/scripts/static_pokemon.inc',
          'data/scripts/aide.inc','data/scripts/pokemon_mansion.inc','data/scripts/pokemon_league.inc','data/scripts/route23.inc',
          'data/scripts/flavor_text.inc','data/scripts/trainers_frlg.inc','data/text/trainers_frlg.inc','data/text/ingame_trade_frlg.inc',
          'data/scripts/day_care_frlg.inc','data/text/day_care_frlg.inc','data/scripts/pkmn_center_nurse_frlg.inc',
          'data/scripts/fame_checker_frlg.inc','data/text/fame_checker_frlg.inc','data/scripts/move_tutors_frlg.inc',
          'data/scripts/cable_club_frlg.inc','data/scripts/mystery_event_club.inc','data/scripts/seagallop.inc',
          'data/scripts/trainer_card_frlg.inc','data/text/trainer_card_frlg.inc']
def files():
    return [f'data/maps/{m}/scripts.inc' for m in K.kanto_maps()] + COMMON
if __name__ == '__main__':
    macros = hns_macros()
    used = {}
    for f in files():
        for w in re.findall(r'\b([A-Z][A-Z0-9_]{3,})\b', open(f).read()):
            used.setdefault(w, f)
    pre = {}
    for w in used:
        if w in macros: continue
        p = w.split('_')[0]
        pre.setdefault(p, []).append(w)
    for p, ws in sorted(pre.items(), key=lambda x: -len(x[1])):
        print(p, len(ws), ' '.join(sorted(ws)[:12]))
