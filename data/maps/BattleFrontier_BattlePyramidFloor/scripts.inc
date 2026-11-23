BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest::
	.string "バトルピラミッドの　ちょうせんを\nきろく　して　ちゅうだん\lします　よろしい　ですか？$"

gText_BattlePyramidConfirmRetire::
	.string "ピラミッドの　ちょうせんを\nほんとうに　やめますか？$"

BattlePyramid_Text_ExitHintUp1::
	.string "この　フロアの　でぐちは\n{UP_ARROW}の　ほうこう　だよ$"

BattlePyramid_Text_ExitHintLeft1::
	.string "この　フロアの　でぐちは\n{LEFT_ARROW}の　ほうこう　だよ$"

BattlePyramid_Text_ExitHintRight1::
	.string "この　フロアの　でぐちは\n{RIGHT_ARROW}の　ほうこう　だよ$"

BattlePyramid_Text_ExitHintDown1::
	.string "この　フロアの　でぐちは\n{DOWN_ARROW}の　ほうこう　だよ$"

BattlePyramid_Text_ExitHintUp2::
	.string "この　フロアの　でぐちは\n{UP_ARROW}の　ほう　だ$"

BattlePyramid_Text_ExitHintLeft2::
	.string "この　フロアの　でぐちは\n{LEFT_ARROW}の　ほう　だ$"

BattlePyramid_Text_ExitHintRight2::
	.string "この　フロアの　でぐちは\n{RIGHT_ARROW}の　ほう　だ$"

BattlePyramid_Text_ExitHintDown2::
	.string "この　フロアの　でぐちは\n{DOWN_ARROW}の　ほう　だ$"

BattlePyramid_Text_ExitHintUp3::
	.string "でぐちは\nあっち　{UP_ARROW}　の　ほうさ$"

BattlePyramid_Text_ExitHintLeft3::
	.string "でぐちは\nあっち　{LEFT_ARROW}　の　ほうさ$"

BattlePyramid_Text_ExitHintRight3::
	.string "でぐちは\nあっち　{RIGHT_ARROW}　の　ほうさ$"

BattlePyramid_Text_ExitHintDown3::
	.string "でぐちは\nあっち　{DOWN_ARROW}　の　ほうさ$"

BattlePyramid_Text_ExitHintUp4::
	.string "この　フロアの　でぐちは\n{UP_ARROW}の　ほうこうの　どこかに　ある$"

BattlePyramid_Text_ExitHintLeft4::
	.string "この　フロアの　でぐちは\n{LEFT_ARROW}の　ほうこうの　どこかに　ある$"

BattlePyramid_Text_ExitHintRight4::
	.string "この　フロアの　でぐちは\n{RIGHT_ARROW}の　ほうこうの　どこかに　ある$"

BattlePyramid_Text_ExitHintDown4::
	.string "この　フロアの　でぐちは\n{DOWN_ARROW}の　ほうこうの　どこかに　ある$"

BattlePyramid_Text_ExitHintUp5::
	.string "でぐち？\nあっち　{UP_ARROW}　だよ$"

BattlePyramid_Text_ExitHintLeft5::
	.string "でぐち？\nあっち　{LEFT_ARROW}　だよ$"

BattlePyramid_Text_ExitHintRight5::
	.string "でぐち？\nあっち　{RIGHT_ARROW}　だよ$"

BattlePyramid_Text_ExitHintDown5::
	.string "でぐち？\nあっち　{DOWN_ARROW}　だよ$"

BattlePyramid_Text_ExitHintUp6::
	.string "でぐちは　たしか\n{UP_ARROW}の　ほうこう　だったわ$"

BattlePyramid_Text_ExitHintLeft6::
	.string "でぐちは　たしか\n{LEFT_ARROW}の　ほうこう　だったわ$"

BattlePyramid_Text_ExitHintRight6::
	.string "でぐちは　たしか\n{RIGHT_ARROW}の　ほうこう　だったわ$"

BattlePyramid_Text_ExitHintDown6::
	.string "でぐちは　たしか\n{DOWN_ARROW}の　ほうこう　だったわ$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　8こ　おちて　いるよ$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　7こ　おちて　いるよ$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　6こ　おちて　いるよ$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　5こ　おちて　いるよ$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　4こ　おちて　いるよ$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　3こ　おちて　いるよ$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　2こ　おちて　いるよ$"

BattlePyramid_Text_OneItemRemaining1::
	.string "どうぐを　さがして　いるの？\pまだ　1こ　おちて　いるよ$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "どうぐを　さがして　いるの？\pもう　なにも\nおちて　いないよ！$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\n8こ　おちて　いるよ$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　7こ　おちて　いるよ$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　6こ　おちて　いるよ$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　5こ　おちて　いるよ$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　4こ　おちて　いるよ$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　3こ　おちて　いるよ$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\nあと　2こ　おちて　いるよ$"

BattlePyramid_Text_OneItemRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　どうぐが\n1こ　だけ　おちて　いるよ$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "きみの　かちだから\nちょっと　ひみつを　おしえる！\pこの　あたりには　もう\nなにも　おちて　いないよ$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　8こ　ある　はずだ$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　7こ　ある　はずだ$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　6こ　ある　はずだ$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　5こ　ある　はずだ$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　4こ　ある　はずだ$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　3こ　ある　はずだ$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　まだ\nどうぐが　2こ　ある　はずだ$"

BattlePyramid_Text_OneItemRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　どうぐが\nあと　1こ　だけ　ある　はずだ$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "どうぐは　たりてるかい？\pこの　フロアには　もう\nどうぐは　ない　はずだ\lきを　つけてな！$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n8こ　ある　みたい$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n7こ　ある　みたい$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n6こ　ある　みたい$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n5こ　ある　みたい$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n4こ　ある　みたい$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n3こ　ある　みたい$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n2こ　ある　みたい$"

BattlePyramid_Text_OneItemRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんに　どうぐが　あと\n1こ　だけ　ある　みたい$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "つよいから　ヒントを\nあげる！\pじめんには　もう\nどうぐは　ない　みたい$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　8こ　あるらしい‥$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　7こ　あるらしい‥$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　6こ　あるらしい‥$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　5こ　あるらしい‥$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　4こ　あるらしい‥$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　3こ　あるらしい‥$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　2こ　あるらしい‥$"

BattlePyramid_Text_OneItemRemaining5::
	.string "ピラミッドの　この　フロアには\nどうぐが　1こ　あるらしい‥$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "ピラミッドの　この　フロアには\nもう　どうぐは　ないらしい‥$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n8こ　ある　はずよ$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n7こ　ある　はずよ$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n6こ　ある　はずよ$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n5こ　ある　はずよ$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n4こ　ある　はずよ$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n3こ　ある　はずよ$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n2こ　ある　はずよ$"

BattlePyramid_Text_OneItemRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　あと\n1こ　ある　はずよ$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "どうぐは　ひろった？\pこの　フロアには　もう\nどうぐは　ない　はずよ$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　7にん　いる！$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　6にん　いる！$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　5にん　いる！$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　4にん　いる！$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　3にん　いる！$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　2にん　いる！$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pでも　ぼくの　ほかに　まだ\nつよい　トレーナーが　1にん　いる！$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "きみ　ほんとに　すごいね！\pもう　きみに　かてる\nひとは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n7にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n6にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n5にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n4にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n3にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n2にん　いる！\lだれかが　きみを　たおすよ！$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "くやしい！\pでも　トレーナーは　あと\n1にん　いる！\lきっと　きみを　たおすよ！$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "くやしい！\pもう　きみと　たたかえる\nトレーナーは　いないよ！$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n7にん　トレーナーが　いる\lみんなに　かてるかな？$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n6にん　トレーナーが　いる\lみんなに　かてるかな？$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n5にん　トレーナーが　いる\lみんなに　かてるかな？$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n4にん　トレーナーが　いる\lみんなに　かてるかな？$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n3にん　トレーナーが　いる\lみんなに　かてるかな？$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n2にん　トレーナーが　いる\lふたりとも　かてるかな？$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "なかなか　やるね！\pでも　この　フロアには　あと\n1にん　トレーナーが　いる\lかてるかな？$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "なかなか　やるね！\pこの　フロアの　トレーナーを\nぜんいん　たおしたね$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "この　フロアに　のこった\n7にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "この　フロアに　のこった\n6にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "この　フロアに　のこった\n5にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "この　フロアに　のこった\n4にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "この　フロアに　のこった\n3にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "この　フロアに　のこった\n2にんの　トレーナーにも\lかてる　かもね$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "この　フロアに　のこった\n1にんにも　かてば　ぜんしょうだね$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "もう　きみに　かてる　ひとは\nひとりも　いない‥$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "きみなら　のこりの\n7にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "きみなら　のこりの\n6にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "きみなら　のこりの\n5にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "きみなら　のこりの\n4にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "きみなら　のこりの\n3にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "きみなら　のこりの\n2にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "きみなら　のこりの\n1にんの　つわものにも\lかてる　かも　しれない$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "きみの　うでは\nもうしぶん　ない\pもう　きみに　かてそうな\nトレーナーは　いないよ$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "のこりの　7にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "のこりの　6にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "のこりの　5にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "のこりの　4にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "のこりの　3にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "のこりの　2にんの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "のこった　さいごの\nトレーナーにも　かてるかな？$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "もう　きみの　あいてに\nなる　トレーナーは　いない‥$"
