@ カントー＆ジョウト: ジョウトの　ひでんマシン（tools_kj/johto_hm.py で作成）

KJ_EventScript_GiveHM_CUT::
	checkitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave
	giveitem ITEM_HM_CUT
	return

KJ_EventScript_GiveHM_FLY::
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave
	giveitem ITEM_HM_FLY
	return

KJ_EventScript_GiveHM_SURF::
	checkitem ITEM_HM_SURF
	goto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave
	giveitem ITEM_HM_SURF
	return

KJ_EventScript_GiveHM_STRENGTH::
	checkitem ITEM_HM_STRENGTH
	goto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave
	giveitem ITEM_HM_STRENGTH
	return

KJ_EventScript_GiveHM_FLASH::
	checkitem ITEM_HM_FLASH
	goto_if_eq VAR_RESULT, TRUE, KJ_EventScript_HMAlreadyHave
	giveitem ITEM_HM_FLASH
	return

KJ_EventScript_HMAlreadyHave::
	msgbox KJ_Text_HMAlreadyHave
	setvar VAR_RESULT, TRUE
	return

KJ_Text_HMAlreadyHave::
	.string "{PLAYER}は　その　ひでんマシンを\n"
	.string "カントーで　もう　もらっていた！$"
