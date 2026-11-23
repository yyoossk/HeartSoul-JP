PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "こんにちは！\pレッドは　ずっと\nるすに　してるの\pでんわも　くれないから\nどこで　なにを　しているか\lさっぱり　わからなくて\pたよりが　ないのは　げんきな\nしょうこ　って　いうけど\lやっぱり　しんぱいよ$"

RedsHouse_Text_Mom2:
	.string "けがや　びょうきが　しんぱい\nだけど　おとこのこ　だもの\pやりたい　ことを　やってるのは\nほこらしいわ$"

RedsHouse_Text_TV:
	.string "ジョウトでは　やってない\nばんぐみを　やってる‥$"
