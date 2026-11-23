UnionCave_B2F_hns_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK_HNS, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN_HNS, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA_HNS, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "にんげんには　2しゅるい　いる\pスタイルの　ある　やつと\nない　やつだ\pきみは　どっちだ？$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "まばゆい　スタイルだ！$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "きみの　ポケモンの　スタイルは\nあざやかで　すばらしい\pこれからも　どんどん\nよく　なるぞ！$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "しゅぎょう　ちゅうなの\nひとしょうぶ　どう？$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "いやー！　つよすぎる$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "つよく　なるまで\nひとりで　しゅぎょう　するわ$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "すきな　ポケモンが　いるなら\nどこへ　だって　いくわ\pそれが　ほんとうの\nトレーナーよ$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "こんな　ことより\nあの　こたちを　なでたい！$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "しゅうに　いちど　だけ\nポケモンが　みずべに\lあらわれるの\pその　ポケモンを\nみたかったの‥$"
