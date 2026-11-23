GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "ランス『ちょっと　まちな！\pおまえ　ヤドンのいどで\nじゃまを　した　やつだな？\pなるほど‥　わたしを\nおこらせたくて　こんな\lことを　しているのか\lきを　つけたまえ！\pのぞみ　どおり　ロケットだん\nかんぶの　いかりを\lみせて　あげよう！$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "ふう‥$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "ランス『こんかいは　まけたが‥\nおまえは　ロケットだんの\pいかりを　ふくらませた\nだけだ$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "いせきで　ラジオを\nきいて　いたら\pへんな　ほうそうが\nきこえたんだ$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "クルミ『なんで？　なんで\nこんな　めに　あうの？\pニャース　たすけて！$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "クルミ『わあ！　あなたが\nたすけて　くれたのね！\pおれいに　これ\nうけとって？$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "クルミ『あいての　こうげきを\nよけるのに　やくだつのよ$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "クルミ『オーキドはかせの\nポケモンこうざ　きいてね！$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "ニャース『ニャース‥$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "きょくちょうを　たすける\nつもりか？\pむりだな　おれが\nおまえを　たおすからな！$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "そんな！　しんじられん！$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "しんじられない！\nおれが　まけた！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "とまれ！　おれは\nロケットだんの　ようさいと\lよばれる　おとこ！\pここから　さきへは\nいっぽも　とおさん！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "ようさいが　くずれた！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "みとめて　やる\nだから　ちゅうこくだ\pまだ　まにあう\nひきかえすんだな$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "ポケモンが　かわいいか\nですって？\pわたしの　ポケモンが\nあんたのを　たおしたら‥\pかわいいと　おもって\nあげるわ！$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "いやー！\nほんと　やくたたず！$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "うつくしい　わたしが\nだいすき！\pポケモン　なんて\nどうでも　いいわ$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "すばらしい\pこの　ラジオとうで\nわれらの　けいかくが\lじつげん　する$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "ふむ‥\pおおきな　けいかくには\nじゃまが　つきものか$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "ほんとうに　ロケットだんを\nとめられると　おもって\lいるのか？$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4F　せいさくぶ$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4F　だい2スタジオ$"
