CeladonCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FRUSTRATION, CeladonDeptStore5_EventScript_Receptionist_Already
	msgbox CeladonDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, FRIENDSHIP_50_TO_99, CeladonDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	msgbox CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_Already::
	msgbox CeladonDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore_Text_5FReceptionistOhYourMon:
	.string "こんにちは\nあら　あなたの　ポケモン‥$"

CeladonDeptStore_Text_5FReceptionistWait:
	.string "あら　その　わざマシンは\nもう　あげたわよ！$"

CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "うーん‥\nわるくは　ないけど\lよくも　ないわね\pトレーナーの　あなたが\nもっと　がんばらなきゃ$"

CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
	.string "わるそうな　かおね\nこの　わざマシンは　どう？$"

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}　こんな　ところで\nあうとは　おもわなかった\pとりポケモンの　どうぐを\nかいに　きたんだ\pまた　たたかいたいなら\nヤマブキシティの\lどうじょうに　いるよ$"

CeladonDeptStore5F_Text_Gentleman:
	.string "ポケモンの　のうりょくを\nあげる　どうぐが　ほしいが\lおかねが　たりない‥$"

CeladonDeptStore5F_Text_Sailor:
	.string "わざの　PPを　ふやせる\nポイントアップが　ほしい\lでも　うってないんだ‥$"

CeladonDeptStore5F_Text_Teacher:
	.string "どうぐを　つかって　あげると\nポケモンは　よろこぶの\pでも　きらいな　どうぐも\nあるのよね‥$"

CeladonDeptStore5F_Text_Directory:
	.string "5F　くすりやさん$"
