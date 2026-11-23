GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "アカネ『はーい！\pうち　アカネ！\pクイズで　ラジオカードが\nもらえるって　きいて\lきたんやけど‥\pこの　クイズ　めっちゃ\nむずかしいねん！$"

RadioTower1F_Text_Whitney2::
	.string "アカネ『すごい　やったやん！\pみっつめの　こたえ　ぜったい\nぼんぐりや　おもてたわ！\lあちゃー！\pそろそろ　ジムに\nもどらな！$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
	.string "いらっしゃいませ！$"

RadioTower1F_Text_ReceptionistNoTours:
	.string "こんにちは　もうしわけ\nありませんが　きょうは\lけんがくは　して　おりません$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
	.string "ただいま　とくべつ　クイズ\nキャンペーンを　おこなって　います\p5もん　せいかい　すると\nポケギアの　ラジオカードが\lもらえます\pいつでも　どこでも\nおんがくが　きけますよ\pクイズに　ちょうせん\nしますか？$"

RadioTower1F_Text_QuizQuestion1:
	.string "だい1もん\pひるま　だけ　あらわれる\nポケモンは　いる？$"

RadioTower1F_Text_QuizQuestion2:
	.string "せいかい！\nだい2もん\pつぎの　ことは　ただしい？\pショップでは　きのみは　かえない$"

RadioTower1F_Text_QuizQuestion3:
	.string "だいせいかい！\nだい3もん\pボールしょくにんの　ガンテツは\nぼんぐりを　ざいりょうに　つかう？$"

RadioTower1F_Text_QuizQuestion4:
	.string "ここまで　ぜんもん　せいかい！\nだい4もん\pキキョウジムの　リーダー\nハヤトは　とりポケモンつかい？$"

RadioTower1F_Text_QuizQuestion5:
	.string "すごい！　また　せいかい！\nさいごの　もんだい\pコガネの　ゲームコーナーの\nスロットに　ヒトカゲは　いる？$"

RadioTower1F_Text_QuizWin:
	.string "ピンポーン！　せいかい！\nおめでとう　ございます！\pしょうひんの　ラジオカードです！$"

RadioTower1F_Text_PokegearRadio:
	.string "{PLAYER}の　ポケギアで\nラジオが　きけるように　なった！$"

RadioTower1F_Text_TuneIn:
	.string "わたしたちの　ラジオばんぐみも\nきいて　くださいね$"

RadioTower1F_Text_WrongAnswer:
	.string "あら‥　ざんねん！\nふせいかい　です\pまた　ちょうせん\nして　くださいね！$"

RadioTower1F_Text_DeclineQuiz:
	.string "そうですか\nきが　かわったら\lまた　どうぞ$"

RadioTower1F_Text_Lass:
	.string "DJの　ベンさんって\nすてき！\pあまい　こえに\nとろけちゃう！$"

RadioTower1F_Text_Youngster:
	.string "ポケモンじっきょうの\nクルミちゃんが　すきなんだ\pこえしか　しらない\nけどね$"

RadioTower1F_Text_GruntM3Seen:
	.string "ついに　ラジオとうを\nのっとったぞ！\pこれで　みんなに　ロケットだんの\nほんとうの　おそろしさを\lあじわわせて　やる！\pおれたちの　こわさを\nみせて　やる！$"

RadioTower1F_Text_GruntM3Beaten:
	.string "つよすぎる！\nすみません　ボス‥$"

RadioTower1F_Text_GruntM3After:
	.string "おまえ　つよすぎる\pけいかくが　だいなしに\nなるかも‥　みんなに\lしらせなくては‥$"

RadioTower1F_Text_Directory:
	.string "1F　うけつけ\n2F　えいぎょうぶ\p3F　じんじぶ\n4F　せいさくぶ\p5F　きょくちょうしつ$"

RadioTower1F_Text_GotRadio:
	.string "{PLAYER}は　ポケギアの\nラジオカードを　もらった！$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "こちらは　ポケモン\nくじびきコーナー　です\pくじの　ばんごうと　あなたの\nポケモンの　IDが　あえば\lすてきな　しょうひんを\lさしあげます\pくじを　ひいて\nみますか？$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "また　あした\nおこし　ください$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "また　おこし　くださいね$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "くじを　1まい　どうぞ\n‥{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}‥{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}‥{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "くじの　ばんごうは\n{STR_VAR_1}です\pあなたの　ポケモンの　IDと\nあっているか　しらべますので\lしょうしょう　おまちください$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "おめでとう　ございます！\pてもちの　{STR_VAR_1}の\nIDが　くじの　ばんごうと\lあいました！$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "おめでとう　ございます！\pパソコンに　あずけている\n{STR_VAR_1}の　IDが\lくじの　ばんごうと　あいました！$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "ざんねんですが\nどの　ばんごうも　あいません$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "したの　2けたが　あったので\n3とう　です！\l{STR_VAR_1}を　どうぞ！$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "したの　3けたが　あったので\n2とう　です！\l{STR_VAR_1}を　どうぞ！$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "したの　4けたが　あったので\n1とう　です！\l{STR_VAR_1}を　どうぞ！$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "まあ！　5けた　ぜんぶ\nあいました！\pとくとう　です！\n{STR_VAR_1}を　どうぞ！$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "あら？\nもう　もてない　ようですね\pバッグを　かたづけてから\nまた　おこし　ください$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}さん　ですね？\nおまちして　おりました\pおあずかり　していた\nしょうひん　です$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "また　おこし　くださいね$"


