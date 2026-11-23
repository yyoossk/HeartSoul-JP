BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "やあ！　バトルフロンティアの\nニュースなら　おれが　1ばん！\pフロンティアマニアって\nよんでくれ\pいちおう　きくけど\nきみ　トレーナー　だよね？\pバトルフロンティアの\nさいしん　ニュースを\lよろこんで　おしえるよ$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "やあ！　さいしんの　ニュースを\nききに　きたのかい？\lしかたないなあ！$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "ええと‥\pいま　いちばん　あつい\nばしょは\l{STR_VAR_1}　らしいよ$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "ええと‥\pいま　いちばん　あついのは\nバトルタワーの\l{STR_VAR_1}　らしいよ$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pタワータイクーンと　よばれる\nなぞの　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "タワータイクーンと\nたたかった　ことは　ある？\pあいてを　はかる　ときは\nこんな　ポケモンを\lつかう　らしいよ\pエスパータイプの　ねんりき\nポケモン　ほのおタイプの\lかざん　ポケモン　ノーマルの\lいねむり　ポケモン$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "タワータイクーンの\nほんきと　たたかった\lことは　ある？\pぜんりょくの　ときは\nこんな　ポケモンを\lつかう　らしいよ\pドラゴンと　エスパーの\nむげん　ポケモン　でんきタイプの\lいかずち　ポケモン　ノーマルの\lいねむり　ポケモン$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pドームスーパースターと　よばれる\nはでな　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "ドームスーパースターと\nたたかった　ことは　ある？\pあいてを　かるく　みてる\nときは　この　3びきを\lつかうよ\pドラゴンと　ひこうの\nドラゴン　ポケモン　みずと\lじめんの　ぬまうお　ポケモン\lほのおと　ひこうの\lかえん　ポケモン$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "ドームスーパースターの\nほんきと　たたかった\lことは　ある？\pせんりゃくを　みせる　ときは\nこの　3びきを　つかうよ\pドラゴンと　ひこうの\nむげん　ポケモン　みずと\lじめんの　ぬまうお　ポケモン\lはがねと　エスパーの\lてつあし　ポケモン$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pファクトリーヘッドと　よばれる\nかわった　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "ファクトリーヘッドとは\nもう　たたかった？\pええと‥　たたかう　ときは\nレンタルポケモンを\l3びき　もらうだけ\pきみと　ほぼ　おなじ\nじょうけんで　たたかうんだ$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "ファクトリーヘッドの\nほんきと　たたかった\lことは　ある？\pほんきの　ときでも\nレンタルポケモンを\l3びき　もらうだけ\pきみと　ほとんど　おなじ\nじょうけんで　たたかうんだ$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pチューブクイーンと　よばれる\nこわい　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "チューブクイーンと\nたたかった　ことは　ある？\pきげんが　いい　ときは\nこの　3びきを　つかう\lらしいよ\pどくタイプの　キバへび\nポケモン　むしと　いわの\lはっこう　ポケモン　みずタイプの\lやさしい　ポケモン$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "チューブクイーンの\nほんきと　たたかった\lことは　ある？\pほんきで　おこると\nこの　3びきを　つかう\lらしいよ\pどくタイプの　キバへび\nポケモン　はがねと　じめんの\lてつへび　ポケモン　みずと\lひこうの　きょうあく　ポケモン$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pアリーナキャプテンと　よばれる\nかわいい　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "アリーナキャプテンと\nたたかった　ことは　ある？\pあいての　ちからを　みる\nときは　こんな　ポケモンを\lつかう　らしいよ\pむしと　かくとうの\nひとつのツノ　ポケモン\lあくタイプの　げっこう\lポケモン　むしと　ゴーストの\lぬけがら　ポケモン$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "アリーナキャプテンの\nほんきと　たたかった\lことは　ある？\pほんきで　たたかう　ときは\nこんな　ポケモンを\lつかう　らしいよ\pあくタイプの　げっこう\nポケモン　ゴーストと　どくの\lシャドー　ポケモン　くさと\lかくとうの　キノコ　ポケモン$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pパレスガーディアンと　よばれる\nあやしい　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "パレスガーディアンと\nたたかった　ことは　ある？\pあいての　こころを\nためす　ときは　こんな\lポケモンを　つかう　らしいよ\pどくと　ひこうの　こうもり\nポケモン　ノーマルタイプの\lなまけもの　ポケモン\lみずと　こおりの\lのりもの　ポケモン$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "パレスガーディアンの\nほんきと　たたかった\lことは　ある？\pぜんりょくで　たたかう\nときは　こんな　ポケモンを\lつかう　らしいよ\pほのおタイプの　でんせつ\nポケモン　ノーマルタイプの\lなまけもの　ポケモン\lみずタイプの　オーロラ\lポケモン$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "これは　しらないだろ！\pスコットが　フロンティアブレーン\nと　よぶ　トップトレーナーの\lひとりが　そこに　いるんだ\pピラミッドキングと　よばれる\nあつい　トレーナーが\lしきって　いるのさ$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "ピラミッドキングと\nたたかった　ことは　ある？\pあいての　ちからを\nためす　ときは　こんな\lポケモンを　つかう　らしいよ\pいわタイプの　いわやま\nポケモン　こおりタイプの\lひょうざん　ポケモン\lはがねタイプの　てつ　ポケモン$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "ピラミッドキングの　ほんきと\nたたかった　ことは　ある？\pあつい　ちからが　みなぎると\nこんな　ポケモンを\lつかう　らしいよ\pこおりと　ひこうの　れいとう\nポケモン　でんきと　ひこうの\lでんげき　ポケモン　ほのおと\lひこうの　かえん　ポケモン$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "ダブルバトルが　できる\nばしょは　いくつか　あるけど\pバトルタワーの　ダブル\nバトルルームは　きほん\lなんだよね！\pバトルフロンティアの\nダブルバトルを　まなぶ\lなら　ここだよ$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "ここの　バトルは\nきを　つけてね\pダブルバトル　せんようの\nさくせんを　もつ\lトレーナーも　いるらしいよ$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "ここの　ダブルバトルに\nなれて　じしんが　ついたら\lほかの　ダブルバトルの\lしせつにも　ちょうせん\lして　みると　いいよ$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "バトルサロンには\nいろんな　トレーナーが\lあつまるんだ\pともだちや　なかまに\nあえるかも！\lよく　みて　ごらん！$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "ともだちと　いっしょなら\nつうしんマルチ\lバトルルームへ　いこう\pつよい　ともだちと　なら\nてごわい　あいてが\lでて　くるよ！$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "なんて　すごい　じょうほう\nしゅうしゅうりょく！\lさすが　ししょう！$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "なんて　すごい　かんさつりょく！\nさすが　ししょう！$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "なんて　すごい　せっとくりょく！\nさすが　ししょう！$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "‥ここ　どこ？\nこわいよ‥$"

