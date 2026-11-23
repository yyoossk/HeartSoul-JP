MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "チョウジタウン　ポケモンジム$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "チョウジタウン　ポケモンジム\pヤナギ　にんてい　トレーナー\n{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
	.string "ポケモンも　わしら　とおなじく\nいろんな　けいけんを　つむ\pわしも　じんせいで　おおくを\nみて　くるしんで　きた\pとしうえと　して\nそれを　みせて　やろう\pわしは　きみが　うまれる　まえから\nポケモンと　ともに　あった\pかんたんには　まけん\pふゆの　トレーナー\nこの　ヤナギが　ちからを\lみせて　くれよう！$"

MahoganyTown_Gym_Text_PryceImpressed:
	.string "うむ　みごとな　うでまえ\pその　つよい　いしが　あれば\nどんな　こんなんも\lのりこえられよう\pこの　バッジに\nふさわしい！$"

MahoganyTown_Gym_Text_ReceivedBadge:
	.string "{PLAYER}は\nアイスバッジを　もらった$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "その　バッジで　ポケモンの\nとくこうが　あがる\pそれに　うずしおで　ほんものの\nうずを　わたれる\pそして　これは‥\nわしからの　おくりものじゃ！$"

MahoganyTown_Gym_Text_HailSpeech:
	.string "その　わざマシンは　あられ\p5ターンの　あいだ\nまいターン　ダメージを\lあたえる\pふゆの　きびしさを\nあらわした　わざじゃ$"

MahoganyTown_Gym_Text_CherishPokemon:
	.string "こおりと　ゆきが　とければ\nはるが　くる\pきみと　ポケモンは　これから\nながい　としつきを\lともに　すごすじゃろう\pその　ときを\nたいせつに　するのじゃ！$"

MahoganyTown_Gym_Text_PryceRematch:
	.string "おお　ジョウトの\nチャンピオン！\pきみの　うでは\nまことに　すばらしい\pかんしん　したぞ\pだが　いまでも　おたがいに\nまなぶ　ことは　おおい\pふゆの　トレーナー　ヤナギ\nまだ　おくのては　あるぞ\pもう　いちど\nしょうぶ　するか？$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "うむ　またしても\nみごとな　うでまえ\pその　つよい　いしが　あれば\nどんな　こんなんも\lのりこえられよう$"

MahoganyTown_Gym_Text_Guide:
	.string "ヤナギは　50ねんも\nポケモンを　そだてて　きた\lベテランだ\pどんな　あいてにも　たいおう\nできる　ポケモンを\lそろえて　いるぞ\pほのおで　せめると　いいが\nあめには　きを　つけろ！$"

MahoganyTown_Gym_Text_GuideWin:
	.string "ヤナギも　すごいが\nきみは　もっと　すごい！\pせだいを　こえた\nあつい　しょうぶ　だったな！$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "きみの　ポケモンを　こおらせて\nなにも　できなく　してやる！$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "くそっ　なにも\nできなかった$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "こおって　いても\nつかえる　わざが　あるらしい$"

MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "この　ジムは　ゆかが\nすべるんだ\pたのしい　だろ？\pでも　あそびじゃ\nないんだぜ！$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "おれたちの　ほんきが\nわかったか？$"

MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "この　ジムは　さいこう\nポケモンと　すべるのが\lだいすきさ！$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "ヤナギさんの　ひみつを\nしってるぞ$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "よし　ヤナギさんの\nひみつを　おしえよう$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "ヤナギさんの　つよさの\nひみつは‥\pまいにち　たきに　うたれて\nこころと　からだを\lきたえて　いるんだ$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "ジムリーダーの　ヤナギさんの\nところへ　いくには\lよく　かんがえて　すべるのよ$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "スキー　なら\nまけないのに！$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "せいかくに　すべらないと\nこの　ジムでは\lさきへ　すすめないわ$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "わたしの　パラレルターン\nみてて！$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "いやー！　ころんじゃった！$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "スキーの　じまん　なんて\nしなきゃ　よかった‥$"

