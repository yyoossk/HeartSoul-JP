BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "わたしの　ポケモンは\n{STR_VAR_2}　しってる？\lとても　かわいくて\lいい　こなの\pこの　こなら　じしんを\nもって　こうかん　できるわ！\p{STR_VAR_1}と　わたしの\n{STR_VAR_2}を\lこうかん　しない？$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "まあ　かわいい！\nありがとう！\lだいじに　するわ！\pわたしの　{STR_VAR_2}も\nだいじに　してね！$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "ごめんなさい！\n{STR_VAR_1}　いがいとは\lこうかん　しないの$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "あら　だめ？\nそれでも　いいのよ\lまた　あそびに　きてね$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "うふふ！\nエネコって　おもってたより\lずっと　かわいい！\lうれしいわ！$"
