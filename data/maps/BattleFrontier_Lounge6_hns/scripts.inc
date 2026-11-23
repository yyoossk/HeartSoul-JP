BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "わたしの　ポケモンは\n{STR_VAR_2}\lしってる？\lとても　かわいくて　いいこよ\pこのこなら　じしんを　もって\nこうかんに　だせるわ！\p{STR_VAR_1}と　わたしの\n{STR_VAR_2}を\lこうかん　して　くれない？$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "まあ　かわいい！\nありがとう！\lだいじに　するわね！\pわたしの　{STR_VAR_2}も\nかわいがって　あげてね！$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "あら　ごめんなさい！\n{STR_VAR_1}　いがいとは\lこうかん　しないの$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "あら　だめ？\nそれなら　しかたないわね\lまた　あそびに　きてね$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "うふふ！\nエネコって　おもってたより\lずっと　かわいいわ！\lうれしい！$"
