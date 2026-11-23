GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
	.string "こんにちは\nあら　あなたの　ポケモン‥$"

GoldenrodDeptStore_Text_5FReceptionistWait:
	.string "あら　その　わざマシンは\nもう　あげたわよ！$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "うーん‥\nわるくは　ないけど\lよくも　ないわね\pトレーナーの　あなたが\nもっと　がんばらなきゃ$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
	.string "あなたに　とても\nなついて　いるわ\pこの　わざは　あなたたちに\nぴったりよ$"

GoldenrodDeptStore_Text_5FLass:
	.string "ひるまに　ポケモンを　みて\nくれる　おねえさんが\lくるの\pわざマシンも\nくれるのよ！$"

GoldenrodDeptStore_Text_5FPokefanM:
	.string "こうかんで　もらった\nポケモンの　なまえは\lかえられない\pなまえには　おやの\nおもいが　こもって\lいるからね$"

GoldenrodDeptStore_Text_Girl:
	.string "おねえさんに　おんがえしを\nもらったの！\pわたしの　ポケモン\nなついてるのね！$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
	.string "ポケモンを　カスタマイズ\p5F　わざマシンコーナー$"
