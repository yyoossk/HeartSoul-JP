import re,sys,json;sys.path.insert(0,'/home/claude/work');import cstr
N=json.load(open('/home/claude/work/names.json'));SP=dict(N['species']);SP.update(json.load(open('/home/claude/work/extra_sp.json'))['species']);SP.update(json.load(open('/home/claude/work/extra.json'))['species'])
MV=dict(N['moves']);MV.update(json.load(open('/home/claude/work/extra_mv.json'))['moves'])
TY={'Normal':'ノーマル','Fire':'ほのお','Water':'みず','Electric':'でんき','Grass':'くさ','Ice':'こおり','Fighting':'かくとう','Poison':'どく','Ground':'じめん','Flying':'ひこう','Psychic':'エスパー','Bug':'むし','Rock':'いわ','Ghost':'ゴースト','Dragon':'ドラゴン','Dark':'あく','Steel':'はがね','Fairy':'フェアリー','Elec-\\ntric':'でんき','Fight-\\ning':'かくとう','Psy\\nchic':'エスパー'}
def sp(x):
    x=x.upper().replace('\\N','').replace('-','')
    return SP.get(x) or SP.get(x.replace(' ',''))
def gen(s):
    m=re.match(r"This stone enables\\n(.*?) to Mega\\n(?:Evolve )?in battle\.$",s)
    if m and sp(m.group(1)): return '%sを　バトルちゅうに\\nメガシンカ　させる\\nふしぎな　いし'%sp(m.group(1))
    m=re.match(r"A tablet that ups\\nthe power of(?:\\n| )(.*?)-type moves\.$",s.replace('\\nFire','\\nFire'))
    if m:
        t=m.group(1).replace('\\n','\\n')
        for k,v in TY.items():
            if t==k or t.replace('\\n','')==k.replace('\\n','').replace('-',''): return 'もたせると\\n%sわざの\\nいりょくが　あがる'%v
    m=re.match(r"(?:A d|D)isc with (\w+)\\ntype data\. It swaps\\nSilvally's type\.$",s)
    if m: return '%sの　データが\\nはいった　ディスク\\nシルヴァディの　タイプが　かわる'%TY[m.group(1)]
    m=re.match(r"Increases the\\npower of (\w+)\\nType moves\.$",s)
    if m: return 'もたせると\\n%sわざの\\nいりょくが　あがる'%TY[m.group(1)]
    m=re.match(r"Upgrade (\w+)-\\ntype moves into\\nZ-Moves\.$",s)
    if m: return '%sわざを\\nZワザに　する'%TY[m.group(1)]
    m=re.match(r"A (\w+)-print\\nMail to be held by\\na Pokémon\.$",s)
    if m and sp(m.group(1)): return '%sの　がらの\\nメール\\nポケモンに　もたせる'%sp(m.group(1))
    m=re.match(r"Changes Genesect's\\nTechno Blast to\\n(\w+)-type\.$",s)
    if m: return 'ゲノセクトの\\nテクノバスターが\\n%sタイプに　なる'%TY[m.group(1)]
    m=re.match(r"A (\w+) Gem\. Ups\\nthe power of a\\n\w+-type move once\.$",s) or re.match(r"A gem with an essence of\\n(\w+)\.",s)
    m=re.match(r"(?:A|An) (\w+)-type\\ngem\. (?:It )?ups the\\npower of .*?$",s)
    if m and m.group(1) in TY: return '%sタイプの\\nジュエル　1かいだけ\\nわざの　いりょくアップ'%TY[m.group(1)]
    return None
BER={'Razz':'ズリ','Bluk':'ブリー','Nanab':'ナナ','Wepear':'セシナ','Pinap':'パイル','Cornn':'モコシ','Magost':'ゴス','Rabuta':'ラブタ','Nomel':'ノメル','Spelon':'ノワキ','Pamtre':'シーヤ','Watmel':'カイス','Durin':'ドリ','Belue':'ベリブ'}
ST={'HP':'HP','Attack':'こうげき','Defense':'ぼうぎょ','Sp. Atk':'とくこう','Sp. Def':'とくぼう','Speed':'すばやさ'}
def gen2(s):
    m=re.match(r"\{POKEBLOCK\} ingredient\.\\nPlant in loamy soil\\nto grow (\w+)\.$",s)
    if m: return '{POKEBLOCK}の　ざいりょう\\nうえると　%sのみが\\nそだつ'%BER[m.group(1)]
    if s=="{POKEBLOCK} ingredient.\\nPlant in loamy soil\\nto grow a mystery.": return '{POKEBLOCK}の　ざいりょう\\nうえると　なにが\\nそだつかは　なぞ'
    m=re.match(r"Makes a Pokémon\\nfriendly but lowers\\nbase (.*?)\.$",s)
    if m: return 'ポケモンが　なつくが\\n%sの　きそポイントが\\nさがる'%ST[m.group(1)]
    m=re.match(r"A hold item that\\nweakens a (\w+)\\nmove(?: if weak to it)?\.$",s)
    if m: return 'ばつぐんの　%sわざの\\nダメージを　へらす\\nきのみ'%TY[m.group(1)] if m.group(1)!='Normal' else 'ノーマルわざの\\nダメージを　へらす\\nきのみ'
    m=re.match(r"A hold item that\\nraises (.*?) in\\na pinch\.$",s)
    if m: return 'ピンチの　とき\\n%sが\\nあがる　きのみ'%ST[m.group(1)]
    return None
