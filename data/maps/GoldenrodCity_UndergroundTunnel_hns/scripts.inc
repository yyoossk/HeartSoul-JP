GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "くろい　ふくの　ロケットだんが\nうろうろ　していましたが‥\pなにごとかと　おもいました\nあなたが　ロケットだんと\lたたかったのですね？\lみごとです！\pあなたなら　でんせつの\nポケ‥　にも　たちむかえる\lかもしれません$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "ほほほ！　なんでも\nありません　わたくしは\lもう　いかなくては$"

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC_HNS, GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU_HNS, GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC_HNS, GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD_HNS, GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother2
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
	.string "ポケモンサロンへ　ようこそ！\pおれは　カットきょうだいの\nおとうとの　ほう　やすい　ほうだ\pたったの　300円で　ポケモンを\nかっこよく　して　やるぜ\pどうだい？$"

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
	.string "よし　どの　ポケモンに\nする？$"

GoldenrodUnderground_Text_YoungerBrotherLookCool:
	.string "よし！　かっこよく\nして　やるぜ！$"

GoldenrodUnderground_Text_YoungerBrotherAllDone:
	.string "ほら！　できあがり！$"

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
	.string "いらない？　ざんねんだな！$"

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
	.string "おかねが　ちょっと\nたりない　みたいだな$"

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
	.string "カットは　1にち　1かい\nまで　なんだ\pわるいが　きょうは\nもう　おしまいだ$"



GoldenrodUnderground_Text_OlderBrotherOffer:
	.string "いらっしゃい！\pポケモンサロンを　やってる\nものだ！\pおれは　カットきょうだいの\nあにの　ほう　うでの　いい　ほうだ\pたったの　500円で　ポケモンを\nうつくしく　して　やろう\pどうだい？$"

GoldenrodUnderground_Text_OlderBrotherAskWhich:
	.string "どの　ポケモンに　する？$"

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
	.string "よし！　うつくしく　なるのを\nみていてくれ！$"

GoldenrodUnderground_Text_OlderBrotherAllDone:
	.string "はい！　できあがり！$"

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
	.string "そうかい？　ざんねんだ！$"

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
	.string "それじゃ　おかねが\nたりないな$"

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
	.string "カットは　1にち　1かいだけ\nきょうは　もう　おしまいだ$"

GoldenrodUnderground_Text_SupernerdEricSeen:
	.string "ゲームコーナーを\nおいだされちゃったよ\pポケモンを　つかって\nずるを　しようと　したら‥$"

GoldenrodUnderground_Text_SupernerdEricBeaten:
	.string "‥ぶつぶつ‥$"

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
	.string "せいせいどうどう\nやるしか　ないか‥$"

GoldenrodUnderground_Text_SupernerdTeruSeen:
	.string "しょうぶで　タイプの　あいしょうを\nかんがえてる？\pタイプの　ゆうりを　しってれば\nしょうぶは　うまく　いくよ$"

GoldenrodUnderground_Text_SupernerdTeruBeaten:
	.string "いてて　いてて！$"

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
	.string "タイプの　あいしょうは\nしってるんだ\pでも　ぼくは　ひとつの　タイプの\nポケモンしか　つかわないんだ$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
	.string "ぼくの　ポケモン\nカット　したばかり　なんだ！\pどれだけ　つよいか\nみせて　あげる！$"

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
	.string "あいえーっ！$"

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
	.string "カット　して　あげると\nポケモンが　なついて　くれるよ$"

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
	.string "めずらしい　ポケモンを\nもってる　みたいだね\pみせて　よ！$"

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
	.string "ぐああ！　まけた！\nむかつく！$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "ゆうべ　じてんしゃやの\nちかくを　あるいてたら\lやねの　うえから　みられてる\lような　きが　したんだ‥$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
	.string "ずかんを　つくってるの？\nいい　こと　おしえて　あげる\p33ばんどうろの　やまおとこ\nツトムは　いい　ひとだよ\pめずらしい　ポケモンを　みたら\nでんわ　してくれるよ$"

GoldenrodUnderground_Text_DoorsLocked:
	.string "とびらに　かぎが\nかかっている‥$"

GoldenrodUnderground_Text_DoorIsOpen:
	.string "とびらは　あいている$"

GoldenrodUnderground_Text_KeyOpenedDoor:
	.string "ちかの　かぎで\nとびらが　あいた$"

GoldenrodUnderground_Text_NoEntry:
	.string "これより　さき\nたちいり　きんし$"
