BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "ここは　バトルドーム！\nむてきの　スーパースターへの\lみち！$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "ここは　バトルファクトリー！\nさいきょうの　ポケモンを\lさがせ！$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "ここは　バトルチューブ！\n3つの　みちから\lひとつを　えらべ！$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "ここは　バトルタワー\pトレーナーが　そだて　あげた\nポケモンで　かちぬきせんを\lおこなう　ところ$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "こんにちは　ふねに\nおのりですか？\lチケットを　はいけん　します$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER}は　チケットを\nもって　いない‥\pもうしわけ　ありません\pふねに　のるには　チケットが\nひつようです$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER}は\nチケットを　みせた\pはい　けっこうです！\pどちらへ　いかれますか？$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "カイナシティ　ですね！$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "ミナモシティ　ですね！$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "また　ごりよう　ください！$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "ふねに　のって　しゅっこうを\nおまち　ください$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "では　どちらへ\nいかれますか？$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "ともだちの　なかでは\nいちばん　つよいのに\lここでは‥　ぜんぜん\lだめだ！$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "バトルタワーに　いきたいのに\nバトルフロンティアの　ちずが\lあっても　みつからない\pここ　ひろすぎる！$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "ついたら　すぐ　ちょうせん\nしたかったのに\pとちゅうで　ふなよい\nしちゃって‥　うぷ‥$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "だれでも　ここに　これる\nわけじゃ　ないのよ？\pつよいと　みとめられた\nトレーナー　だけが\lつれて　こられるの\pだから　バトルフロンティアを\nしらない　トレーナーも\lおおいのよ$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "ねえ　にいちゃん‥\pポケモンを　もってなくても\nちょうせん　できるって\lほんと？$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "えっと‥\nだいじょうぶ　だと　おもう\pたぶん‥\pほら　あの　おおきくて\nこわい　ひと　いただろ？\lポケモンを　かして　やるって\lいってたぞ$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "あれは　バトルファクトリー\nつよい　ポケモンを\lかりられるんだ\pでも　ふしぎに　おもうよ\nレンタルの　ポケモンは\lだれが　そだててるんだろう？$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "ハブネークが　いるから\nバトルチューブに　はいるのが\lこわい‥\pで　でも　ここまで　きたから\nぜんぶ　せいは　するぞ！\l‥ぶるぶる‥$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "じゃんけん　しよう！\nじゃん　けん　ぽん！\p‥　‥　‥　‥　‥　‥$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "やった！　かった！\nバトルチューブに\lちょうせん　するぞ！$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "ああ‥\nまけた\pきょうは　ついて　ないな\nバトルチューブの　ちょうせんは\lあしたに　しよう$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "しょうぶより　つりを　えらぶ\nのは　なぜか　ここで\lわたし　だけ　だろうな\pえ？　ここでは　なにも\nつれない？　がっかりだ‥$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "きょうは　シンボルを\nもらうまで　なにが　あっても\lたたかい　つづけるぞ$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "おや？　バトルドームに\nちょうせん　するのかね？\pけんとうを　いのるよ\nおたがい　かちあがって\lあいまみえよう$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "おじいちゃん　こっち！\nバトルドームは　ここだよ！\lがんばって　おじいちゃん！$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "ほう　ここが　バトルドームか？\nジェントルマンには\lまけんぞ！\pじゃが　いりぐちは\nどこじゃ？$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "すこし　まえまで　ここには\nなにも　なかったんだ\pそれが　いまは　どうだ！\nすごい！　かあさんを\lつれて　きて　みせよう$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "ついに　バトルフロンティアに\nきたわ！\pわたしの　ルックスと　じつりょくで\nちゅうもくの　まとよ！$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "もぐもぐ‥\pこの　ひろばは　つよい\nひとで　いっぱい　みたいだ\pもぐもぐ‥$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
	.string "ぼりぼり　もぐもぐ‥\pまえに　バトルチューブで\nとしうえの　おんなのこに\lあったんだ\pめつきが　ものすごく\nこわかった\pぼりぼり　もぐもぐ‥\pたべるの　やめなさい！\nって　おこられて\lぼこぼこに　された\pほんとうに　ぞっと　する\nけいけん　だったよ\pぼりぼり　もぐもぐ‥$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "はあ？　なに　いってるの？\nそんなの　たいした　こと\lないわ！\pまえに　おうえん　した　ときなんか\nめが　あって　ひばなが\lちったのよ！$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "なんですってー？！\nふん！\pそれは　たまたま　わたしの\nとなりに　すわってた\lから　でしょ！\pドームスーパースターが　こっちを\nみたのは　わたしの　おうえんが\lおおきかった　からよ！$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "もう　うるさい！\nしずかに　して！\pにわかファンは　ジムリーダーでも\nおうえん　してなさい！\pドームスーパースターは　わたしの！\nわたし　だけの　アイドルよ！$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
	.string "あそこで　いいあらそって\nいる　ひとたち‥\pしんじられない　けど\nむかしは　うでの　いい\lトレーナー　だったんだ\pものすごく　つよくて\nゆうめい　だった\pでも　ある　たいかいで\nある　トレーナーに\lこてんぱんに　された\pあまりの　まけっぷりに\nその　トレーナーに\lほれこんで　しまった\pいまは　ただの　ファンさ\nまいにち　バトルドームへ\lアイドルの　おうえんに\lいってるよ$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "バトルフロンティアの　どこかで\nとても　ながい　しっぽの\lポケモンを　みたって\lうわさが　あるの\pきっと　かわいいに\nちがいないわ‥\pちょうせんは　あとで　いいわ\nその　かわいい　こを\lさがしたくて　たまらない！$"

