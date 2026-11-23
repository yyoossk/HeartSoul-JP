BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
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

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
	.string "ここは　バトルタワー！\nさいきょうの　トレーナーとして\lれんしょうを　つづけろ！$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
	.string "ここは　バトルパレス！\nポケモンの　たたかいを\lみまもれ！$"

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
	.string "ここは　バトルアリーナ！\nさいきょうの　チームよ\lあつまれ！$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
	.string "ここは　バトルピラミッド！\nバトルクエストを\lすすめ！$"

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
	.string "バトルフロンティア\nランキングホール\lあたらしい　きろくを　めざせ！$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
	.string "バトルポイント\nこうかんサービスコーナー\lバトルポイントを　こうかんしよう！$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
	.string "うわあ！\nおおきい！\pバトルタワーは　とくべつな\nかんじ　ほかとは　ちがうね$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
	.string "ぼくの　おおきな　ゆめは\nバトルフロンティアと\lポケモンリーグを　せいは\lする　こと\pもし　ゆめが　かなったら‥\pと　となりの　ミミちゃんに\nともだちに　なって　って\lいうんだ！$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
	.string "バトルピラミッドは\nきびしすぎる！\lてっぺんまで　いけない！\pこうなったら　そとがわを\nのぼろう　かな‥$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
	.string "わたしは　やみの　なかで\nいきる　もの‥\lそう‥　わたしに　ふさわしいのは\lバトルピラミッド　のみ‥\pくらやみを　さまよい\nぜつぼうに　ひたるのは\lいかが　かな？$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
	.string "いっしゅうかん　ねないで\nさいきょうの　チームを\lつくったぞ！\pまける　きが　しない　まじで\nバトルアリーナに\lのりこむぞ！$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
	.string "きみも　エニシダさんに\nつれて　こられたの？\lあの　ひと　なんなんだろう？\pさいのうの　ある　トレーナーを\nみぬく　めは　ほんもの\lらしいけど‥\pあの　ひとが　たたかってる\nところは　みた　ことが\lないんだ$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
	.string "ジグ！\nきみを　しんじてるよ！\pかったら　すきな　おやつ\nなんでも　つくって\lあげるからね！$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
	.string "ジグザグマは　ぼんやり\nしている‥$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
	.string "おせっかい　って　いわれるけど\nしかたないのよ\pぼうしが　まがってるわ！\nあら　ゴミが　おちてる！\lあら　もうすぐ　ゆうごはん！\pバトルパレスで　みてる\nだけ　なんて　がまん\lできるかしら‥$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
	.string "いまは　そう　みえない\nかも　しれないが　むかしは\lジムリーダーに　かったんだ\pもう　いちど　えいこうを\nめざすのも　いいかもな$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
	.string "じてんしゃも　はやいけど\nしょうぶも　はやいのさ\pあっというまに\nかってしまうぞ！$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
	.string "ポケモンなら　パパより\nわたしの　ほうが　つよいの$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
	.string "いけ　かわいい　むすめよ！\nパパの　ために　かちまくれ！\pママに　にてるから\nきっと　むてきだぞ！$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
	.string "ここまで　くるのは\nたいへん　だったが\lバトルアリーナに　すごい\lびじんが　いると　きいてね\pかわりに　なにが\nいたと　おもう？\pあせくさくて　むさくるしい\nかくとうかの　むれだよ！$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
	.string "ときどき　とても　えらそうな\nおじいさんが　はいって\lいくのを　みるんだ\pすごい　ポケモンを\nつれてるよ\lでも　やさしそうな　ひとだよ$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
	.string "しってるかい？\nバトルピラミッドの　でんせつを\pじしんに　みちた　トレーナーが\nおうごんの　いただきに　とどく\lとき　おとこの　なかの\lおとこが　あらわれる\pしらない？\nそりゃ　そうさ！\lいま　つくったんだから！\pどういう　いみかって？\nそれは　いえないな！$"

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
	.string "くそっ！　くそっ！\nいちども　まけた　ことが\lなかったのに！\pても　あしも　でずに\nやられた！\pしかも　さいのうが　ない\nだって？！　くそっ！$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
	.string "こいつ　バトルタワーで\nとんでもなく　つよい\lトレーナーに　あったんだ\pみて　ごらん‥\pバトルタワーに　いくなら\nきを　つけた　ほうが\lいいよ$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
	.string "やった！\nついに　バトルポイントが\lたまった！\pまた　おおきな　ぬいぐるみと\nこうかん　しようかな！$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
	.string "おお　そうか！\nここが　ランキングホールか！\pスーパーチャンピオンとして\nなまえを　ここに　のこして\lれきしに　なりたいな$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
	.string "きみが　いれば\nなんだって　できるよ$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
	.string "ああ　ダーリン　すてき！\pもう　まちきれない！\pいますぐ　マルチバトル\nルームへ　いきましょう！\pバトルサロンで　くめば\nわたしたちの　あいの　ちからで\lだれにも　まけないわ\pダーリン　わたしたちの\nまえでは　みんな　ドミノ\lみたいに　たおれるのよ！$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
	.string "バトルフロンティアは　つよい\nトレーナー　だけの　ものでは\lない\pとくべつな　ちからを　もつ\nひとが　たくさん　まねかれて\lいる　ようだ\pあの　エニシダと　いう　おとこ‥\pもっと　おおきな　もくてきが\nあって　ここを　つくったの\lかも　しれん‥$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
	.string "もし　そこの　かた\nめは　いいかね？\pこの　さきに　へんな　きが\nあって　わしの　めには\lゆれて　みえるのじゃ$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
	.string "もし　そこの　かた\nものおぼえは　いいかね？\pこの　さきに　むかし　へんな\nきが　あった　ような\lきが　するのじゃ$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
	.string "み‥\nみた！\pこの　さきに　しっぽの　ながい\nべたべた　した　ポケモンが\lいたんだ！\pおおきな　いわの　したに\nかくれて　こっちを\lじっと　みてた！$"
