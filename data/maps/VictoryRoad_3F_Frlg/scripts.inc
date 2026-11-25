VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "きみは　すてみで\n"
	.string "この　チャンピオンロードを\l"
	.string "ぬけて　きたのだな！\p"
	.string "がんばりを　みとめて\n"
	.string "すてみタックルを　おしえよう！\p"
	.string "どうだ　おしえて　ほしいか？$"

Text_DoubleEdgeDeclined::
	.string "きみには　いつでも　おしえよう\n"
	.string "また　くるがいい$"

Text_DoubleEdgeWhichMon::
	.string "どの　ポケモンに\n"
	.string "おしえさせて　みるか？$"

Text_DoubleEdgeTaught::
	.string "ポケモンリーグでも　その　いきだ！\n"
	.string "すてみで　ぶつかって　いけ！$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "やたらと　つよい　こどもが　いると\n"
	.string "ウワサは　きいて　いるよ$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "たいした　やつだ$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "ロケットだんの　サカキを\n"
	.string "たおしたのは　…　きみか！$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "つよい　あいてを　もとめるのは\n"
	.string "トレーナーの　しゅくめいよ！$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "ああッ　つよい！$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "きびしい　たたかいを　つづけて\n"
	.string "ほんとうの　つよさが　みに　つくわ$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "うえには　うえが　いるって\n"
	.string "おしえて　あげます！$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "…　くやしい！$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "あなた　わたしより　つよいわ！\n"
	.string "うえには　うえが　いるって　ことか$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "えらばれた　もの　だけが\n"
	.string "ここを　ぬけられるのだ！$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "まさかの　はいぼくだ$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "ここの　トレーナーも　みんな\n"
	.string "ポケモン　リーグを　めざしている\l"
	.string "ゆだん　しない　ほうが　いいぜ！$"

VictoryRoad_3F_Text_RayIntro::
	.string "シン“ふたりで　どこまでも\n"
	.string "うえを　めざすっ！$"

VictoryRoad_3F_Text_RayDefeat::
	.string "シン“ばかな…！$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "シン“ぼくたちの　まけだ\n"
	.string "うえには　うえが　いるものだな$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "シン“ふたりで　ちょうてんを\n"
	.string "めざして　いるんだ\l"
	.string "きみも　ポケモン　２ひきで\l"
	.string "たたかって　くれたまえ$"

VictoryRoad_3F_Text_TyraIntro::
	.string "カヨ“いっしょに\n"
	.string "チャンピオンを　めざすわ！$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "カヨ“そんな…$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "カヨ“つよさは　むげん　なのね\n"
	.string "おしえて　くれて　ありがとう$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "カヨ“ポケモン　１ひきでは\n"
	.string "わたしたち　とは　たたかえないわ$"

