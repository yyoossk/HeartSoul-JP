Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "みずに　はいる　まえは\nじゅんびうんどう！\pきほん　だぜ$"

Route40_Text_SwimmermSimonBeaten:
	.string "わかった！　まいった！$"

Route40_Text_SwimmermSimonAfter:
	.string "タンバシティは　ここから\nけっこう　とおいぜ$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "おい　わかくて　げんきだろ！\pポケモンに　のるな！\nおよげ！$"

Route40_Text_SwimmermRandallBeaten:
	.string "あちゃあ　まけた‥$"

Route40_Text_SwimmermRandallAfter:
	.string "すいえいは　ぜんしんうんどう\nけんこうに　いいぞ$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "タンバに　いくの？\pそのまえに　ちょっと\nしょうぶ　しない？$"

Route40_Text_SwimmerfElaineBeaten:
	.string "まけちゃった！$"

Route40_Text_SwimmerfElaineAfter:
	.string "およぎなら　わたしの\nほうが　うまいわ　うん！$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "うきわは　つかわないの\pうみの　ポケモンに\nつかまってるのよ！$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "ああ　めが　まわる！$"

Route40_Text_SwimmerfPaulaAfter:
	.string "こうして　うかんでると\nなみが　はこんで　くれるの$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "ここからは　みえないけど\nうみの　むこうに　タンバが\lあるのよ$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "けしきと　ふんいきを\nたのしみに　ふねで\lアサギに　きたの\pみなとまちって　だいとかいとは\nぜんぜん　ちがう　かんじね$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "トレーナーヒルには\nいった？\pつよい　トレーナーが　もう\nたくさん　あつまってるみたい\pでも　そんなに　バッジを\nもってるなら　だいじょうぶだよ$"

Route40_Text_Monica:
	.string "ツキコ『はじめまして\nようび　きょうだいの\lツキコです\pわたしの　すきな　ようび\nあてられないでしょ！$"

Route40_Text_MonicaGivesGift:
	.string "せいかい！\pおちかづきの　しるしに\nプレゼントが　あるの！$"

Route40_Text_MonicaGaveGift:
	.string "ツキコ『ひこうタイプの　わざを\nつよく　する　どうぐよ\pとりポケモンに　もたせると\nいいわ$"

Route40_Text_MonicaMonday:
	.string "ツキコ『きょうだいは　あちこちに\nいるの\pぜんいん　さがせるかしら！$"

Route40_Text_MonicaNotMonday:
	.string "ツキコ『きょうは　げつようびじゃ\nないみたい　ざんねん‥$"

Route40_Text_MonicaNope:
	.string "それじゃ　ないわ$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
