.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad_Kj
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition_Kj
	.byte 0

VermilionCity_Gym_OnLoad_Kj::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff_Kj
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff_Kj
	end

VermilionCity_Gym_EventScript_SetOneBeamOff_Kj::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff_Kj::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition_Kj::
	call VermilionCity_Gym_EventScript_InitTrashCans_Kj
	end

VermilionCity_Gym_EventScript_InitTrashCans_Kj::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_TrashCan1_Kj::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan2_Kj::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan3_Kj::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan4_Kj::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan5_Kj::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan6_Kj::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan7_Kj::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan8_Kj::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan9_Kj::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan10_Kj::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan11_Kj::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan12_Kj::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan13_Kj::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan14_Kj::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan15_Kj::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan_Kj
	end

VermilionCity_Gym_EventScript_TrashCan_Kj::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen_Kj
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo_Kj
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne_Kj
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere_Kj
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne_Kj::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened_Kj
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff_Kj
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo_Kj::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo_Kj
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset_Kj
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn_Kj
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo_Kj::
	msgbox VermilionCity_Gym_Text_SecondLockOpened_Kj
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff_Kj
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen_Kj::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere_Kj
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn_Kj::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_LtSurge::
	famechecker FAMECHECKER_LTSURGE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle
	release
	end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
	famechecker FAMECHECKER_LTSURGE, 1
	call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
	clearflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_DEFEATED_LT_SURGE
	setflag FLAG_BADGE11_GET
	set_gym_trainers_frlg 3
	goto VermilionCity_Gym_EventScript_GiveTM34
	end

VermilionCity_Gym_EventScript_ShowOaksAide::
	clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_Gym_EventScript_GiveTM34::
	msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis
	checkitemspace ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM34
	giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
	setflag FLAG_GOT_TM34_FROM_SURGE
	msgbox VermilionCity_Gym_Text_ExplainTM34
	release
	end

VermilionCity_Gym_EventScript_NoRoomForTM34::
	msgbox VermilionCity_Gym_Text_MakeRoomInYourBag
	release
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	famechecker FAMECHECKER_LTSURGE, 4
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat, VermilionCity_Gym_EventScript_DefeatedTucker
	famechecker FAMECHECKER_LTSURGE, 3
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_DefeatedTucker::
	famechecker FAMECHECKER_LTSURGE, 2
	release
	end

VermilionCity_Gym_EventScript_GymGuy_Kj::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory_Kj
	msgbox VermilionCity_Gym_Text_GymGuyAdvice_Kj
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory_Kj::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory_Kj
	release
	end

VermilionCity_Gym_EventScript_GymStatue_Kj::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory_Kj
	msgbox VermilionCity_Gym_Text_GymStatue_Kj
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory_Kj::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon_Kj
	releaseall
	end

VermilionCity_Gym_Text_LtSurgeIntro::
	.string "ヘイ　ボーイ！　ここで\nなにを　しているんだ？\pユーの　ちいさな　ちからでは\nせんじょうで　いきのこれないぞ！\pいいか　ボーイ　せんそうでは\nでんきポケモンに　たすけられた！\pてきを　しびれさせて\nうごけなく　したのさ！\pユーも　おなじ　めに\nあわせて　やる！{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

VermilionCity_Gym_Text_LtSurgePostBattle::
	.string "ひとつ　アドバイスだ　ボーイ！\pでんきは　たしかに　つよい！\pだが　じめんタイプの\nポケモンには　きかないぞ！$"

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
	.string "オレンジバッジは　ポケモンの\nすばやさを　あげる！\pそれに　いつでも　そらを　とぶが\nつかえる　ように　なるぞ　ボーイ！\pユーは　とくべつだ　ボーイ！\nこれを　うけとれ！$"

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
	.string "{PLAYER}は　マチスから\nわざマシン34を　もらった$"

VermilionCity_Gym_Text_ExplainTM34::
	.string "わざマシン34は　でんげきは！\pでんきタイプの　ポケモンに\nおしえて　やれ！$"

VermilionCity_Gym_Text_MakeRoomInYourBag::
	.string "ヘイ　ボーイ　バッグを\nあけて　おけ！$"

VermilionCity_Gym_Text_LtSurgeDefeat::
	.string "オー　ノー！　ショッキング！\pユーは　ほんものだ　ボーイ！\pよし　オレンジバッジを\nもって　いけ！$"

VermilionCity_Gym_Text_TuckerIntro::
	.string "ぐんたいに　いた　ころ\nマチスは　きびしい　じょうかん\lだった\pほんとうに　きびしい\nひと　だったよ$"

VermilionCity_Gym_Text_TuckerDefeat::
	.string "まいった！\nきみは　つよい！$"

VermilionCity_Gym_Text_TuckerPostBattle::
	.string "あの　ドアを　あけるのは\nかんたんじゃ　ないよ\pマチスは　ぐんたいでも\nようじんぶかい　ことで\lゆうめい　だったんだ$"

VermilionCity_Gym_Text_BailyIntro::
	.string "ぼくは　かるいけど\nでんきには　つよいんだ！\pだから　この　ジムに\nはいったのさ！$"

VermilionCity_Gym_Text_BailyDefeat::
	.string "しびれた！$"

VermilionCity_Gym_Text_BailyPostBattle::
	.string "わかった　おしえるよ！\pマチスは　ドアの　スイッチを\nなにかの　なかに　かくしたって\lいってた$"

VermilionCity_Gym_Text_DwayneIntro::
	.string "ここは　こどもの　くる\nところじゃ　ないぞ！\lつよくても　だめだ！$"

VermilionCity_Gym_Text_DwayneDefeat::
	.string "うわ！\nおどろいた！$"

VermilionCity_Gym_Text_DwaynePostBattle::
	.string "ジムの　しかけは　マチスが\nじぶんで　つくったんだ\pいたるところに\nにじゅうの　ロックが　ある\lヒントを　やろう\pひとつめの　ロックを　あけたら\nふたつめは　すぐ　となりだ$"

VermilionCity_Gym_Text_GymGuyAdvice_Kj::
	.string "よう！\nみらいの　チャンピオン！\pマチスには　あだなが　ある\pみんなは　かれを\nイナズマ　アメリカン　と　よぶ！\pでんきポケモンの\nエキスパートだ\pとりや　みずタイプの　ポケモンは\nでんきタイプに　よわい\pまひにも　きを　つけろ\pマチスは　とても　ようじんぶかい\pじぶんを　とじこめて　いるから\nたどりつくのは　たいへんだぞ$"

VermilionCity_Gym_Text_GymGuyPostVictory_Kj::
	.string "ふう！\nしびれる　しあい　だったな！$"

VermilionCity_Gym_Text_GymStatue_Kj::
	.string "クチバ　ポケモンジム\nリーダー　マチス\pにんてい　トレーナー\n{RIVAL}$"

VermilionCity_Gym_Text_GymStatuePlayerWon_Kj::
	.string "クチバ　ポケモンジム\nリーダー　マチス\pにんてい　トレーナー\n{RIVAL}　{PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere_Kj::
	.string "ない！\nゴミしか　ない$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened_Kj::
	.string "あっ！　ゴミの　したに\nスイッチが　ある！　おしてみよう！\pひとつめの　でんきロックが\nひらいた！$"

VermilionCity_Gym_Text_SecondLockOpened_Kj::
	.string "ふたつめの　でんきロックが\nひらいた！　ドアが　ひらいた！$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset_Kj::
	.string "ない！\nゴミしか　ない\pあっ！\nでんきロックが　もどって　しまった！$"

