.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}くん！\pここで　なにを　してるんだい？\pじょしゅが　まだ　キキョウシティで\nきみを　まってるよ！$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	removeitem ITEM_SS_TICKET
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "さわらない　ほうが\nよさそうだ！$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ウツギ『やあ！　きみが\n{PLAYER}くん　だね！\p"
	.string "オーキドはかせから\nはなしは　きいて　いるよ\p"
	.string "カントーの　チャンピオンに\nなった　トレーナー　だって！\p"
	.string "じつは　きみに　たのみが\nあったんだ\p"
	.string "いま　あたらしい　ポケモンの\nけんきゅうを　しているんだけど\l{PLAYER}くんに　てつだって\lもらえないかと　おもってね\p"
	.string "がっかいで　はっぴょう\nしたい　ろんぶんを\lかいているんだ\p"
	.string "でも　まだ　よく　わからない\nところが　あってね\p"
	.string "そこで！\p"
	.string "さいきん　つかまえた　ポケモンを\nきみに　そだてて　ほしいんだ$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "ありがとう　{PLAYER}くん！\nほんとうに　たすかるよ！$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "そんな‥　たのむよ\nきみの　ちからが　ひつようなんだ！$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "わたしの　けんきゅうを\nはっぴょう　すれば\pポケモンの　なぞが\nもっと　ふかく　わかるはずさ\pきたいして　いて\nくれよ！$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "おや？　メールが\nとどいたぞ！\p‥‥‥‥‥‥‥‥\nふむ‥　なるほど‥\pよし‥$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "ねえ　きいてよ\pわたしの　しりあいに\nポケモンじいさんって　ひとが\lいるんだけど\pへんな　ものを　みつけては\nだいはっけんだと\lさわいでるんだ\pその　ひとから　こんどこそ\nほんものだって　メールが\lきたんだ\pきに　なるけど\nポケモンの　けんきゅうで\lいそがしいし‥\pそうだ！\nいい　ことを　おもいついた！\p{PLAYER}くん　かわりに\nいって　くれないかい？$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "この　ボールの　なかの　ポケモンを\n1ぴき　そだてて　ほしいんだ\p"
	.string "{PLAYER}くんの　ジョウトでの\nあたらしい　パートナーさ！\p"
	.string "さあ　えらんで！$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ウツギ『まって！　どこへ\nいくんだい？$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ウツギ『{STR_VAR_2}ポケモンの\n{STR_VAR_1}に　するかい？$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ウツギ『{STR_VAR_2}ポケモンの\n{STR_VAR_1}が　いいかい？$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ウツギ『{STR_VAR_2}ポケモンの\n{STR_VAR_1}が　すきなのかい？$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ウツギ『よく　かんがえてね\pパートナーは　だいじだよ$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ウツギ『わたしも　すばらしい\nポケモンだと　おもうよ！$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER}は\n{STR_VAR_1}を　てにいれた！$"

NewBarkTown_Lab_Text_Nickname:
	.string "{STR_VAR_1}に\nニックネームを　つけますか？$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "ポケモンじいさんの　いえは\nとなりの　ヨシノシティの\lすこし　さきだよ\pほとんど　いっぽんみち　だから\nまよわないと　おもうけど\pねんのため　わたしの　でんわ\nばんごうは　しってるね\lなにか　あったら　でんわしてね！$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "ポケモンじいさんの　いえは\nとなりの　ヨシノシティの\lすこし　さきだよ\pほとんど　いっぽんみち　だから\nまよわないと　おもうけど\pねんのため　わたしの　でんわ\nばんごうを　おしえて　おくよ\lなにか　あったら　でんわしてね！$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "ポケギアに\nウツギはかせを　とうろく　した$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "やせいの　ポケモンが　でたら\nきみの　ポケモンで　たたかうんだ！$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "やせいの　ポケモンが　でたら\nきみの　ポケモンで　たたかうんだ！\pポケモンが　きずついたら\nわたしの　みぎの　きかいか\lポケモンセンターで　なおしてね\pたのんだよ！$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER}は　ウツギはかせの\nでんわばんごうを　てにいれた$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "ポケモンじいさんは　あちこち\nいっては　めずらしい　ものを\lみつけて　くるんだ\pでも　めずらしい　だけで\nあまり　やくに　たたないのが\lざんねん　なんだよね‥$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "ウツギはかせが　つかまえた\nポケモンが　はいっている$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ウツギ『{PLAYER}くん　たいへんな\nことに　なったよ‥\pそうそう　ポケモンじいさんの\nだいはっけんって　なんだった？$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER}は　ふしぎなタマゴを\nウツギはかせに　わたした$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ウツギ『これ？$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "でも‥　これって　ポケモンの\nタマゴかな？\p"
	.string "もし　そうなら\nだいはっけんだ！\p"
	.string "ウツギ『なに！？\p"
	.string "オーキドはかせが　きみの\nポケモンずかんを　ジョウトでも\lつかえる　ように　してくれた！？\p"
	.string "さすが　オーキドはかせだ！\p"
	.string "カントーの　チャンピオンの\nきみなら　ジョウトの　ジムも\lきっと　のりこえられるよ\p"
	.string "いちばん　ちかい　ジムは\nキキョウシティだよ\p"
	.string "‥{PLAYER}くん　ジョウトの\nたびも　ながいよ\p"
	.string "マサラタウンの　おかあさんにも\nちゃんと　れんらく　しておいてね$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ウツギ『あきらめないで！\nタマゴの　ことが　わかったら\lでんわ　するよ！$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ウツギ『{PLAYER}くん？　じょしゅに\nあわなかったかい？\pキキョウシティの　ポケモンセンターで\nタマゴを　もって　まってる\pはずなんだけど\pいきちがい　だったのかな\nもういちど　いって　みて$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ウツギ『ねえ　タマゴに\nへんかは　あったかい？$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}くん？　タマゴが\nかえったと　おもったんだけど\pポケモンは　どこだい？$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ウツギ『{PLAYER}くん　げんきそうだね！$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "え？　その　ポケモン！？$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "タマゴが　かえったんだ！\nポケモンは　タマゴから\lうまれるのか‥\pいや　ぜんぶの　ポケモンが\nそうとは　かぎらないか\pいやあ　まだまだ　けんきゅう\nする　ことが　いっぱいだ$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "ありがとう　{PLAYER}くん！\nポケモンの　なぞを　とく\lてつだいを　してくれて！\pおれいの　しるしに\nこれを　うけとって$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "それは　かわらずのいし\pポケモンの　なかには　ある\nレベルに　なると　しんかする\lものが　いる\pかわらずのいしを　もった\nポケモンは　しんか　しないんだ\pしんか　させたくない\nポケモンに　もたせてね$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ウツギ『{PLAYER}くん　なにか\nあったら　でんわするよ$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "‥はあ‥　ぬすまれた　ポケモン\pいま　どうして　いるかな\pわるい　ひとに　そだてられた\nポケモンは　わるく　なるって\lいうけど‥$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ウツギ『やあ　{PLAYER}くん！\pきみの　おかげで　けんきゅうは\nじゅんちょうだよ！\pおれいの　しるしに\nこれを　うけとって$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "マスターボールは　さいこうの\nボールさ！\pどんな　ポケモンでも　かならず\nつかまえられる\pみとめられた　ポケモン\nけんきゅうしゃ　だけが\lもらえるんだ\pわたしより　{PLAYER}くんの\nほうが　ずっと　うまく\lつかえると　おもうよ！$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "ところで‥\nきれいな　まいこはんたちが\lきみを　さがして　いたよ\pエンジュの　かぶれんじょうで\nまっているって\pあの　タマゴを　きっかけに\nいろんな　ことが　あったね‥\pさいごまで　やりとげて\nほしいな$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "ウツギ『まいこはんたちが\nエンジュの　かぶれんじょうで\lまっているよ$"

NewBarkTown_Lab_Text_League:
	.string "ウツギ『あはは‥\nよく　やったね！\p"
	.string "あの　めずらしい　タマゴの\nせいで　いろいろ　たいへん\lだったね？\p"
	.string "まいこはんたちが　わたしの\nことを　なにか　いってた？\p"
	.string "わたしは　なにも\nしていないよ\p"
	.string "きみが　じぶんで　きめて\nやりとげたんだ\p"
	.string "ここまで　やったなら\nジョウトの　ポケモンリーグにも\lちょうせん　できるはずだ！\p"
	.string "3ねん　まえとは　ちがう\nしてんのうが　セキエイこうげんで\lまって　いるよ！\p"
	.string "いきかたは　わかるかい？\n27ばんどうろから　26ばんどうろへ\p"
	.string "そこから　まっすぐ　きただよ！$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ウツギ『{PLAYER}くん！\nまってたよ！\p"
	.string "ジョウトの　チャンピオン\nおめでとう！\p"
	.string "おいわいに　わたしたい\nものが　あって　でんわ　したんだ\p"
	.string "ほら　ふねのチケットだよ\p"
	.string "これで　いつでも\nカントーに　かえれるね$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "ふねは　アサギシティから\nでているよ\p"
	.string "3ねんぶりの　カントーは\nきっと　すこし　かわって　いるよ\p"
	.string "マサラタウンの　おかあさんと\nオーキドはかせに\lよろしく　つたえてね！$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "ウツギはかせが　しらべている\nポケモンの　タマゴだ$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}くん　おつかいの\nために　これを　どうぞ$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "ここは　3にん　しか　いないから\nいつも　いそがしいんだ$"

NewBarkTown_Lab_Text_AideSave:
	.string "こまめに　レポートを\nかくのを　わすれずに！\pスタートボタンを　おして\nレポートを　えらんでね！$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "そとで　おおきな　おとが\nしたんだ‥\pみに　いったら　ポケモンを\nぬすまれて　しまった\pそんな　ことを　する\nひとが　いるなんて！\p‥はあ‥　ぬすまれた　ポケモン\pいま　どうして　いるかな\pわるい　ひとに　そだてられた\nポケモンは　わるく　なるって\lいうけど‥$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}くん！\pずかんづくりに\nこれを　つかって！$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "{PLAYER}くんには\nいうまでも　ないけど\p"
	.string "ジョウトの　ポケモンも\nどんどん　つかまえて\lずかんに　とうろく　してね！$"

NewBarkTown_Lab_Text_Officer1:
	.string "ここで　ポケモンが\nぬすまれたと　きいてね‥\pいま　ウツギはかせから\nはなしを　きいて　いたんだ\pどうやら　あかい　かみの\nわかい　おとこ　らしい‥\pなに？\pそんな　トレーナーと\nしょうぶ　したって？\pなまえは　わかるかい？$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "よし！　{RIVAL}と　いうんだな？$"

NewBarkTown_Lab_Text_Officer2:
	.string "そうさに　きょうりょく\nありがとう！$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "なまえくらい　わかるだろう！？$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "やあ　{PLAYER}くん！\pずかんは　すすんでるかい？\nいまは　いそがしいけど\lでんわを　くれれば　みてあげるよ！$"
