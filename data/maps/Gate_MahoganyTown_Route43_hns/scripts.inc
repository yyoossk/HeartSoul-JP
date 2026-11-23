Gate_MahoganyTown_Route43_hns_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
	.string "さいきん　ここを　とおるのは\nいかりのみずうみへ\lいく　ひと　ばかりだ$"

Route43MahoganyGate_Text_Officer_RocketsCleared:
	.string "さいきんは　いかりのみずうみに\nいく　ひとは　いないな$"

