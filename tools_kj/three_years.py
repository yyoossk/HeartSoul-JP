# three_years.py : 「カントークリアから3年後」に合わせたセリフ（ジョウトと、ジョウトのあとのカントー）
# サトシは3年前にロケット団を解散させたカントーのチャンピオン。カントーのジムリーダーはサトシを知っている
# （アンズは前にいなかったのでそのまま）。トキワのジムリーダーはカントーのライバル（{KANTO_RIVAL}）。
# 何度実行しても同じ結果。
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from settext import set_text
M = lambda m: f'data/maps/{m}/scripts.inc'

T = {
 # ---------------- ジョウト
 (M('VioletCity_PokemonCenter_hns'), 'VioletCity_PokeCenter_Text_Gentleman'): [
  '3ねんほど　まえの　ことだ\\p',
  'ロケットだんが　ポケモンを\\nつかって　わるさを　していた\\p',
  'だが　せいぎは　かった\\nひとりの　しょうねんが\\lやつらを　かいさん　させたんだ\\p',
  'ん？　きみの　かお‥\\nどこかで　みた　ような‥\\p',
  'まさか　カントーの　チャンピオン\\n{PLAYER}くん　かい！？$'],
 (M('SlowpokeWell_B1F_hns'), 'SlowpokeWell_B1F_Text_ProtonAfter'): [
  'そう　ロケットだんは\\n3ねんまえに　かいさん　した\\p',
  'おまえの　せいでな　{PLAYER}！\\p',
  'ボスは　すがたを\\nけした\\p',
  'だが　われわれは　うらで\\nかつどうを　つづけて　きた！\\p',
  'こんどは　おまえ　ひとりに\\nじゃま　される\\lわれわれでは　ないぞ\\p',
  'これから　おこる　ことを\\nせいぜい　おそれる\\lことだな！$'],
 (M('TohjoFalls_GiovanniRoom_hns'), 'TohjoFalls_GiovanniRoom_Text_GiovanniIntro'): [
  'サカキ『‥\\p',
  'おまえは‥　{PLAYER}！\\p',
  'まさか　また　おまえが\\nわたしの　まえに　たつとはな\\p',
  '3ねんまえ　わたしを　たおした\\nおまえの　その　め‥\\lすこしも　かわって　いないな\\p‥\\p',
  'わたしは　なかまの　よびかけに\\nこたえて　コガネシティへ\\lむかう　ところだ\\l',
  'じゃまを　する　つもりか？$'],
 (M('TohjoFalls_GiovanniRoom_hns'), 'TohjoFalls_GiovanniRoom_Text_GiovanniAfter'): [
  'サカキ『なぜだ‥？\\nこの　3ねんは\\lむだ　だったのか‥？\\p',
  'またしても　おまえに\\nゆめを　うちくだかれる　とは‥\\p',
  'ロケットだんの　だいじな　ゆめは\\nまぼろしに　すぎなく\\lなって　しまった‥$'],
 (M('SaffronCity_CopyCatsHouse_1F_hns'), 'CopycatsHouse1F_Text_PokefanF_ReturnedPart'): [
  '3ねんまえ　{PLAYER}くんに　もらった\\nポケモンにんぎょうを　さいきん\\lなくして　しまったの\\p',
  'それから　ものまねが\\nもっと　うまく　なって‥$'],
 # ---------------- カントーの　ジムリーダー（ジョウトの　あと）
 (M('PewterCity_Gym_hns'), 'PewterCity_Gym_Text_Brock_Intro'): [
  'タケシ『おお　{PLAYER}じゃないか！\\nひさしぶりだな！\\p',
  'ジョウトを　たびして\\nきたんだって？\\p',
  '3ねんまえ　おまえに　まけてから\\nおれも　ずっと　しゅぎょう\\lして　きたんだ\\p',
  'いわタイプの　かたい　まもり‥\\nもう　いちど　ためさせて\\lもらうぞ\\p',
  'さあ　こい！$'],
 (M('PewterCity_Gym_hns'), 'PewterCity_Gym_Text_Brock_WinLoss'): [
  'タケシ『やっぱり　つよいな\\n{PLAYER}‥\\p',
  'あの　ときより　ずっと\\nつよく　なってる\\p',
  'さあ　この　バッジを\\nうけとって　くれ$'],
 (M('CeruleanCity_Gym_hns'), 'CeruleanGym_Text_MistyIntro'): [
  'カスミ『あら　{PLAYER}じゃない！\\nまってたわよ！\\p',
  'ジョウトの　バッジも\\nたくさん　もってる　みたいね\\p',
  'でも　3ねんまえと　おなじだと\\nおもったら　おおまちがいよ！\\p',
  'わたしの　みずポケモンは\\nつよく　なったんだから！$'],
 (M('CeruleanCity_Gym_hns'), 'CeruleanGym_Text_GuideIntro'): [
  'よう！　チャンピオン！\\p',
  'カスミが　いないから　おれも\\nあそびに　いってたんだ\\pへへへ$'],
 (M('VermilionCity_Gym_hns'), 'VermilionGym_Text_LtSurgeIntro'): [
  'マチス『ヘイ　{PLAYER}！\\nひさしぶりだな　ボーイ！\\p',
  'カントーの　チャンピオンが\\nジョウトから　もどって　きたか！\\p',
  'でんきポケモンなら\\nミーが　ナンバーワン！\\p',
  '3ねんまえの　リベンジだ！\\nしびれさせて　やるぜ！$'],
 (M('CeladonCity_Gym_hns'), 'CeladonCity_Gym_Text_ErikaBeforeBattle'): [
  'エリカ『あら‥　{PLAYER}さん？\\p',
  'まあ　おひさしぶり\\nですわね‥\\p',
  'ジョウトから　もどって\\nいらしたの？　すてき‥\\p',
  'あれから　3ねん‥\\nわたくしも　くさポケモンも\\lせいちょう　しましたのよ\\p',
  'もう　いちど　おあいて\\nいただけますか？\\p',
  'まけませんわよ$'],
 (M('SaffronCity_Gym_hns'), 'SaffronCity_Gym_Text_SabrinaIntro'): [
  'ナツメ『あなたが　また\\nくるのは　わかっていた‥\\p',
  '3ねんぶりね　{PLAYER}\\p',
  'あの　とき　あなたに　まけてから\\nいまも　わたしの　よちは\\lあなたの　みらいを　よめないの\\p',
  'のぞむ　なら\\nもう　いちど　ちょうのうりょくを\\lみせて　あげる！$'],
 (M('SaffronCity_Gym_hns'), 'SaffronCity_Gym_Text_GymGuideIntro'): [
  'よう　チャンピオン！\\p',
  'きみほどの　うでなら\\nエスパータイプの　たいさくは\\lいわなくても　わかるよな？\\p',
  'きたい　してるぞ！\\pがんばれよ！$'],
 (M('SeafoamIslands_Gym_hns'), 'SeafoamIslands_Gym_Text_BlaineIntro'): [
  'カツラ『うおおーっ！\\n{PLAYER}では　ないか！\\p',
  'グレンの　ジムが\\nやけて　しもうた\\p',
  'かざんの　せいで　わしと\\nほのおポケモンは\\lいえなし　じゃ\\p',
  'じゃが　この　どうくつで\\nジムリーダーに\\lふっかつ　したぞ！\\p',
  '3ねんまえの　リベンジじゃ！\\p',
  'はっ！　やけどなおしを\\nよういして　おけい！$'],
 # ---------------- トキワの　ジムリーダー＝カントーの　ライバル
 (M('ViridianCity_Gym_hns'), 'ViridianCity_Gym_Text_BlueGotoDojo'): [
  '{KANTO_RIVAL}『もう　きたのか？\\p',
  'また　おれと　やりたいなら\\nかくとうどうじょうに　こい！$'],
 (M('ViridianCity_Gym_hns'), 'ViridianCity_Gym_Text_LeaderBlue_Before'): [
  '{KANTO_RIVAL}『よう　{PLAYER}！\\nやっと　きたな？\\p',
  'グレンでは　そんな　きぶんじゃ\\nなかったが\\p',
  'いまなら　あいて\\nしてやるぜ\\p‥\\p',
  'ジョウトの　ジムを\\nぜんぶ　せいは　した　だと？\\p',
  'へっ！　さすが\\nおれの　ライバルだぜ\\p',
  'だが　3ねんまえの　おれと\\nおなじだと　おもうなよ\\p',
  'じゅんびは　いいか？\\n{PLAYER}！$'],
 (M('ViridianCity_Gym_hns'), 'ViridianCity_Gym_Text_LeaderBlue_Win'): [
  '{KANTO_RIVAL}『なに？\\p',
  'なんで　また　おれが\\nおまえに　まけるんだ？\\p‥\\p',
  'ちっ　わかったよ‥\\nほら　グリーンバッジだ$'],
 (M('ViridianCity_Gym_hns'), 'ViridianCity_Gym_Text_LeaderBlue_After'): [
  '{KANTO_RIVAL}『‥\\p',
  'やっぱり　おまえは\\nつよいな　{PLAYER}\\p',
  'だが　いつか　かならず\\nおまえを　たおす\\p',
  'わすれるなよ！$'],
 (M('ViridianCity_Gym_hns'), 'ViridianCity_Gym_Text_LeaderBlue_Epilogue'): [
  '{KANTO_RIVAL}『いいか\\p',
  'おれが　おまえを　たおすまで\\nまけるんじゃ　ねえぞ\\lわかったな？$'],
 (M('SaffronCity_FightingDojoVIP_hns'), 'SaffronCity_FightingDojoVIP_Text_Blue_Rematch'): [
  '{KANTO_RIVAL}『へえ　ジョウトの\\nチャンピオンにも　なったのか！\\p',
  'カントーと　ジョウト\\nりょうほうの　チャンピオン‥\\lたいした　もんだぜ\\p',
  'てかげんは　しないぞ\\p',
  'もう　いちど\\nしょうぶ　するか？$'],
 (M('SaffronCity_FightingDojoVIP_hns'), 'SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat'): [
  '{KANTO_RIVAL}『なに？\\p',
  'なんで　また　まけるんだ？$'],
 # ---------------- 3ねんまえの　してんのう（ワタル・シバ）と　キョウ
 (M('LakeOfRage_hns'), 'LakeOfRage_Text_LanceIntro1'): [
  'きみも　うわさを　ききつけて\\nきたのか？\\p‥\\p',
  'きみは　{PLAYER}くん！\\nおぼえて　いるかい？\\lワタルだ\\p',
  '3ねんまえ　セキエイこうげんで\\nきみに　まけた　してんのうさ$'],
 (M('LakeOfRage_hns'), 'LakeOfRage_Text_LanceIntro3'): [
  '{PLAYER}くん　さっきの\\nたたかいかた　みせて\\lもらったよ\\p',
  'あの　ときより　さらに\\nつよく　なったね\\p',
  'よければ　ちょうさを\\nてつだって　くれないか？$'],
 (M('PokemonLeague_BrunosRoom_hns'), 'PokemonLeague_BrunosRoom_Text_Before'): [
  'おれは　してんのうの　シバ！\\p',
  'む？　おまえは　{PLAYER}！\\p',
  '3ねんまえ　おれを　たおした\\nあの　トレーナーか！\\p',
  'あれから　おれは\\nさらに　げんかいまで\\lきたえて　きた\\p',
  'こんどこそ　おれたちの\\nちからに　ひれふすが　いい！\\p',
  'いくぞ　{PLAYER}！\\pウー　ハーッ！$'],
 (M('PokemonLeague_KogasRoom_hns'), 'PokemonLeague_KogasRoom_Text_Before'): [
  'ファファファ！\\p',
  'せっしゃ　してんのうの\\nキョウ！\\p',
  'かつては　セキチクの\\nジムリーダー　だった　おとこ‥\\p',
  'そなた　{PLAYER}で　ござるな\\p',
  '3ねんまえの　せっしゃとは\\nちがう　ところを\\lみせて　しんぜよう！\\p',
  'こんらん　ねむり　どく‥\\nせっしゃの　わなに\\lかかるが　よい！\\p',
  'ファファファ！$'],
 (M('PokemonLeague_ChampionsRoom_hns'), 'PokemonLeague_ChampionsRoom_Text_BattleIntro'): [
  'ワタル『まって　いたよ\\p',
  '{PLAYER}くん！\\p',
  '3ねんまえ　カントーの\\nチャンピオンに　なった　きみなら\\lここまで　くると\\lおもって　いた\\p',
  'もう　ことばは\\nいらない\\p',
  'どちらが　つよいか\\nたたかって　きめよう\\p',
  'ドラゴンつかい　ワタル\\nきみの　ちょうせんを　うけよう！$'],
 # ---------------- マサラタウン（ジョウトの　あと）：レッドの　いえ＝サトシの　いえ
 (M('PalletTown_RedsHouse_1F_hns'), 'RedsHouse_Text_Mom1'): [
  '{PLAYER}！　おかえりなさい！\\p',
  'ジョウトに　いってたん\\nですって？\\p',
  'でんわも　くれないから\\nどこで　なにを　しているか\\lさっぱり　わからなくて\\p',
  'たよりが　ないのは　げんきな\\nしょうこ　って　いうけど\\lやっぱり　しんぱいよ\\p',
  'でも　げんきそうで\\nあんしん　したわ$'],
 (M('PalletTown_RedsHouse_1F_hns'), 'RedsHouse_Text_Mom2'): [
  'けがや　びょうきが　しんぱい\\nだけど　おとこのこ　だもの\\p',
  'やりたい　ことを　やってるのは\\nほこらしいわ\\p',
  'ヒビキくんの　おかあさんにも\\nよろしくね！$'],
 (M('PalletTown_hns'), 'PalletTown_Text_RedsHouseSign'): ['{PLAYER}の　いえ$'],
 (M('PalletTown_Lab_hns'), 'PalletTown_Lab_Text_OakWelcomeKanto'): [
  'オーキド『おお　{PLAYER}！\\nジョウトから　かえって\\lきたのか！\\p',
  '3ねんぶりの　カントーは\\nどうじゃ？\\p',
  'ジムリーダーたちも\\nきみに　あいたがって　おったぞ$'],
 (M('PalletTown_Lab_hns'), 'PalletTown_Lab_Text_OakOpenMtSilver'): [
  'オーキド『なんと！　すばらしい！\\p',
  'カントーと　ジョウトの\\nジムバッジを　16こ\\lそろえたのか　みごとじゃ！\\p',
  'わしの　みこんだ　とおりじゃった\\p',
  'よし　{PLAYER}　シロガネやまへ\\nいけるように　てはいして\\lおこう\\p',
  'シロガネやまは　やせいの\\nポケモンが　たくさん　すむ\\lおおきな　やまじゃ\\p',
  'ふつうの　トレーナーには\\nきけん　なので　たちいり\\lきんしじゃが　きみは\\lとくべつじゃ\\p',
  'セキエイこうげんへ　いきなさい\\nそこから　シロガネやまへ\\lいけるぞ$'],
 (M('PalletTown_hns'), 'PalletTown_Text_BluesHouseSign'): ['{KANTO_RIVAL}の　いえ$'],
}

CINNABAR_OLD = ('だれだ　おまえ？\\pまあ　みれば　トレーナーだって\\nことは　わかるけどな‥\\pおれの　なまえは　グリーン\\p'
                'いちどは　チャンピオンに\\nなった　おとこさ　ほんの\\lわずかな　あいだ　だったけど‥\\p'
                'あの　レッドの　やつに\\nやられちまったからな‥\\pで　なんの　ようだ？\\nおれに　ちょうせん　でも\\lしにきたのか？\\p')
CINNABAR_NEW = ('{PLAYER}！？\\nひさしぶり　じゃねえか！\\p'
                'ジョウトに　いってたんだってな\\n3ねんぶり　か‥\\p'
                'おれは　いま　トキワの\\nジムリーダー　やってるぜ\\p'
                'で　なんの　ようだ？\\nおれに　ちょうせん　でも\\lしにきたのか？\\p')

KANTO_GYMS = ['PewterCity_Gym_hns', 'CeruleanCity_Gym_hns', 'VermilionCity_Gym_hns', 'CeladonCity_Gym_hns',
              'FuchsiaCity_Gym_hns', 'SaffronCity_Gym_hns', 'SeafoamIslands_Gym_hns', 'ViridianCity_Gym_hns']

def main():
    for (p, lab), text in T.items():
        set_text(p, lab, text)
    # グレンじまの　ライバル（2か所の　セリフの　はじめ）
    p = M('CinnabarIsland_hns'); s = open(p, encoding='utf-8').read()
    # 文字列は　\n などで　分かれて　いないので　そのまま　おきかえ
    s = s.replace(CINNABAR_OLD, CINNABAR_NEW)
    open(p, 'w', encoding='utf-8').write(s)
    # カントーの　ジムの　ぞう：かった　トレーナー　（レッドは　サトシ　なので　いない）
    for g in KANTO_GYMS:
        p = M(g); s = open(p, encoding='utf-8').read()
        s = s.replace('かった　トレーナー\\nグリーン　レッド　{PLAYER}', 'かった　トレーナー\\n{KANTO_RIVAL}　{PLAYER}')
        s = s.replace('リーダー　グリーン\\pかった　トレーナー\\nグリーン　レッド　{PLAYER}', 'リーダー　{KANTO_RIVAL}\\pかった　トレーナー\\n{PLAYER}')
        s = s.replace('リーダー　グリーン\\pかった　トレーナー\\nグリーン　レッド$', 'リーダー　{KANTO_RIVAL}\\pかった　トレーナー\\nまだ　いない$')
        s = s.replace('リーダー　グリーン\\pかった　トレーナー\\n{KANTO_RIVAL}　{PLAYER}', 'リーダー　{KANTO_RIVAL}\\pかった　トレーナー\\n{PLAYER}')
        if g != 'ViridianCity_Gym_hns':
            s = s.replace('かった　トレーナー\\nグリーン　レッド$', 'かった　トレーナー\\n{KANTO_RIVAL}　{PLAYER}$')
        open(p, 'w', encoding='utf-8').write(s)

if __name__ == '__main__':
    main()
