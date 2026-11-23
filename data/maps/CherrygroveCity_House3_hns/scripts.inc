CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "ポケモンは　しょうぶで　けいけんを\nつんで　すがたを　かえるんだ$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "ポケモンが　かわる？\pそんなの　みたら\nびっくり　しちゃう！$"
