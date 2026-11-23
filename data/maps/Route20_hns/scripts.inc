Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "デニス『シャアアアアアッ！$"

Route20_Text_Headlocker:
	.string "この　すいどうには　めずらしい\nポケモンが　いるんだ\pしかも　ときどき　めずらしい\nしんかの　どうぐを　もってる\pダブルで　めずらしい！\pずかんを　かんせい　させたくて\nなんじかんも　つりを\lしてるんだ！$"

Route20_Text_Seel:
	.string "パウワウ『パウッ　パウッ！$"

Route20_Text_Dewgong:
	.string "ジュゴン『ジュゴーン！$"

Route20_Text_SeafoamSign:
	.string "ふたごじま$"

Route20_Text_NicoleRegister:
	.string "あなたの　ポケモン　はやいわね！\nばんごう　おしえて！$"

Route20_Text_NicoleRematchIntro:
	.string "およいで　ポケモンが　つよく\nなったわ！　しょうぶよ！$"

Route20_Text_NicoleRematchDefeat:
	.string "また　ながされちゃった‥$"

Route20_Text_NicolePostRematch:
	.string "かっても　まけても　わたしも\nポケモンも　からだが\lひきしまっていくわ！$"

Route20_Text_SwimmerfNicoleSeen:
	.string "みずの　なかだと\nからだが　かるいの$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "ああっ！$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "すいえいは　ぜんしんうんどう\pからだに　とっても　いいのよ$"

Route20_Text_SwimmerfLoriSeen:
	.string "すごい　ジムバッジの　かずね\nしょうぶ　しましょ！$"

Route20_Text_SwimmerfLoriBeaten:
	.string "いやっ！$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "みずの　うえで　つかう　ひでんわざは\nなみのり　だけじゃ　ないのよ$"

Route20_Text_SwimmermCameronSeen:
	.string "ジョウトまで　およいで\nいくのは　むりだろうな$"

Route20_Text_SwimmermCameronBeaten:
	.string "あいやー！$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "うみの　ほかにも　いけや\nかわでも　およげるぜ$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "なんて　かいてある　かな？\pグレンジム　ジムリーダー　カツラ$"

