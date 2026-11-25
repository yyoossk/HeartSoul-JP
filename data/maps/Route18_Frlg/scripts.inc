Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition_Kj
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition_Kj::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
	.string "こういう　くさむらを　みつけては\n"
	.string "あたらしい　ポケモン　いないか\l"
	.string "さがしてるのさ！$"

Route18_Text_WiltonDefeat::
	.string "あう…！$"

Route18_Text_WiltonPostBattle::
	.string "じてんしゃ　もって　いたら\n"
	.string "ぼくも　サイクリング　したい$"

Route18_Text_RamiroIntro::
	.string "クルック…ッ！\n"
	.string "どう？　ぼくの　ゆびぶえ！$"

Route18_Text_RamiroDefeat::
	.string "きじも　なかずば\n"
	.string "うたれまいに　って　ことか$"

Route18_Text_RamiroPostBattle::
	.string "うみが　ちかい　から\n"
	.string "しゅうまつは　うみどり　ポケモン\l"
	.string "つかまえに　くるよ$"

Route18_Text_JacobIntro::
	.string "この　あたりは\n"
	.string "ぼくらの　なわばりだ！\l"
	.string "ちかよらないで　ほしいな！$"

Route18_Text_JacobDefeat::
	.string "…　ふう！$"

Route18_Text_JacobPostBattle::
	.string "だれでも　おきにいりの\n"
	.string "ポケモンを　とりに　いく\l"
	.string "ばしょが　あるだろ！$"

Route18_Text_RouteSign::
	.string "ここは　１８ばん　どうろ\n"
	.string "タマムシ　…　セキチク$"

Route18_Text_CyclingRoadSign::
	.string "ここは　サイクリング　ロード\n"
	.string "あるいての　つうこう　きんし$"

