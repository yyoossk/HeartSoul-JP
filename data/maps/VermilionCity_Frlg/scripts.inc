VermilionCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_KJ_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	end

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_KJ_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_KJ_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_KJ_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	goto KJ_EventScript_ShipToJohto
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_KJ_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_KJ_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_KJ_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_KJ_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_KJ_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_KJ_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

@ Unreachable
Vermilion_EventScript_Unused::
	release
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_KJ_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	goto KJ_EventScript_ShipToJohtoTrigger
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_KJ_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop_Kj::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign_Kj::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign_Kj::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign_Kj
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_GrimerMultipliesInSludge::
	.string "わたし　スポーツの　あとは\n"
	.string "あせで　ベトベター！\p"
	.string "…しってる？　ベトベターって\n"
	.string "うみの　ヘドロから　うまれたの$"

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
	.string "みたかね！　いま　みなとに\n"
	.string "サント・アンヌごう　という\l"
	.string "ふねが　きとるぞ！$"

VermilionCity_Text_SSAnneHasDepartedForYear::
	.string "おお！　サント・アンヌごう\n"
	.string "しゅっぱつ　して　いったか！\p"
	.string "つぎに　クチバに　くる　のは\n"
	.string "らいねんの　いまごろ　じゃな…$"

VermilionCity_Text_BuildingOnThisLand::
	.string "わし　じぬし！\n"
	.string "この　しかくの　ばしょ\l"
	.string "ぜーんぶ　わしの　とち！\p"
	.string "ここに　ビル　たてようと　おもって\n"
	.string "ポケモンに　じならし　させとる！$"

VermilionCity_Text_Machop::
	.string "ワンリキー“ごおーっ　ごごごー$"

VermilionCity_Text_MachopStompingLandFlat::
	.string "ワンリキーは　うなりながら\n"
	.string "じめんを　ならしている！$"

VermilionCity_Text_SSAnneVisitsOnceAYear::
	.string "サント・アンヌごうは\n"
	.string "ゆうめいな　ごうか　きゃくせん！\p"
	.string "１ねんに　１ど　だけ\n"
	.string "クチバこう　に　とまるんだ！$"

VermilionCity_Text_CitySign::
	.string "ここは　クチバ　シティ\n"
	.string "クチバは　オレンジ　ゆうやけのいろ$"

VermilionCity_Text_SnorlaxBlockingRoute12::
	.string "…　おしらせの　チラシだ！\p"
	.string "さいきん…　１２ばん　どうろに\n"
	.string "いねむり　ポケモンが　しゅつぼつ\l"
	.string "とおれない　ことが　あります！\p"
	.string "そういう　とき　シオン　タウンへ\n"
	.string "いく　かたは　イワヤマトンネルを\l"
	.string "とおって　ください！\p"
	.string "…　クチバ　けいさつ　より$"

VermilionCity_Text_PokemonFanClubSign::
	.string "こちら　ポケモン　だいすき　クラブ\n"
	.string "ポケモンずき　だれでも　かんげい！$"

VermilionCity_Text_GymSign_Kj::
	.string "クチバ　シティ　ポケモン　ジム\n"
	.string "リーダー　マチス\l"
	.string "イナズマ　アメリカン！$"

VermilionCity_Text_VermilionHarbor::
	.string "クチバ　みなと　いりぐち$"

VermilionCity_Text_WelcomeToTheSSAnne::
	.string "ようこそ　サント・アンヌ　ごうへ！$"

VermilionCity_Text_DoYouHaveATicket::
	.string "ようこそ　サント・アンヌ　ごうへ！\p"
	.string "ちょっと　まって！\n"
	.string "おきゃくさん　チケットは？$"

VermilionCity_Text_FlashedSSTicket::
	.string "{PLAYER}は　せんいんに\n"
	.string "ふねのチケットを　みせた！\p"
	.string "はい！　けっこう　です！\n"
	.string "ようこそ　サント・アンヌ　ごうへ！$"

VermilionCity_Text_DontHaveNeededSSTicket::
	.string "{PLAYER}は　せんいんに\n"
	.string "チケットを　みせようとした…\l"
	.string "チケットが…　ない…！\p"
	.string "…もうしわけ　ありません！\p"
	.string "はいれる　のは\n"
	.string "チケットの　ある　かた　だけです$"

VermilionCity_Text_TheShipSetSail::
	.string "ふねは　しゅっこうしました$"

VermilionCity_Text_BoardSeagallopTriPass::
	.string "トライパスを　おもち　なのですね！\n"
	.string "せんようせん　シーギャロップに\l"
	.string "おのりに　なりますか？$"

VermilionCity_Text_Seagallop7Departing::
	.string "では　どうぞ！\n"
	.string "シーギャロップ　ハイスピード７は\l"
	.string "すぐに　しゅっこう　しますよ！$"

VermilionCity_Text_BoardSeagallopRainbowPass::
	.string "レインボーパスを　おもち　ですね！\n"
	.string "せんようせん　シーギャロップに\l"
	.string "おのりに　なりますか？$"

VermilionCity_Text_OhMysticTicketTakeYouToNavelRock::
	.string "それは　しんぴのチケット…！\n"
	.string "わかりました\p"
	.string "あなたを　へそのいわへ\n"
	.string "いつでも　おつれ　しましょう！$"

VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland::
	.string "それは　オーロラチケット…！\n"
	.string "わかりました\p"
	.string "あなたを　たんじょうのしまへ\n"
	.string "いつでも　おつれ　しましょう！$"

VermilionCity_Text_BoardSeagallopFerry::
	.string "せんようせん　シーギャロップに\n"
	.string "おのりに　なりますか？$"

VermilionCity_Text_Seagallop10Departing::
	.string "では　どうぞ！\p"
	.string "とくべつ　せんようせん\n"
	.string "シーギャロップ　ハイスピード１０\l"
	.string "はっしん　します！$"

VermilionCity_Text_Seagallop12Departing::
	.string "では　どうぞ！\p"
	.string "とくべつ　せんようせん\n"
	.string "シーギャロップ　ハイスピード１２\l"
	.string "はっしん　します！$"

VermilionCity_Text_Route2AideHasPackageForYou::
	.string "あ　{PLAYER}{KUN}！\n"
	.string "げんきに　やってますか？\l"
	.string "ぼくですよ\l"
	.string "オーキドはかせの　じょしゅ　です！\p"
	.string "ほかの　じょしゅには　あいました？\n"
	.string "はかせから　{PLAYER}{KUN}への\l"
	.string "おくりものを　もって\l"
	.string "でかけた　はずなんだけど…\p"
	.string "２ばんどうろ　あたりで\n"
	.string "{PLAYER}{KUN}を　さがす　って\l"
	.string "いってたから　そのへんかな？\p"
	.string "もし　２ばんどうろに　いったら\n"
	.string "さがして　みてよ！$"

