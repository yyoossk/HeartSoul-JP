SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
	.string "ダイゴ『ん？$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "ダイゴ『{PLAYER}くん！\pその　めは　どこに　いても\nわかるよ\pこんな　きたまで\nどうしたんだい？\p‥‥‥‥‥‥‥\pなるほど　ニューシンジョウの\nまいこはんが　ちょうさの\lてつだいに　よこしたのか\pそれなら　いままでの\nことを　はなそう$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "ダイゴ『この　いせきの　ことを\nきいて　じぶんの　めで\lみたく　なったんだ\pデボン　コーポレーションで\nチームを　くんで\lちょうさに　きたんだよ\pなにが　うまって　いるか\nわからない\pもう　かなりの　ことが\nわかって　きたよ$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "げんごがくしゃ『いせきの\nもじは　まだ　ぜんぶ\lかいどく　できて　いませんが\lわかった　ことも　あります\pふしぎな　プレートが\n17まい　あるんです\pいせきと　かんけいが\nあるようですが　まだ\l1まいしか　みつかって\lいません\pのこりは　すごい　ちからの\nポケモンと　トレーナーが\lまもって　いる　そうです$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "ダイゴ『と　いうわけだ\n{PLAYER}くん\pのこりの　プレートを\nまもる　キングの　ポケモンは\lぼくの　チームには\lつよすぎる\pそれに　ぼくは　ここで\nけんきゅうを　みなければ\lならない\pでも　きみなら　できると\nおもう　てつだって\lくれるかい？$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "ありがとう\pもじに　よると　プレートは\nシンジョウ　じゅうの\lキングの　ポケモンと\lつよい　トレーナーが\lもって　いる\pなにか　わかったら\nポケギアに　でんわ　するよ\pありがとう　{PLAYER}くん$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "ほんとうに？\pなにが　うまって　いるか\nわからないよ\pかんがえ　なおして\nくれないかい？$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "ダイゴ『{PLAYER}くん！\p17まいの　プレートを\nあつめたら　なにが　おこるか\lわかった　きが　する\pなにかを‥\l‥‥‥‥‥‥‥‥‥‥$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "ダイゴ『この　めで\nたしかめなくては！\pそとへ　{PLAYER}くん！$"

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "ダイゴ『やあ　{PLAYER}くん\pいままでに　プレートは\n{STR_VAR_1}まい　わるくないね\pぜんぶ　あつまったら　なにが\nおこるのか　きになるよ\pさて　なにを　みつけて\nくるかな$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "ダイゴ『やあ　{PLAYER}くん\pいままでに　プレートは\n{STR_VAR_1}まい　わるくないね\pあの　へやは\nしらべたかい？\lなんとも　ふしぎだよ$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "ダイゴ『やあ　{PLAYER}くん\pいままでに　プレートは\n{STR_VAR_1}まい　じゅんちょうだね\pひらいた　へやは　ホウエンちほうの\nある　へやに　とても\lにて　いるんだ\pそこにも　それぞれ\nでんせつの　ポケモンが\lいた\pでも　ホウエンで　みつかったのは\n3つ　だけ\pここには　すくなくとも\n6つ　ある\pつぎは　なにが\nみつかるかな$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "ダイゴ『{PLAYER}くん！\pこの　ちょうさは　いっしょうに\nいちどの　けいけん　だった\pこの　いせきの　ことを　きいた\nときから　かんじて　いたんだ\pなにか　すごい　ものが\nみつかると\pぼくの　よかんは\nよく　あたるんだ\pいろいろ　ありがとう\nチャンピオン\pこれから　どこへ\nいくんだい？\pまた　どこかで\nあえると　いいね$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
	.string "ちちゅうレーダーで　この\nたにに　6つの　ちかしつが\lあると　わかりました\p5つは　ちひょうに　ちかく\n1つは　もっと　ふかくに\lうまって　います$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "ずっと　きかいを　したに\nむけて　ちかを　しらべて\lいました\pうえに　むけるべき\nだったのに！$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "あの　プレートが　もっとも\nつよい　ポケモンと\lかんけい　していた？？\pもっと　しらべる\nじかんが　ほしかった$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
	.string "うう‥\nかいどく　する　もじが\lおおすぎる‥\pホウエンちほうには\nこんな　ものは　ないのに$"
SinjohRuins_Lab_Text_LinguistDuring:
	.string "もじを　かいどく　した\nときは　おどろきました！\pダイゴさんに　いう　まえに\nなんども　たしかめましたよ！\pだって　ポケモンの\nかみさま　ですよ？\pしんじられません$"
SinjohRuins_Lab_Text_LinguistAfter:
	.string "この　ちょうさは\nたのしかった　です\l{PLAYER}さん\pげんちの　ちょうさを\nしてくれて　ありがとう$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "この　ちいきに　ぶんめいが\nあった　ことで　れきしの\lとらえかたが　かわります\pみつかった　いぶつの\nおおくは　1000ねん\lいじょう　まえの　もの\pシンオウちほうの　いぶつと\nねんだいが　いっち　します\pでも　あなたが　みつけた　ふえは‥\nもっと　ふるい　ようです$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "あの　プレート‥\nシンオウちほうとの\lつながり‥\lあの　ふえ‥\lすべて　つじつまが\lあって　きた$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "あなたが　ほりおこす\nてつだいを　して　くれた\lものの　れきしてきな　かちは\lはかりしれません\l{PLAYER}さん\pほんとうに　ありがとう$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
	.string "ガウ　ガウ！！$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
	.string "ガーディの　ボールの\nようだ‥\lそっとして　おこう$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
	.string "この　すばらしい　こたいを\nみて！\pこの　ガーディは　せかいの\nどこの　ガーディとも\lちがうの\pDNAの　ぶんせきで　ほかの\nちほうの　ガーディと\lそせんが　おなじと\lわかったわ\pでも　せいかくも　タイプも\nおおきく　ちがうの\pこだいの　シンオウの　きろくの\nガーディの　ようすと\lいっち　するわ\pむかしは　この　しゅが\nこだいの　シンオウまで\lひろく　すんで　いた\lのかも　しれない$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "あの　かいだんの　うえの\nいきものが　ほんとうに\lポケモンの　かみさま　なら\lそれが　さいしょの\lそせん　なのかしら？$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "この　ちょうさで　リージョン\nフォームや　しんかの\lわかれかたの　データが\lたくさん　あつまったわ\lありがとう　{PLAYER}$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
	.string "10ねん　おれは　この\nあれちを　あるいて　きた\pいや　20ねんだな\pそして　ある　ひ　おおきな\nいしの　はしらと　ぶきみな\lしんでんを　みつけたんだ\pそれが　シンジョウいせき\nだと　きいた\pそのころは　むらの\nことも　しらなかった\pなかまに　すこし\nはなした　だけ　なのに\lうわさは　すぐ　ひろまった\pこんなに　ちゅうもく\nされるとは　おもわなかった\pなんだか　ふくざつな\nきぶん　だよ$"
SinjohRuins_Lab_Text_HikerDuringAfter:
	.string "ないしょ　だぞ　{PLAYER}\nここを　みつけた　とき\lやまの　うえの　しんでんも\lみて　いたんだ\pおれの　むねに\nしまって　おいた\pいせきの　ことは\nもう　しゃべりすぎたからな\pまあ　なんとか\nうまく　いった　みたいだな$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
	.string "けんきゅうにっし　1\n1975ねん　5がつ3にち\pいせきの　ばしょに\nとうちゃく　した\pシロガネやまの　きびしい\nさむさが　ここまで\lつたわって　くる‥\pまもなく　はっくつはんが\nやまを　こえて　くる‥\lあしもとに　なにが　ねむるか\lたのしみで　ならない！$"

SinjohRuins_Lab_Text_Note2:
	.string "けんきゅうにっし　2\n1975ねん　5がつ10にち\pいっしゅうかん　ほったが\nなにも　でない\pこおりは　おそろしく\nあつく　いわは　きかいを\lこわして　しまう\pカイリキーでも　きずひとつ\nつけられない\pここは　なんなのだ？\pかならず　つきとめる$"

SinjohRuins_Lab_Text_Note3:
	.string "けんきゅうにっし　3\n1975ねん　5がつ14にち\pなにも　しなければ\nまえへは　すすめない\pわたしは　ただの\nさぎょういん\pだが　こおりを　くだく\nほうほうを　おもいついた\pいや　とかす\nほうほうだ\pほのおタイプの　ポケモンが\nたくさん　ひつようだ\pだが　シンオウから　どうやって\nここまで　つれて　くる？$"

SinjohRuins_Lab_Text_Note4:
	.string "けんきゅうにっし　4\n1975ねん　5がつ21にち\pいそがしかった\pわたしの　かんがえで\nこおりを　とかせた\lだが　ほのおタイプは\lくにから　つれて　こなかった\pボスが　げんちで\nあつめろと　いったのだ\pちかくの　むらの\nおんせんで　みつけた‥\pそして　ひつようなだけ\nうばった‥\pほこれる　ことでは　ない\nだが　しんぽには　ぎせいが\lつきものだ\pこおりは　なくなった\pへやが　6つと　まんなかに\nふういん　された\lしんでんが　ある\pたてものの　つくりは　こだいの\nカンナギの　ひとびとの\lものかも　しれない‥\pわれらの　そせんだ　きたへ\nうつりすむ　まえの\pボスは　すぐに　しんでんを\nあけたがって　いる‥$"

SinjohRuins_Lab_Text_Note5:
	.string "けんきゅうにっし　5\n1975ねん　6がつ2にち\pついに　あけた‥\pおおよろこび　すると\nおもって　いた‥\pだが　しんでんから\nふきだした　エネルギーで\lなかまを　うしなった\pあけるのを　てつだった\nポケモンも‥\lどうか　やすらかに‥\p‥‥‥‥‥‥‥‥‥\pとにかく\pしんでんは　ひらいたが\nなぞが　ふえた　だけだ\pなかには　でんせつの\nポケモンも　たからも\lなかった\pぶっしは　つきかけ\nせいかは　なにも\lない‥$"

SinjohRuins_Lab_Text_Note6:
	.string "けんきゅうにっし　6\n1975ねん　6がつ10にち\pちょうさは　おわった\nほかの　ものは\lひきあげの　じゅんびを\lしている\pだが　わたしは\nできない\pこの　にんむを\nすてられない\lあれだけの　ものを\lうしなったのだ\pわたしは　ここに\nのこる$"

SinjohRuins_Lab_Text_Note7:
	.string "けんきゅうにっし　7\n1975ねん　9がつ10にち\pここに　きて　なんかげつも\nたった\pほかの　ものは　さった\pいまは　わたしと　さぎょうの\nために　つかまえた\lポケモン　だけだ\pポケモンを　きたえて\nいる\pとくに　バクフーンを\pしんでんの　したに　なにが\nあるのか　つきとめねば$"

SinjohRuins_Lab_Text_Note8:
	.string "けんきゅうにっし　8\n1975ねん　9がつ15にち\pしっぱい\p‥‥‥‥‥‥‥‥‥‥‥\pわたしの　ポケモンが‥\p6ぴき　ちからを　あわせて\nしんでんの　にせの　かべを\lうちやぶった\pだが　それは　まって\nいた‥\pきょじんの　ような\nなにかが‥\pときはなたれた　エネルギーは\nまえと　おなじ　だった\pポケモンは　みな\nやられた‥\pしかも　あの　かいぶつは\nかべを　また　ふさいだ\pもう　かえれない\nだれも　わたしと\lわからないだろう‥\pこの　ばしょが　わたしを\nかえて　しまった‥\pむらの　ひとと\nはなして　みよう\pかれらは　わたしの　した\nことを　しらない\pなかまは　とうに　さった\nから　ただの　まよった\lハイカーだと　おもうだろう\pもう　ここ　いがいに\nいばしょは　ない$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
	.string "みほんや　いぶつが\nきちんと　ならべられた\lかざりだなだ！$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
	.string "エックスせん　いんさつしつ$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
	.string "いせきの　なかで　みつかった\nいぶつだ！$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "てんかいのふえが\nはんのう　している\lふえを　ふきますか？$"

SinjohRuins_Lab_Text_DropedItem:
	.string "キングの　{STR_VAR_1}が\nどうぐを　おとした‥$"

SinjohRuins_Lab_Text_StevenName:
	.string "ダイゴ$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "ダイゴ『{PLAYER}くん\pいま　いせきで\nゆれが　あった\pみんな　ぶじ　だから\nしんぱい　しないで\pおもしろい　ことに　いせきの\nしたの　ちかしつの　ひとつが\lひらいたんだ\pなかの　もようは　ホウエンの\nあるものを　おもいださせる\pじかんが　あったら\nみに　きて　くれ$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "ダイゴ『{PLAYER}くん\pさがしものは　どうだい？\pまた　ゆれが　あったよ\nこんどは　ふたつめの\lちかしつが　ひらいた\pまた　おきても　いいように\nちしつがくしゃに　きかいを\lよういして　もらって　いる\pほるほど‥\nなぞが　ふえて　いく$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "ダイゴ『{PLAYER}くん\pいせきで　また\nゆれが　あった\pデータから　おもしろい\nことが　わかった\pじしんでは　なかったんだ\pちかに　たまった　なにかの\nエネルギーが　うちがわから\lいわを　わったんだ\pいったい　なにが‥\nしょうじき　わからない$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "ダイゴ『{PLAYER}くん\pまた　ゆれだ　また\nちかしつが　ひらいた\pタイミングの　きまりが\nまだ　わからない\pねえ　{PLAYER}くん‥\nきみが　なにか　して\lいる　わけじゃ　ないよね？\pいや　そんな　はずは　ないか$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "ダイゴ『{PLAYER}くん\pいま　また　プレートを\nみつけたかい？\p‥‥‥‥‥‥‥‥‥\pやっぱり\pこの　いせきに　ねむる\nでんせつの　ポケモンは\lきみに　こたえて　いるんだ\pまるで　みつけて　ほしい\nみたいに\pぼくの　よかんは　よく　あたる\nきみを　うたがうべきじゃ\lなかったね$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "ダイゴ『{PLAYER}くん\pもう　すぐだ\nそう　かんじる\p‥‥‥‥‥‥‥‥‥\pきみも　じぶんの　めで\nたしかめに　きて　くれ$"

