Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "はつでんしょの　じこを\nきいたかい？\pシオンタウンの　ちかく\nひがしに　あるんだ$"

Route7_Text_SaffronGuard_Serious:
	.string "けいびの　しごとは\nまじめに　やってるんだ\pおや！　ずかんを\nもってるね\pよし　とおって　いいよ$"
