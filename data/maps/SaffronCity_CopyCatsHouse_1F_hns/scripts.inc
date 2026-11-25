SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "むすめは　ひとの　まねを\nするのが　すきでね\pそれで　まわりから　ものまね\nむすめと　よばれて　いるんだ$"

CopycatsHouse1F_Text_PokefanF:
	.string "むすめは　ほんとうに\nじぶんかって‥\pともだちも　すくないのよ$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "3ねんまえ　{PLAYER}くんに　もらった\nポケモンにんぎょうを　さいきん\lなくして　しまったの\p"
	.string "それから　ものまねが\nもっと　うまく　なって‥$"

CopycatsHouse1F_Text_Blissey:
	.string "ハピナス『ハピー！$"
