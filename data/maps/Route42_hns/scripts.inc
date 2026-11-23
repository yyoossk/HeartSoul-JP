Route42_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

Route42_EventScript_Suicune_Trigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	release
	end

Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_up
	step_end

Route42_Movement_Suicune3:
	jump_in_place_up
	delay_2
	face_up
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_up
	unlock_facing_direction
	step_end

Route42_Movement_Eusine1:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route42_Movement_Eusine2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Text_EusineAdmireSuicune:
	.string "ミナキ『スイクン‥\nなんと　いさましい！\pなんと　すがすがしい！\nなんと　うつくしい！\pそして　なんと　はやい！$"

Route42_Text_EusineJealous:
	.string "{PLAYER}くん！\pきみは　スイクンが　あらわれる\nところに　いつも　いるようだね\pまあ　いい\nスイクンを　おもう　きもちは\lわたしの　ほうが　ずっと　うえだ‥\pわたしの　そふは‥　でんせつに\nとても　くわしかった\pそふから　スイクンの　はなしを\nたくさん　きいて　そだったんだ$"

Route42_Text_EusineWontGiveUp:
	.string "スイクン‥\nきみが　なにを　もとめて\lいるのか　わかるまで\lおいつづけるぞ‥\pきこえたか！$"


Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY_HNS, Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten, Route42_EventScript_RegisterTully
	goto_if_set FLAG_TULLY_HAS_ITEM_HNS, Route42_EventScript_TullyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route42_EventScript_RematchTully
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_RegisterTully::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route42_Text_TullyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TULLY_HNS
	release
	end

Route42_EventScript_RematchTully::
	trainerbattle_rematch TRAINER_TULLY_HNS, Route42_Text_TullyRematchIntro, Route42_Text_TullyRematchDefeat
	msgbox Route42_Text_TullyPostRematch, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyGiveItem::
	msgbox Route42_Text_TullyHasItem, MSGBOX_DEFAULT
	giveitem VAR_TULLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route42_EventScript_TullyNoRoom
	clearflag FLAG_TULLY_HAS_ITEM_HNS
	msgbox Route42_Text_TullyGaveItem, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyNoRoom::
	msgbox Route42_Text_TullyNoRoom, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN_HNS, Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE_HNS, Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end
Route42_EventScript_Item_Shadow_Claw::
    finditem ITEM_TM_SHADOW_CLAW
    end
Route42_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_Text_FisherTullySeen:
	.string "じぶんで　つった　ポケモンの\nちからを　みせて　やる！$"

Route42_Text_FisherTullyBeaten:
	.string "なに？　そんな　ばかな\nしんじられない！$"

Route42_Text_FisherTullyAfter:
	.string "じぶんで　つった　ポケモンで\nチャンピオンに　なりたいんだ\pそれが　つりの\nいちばんの　たのしみさ！$"

Route42_Text_HikerBenjaminSeen:
	.string "ああ　そとは　いいなあ！\nじゆうな　きぶんだ！$"

Route42_Text_HikerBenjaminBeaten:
	.string "がはは！　いい　しょうぶ\nだった！$"

Route42_Text_HikerBenjaminAfter:
	.string "おおきな　そらを　みあげれば\nまけたって　ちっぽけな　ことさ！$"

Route42_Text_PokemaniacShaneSeen:
	.string "おい！\pここは　おれの　ひみつの\nばしょだ！　よそものは　かえれ！$"

Route42_Text_PokemaniacShaneBeaten:
	.string "つきのいしを\nつかえば　よかった‥$"

Route42_Text_PokemaniacShaneAfter:
	.string "ずかんを　つくってるのか？\pじゃあ　めずらしい　ポケモンも\nしってるんだろうな！\pみせて　くれよ\nなあ　たのむよ！$"

Route42_Text_Sign1:
	.string "42ばんどうろ\pエンジュシティ　ー　チョウジタウン$"

Route42_Text_MtMortarSign1:
	.string "すりばちやま\pなかに　たきの　どうくつ$"

Route42_Text_TullyRegister:
	.string "じぶんで　つった　ポケモンで\nチャンピオンに　なりたいんだ\pそれが　つりの\nいちばんの　たのしみさ！$"

Route42_Text_TullyRematchIntro:
	.string "じぶんで　つった　ポケモンの\nちからを　みせて　やる！$"

Route42_Text_TullyRematchDefeat:
	.string "なに？　そんな　ばかな\nしんじられない！$"

Route42_Text_TullyPostRematch:
	.string "じぶんで　つった　ポケモンで\nチャンピオンに　なりたいんだ\pそれが　つりの\nいちばんの　たのしみさ！$"

Route42_Text_TullyHasItem:
	.string "おーい！　つりを　してたら\nいいもの　みつけたぜ！\pほら　やるよ！$"

Route42_Text_TullyGaveItem:
	.string "また　なにか　つりあげたら\nしらせるぜ！$"

Route42_Text_TullyNoRoom:
	.string "うーん　バッグが　いっぱいだな\pあきを　つくってから\nまた　こいよ$"
