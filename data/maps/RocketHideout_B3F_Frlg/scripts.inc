RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "あまり　ロケットだんの\n"
	.string "じゃまを　しない　ほうが\l"
	.string "みの　ため　だぜ！$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "くッ　やられた！$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "…　シルフスコープ？　ああ！\n"
	.string "ボスが　シルフ　カンパニーで\l"
	.string "ぬすんで　きた　マシンの　ことか！\l"
	.string "…　どこかに　ある　はず　だぜ$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "…　きたな？\n"
	.string "うえの　フロア　から\l"
	.string "れんらくが　きてるぜ！$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "まけた…　ばかな！$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "いく　なら　いって　みろ！\n"
	.string "しかし　エレベータは\l"
	.string "カギが　ないと　つかえないぜ！$"

