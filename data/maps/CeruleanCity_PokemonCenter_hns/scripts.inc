CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "しょうぶ　には　つかまえた\nばかりの　ポケモンより\pよわくても　そだててきた\nポケモンを　つかいたいな$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "リニアは　じそく　550キロ\nいじょうで　はしる\lカントーと　ジョウトを\lあっというまに　むすぶんだ\pジョウトへ　いくのが\nほんとうに　らくに　なったよ$"
