OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "となりの　アサギしょくどうの\nふなのりは　きまえが　いい\pおれの　ポケモンに\nかいりきを　おしえて　くれた\pいまじゃ　おおきな　いわも\nへっちゃらで　うごかせるぜ$"

OlivineCity_Text_PokecenterTeacher:
	.string "うみの　むこうの\nタンバシティに　いる　ひとが\pいつも　めずらしい　ポケモンを\nじまん　していたわ$"
