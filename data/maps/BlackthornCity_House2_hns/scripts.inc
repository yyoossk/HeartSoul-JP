BlackthornCity_House2_hns_MapScripts::
	.byte 0

BlackthornCity_House2_EventScript_Emy::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, BlackthornCity_House2_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MR_MIME, BlackthornCity_House2_Text_YouWillTradeWontYou, BlackthornCity_House2_EventScript_DeclineTrade, BlackthornCity_House2_EventScript_NotRequestedMon, BlackthornCity_House2_Text_MonYouTakeCare
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
	release
	end

BlackthornCity_House2_EventScript_DeclineTrade::
	msgbox BlackthornCity_House2_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_TradeCompleted::
	msgbox BlackthornCity_House2_Text_After, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_Text_YouWillTradeWontYou:
	.string "ポケモン　あつめてるの！\n{STR_VAR_1}　もってない？\pぼくの　{STR_VAR_2}と\nこうかん　しない？$"

BlackthornCity_House2_Text_MonYouTakeCare:
	.string "やったー！\n{STR_VAR_1}　ゲット！\p{STR_VAR_2}\nげんきでね！$"

BlackthornCity_House2_Text_ThisIsntAMon:
	.string "えー　ちがうよ\nそれ　{STR_VAR_1}じゃ　ないもん$"

BlackthornCity_House2_Text_YouWontTradeMe:
	.string "こうかん　しないの？\nざんねん‥$"

BlackthornCity_House2_Text_After:
	.string "ねえ　まえの\nバリヤード　げんき？$"
