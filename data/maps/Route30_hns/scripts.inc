Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "ポケモンじいさんの　いえ$"

Route30_Text_UseTackle:
	.string "いけっ　コラッタ！\pたいあたり！$"

Route30_Text_ThisIsABigBattle:
	.string "なんだよ！　いま　だいじな\nしょうぶ　ちゅうなんだ！\lじゃま　しないで！$"

Route30_Text_YoungsterJoey1Seen:
	.string "さっき　まけちゃったから\nポケモンを　さがしてるんだ\pまてよ！　きみ　よわそうだな！\nさあ　しょうぶだ！$"

Route30_Text_YoungsterJoey1Beaten:
	.string "あっ！　また　まけた！\nちくしょう！$"

Route30_Text_YoungsterJoey1After:
	.string "しょうぶに　かつには　もっと\nポケモンが　いるのかな？\pいや！　ぼくは　なにが　あっても\nこいつ　ひとすじだ！$"

Route30_Text_YoungsterMikeySeen:
	.string "きみ　ポケモントレーナー\nだよね？\pだったら　しょうぶだ！$"

Route30_Text_YoungsterMikeyBeaten:
	.string "おかしいな\nまえは　かったのに$"

Route30_Text_YoungsterMikeyAfter:
	.string "いい　トレーナーに　なるのって\nほんとに　たいへんだ\pいろんな　ひとと　しょうぶして\nうまく　なるんだ$"

Route30_Text_BugCatcherDonSeen:
	.string "むしポケモンじゃなくて\nトレーナーを　みつけた！$"

Route30_Text_BugCatcherDonBeaten:
	.string "うわあ！　つよすぎる！$"

Route30_Text_BugCatcherDonAfter:
	.string "ポケモンを　つかまえてたら\nボールが　なくなっちゃった\pもっと　かっておけば\nよかった‥$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "ポケモンじいさんの　いえ？\nもう　すこし　さきだよ$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "みんな　たのしそうに\nしょうぶ　してるよ！\pきみも　やりなよ！$"

Route30_Text_CooltrainerF:
	.string "わたしは　トレーナーじゃないの\pでも　トレーナーと　めが　あったら\nしょうぶを　かくごしてね$"

Route30_Text_Sign:
	.string "30ばんどうろ\pキキョウシティ　ー　ヨシノシティ$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "ポケモンじいさんの　いえ\nこの　さき　まっすぐ！$"

Route30_Text_MrPokemonsHouseSign:
	.string "ポケモンじいさんの　いえ$"

Route30_Text_TrainerTips:
	.string "トレーナーの　こころえ\pひとの　ポケモンを\nとっては　いけません！\pモンスターボールは　やせいの\nポケモンに　なげましょう！$"

Route30_Text_JoeyRegister:
	.string "きみ　なかなか　やるね！\pぼくの　コラッタは　あいかわらず\nやるきまんまん　なんだ\pこいつ　1ぴきしか　いないけど\nこいつと　すごい\lトレーナーに　なるんだ！\pまた　しょうぶしようね！$"

Route30_Text_JoeyRematchIntro:
	.string "こんどは　ちがうって\nいったよね！　しょうぶだ！$"

Route30_Text_JoeyRematchDefeat:
	.string "あっ！　また　まけた！\nちくしょう！$"

Route30_Text_JoeyPostRematch:
	.string "いま　コラッタの　わざを\nしらべて　さくせんを\lかんがえてるんだ\pいい　さくせんが　うかんだら\nしょうぶしよう！$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "また　まけた‥\nきみって　つよいなあ！\pそうだ　これを　わたすの\nわすれる　ところだった\pこれで　もっと　つよく\nなってね！\pぼくも　つよく　なるから$"

Route30_Text_ElmName:
	.string "ウツギはかせ$"

Route30_Text_Elm_Disaster:
	.string "ウツギ『も‥　もしもし？\n{PLAYER}くん？　たいへんだ！\pえっと　その　とにかく\nたいへん　なんだ！\pどうしよう？　あれが‥\nああ　もう‥\pすぐに　もどってきて　くれ！$"


Route30_Text_Poliwag:
	.string "ニョロモ『ニョロ　ニョーロ！$"
