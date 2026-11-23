BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "‥なんの　ようだ？\pいま　いそがしいの\nわからないか？\lあとに　して　くれないか？$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "‥ん？\nきみ　つよそうな\lトレーナーだね\pへへ‥\nちょっと　はなしが\lあるんだけど\pおれたちは　ここで\nバトルフロンティアを\lつかった　ちょっとした\lゲームを　してるんだ\pルールは　かんたん\pまず　バトルフロンティアの\nしせつを　ひとつ　えらぶ\pそれから　その　しせつに\nちょうせん　する\lトレーナーを　それぞれ\lえらんで　バトルポイントを\lかけるんだ\pいちばん　いい　きろくを\nだした　トレーナーに\lかけた　やつが　ポイントを\lぜんぶ　もらえる\pかんたん　だろ？\nそれでさ‥$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "さがして　いるのは\nバトルタワーの　シングル\lバトルルームに　いどむ\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "さがして　いるのは\nバトルタワーの　ダブル\lバトルルームに　いどむ\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "さがして　いるのは\nバトルタワーの　マルチ\lバトルルームに　いどむ\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "さがして　いるのは\nバトルドームの　シングル\lトーナメントに　でる\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "さがして　いるのは\nバトルドームの　ダブル\lトーナメントに　でる\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "さがして　いるのは\nバトルファクトリーの\lレンタルバトル　シングルに\lでる　トレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "さがして　いるのは\nバトルファクトリーの\lレンタルバトル　ダブルに\lでる　トレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "さがして　いるのは\nバトルパレスの　シングル\lバトルホールに　いどむ\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "さがして　いるのは\nバトルパレスの　ダブル\lバトルホールに　いどむ\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "さがして　いるのは\nバトルアリーナの\lセットKOトーナメントに\lでる　トレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "さがして　いるのは\nバトルチューブに　でる\lトレーナーだ\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけないね$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "わたしが　さがして　いるのは\nバトルピラミッドの\lバトルクエストに　でる\lトレーナー　です\pでも　いまの　ところ\nかちそうな　トレーナーは\lみかけませんね$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "きみにも　ちゃんと\nとくを　させるよ\lどうだい？\lおれの　かわりに\lでて　くれないか？$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "よし　かんぺきだ\nそれで‥　バトルポイントを\lすこし　かして　くれない？\pあとで　ちゃんと\nおれいは　するからさ$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "いいね　いいね！\nで　いくら　かして\lくれる？$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "だめ　だめ　だめ！\nバトルポイントが\lたりないじゃないか！\pふざけて　みんなの\nじかんを　むだに\lしないで　くれよ！$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "へへっ！　ありがとう！\nさあ　いって　こい！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "すぐに　バトルタワーの\nシングルバトルルームへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "すぐに　バトルタワーの\nダブルバトルルームへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "すぐに　バトルタワーの\nマルチバトルルームへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "すぐに　バトルドームの\nシングルトーナメントへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "すぐに　バトルドームの\nダブルトーナメントへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "すぐに　バトルファクトリーの\nレンタルバトル　シングルへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "すぐに　バトルファクトリーの\nレンタルバトル　ダブルへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "すぐに　バトルパレスの\nシングルバトルホールへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "すぐに　バトルパレスの\nダブルバトルホールへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "すぐに　バトルアリーナの\nセットKOトーナメントへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "すぐに　バトルチューブへ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "すぐに　バトルピラミッドの\nバトルクエストへ　いって　くれ！\pぜったいに　かたないと\nいけない！　チャンスを\lのがすな！\lおれたちの　みらいが\lかかってるんだ！$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "ああ　きみか‥\nおしかったね‥\pわるいけど　バトルポイントは\nかえせないんだ‥\pつぎは　もっと　がんばろう\nって　ことで！$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "おお　やった！\nよう　チャンピオン！\pきみなら　やると\nおもってたよ！\lふたりとも　おおかちだ！\pバトルポイントを　かえすよ\nもちろん　おれから\lおまけ　つきでね！$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER}は　バトルポイントを\n{STR_VAR_1}ポイント　もらった$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "また　ちょうせん　する\nきに　なったら\lおれを　おもいだしてくれ！$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "きょうみ　ない？！\nもっと　ゆうきを　だして\lかけて　みなよ！$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "また　かける　トレーナーを\nまちがえた！\pみんなと　おなじように\nふつうに　バトル　した\lほうが　いいかな‥$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "あの　トレーナー‥\pつよいけど　すぐ　あせるから\nバトルドームでは\lかちのこれないな‥$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "うふふ！\nかつ　ひとは　みれば\lわかるのさ！$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "あの　トレーナーたち‥\nなにを　してるんだ？\lちょうせん　すれば　いいのに$"
