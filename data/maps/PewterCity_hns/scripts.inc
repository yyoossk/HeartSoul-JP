PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "ニビジムには　いった？\pリーダーは　いわタイプの\nポケモンを　つかうのよ$"

PewterCity_Text_BugCatcher:
	.string "よるに　なると　おつきみやまで\nピッピが　あそんでるんだ\pでも　まいばん　じゃないよ$"

PewterCity_Text_Gramps:
	.string "おお　ジョウトから\nはるばる　きたのかい？\pなつかしいのう　わしも　わかい\nころ　ジョウトへ　しゅぎょうに\lいったもんじゃ\pおまえさんを　みていると\nわかい　ころの　わしを\lおもいだすわい\pほれ　ジョウトで　ひろった\nこの　どうぐを　やろう$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "しらない　ところへ　いって\nあたらしい　ひとと　であう‥\pそれが　たびの\nたのしさじゃよ$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "ニビシティ\nニビは　はいいろ\lいしの　いろ$"

PewterCity_Text_GymSign:
	.string "ニビシティ　ポケモンジム\nジムリーダー　タケシ\pつよくて　かたい\nいしの　おとこ$"

PewterCity_Text_MuseumSign:
	.string "はりがみが　ある‥\pニビかがくはくぶつかんは\nかいそうの　ため　きゅうかん‥$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "はりがみが　ある‥\pおつきみやま　おみやげやさん\nオープン！$"

PewterCity_Text_WelcomeSign:
	.string "ようこそ　ニビシティへ！$"

