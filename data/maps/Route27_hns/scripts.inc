Route27_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	setspeaker Route27_Text_BaobaName
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Text_BaobaName:
	.string "バオバ$"

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_DragonClaw::
    finditem ITEM_TM_DRAGON_CLAW
    end

Route27_EventScript_Item_Destiny_Knot::
    finditem ITEM_DESTINY_KNOT
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE_HNS, Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN_HNS, Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA_HNS, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_RegisterReena
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterReena::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_ReenaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_REENA_HNS
	release
	end

Route27_EventScript_RematchReena::
	trainerbattle_rematch TRAINER_REENA_HNS, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
	msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN_HNS, Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT_HNS, Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE_HNS, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_RegisterJose
	goto_if_set FLAG_JOSE_HAS_ITEM_HNS, Route27_EventScript_JoseGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterJose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_JoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE_HNS
	release
	end

Route27_EventScript_RematchJose::
	trainerbattle_rematch TRAINER_JOSE_HNS, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
	msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseGiveItem::
	msgbox Route27_Text_JoseHasItem, MSGBOX_DEFAULT
	giveitem VAR_JOSE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route27_EventScript_JoseNoRoom
	clearflag FLAG_JOSE_HAS_ITEM_HNS
	msgbox Route27_Text_JoseGaveItem, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseNoRoom::
	msgbox Route27_Text_JoseNoRoom, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT_HNS, Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
	.string "おーい！$"

Route27_Text_FisherMessage:
	.string "いま　なにを　したか\nわかってるかい？\pきみは　カントーへの\nだいいっぽを　ふみだしたんだ\pポケギアの　マップで\nたしかめて　ごらん$"

Route27_Text_CooltrainermBlakeSeen:
	.string "つよそうだな\nしょうぶ　させて　くれ！$"

Route27_Text_CooltrainermBlakeBeaten:
	.string "うおっ！$"

Route27_Text_CooltrainermBlakeAfter:
	.string "この　けわしい　みちのりを\nこえた　とき　しんじつが\lあきらかに　なる！\pへへ　ごめん　かっこいい　こと\nいって　みたかった　だけ$"

Route27_Text_CooltrainermBrianSeen:
	.string "ん？　きみ　つよいだろ？$"

Route27_Text_CooltrainermBrianBeaten:
	.string "おもった　とおりだ！$"

Route27_Text_CooltrainermBrianAfter:
	.string "いい　トレーナーは　いい\nトレーナーを　みぬけるのさ$"

Route27_Text_CooltrainerfReenaSeen:
	.string "この　あたりの　やせいの\nポケモンを　あまく　みちゃ\lだめよ$"

Route27_Text_CooltrainerfReenaBeaten:
	.string "あら！　つよすぎるわ！$"

Route27_Text_CooltrainerfReenaAfter:
	.string "こどもだけど　あなたも\nあまく　みられないわね$"

Route27_Text_ReenaRegister:
	.string "こどもだけど　あなたも\nあまく　みられないわね$"

Route27_Text_ReenaRematchIntro:
	.string "この　あたりの　やせいの\nポケモンを　あまく　みちゃ\lだめよ$"

Route27_Text_ReenaRematchDefeat:
	.string "あら！　つよすぎるわ！$"

Route27_Text_ReenaPostRematch:
	.string "こどもだけど　あなたも\nあまく　みられないわね$"

Route27_Text_CooltrainerfMeganSeen:
	.string "ここに　ひとが　くるなんて\nめずらしいわ\pひとりで　しゅぎょう　してるの？$"

Route27_Text_CooltrainerfMeganBeaten:
	.string "まあ！　ほんとうに　つよいのね！$"

Route27_Text_CooltrainerfMeganAfter:
	.string "しんかの　まえと　あとの\nポケモンを　しらべてるの\pしんかすると　たしかに\nつよく　なるわ\pでも　しんかした　すがただと\nわざを　おぼえるのが　おそいの$"

Route27_Text_PsychicGilbertSeen:
	.string "なにも　いうな！\pきみの　かんがえを\nあてて　みせよう\pむむむむむ‥\pわかった！　ポケモンリーグに\nちょうせん　するんだな！$"

Route27_Text_PsychicGilbertBeaten:
	.string "すごすぎる！$"

Route27_Text_PsychicGilbertAfter:
	.string "その　うでなら　リーグでも\nいいせんいくだろう\pわたしの　よかんが\nそう　いってる$"

Route27_Text_BirdKeeperJoseSeen:
	.string "ピーッ！　ピーッ！　ピピーッ！$"

Route27_Text_BirdKeeperJoseBeaten:
	.string "ピーッ！$"

Route27_Text_BirdKeeperJoseAfter:
	.string "とりつかいは　とりの\nなきごえを　まねして\lポケモンに　しじを　だすんだ$"

Route27_Text_JoseRegister:
	.string "とりつかいは　とりの\nなきごえを　まねして\lポケモンに　しじを　だすんだ$"

Route27_Text_JoseRematchIntro:
	.string "ピーッ！　ピーッ！　ピピーッ！$"

Route27_Text_JoseRematchDefeat:
	.string "ピーッ！$"

Route27_Text_JosePostRematch:
	.string "とりつかいは　とりの\nなきごえを　まねして\lポケモンに　しじを　だすんだ$"

Route27_Text_JoseHasItem:
	.string "おーい！　とりを　みてたら\nひかる　ものを　みつけたよ！\pはい　あげる！$"

Route27_Text_JoseGaveItem:
	.string "27ばんどうろでは　いろんな\nものが　みつかるんだ\pまた　みつけたら\nしらせるね！$"

Route27_Text_JoseNoRoom:
	.string "うーん　バッグが　いっぱいだね\pあきを　つくってから\nまた　きて$"

TohjoFalls_Text_Sign:
	.string "トージョウのたき\pカントーと　ジョウトを\nむすぶ　たき$"

Route27_Text_FisherScottSeen:
	.string "きょうは　ぜっこうちょう！\pリーグチャンピオンだって\nたおせそうな　きぶんだ！$"

Route27_Text_FisherScottBeaten:
	.string "そんな！　この　しょうぶでは\nありえない！$"

Route27_Text_FisherScottAfter:
	.string "つりも　ポケモンも\nあきらめたら　そこで\lおしまい　なんだ$"
