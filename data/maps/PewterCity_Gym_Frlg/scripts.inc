PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock_Kj::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_KJ_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_KJ_DEFEATED_BROCK
	setflag FLAG_BADGE09_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_KJ_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_KJ_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_KJ_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy_Kj::
	lock
	faceplayer
	goto_if_set FLAG_KJ_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue_Kj::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory_Kj
	msgbox PewterCity_Gym_Text_GymStatue_Kj
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory_Kj::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon_Kj
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "きたな！\n"
	.string "おれは　ニビ　ポケモン　ジム\l"
	.string "リーダーの　タケシ！\p"
	.string "おれの　かたい　いしは\n"
	.string "おれの　ポケモンにも　あらわれる！\l"
	.string "かたくて　がまん　づよい！\p"
	.string "そう！　つかうのは\n"
	.string "いわ　タイプ　ばっかりだ！\p"
	.string "ふはは！\n"
	.string "まけると　わかってて　たたかうか！\l"
	.string "ポケモン　トレーナーの　さがだな\l"
	.string "いいだろう！\l"
	.string "かかって　こい！{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "きみを\n"
	.string "みくびって　いた　ようだ\p"
	.string "ぼくに　かった　あかしに\n"
	.string "ポケモン　リーグ　こうにん\l"
	.string "グレー　バッジを　さずけよう！\p"
	.string "{PLAYER}は　タケシから\n"
	.string "グレー　バッジを　もらった！{0xFC}{0x17}{PLAY_BGM}{MUS_OBTAIN_BADGE}{0xFC}{0x08}{0xFE}{0xFC}{0x08}{0x56}{0xFC}{0x18}\p"
	.string "グレー　バッジを　つけてると\n"
	.string "それだけで\l"
	.string "きみの　ポケモンは　つよくなる！\p"
	.string "フラッシュ　という　わざを\n"
	.string "もっている　ポケモンは\l"
	.string "たたかって　なくても　フラッシュを\l"
	.string "つかえる　ように　なる！$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "あと…　そうだ！\n"
	.string "これを　きみに　あげよう！$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{PLAYER}は　タケシから\n"
	.string "わざマシン３９を　もらった！$"

PewterCity_Gym_Text_ExplainTM39::
	.string "わざマシンを　つかうと　ポケモンは\n"
	.string "すぐ　その　わざを　おぼえる！\l"
	.string "ただし　マシンは　つかい　すてだ！\l"
	.string "どの　ポケモンに　おぼえさせるか\l"
	.string "よく　かんがえた　ほうが　いい\p"
	.string "ところで…\n"
	.string "わざマシン３９には\l"
	.string "がんせきふうじ　が　はいっている！\p"
	.string "いわを　あいてに　なげつけて\n"
	.string "すばやさを　さげて　しまう\l"
	.string "おもしろい　わざだ！$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "この　ひろい　せかいでは\n"
	.string "いろんな　やつが　ポケモンで\l"
	.string "たたかいを　くりひろげてる！\p"
	.string "きみには\n"
	.string "ポケモン　トレーナーの\l"
	.string "さいのうが　ある　ようだ！\p"
	.string "ハナダ　シティの　ジムにも　いき\n"
	.string "きみの　ちからを\l"
	.string "ためして　みると　いい$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "もちものが　いっぱいだ$"

PewterCity_Gym_Text_LiamIntro::
	.string "まちなー！\p"
	.string "こどもが　なんの　ようだ！\n"
	.string "タケシさんに　ちょうせん　なんて\l"
	.string "１００００こうねん　はやいんだよ！$"

PewterCity_Gym_Text_LiamDefeat::
	.string "しまった！\p"
	.string "１００００こうねんは…　…\n"
	.string "じかん　じゃない！\l"
	.string "…　…　きょり　だ！$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "おまえ　なかなか　やるな！\n"
	.string "タケシさん　ほどじゃ　ないけどな$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "おっす！\n"
	.string "ポケモン　チャンピオンを\l"
	.string "めざして　みないか？\p"
	.string "おれは　トレーナー　じゃない\n"
	.string "しかし　かつ　ために　ばっちり\l"
	.string "アドバイス　できるぜ！\p"
	.string "な…！　いっしょに\n"
	.string "ポケモン　チャンピオン　めざそうぜ$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "よっしゃーッ！\n"
	.string "じゃ　さっそく…！$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "しょうぶの　さいしょに　とびだす\n"
	.string "ポケモンは…\l"
	.string "ポケモン　リストの\l"
	.string "ひだりがわの　やつだ！\p"
	.string "リストの　じゅんばんを　かえれば\n"
	.string "ゆうりに　なることも　ある！\l"
	.string "ためして　みなよ！$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "えんりょは　いらんぜ！\n"
	.string "じゃ　さっそく…！$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "さすがだな！\n"
	.string "この　ちょうしで　めざせ！\l"
	.string "ポケモン　チャンピオン！$"

PewterCity_Gym_Text_GymStatue_Kj::
	.string "ニビ　ポケモン　ジム\n"
	.string "タケシ　にんてい　トレーナー！\l"
	.string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon_Kj::
	.string "ニビ　ポケモン　ジム\n"
	.string "タケシ　にんてい　トレーナー！\l"
	.string "{RIVAL}　{PLAYER}$"

