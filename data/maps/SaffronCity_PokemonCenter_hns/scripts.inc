SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "ジョウトの　ポケモンセンターって\nどんな　かんじ？\p‥へえ　カントーと\nあまり　かわらないのね\pじゃあ　あんしん　して\nジョウトに　いけるわ！$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "イワヤマトンネルを\nとおって　きたんだが\pはつでんしょで　なにか\nさわぎが　あったぞ$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "ハナダに　へんな　どうくつが\nあるんだ\pプロの　やまおとこ　として\nしらべるべき　だが\lあそこは　おれでも　こわい$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "シルフカンパニーの　ほんしゃと\nリニアの　えき‥\lヤマブキの　みどころだよ$"
