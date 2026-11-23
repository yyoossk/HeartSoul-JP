MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
	.string "なんだって？　ロケットだんが\nもどって　きた？\pいかりのみずうみで　くろずくめの\nおとこたちを　みたぞ‥$"

MahoganyTown_PokemonCenter_Text_Youngster:
	.string "ポケモンが　はやく　しんか\nしすぎない　ように\lとめているんだ\pある　わざを　おぼえさせてから\nしんか　させるんだよ$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
	.string "ポケモンは　しんか　すると\nつよく　なるけど\pわざを　おぼえるのが\nおそく　なるのよ$"
