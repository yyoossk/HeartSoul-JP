BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "ここは　バトルタワー！\nさいきょうの　トレーナーとして\lれんしょうを　つづけろ！$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "ここは　バトルパレス！\nポケモンの　バトルから\lめを　はなすな！$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "ここは　バトルアリーナ！\nさいきょうの　チームよ\lあつまれ！$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "ここは　バトルピラミッド！\nバトルクエストを　すすめ！$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "バトルフロンティア\nランキングホール\lあたらしい　きろくを\lめざせ！$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "バトルポイント\nこうかんサービス　カウンター\lバトルポイントを　こうかん！$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "わあ！\nおっきい！\pバトルタワーって　とくべつな\nかんじ　ほかと　ちがうね$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "ぼくの　おおきな　ゆめは\nバトルフロンティアと\lポケモンリーグを\lせいは　する　こと\pそして　ゆめが　かなったら‥\pぼ‥　ぼく　となりの　ミミちゃんに\nともだちに　なってって\lいうんだ！$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "バトルピラミッドは　きびしすぎる！\nてっぺんまで　いけないよ！\pこう　なったら　そとがわを\nのぼって　みようかな‥$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "わたしは　くらやみで\nいきる‥　そう‥\lわたしに　ふさわしいのは\lバトルピラミッド　だけ‥\pくらやみの　なかを\nぜつぼうと　ともに\lさまよう　のは\lいかが　かな？$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "1しゅうかん　ねないで\nさいきょうの　チームを\lつくったんだ！\pまける　きが　しない\nじょうだん　ぬきで\lバトルアリーナに\lのりこむぞ！$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "あんたも　スコットに\nつれて　こられたの？\lあの　ひと　なんなの？\pつよい　トレーナーを\nみぬく　めは　ほんもの\lみたい　だけど‥\pあの　ひとが　じっさいに\nバトル　してるのは\lみた　ことが　ないわ$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ジグ！\nしんじてるぞ　あいぼう！\pかったら　ジグの　すきな\nおいしい　ものを\lなんでも　つくって　やるぞ！$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ジグザグマは\nぼーっと　している‥$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "おせっかいって　いわれる\nけど　しかたないのよ\pぼうしが　まがってる！\nあら　ゴミが　おちてる！\lあっ　もう　ゆうごはんの\lじかんだわ！\pバトルパレスで　みてる\nだけなんて　がまん\lできる　かしら‥$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "いまは　そう　みえない\nかも　しれんが　むかしは\lジムリーダーに　かった\lことも　あるんじゃ\pもう　いちど　えいこうを\nめざして　みるかのう$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "じてんしゃも　はやいけど\nバトルも　はやいよ\pあっと　いうまに\nかっちゃうんだ！$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "ぼく　ポケモンは\nパパより　つよいよ$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "いけ　かわいい　わが　こよ！\nパパの　ために\lたくさん　かって　こい！\pおまえは　ママに　そっくり\nだから　きっと\lかちまくれるぞ！$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "ここまで　くるのは\nたいへん　だったけど\lバトルアリーナに　すごい\lびじんが　いるって　きいてさ\pかわりに　なにが\nいたと　おもう？\pあせくさくて　むさくるしい\nかくとうかの　むれ　だよ！$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "ときどき　すごく\nえらそうな　おじいさんが\lあそこに　はいって　いくの\pすごい　ポケモンを\nつれてるの\lでも　やさしそうな　ひとよ$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "しってるかい？\nバトルピラミッドの　でんせつ\pじしん　あふれる　トレーナーが\nおうごんの　いただきを　めざす\lとき　おとこの　なかの　おとこが\lあらわれる　という‥\pしらない？\nそりゃ　そうだ！\lいま　おれが　つくったからな！\pどういう　いみかって？\nそれは　いえないな！$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "くそ！　くそー！\nいちども　まけた\lことが　なかったのに！\pぼろぼろに　やられて\nしまった！\pおまけに　さいのうが\nないって？！　くそー！$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "こいつ　バトルタワーで\nとんでもなく　つよい\lトレーナーに　あたっちゃって\pいまは　この　ありさま‥\pバトルタワーに　いく\nときは　きを　つけた\lほうが　いいよ$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "やった！\nやっと　バトルポイントが\lたまった！\pまた　おおきな　ぬいぐるみと\nこうかん　しよう！$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "おお　そうか！\nここが　ランキングホールか！\pスーパーチャンピオンとして\nれきしに　のこって\lここに　なまえを\lきざみたいな$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "あなたが　いれば\nなんでも　できる$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "ああ　ダーリン\nあなたって　すてき！\pああ　もう　まちきれないわ！\pいますぐ　マルチ\nバトルルームへ　いきましょ！\pバトルサロンで　いっしょに\nなれば　ふたりの　あいの\lちからで　みんなに\lかてるわ！\pわたしたちの　まえでは\nダーリン　みんな\lドミノの　ように\lたおれていくわ！$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "バトルフロンティアは\nつよい　トレーナー　だけの\lものじゃ　ない\pとくべつな　ちからを\nもつ　ひとも　おおぜい\lまねかれて　いる　らしい\pあの　スコットと　いう　おとこ‥\pもっと　おおきな　もくてきの\nために　ここを\lつくったの　かもな‥$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "ちょいと　すまんが\nめは　いいかね？\pこの　さきに　へんな　きが\nあってな　つかれた\lわしの　めには\lゆれて　みえるんじゃ$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "ちょいと　すまんが\nきおくりょくは　いいかね？\pこの　さきに　むかし\nへんな　きが　あった\lきが　するんじゃ$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "み‥\nみたんだ！\pこの　さきに　しっぽの\nながい　ねばねばした\lポケモンが　いたんだ！\pいわの　したに　かくれて\nずっと　こっちを\lみてたんだ！$"
