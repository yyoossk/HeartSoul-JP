BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "ここは　バトルドーム！\nむてきの　スーパースターへの\lみち！$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "ここは　バトルファクトリー！\nさいきょうの　ポケモンを\lさがせ！$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "ここは　バトルチューブ！\n3つの　みちから　ひとつを\lえらべ！$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "こんにちは　フェリーに\nごじょうせん　ですか？\lチケットを　はいけん\lします$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER}は　チケットを\nもって　いない‥\pまことに　もうしわけ\nございません\pフェリーに　のるには\nチケットが　ひつよう　です$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER}は　チケットを\nみせた\pけっこう　です！\nそれで　だいじょうぶ！\pどちらへ　いかれますか？$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "では　カイナシティ　ですね！$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "では　ミナモシティ　ですね！$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "また　ごりよう\nください！$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "フェリーに　のって\nしゅっぱつを　おまち\lください$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "では　どちらへ\nいかれますか？$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "ともだちの　なかでは\nいちばん　なのに\lここでは‥\lぜんぜん　だめ　だった！$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "ついたら　すぐ\nちょうせん　したかった\pでも　とちゅうで\nふなよい　しちゃって‥\lうっぷ‥$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "ここには　だれでも\nこられる　わけじゃ\lないのよ\pつよいと　みとめられた\nトレーナー　だけが\lつれて　こられるの\pだから　バトルフロンティアを\nしらない　トレーナーも\lおおいのよ$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "ねえ　にいちゃん‥\pポケモンを　もって\nなくても　ちょうせん\lできるのかな？$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "えっと‥\nきっと　だいじょうぶ\pたぶん‥\pでも　あの　おおきくて\nこわい　ひと　おぼえてる？\p「ポケモンを　かして　やる！」\nって　いってたよね$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "あれは　バトルファクトリー\nつよい　ポケモンを\lかりられるんだ\pでも　ふしぎに　おもうんだ\nあの　レンタルポケモンは\lだれが　そだててるんだろう？$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "サビパーが　こわくて\nバトルチューブに\lはいれないよ‥\pで　でも　せっかく　ここまで\nきたんだから　ぜんぶ\lせいは　するぞ！\l‥ぶるぶる‥$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "じゃんけん　しよう！\nじゃんけん　ぽん！\p‥　‥　‥　‥　‥　‥$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "やった！　かった！\nバトルチューブに\lちょうせん　する！$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "ああ‥\nまけちゃった\pきょうは　ついて\nないみたい\lバトルチューブは\lあしたに　しよう$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "ここで　バトルより\nつりを　えらぶのは\lたぶん　わたしだけ\lでしょうね\pえ？　ここでは　なにも\nつれない？\pそれは　ざんねん‥$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "きょうは　シンボルを\nもらうまで　なにが\lあっても　たたかいつづけるぞ$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "おや？　バトルドームに\nちょうせん　するのかい？\pうんを　いのって　いるよ\nおたがい　かちあがって\lちょうせんで　あおう$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "ほう　ここが\nバトルドームか？\lジェントルマンには\lまけないわよ！\pでも　いりぐちは\nどこ　かしら？$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "ちょっと　まえまで\nここには　なにも\lなかったんだ\pでも　いまは　どう！\nすごい！\lかあちゃんを　つれて　こよう$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "やっと　バトルフロンティアに\nついたわ！\pこの　ルックスと　じつりょく\nなら　ちゅうもくの\lまとに　なるはず！$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "もぐもぐ‥\pこの　ひろば　つよい\nひとで　いっぱい\lみたい\pもぐもぐ‥$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "ぼりぼり‥\pまえに　バトルチューブで\nおねえさんに　あったんだ\pすごく　こわい　めつき\nだった\pぼりぼり‥\p「たべるの　やめなさい！」\nって　おこられて\lぶたれたんだ\pほんとうに　ぞっと\nする　ような\lこわい　けいけん　だった\pぼりぼり‥$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "はあ？　なに\nいってるの？\lそんなの　たいした\lことないわよ！\pわたしが　このまえ\nおうえん　したら\lめと　めが　あって\lひばなが　ちったのよ！$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "なんですってー？！\nふん！\pそれは　たまたま　あなたの\nとなりに　すわってた\lから　でしょ！\pドームスーパースターが\nこっちを　みたのは　わたしの\lおうえんが　おおきかった\lから　よ！$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "ちょっと　しずかに　して！\nうるさいわね！\pにわかファンは\nジムリーダーでも\lおうえん　してなさい！\pドームスーパースターは\nわたしの　もの！\lわたしだけの　アイドル！$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "あそこで　いいあらそってる\nひとたち‥\pしんじられない　だろうけど\nむかしは　トレーナーで\lしかも　つよかったのよ\pすごく　つよくて\nゆうめい　だったの\pでも　トーナメントで\nある　トレーナーに\lこてんぱんに　やられてね\pあまりにも　みごとに\nまけたから　その\lトレーナーに　ほれこんで\lしまったの\pいまでは　その　トレーナーの\nファンで　まいにち\lバトルドームへ\lおうえんに　いってるの$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "バトルフロンティアの\nどこかで　しっぽが\lとても　ながい　ポケモンを\lみた　ひとが　いるって\pきっと　かわいいに\nちがいないわ‥\pちょうせんは　あとで　いいわ\nその　すてきな　いきものを\lさがしに　いかなくちゃ！$"

