Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "この　みちを　きたへ　すすむと\nポケモンじいさんの　いえが\lあるよ\pでも　その　まえに　きのみの\nことを　おしえて　あげよう！\pポケモンは　きのみを　たべると\nげんきに　なるんだ\pもたせて　おけば　たたかいの\nなかで　じぶんで　たべるよ\pヒワダタウンの　ガンテツさんは\nきのみから　ボールを\lつくって　くれる\pほら　ひとつ\nわけて　あげよう！$"

Route30_BerryHouse_Text_CheckTrees:
	.string "きのみの　きを　しらべて　ごらん\nなんじかんか　すると\lまた　なるよ$"
