CeladonCity_DepartmentStore_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor::
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1::
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2::
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3::
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl::
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES::
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1::
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2::
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3::
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4::
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster::
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer::
	.string "とった　ひとの　なまえと\n"
	.string "アイディが　ポケモン　ごとに\l"
	.string "きろく　されてるよ$"

CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter::
	.string "やったー！\p"
	.string "となりのこが　ゴーストと　ガルーラ\n"
	.string "こうかん　してくれるって！$"

CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade::
	.string "はやく　きて！\n"
	.string "ゴースト　ちゃーん！\p"
	.string "ぼくは\n"
	.string "ゴースト　マニア　なのね！\p"
	.string "…　あー？\p"
	.string "てんそう　されて　きた　ゴーストが\n"
	.string "べつの　ポケモンに！？$"

CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID::
	.string "ひとから　もらった　ポケモンは\n"
	.string "アイディが　ちがうから　わかるよ$"

CeladonCity_DepartmentStore_3F_Text_ItsSuperNES::
	.string "スーパー　ファミコン　だ！$"

CeladonCity_DepartmentStore_3F_Text_AnRPG::
	.string "ロールプレイング　ゲームだ！\n"
	.string "…　あそんでく　ひまが　ない$"

CeladonCity_DepartmentStore_3F_Text_SportsGame::
	.string "これは　スポーツ　ゲームだ！\n"
	.string "…　おとうさんが　すきそう！$"

CeladonCity_DepartmentStore_3F_Text_PuzzleGame::
	.string "パズル　ゲームだ…！\n"
	.string "…　はじめたら　やめられない$"

CeladonCity_DepartmentStore_3F_Text_FightingGame::
	.string "たいせん　アクションゲームだ！\n"
	.string "…　ちょっと　むずかしそう！$"

CeladonCity_DepartmentStore_3F_Text_TVGameShop::
	.string "３かい…テレビ　ゲーム　ショップ$"

CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon::
	.string "レッドと　グリーン！\n"
	.string "どっちも　ポケット　モンスター！$"

Text_CounterTeach::
	.string "いやあー！\n"
	.string "ポケモン　やっと　おわったよ！\l"
	.string "きみは　まだ　なの？\p"
	.string "それじゃあ\n"
	.string "いい　わざ　おしえて　あげよう！\p"
	.string "てんいんが　おしえる　わざだけに\n"
	.string "カウンター！　どう　おぼえる？$"

Text_CounterDeclined::
	.string "やめるの？\n"
	.string "じゃ　きがむいたら　きなよ$"

Text_CounterWhichMon::
	.string "どの　ポケモンが\n"
	.string "おぼえるの　かな？$"

Text_CounterTaught::
	.string "カウンター　つかってる　かい？$"
