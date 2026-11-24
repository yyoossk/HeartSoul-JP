BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
	.string "たいかいは　しゅうりょう　しました\nしんさを　うけて　のこしたい\lポケモンを　えらんで　ください$"

BugContest_Text_Judging1::
	.string "それでは　つかまえた　ポケモンの\nしんさを　はじめます\p‥‥‥‥‥‥‥‥‥\n‥‥‥‥‥‥‥‥‥\pじゅんいが　きまりました！\nじゅんびは　いいですか？$"

BugContest_Text_WrongChoiceMon:
	.string "しんさを　うけて　のこしたい\nポケモンを　えらんで　ください$"

BugContest_Text_DidntCatch:
	.string "あら！　ポケモンを　つかまえて\nいませんね　しっかくです\pあずかった　ポケモンを\nおかえし　します$"

BugContest_Text_TimesUp:
	.string "ピンポーン！　じかんぎれです！$"

BugContest_Text_WhiteOut:
	.string "{PLAYER}は　たたかえる\nポケモンが　いなくなった！\l{PLAYER}は　たいかいを　きけんした$"

BugContest_Text_First1:
	.string "だい3いは　エリートトレーナーの\nベリンダさん！　ぴちぴちの\lバタフリーを　つかまえました！$"
BugContest_Text_First2:
	.string "だい2いは　むしとりしょうねんの\nショーンくん！　あばれる\lカイロスを　つかまえました！$"
BugContest_Text_First3:
	.string "むしとりたいかい　ゆうしょうは‥\p{PLAYER}さん！　みごとな\n{STR_VAR_1}を　つかまえました！$"

BugContest_Text_Second1:
	.string "だい3いは　エリートトレーナーの\nベリンダさん！　ぴちぴちの\lバタフリーを　つかまえました！$"
BugContest_Text_Second2:
	.string "だい2いは　{PLAYER}さん！\nあばれる　{STR_VAR_1}を\lつかまえました！$"
BugContest_Text_Second3:
	.string "むしとりたいかい　ゆうしょうは‥\pむしとりしょうねんの　ショーンくん！\nみごとな　カイロスを　つかまえました！$"

BugContest_Text_Third1:
	.string "だい3いは　{PLAYER}さん！\nぴちぴちの　{STR_VAR_1}を\lつかまえました！$"
BugContest_Text_Third2:
	.string "だい2いは　エリートトレーナーの\nベリンダさん！　あばれる\lバタフリーを　つかまえました！$"
BugContest_Text_Third3:
	.string "むしとりたいかい　ゆうしょうは‥\pむしとりしょうねんの　ショーンくん！\nみごとな　カイロスを　つかまえました！$"

BugContest_Text_TakePartInFuture:
	.string "ごさんか　ありがとう　ございました！\nまた　ぜひ　さんか　してくださいね$"

BugContest_Text_TransferAndReturn:
	.string "えらんだ　むしポケモンは\nパソコンに　おくられます\lあずかった　ポケモンを　おかえしします$"
