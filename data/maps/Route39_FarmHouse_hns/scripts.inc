Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "うちの　ミルタンクが\nミルクを　だして　くれねえだ\pこの　ぼくじょうの\nミルクは　ゆうめいでな\pみんな　のみたがるだよ\pきのみを　たくさん\nたべさせりゃ　ミルクを\lだすと　おもうだが$"

Route39_Text_FarmerMBuyMilk:
	.string "うちの　モーモーミルク\nどうだべ？\pじまんの　いっぴんだ\pポケモンに　のませりゃ\nHPが　かいふく　するだよ！\pたったの　500円で\nゆずって　やるだ$"

Route39_Text_FarmerMGotMilk:
	.string "ほれ！\nえんりょ　なく　のんでけろ！$"

Route39_Text_FarmerMNoMoney:
	.string "わりいな\nかねが　なけりゃ　うれねえだ！$"

Route39_Text_FarmerMNoRoom:
	.string "バッグが　いっぱい\nみてえだな$"

Route39_Text_FarmerMNoSale:
	.string "いらねえだか？\nまた　きてけろ$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "もう　1ぽん　どうだ？$"

Route39_Text_GotMilk:
	.string "{PLAYER}は\nモーモーミルクを　てにいれた$"

Route39_Text_FarmerMMilking:
	.string "さて　ちちしぼりに\nいくだ$"

Route39_Text_FarmerFInTrouble:
	.string "うちの　ミルクは　カントーにも\nでてるのよ\pだから　ミルタンクが　ミルクを\nださないと　こまるのよ$"

Route39_Text_FarmerFHealedMiltank:
	.string "ミルタンクを　なおして\nくれたのね\lまた　モーモーミルクを\lだすように　なったわ\pおれいに　これを\nどうぞ$"

Route39_Text_FarmerFSnatchSpeech:
	.string "それは　よこどり\pあいてが　つかう　まえに\nわざを　よこどり　する\lずるい　わざよ\pふたり　いじょうが　よこどりを\nつかうと　いちばん　おそい\lポケモンだけが　よこどり\lできるの\pうまく　つかってね\nタイミングが　だいじよ$"
