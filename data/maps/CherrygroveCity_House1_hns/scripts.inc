CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "ポケモントレーナーとしての\nじつりょくを　ためしたいのか？\pだったら　ジョウトの\nポケモンジムを　まわって\lバッジを　あつめるといい$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "おおきく　なったら\nジムリーダーに　なるんだ！\pともだちの　ポケモンと\nたたかわせて　きたえてるんだ！$"
