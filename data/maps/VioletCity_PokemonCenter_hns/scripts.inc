VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}くん　ひさしぶり\pウツギはかせに　きみを\nさがすように　たのまれたんだ\pまた　たのみたい　ことが\nあるんだって\pポケモンの　タマゴを\nあずかって　くれるかい？$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}くん　ひさしぶり\pウツギはかせに　きみを\nさがすように　たのまれたんだ\pまた　たのみたい　ことが\nあるんだって\pポケモンの　タマゴを\nあずかって　くれるかい？\pあ　まって‥　まず　てもちに\nあきを　つくらないと$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "タマゴの　なかで　そだたないと\nポケモンは　うまれないって\lわかったんだ\pそれに　げんきな　ポケモンと\nいっしょに　いないと\lかえらないんだ\p{PLAYER}くん　たよれるのは\nきみ　だけなんだ$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "そうそう　うまれたら　これが\nやくに　たつかも$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "あれ　もう　ポケモンを\nもてないみたいだね\pタマゴの　ぶんの　あきを\nつくるまで　ここで　まってるよ$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "あれ　もう　ポケモンを\nもてないみたいだね\pだいじょうぶ　タマゴは\nマサキの　パソコンに\lおくって　おいたよ$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "そ‥　そんな‥　ウツギはかせに\nたのまれたのに‥$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "ポケモンが　かいふくする\nあいだ　ほんを　よむのが\lだいすきなの$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "タンバの　ともだちと\nつうしんで　たいせん　したんだ\pモバイルアダプタを　つなげば\nとおくの　ともだちとも\lつうしん　できるんだよ$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "ポケモンを　パソコンに　あずける\nしくみは　マサキって　ひとが\lつくったんだって$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "3ねんほど　まえの　ことだ\pロケットだんが　ポケモンを\nつかって　わるさを　していた\pだが　せいぎは　かった\nひとりの　しょうねんが\lやつらを　かいさん　させたんだ$"

VioletCity_PokeCenter_Text_Youngster:
	.string "ポケモンは　かしこいんだ\nみとめて　いない　トレーナーの\lいうことは　きかない\pちゃんと　ジムバッジが　ないと\nかってに　うごいちゃうんだ$"
