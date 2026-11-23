SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "ポケモンセンターに　くる　ひとは\nポケモンを　だいじに　する\lひとが　おおい\pそう　おもわない？$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "やまを　ながく　あるいて\nたおれそうな　ときに\lポケモンセンターを\lみつけると‥\pまるで　てんごくに\nいる　きぶんだよ！$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "サファリ　サファリ　たのしいな\nサファリ　サファリ　おもしろい\pポケモン　いっぱい\nまってるよ！\p‥ぼくが　つくった　うた\nサファリゾーンで　うたうんだ$"
