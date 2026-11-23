GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "コガネ　ポケモンジム$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "コガネシティ　ポケモンジム\pアカネ　にんてい　トレーナー\n{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
	.string "はーい！　うち　アカネ！\pみんな　ポケモン　やってるから\nうちも　はじめたんよ！\pポケモンって　めっちゃ\nかわいいやん！\pしょうぶ　したいん？　いうとくけど\nうち　つよいで！$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
	.string "ぐすっ‥\p‥うわあああん！\nいじわる！\pそんな　ほんきに　ならんでも\nええやん！　この‥　こどもー！$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
	.string "うわあああん！\pうわあああん！\p‥ひっく　ぐすっ‥\n‥いじわる！$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
	.string "‥ぐすっ‥\pなに？　なんの　よう？\nバッジ？\pあ　そうか　わすれてたわ\nはい　レギュラーバッジ$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
	.string "{PLAYER}は　レギュラーバッジを\nもらった$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
	.string "レギュラーバッジが　あると\nたたかい　いがいでも\lかいりきが　つかえるんよ\pそれと　ポケモンの\nぼうぎょも　あがるんよ\pそうそう　これも　あげる！$"

GoldenrodCity_Gym_Text_WhitneyAttract:
	.string "メロメロや！\nポケモンの　みりょくを\lめいっぱい　いかす　わざよ\pうち　みたいな　かわいこちゃんに\nぴったり　やろ？$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
	.string "あー　いっぱい　ないて\nすっきりした！$"

GoldenrodCity_Gym_Text_WhitneyRematch:
	.string "あっ！　あんたや！\pえー　いまは　ジョウトの\nチャンピオンなん？\pほんま　すごいわ！\pどれくらい　つよいか\nみてみたいわ\pもう　いっかい　しょうぶ\nしよっか？$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
	.string "うわあああん！\pうわあああん！\p‥ひっく　ぐすっ‥\n‥いじわる！$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
	.string "わたしの　ポケモンの\nかわいさに　だまされちゃ\lだめよ\pけっこう　つよいんだから！$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
	.string "くやしい‥\nよわいと　おもったのに‥$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
	.string "わたしの　ポケモン\nわたしを　かわいいと\lおもってるかな？$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
	.string "つよい　ポケモンより\nかわいい　ポケモンが　すき\pでも　つよくて　かわいい\nポケモンも　いるのよ！$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
	.string "やだ　やだ　やだ！$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
	.string "アカネちゃんに　かちたいけど‥\nおちこむわ\pへいき！　まけたら\nつぎ　もっと　がんばるの！$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
	.string "あらら　アカネちゃん\nなかせちゃった\pだいじょうぶ　すぐ　なきやむわ\nまけると　いつも　なくのよ$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
	.string "あら　かわいい\nトレーナーさん！\pすきだけど\nてかげんは　しないわよ！$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
	.string "えっと‥　あら　もう　おわり？$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
	.string "わたしに　かつなんて\nやるわね！　がんばってね！$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
	.string "ぜんりょくで　きなさい\nでないと　たおしちゃうわよ！$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
	.string "いや！　ニャース\nごめんね！$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
	.string "ニャースには　どんな　タイプにも\nたちむかえる　わざを\lおしえたのに‥$"

GoldenrodCity_Gym_Text_GymGuide:
	.string "よう！　みらいの　チャンピオン！\pこの　ジムは　ノーマルタイプの\nつかいて　アカネの　ジムだ\pかわいい　チームには\nきを　つけろ\pこの　ジムには　あたらしく\nみつかった　フェアリータイプを\lもつ　ポケモンも　いるぞ\pかくとうや　どくタイプが\nほしいなら　34ばんどうろを\lさがして　みな$"

GoldenrodCity_Gym_Text_GymGuideWin:
	.string "かったのか？　すごい！\nおれは　ここの　おねえさんたちに\lみとれてたよ$"

