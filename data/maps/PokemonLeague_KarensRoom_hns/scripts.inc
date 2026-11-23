PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC

PokemonLeague_KarensRoom_EventScript_KarenRematchStandard::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_POSTOBC_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
	.string "カリン『あら　また　あなた\pわたしの　しんねん\nわすれて　ないわよね\pほんとうの　つよさは\nポケモンを　しんじる\lこころから　うまれる\pあれから　わたしと\nポケモンの　きずなは\lもっと　ふかく　なった\pこわれない　きずなで\nむすばれた　チームに\lいどむ　かくごは　いい？\pあなたと　ポケモンの\nきずなの　ちからを\lみせて　ちょうだい$"

PokemonLeague_KarensRoom_Text_Before:
	.string "わたしは　してんのうの　カリン\pあなたが　{PLAYER}？\nおもしろい　わね\pわたしは　あくタイプの\nポケモンが　すき\pワイルドで　タフな　ところに\nひかれるの　それに\lとても　つよい\pあなたに　かてる　かしら？\nせいぜい　たのしませて\pさあ　はじめましょう$"

PokemonLeague_KarensRoom_Text_Beaten:
	.string "あら　やるじゃない\nそういう　トレーナー\lすきよ$"

PokemonLeague_KarensRoom_Text_Defeat:
	.string "つよい　ポケモン\pよわい　ポケモン\pそんなの　ひとの\nかってな　おもいこみ\pほんとうに　うでの　ある\nトレーナー　なら　すきな\lポケモンで　かつべき\pあなたの　スタイル　すきよ\nだいじな　ことが\lわかってる\pさあ　いって\nチャンピオンが　まってるわ$"

