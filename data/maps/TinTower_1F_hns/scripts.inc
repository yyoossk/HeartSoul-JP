TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "いいつたえに　よると‥\nポケモンと　ひとの　こころが\pかよいあう　とき　てんから\nにじいろの　ポケモンが\lまいおりる‥\pでんせつの　ポケモンが　ひとを\nためして　いると　いうことか？$"

TinTower_1F_Sage2_Text:
	.string "カネのとうが　もえた　とき\nなもなき　3びきの　ポケモンが\lいのちを　おとしたと　いう\pいたましい　ことじゃ\pしかし‥\pにじいろの　ポケモン‥\nすなわち‥\pホウオウが　そらから　まいおり\n3びきに　あたらしい\lいのちを　あたえた\pそれが‥\nスイクン　エンテイ　ライコウ\pそう　いわれて　おる$"

TinTower_1F_Sage3_Text:
	.string "ふたつの　とうは　ポケモンと\nひとの　ゆうじょうと\pきぼうを　はぐくむ　ために\nたてられたと　いう\lそれは　700ねん　まえの　こと\pだが　その　ねがいは\nいまも　たいせつじゃ$"

TinTower_1F_Sage4_Text1:
	.string "ホウオウが　この　スズのとうに\nまいおりた　ようじゃ！$"

TinTower_1F_Sage4_Text2:
	.string "でんせつの　ポケモンは\n3つの　ちからを　あらわす\lと　いわれて　おる‥\pとうに　おちた　かみなり\nとうを　やいた　ほのお\pそして　ひを　けした　あめ‥$"

TinTower_1F_Sage6_Text2:
	.string "でんせつの　ポケモンの　なかで\nスイクンが　もっとも　ホウオウに\lちかいと　いわれて　おる\pアンノーンと　いう\nポケモンとも　かかわりが\lあるかも　しれん\pアンノーンは　スイクンと\nきょうりょく　しあって\lいるに　ちがいない$"

TinTower_1F_EusineHoOh_Text:
	.string "やっぱり\pきみなら　にじいろの\nポケモンに　あえると\lおもって　いたよ\pわたしの　よそう　どおりだ\nわたしの　けんきゅうも\lまんざら　じゃないな\pこれからも　ポケモンを\nけんきゅう　して\lゆうめいな　ポケモンマニアに\lなるぞ！$"

TinTower_1F_EusineSuicune_Text:
	.string "ミナキ『すごい！\nすごすぎる！\lこんな　しょうぶは\lはじめて　みた\pほんとうに　かんどう　した\nスイクンも　つよかったが\lきみは　もっと　すごかった\pスイクンの　ふしぎな　ちからは\nにじいろの　ポケモンを\lよぶと　きいた\pもしかしたら　きょうの\nできごとで　その　ポケモンが\lあらわれるかも　しれない\pでんせつを　もっと\nしらべて　みるよ\pすばらしい　しょうぶを\nありがとう\pまた　あおう！$"
