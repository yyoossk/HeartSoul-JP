SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_KJ_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_KJ_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "た　たすけて！\n"
	.string "わたしは　シルフ　しゃいん　です$"

SilphCo_2F_Text_ConnorDefeat::
	.string "く！　ばれたか$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "わたしは　シルフの　しゃいん\n"
	.string "であると　どうじに\l"
	.string "ロケットだんいん　でも　あるのさ$"

SilphCo_2F_Text_JerryIntro::
	.string "ここは　たちいり　きんしだ\n"
	.string "かえりなさい！$"

SilphCo_2F_Text_JerryDefeat::
	.string "なかなか…$"

SilphCo_2F_Text_JerryPostBattle::
	.string "ビルの　なかは　ふくざつだぞ\n"
	.string "きみに　こうりゃく　できるかな？$"

SilphCo_2F_Text_Grunt1Intro::
	.string "ここは　こどもの\n"
	.string "くる　ところ　じゃない！$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "つよい！$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "ひしがた　デザインの　ゆかは\n"
	.string "テレポート　ブロックだ！\p"
	.string "ハイテクな　ビルの　なかでの\n"
	.string "いどう　しゅだんだぜ$"

SilphCo_2F_Text_Grunt2Intro::
	.string "そこの　こども！\n"
	.string "うろうろ　するんじゃない！$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "ぐ！　しくじった$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "ロケットだんは\n"
	.string "シルフ　カンパニーと\l"
	.string "ていけい　するのだ！$"

Text_ThunderWaveTeach::
	.string "きゃあ！\n"
	.string "だめよ　たすけてー！\p"
	.string "…　あら？\n"
	.string "ロケットだん　じゃない\l"
	.string "ごめんなさい\l"
	.string "あたし　てっきり…\p"
	.string "でんじはの　わざを\n"
	.string "おしえたげる　から　ゆるしてね$"

Text_ThunderWaveDeclined::
	.string "でんじは　って　べんり　なのに$"

Text_ThunderWaveWhichMon::
	.string "どの　ポケモンに\n"
	.string "でんじはを　おぼえさせるの？$"

Text_ThunderWaveTaught::
	.string "でんじはを　つかうと\n"
	.string "あいての　ポケモンは　まひして\l"
	.string "わざが　でにくく　なるわ！\p"
	.string "でんきタイプの　わざ　だから\n"
	.string "きかない　あいても　いるわよ$"

SilphCo_2F_Text_FloorSign::
	.string "シルフ　カンパニー　ほんしゃ\n"
	.string "２かい$"

