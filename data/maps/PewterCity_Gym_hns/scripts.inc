PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "タケシ『おお　{PLAYER}じゃないか！\nひさしぶりだな！\p"
	.string "ジョウトを　たびして\nきたんだって？\p"
	.string "3ねんまえ　おまえに　まけてから\nおれも　ずっと　しゅぎょう\lして　きたんだ\p"
	.string "いわタイプの　かたい　まもり‥\nもう　いちど　ためさせて\lもらうぞ\p"
	.string "さあ　こい！$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "タケシ『やっぱり　つよいな\n{PLAYER}‥\p"
	.string "あの　ときより　ずっと\nつよく　なってる\p"
	.string "さあ　この　バッジを\nうけとって　くれ$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER}は\nグレーバッジを　もらった$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "ほら　この　わざマシンも\nもって　いけ$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "それは　いわなだれ\pあいてに　いわを　おとし\nひるませる　ことも　ある\pあいての　うごきを\nとめるのに　つかえ$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "タケシ『{PLAYER}　ありがとう\nくやしいけど　たのしい\lしょうぶ　だったよ\pその　グレーバッジで　ポケモンは\nもっと　つよく　なるぞ$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "タケシ『せかいは　ひろい\nきみの　ような　つよい\lトレーナーは　まだ　いる\pみてろよ　おれも\nもっと　つよく　なる$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "この　ジムの　トレーナーは\nいわタイプを　つかう\pいわタイプは\nぼうぎょが　たかい\pしょうぶは　ながびくかもな\nかくごは　いいか？$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "かたなきゃ　いけないのに‥$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "おい　ジョウトの　トレーナー！\nタケシさんは　つよいぞ\lあまく　みると　いたい\lめに　あうぞ$"

PewterCity_Gym_Text_Guide:
	.string "よう！　みらいの　チャンピオン！\nいわの　ように　かたい\lかつやくだな\pカントーの　ジムリーダーにも\nちょうせん　してるのか？\pジョウトの　ジムリーダー　と\nおなじく　つよくて　ねっしんな\lひとたちだぞ$"

PewterCity_Gym_Text_Guide_Win:
	.string "よう！　みらいの　チャンピオン！\nこの　ジムは　らくしょう\lだったな\pきみの　たたかいぶりには\nほんとうに　しげき　されたよ$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
	.string "ニビ　ポケモンジム\nリーダー　タケシ\pかった　トレーナー\n{KANTO_RIVAL}　{PLAYER}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "ニビ　ポケモンジム\nリーダー　タケシ\pかった　トレーナー\n{KANTO_RIVAL}　{PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "タケシ『やあ　{PLAYER}\nやまで　しゅぎょう　ちゅうに\lこの　ウソハチを　みつけたんだ\pかわいいけど　べつの\nトレーナーが　あってる\lきがするんだ\p{STR_VAR_1}と　おれの\n{STR_VAR_2}を　こうかん\lしないか？$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "タケシ『ありがとう！\nウッディを　よろしくな！$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "タケシ『だめか？　いいさ\nウッディと　しゅぎょうを\lつづけるよ$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "タケシ『それは　{STR_VAR_1}じゃ\nないな　ほしいのは\lそれじゃ　ないんだ$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "タケシ『ウッディは　げんきか？\nウソハチは　みかけより\lたくましいぞ！$"
