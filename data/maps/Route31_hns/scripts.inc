Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "くらやみのほらあな‥\pポケモンで　あかるく　できたら\nたんけん　するんだけどな$"

Route31_Text_BugCatcherWade1_Seen:
	.string "ポケモンを　いっぱい\nつかまえたんだ　しょうぶしよう！$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "あーあ‥$"

Route31_Text_BugCatcherWade1_After:
	.string "てもちが　6ぴきでも\nポケモンは　つかまえられるよ\pつかまえたら　じどうで\nボックスに　おくられるんだ$"

Route31_Text_SleepyMan:
	.string "‥ふぁあ‥　ん？\pきょうは　ポケモンを　さがして\nあるきすぎて　しまった\pあしは　いたいし　ねむいし‥\pわしが　やせいの　ポケモンなら\nすぐ　つかまって　しまうな‥\p‥ぐう‥$"

Route31_Text_SleepyManGotMail:
	.string "‥ぐう‥　ん？\pなんじゃ？　わしに\nメールかい？$"

Route31_Text_SleepyManFail:
	.string "‥ぐう‥$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER}は　メールを　もった\nポケモンを　わたした$"

Route31_Text_ReadingMail:
	.string "どれどれ‥\pとどけて　くれて\nありがとう\pわしの　ともだちは　いい　やつで\nきみも　いい　こじゃな！\pわしも　なにか\nおれいを　したいのう！\pそうじゃ！　これを\nあげよう！$"

Route31_Text_DescribeRest:
	.string "‥ぐう‥\p‥ええと‥　ねむる！\pねて　すばやく　かいふく　するから\nねむる　なんじゃ\pねむって　HPを　かいふくする\nわざじゃよ$"

Route31_Text_WrongMail:
	.string "この　メールは　わしあて\nじゃないのう$"

Route31_Text_MissingMail:
	.string "この　ポケモンが　どうか\nしたのかね？\pメールを　もって　おらんぞ$"

Route31_Text_DeclinedToHandOverMail:
	.string "なんじゃ？　なにも\nいらんのか？$"

Route31_Text_CantTakeLastMon:
	.string "その　ポケモンを　もらったら\pきみは　なにで\nたたかうんじゃ？$"

Route31_Text_Youngster:
	.string "くらやみのほらあなで\nいい　ポケモンを　みつけたんだ\pそだてて　ハヤトに\nいどむんだ\pキキョウジムの\nリーダーだよ$"

Route31_Text_Sign:
	.string "31ばんどうろ\pキキョウシティ　ー　ヨシノシティ$"

Route31_Text_WadeRegister:
	.string "きみ　すごいね！　きにいったよ！\pまいにち　ここで　ポケモンを\nさがしてるんだ\pくさむらに　いると　いろんな\nきのみが　みつかるんだ\pよかったら　わけて　あげるよ$"

Route31_Text_WadeRematchIntro:
	.string "まってたよ\nしょうぶしよう！$"

Route31_Text_WadeRematchDefeat:
	.string "あーあ‥$"

Route31_Text_WadePostRematch:
	.string "きみが　よろこびそうな　ものを\nみつけたら　すぐ　れんらく\lするからね$"

Route31_Text_WadeHasItem:
	.string "おーい！　きみを　さがして\nたんだよ！\pくさむらで　いい　ものを\nみつけたんだ\pはい　あげる！$"

Route31_Text_WadeGaveItem:
	.string "また　なにか　みつけたら\nしらせるね！$"

Route31_Text_WadeNoRoom:
	.string "うーん　バッグが\nいっぱい　みたいだね\pあきを　つくってから\nまた　きてよ！$"

Route31_Text_DarkCaveSign:
	.string "くらやみのほらあな$"
