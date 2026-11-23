LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
	.string "‥とおくから　よく　きた‥\pわしは　ここで　めいそう\nしておった　わしの　なかに\lあたらしい　ちからが\lめざめたのじゃ\pおまえの　ポケモンにも\nわけて　やろう\lうけとるが　よい$"

HiddenPowerGuy_Text_Explanation:
	.string "わかるか？\nめざめるパワーじゃ！\pポケモンの　ちからを\nひきだして　こうげき　する\pおぼえて　おけ　タイプと　いりょくは\nつかう　ポケモンで　かわるのじゃ$"

HiddenPowerGuy_Text_Meditating:
	.string "めいそう　ちゅうじゃ‥$"
