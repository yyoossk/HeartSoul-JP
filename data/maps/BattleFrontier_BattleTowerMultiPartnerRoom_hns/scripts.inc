BattleFrontier_BattleTowerMultiPartnerRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_hns::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR_HNS, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsEast_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsWest_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM_HNS, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns:
	.string "ここに　あつまった　トレーナーの\nなかから　パートナーを\lさがして　ください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns:
	.string "{PLAYER}さま　まだ　パートナーが\nみつかって　いません\pさがすのを　やめて\nうけつけに　もどりますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns:
	.string "では　ここに　あつまった\nトレーナーの　なかから\lパートナーを　さがして\lください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns::
	.string "パートナーが　きまりましたね\pそれでは　マルチバトルルームへ\nごあんない　いたします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro_hns::
	.string "ぼく　{STR_VAR_1}の　{STR_VAR_2}ばんめの\nでし　{STR_VAR_3}って　よんでね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1_hns::
	.string "{STR_VAR_1}の　アドバイスで\n{STR_VAR_2}の　{STR_VAR_3}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}を\nつれて　きたよ\pタッグを　くませて　ください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept_hns::
	.string "ありがとう！\nすぐに　うけつけ　してくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject_hns::
	.string "{PLAYER}と　タッグを\nくみたかったのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro_hns::
	.string "わたしは　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし\l{STR_VAR_3}と　もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1_hns::
	.string "{STR_VAR_1}の　アドバイスで\n{STR_VAR_2}の　{STR_VAR_3}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}を\nえらびました\pタッグを　くみましょう！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept_hns::
	.string "ありがとう　ございます！\nすぐ　うけつけを\lすませて　きます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject_hns::
	.string "{PLAYER}さんと　くめると\nおもって　いたのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro_hns::
	.string "あの　ぼく　{STR_VAR_3}です\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　です\pぐすっ‥\pごめんなさい！\nきんちょうで　なみだが‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1_hns::
	.string "{STR_VAR_3}の　アドバイスで\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}が\nいます\pぐすっ‥\nおねがい　くんで　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept_hns::
	.string "えっ　ほんと？　いいの？\nやった！　すごい！\lうおーん！\pあ‥　ごめんなさい‥\nうれしくて　なみだが‥\pすぐ　うけつけ　してきます\nどこにも　いかないでね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject_hns::
	.string "そ　そんな‥\nぐすっ‥　うわーん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro_hns::
	.string "やあ！　わたし　{STR_VAR_3}！\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　だよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1_hns::
	.string "{STR_VAR_3}　おすすめの　メンバー\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}\nいいでしょ？\pさあ　さあ！\nタッグを　くもうよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept_hns::
	.string "やった！　よし！\nじゃあ　うけつけ　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject_hns::
	.string "えー　なんで？\n{PLAYER}と　くみたかったのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro_hns::
	.string "わたしは　あの　ゆうめいな\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　{STR_VAR_3}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1_hns::
	.string "{STR_VAR_3}に　アドバイスを\nもらって　{STR_VAR_1}を\lつかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}の\nコンビ　なの\pタッグを　くんで\nくれませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept_hns::
	.string "ありがとう！\nすぐ　うけつけ　します！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject_hns::
	.string "{PLAYER}と　タッグを\nくめると　おもってたのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro_hns::
	.string "あの‥　はなしかけて\nくれて　ほんとうに\lうれしいです\pわたし　{STR_VAR_3}です\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　です‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1_hns::
	.string "{STR_VAR_3}に　アドバイスを\nもらいました　とても\lかんしゃ　しています\pチームは　{STR_VAR_1}の\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}です\nむりな　おねがい　ですが‥\pだめ　だと　おもいますけど\nパートナーに　して\lもらえますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept_hns::
	.string "ほんとうに？　しんじられない！\nわたしと　くんで　くれるなんて！\lき　きたいに　こたえます！\pあの‥　ほんとうに　いいなら\nいますぐ　うけつけ\lしてきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject_hns::
	.string "ああ‥\nやっぱり　わたしじゃ\lだめ　ですよね‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro_hns::
	.string "やあ　ぼく　{STR_VAR_3}\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　さ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1_hns::
	.string "{STR_VAR_3}が　この　チームが\nいいって　いったんだ\l{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかえる\n{STR_VAR_2}\pわるくない　だろ？\nタッグを　くんで　やろうか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept_hns::
	.string "よし　くんで　やるよ！\nあしを　ひっぱるなよ！\lうけつけ　してくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject_hns::
	.string "え？　なんで　ことわるの？\nひとを　みる　めが\lないなあ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro_hns::
	.string "わたしは　{STR_VAR_3}\nトライアスロンを　やってるの\lジョギングに　トレーニングに\lラップで　まいにち\lいそがしいの\pそれと　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし　なの$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1_hns::
	.string "{STR_VAR_3}の　おすすめは　これ\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかう\n{STR_VAR_2}\pいそがしいけど　がんばって\nそだてたのよ\pタッグを　くんで\nやって　みましょう！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept_hns::
	.string "ありがとう　その　いき！\nうけつけ　してくるから\lまっててね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject_hns::
	.string "いそがしい　なか　きたのに！\nかんべん　してよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro_hns::
	.string "やあ！\nげんき？\pわたし　{STR_VAR_3}　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし！\lよろしくね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1_hns::
	.string "きいて　きいて！　{STR_VAR_3}　おすすめの\nポケモンは　ね\l{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\nもちろん　ばっちり　そだてたよ！\pタッグ　くまない？\nきっと　いい　コンビに　なるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept_hns::
	.string "やった　たのしく　なりそう！\nうけつけ　してくる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject_hns::
	.string "もう　いじわる！\nわたし　おすみつき　なのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro_hns::
	.string "じこしょうかい　させて\nください　わたしは　{STR_VAR_3}\p{STR_VAR_1}の　{STR_VAR_2}ばんめの\nでし　です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1_hns::
	.string "{STR_VAR_3}の　アドバイスを　うけ\nそだてた　チームは\l{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}です\pどうか　タッグを\nくんで　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept_hns::
	.string "まあ‥　うれしい！\nぜんりょくを　つくします！\pうけつけは　わたしが！\nおまち　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject_hns::
	.string "{PLAYER}さんと　くめると\nおもって　いたのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro_hns::
	.string "きゃっ！　はなしかけて\nくれた！　う　うれしい！\pわたし　{STR_VAR_3}！　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1_hns::
	.string "{STR_VAR_3}の　アドバイスで\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかう\n{STR_VAR_2}を　そだてたの\pおねがい　かなえて！\nあなたの　パートナーに\lなりたいの！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept_hns::
	.string "きゃっ！　ふわふわ\nしちゃう！　ありがとう！\lすぐ　うけつけ　してくる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject_hns::
	.string "うわーん！　ひどい！\nでも　そこが　かっこいい‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro_hns::
	.string "ひゃっほう！　おれは　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし！\pなまえは　{STR_VAR_3}\nよろしく　よろしく！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1_hns::
	.string "ししょうの　{STR_VAR_3}の　おすすめ\n{STR_VAR_1}　めいじんの　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask_hns::
	.string "{STR_VAR_1}　めいじんの\n{STR_VAR_2}\pいい　だろ？\nパートナーに　なって\lくれるよな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept_hns::
	.string "よし　さいこう！\nすぐ　うけつけ　してくる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject_hns::
	.string "ぐわーっ！\n{PLAYER}は　ださんてきだな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro_hns::
	.string "たいへん！　きょうで\nバトルタワーは　おしまい！\p‥　‥　‥　‥　‥　‥\nなーんて　じょうだん！\pみんな　{STR_VAR_3}って　よぶよ！\n{STR_VAR_1}の　1000ばんめの　でし！\lほんとは　{STR_VAR_2}ばんめ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1_hns::
	.string "{STR_VAR_3}に　アドバイス　もらったの\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\nそれぞれ　10ぴき　いるよ！\lほんとは　1ぴきずつ！\pどう？\nいっしょに　タッグバトル\lしない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept_hns::
	.string "やったー！\nおれいに　ポケモン　あげる！\pじょうだん！　でも　うけつけは\nほんとに　してくるね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject_hns::
	.string "つめたーい！　バトルタワーを\nこわしちゃうぞ！\pもちろん　しないけど！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro_hns::
	.string "ヘイ　おれは　ノリノリ！\nポケモン　あやつる　バリバリ！\pラップ　する　ふなのり　{STR_VAR_3}！\nなきむしと　まちがえる　な！\p{STR_VAR_1}の　{STR_VAR_2}ばんめの　でし！\nみくびる　な　この　おれっち！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1_hns::
	.string "{STR_VAR_3}の　アドバイス　まもって\nじまんの　チーム　つくって！\l{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかう\n{STR_VAR_2}！\pであいを　きねんに\nタッグで　しょうりを　いわおう！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept_hns::
	.string "ヘイ　ヘイ　きにいった　ぜ！\nうけつけ　いって　くる　ぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject_hns::
	.string "おいおい　{PLAYER}　つめたい　ぜ！\nいわせて　もらえば　の　はなし　さ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro_hns::
	.string "いやっほー！\nにげないで！　ふざけた　だけ！\pやあ！　わたし　{STR_VAR_3}！\n{STR_VAR_1}の　{STR_VAR_2}ばんめの　でし！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1_hns::
	.string "{STR_VAR_3}に　いわれた　とおり\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかう\n{STR_VAR_2}を　えらんだの\pどう？\nいい　へんじ　ちょうだい！\pおねがい！\nなかまに　いれて！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept_hns::
	.string "いえーい！　ついてる！\nうれしい！\pたたかう　まえに\nすぐ　うけつけ　してくる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject_hns::
	.string "ことわるの？\n{PLAYER}　かなしく　なっちゃう！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro_hns::
	.string "ごほっ！\pあ　ごめん　かぜ　なんだ\nポケモンは　げんき　だけど\pぼく　{STR_VAR_3}　{STR_VAR_1}の\n{STR_VAR_2}ばんめの　でし　ごほっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1_hns::
	.string "{STR_VAR_3}の　アドバイスを　まもって\nつくった　チームは\l{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}\pかぜの　ひも　あめの　ひも\nまいにち　きたえたんだ\pだから　かぜを\nひいたのかも\pそんな　ぼくだけど\nパートナーに　なる？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept_hns::
	.string "ありがとう　たすかるよ！\nごほっ　ごほっ！\lうけつけ　してくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject_hns::
	.string "だめ？\n{PLAYER}とは　いい　コンビに\lなれると　おもうのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro_hns::
	.string "あ　こんにちは！\nきんちょう　しちゃう\pわたし　{STR_VAR_3}\n{STR_VAR_1}の　{STR_VAR_2}ばんめの\lでし　です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1_hns::
	.string "{STR_VAR_3}が　いいって　いった　チーム\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}です\pはずかしい　けど\nいっしょに　くんで\lくれますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept_hns::
	.string "わあ　ありがとう！\nてれるけど　がんばります！\pうけつけ　してきます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject_hns::
	.string "ことわらないで！\nただでさえ　はずかしいのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro_hns::
	.string "わたしは　{STR_VAR_3}　うそでは\nない　{STR_VAR_1}の\l{STR_VAR_2}ばんめの　でしだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1_hns::
	.string "{STR_VAR_3}が　すすめた　チームだ\pせいじつな　アドバイスに\nきこえたので　つれてきた\l{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pできれば　タッグの\nパートナーと　して\lみとめて　ほしい$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept_hns::
	.string "ほんとうに　みとめて\nくれるのか？\lでなければ　こまる　ところだ\pだが　しょうち　して　くれた\nなら　よし　ふたりぶん\lうけつけ　してこよう$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject_hns::
	.string "む？　なぜ　ことわる？\nじょうだん　かね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro_hns::
	.string "わたし　ミニスカートの\n{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1_hns::
	.string "つれてるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pパートナーに　なって\nくれる？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept_hns::
	.string "ありがとう！\nうけつけ　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject_hns::
	.string "パートナーに　ならないの？\nあとで　こうかい　するわよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro_hns::
	.string "こんにちは！\pぼく　たんぱんこぞうの\n{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1_hns::
	.string "なにが　いるか　しりたい？\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\pタッグの　パートナーに\nなって　くれるよね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept_hns::
	.string "やった！\nうけつけ　してくるね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject_hns::
	.string "えー！　ぼくの　ポケモンと\nくめば　むてき　なのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro_hns::
	.string "やっほー！\nやまおとこの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1_hns::
	.string "なにを　つれてるか\nしってるか？\l{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ！\pいい　だろ？\nタッグを　くまないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept_hns::
	.string "やっほー！\nじゃあ　うけつけ　してくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject_hns::
	.string "きみと　ならんで\nたたかいたかったな$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro_hns::
	.string "こんにちは！\nおとなの　おねえさんの\l{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1_hns::
	.string "なにを　そだてて　いるか\nわかる？\l{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\pどう　かしら？\nいっしょに　タッグを\lくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept_hns::
	.string "すてき！\nすぐ　うけつけ　するわ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject_hns::
	.string "ざんねん！\pわたしたち　ふたり　なら\nさいこう　だったのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro_hns::
	.string "よう！\pおれを　しってるか？\nつりびとの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1_hns::
	.string "おれの　チームは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pどうだ？\nおれと　ならんで　たたかうか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept_hns::
	.string "よし　よし！\nおれに　まかせろ！\pうけつけ　してくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject_hns::
	.string "あいしょう　ぴったり\nだったのに‥$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro_hns::
	.string "おめに　かかれて　うれしいわ\nわたくし　おじょうさまの\l{STR_VAR_1}と　もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1_hns::
	.string "わたくしの　チームは\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}です\pおきに　めして　いただけたら\nパートナーに　なって\lほしいのです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept_hns::
	.string "こころから　かんしゃ\nいたします\lうけつけは　わたくしが$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject_hns::
	.string "わたくしを　えらばなかった\nこと　きっと　こうかい\lなさいますわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro_hns::
	.string "トライアスロンの\n{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1_hns::
	.string "つれてるのは‥\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\nこの　コンビよ！\pおねがい！\nタッグを　くんで　くれる？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept_hns::
	.string "わあ　ありがとう！\nカウンターで　うけつけ\lしてくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject_hns::
	.string "わたしたち　ふたり　なら\nぜったい　つよかったのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro_hns::
	.string "やあ！\nむしとりしょうねんの\l{STR_VAR_1}だよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1_hns::
	.string "ぼくの　ポケモン　みてよ！\n{STR_VAR_1}の　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask_hns::
	.string "{STR_VAR_1}の　{STR_VAR_2}！\pねえ　きいて！\nタッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept_hns::
	.string "わかった！\pカウンターで　うけつけ\nしてくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject_hns::
	.string "ちぇっ　ぼくの　ポケモン\nすごいのに　こうかい\lしないでよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro_hns::
	.string "ごきげんよう！\nじゅくがえりの\l{STR_VAR_1}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1_hns::
	.string "そだてて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう\n{STR_VAR_2}です\pわるくない　でしょう？\nタッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept_hns::
	.string "ありがとう　ございます！\nうけつけを　すませて\lきます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro_hns::
	.string "こんにちは！\nおぼっちゃまの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro_hns::
	.string "こんにちは！\nからておうの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro_hns::
	.string "こんにちは！\nうきわガールの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro_hns::
	.string "こんにちは！\nオカルトマニアの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro_hns::
	.string "こんにちは！\nポケモンブリーダーの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro_hns::
	.string "こんにちは！\nトライアスロンの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro_hns::
	.string "こんにちは！\nトライアスロンの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro_hns::
	.string "こんにちは！\nバトルガールの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro_hns::
	.string "こんにちは！\nトライアスロンの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro_hns::
	.string "こんにちは！\nうきわボーイの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro_hns::
	.string "こんにちは！\nギタリストの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro_hns::
	.string "こんにちは！\nジェントルマンの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro_hns::
	.string "こんにちは！\nだいすきクラブの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro_hns::
	.string "こんにちは！\nたつじんの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro_hns::
	.string "こんにちは！\nたつじんの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro_hns::
	.string "こんにちは！\nドラゴンつかいの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro_hns::
	.string "こんにちは！\nとりつかいの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro_hns::
	.string "こんにちは！\nにんじゃごっこの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro_hns::
	.string "こんにちは！\nパラソルおねえさんの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro_hns::
	.string "こんにちは！\nむしマニアの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro_hns::
	.string "こんにちは！\nふなのりの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro_hns::
	.string "こんにちは！\nコレクターの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro_hns::
	.string "こんにちは！\nポケモンレンジャーの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro_hns::
	.string "こんにちは！\nポケモンレンジャーの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro_hns::
	.string "こんにちは！\nアロマなおねえさんの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro_hns::
	.string "こんにちは！\nいせきマニアの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro_hns::
	.string "こんにちは！\nエリートトレーナーの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro_hns::
	.string "こんにちは！\nエリートトレーナーの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro_hns::
	.string "こんにちは！\nポケマニアの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro_hns::
	.string "こんにちは！\nひふきやろうの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro_hns::
	.string "こんにちは！\nキャンプボーイの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro_hns::
	.string "こんにちは！\nピクニックガールの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro_hns::
	.string "こんにちは！\nサイキッカーの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro_hns::
	.string "こんにちは！\nサイキッカーの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro_hns::
	.string "こんにちは！\nじゅくがえりの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro_hns::
	.string "こんにちは！\nポケモンブリーダーの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro_hns::
	.string "こんにちは！\nだいすきクラブの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro_hns::
	.string "こんにちは！\nビキニのおねえさんの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro_hns::
	.string "こんにちは！\nトライアスロンの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro_hns::
	.string "こんにちは！\nトライアスロンの　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro_hns::
	.string "こんにちは！\nかいパンやろうの　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1_hns::
	.string "つれて　いるのは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask_hns::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ\pいっしょに　タッグを\nくまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept_hns::
	.string "ありがとう！\nすぐ　うけつけ　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject_hns::
	.string "ざんねん‥\nいい　コンビに　なれたのに$"

