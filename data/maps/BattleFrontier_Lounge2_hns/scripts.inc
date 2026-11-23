BattleFrontier_Lounge2_hns_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice_hns::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews_hns
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews_hns::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle_hns::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble_hns::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns::
	.string "よう！　バトルフロンティアの\nニュースなら　おれが\lナンバーワン！\pフロンティアマニアと\nよんで　くれ\pいちおう　きくけど\nきみ　トレーナー　だよな？\pバトルフロンティアの\nさいしん　じょうほうを\lおしえて　あげるよ$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns::
	.string "よう！　さいしん　じょうほうを\nききに　きたのかい？\lよし　いいぞ！$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight_hns::
	.string "どう？　どう？　どう？\pおれの　じょうほう\nすごく　やくに　たった\lだろ？$"

BattleFrontier_Lounge2_Text_FacilityIsHottest_hns::
	.string "えーと‥\pいま　いちばん　あついのは\n{STR_VAR_1}　らしいぞ$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns::
	.string "えーと‥\pいま　いちばん　あついのは\nバトルタワーの\l{STR_VAR_1}　らしいぞ$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pサロンメイデンと　いう\nなぞの　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons_hns::
	.string "サロンメイデンと\nたたかった　ことある？\pあいての　じつりょくを\nはかる　ときは\lこんな　ポケモンを\lつかう　らしい\pエスパータイプの　ねんりき\nポケモン　ほのおタイプの\lかざんポケモン　そして\lノーマルタイプの\lいねむりポケモン$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons_hns::
	.string "ほんきの　サロンメイデンと\nたたかった　ことある？\pぜんりょくの　ときは\nこんな　ポケモンを\lつかう　らしい\pドラゴンと　エスパーの\nむげんポケモン　でんきタイプの\lいかずちポケモン　そして\lノーマルタイプの\lいねむりポケモン$"

BattleFrontier_Lounge2_Text_DomeAceIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pドームスーパースターと　いう\nはなやかな　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons_hns::
	.string "ドームスーパースターと\nたたかった　ことある？\pあいてを　かるく　みてる\nときは　この　3びきを\lつかう\pドラゴンと　ひこうの\nドラゴンポケモン　みずと\lじめんの　ぬまうおポケモン\lほのおと　ひこうの\lかえんポケモン$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons_hns::
	.string "ほんきの　ドームスーパースターと\nたたかった　ことある？\pせんりゃくを　みせる　ときは\nこの　3びきを　つかう\pドラゴンと　ひこうの\nむげんポケモン　みずと\lじめんの　ぬまうおポケモン\lはがねと　エスパーの\lてつあしポケモン$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pファクトリーヘッドと　いう\nかわった　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons_hns::
	.string "ファクトリーヘッドと\nもう　たたかった？\pえーと‥　しょうぶの　ときは\nレンタルポケモンを\l3びき　つかうだけ\pきみと　ほとんど　おなじ\nじょうけんで　たたかうんだ$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons_hns::
	.string "ほんきの　ファクトリーヘッドと\nたたかった　ことある？\pほんきの　ときも\nレンタルポケモンを\l3びき　つかうんだ\pきみと　ほとんど　おなじ\nじょうけんで　たたかうんだ$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pチューブクイーンと　いう\nこわい　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons_hns::
	.string "チューブクイーンと\nたたかった　ことある？\pきげんが　いい　ときは\nこの　3びきを　つかう\lらしい\pどくタイプの　きばへび\nポケモン　むしと　いわの\lかびポケモン　みずタイプの\lいつくしみポケモン$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons_hns::
	.string "ほんきの　チューブクイーンと\nたたかった　ことある？\pほんきで　おこった　ときは\nこの　3びきを　つかう\lらしい\pどくタイプの　きばへび\nポケモン　はがねと　じめんの\lてつへびポケモン　みずと\lひこうの　きょうあくポケモン$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pアリーナキャプテンと　いう\nかわいい　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons_hns::
	.string "アリーナキャプテンと\nたたかった　ことある？\pあいての　じつりょくを\nみる　ときは　こんな\lポケモンを　つかう　らしい\pむしと　かくとうの\n1ぽんヅノポケモン　あくタイプの\lげっこうポケモン　むしと\lゴーストの　ぬけがらポケモン$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons_hns::
	.string "ほんきの　アリーナキャプテンと\nたたかった　ことある？\pほんきの　ときは\nこんな　ポケモンを\lつかう　らしい\pあくタイプの　げっこう\nポケモン　ゴーストと　どくの\lシャドーポケモン　くさと\lかくとうの　キノコポケモン$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pパレスガーディアンと　いう\nあやしい　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons_hns::
	.string "パレスガーディアンと\nたたかった　ことある？\pあいての　こころを　ためす\nときは　こんな　ポケモンを\lつかう　らしい\pどくと　ひこうの\nこうもりポケモン　ノーマルの\lなまけものポケモン　みずと\lこおりの　のりものポケモン$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons_hns::
	.string "ほんきの　パレスガーディアンと\nたたかった　ことある？\pぜんりょくの　ときは\nこんな　ポケモンを\lつかう　らしい\pほのおタイプの　でんせつ\nポケモン　ノーマルの\lなまけものポケモン\lみずタイプの\lオーロラポケモン$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere_hns::
	.string "しらなかった　だろ！\pそこには　エニシダさんが\nフロンティアブレーンと　よぶ\lトップトレーナーが　いるんだ\pピラミッドキングと　いう\nあつい　トレーナーが\lとりしきってるんだ$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons_hns::
	.string "ピラミッドキングと\nたたかった　ことある？\pあいての　ちからを　みる\nときは　こんな　ポケモンを\lつかう　らしい\pいわタイプの　いわやま\nポケモン　こおりタイプの\lひょうざんポケモン\lはがねタイプの\lくろがねポケモン$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons_hns::
	.string "ほんきの　ピラミッドキングと\nたたかった　ことある？\pあつく　もえてる　ときは\nこんな　ポケモンを\lつかう　らしい\pこおりと　ひこうの　れいとう\nポケモン　でんきと　ひこうの\lでんげきポケモン　ほのおと\lひこうの　かえんポケモン$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1_hns::
	.string "ダブルバトルが　できる\nばしょは　いくつか　あるけど\pバトルタワーの　ダブルバトル\nルームが　きほん　なんだ！\pバトルフロンティアの\nダブルバトルは　まず\lそこで　まなぶと　いいよ$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2_hns::
	.string "ここの　しょうぶは\nきを　つけてね\pダブルバトル　せんようの\nさくせんを　もつ\lトレーナーも　いるらしい$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3_hns::
	.string "ここの　ダブルバトルに\nなれて　じしんが　ついたら\lほかの　ダブルバトルにも\lちょうせん　して　みなよ$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice_hns::
	.string "バトルサロンには　いろんな\nトレーナーが　あつまる\pともだちや　ファンに\nあえるかも！\lよく　さがして　みなよ！$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice_hns::
	.string "ともだちと　いっしょなら\nつうしんマルチバトルルームへ\pつよい　ともだちと　くめば\nてごわい　あいてが\lでて　くるぞ！$"

BattleFrontier_Lounge2_Text_NewsGatheringPower_hns::
	.string "なんて　しゅざいりょく！\nししょうは　さすがだ！$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns::
	.string "なんて　かんさつりょく！\nししょうは　さすがだ！$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns::
	.string "なんて　せっとくりょく！\nししょうは　さすがだ！$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns::
	.string "‥ここ　なんなの？\nこわい‥$"

