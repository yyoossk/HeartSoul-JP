SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_KJ_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	setflag FLAG_KJ_RECEIVED_HM_SURF @ カントー＆ジョウト
	setflag FLAG_KJ_RECEIVED_HM_SURF @ カントー＆ジョウト
	setflag FLAG_KJ_RECEIVED_HM_SURF @ カントー＆ジョウト
	setflag FLAG_KJ_RECEIVED_HM_SURF @ カントー＆ジョウト
	setflag FLAG_KJ_RECEIVED_HM_SURF @ カントー＆ジョウト
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_KJ_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "おおッ！　きたか！\p"
	.string "ここは　いちばん　おくち　の\n"
	.string "トレジャー　ハウス　だよ！\p"
	.string "サファリ　ゾーンの　キャンペーン\n"
	.string "ひらいたは　いいが　だれも　こない\l"
	.string "ふあんに　なってた　ところだ\p"
	.string "いやー！　おめでとう！\n"
	.string "しょうひんは　きみの　ものだ！$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "{PLAYER}は　かかりいん　から\n"
	.string "ひでんマシン０３を　もらった！$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "ひでんマシン０３は　なみのり！\p"
	.string "なんと！　ポケモンに　のって\n"
	.string "みずの　うえを　すすめる！\p"
	.string "しかも　この　マシンは　つかっても\n"
	.string "なく　ならない　タイプだ！\p"
	.string "こんなに　すばらしい\n"
	.string "しょうひんを　もらって　しまった\l"
	.string "きみは　とても　ツイてるぞ！$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "きみ　もちもの　いっぱいだよ$"

