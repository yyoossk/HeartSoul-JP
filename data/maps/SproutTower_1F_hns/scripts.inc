SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "われらは　この　とうを\nまもって　いる\pここで　すべての　ポケモンに\nかんしゃを　ささげるのじゃ$"

SproutTower_Text_SageChow_Beaten:
	.string "あ　ありがとう！$"

SproutTower_Text_SageChow_AfterBattle:
	.string "いきとし　いける　ものは\nたすけあって　いきて　いる\pつねに　それに\nかんしゃ　せねばな$"

SproutTower_Text_1F_Sage1:
	.string "てっぺんまで　いけば\nひでんマシンが　もらえるぞ$"

SproutTower_Text_1F_Sage2:
	.string "マダツボミのとうは　ポケモンの\nしゅぎょうの　ばとして\lむかし　たてられたのじゃ$"

SproutTower_Text_1F_Granny:
	.string "30メートルを　こえる\nマダツボミが‥\pこの　とうの　はしらに\nなったと　いわれて　おる$"

SproutTower_Text_1F_Teacher:
	.string "はしらが　ゆれてるの\nみえる？\pうえの　かいで\nしゅぎょう　してるのよ$"

SproutTower_Text_1F_Statue:
	.string "ポケモンの　ぞう‥\pとても　ふうかくが　ある$"
