AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "ポケモンは　ひでんわざを\nおぼえて　いるかね？\pひでんわざは　ポケモンが\nひんしでも　つかえるんじゃ$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "ポケモンを　パソコンに　あずける\nしくみは　マサキって　ひとが\lつくったんだ\pマサキの　パソコンは　ボックス\nひとつに　30ぴき　あずけられる$"

AzaleaPokecenter_Text_FishingGuru:
	.string "マサキの　パソコンは　ボックス\nひとつに　30ぴき　あずけられる$"

AzaleaPokecenter_Text_PokefanF:
	.string "ぼんぐりって　しってる？\pわって　なかを　くりぬいて\nとくべつな　しかけを　つけるの\pそうすると　ポケモンが\nつかまえられるのよ\pモンスターボールが　できる　まえは\nみんな　ぼんぐりを　つかってたの$"
