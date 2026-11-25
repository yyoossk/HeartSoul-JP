# FRLG のマップのうち、カントー編（マサラ〜殿堂入り）で使うものを選ぶ
import json, re, sys
EXCLUDE = re.compile(r'(One|Two|Three|Four|Five|Six|Seven)Island|NavelRock|BirthIsland|TrainerTower|'
                     r'AlteringCave|Tanoby|PatternBush|DottedHole|LostCave|'
                     r'BerryForest|BondBridge|CapeBrink|TreasureBeach|KindleRoad|MtEmber|IcefallCave|RuinValley|'
                     r'WaterLabyrinth|ResortGorgeous|WaterPath|GreenPath|OutcastIsland|SevaultCanyon|TrainerTower|'
                     r'MemorialPillar|FiveIsle|Meadow|Warehouse|RocketWarehouse|MonEan|Liptoo|Weepth|Dilford|Scufib|Rixy|Viapois|'
                     r'Colosseum|TradeCenter|RecordCorner|UnionRoom|DesertResort|PokemonTower_DUMMY')
def kanto_maps():
    g = json.load(open('data/maps/map_groups.json'))
    out = []
    for k in g['group_order']:
        if 'Frlg' not in k or k == 'gMapGroup_Link_Frlg': continue
        for m in g[k]:
            if not EXCLUDE.search(m): out.append(m)
    return out
if __name__ == '__main__':
    ms = kanto_maps()
    print(len(ms)); print('\n'.join(ms) if '-v' in sys.argv else '')
