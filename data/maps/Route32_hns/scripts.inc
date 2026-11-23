Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "まって！\nなにを　あわてて　いるんだい？$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}くん　だよね？\nメガネを　かけた　ひとが\pきみを　さがしていたよ\pポケモンセンターで\nまってるから　いって　ごらん$"

Route32_Text_CooltrainerM_SproutTower:
	.string "マダツボミのとうには　いった？\nキキョウシティに　きたら\pあそこで　しゅぎょう　するのが\nトレーナーの　きほんさ\pマダツボミのとうへ　いこう！$"

Route32_Text_CooltrainerM_VioletGym:
	.string "ポケモンジムには　いった？\nあそこで　ポケモンと　じぶんを\pためす　ことが　できる\nすべての　トレーナーの\pとおりみちだよ！$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "いい　ポケモンを　つれてるね\nキキョウシティの　あたりで\pきたえた　せいかだね\nとくに　ジムでの　しゅぎょうは\pやくに　たった　だろう\nキキョウシティの　きねんに　これを\pあげよう　くさタイプの\nわざが　つよく　なるんだ$"

Route32_Text_CooltrainerM_Experiences:
	.string "キキョウシティでの　けいけんは\nこれからの　たびに\lやくだつ　はずだよ$"

Route32_Text_SlowpokeTailOffer:
	.string "おいしくて　えいようまんてんの\nヤドンのシッポ　いかが？\pいまなら　とくべつに\n100まん円！\pほしく　なるだろ？$"

Route32_Text_ThoughtKidsLoaded:
	.string "ちっ！　さいきんの　ガキは\nかねもちだと　おもったのに‥$"

Route32_Text_RefusedSlowpokeTail:
	.string "いらないのか？\nだったら　うせろ！　しっしっ！$"

Route32_Text_FisherJustin_Seen:
	.string "うわっ！\pきみの　せいで　さかなを\nにがしちゃったじゃないか！$"

Route32_Text_FisherJustin_Beaten:
	.string "ザッパーン！$"

Route32_Text_FisherJustin_After:
	.string "おちついて　れいせいに‥\nつりも　ポケモンも\lたいせつな　ことは　おなじさ$"

Route32_Text_FisherRalph1_Seen:
	.string "おれは　つりも　ポケモンも\nとくい　なんだ\pこどもなんかに\nまけて　たまるか！$"

Route32_Text_FisherRalph1_Beaten:
	.string "ちっ！　あせりすぎた‥$"

Route32_Text_FisherRalph1_After:
	.string "つりは　いっしょうの\nしゅみだ\pポケモンは　いっしょうの\nともだちさ！$"

Route32_Text_RalphRegister:
	.string "つりは　いっしょうの\nしゅみだ\pポケモンは　いっしょうの\nともだちさ！$"

Route32_Text_RalphRematchIntro:
	.string "おれは　つりも　ポケモンも\nとくい　なんだ\pこどもなんかに\nまけて　たまるか！$"

Route32_Text_RalphRematchDefeat:
	.string "ちっ！　あせりすぎた‥$"

Route32_Text_RalphPostRematch:
	.string "つりは　いっしょうの\nしゅみだ\pポケモンは　いっしょうの\nともだちさ！$"

Route32_Text_FisherHenry_Seen:
	.string "おれの　ポケモン？　つりたてだぜ！$"

Route32_Text_FisherHenry_Beaten:
	.string "ピチャン？$"

Route32_Text_FisherHenry_After:
	.string "つりたての　ポケモンじゃ\nちゃんと　そだてた　ポケモンには\lかなわないな$"

Route32_Text_YoungsterAlbert_Seen:
	.string "みかけない　かおだね\nじぶんは　つよいって　おもってる？$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "きみ　つよいね！$"

Route32_Text_YoungsterAlbert_After:
	.string "ぼくは　すきな　ポケモンで\nいちばんを　めざすんだ\pみんなと　おなじ　つよい\nポケモンは　つかわないよ$"

Route32_Text_YoungsterGordon_Seen:
	.string "くさむらで　いい　ポケモンを\nみつけたんだ！\pこいつらなら　かてるはず！$"

Route32_Text_YoungsterGordon_Beaten:
	.string "ちぇっ　かてると　おもったのに$"

Route32_Text_YoungsterGordon_After:
	.string "くさむらって　ひっつき\nむしが　いっぱいだ$"

Route32_Text_CamperRoland_Seen:
	.string "その　まなざし‥　きになるね$"

Route32_Text_CamperRoland_Beaten:
	.string "うーん　ざんねんだ$"

Route32_Text_CamperRoland_After:
	.string "しょうぶ　したくなかったら\nめを　あわせないことだね$"

Route32_Text_PicnickerLiz1_Seen:
	.string "うんうん　それでね‥\pえ？　しょうぶ？　いま　でんわ\nちゅうなの　もう　いいわ\lでも　さっさと　すませてよ$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "もう！　むしゃくしゃする！$"

Route32_Text_PicnickerLiz1_After:
	.string "せっかく　たのしく　おしゃべり\nしてたのに$"

Route32_Text_LizRegister:
	.string "せっかく　たのしく　おしゃべり\nしてたのに$"

Route32_Text_LizRematchIntro:
	.string "うんうん　それでね‥\pえ？　しょうぶ？　いま　でんわ\nちゅうなの　もう　いいわ\lでも　さっさと　すませてよ$"

Route32_Text_LizRematchDefeat:
	.string "もう！　むしゃくしゃする！$"

Route32_Text_LizPostRematch:
	.string "せっかく　たのしく　おしゃべり\nしてたのに$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "その　バッジ！　キキョウシティの\nだな！　ハヤトに　かったのか？$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "じぶんの　よわてんは\nわかってるんだ$"

Route32_Text_BirdKeeperPeter_After:
	.string "キキョウシティの　ジムで\nまた　しゅぎょう　しなきゃ$"

Route32_Text_RoarIntro:
	.string "ガオーッ！　おれが　ほえると\nみんな　にげるのに　おまえは\lよってきた！\pきにいった！　これを　やる！$"

Route32_Text_RoarOutro:
	.string "ガオーッ！　ほえるだ！\pいい　ほえごえは　ポケモンでも\nにげだすぞ！$"

Route32_Text_MeetFrieda:
	.string "キンコ『やっほー！\pようび　きょうだいの　キンコだよ！\nよろしくね！\pわたしの　すきな　ようびを\nあてたら　ごほうびを　あげる$"

Route32_Text_FriedaGivesGift:
	.string "どくバリを　あげる！$"

Route32_Text_FriedaGaveGift:
	.string "キンコ『どくタイプの　わざを\nもってる　ポケモンに　もたせてね\pそれ！\pすっごいんだから！\pどくの　わざが　びっくりするほど\nつよく　なるよ！$"

Route32_Text_FriedaFriday:
	.string "キンコ『やっほー！　なにようびが\nすき？\pわたしは　ぜったい\nきんようび！\pさいこうだと　おもわない？$"

Route32_Text_FriedaNope:
	.string "キンコ『それじゃ　ないよ！$"

Route32_Text_Sign1:
	.string "32ばんどうろ\pキキョウシティ　ー　ヒワダタウン$"

Route32_Text_Sign2:
	.string "アルフのいせき\nひがしいりぐち$"

Route32_Text_Sign3:
	.string "この　さき\nつながりのどうくつ$"
