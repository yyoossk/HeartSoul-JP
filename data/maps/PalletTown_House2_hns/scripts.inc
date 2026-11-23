PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "ナナミ『こんにちは！　おとうとは\nトキワシティの\lジムリーダー　なの\pでも　しょっちゅう　まちを\nでるから　トレーナーが\lこまってるのよね$"

PalletTown_House2_Text_OfferGrooming:
	.string "ナナミ『こんにちは！　ちょうど\nおちゃに　する　ところよ\pいっしょに　どう？\pあら　ポケモンが\nちょっと　よごれてるわね\p1ぴき　グルーミング\nして　あげましょうか？$"

PalletTown_House2_Text_WhichMon:
	.string "ナナミ『どの　こを\nきれいに　する？$"

PalletTown_House2_Text_Alright:
	.string "ナナミ『わかったわ\nすぐ　きれいに　するわね$"

PalletTown_House2_Text_AllDone:
	.string "ナナミ『はい　できあがり！\pほら　{STR_VAR_1}\nきれいに　なったでしょ？\pほんとうに　かわいい\nポケモンね$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "ナナミ『いつも　この　じかんに\nおちゃを　してるの\lいっしょに　どうぞ$"

PalletTown_House2_Text_Refused:
	.string "ナナミ『グルーミングは\nいらないの？\pじゃあ　おちゃだけ\nしましょう$"

PalletTown_House2_Text_CantGroomEgg:
	.string "ナナミ『あら　ごめんね\nタマゴは　さすがに\lグルーミング　できないわ$"
