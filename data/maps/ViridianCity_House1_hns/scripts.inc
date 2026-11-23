ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "ポケモンの　なまえ\nよく　かんがえて　つけてる？\pいい　ニックネームが　あると\nこうかんが　もっと\lたのしく　なるよ$"

ViridianCity_House1_Text_Lass:
	.string "オニスズメの　スズと\nコラッタの　ラッタンよ$"

ViridianCity_House1_Text_Speary:
	.string "スズ『チュ　チュン！$"

ViridianCity_House1_Text_Rattey:
	.string "ラッタン『キキィ！$"

