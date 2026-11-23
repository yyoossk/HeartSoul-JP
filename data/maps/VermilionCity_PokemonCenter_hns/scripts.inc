VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "ディグダのあなの　まえで\nポケモンが　ねむってるんだ\pつかまえる　チャンス　だけど\nどうやって　おこせば\lいいんだろう？$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "ディグダのあなの　まえで\nポケモンが　ねむって\lいたんだが\pいなく　なった\nみたいだな$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "こうそくせんは　トレーナーと\nであって　たたかうのに\lもってこいの　ばしょだ$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "あれ？　みた　ことの　ない\nバッジを　もってるね\pそうか　ジョウトの\nバッジ　なんだね$"
