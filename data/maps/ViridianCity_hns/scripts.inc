ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "オーキド$"

ViridianCity_Text_OakCall:
	.string "オーキド『おお　{PLAYER}くん！\pひまが　あったら　マサラタウンの\nわしの　けんきゅうじょに\lきて　おくれ$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "おい　ぼうず！　エスプレッソを\nダブルで　のんだら\lめが　さえて　しかたない！\pだれかと　はなしたいんじゃ\nおまえで　いい！\pいまは　こんなじゃが　むかしは\nポケモンを　つかまえる\lめいじん　だったんじゃ\pしんじるか？$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "うむ　うむ　わしは　ただもの\nじゃ　なかったんじゃぞ！$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "なに？　この　こぞうめ！\pもう　すこし　わかければ\nおもいしらせて　やるのに！\lふん！$"

ViridianCity_Text_GrampsNearGym:
	.string "この　ジムには　さいきんまで\nリーダーが　おらんかった\pマサラの　わかものが\nリーダーに　なったが\lよく　るすに　しておる$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "リーダーと　しょうぶ\nするのかい？\pがんばりな　ひつようだぞ$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "‥ぐうぐう‥\pふぁあ！\pひなたで　いねむり\nしちまったよ\pえ？　だれかに　にてる？\nしらないけど　これ　やるよ$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "‥ぐうぐう‥$"

ViridianCity_Text_DreamEaterFisher:
	.string "ふぁあ！\pひなたで　いねむり\nしちまったよ\p‥スリープに　ゆめを　くわれる\nゆめを　みたんだ　へんだろ？\pん？　なんだ　これ？\pどこから　きた\nわざマシンだ？\pきみが　わるい！　この\nわざマシン　やるよ$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "わざマシン42は　ゆめくい‥\p‥ぐうぐう‥$"

ViridianCity_Text_Youngster:
	.string "トキワのもりの　じめんには\nどうぐが　たくさん\lおちてるらしいよ$"

ViridianCity_Text_Sign:
	.string "トキワシティ\pトキワは　みどり\nえいえんの　いろ$"

ViridianCity_Text_GymSign:
	.string "トキワシティ　ポケモンジム\nジムリーダー　‥\pあとは　よめない‥$"

ViridianCity_Text_WelcomeSign:
	.string "ようこそ　トキワシティへ\pセキエイこうげんへの　いりぐち$"

ViridianCity_Text_TrainerHouseSign:
	.string "トレーナーハウス\pつよい　トレーナーが\nあつまる　クラブ$"
