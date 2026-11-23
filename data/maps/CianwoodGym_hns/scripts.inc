CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "タンバシティ　ポケモンジム$"

CianwoodGym_Text_GymStatueCertified:
	.string "タンバシティ　ポケモンジム\pシジマ　にんてい　トレーナー\n{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "わはははは　{PLAYER}！\nいまは　しゅぎょう　ちゅうだ！\pまた　しょうぶ　したいなら\nヤマブキの\lかくとうどうじょうへ　こい！$"

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "どうじょうで　まって　おるぞ！\nわははははは$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "わははは！\pよくぞ　ここまで\nきた！\pいっておくが\nわしは　つよいぞ！\pわしの　ポケモンは　いわを\nくだき　ほねを　くだく！\pみておれ！$"

CianwoodGym_Text_ChuckIntro2:
	.string "シジマ『うぐぐ‥\n‥\pうおりゃあ！$"

CianwoodGym_Text_ChuckIntro3:
	.string "どうだ！　こわく\nなったか？\pなに？　ポケモンと\nかんけい　ないだと？\pその　とおり！\pさあ　しょうぶだ！$"

CianwoodGym_Text_ChuckLoss:
	.string "な？　なに？　まけた？\pたいしたものだ！\nショックバッジに　ふさわしい！$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER}は\nショックバッジを　もらった$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "ショックバッジが　あれば\nこうかんした　ポケモンも\lレベル70まで　いうことを　きく\pそれに　たたかい　いがいでも\nそらをとぶが　つかえる\pほれ　これも\nもって　いけ！$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "それは　きあいパンチ\pおそいが　ダメージは\nきょうれつだ\lさきに　こうげき　されるなよ！$"

CianwoodGym_Text_ChuckAfter:
	.string "わははは！　たのしい\nしょうぶ　だった！\pだが　まけは　まけ！\pこれからは　24じかん\nしゅぎょう　するぞ！$"

CianwoodGym_Text_ChuckRematch:
	.string "わははは！\nジョウトの　チャンピオン！\pまた　きたな！\pうでを　あげた\nようだな！\pどちらが　つよいか\nためすか？$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "な？　なに？　まけた？\nまたか？$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "おれと　ポケモンは\nゆうじょうで　むすばれている\pこの　きずなは\nぜったいに　きれない！$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "うそだろ！$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "きみも　ポケモンと\nつよい　きずなで　むすばれて\lいる　ようだな！$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "われら　ぶどうかに\nおそれる　ものなし！$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "しょうげき　だ！$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "かくとうポケモンは\nエスパーが　にがて‥$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "ことばは　いらん\nこぶしで　かたれ！$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "まけた！\nことばも　でない！$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "いかりの　こぶしで　きみの\nポケモンを　くだいて　やる！$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "くだかれた！$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "ポケモンが　まけた‥\nおれの　プライドが‥$"

