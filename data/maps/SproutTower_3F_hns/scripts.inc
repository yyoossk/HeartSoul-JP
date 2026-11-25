SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	call KJ_EventScript_GiveHM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ちょうろう『たしかに\nうでの　ある　トレーナーじゃ\pやくそく　どおり\nひでんマシンを　やろう\pだが　ひとこと　いわせて\nもらう　ポケモンを\lもっと　だいじに　せよ\pおぬしの　たたかいかたは\nあまりにも　らんぼうじゃ\pポケモンは　たたかいの\nどうぐでは　ない‥$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "‥\n‥ふん！\pちょうろう　なんて\nいっても　よわいな\pとうぜんだ\pポケモンに　やさしく\nなんて　いってる　やつに\lまける　わけが　ない\pおれが　きょうみ　あるのは\nかてる　つよい　ポケモン\lだけだ\pよわい　ポケモンなんか\nどうでも　いい$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL}は\nあなぬけのヒモを　つかった！$"

SproutTower_Text_SageLi_Seen:
	.string "よくぞ　まいられた！\pマダツボミのとうは\nしゅぎょうの　ば\pひとと　ポケモンが\nきずなを　たしかめ\lあかるい　みらいを\lきずく　ところ\pわしが　さいごの　しれんじゃ\pおぬしと　ポケモンの\nきずなを　みせて\lもらおう！$"

SproutTower_Text_SageLi_Beaten:
	.string "おお　みごと！$"

SproutTower_Text_SageLi_TakeFlash:
	.string "おぬしと　ポケモン　なら\nこの　わざを　つかいこなせる\lじゃろう\pフラッシュの\nひでんマシンじゃ$"

SproutTower_Text_SageLi_FlashExplain:
	.string "フラッシュは　どんな　くらやみも\nてらす　わざじゃ\pたたかい　いがいで　つかうには\nキキョウジムの　バッジが\lひつようじゃ$"

SproutTower_Text_SageLi_AfterBattle:
	.string "たびで　まなび\nせいちょう　するのじゃぞ$"

SproutTower_Text_SageJin_Seen:
	.string "ポケモンで　さとりを\nひらく　ための　しゅぎょうじゃ！$"

SproutTower_Text_SageJin_Beaten:
	.string "しゅぎょうが\nたりぬ‥$"

SproutTower_Text_SageJin_AfterBattle:
	.string "ポケモンが　つよく　なれば\nトレーナーも　つよく　なる\pいや　まて　トレーナーが\nつよく　なれば　ポケモンも\lつよく　なるのじゃ$"

SproutTower_Text_SageTroy_Seen:
	.string "どれほど　ポケモンを\nしんじて　おるか\lみせて　もらおう$"

SproutTower_Text_SageTroy_Beaten:
	.string "うむ　その　しんらいは\nほんものじゃ！$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "ちょうろうは\nもう　すぐ　そこじゃ$"

SproutTower_Text_SageNeal_Seen:
	.string "ちょうろうの　ひでんマシンは\nまっくらやみも　てらすぞ$"

SproutTower_Text_SageNeal_Beaten:
	.string "ひかって　おるのは\nわしの　あたまじゃ！$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "おぬしの　たびに\nひかり　あれ$"

SproutTower_Text_3F_Painting:
	.string "マダツボミの\nはくりょく　ある　え　だ$"
