Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition_Kj
	.byte 0

Route20_OnTransition_Kj::
	call_if_unset FLAG_KJ_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_KJ_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_KJ_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_KJ_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_KJ_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_KJ_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_KJ_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_KJ_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_KJ_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_KJ_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_KJ_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
	.string "とおあさに　なってる　から\n"
	.string "およいでる　ひとも　おおいよ！$"

Route20_Text_BarryDefeat::
	.string "うーみーッ！$"

Route20_Text_BarryPostBattle::
	.string "きみは　ポケモンに　のってて\n"
	.string "つかれ　ないから　いいなあ$"

Route20_Text_ShirleyIntro::
	.string "ふたごじまに\n"
	.string "リゾートに　きてるの　わたし$"

Route20_Text_ShirleyDefeat::
	.string "ちょっと　やめてよ$"

Route20_Text_ShirleyPostBattle::
	.string "ふたごじまの　ちかに\n"
	.string "しょうにゅうどうが　あるんだって$"

Route20_Text_TiffanyIntro::
	.string "なみまに　ぷかぷか　うかぶ\n"
	.string "…　あたしは　おさかな$"

Route20_Text_TiffanyDefeat::
	.string "うー　まんぼう！$"

Route20_Text_TiffanyPostBattle::
	.string "あなた　いっしょに\n"
	.string "…　ぷかぷか　しない？$"

Route20_Text_IreneIntro::
	.string "きみも　リゾートに　きてるの？$"

Route20_Text_IreneDefeat::
	.string "てかげん　なしね$"

Route20_Text_IrenePostBattle::
	.string "ふたごじまは　むかしは\n"
	.string "ふたつの　しま　だった　らしいね$"

Route20_Text_DeanIntro::
	.string "みよーッ！\n"
	.string "きたえ　あげた　この　からだ！$"

Route20_Text_DeanDefeat::
	.string "ふにゃふにゃだ$"

Route20_Text_DeanPostBattle::
	.string "じぶんの　からだ　より\n"
	.string "ポケモンを　きたえる　べきだった$"

Route20_Text_DarrinIntro::
	.string "ポケモンに　のってる　なんて\n"
	.string "もしかして　およげない　とか？$"

Route20_Text_DarrinDefeat::
	.string "うー　ぶくぶく$"

Route20_Text_DarrinPostBattle::
	.string "ポケモンに　のって　いくのも\n"
	.string "たのしそうだなあ$"

Route20_Text_RogerIntro::
	.string "とり　ポケモンに　つかまって\n"
	.string "ここまで　きたよ$"

Route20_Text_RogerDefeat::
	.string "あ！　こまったな$"

Route20_Text_RogerPostBattle::
	.string "とりが　へばちゃって　もどれないぞ\n"
	.string "…　どうしよう$"

Route20_Text_NoraIntro::
	.string "かれに\n"
	.string "おっきな　しんじゅ　もらったわ！$"

Route20_Text_NoraDefeat::
	.string "やーん！\n"
	.string "しんじゅ　いり　なのに…$"

Route20_Text_NoraPostBattle::
	.string "パルシェン　もっと　そだてたら\n"
	.string "しんじゅも　おっきく　なるかしら$"

Route20_Text_MissyIntro::
	.string "グレン　じま　から\n"
	.string "およいで　きたけど…　きついわ！$"

Route20_Text_MissyDefeat::
	.string "がっかり$"

Route20_Text_MissyPostBattle::
	.string "グレン　じまの\n"
	.string "だれも　すんでない　おやしき\l"
	.string "いつからか　ポケモンが　すみついて\l"
	.string "ポケモン　やしきと　よばれてる$"

Route20_Text_MelissaIntro::
	.string "にしに　ある　グレン　じまは\n"
	.string "ポケモン　けんきゅうの　しま！\l"
	.string "あそこで　パパも　はたらいてるわ$"

Route20_Text_MelissaDefeat::
	.string "まってよ　もう！$"

Route20_Text_MelissaPostBattle::
	.string "グレンは　かざんの　ふんかで\n"
	.string "もりあがって　できたって　きいたわ$"

Route20_Text_SeafoamIslands::
	.string "ふたごじま$"

Route20_Text_MistyTrainsHere::
	.string "この　あたりは\n"
	.string "つよい　トレーナーや\l"
	.string "みずポケモンが　おおいから\l"
	.string "ハナダシティの　カスミも\l"
	.string "しゅぎょうに　きていると　いうぜ$"
