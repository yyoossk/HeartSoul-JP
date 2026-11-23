Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
	.string "なにか　かいてある\pよみますか？$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
	.string "きょうだいたちへ\pわたしたちは　トレーナーの\nやくに　たつことを\lほこりに　しています\pトレーナーに　はなしかけられたら\nやくに　たつ　ものを\lあげてね\pツキコより\pつづきを　よむ？$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
	.string "げつようび　ツキコ\n40ばんすいどう\pかようび　カヨ\n29ばんどうろ\pすいようび　スイ\nいかりのみずうみ\pもくようび　モク\n36ばんどうろ\pきんようび　キンコ\n32ばんどうろ\pどようび　ドヨウ\nフスベシティ\pにちようび　ニチ\n37ばんどうろ$"
