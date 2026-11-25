SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_KJ_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_KJ_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign_Kj::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign_Kj::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign_Kj::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign_Kj
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign_Kj::
	msgbox SaffronCity_Text_SilphCoSign_Kj, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "なんだァ！\n"
	.string "てめえ！　あっち　いけ！$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "ボスは　この　まちを\n"
	.string "ロケットだんの　ものに　するってよォ$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "こらァ　おれたちに　さからうと\n"
	.string "いたい　めに　あうぞ！$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "ヤマブキ　シティ　ごと\n"
	.string "ロケットだんが　のっとったぜ！$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "わるい　こと　やりまくると\n"
	.string "スカッと　するぜ！$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "いてッ！　この　やろ！\n"
	.string "どこ　みて　あるいてんだよ！$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "シルフ　カンパニー　のっとったら\n"
	.string "せかい　じゅうに　ポケモン　うって\l"
	.string "ガバガバ　おお　もうけ　だぜ！$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "ロケットだん　やっつけたの\n"
	.string "たった　ひとり　だって…　すごいな$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "ばんざーい！\n"
	.string "ロケットだんが　いなくなった！\l"
	.string "ビビらないで　そと　あるけるんだ！$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "ヤマブキ　シティも　いちじは\n"
	.string "ひとが　にげて　へっちゃった　けど\l"
	.string "にぎやかな　まちに　もどるわ！$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "ロケットだんが　シルフ　おそって\n"
	.string "だいじけんって　きいて！\l"
	.string "ピジョットで　とんで　きたッス\p"
	.string "かいけつ　した…？\n"
	.string "すんません！\l"
	.string "ねっからの　ヤジウマ　で！$"

SaffronCity_Text_Pidgeot::
	.string "ピジョット“ビビーッ！$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "おれ　みたぜ！　シルフの　ビル　から\n"
	.string "ロケットの　ボスが　にげて　いくの！$"

SaffronCity_Text_ImASecurityGuard::
	.string "わたしは　けいびいんだが\n"
	.string "あやしい　こどもは\p"
	.string "とおせんぼ　することに　してるのだ$"

SaffronCity_Text_HesTakingASnooze::
	.string "…　…　…\n"
	.string "…こっくり　こっくり\p"
	.string "しめしめ！　いねむり　しているぞ$"

SaffronCity_Text_CitySign::
	.string "ここは　ヤマブキ　シティ\n"
	.string "ヤマブキ　きんいろ　かがやきのいろ$"

SaffronCity_Text_FightingDojo::
	.string "かくとう　どうじょう！$"

SaffronCity_Text_GymSign_Kj::
	.string "ヤマブキ　シティ　ポケモン　ジム\n"
	.string "リーダー　ナツメ\l"
	.string "エスパー　しょうじょ！$"

SaffronCity_Text_FullHealCuresStatus::
	.string "…　おとくな　けいじばん！\p"
	.string "なんでも　なおしは\n"
	.string "ねむり　どく　やけど　こおり…\l"
	.string "なんでも　なおします！\p"
	.string "すこし　たかい　けど\n"
	.string "ねむけざまし　どくけし　などを\l"
	.string "バラバラに　かうより　らくちん！$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "…　おとくな　けいじばん！\p"
	.string "しんせいひん　スーパーボールは\n"
	.string "モンスターボール　より　かくじつに\l"
	.string "ポケモンを　つかまえます！\p"
	.string "なかなか　つかまえ　られない\n"
	.string "ポケモンには　こちらを　ためそう！$"

SaffronCity_Text_SilphCoSign_Kj::
	.string "シルフ　カンパニー　ほんしゃ　ビル$"

SaffronCity_Text_MrPsychicsHouse::
	.string "エスパー　おやじの　いえ$"

SaffronCity_Text_SilphsLatestProduct::
	.string "シルフ　うわさの　しんせいひん！\n"
	.string "…　はつばいび　みてい$"

SaffronCity_Text_TrainerFanClubSign::
	.string "ポケモン　トレーナー　ファンクラブ\p"
	.string "かんばんに　いろんな　トレーナーの\n"
	.string "なまえが　らくがき　されている……$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "はなしの　あうひとが　ぜーんぜん\n"
	.string "いないわっ　この　ファンクラブ！\p"
	.string "せいぎかんが　つよくて\n"
	.string "ねっけつで　かっこよくて\l"
	.string "いちばん　すごい　ひと…！\p"
	.string "その　ワタルさまの　よさが\n"
	.string "わからない　なんて！　プンプン！$"

