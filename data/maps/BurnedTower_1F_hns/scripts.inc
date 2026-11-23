BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "ミナキ『わたしは　ミナキ\pスイクンと　いう　ポケモンを\nおいかけて　いるんだ\pきみは‥？\p{PLAYER}くん？\nよろしく！\pこの　やけたとうに　スイクンが\nいるかも　しれないと　きいて\lしらべに　きたんだ\pでも　いったい　どこに\nいるんだろう？$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "ミナキ『この　やけたとうに\nスイクンが　いるかも\lしれないと　きいて\lしらべに　きたんだ\pでも　いったい　どこに\nいるんだろう？$"

BurnedTower_1FMortyText:
	.string "マツバ『エンジュの　ジムリーダーは\nでんせつの　ポケモンと\lいわれる　スイクン　エンテイ\lライコウを　しらべねば\lならないんだ\pミナキくんが　いるから\nいっしょに　とうを\lしらべる　ことにしたよ$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "‥‥‥‥‥‥‥‥‥‥\p‥なんだ　おまえか\pここに　でんせつの　ポケモンが\nすんでると　きいて\lきたんだが\pなにも　いない　じゃないか！\pこんな　ぼろい　ところまで\nきて　なにも　なし？\lふざけるな！\pぜんぶ　おまえの\nせいだ！$"

BurnedTowerSilver_WinText:
	.string "‥ふん！\pおれの　ポケモンが\nよわすぎる　から\lまけただけだ\pなさけない$"

BurnedTowerSilver_AfterText1:
	.string "‥まあ　いい\pどうせ　おまえに　でんせつの\nポケモンは　つかまえられない$"

BurnedTowerSilver_LossText:
	.string "‥ふん！\pだから　よわい　やつとは\nたたかいたく　ないんだ\lじかんの　むだだ$"

BurnedTowerSilver_AfterText2:
	.string "ふん！\pあなに　おちる　なんて\nたいした　てんさいだな！\pざまあみろ！$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "しんぱい　するな！\pほのおの　ほんとうの　ちからを\nいちばん　しってるのは\lおれたち　ひふきやろうだ！$"
BurnedTower_Text_NardBeaten:
	.string "あつい　しょうぶ\nありがとう！$"
BurnedTower_Text_NardAfter:
	.string "この　とうが　もえたのは\nかみなりが　おちた　からだ\pおれの　はく　ほのおなんか\nちっぽけな　もんさ‥$"

BurnedTower_Text_RichardoSeen:
	.string "やけたとうで　ぬすみの\nれんしゅう　ちゅうだ！\lまねするなよ！$"
BurnedTower_Text_RichardoBeaten:
	.string "ぷしゅーーーー$"
BurnedTower_Text_RichardoAfter:
	.string "わるい　ことは　おれに\nむいて　ないのかも‥$"
