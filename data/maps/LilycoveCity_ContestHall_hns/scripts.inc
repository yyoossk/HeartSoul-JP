@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "この　ポケモンは　まえに\nここの　うつくしさコンテストで\lゆうしょう　したのよ\pそれが　なんと　きょうは\nかしこさコンテストでも\lゆうしょう　させたの！\pじぶんの　さいのうが\nこわい　くらいだわ‥$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "コンテストに　たくさん　でて\nだんだん　わかって　きたよ\pかっこよさコンテストなら\nかっこいい　わざが\lアピールに　なる\pでも　かしこい　わざや\nかわいい　わざは\lあまり　うけないんだ$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "さっき　ゆうしょう　した\nおにいさん　いろんな\l{POKEBLOCK}を　もってたよ\pあんなに　もってたら\nかてる　のかな？$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "うわあ　ここ　でっかいな！\pこの　きんちょうかん‥\nいなかの　コンテストかいじょう\lとは　ちがうね$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "しかい『かしこい　ポケモンと\nトレーナーの　みなさん\lじゅんびは　いいですか！\pせいいっぱい　がんばって！\nアピール　かいし！$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "しんさいん『コンテストは\nたのしんで　いますか？\pともだち　3にんと　くれば\nみんなで　コンテストに\lでられますよ！$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "あいたたた‥\nコンテストを　まちがえた\pこの　たくましい　ポケモンを\nかしこさコンテストに\lだしちゃった‥\pさあ　かしこそうな\nいわくだきで　みんなを\lうならせろ！$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "わしは　ながい　ねんげつと\nありったけの　ちえを　かけて\lこの　ポケモンを\lかしこく　そだてた\pわかぞうの　ポケモンに\nかんたんには　まけんぞ\pばあさんや　みて　おるか？$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "きた　きた！\pつぎに　かしこい　わざを\nきめれば　かんきゃくの\lもりあがりは　さいこうちょうだ！$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "ああ　そんな！\pわたしの　ズバットちゃんの\nきゅうけつが　かわいくて\lなんども　つかったのに！\pここの　ひとたち　ぜんぜん\nわかって　くれないの！$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "きゃー！\nおじいちゃん　すてき！$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "おなじ　しゅるいの　ポケモンでも\nトレーナーに　よって\lアピールの　わざが\lみんな　ちがうんだね\pバトルの　スタイルが\nひとに　よって　ちがうのと\lおなじだね$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "トレーナーより　ポケモンの\nほうが　ずっと　かしこそうに\lみえるな$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "なんだかんだ　いっても\nやっぱり　かしこさコンテストが\lすきだな\pあの　ちてきな　みどりいろ‥\nなんて‥　なんて‥\lかっこいいんだ$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "しかい『きみも　うつくしさ\nコンテストに　でるの？\lがんばってね！$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "しんさいん『ああ　どの　ポケモンも\nなんと　うつくしい！\pおもわず　さいてんを\nわすれる　ところでした！$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "こんなに　うつくしい\nポケモンは　ほかに　いないわ\pみんなの　めは　わたしの\nうつくしさに　くぎづけよ$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "うわーん！\pコンテストの　ために\nポケモンを　ていねいに\lブラッシング　したのに‥\pやりすぎちゃって‥\nけが　ボサボサに\lなっちゃった‥\pどう　しよう？$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "この　オーロラビームは\nまぶしすぎて　しんさいんにも\lみえない　くらいだ\pあれ　まてよ‥\nそれじゃ　いみ　ないじゃん！$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "この　きれいな　ポケモン\nわかい　ころの　わたしに\lそっくり\pそう　いったら　しゅじんが\nのんでた　コーヒーを\lふきだしたの\pなにか　おかしな　こと\nいったかしら？$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "うつくしさコンテストで\nかつと　やっぱり\lいつもより　うれしいのよね$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "わっはっはっは！\pみて　ごらん　きれいな\nポケモンが　いっぱいだ！\lこういう　はなやかなのが\lだいすき　なんだ！$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "うつくしさ　だけで\nかてるとは　かぎらない\pわたしの　ポケモン　みたいに\nつやつやに　ていれ\lしなくちゃね$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "しかい『あれれ！　こんにちは！\nいまは　コンテストちゅう　です！\pうけつけで　エントリー\nしてから　でて　きてね！$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "しんさいん『なんと　かわいい\nアピール　でしょう！\pまあ！　なんて　かわいい\nみずあそびの　アピール！$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "ああ‥　わたしの　ルリリが\nほかの　ポケモンに\lきを　とられちゃった$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "わたしの　ポケモンは　バトルで\nかった　ことは　ないけど\lコンテストなら　まかせて！$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "わたしの　ポケモンの\nはなびらのまいは\lゆうがさの　きわみ\pだれにも　じゃまは\nさせませんわ$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "みんなの　ポケモン\nとても　かわいいわね\pでも　わたしの　ポケモンが\nかわいい　アピールを\lしたら‥\pぜったい　だれよりも\nかわいいに　きまってるわ$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "うちの　こが　この\nコンテストに　でてるんです$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "がんばって！　いけー！\nあなたの　ポケモンが\lいちばんよ！$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "あそこの　おんなのこが\nいちばん　かわいいと　おもう\pえ？　ポケモンの　みためを\nしんさ　してるの？$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "かわいい　ポケモンを\nたくさん　みてたら\lじぶんも　ほしく　なった！\pつかまえに　いこう！$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "うつくしさコンテスト　ステージ\nうつくしい　ポケモンに　みとれよう！$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "かわいさコンテスト　ステージ\nかわいい　ポケモンに　めろめろ！$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "かしこさコンテスト　ステージ\nかしこい　ポケモンに　かんしん！$"

