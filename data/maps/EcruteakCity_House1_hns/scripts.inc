EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "わしが　わかい　ころの\nはなしじゃ\pそらが　とつぜん　まっくらに\nなった　きょだいな　とりの\lポケモンが　たいようを\lさえぎって　いたのじゃ\pあれは　なんと　いう\nポケモン　だったのかのう？\pとりの　ようで　りゅうの\nようでも　あった$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "そんなに　おおきな\nポケモンが　ほんとうに　いるの？\pいるなら　きっと\nすごく　つよいんだろうな$"
