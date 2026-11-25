# kanto_fix.py : ファイアレッドのカントーを　カントー＆ジョウト版に　あわせる　こまかい　なおし（何度実行しても同じ結果）
# - グレンジムのあと　マサキが　1のしまへ　さそう　ばめんを　なくす（ナナシマは　入れていない）
p = 'data/maps/CinnabarIsland_Gym_Frlg/scripts.inc'
s = open(p, encoding='utf-8').read()
old = '\tsetvar VAR_MAP_SCENE_CINNABAR_ISLAND, 1\n\tclearflag FLAG_KJ_HIDE_CINNABAR_BILL\n'
new = '\tsetvar VAR_MAP_SCENE_CINNABAR_ISLAND, 4 @ カントー＆ジョウト: ナナシマへは　いかない\n'
if old in s:
    s = s.replace(old, new); open(p, 'w', encoding='utf-8').write(s)
