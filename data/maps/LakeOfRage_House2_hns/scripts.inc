LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
	.string "いかりのみずうみは　あばれた\nギャラドスが　つくった\lクレーター　なんだ\pそこに　あまみずが　たまって\nみずうみに　なったのさ\pおじいちゃんの　ひいひい\nおじいちゃんから\lつたわる　はなしだ\pむかしは　げんきな　コイキングが\nつれたんだけど‥\pいったい　どう　なって\nいるんだろう$"

LakeOfRage_House2_Text_MenInBlack:
	.string "くろい　ふくの　おとこたちが\nきてから　みずうみが\lおかしいんだ$"

LakeOfRage_House2_Text_LastMon:
	.string "さいごの　ポケモンを\nもらう　わけには　いかないよ！$"

LakeOfRage_House2_Text_WorldsLargest:
	.string "いかりのみずうみが\nもとに　もどった\pコイキングも　もどって　きた\pせかい　いちの　コイキングを\nもつ　ゆめが　かなうかも\pそうだ‥　コイキング\n1ぴきに　2000円\lでかい　コイキングなら\l100000円　はらうぞ！$"

LakeOfRage_House2_Text_ForMe:
	.string "で‥　コイキングは\nもって　きたかい？$"

LakeOfRage_House2_Text_HaveMagikarp:
	.string "おっ　コイキング　だね！\nどれだけ　おおきいか\lみせて　もらおう$"

LakeOfRage_House2_Text_BigPayout:
	.string "おお！　これは　すごい！\pまいった！\pほんの　きもち　だが\nうけとって　くれ$"

LakeOfRage_House2_Text_Bonus:
	.string "だいじなのは　きろくさ\pそれは　おまけだと\nおもって　くれ！$"

LakeOfRage_House2_Text_TooShort:
	.string "おお！　これは　すごい！\p‥と　いいたい　ところ　だが\nもっと　おおきいのを\lみた　ことが　ある\pまあ　それなりの\nかちは　あるな$"

LakeOfRage_House2_Text_NotMagikarp:
	.string "なに？　それは\nコイキングじゃ　ないぞ！$"

LakeOfRage_House2_Text_Refused:
	.string "そうか‥　みせられる　ほどの\nやつは　まだ　いないか\lまた　こんど　だな$"
