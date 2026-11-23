BattleFrontier_BattlePyramidFloor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition_hns
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame_hns:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume_hns:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition_hns:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop_hns
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP_HNS, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle_hns::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall_hns::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBall_hnsEnd_hns
	pyramid_hideitem
BattlePyramid_FindItemBall_hnsEnd_hns::
	end

BattlePyramid_Retire_hns::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText_hns:
	.string "これは　サンプルの\nメッセージです$"

gText_BattlePyramidConfirmRest_hns::
	.string "バトルピラミッドの　たんけんを\nレポート　して　いったん\lやめます　よろしいですか？$"

gText_BattlePyramidConfirmRetire_hns::
	.string "ピラミッドの　たんけんを\nほんとうに　やめますか？$"

BattlePyramid_Text_ExitHintUp1_hns::
	.string "この　かいの　でぐちは\n{UP_ARROW}の　ほうこうだ$"

BattlePyramid_Text_ExitHintLeft1_hns::
	.string "この　かいの　でぐちは\n{LEFT_ARROW}の　ほうこうだ$"

BattlePyramid_Text_ExitHintRight1_hns::
	.string "この　かいの　でぐちは\n{RIGHT_ARROW}の　ほうこうだ$"

BattlePyramid_Text_ExitHintDown1_hns::
	.string "この　かいの　でぐちは\n{DOWN_ARROW}の　ほうこうだ$"

BattlePyramid_Text_ExitHintUp2_hns::
	.string "この　かいの　でぐちは\n{UP_ARROW}の　ほうに　あるよ$"

BattlePyramid_Text_ExitHintLeft2_hns::
	.string "この　かいの　でぐちは\n{LEFT_ARROW}の　ほうに　あるよ$"

BattlePyramid_Text_ExitHintRight2_hns::
	.string "この　かいの　でぐちは\n{RIGHT_ARROW}の　ほうに　あるよ$"

BattlePyramid_Text_ExitHintDown2_hns::
	.string "この　かいの　でぐちは\n{DOWN_ARROW}の　ほうに　あるよ$"

BattlePyramid_Text_ExitHintUp3_hns::
	.string "でぐちは\n{UP_ARROW}の　ほうだ$"

BattlePyramid_Text_ExitHintLeft3_hns::
	.string "でぐちは\n{LEFT_ARROW}の　ほうだ$"

BattlePyramid_Text_ExitHintRight3_hns::
	.string "でぐちは\n{RIGHT_ARROW}の　ほうだ$"

BattlePyramid_Text_ExitHintDown3_hns::
	.string "でぐちは\n{DOWN_ARROW}の　ほうだ$"

BattlePyramid_Text_ExitHintUp4_hns::
	.string "この　かいの　でぐちは\n{UP_ARROW}の　どこかに　ある$"

BattlePyramid_Text_ExitHintLeft4_hns::
	.string "この　かいの　でぐちは\n{LEFT_ARROW}の　どこかに　ある$"

BattlePyramid_Text_ExitHintRight4_hns::
	.string "この　かいの　でぐちは\n{RIGHT_ARROW}の　どこかに　ある$"

BattlePyramid_Text_ExitHintDown4_hns::
	.string "この　かいの　でぐちは\n{DOWN_ARROW}の　どこかに　ある$"

BattlePyramid_Text_ExitHintUp5_hns::
	.string "でぐち？\n{UP_ARROW}の　ほうさ$"

BattlePyramid_Text_ExitHintLeft5_hns::
	.string "でぐち？\n{LEFT_ARROW}の　ほうさ$"

BattlePyramid_Text_ExitHintRight5_hns::
	.string "でぐち？\n{RIGHT_ARROW}の　ほうさ$"

BattlePyramid_Text_ExitHintDown5_hns::
	.string "でぐち？\n{DOWN_ARROW}の　ほうさ$"

BattlePyramid_Text_ExitHintUp6_hns::
	.string "でぐちは　たしか\n{UP_ARROW}の　ほうこうだよ$"

BattlePyramid_Text_ExitHintLeft6_hns::
	.string "でぐちは　たしか\n{LEFT_ARROW}の　ほうこうだよ$"

BattlePyramid_Text_ExitHintRight6_hns::
	.string "でぐちは　たしか\n{RIGHT_ARROW}の　ほうこうだよ$"

BattlePyramid_Text_ExitHintDown6_hns::
	.string "でぐちは　たしか\n{DOWN_ARROW}の　ほうこうだよ$"

BattlePyramid_Text_EightItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　8こ　あるよ$"

BattlePyramid_Text_SevenItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　7こ　あるよ$"

BattlePyramid_Text_SixItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　6こ　あるよ$"

BattlePyramid_Text_FiveItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　5こ　あるよ$"

BattlePyramid_Text_FourItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　4こ　あるよ$"

BattlePyramid_Text_ThreeItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　3こ　あるよ$"

BattlePyramid_Text_TwoItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　2こ　あるよ$"

BattlePyramid_Text_OneItemRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　どうぐが\nあと　1こ　あるよ$"

BattlePyramid_Text_ZeroItemsRemaining1_hns::
	.string "どうぐを　さがしてるの？\pこの　かいには　もう\nどうぐは　ないよ$"

BattlePyramid_Text_EightItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　8こ　あるよ$"

BattlePyramid_Text_SevenItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　7こ　あるよ$"

BattlePyramid_Text_SixItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　6こ　あるよ$"

BattlePyramid_Text_FiveItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　5こ　あるよ$"

BattlePyramid_Text_FourItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　4こ　あるよ$"

BattlePyramid_Text_ThreeItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　3こ　あるよ$"

BattlePyramid_Text_TwoItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　2こ　あるよ$"

BattlePyramid_Text_OneItemRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　どうぐが\nあと　1こ　あるよ$"

BattlePyramid_Text_ZeroItemsRemaining2_hns::
	.string "かったから　ひみつを\nおしえて　あげる！\pこの　かいには　もう\nどうぐは　ないよ$"

BattlePyramid_Text_EightItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　8こ　あるよ$"

BattlePyramid_Text_SevenItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　7こ　あるよ$"

BattlePyramid_Text_SixItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　6こ　あるよ$"

BattlePyramid_Text_FiveItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　5こ　あるよ$"

BattlePyramid_Text_FourItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　4こ　あるよ$"

BattlePyramid_Text_ThreeItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　3こ　あるよ$"

BattlePyramid_Text_TwoItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　2こ　あるよ$"

BattlePyramid_Text_OneItemRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　どうぐが\nあと　1こ　あるよ$"

BattlePyramid_Text_ZeroItemsRemaining3_hns::
	.string "どうぐは　たりてるかい？\pこの　かいには　もう\nどうぐは　ないよ$"

BattlePyramid_Text_EightItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　8こ　あるよ$"

BattlePyramid_Text_SevenItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　7こ　あるよ$"

BattlePyramid_Text_SixItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　6こ　あるよ$"

BattlePyramid_Text_FiveItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　5こ　あるよ$"

BattlePyramid_Text_FourItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　4こ　あるよ$"

BattlePyramid_Text_ThreeItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　3こ　あるよ$"

BattlePyramid_Text_TwoItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　2こ　あるよ$"

BattlePyramid_Text_OneItemRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　どうぐが\nあと　1こ　あるよ$"

BattlePyramid_Text_ZeroItemsRemaining4_hns::
	.string "つよいから　ヒントを\nあげよう！\pこの　かいには　もう\nどうぐは　ないよ$"

BattlePyramid_Text_EightItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n8こ　あると　きいた‥$"

BattlePyramid_Text_SevenItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n7こ　あると　きいた‥$"

BattlePyramid_Text_SixItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n6こ　あると　きいた‥$"

BattlePyramid_Text_FiveItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n5こ　あると　きいた‥$"

BattlePyramid_Text_FourItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n4こ　あると　きいた‥$"

BattlePyramid_Text_ThreeItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n3こ　あると　きいた‥$"

BattlePyramid_Text_TwoItemsRemaining5_hns::
	.string "この　かいには　どうぐが\n2こ　あると　きいた‥$"

BattlePyramid_Text_OneItemRemaining5_hns::
	.string "この　かいには　どうぐが\n1こ　あると　きいた‥$"

BattlePyramid_Text_ZeroItemsRemaining5_hns::
	.string "この　かいには　どうぐは\nないと　きいた‥$"

BattlePyramid_Text_EightItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　8こ　あるよ$"

BattlePyramid_Text_SevenItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　7こ　あるよ$"

BattlePyramid_Text_SixItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　6こ　あるよ$"

BattlePyramid_Text_FiveItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　5こ　あるよ$"

BattlePyramid_Text_FourItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　4こ　あるよ$"

BattlePyramid_Text_ThreeItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　3こ　あるよ$"

BattlePyramid_Text_TwoItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　2こ　あるよ$"

BattlePyramid_Text_OneItemRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　どうぐが\nあと　1こ　あるよ$"

BattlePyramid_Text_ZeroItemsRemaining6_hns::
	.string "どうぐは　あつめた？\pこの　かいには　もう\nどうぐは　ないよ$"

BattlePyramid_Text_SevenTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining1_hns::
	.string "きみ　ほんとうに　すごい！\pもう　きみに　かてる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining2_hns::
	.string "くやしい！\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining2_hns::
	.string "くやしい！\pもう　きみに　かてる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining3_hns::
	.string "やるな！\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining3_hns::
	.string "やるな！\pもう　きみに　かてる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining4_hns::
	.string "まけたよ\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining4_hns::
	.string "まけたよ\pもう　きみに　かてる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining5_hns::
	.string "つよいね\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining5_hns::
	.string "つよいね\pもう　きみに　かてる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　7にん　いるぞ！$"

BattlePyramid_Text_SixTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　6にん　いるぞ！$"

BattlePyramid_Text_FiveTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　5にん　いるぞ！$"

BattlePyramid_Text_FourTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　4にん　いるぞ！$"

BattlePyramid_Text_ThreeTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　3にん　いるぞ！$"

BattlePyramid_Text_TwoTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　2にん　いるぞ！$"

BattlePyramid_Text_OneTrainersRemaining6_hns::
	.string "おみごと\pでも　つよい　トレーナーが\nまだ　1にん　いるぞ！$"

BattlePyramid_Text_ZeroTrainersRemaining6_hns::
	.string "おみごと\pもう　きみに　かてる\nトレーナーは　いないよ！$"
