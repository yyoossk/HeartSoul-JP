CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "こわい　はなしを\nしてあげよう‥$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "いや　そとが　あかるい\nうちは　こわく　ないな\pひが　くれたら\nまた　おいで$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "むかし　むかし　あたらしい\nじてんしゃを　かって\lもらった　おとこのこが\lいた‥\pすぐに　のって\nみたく　なった‥\pあんまり　たのしくて\nひが　くれたのにも\lきづかなかった‥\pまっくらな　よみちを\nかえって　いると　きゅうに\lじてんしゃが　おそく　なった！\pペダルが　おもく\nなったんだ！\pこぐのを　やめると　じてんしゃが\nうしろへ　さがりはじめた！\pまるで　のろわれた　じてんしゃが\nやみの　なかへ　ひきずりこもうと\lして　いるようだった！\p‥\p‥\pぎゃああああ！\pおとこのこは　サイクリングロードの\nのぼりざかを　はしって\lいたのさ！\p‥\nどきっ　どきっ！\pしんぼう　づよく　きいて　くれた\nおれいに　わざマシン82を\lあげよう！$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "わざマシン82は\nねごと\pポケモンが　ねむって　いる\nあいだ　ランダムに\lわざを　だすんだ\pでも　あの　こわい　はなしの\nあとで　ねむれる　かな？$"

