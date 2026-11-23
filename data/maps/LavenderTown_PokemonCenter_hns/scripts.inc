LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "シオンの　きたには\nイワヤマトンネルが　ある\lぬければ　はつでんしょだ$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "ポケモンの　ふえの\nおんがくを　ながす\lばんぐみが　あるのよ\pあら？　あなたの　ラジオ\nかくちょうカードが\lないと　きけないわね\pこの　まちの　ラジオとうで\nもらえるかも？$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "はつでんしょが　とまってると\nリニアも　うごかない‥\pラジオとうも\nほうそう　できないんだ‥$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "ラジオとうの　きょくちょうが\nよろこんでたよ\pはつでんしょが　また　うごいて\nほうそうが　さいかい\lできたって$"
