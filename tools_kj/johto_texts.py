# johto_texts.py : ジョウト編（カントークリアから3年後）のセリフ
# サトシ（カントーのチャンピオン）が船でワカバタウンに来て、旅に出ている
# ヒビキの家に泊めてもらっている、という話に合わせる。何度実行しても同じ結果。
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from settext import set_text
M = 'data/maps/'
H1 = M + 'NewBarkTown_PlayersHouse_1F_hns/scripts.inc'
TW = M + 'NewBarkTown_hns/scripts.inc'
LAB = M + 'NewBarkTown_Lab_hns/scripts.inc'
MRP = M + 'Route30_MrPokemonsHouse_hns/scripts.inc'

T = {
 # ---- ヒビキの家（1かい）
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou'): [
  'あら　{PLAYER}くん　おはよう！\\nよく　ねむれた？\\p',
  'わたしは　ヒビキの　ははです\\nきのうは　ふねの　たびで\\lつかれて　いたものね\\p',
  'ヒビキは　いま　たびに　でてて\\nるすだから　あのこの　へやを\\lつかって　ちょうだいね\\p',
  'そうそう　となりの　ウツギはかせが\\nあなたを　まってるわよ\\p',
  'それと　これ！\\nヒビキの　おさがり　だけど\\lポケギアよ\\p',
  'ジョウトを　たびするなら\\nきっと　やくに　たつわ\\pはい　どうぞ！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear'): [
  'ヒビキのママ『でんわばんごうは\\nメモリーに　はいってるの\\p',
  'かけたい　ひとの　なまえを\\nえらぶだけ　わたしの　ばんごうも\\lいれて　おいたわよ\\p',
  'こまった　ときは\\nいつでも　でんわしてね！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting'): [
  'ヒビキのママ『ウツギはかせが\\nまってるわよ\\p',
  'けんきゅうじょは\\nすぐ　となりよ！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_MomsFriend'): [
  'こんにちは　{PLAYER}くん！\\p',
  'わたしは　となりの　いえの　もの\\nヒビキくんの　おかあさんと\\lおしゃべり　しに　きているの\\p',
  'きいた？\\nうちの　むすめ　どうしても\\lウツギはかせの　じょしゅに\\lなりたいって　いうの\\p',
  'ほんとうに　ポケモンが\\nすきなのね！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_MomLeaving'): [
  'ヒビキのママ『まあ　かわいい　ポケモン！\\nウツギはかせに　もらったの？\\p‥\\p',
  'そう　ジョウトを　たびするのね\\p',
  'うちの　ヒビキも\\n{PLAYER}くんと　おなじ　ころに\\lたびに　でたのよ\\p',
  'もし　どこかで　あったら\\nよろしくね！\\p',
  'さあ　いってらっしゃい！\\nいつでも　やすみに　きてね！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_KjMomRest'): [
  'ヒビキのママ『あら　{PLAYER}くん！\\nおかえりなさい\\p',
  'つかれたでしょう？\\nすこし　やすんで　いって！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes'): [
  'ヒビキのママ『{PLAYER}くん　これを\\nはいて　Bボタンを　おすと\\lはやく　はしれるわよ！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_DepositSuccess'): ['いいわよ！\\nちょきん　しておくわね$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_WithdrawSuccess'): ['はい　どうぞ！$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_NoMoneyToDeposit'): ['いまは　ちょきん　できる\\nおかねが　ないみたいね$'],
 (H1, 'NewBarkTown_PlayersHouse_1F_Text_NoMoneyToWithdraw'): ['まだ　ちょきんは\\nないわよ$'],
 # ---- ワカバタウン
 (TW, 'NewBarkTown_Text_FatManState2'): ['あれ？　その　ポケギア\\nヒビキの　じゃない？$'],
 (TW, 'NewBarkTown_Text_LassState2'): [
  'まって　{PLAYER}くん！\\p',
  'ウツギはかせが　あなたを\\nまってるわよ\\p',
  'でかける　まえに　けんきゅうじょに\\nよって　いってね！$'],
 (TW, 'NewBarkTown_Text_LassState4'): [
  'あら　{PLAYER}くん！　また　おでかけ？\\p',
  'でかける　ときは\\nヒビキの　おかあさんに\\lあいさつ　して　いきなさいね$'],
 (TW, 'NewBarkTown_Text_LassState5'): [
  'ヒビキの　おかあさん\\nさみしがってたわよ\\p',
  'ときどき　かおを　みせて\\nあげてね$'],
 (TW, 'NewBarkTown_Text_PlayersHouse'): ['ヒビキの　いえ$'],
 # ---- ウツギけんきゅうじょ
 (LAB, 'NewBarkTown_Lab_Text_ElmIntro'): [
  'ウツギ『やあ！　きみが\\n{PLAYER}くん　だね！\\p',
  'オーキドはかせから\\nはなしは　きいて　いるよ\\p',
  'カントーの　チャンピオンに\\nなった　トレーナー　だって！\\p',
  'じつは　きみに　たのみが\\nあったんだ\\p',
  'いま　あたらしい　ポケモンの\\nけんきゅうを　しているんだけど\\l{PLAYER}くんに　てつだって\\lもらえないかと　おもってね\\p',
  'がっかいで　はっぴょう\\nしたい　ろんぶんを\\lかいているんだ\\p',
  'でも　まだ　よく　わからない\\nところが　あってね\\p',
  'そこで！\\p',
  'さいきん　つかまえた　ポケモンを\\nきみに　そだてて　ほしいんだ$'],
 (LAB, 'NewBarkTown_Lab_Text_ElmChooseAPokemon'): [
  'この　ボールの　なかの　ポケモンを\\n1ぴき　そだてて　ほしいんだ\\p',
  '{PLAYER}くんの　ジョウトでの\\nあたらしい　パートナーさ！\\p',
  'さあ　えらんで！$'],
 (LAB, 'NewBarkTown_Lab_Text_ElmAfterTheft4'): [
  'でも‥　これって　ポケモンの\\nタマゴかな？\\p',
  'もし　そうなら\\nだいはっけんだ！\\p',
  'ウツギ『なに！？\\p',
  'オーキドはかせが　きみの\\nポケモンずかんを　ジョウトでも\\lつかえる　ように　してくれた！？\\p',
  'さすが　オーキドはかせだ！\\p',
  'カントーの　チャンピオンの\\nきみなら　ジョウトの　ジムも\\lきっと　のりこえられるよ\\p',
  'いちばん　ちかい　ジムは\\nキキョウシティだよ\\p',
  '‥{PLAYER}くん　ジョウトの\\nたびも　ながいよ\\p',
  'マサラタウンの　おかあさんにも\\nちゃんと　れんらく　しておいてね$'],
 (LAB, 'NewBarkTown_Lab_Text_AideExplainBalls'): [
  '{PLAYER}くんには\\nいうまでも　ないけど\\p',
  'ジョウトの　ポケモンも\\nどんどん　つかまえて\\lずかんに　とうろく　してね！$'],
 (LAB, 'NewBarkTown_Lab_Text_League'): [
  'ウツギ『あはは‥\\nよく　やったね！\\p',
  'あの　めずらしい　タマゴの\\nせいで　いろいろ　たいへん\\lだったね？\\p',
  'まいこはんたちが　わたしの\\nことを　なにか　いってた？\\p',
  'わたしは　なにも\\nしていないよ\\p',
  'きみが　じぶんで　きめて\\nやりとげたんだ\\p',
  'ここまで　やったなら\\nジョウトの　ポケモンリーグにも\\lちょうせん　できるはずだ！\\p',
  '3ねん　まえとは　ちがう\\nしてんのうが　セキエイこうげんで\\lまって　いるよ！\\p',
  'いきかたは　わかるかい？\\n27ばんどうろから　26ばんどうろへ\\p',
  'そこから　まっすぐ　きただよ！$'],
 (LAB, 'NewBarkTown_Lab_Text_ElmGiveTicket1'): [
  'ウツギ『{PLAYER}くん！\\nまってたよ！\\p',
  'ジョウトの　チャンピオン\\nおめでとう！\\p',
  'おいわいに　わたしたい\\nものが　あって　でんわ　したんだ\\p',
  'ほら　ふねのチケットだよ\\p',
  'これで　いつでも\\nカントーに　かえれるね$'],
 (LAB, 'NewBarkTown_Lab_Text_ElmGiveTicket2'): [
  'ふねは　アサギシティから\\nでているよ\\p',
  '3ねんぶりの　カントーは\\nきっと　すこし　かわって　いるよ\\p',
  'マサラタウンの　おかあさんと\\nオーキドはかせに\\lよろしく　つたえてね！$'],
 # ---- ポケモンじいさんの　いえ
 (MRP, 'MrPokemonHouse_Text_OakIntro'): [
  'オーキド『おお！　{PLAYER}！\\nぶじに　ジョウトに\\lついて　おったか！\\p',
  'わしも　ふるい　ともだちの\\nポケモンじいさんを\\lたずねて　きたのじゃ\\p',
  'ウツギくんの　つかいと　いうのは\\nきみの　ことじゃったか\\p',
  'おや！　これは\\nめずらしい　ポケモン！\\p',
  'どれどれ‥\\nふむ　なるほど！\\p',
  'ウツギくんが　きみに\\nこの　ポケモンを　たくした\\lわけが　わかったぞ\\p',
  '‥そうじゃ！\\p',
  'きみの　ポケモンずかんを\\nジョウトの　ポケモンも\\lきろく　できる　ように\\lして　あげよう\\p',
  'ほれ　かしてみなさい$'],
 (MRP, 'MrPokemonHouse_Text_GetDex'): [
  '{PLAYER}の　ポケモンずかんが\\nジョウトに　たいおう　した！$'],
}

def main():
    # 新しいラベル（ヒビキのママの「やすんでいって」）がなければ足す
    s = open(H1, encoding='utf-8').read()
    if 'NewBarkTown_PlayersHouse_1F_Text_KjMomRest:' not in s:
        s = s.rstrip('\n') + '\n\nNewBarkTown_PlayersHouse_1F_Text_KjMomRest:\n\t.string "x$"\n'
        s = s.replace('msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT',
                      'msgbox NewBarkTown_PlayersHouse_1F_Text_KjMomRest, MSGBOX_DEFAULT')
        # カントーで　ランニングシューズを　もらって　いたら　もう　わたさない
        s = s.replace('NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::\n',
                      'NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::\n'
                      '\tgoto_if_set FLAG_SYS_B_DASH, NewBarkTown_PlayersHouse_1F_EventScript_KjReturn\n')
        s += '\nNewBarkTown_PlayersHouse_1F_EventScript_KjReturn::\n\treturn\n'
        open(H1, 'w', encoding='utf-8').write(s)
    # ウツギはかせの　ふねのチケット：カントーで　もらった　チケットを　さきに　かいしゅう
    s = open(LAB, encoding='utf-8').read()
    old = '\tmsgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT\n\tgiveitem ITEM_SS_TICKET\n'
    if old in s:
        s = s.replace(old, '\tmsgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT\n'
                      '\tremoveitem ITEM_SS_TICKET\n\tgiveitem ITEM_SS_TICKET\n')
        open(LAB, 'w', encoding='utf-8').write(s)
    for (p, lab), text in T.items():
        set_text(p, lab, text)

if __name__ == '__main__':
    main()
