GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "したの　かいで　しょうぶを\nしかけられたんだ\pあそこは　あらっぽいから\nきを　つけた　ほうが　いいよ$"


GoldenrodUnderground1_Text_Teacher:
	.string "したの　かいには　おみせが\nあるけど‥　トレーナーも　いるの\pこわくて　いけないわ$"
