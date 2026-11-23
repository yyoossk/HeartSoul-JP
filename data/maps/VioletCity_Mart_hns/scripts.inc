VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "つかまえた　ばかりの\nポケモンは　よわい　かもしれん\pでも　いつかは\nつよく　そだつんじゃ\pポケモンを　あいじょうを　こめて\nあつかう　ことが　だいじじゃよ$"

VioletCity_Mart_Text_CooltrainerM:
	.string "ポケモンは　キズぐすりや\nどくけしを　もてるんだ\pでも　ひとが　つくった　どうぐの\nつかいかたは　しらない　みたいだね$"
