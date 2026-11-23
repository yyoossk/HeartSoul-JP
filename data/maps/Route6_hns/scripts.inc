Route6_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX_HNS, PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN_HNS, PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_EventScript_Item_Silver_Wind::
    finditem ITEM_TM_SILVER_WIND
    end

Route6_Text_PokefanM:
	.string "はつでんしょの　もんだいが\nかいけつ　するまで　みちは\lとおれないよ$"

Route6_Text_UndergroundPathSign:
	.string "ちかつうろ\pハナダシティ　ー　クチバシティ$"

PokefanM_Text_RexSeen:
	.string "おれの　オドシシは\nせかいで　いちばん　かわいい$"

PokefanM_Text_RexBeaten:
	.string "おれの　オドシシが！$"

PokefanM_Text_RexAfter:
	.string "オドシシの　しぐさ\nかわいいだろ？\pこころが　とけちゃう\nくらい　かわいいだろ？$"

PokefanM_Text_AllanSeen:
	.string "おれの　グランブルは\nせかいで　いちばん　かわいい$"

PokefanM_Text_AllanBeaten:
	.string "おれの　グランブルが！$"

PokefanM_Text_AllanAfter:
	.string "グランブルの　しぐさ\nかわいいだろ？\pこころが　とけちゃう\nくらい　かわいいだろ？$"

