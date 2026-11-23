CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "いらっしゃい！\pいま　おおぐい　たいかいを\nやって　いるんだ\pわるいけど　いまは\nだせないんだ$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "‥がつがつ　もぐもぐ‥$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "はなしかけるな！\pしゅうちゅうが\nきれる！$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "‥ごくん‥　もぐもぐ‥$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "しつ　より　りょうだ！\pおなか　いっぱいなら\nしあわせ！$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "むしゃ　むしゃ‥$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "ここの　りょうりも　うまいが\nいちばん　うまいのは\lコガネだな$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "ぽりぽり‥　ぽりぽり‥$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "ここでは　だれも　コインケースは\nくれないわよ\lジョウトで　さがしてね$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "ぽりぽり‥　ぽりぽり‥\pまだ　たべられる！\pおかわり！$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "おおぐい　たいかい！\nじかん　むせいげん！\pおわりなき　たたかい！\nいちばん　たべた　ひとは\lただ！$"

