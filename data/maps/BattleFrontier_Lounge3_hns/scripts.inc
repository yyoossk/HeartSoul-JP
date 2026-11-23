BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "‥なんの　ようだ？\pいそがしいのが\nわからないのか？\lあとに　して　くれ$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "‥ん？\nおまえ　つよそうな\lトレーナー　だな\pへへへ‥\nいい　はなしが　あるんだ\pおれたちは　ここで　バトル\nフロンティアの　しょうぶを\lネタに　ちょっとした\lゲームを　してるんだ\pルールは　かんたんだ\pまず　バトルフロンティアの\nしせつを　ひとつ　えらぶ\pそれから　その　しせつに\nちょうせん　する　トレーナーを\lそれぞれ　えらんで\lバトルポイントを　かける\pいちばん　いい　きろくの\nトレーナーに　かけた　やつが\lバトルポイントを　ぜんぶ\lもらう\pかんたん　だろ？\nそれで　だ‥$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "おれが　さがしてるのは　バトル\nタワーの　シングルバトルルームに\lちょうせん　する　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "おれが　さがしてるのは　バトル\nタワーの　ダブルバトルルームに\lちょうせん　する　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "おれが　さがしてるのは　バトル\nタワーの　マルチバトルルームに\lちょうせん　する　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "おれが　さがしてるのは　バトル\nドームの　シングルトーナメントに\lでる　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "おれが　さがしてるのは　バトル\nドームの　ダブルトーナメントに\lでる　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "おれが　さがしてるのは　バトル\nファクトリーの　シングルの\lこうかんバトルに　でる\lトレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "おれが　さがしてるのは　バトル\nファクトリーの　ダブルの\lこうかんバトルに　でる\lトレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "おれが　さがしてるのは　バトル\nパレスの　シングルバトルホールに\lちょうせん　する　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "おれが　さがしてるのは　バトル\nパレスの　ダブルバトルホールに\lちょうせん　する　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "おれが　さがしてるのは　バトル\nアリーナの　3たいけつ\lトーナメントに　でる\lトレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "おれが　さがしてるのは　バトル\nチューブの　みちえらびバトルに\lでる　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "おれが　さがしてるのは　バトル\nピラミッドの　バトルクエストに\lでる　トレーナーだ\pでも　まだ　かてそうな\nトレーナーが　みつからない$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "おまえにも　いい　おもいを\nさせて　やるよ　どうだ？\lおれの　かわりに\lでて　くれないか？$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "よし　ばっちりだ\nそれで‥　バトルポイントを\lすこし　かして　くれないか？\pあとで　ちゃんと\nおれいは　するから$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "いいね　いいね！\nで　いくら　かして\lくれる？$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "おいおい　だめだ！\nバトルポイントが\lたりないぞ！\pふざけて　みんなの　じかんを\nむだに　しないで　くれ！$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "へへっ！　ありがとよ！\nさあ　いって　こい！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "バトルタワーの　シングル\nバトルルームへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "バトルタワーの　ダブル\nバトルルームへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "バトルタワーの　マルチ\nバトルルームへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "バトルドームの　シングル\nトーナメントへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "バトルドームの　ダブル\nトーナメントへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "バトルファクトリーの　シングルの\nこうかんバトルへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "バトルファクトリーの　ダブルの\nこうかんバトルへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "バトルパレスの　シングル\nバトルホールへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "バトルパレスの　ダブル\nバトルホールへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "バトルアリーナの　3たいけつ\nトーナメントへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "バトルチューブの　みちえらび\nバトルへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "バトルピラミッドの　バトル\nクエストへ　いそげ！\pぜったい　まけられない！\nチャンスを　むだに　するな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "ああ　おまえか‥\nおしかったな‥\pわるいけど　バトルポイントは\nかえせないんだ‥\pつぎは　もっと　がんばろうって\nことで　ひとつ！$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "おお　やった！\nよう　チャンピオン！\pおまえなら　やれると\nしんじてたぜ！\lふたりとも　おおもうけだ！\pバトルポイントは　かえすぜ\nもちろん　おれからの\lおまけも　つけてな！$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER}は\nバトルポイントを\l{STR_VAR_1}ポイント　もらった！$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "また　ちょうせん　する\nきに　なったら\lおれの　ことを　おもいだしてくれ！$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "きょうみ　ないだと？\nそんなに　びびる　ことは\lないだろ！$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "あ‥$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "また　はずれの　トレーナーに\nかけちまった！\pおれも　みんなみたいに\nふつうに　バトル　したほうが\lいいのかな‥$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "あの　トレーナー‥\pうでは　いいけど\nすぐ　あせるから\lバトルドームでは\lかちのこれないな‥$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "うふふ！\nかつ　ひとは　みれば\lわかるのよ！$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "あの　トレーナーたち‥\nなに　してるの　かしら？\lちょうせん　すれば\lいいのに$"
