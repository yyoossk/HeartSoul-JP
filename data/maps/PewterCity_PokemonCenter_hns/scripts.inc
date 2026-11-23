PewterCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY_HNS
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "‥そうなの　グレンの\nジムが　なくなったのよ\pほんとうに　びっくり\pなに？　でんわ　ちゅうよ\nあっちへ　いって！$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "プリン『プーウ　ププー$"

PewterCity_PokemonCenter_EventScript_Mondo::
	lock
	faceplayer
	goto_if_set FLAG_PEWTER_NPC_TRADE_COMPLETED, PewterCity_PokemonCenter_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HAUNTER, PewterCity_PokemonCenter_Text_WantToTrade, PewterCity_PokemonCenter_EventScript_DeclineTrade, PewterCity_PokemonCenter_EventScript_NotRequestedMon, PewterCity_PokemonCenter_Text_TakeCare
	setflag FLAG_PEWTER_NPC_TRADE_COMPLETED
	release
	end

PewterCity_PokemonCenter_EventScript_DeclineTrade::
	msgbox PewterCity_PokemonCenter_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_PokemonCenter_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_TradeCompleted::
	msgbox PewterCity_PokemonCenter_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_Text_WantToTrade:
	.string "いい　{STR_VAR_1}を　さがして\nあちこち　たびを　してるんだ\pぼくの　{STR_VAR_2}と\nこうかん　しない？$"

PewterCity_PokemonCenter_Text_TakeCare:
	.string "ほんとうに　ありがとう！\n{STR_VAR_1}を　だいじにね！$"

PewterCity_PokemonCenter_Text_DeclineTrade:
	.string "だめ？　ざんねん‥\nぼくの　ゴースト\lきにいると　おもうのに$"

PewterCity_PokemonCenter_Text_NotRequestedMon:
	.string "うーん　それは　{STR_VAR_1}じゃ\nないね　ほしいのは\lそれじゃ　ないんだ$"

PewterCity_PokemonCenter_Text_TradeCompleted:
	.string "ゴーストは　どう？\nいたずらずき　だろ！$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "プリンの　うたを　きくと\nたいていの　ポケモンは\lねむく　なるんだ\pねむって　いる　ときにしか\nつかえない　わざも\lいくつか　あるよ$"
