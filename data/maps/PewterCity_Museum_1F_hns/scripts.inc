PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "いらっしゃいませ！\pおおきな　てんじひんは\nほかの　はくぶつかんに\lかしだし　ちゅう　です\pですので　いまは\nにゅうかんりょうは　むりょう！\pどうぞ　おすすみ　ください$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "あなた　つよい\nトレーナー　みたいね\pあっちの　カウンターの　かせきは\nあまり　つかいみちが　ないの\pぎんいろの　かみの　へんな\nひとが　たくさん　おいて\lいったのよ\pよかったら　もって\nいって　いいわ$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "アルフのいせきの　けんきゅういんと\nよく　けんきゅうを\lきょうゆう　してるの\pパソコンで　かせきを\nおくりあう　ことも　あるのよ！$"

PewterCity_Museum_1F_Text_Oldman:
	.string "ながいき　した　ことに\nかんしゃ　せねばな\pドラゴンの　ほねが\nみられる　とは　おもわなんだ！$"

PewterCity_Museum_1F_Text_Bones:
	.string "こだいの　ドラゴンポケモンの\nほね$"
