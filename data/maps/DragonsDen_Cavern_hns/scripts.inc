DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
	.string "{PLAYER}‥　きたのね\pわたしに　ついて　こられる\nなら　ヤマブキの\lかくとうどうじょうに　きなさい$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
	.string "イブキ『まって！\pわるかったわ\nおわびに　これを\lうけとって$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
	.string "りゅうのはどうは\nえっと‥　まあ　いいわ！\pなにか　ものすごい\nエネルギーよ\pいらないなら\nうけとらなくて　いいわ$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
	.string "どうしたの？\nポケモンリーグへ\lいくんでしょ？\pチャンピオンに　なったら\nどの　ジムリーダーとも\lさいせん　できるわ\pポケモンリーグへ\nいきなさい\pばしょは　しってる？\pここから　ワカバタウンへ\nいって\pそこから　ひがしへ　なみのり\nすれば　ポケモンリーグよ\pみちは　とても\nけわしいわ\pポケモンリーグで　まけたら\nしょうちしないわよ！\pわたしが　あなたに　まけた\nことが　もっと　くやしく\lなるじゃない！\pぜんりょくで　いきなさい$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
	.string "りゅうのほこら\pりゅうのあなに　すんでいたと\nいわれる　ドラゴンポケモンを\pまつった　ほこら$"

DragonsDen_Cavern_Text_SilverTraining1:
	.string "‥\nなに？　{PLAYER}？\p‥いや　いまは\nたたかわない‥\pおれの　ポケモンは　まだ\nおまえに　かてない\pいまは　むりを\nさせられない\pさいきょうの　トレーナーに\nなるには　しゅぎょうが\lひつようなんだ‥$"

DragonsDen_Cavern_Text_SilverTraining2:
	.string "‥\pふう‥\pおれの　じゃまを\nするなよ‥$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
	.string "きさま！　かってに\nはいるとは！$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
	.string "つ　つよい！$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
	.string "この　さきの　ほこらには\nドラゴンつかいの　いちぞくの\lちょうろうが　いるんだ\pかってに　はいっては\nならない！$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
	.string "ここに　はいっちゃ\nだめよ！$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
	.string "きゃあ　まけちゃった！$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
	.string "もうすぐ　ちょうろうから\nドラゴンを　つかう\lゆるしを　もらえるの\pそしたら　りっぱな\nドラゴンつかいに　なって\lちょうろうに　みとめて\lもらうわ$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
	.string "しらない　ひとだ$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
	.string "いたーい$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
	.string "ワタルさまと　たたかってる\nみたい　だった$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
	.string "だれ？$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
	.string "いじわる$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
	.string "いいつけちゃうから\pちょうろうに\nおこられるよ$"
