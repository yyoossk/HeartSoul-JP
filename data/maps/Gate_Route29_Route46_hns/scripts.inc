Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "だんさは　のぼれない\pでも　とびおりて\nちかみち　できるよ$"

Gate_Route29_Route46_Text_Youngster:
	.string "ここから　さきは　ちがう\nしゅるいの　ポケモンが　でる\pぜんぶ　つかまえたいなら\nあちこち　さがさないとね$"
