Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "やあ　やあ！　きみが\n{PLAYER}くん　だね\pウツギはかせから\nくると　きいて　いたよ$"

MrPokemonHouse_Text_Intro2:
	.string "これを　ウツギはかせに\nしらべて　ほしいんだ$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER}は\nふしぎな　タマゴを　もらった$"

MrPokemonHouse_Text_Intro3:
	.string "しりあいの　ふうふが\nあずかりやを　やっていてね\pその　タマゴを\nもらったんだ\pきょうみが　わいたので\nウツギはかせに　メールを\lおくったんだよ\pポケモンの　しんかなら\nウツギはかせが　いちにんしゃ\lだからね$"


MrPokemonHouse_Text_Intro4:
	.string "ここに　いる　オーキドはかせも\nみとめて　いるよ$"

MrPokemonHouse_Text_Intro5:
	.string "わたしの　よそうが　ただしければ\nウツギはかせなら\lわかる　はずだ$"

MrPokemonHouse_Text_Heal:
	.string "ウツギはかせの　ところへ\nもどるのかい？\pほら　ポケモンを\nやすませて　あげよう$"

MrPokemonHouse_Text_DependingOnYou:
	.string "たのんだよ！$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "じんせいは　たのしい！\nいつも　あたらしい\lはっけんが　あるからね$"

MrPokemonHouse_Text_OakIntro:
	.string "オーキド『ほう！　きみが\n{PLAYER}くんか！\pわしは　オーキド！\nポケモンの　けんきゅうしゃじゃ\pふるい　ともだちの\nポケモンじいさんを\lたずねて　きたのじゃ\pウツギくんの　つかいで　くると\nきいて　まって　いたのじゃよ\pおや！　これは\nめずらしい　ポケモン！\pどれどれ‥\nふむ　なるほど！\pウツギくんが　つかいに\nポケモンを　もたせた\lわけが　わかったぞ\pウツギくんや　わしの　ような\nけんきゅうしゃに　とって\lポケモンは　ともだちじゃ\pきみなら　ポケモンを　だいじに\nすると　おもったのじゃろう\p‥そうじゃ！\pきみは　たのもしそうじゃ\nわしを　てつだって\lくれんか？\pほれ　これが　さいしんばんの\nポケモンずかんじゃ\pみたり　つかまえたり　した\nポケモンの　データを\lじどうで　きろく　する\pハイテクな　ずかんじゃ！\pすみか　しんかの　しかた\nわざも　わかるぞ$"

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER}は\nポケモンずかんを　もらった！$"

MrPokemonHouse_Text_OakParting:
	.string "いろんな　ポケモンに　あって\nずかんを　かんせい\lさせて　おくれ！\pおっと　ながいを\nしてしまった\pいつもの　ラジオばんぐみで\nコガネへ　いかねば\p{PLAYER}くん\nたのんだぞ！$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "む？　その　ウロコ！\nそれは　なんだい？\lあかい　ギャラドス？\pめずらしい！\nほ　ほしい‥\p{PLAYER}くん\nこうかん　して　くれないか？\pオーキドはかせに　もらった\nがくしゅうそうちを\lあげるよ$"

MrPokemonHouse_Text_Disappointed:
	.string "ざんねんだ\nとても　めずらしい\lものなのに$"

MrPokemonHouse_Text_ExpShare:
	.string "きみに　とくべつな\nものも　あるんだ$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "がいこくの　ざっしが\nぎっしり　つまっている\pタイトルも\nよめない‥$"

MrPokemonHouse_Text_BrokenComputer:
	.string "おおきな　コンピューターだ\nうーん　こわれている$"

MrPokemonHouse_Text_StrangeCoins:
	.string "ふしぎな　コインが\nやまもり！\pがいこくの　もの\nかもしれない‥$"

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER}は\nがくしゅうそうちを　もらった！$"
