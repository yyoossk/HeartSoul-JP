LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "しんじられる？\pポケモンの　せわに\nあきちゃう　ひとが\lいるのよ\pおじいちゃんは　そんな\nかわいそうな　ポケモンを\lひきとって　せわを\lしているの$"
LavenderTown_House1_Text_Guy:
	.string "フジろうじんは　ここに\nすんでるけど　いまは\lたましいのいえに　いるはずだ$"
LavenderTown_House1_Text_Marowak:
	.string "‥‥‥‥‥‥‥‥‥‥‥‥‥‥$"

LavenderTown_House1_Text_Marowak2:
	.string "ガラガラは　おとなしいけど\nしあわせ　そうだ$"

