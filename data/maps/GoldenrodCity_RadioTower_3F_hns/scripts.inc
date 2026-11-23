GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "カードキーを　さしこむ\nところが　ある$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER}は　カードキーを\nさしこんだ$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "シャッターが　あいた$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3F　じんじぶ$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "ポケモンミュージック　DJ　ベン$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "みつかっている　ポケモン\nぜんぶの　なきごえを\lろくおん　してるんだ\pたぶん　400しゅるいは\nあるね$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "トレーナーに　とって\nポケモンは　だいじな　あいぼう\pそれを　あやつろう　なんて\nロケットだんは　ひどい！$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "ここでは　24じかん\nたのしい　ばんぐみを\lながして　いるんだ\pぼくも　24じかん\nがんばるぞ！$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "ロケットだんの　ボスが\nへやに　とじこもって　いるの\pでも　きょくちょうなら\nあけられるわ\pきょくちょうは　5かいよ\pおねがい　たすけて！$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "きょくちょうは\nぶじかしら？$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "ありがとう！\nあなたは　わたしの　ヒーローよ！\pこれは　おれいの　しるし$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "それは　にほんばれ\pしばらく　ほのおタイプの\nわざが　つよく　なるのよ$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "あなた　ほんとうに\nすてきだったわ！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "きびしく　めいれい\nされている\pロケットだんに　さからう\nやつは　つぶせ　とな！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "なにっ！？$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "にんむに　しっぱい\nした‥\pアポロさまに\nおこられる‥$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "ポケモンに　わるい　ことを\nさせるのは　きもちいいぜ$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "うそだろ！$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "まけて　きぶんが　わるい！\pくそっ！　やくたたずの\nポケモンめ！$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "なぜ　シャッターが　あいた？\nおまえの　しわざか？$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "もう　だめだ！$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "なにっ！？　ちかつうろの\nなかまを　とっぱ　したのか？\pどうやって？$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "みしらぬ　こどもが\nなぜ　ここに？\pおまえは　だれだ？$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "ちっ！　あまく\nみすぎたか！$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "ぶわははは‥\pここからなら　いくらでも\nつよい　でんぱを　だせる$"

