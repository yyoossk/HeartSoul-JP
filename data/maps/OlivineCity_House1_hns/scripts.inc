OlivineCity_House1_hns_MapScripts::
	.byte 0

OlivineCity_House1_EventScript_Tim::
	lock
	faceplayer
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, OlivineCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_VOLTORB, OlivineCity_House1_Text_YouWillTradeWontYou, OlivineCity_House1_EventScript_DeclineTrade, OlivineCity_House1_EventScript_NotRequestedMon, OlivineCity_House1_Text_MonYouTakeCare
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_House1_EventScript_DeclineTrade::
	msgbox OlivineCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OlivineCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_TradeCompleted::
	msgbox OlivineCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_Text_YouWillTradeWontYou:
	.string "ポケモン　あつめてるの！\n{STR_VAR_1}　もってない？\pぼくの　{STR_VAR_2}と\nこうかん　しない？$"

OlivineCity_House1_Text_MonYouTakeCare:
	.string "やったー！\n{STR_VAR_1}　ゲット！\p{STR_VAR_2}\nげんきでね！$"

OlivineCity_House1_Text_ThisIsntAMon:
	.string "えー　ちがうよ\nそれ　{STR_VAR_1}じゃ　ないもん$"

OlivineCity_House1_Text_YouWontTradeMe:
	.string "こうかん　しないの？\nざんねん‥$"

OlivineCity_House1_Text_After:
	.string "ねえ　まえの\nビリリダマ　げんき？$"
