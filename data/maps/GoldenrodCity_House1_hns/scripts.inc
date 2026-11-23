GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "いろちがいの　とくべつな　いろの\nせっていを　きりかえますか？$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "いろちがいの　いろを\nきりかえました！\pパソコンの　ちょうせんビューアで\nせっていを　たしかめてね$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "ニュースだ‥\pけいさつが　この　あかい\nかみの　しょうねんを\lさがしている！\pきみは　この　こどもの\nなまえを　しってるかね？$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "はいはい！　わたしは\nせいめい　はんだんし！\lなまえの　うらないしです！\pあなたの　ポケモンの　ニックネームを\nうらなって　さしあげましょう$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "どの　ポケモンの　ニックネームを\nうらないますか？$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "ふむ‥　{STR_VAR_1}　ですか？\nなかなか　いい　なまえを\lつけましたね\pでも！　もうすこし　いい　なまえを\nつけて　みませんか？$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "よろしい　では　あたらしい\nニックネームは？$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "できました！　これからは　この\nポケモンは　{STR_VAR_1}です！\pまえより　ずっと　いい　なまえ！\nよかったですね！$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "そうですか\nまた　おこし　ください$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "できました！　これからは　この\nポケモンは　{STR_VAR_1}です！\pみためは　かわりませんが\nずっと　すぐれた　なまえです！\pよかったですね！$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "ふむ‥　{STR_VAR_1}　ですか！\pすばらしい　ニックネームです！\nけちの　つけようが　ありません！\pこれからも　{STR_VAR_1}を\nだいじに　して　くださいね$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "まあ　まあ\nそれは　ただの　タマゴですよ！$"


