OlivineCity_Gym_hns_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Gent::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Gent2::
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow1::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 6
	release
	end

OlivineCity_Gym_EventScript_MoveLeft0::
	turnobject VAR_TEMP_0, DIR_WEST
	return

OlivineCity_Gym_EventScript_MoveLeft1::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft2::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft3::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft4::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_Text_Gent:
	.string "きっと　くると\nおもって　いたよ\pジムリーダーを　たすけて　くれて\nありがとう　でも　しょうぶは\lべつの　はなしだ\pがんばりなさい！$"

OlivineCity_Gym_Text_Gent2:
	.string "みごとだ！\nこれからも　いろんな　ばしょへ\lたびを　つづけなさい\pなみのりが　つかえるなら\nいかりのみずうみに\lいって　みては　どうかな？$"

OlivineCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Lass2::
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow2::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 7
	release
	end

OlivineCity_Gym_EventScript_MoveRight0::
	turnobject VAR_TEMP_0, DIR_EAST
	return

OlivineCity_Gym_EventScript_MoveRight1::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight2::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight3::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight4::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_Text_Lass:
	.string "うふふ‥\nあなたの　じつりょくは\lとうだいで　みたわ\pその　ちからを　ミカンさんに\nみせて　あげて！　がんばって！$"

OlivineCity_Gym_Text_Lass2:
	.string "すごいわ‥\nそれだけ　さいのうが　あるなら\lもっと　うえを　めざさなきゃ\pチョウジタウンには\nいった？$"

OlivineCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideSick::
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideAfter::
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymGuideText:
	.string "ミカンは　あたらしく　みつかった\nはがねタイプの　つかいてだ\pきりふだが　ひとつ　じゃなく\nふたつ　あることで　ゆうめいだ\pひとつめは　わざで　こうげきを\nあげる　はがねの　むしだ\pほのおに　よわいが　つよい\nこうげきを　こらえる　ことが\lある\pふたつめは　つよい　わざを\nたくさん　もつ　きょだいな\lてつの　へびだ\pこころして　かかれ\pおそそうに　みえるが　おどろく\nほど　はやく　せんせいを\lとるのを　みた　ことが　ある$"

OlivineCity_Gym_Text_GymGuideWinText:
	.string "すごかったぜ\pはがねタイプか‥\pみちとの　そうぐう　だったな！$"

OlivineCity_Gym_Text_GymGuidePreText:
	.string "ジムリーダーの　ミカンは\nとうだいに　いるんだ\pびょうきの　ポケモンを\nかんびょう　しているらしい\pつよい　トレーナーには\nやさしさも　ひつようだな$"

OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1

OlivineCity_Gym_EventScript_JasmineVictory::
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_IRON_TAIL
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
	setvar VAR_OLIVINE_CITY_STATE, 8
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

OlivineCity_Gym_EventScript_CianwoodCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_MahogCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
	
OlivineCity_Gym_EventScript_Jasmine_Battle1::
	trainerbattle_no_intro TRAINER_JASMINE_1_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle2::
	trainerbattle_no_intro TRAINER_JASMINE_1_2_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle3::
	trainerbattle_no_intro TRAINER_JASMINE_1_3_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_JASMINE, OlivineCity_Gym_EventScript_Jasmine_Trade
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end


OlivineCity_Gym_Text_JasmineSteelTypeIntro:
	.string "‥とうだいでは\nありがとう　ございました‥\pでも　これは　べつです\nじこしょうかい　させて\lください\pわたしは　ジムリーダーの　ミカン\nはがねタイプを　つかいます\p‥はがねタイプって\nごぞんじですか？\pさいきん　みつかった\nばかりの　タイプなんです\p‥あの‥　はじめても\nいいですか？$"

OlivineCity_Gym_Text_JasmineBetterTrainer:
	.string "‥あなたは　つよさも　やさしさも\nわたしより　うえの\lトレーナーです\pポケモンリーグの　きまりに\nしたがい　この　バッジを\lおわたし　します$"

OlivineCity_Gym_Text_ReceivedMineralBadge:
	.string "{PLAYER}は\nスチールバッジを　もらった$"

OlivineCity_Gym_Text_JasmineBadgeSpeech:
	.string "スチールバッジは　ポケモンの\nとくぼうを　あげます\p‥あの‥\nこれも　どうぞ‥$"

OlivineCity_Gym_Text_JasmineIronTailSpeech:
	.string "‥その　わざマシンで\nアイアンテールを\lおしえられます$"

OlivineCity_Gym_Text_JasmineGoodLuck:
	.string "あの‥　なんと　いえば\nいいか‥　がんばって\lください‥$"

OlivineCity_Gym_Text_JasmineRematchText:
	.string "‥おめでとう　ございます\nジョウトの　チャンピオン\pとても　つよく\nなられましたね‥\pわたしも　せいちょう\nできたでしょうか\pためして　みませんか？\pもう　いちど　しょうぶ\nして　いただけますか？$"

OlivineCity_Gym_Text_JasmineRematchDefeatText:
	.string "‥あなたは　つよさも　やさしさも\nわたしより　うえの\lトレーナーです$"

OlivineCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Statue2::
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymStatue:
	.string "アサギシティ　ポケモンジム$"

OlivineCity_Gym_Text_GymStatueCertified:
	.string "アサギシティ　ポケモンジム\pミカン　にんてい　トレーナー\n{PLAYER}$"

OlivineCity_Gym_EventScript_Jasmine_Trade::
	goto_if_set FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED, OlivineCity_Gym_EventScript_JasmineTradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_STEELIX
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox OlivineCity_Gym_Text_JasmineWantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OlivineCity_Gym_Text_JasmineTakeCare, MSGBOX_DEFAULT
	setflag FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_Gym_EventScript_JasmineDeclineTrade::
	msgbox OlivineCity_Gym_Text_JasmineDeclineTrade, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_EventScript_JasmineTradeCompleted::
	msgbox OlivineCity_Gym_Text_JasmineTradeCompleted, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_Text_JasmineWantToTrade:
	.string "‥あの　{PLAYER}さん‥\nおねがいが　あるんです\pこの　ハガネールは　ちいさな\nイワーク　だった　ころから\lそだてて　きました\pでも　テツは　あなたの　ような\nトレーナーと　いた　ほうが\lしあわせ　だと　おもうんです\pあなたの　ポケモンと\nテツを　こうかん　して\lくれませんか？$"

OlivineCity_Gym_Text_JasmineTakeCare:
	.string "‥ありがとう\nテツを　よろしく‥$"

OlivineCity_Gym_Text_JasmineDeclineTrade:
	.string "‥あ‥　いいんです\nわかりました‥$"

OlivineCity_Gym_Text_JasmineTradeCompleted:
	.string "‥テツは　げんき\nですか？\lだいじに　してあげてね‥$"
