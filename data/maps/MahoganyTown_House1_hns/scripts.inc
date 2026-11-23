MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
	.string "みずうみに　あかい　ギャラドスが\nでたって　きいたぞ\pへんだな　ふつうの\nギャラドスでさえ　あそこでは\lめずらしいのに‥$"

MahoganyRedGyaradosHouse_Text_Teacher:
	.string "すきな　ばんぐみ？\nポケモンミュージック　かしら$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
	.string "ラジオから　わらいごえが\nきこえて　くるの‥\pきみが　わるいわ$"
