OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "アサギは　うみの　まち！\pうみ　ならば\nさかなが　いる！\pわしは　ここで　30ねん\nつりを　しておる\pおまえさんも　うみに　むかって\nつりを　して　みんか？$"

OlivineCity_Text_GiveGoodRod:
	.string "わっはっは！\nあたらしい　つりびとの\lたんじょうじゃ！$"

OlivineCity_Text_GaveGoodRod:
	.string "さかなは　うみ　だけで　なく\nみずの　ある　ところなら\lどこにでも　おる\pところで　ずかんには　ポケモンの\nつりの　グループが　でておる\pばしょが　ちがっても　にた\nさかなが　つれる　ことが\lあるぞ$"

OlivineCity_Text_DontWantGoodRod:
	.string "なんじゃと？　つりが\nきらいじゃと！？\lしんじられん！$"

OlivineCity_Text_HaveGoodRod:
	.string "ちょうしは　どうじゃ？\nおおものは　つれたか？$"
