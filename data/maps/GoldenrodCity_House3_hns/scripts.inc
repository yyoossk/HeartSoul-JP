GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
	.string "しょうぶに　まけて　ばかりで\nポケモンが　たおれて　しまう‥\pだから　ポケモンに\nなつかれないのかなあ‥$"

GoldenrodHappinessRater_Text_Twin:
	.string "ポケモンに　どうぐを　つかうと\nすっごく　よろこぶの！$"
