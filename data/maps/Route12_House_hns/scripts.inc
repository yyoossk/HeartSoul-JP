Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "わしは　つりの　めいじんの\nおとうとじゃ\pおまえさん　つりが\nすきじゃな\pまちがい　ない！\pな？　あたり　じゃろ？$"

Route12_House_Text_GiveSuperRod:
	.string "そうか　そうか\nやっぱり　そうじゃ！\pほれ　つりずき！\nこの　すごいつりざおを\lやろう$"

Route12_House_Text_GaveSuperRod:
	.string "みずの　ある　ところなら\nどこでも　つって　みい\pつりざおで　つれる\nポケモンが　ちがうのを\lわすれるなよ$"

Route12_House_Text_DontWantSuperRod:
	.string "なに？　わしの　めが\nくもっておったか？$"

