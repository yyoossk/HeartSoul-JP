PokemonLeague_BrunosRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume_Kj
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_BrunosRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BrunosRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BrunosRoom_OnFrame
	.byte 0

PokemonLeague_BrunosRoom_OnResume_Kj::
	setvar VAR_0x8004, 1
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_BrunosRoom_OnLoad::
	call_if_set FLAG_KJ_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_SetDoorOpen
	call_if_eq VAR_MAP_SCENE_POKEMON_LEAGUE, 2, PokemonLeague_BrunosRoom_EventScript_CloseEntry
	end

PokemonLeague_BrunosRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_BrunosRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_BrunosRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_BrunosRoom_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 1, PokemonLeague_BrunosRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 2
	releaseall
	end

PokemonLeague_BrunosRoom_EventScript_Bruno_Kj::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_KJ_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_PostBattle
	famechecker FAMECHECKER_BRUNO, 0
	famechecker FAMECHECKER_BRUNO, 1
	call_if_unset FLAG_KJ_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_Intro
	call_if_set FLAG_KJ_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_KJ_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_Battle
	call_if_set FLAG_KJ_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_Rematch
	clearflag FLAG_TEMP_5
	goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
	end

PokemonLeague_BrunosRoom_EventScript_Intro::
	msgbox PokemonLeague_BrunosRoom_Text_Intro
	return

PokemonLeague_BrunosRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_BrunosRoom_Text_RematchIntro
	return

PokemonLeague_BrunosRoom_EventScript_Battle::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat_Kj
	return

PokemonLeague_BrunosRoom_EventScript_Rematch::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO_2, PokemonLeague_BrunosRoom_Text_Defeat_Kj
	return

PokemonLeague_BrunosRoom_EventScript_PostBattle::
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	release
	end

PokemonLeague_BrunosRoom_EventScript_DefeatedBruno::
	setflag FLAG_KJ_DEFEATED_BRUNO
	call PokemonLeague_EventScript_OpenDoor
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PokemonLeague_BrunosRoom_Text_Intro::
	.string "おれは　してんのうの　シバ！\p"
	.string "ひとも　ポケモンも\n"
	.string "たたかい　きたえれば\l"
	.string "どこまでも　つよくなる！\p"
	.string "おれは　そんな　きたえ　ぬかれた\n"
	.string "かくとうポケモン　たちと\l"
	.string "ともに　いきてきた！\l"
	.string "そして　これからもな！\p"
	.string "{PLAYER}と　いったな！\p"
	.string "おれたちの　スーパー　パワーを\n"
	.string "うけて　みるが　いい！\p"
	.string "ウー！　ハーッ！{0xFC}{0x0B}{0x56}{0x01}$"

PokemonLeague_BrunosRoom_Text_RematchIntro::
	.string "おれは　してんのうの　シバ！\p"
	.string "ひとも　ポケモンも\n"
	.string "たたかい　きたえれば\l"
	.string "どこまでも　つよくなる！\p"
	.string "おれは　そんな　きたえ　ぬかれた\n"
	.string "かくとうポケモン　たちと\l"
	.string "ともに　いきてきた！\l"
	.string "そして　これからもな！\p"
	.string "{PLAYER}よ…！\p"
	.string "おれたちの　スーパー　パワーを\n"
	.string "うけて　みるが　いい！\p"
	.string "ウー！　ハーッ！{0xFC}{0x0B}{0x56}{0x01}$"

PokemonLeague_BrunosRoom_Text_Defeat_Kj::
	.string "どうした　ことだ！\n"
	.string "…　おれが　まけるとは！$"

PokemonLeague_BrunosRoom_Text_PostBattle::
	.string "まけちまったら\n"
	.string "おれの　でばんは　おわりだ！\l"
	.string "くそッ！　つぎに　いって　くれ！$"

