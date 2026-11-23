EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "ほう　ポケモンと\nぼうけん　ちゅう　かね？\pぼうけんと　いえば\nたからさがし　だろう？\pそうだろう？\nそうだろう？$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "よし！　ぼうけんの\nこころを　わかってるな\pきにいった！\nこれを　もって　いきなさい$"

Ecruteak_Text_ItemfinderExplanation:
	.string "めに　みえない　どうぐが\nあちこちに　おちて　いる\pダウジングマシンで　ちかくに\nどうぐが　あるか　しらべられる\pばしょ　までは　わからないから\nじぶんで　さがすんだ\pそうそう　エンジュの　やけたとうに\nどうぐが　あるらしいぞ$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "そうか‥　ひとそれぞれ\nだな‥$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "エンジュは　とても　ふるい　まち\nいくつもの　せだいが　こういう\lほんで　れきしを　つたえて　きた$"

Ecruteak_Text_HistoryBook:
	.string "エンジュの　れきし\pよみますか？$"

Ecruteak_Text_TwoTowers:
	.string "エンジュには　ふたつの\nとうが　あった\pそれぞれの　とうには\nつよい　とりポケモンが\lすんで　いた\pしかし　かたほうの　とうは\nもえて　しまった\pそれいらい　2ひきの　ポケモンは\nすがたを　みせていない‥\pつづきを　よむ？$"

Ecruteak_Text_ThreeMon:
	.string "エンジュには　まちを　かけまわる\n3びきの　ポケモンも　いた\pみず　かみなり　ほのおから\nうまれたと　いわれている\pしかし　あふれる　ちからを\nおさえきれず\pかぜの　ように　そうげんへ\nかけさって　いったという$"
