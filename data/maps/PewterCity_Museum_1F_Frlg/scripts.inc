PewterCity_Museum_1F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself
	release
	end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	goto_if_eq VAR_RESULT, NO, PewterCity_Museum_1F_EventScript_ExplainAmber
	end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_ExplainAmber::
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
	call_if_eq VAR_TEMP_1, 1, PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_KJ_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_KJ_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked
	release
	end

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	lockall
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	lockall
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
	.string "　けÜぬくア　　ヒいた\n"
	.string "ててひり\n"
	.string "てひり\n"
	.string "ひり\n"
	.string "そ　göぬくけいいそ　aäぬくけいいハコろセいかあレÜぬくそ　\l"
	.string "äぬくけえばツああ　むすィ　　かあミÜぬくるセいウえ　でツああ　そ　０öぬくは　ィツあはあィあ　はいィずあけけフいそ　Uöぬくけえフいそ　Aöぬくけえフいそ　せüぬくけいいノにえィズ　におィこ　にかィう　ゆゴあそ　ろüぬくけえゆザあヒいノにえィジ　におィこ　にかィう　ゆゴあそ　づüぬくけえゆザあヒいはいはい　こどもは　\n"
	.string "けんがくりょう　５０えん　です\p"
	.string "けんがく　しますか？$"

PewterCity_Museum_1F_Text_ComeAgain::
	.string "また　きてね$"

PewterCity_Museum_1F_Text_Right50YThankYou::
	.string "はい　たしかに\n"
	.string "５０えん　いただき　ました！$"

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
	.string "…あら\n"
	.string "おかねが　ないよ$"

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
	.string "ごゆっくり　どうぞ！$"

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
	.string "うらぐちから　タダで\n"
	.string "はいろうなんて\l"
	.string "ちゃっかりもの　だね\p"
	.string "それより　きみ\n"
	.string "コハクって　しってる？$"

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
	.string "コハクに　まじった\n"
	.string "むかしのいきものを　よみがえらせる\p"
	.string "そうだいな　じっけんを　どこかの\n"
	.string "けんきゅうじょが　してるんだって$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
	.string "おおむかし　きから　でた　しるが\n"
	.string "カセキのように　かたまった　ものを\p"
	.string "コハクと　いうんだよ$"

@ Unused
PewterCity_Museum_1F_Text_PleaseGoAround::
	.string "あちらへ　おまわりください$"

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
	.string "ありがたや！　ありがたや！\p"
	.string "りゅうじん　さまの\n"
	.string "ほねを　おがめる　とは！$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
	.string "しー！\n"
	.string "ないしょ　だけど　このコハク\p"
	.string "ポケモンの　いでんしが　のこってると\n"
	.string "おれは　にらんでるんだ！\p"
	.string "もし　いきかえらせたら\n"
	.string "ポケモンの　いちだい　はっけんだ！\p"
	.string "でも　ここの　なかまは\n"
	.string "おれの　いうこと　しんじないんだ\p"
	.string "……それで\n"
	.string "きみに　たのみが　ある！\p"
	.string "これを　どこかの\n"
	.string "けんきゅうじょに　もって　いって\p"
	.string "しらべて　ほしいんだ！$"

PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan::
	.string "{PLAYER}は　おじさんから\n"
	.string "ひみつのコハクを　もらった！$"

PewterCity_Museum_1F_Text_GetOldAmberChecked::
	.string "…しー！\n"
	.string "コハク　よろしく　たのむよ！$"

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
	.string "もちものが　いっぱいだ$"

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
	.string "ここでは　せかいでも　めずらしい\n"
	.string "こだい　ポケモンの　カセキのうち\p"
	.string "２しゅるいを　てんじ　してます！$"

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
	.string "こがねいろに　すき　とおった\n"
	.string "きれいな　コハクが　ある！$"

PewterCity_Museum_1F_Text_AerodactylFossil::
	.string "めずらしい　こだい　ポケモン\n"
	.string "プテラの　カセキ$"

PewterCity_Museum_1F_Text_KabutopsFossil::
	.string "めずらしい　こだい　ポケモン\n"
	.string "カブトプスの　カセキ$"

