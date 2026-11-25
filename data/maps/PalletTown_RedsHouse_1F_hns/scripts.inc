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
	.string "{PLAYER}！　おかえりなさい！\p"
	.string "ジョウトに　いってたん\nですって？\p"
	.string "でんわも　くれないから\nどこで　なにを　しているか\lさっぱり　わからなくて\p"
	.string "たよりが　ないのは　げんきな\nしょうこ　って　いうけど\lやっぱり　しんぱいよ\p"
	.string "でも　げんきそうで\nあんしん　したわ$"

RedsHouse_Text_Mom2:
	.string "けがや　びょうきが　しんぱい\nだけど　おとこのこ　だもの\p"
	.string "やりたい　ことを　やってるのは\nほこらしいわ\p"
	.string "ヒビキくんの　おかあさんにも\nよろしくね！$"

RedsHouse_Text_TV:
	.string "ジョウトでは　やってない\nばんぐみを　やってる‥$"
