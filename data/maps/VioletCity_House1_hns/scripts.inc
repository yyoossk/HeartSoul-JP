VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "ポケモンを　あつめてるんだ！\n{STR_VAR_1}　もってる？\pぼくの　{STR_VAR_2}と\nこうかん　しない？$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "やった！　{STR_VAR_1}を\nてにいれたぞ！\p{STR_VAR_2}　げんきでね！$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "うーん　ちがうよ\nそれは　{STR_VAR_1}じゃない$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "こうかん　したくないの？\nざんねん‥$"

VioletCity_House1_Text_After:
	.string "やあ　まえの　ぼくの\nイワーク　げんき？$"

VioletCity_House1_Text_PokefanM:
	.string "こうかんで　もらった　ポケモンは\nはやく　そだつんだ\pでも　ちゃんと　ジムバッジが\nないと　いうことを\lきかない　ことも　あるぞ$"
