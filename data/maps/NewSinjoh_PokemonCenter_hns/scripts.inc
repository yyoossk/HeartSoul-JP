NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "ゆきで　みちが\nわかりにくいの\pどこも　おなじに\nみえるのよ\pだから　この　ちずは\nとても　たすかるわ！\pなんて　きれいな\nちほう　かしら！$"

NewSinjoh_Text_Artist:
	.string "この　かくれざとで\nすごい　インスピレーションを\lえたよ！\pこの　けしき　いきを　のむ\nほど　だと　おもわない？$"

Text_ItemGiveaway:
	.string "そうか！\nきみも　げいじゅつか\lなんだね！\pせいかつの　こまかな　ところに\nきづける　ものが　ちょうど\lひとつ　あまってるんだ！$"

NewSinjoh_Text_Artist_No:
	.string "まさか　かんこうきゃく\nぎらいの　ひと？\lうつくしさは　わかちあう\lものだよ$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "その　レンズ\nたのしんで　ね！$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "ニューシンジョウには\nさいしんの　ものは\lあまり　ないの\pでも　ポケモンセンターは\nあるから　たすかるわ$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER}は　シンジョウの\nちずを　よく　みた$"
