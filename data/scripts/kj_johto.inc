@ カントー＆ジョウト: カントーの殿堂入りのあと → オーキドから チケット → クチバの港 → 3年後 ワカバタウン

KJ_EventScript_OakJohtoTicket::
	goto_if_set FLAG_KJ_GOT_JOHTO_TICKET, KJ_EventScript_OakGoToVermilion
	msgbox KJ_Text_OakChampion
	giveitem ITEM_SS_TICKET
	setflag FLAG_KJ_GOT_JOHTO_TICKET
	msgbox KJ_Text_OakExplainTicket
	release
	end

KJ_EventScript_OakGoToVermilion::
	msgbox KJ_Text_OakExplainTicket
	release
	end

KJ_EventScript_ShipToJohtoTrigger::
	goto_if_unset FLAG_KJ_GOT_JOHTO_TICKET, KJ_EventScript_NoJohtoTicketTrigger
	call KJ_EventScript_AskBoard
	goto_if_eq VAR_RESULT, NO, KJ_EventScript_NotBoardingTrigger
	goto KJ_EventScript_SailToJohto
	end

KJ_EventScript_NoJohtoTicketTrigger::
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

KJ_EventScript_NotBoardingTrigger::
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

KJ_EventScript_ShipToJohto::
	goto_if_unset FLAG_KJ_GOT_JOHTO_TICKET, KJ_EventScript_NoJohtoTicket
	call KJ_EventScript_AskBoard
	goto_if_eq VAR_RESULT, NO, KJ_EventScript_NotBoarding
	goto KJ_EventScript_SailToJohto
	end

KJ_EventScript_NoJohtoTicket::
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

KJ_EventScript_NotBoarding::
	release
	end

KJ_EventScript_AskBoard::
	msgbox KJ_Text_SailorJohtoShip, MSGBOX_YESNO
	return

KJ_EventScript_SailToJohto::
	msgbox KJ_Text_SailorDeparting
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SHIP
	waitse
	delay 30
	setflag FLAG_KJ_JOHTO_STARTED
	special KJ_StartJohto
	message KJ_Text_ThreeYearsLater
	waitmessage
	waitbuttonpress
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	warp MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_2F_HNS, 1
	waitstate
	releaseall
	end

KJ_Text_OakChampion::
	.string "オーキド“おお　{PLAYER}！\n"
	.string "ついに　チャンピオンに　なったか！\p"
	.string "じつはな　わしの　しりあいが\n"
	.string "ジョウトちほうで　ポケモンの\l"
	.string "けんきゅうを　しておる\p"
	.string "ジョウトにも　カントーには　いない\n"
	.string "ポケモンが　たくさん　おるのじゃ\p"
	.string "これを　もって　いきなさい！$"

KJ_Text_OakExplainTicket::
	.string "オーキド“それは　ジョウト　いきの\n"
	.string "ふねの　チケットじゃ\p"
	.string "クチバの　みなとから\n"
	.string "ワカバタウン　いきの　ふねが　でておる\p"
	.string "あたらしい　ぼうけんが\n"
	.string "まって　おるぞ！$"

KJ_Text_SailorJohtoShip::
	.string "その　チケットは！\n"
	.string "オーキドはかせから　きいてますよ\p"
	.string "ジョウトの　ワカバタウン　いきの\n"
	.string "ふねに　のりますか？$"

KJ_Text_SailorDeparting::
	.string "では　しゅっこう　します！$"

KJ_Text_ThreeYearsLater::
	.string "……　それから\n"
	.string "３ねんの　つきひが　ながれた……$"
