CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_KJ_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_KJ_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_KJ_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_KJ_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster_Kj::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave_Kj, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro_Kj::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign_Kj::
	msgbox CeruleanCity_Text_BikeShopSign_Kj, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign_Kj::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign_Kj
	releaseall
	end

CeruleanCity_Text_RivalIntro::
	.string "{RIVAL}“よう　{PLAYER}！\p"
	.string "こんな　とこ\n"
	.string "うろちょろ　してたのか！\p"
	.string "おれ　なんか　つよいの　すごいの\n"
	.string "いろいろ　つかまえ　ちゃって\l"
	.string "ぜっこうちょう　だぜ！\p"
	.string "…　どれどれ　{PLAYER}は\n"
	.string "なんか　つかまえた？\l"
	.string "みせて　みろよ！$"

CeruleanCity_Text_RivalDefeat::
	.string "なんだよー！\n"
	.string "ムキに　なっちゃって！\l"
	.string "…　わかった　わかった！$"

CeruleanCity_Text_RivalPostBattle::
	.string "{RIVAL}“へへーんッ！\p"
	.string "おれ　マサキの　うちに　いって\n"
	.string "めずらしい　ポケモン　たくさん\l"
	.string "みせて　もらっちゃった　もんね！\p"
	.string "おかげで　ポケモン　ずかんの\n"
	.string "ページが　ふえたぜ！\p"
	.string "なにしろ　マサキは　ゆうめいな\n"
	.string "ポケモン　マニア　だからな！\p"
	.string "パソコン　つうしんの\n"
	.string "ポケモン　あずかり　システム！\l"
	.string "あれも　マサキが　つくったんだぜ\p"
	.string "おまえも　つかってるんなら\n"
	.string "いちど　おれいに　いけば？\p"
	.string "おっと　みちくさ　くってる\n"
	.string "ばあい　じゃ　ないぜ！\l"
	.string "…　じゃな　バイビー！$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
	.string "そうそう！\p"
	.string "おれに　いつも　さき　こされて\n"
	.string "おまえも　かわいそー　だから\l"
	.string "これを　めぐんで　やるぜ！$"

CeruleanCity_Text_ExplainFameCheckerSmellYa::
	.string "うわさずきの　おまえには\n"
	.string "それが　ピッタリ　だぜ！\l"
	.string "おれさまは　たにん　なんかに\l"
	.string "きょうみ　ないからなー\p"
	.string "じゃな　こんどこそ　バイビー！$"

CeruleanCity_Text_GruntIntro::
	.string "あ　こら！\n"
	.string "ひとんちの　にわ　はいるなよ！\l"
	.string "……　……　え　おれ？\p"
	.string "……　ただの　とおり　すがりだ\n"
	.string "ぜーんぜん　あやしくないよ！\l"
	.string "……　……　あやしい？{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

CeruleanCity_Text_GruntDefeat::
	.string "だんいん“ひょえー　まいった！\n"
	.string "もう　しないよ！\l"
	.string "みのがして　くれい！$"

CeruleanCity_Text_OkayIllReturnStolenTM::
	.string "……　わかった！\n"
	.string "ぬすんだ　もの　かえすよ$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
	.string "{PLAYER}は　ロケットだんいんから\n"
	.string "わざマシン２８を　とりかえした！$"

CeruleanCity_Text_BetterGetMovingBye::
	.string "そ　それじゃ……！\n"
	.string "おれは　たいさん　するから！\l"
	.string "……　……　ばいばーい！$"

CeruleanCity_Text_MakeRoomForThisCantRun::
	.string "にもつが　いっぱいだ！\p"
	.string "……　これ　わたさないと\n"
	.string "おれ　にげられないよ！$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
	.string "きみも　ポケモン　やってるか！\n"
	.string "あつめたり　たたかったり\l"
	.string "いろいろ　たいへん　だな！$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
	.string "ほそい　きは　いあいぎりで\n"
	.string "きれるって　しってた？\p"
	.string "みせの　まえの　ほそいきも\n"
	.string "いあいぎりで　きれるんだよ！\p"
	.string "でも　どこか　まわりみち　すると\n"
	.string "いける　らしい　けど…$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
	.string "あの　ヤドランが　いなければ\n"
	.string "きを　きって\l"
	.string "むこうに　いけるのに…\p"
	.string "でも　どこか　まわりみち　すると\n"
	.string "いける　らしい　けど…$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
	.string "ほほう…！\n"
	.string "ポケモンの　ずかんを　つくってる？\l"
	.string "それは　たのしそう　だなあ！$"

CeruleanCity_Text_PeopleHereWereRobbed::
	.string "かわいそーな　ことに\p"
	.string "この　いえは\n"
	.string "ドロボーに　はいられたんだ！\l"
	.string "はんにんは　わかっとる！\l"
	.string "ロケットだんの　しわざだ！\p"
	.string "けいさつ　としても\n"
	.string "ロケットだんの　あくじ　には\l"
	.string "ほとほと　こまっとるのだ！$"

CeruleanCity_Text_SlowbroUseSonicboom::
	.string "さあ　ヤドラン！\n"
	.string "ソニック　ブーム　だすのよ！$"

CeruleanCity_Text_SlowbroPayAttention::
	.string "…やどらーん　ってば\l"
	.string "わたしの　いうこと　きいて！$"

CeruleanCity_Text_SlowbroPunch::
	.string "ヤドラン！　そこで　パーンチ！$"

CeruleanCity_Text_NoYouBlewItAgain::
	.string "…　がっくし　また　ダメ！$"

CeruleanCity_Text_SlowbroWithdraw::
	.string "ヤドラン！　からに　こもるの！$"

CeruleanCity_Text_HardToControlMonsObedience::
	.string "あん　…ちがーう！\l"
	.string "ポケモンって　むずかしいわ！\p"
	.string "ポケモンが\n"
	.string "いうこと　きくか　どうかは\l"
	.string "ひとの　うでまえ　しだい　なんだもの$"

CeruleanCity_Text_SlowbroTookSnooze::
	.string "ヤドランは　ひるね　してる…$"

CeruleanCity_Text_SlowbroLoafingAround::
	.string "ヤドランは　なまけてる…$"

CeruleanCity_Text_SlowbroTurnedAway::
	.string "ヤドランは　そっぽを　むいた！$"

CeruleanCity_Text_SlowbroIgnoredOrders::
	.string "ヤドランは　しらんぷり　した…$"

CeruleanCity_Text_WantBrightRedBicycle::
	.string "わたしも　じてんしゃ　ほしい！\n"
	.string "まっかな　じてんしゃ！\p"
	.string "それで　よごすの　いや　だから\n"
	.string "おうちに　かざるわ！$"

CeruleanCity_Text_ThisIsCeruleanCave_Kj::
	.string "ここは…　ハナダのどうくつ！\n"
	.string "こわい　ほど　つよい　ポケモンが\l"
	.string "せいそく　してるぞ！\p"
	.string "この　どうくつ　には\n"
	.string "ポケモン　リーグ　にんてい\l"
	.string "チャンピオンに　なれるほど　つよく\p"
	.string "また　いだいな　しごとを\n"
	.string "なしとげた　トレーナーしか\l"
	.string "はいれないのだ！$"

CeruleanCity_Text_CitySign::
	.string "ここは　ハナダシティ\n"
	.string "ハナダは　みずいろ　しんぴのいろ$"

CeruleanCity_Text_TrainerTipsHeldItems::
	.string "…　おとくな　けいじばん！\p"
	.string "ポケモンには　どうぐを\n"
	.string "もたせる　ことが　できます！\p"
	.string "どうぐを　もたせておくと\n"
	.string "ポケモンが　それを\l"
	.string "つかう　ことも　あります！$"

CeruleanCity_Text_BikeShopSign_Kj::
	.string "くさむらも　どうくつも　スイスイ！\n"
	.string "…　…　ミラクル・サイクル$"

CeruleanCity_Text_GymSign_Kj::
	.string "ハナダ　シティ　ポケモン　ジム\n"
	.string "リーダー　カスミ\l"
	.string "おてんば　にんぎょ$"

