MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
	.string "うわーッ！\n"
	.string "びっくり　した！\l"
	.string "…　なんだ　こどもか$"

MtMoon_1F_Text_MarcosDefeat::
	.string "おどろいた！$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "こどもが\n"
	.string "こんな　くらい　ところを\l"
	.string "ウロウロ　しちゃ　いかん　なあ$"

MtMoon_1F_Text_JoshIntro::
	.string "きみも\n"
	.string "どうくつ　たんけんに　きたのかい$"

MtMoon_1F_Text_JoshDefeat::
	.string "…　まける　なんて\n"
	.string "カッコ　わるい$"

MtMoon_1F_Text_JoshPostBattle::
	.string "おんなのこに\n"
	.string "イイ　とこ　みせようと\l"
	.string "こんな　とこ　まで　きちゃった$"

MtMoon_1F_Text_MiriamIntro::
	.string "わあーッ！\n"
	.string "どうくつの　なかって\l"
	.string "いがいと　ひろいのねー！$"

MtMoon_1F_Text_MiriamDefeat::
	.string "あ…　まけてる！$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "こんなに　ひろいと\n"
	.string "どっちが　でぐちか　まよっちゃう$"

MtMoon_1F_Text_JovanIntro::
	.string "うわッ！　なんだ？\n"
	.string "きゅうに　こえを　かけるな！$"

MtMoon_1F_Text_JovanDefeat::
	.string "…\n"
	.string "こんな　ポケモン　では　ダメか$"

MtMoon_1F_Text_JovanPostBattle::
	.string "えーと…！　どこかに\n"
	.string "つよい　ポケモン　いないか…　な$"

MtMoon_1F_Text_IrisIntro::
	.string "なによー！\n"
	.string "どうくつで　はぐれた　ともだちを\l"
	.string "ここで　まってるのよ$"

MtMoon_1F_Text_IrisDefeat::
	.string "わたし　まけたの？$"

MtMoon_1F_Text_IrisPostBattle::
	.string "この　どうくつに\n"
	.string "すごい　カセキが\l"
	.string "あるって　きいて　きたの$"

MtMoon_1F_Text_KentIntro::
	.string "あやしい　やつが\n"
	.string "どうくつを　うろついてるんだ\l"
	.string "きみは…？$"

MtMoon_1F_Text_KentDefeat::
	.string "やられた！$"

MtMoon_1F_Text_KentPostBattle::
	.string "ぼくが　みた　やつ！\n"
	.string "まちがい　ない！\l"
	.string "あいつ　ロケットだん　だぜ！$"

MtMoon_1F_Text_RobbyIntro::
	.string "ハナダ　シティに　いくには\n"
	.string "どうくつを\l"
	.string "ぬけないと　だめだよ！$"

MtMoon_1F_Text_RobbyDefeat::
	.string "ぼくの　まけだ$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "ズバットは　てごわい！\n"
	.string "でも　つかまえられれば\l"
	.string "たよりに　なる　ポケモンだよ$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "ズバットの\n"
	.string "きゅうけつ　こうげきに　ちゅうい！$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "おじさんは　オツキミやまの　かせきを\n"
	.string "はっくつ　してるんだよ！\p"
	.string "ニビジムの　タケシくんが\n"
	.string "てつだってくれる　ことも　あるよ$"
