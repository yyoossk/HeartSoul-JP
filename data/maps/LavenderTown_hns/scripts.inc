LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "りっぱな　たてもの　だろう？\pカントーの　ラジオとうさ$"

LavenderTown_Text_Teacher:
	.string "カントーには　いい\nラジオばんぐみが　たくさん　あるの$"

LavenderTown_Text_Gramps:
	.string "ポケモンの　たましいを\nとむらいに　あちこちから\lひとが　やってくるんじゃ$"

LavenderTown_Text_Youngster:
	.string "ねむっている　ポケモンを\nおこすには　ポケモンのふえが\lいるんだ\pトレーナーの　じょうしきさ！$"

LavenderTown_Text_Sign:
	.string "シオンタウン\pシオン　むらさき\nとうとい　いろ$"

LavenderTown_Text_KantoRadioStationSign:
	.string "カントー　ラジオとう\pみんなの　すきな　ばんぐみを\n24じかん　ほうそうちゅう！$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "シオン　ボランティア\nポケモンハウス$"

LavenderTown_Text_SoulHouseSign:
	.string "たましいの　いえ\pポケモンの　たましいよ\nやすらかに$"
