SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_KJ_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_KJ_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_KJ_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_KJ_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_KJ_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
	.string "しゃちょう“おお　しょうねんよ！\n"
	.string "たすけて　くれて　ありがとう！\p"
	.string "わたしは\n"
	.string "ピンチを　すくって　くれた\p"
	.string "きみのことを　このさき\n"
	.string "けして　わすれない　だろう！\p"
	.string "おお！　そうだ\n"
	.string "おれいを　さしあげなくては！\p"
	.string "わたしは\n"
	.string "ふとっぱらで　ある　からして\p"
	.string "ほれ\n"
	.string "こーんな　ものでは　いかがかな？$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
	.string "しゃちょう“おお　しょうじょよ！\n"
	.string "たすけて　くれて　ありがとう！\p"
	.string "わたしは\n"
	.string "ピンチを　すくって　くれた\p"
	.string "きみのことを　このさき\n"
	.string "けして　わすれない　だろう！\p"
	.string "おお！　そうだ\n"
	.string "おれいを　さしあげなくては！\p"
	.string "わたしは\n"
	.string "ふとっぱらで　ある　からして\p"
	.string "ほれ\n"
	.string "こーんな　ものでは　いかがかな？$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
	.string "{PLAYER}は　しゃちょうから\n"
	.string "マスターボールを　もらった！$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
	.string "しゃちょう“それは…\n"
	.string "どこで　かうことも　できない\p"
	.string "ひみつの\n"
	.string "しさくひん　マスターボール！\p"
	.string "なげれば　かならず\n"
	.string "ポケモンを　つかまえられる！\p"
	.string "こっそりと…\n"
	.string "…　…\l"
	.string "つかって　みて　くれたまえ$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
	.string "もちものが　いっぱいだぞ$"

SilphCo_11F_Text_ThanksForRescuingUs::
	.string "ひしょ“このたびは　たすけて\n"
	.string "いただいて　ありがとう　ございます\p"
	.string "しゃちょう　ともども\n"
	.string "かんしゃの　きもちで　いっぱいです$"

SilphCo_11F_Text_GiovanniIntro::
	.string "おお　{PLAYER}か？\n"
	.string "また　あったな！\p"
	.string "おれは　いま　シルフの　しゃちょうと\n"
	.string "しごとの　はなしを　してるんだ\p"
	.string "おとなの　せかいに\n"
	.string "くちを　はさまないで　もらいたい\p"
	.string "どうしても　というなら\n"
	.string "いたいめに　あって　もらうぞ！$"

SilphCo_11F_Text_GiovanniDefeat::
	.string "はぐ！\n"
	.string "この　おれが　まける　なんて！$"

SilphCo_11F_Text_GiovanniPostBattle::
	.string "くそー　…しょうが　ない！\n"
	.string "シルフは　ひとまず　あきらめよう！\p"
	.string "しかし　\n"
	.string "わが　ロケットだんは　ふめつだ！\p"
	.string "{PLAYER}！　すべての　ポケモンは\n"
	.string "ロケットだんの　ために\l"
	.string "そんざい　するのだ！\l"
	.string "そのことを　わすれるなよ！\p"
	.string "では…！\n"
	.string "おれは　たいさん　しよう！$"

SilphCo_11F_Text_Grunt2Intro::
	.string "こらこら　まて！\n"
	.string "すすんでは　いかん　というのに$"

SilphCo_11F_Text_Grunt2Defeat::
	.string "ううーん　だめだ$"

SilphCo_11F_Text_Grunt2PostBattle::
	.string "そうか\n"
	.string "ボスに　あおうって　いうのかい$"

SilphCo_11F_Text_Grunt1Intro::
	.string "なんだ　おまえは\n"
	.string "ボスに　なんの　ようだ！$"

SilphCo_11F_Text_Grunt1Defeat::
	.string "だあー！　やられた$"

SilphCo_11F_Text_Grunt1PostBattle::
	.string "いって　おくが　ボスは　つよいぞ\n"
	.string "くれぐれも　きを　つけな$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
	.string "モニター　がめんに\n"
	.string "ポケモンが　うつってる！$"

SilphCo_11F_Text_FloorSign::
	.string "シルフ　カンパニー　ほんしゃ\n"
	.string "１１かい$"

