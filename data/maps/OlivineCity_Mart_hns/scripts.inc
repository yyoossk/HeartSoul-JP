OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "あなたの　ポケモン　ひとを\nのせて　みずを　わたる\lわざを　もう　おぼえてる？$"

OlivineCity_Text_MartLass:
	.string "わたしの　バタフリーは\nうみの　むこうの　かれから\lきたの\pかれからの　メールを\nもって　きたのよ\pなんて　かいてあるか\nしりたい？\pえーと‥　ないしょ！$"
