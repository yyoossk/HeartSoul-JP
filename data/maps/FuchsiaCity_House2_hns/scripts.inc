FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "おじいちゃんは　サファリゾーンの\nえんちょう‥\pだったの‥\pりょこうに　いくと　いって\nひとりで　かいがいへ\lいっちゃった\pサファリゾーンも　あっさり\nやめちゃったの$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "サファリゾーンが　しまって\nがっかり　した　ひとも\lおおいけど　おじいちゃんは\lがんこ　だから‥$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "ポケモンに　かこまれて\nにっこり　わらう\lおじいさんの　しゃしんだ$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "めずらしい　ポケモンが\nあそぶ　ひろい　そうげんの\lしゃしんだ$"
