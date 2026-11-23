SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "こわがらないで\nわるい　ものじゃ　ないよ\pこういう　ところには‥\nわるい　やつが　あつまる\pいずれ　もんだいを\nおこすんだ‥\pかんがえる　だけで\nはらが　たつ$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "おお！\nそれは　いかりまんじゅう！\pくれないか？\nたのむ！$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER}は　ちかつうろの\nおじさんに　いかりまんじゅうを\lあげた\pもぐっ！\pはらが　たつ！\pでも　うまい！\pもぐもぐ！\pうがー！　はらが　たつ！\pもぐもぐ！\pうがー‥\p‥‥‥‥‥‥‥‥ふう！\pすっかり　おちついた！\nまんじゅう　ありがとう！\lこれを　あげよう！$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "わざマシン64の　なかみは‥‥‥\pチク‥\n　　　　タク\lチク‥\l　　　　タク\lチク‥\l　　　　タク\lチク‥\l　　　　タク\lチク‥‥\l‥‥‥‥‥‥‥\l‥‥‥‥‥‥‥\lドッカーン！！$"

