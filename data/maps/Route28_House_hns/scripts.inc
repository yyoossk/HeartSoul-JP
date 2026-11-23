Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "あら　みつかっちゃった\pわたしの　ことは\nだれにも　いわないで\pないしょに　して　くれる\nおれいに　これを　あげる\lおねがい？$"

Route28House_Text_Celebrity2:
	.string "トップスターも　らくじゃ\nないの\pどこへ　いっても\nおいかけられて\pそっと　して\nおいて　ほしいのに‥$"

Route28House_Text_Fearow:
	.string "オニドリル『ドリィー！$"

