RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition_Kj
	.byte 0

RockTunnel_1F_OnTransition_Kj::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "この　ながーい\n"
	.string "トンネルを　ぬける　つもりか！$"

RockTunnel_1F_Text_LennyDefeat::
	.string "おいらの　まけだ$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "たまに　でる　イワークは\n"
	.string "レベルが　たかいと　しめつけてくる\l"
	.string "きを　つけなよ$"

RockTunnel_1F_Text_OliverIntro::
	.string "えーと\n"
	.string "みちに　まよったかな？$"

RockTunnel_1F_Text_OliverDefeat::
	.string "たたかってる\n"
	.string "ばあいじゃ　なかった\l"
	.string "でぐちは　どっち　だっけ？$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "１２ばん　どうろに\n"
	.string "ポケモンが　ねてたろ？\l"
	.string "おれも　こまって　まわりみちだ$"

RockTunnel_1F_Text_LucasIntro::
	.string "おれは\n"
	.string "やまに　すんで　ながい\l"
	.string "よそものに　でかい　つらは　させん$"

RockTunnel_1F_Text_LucasDefeat::
	.string "やるなあ$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "おまえ　みこみが　ある\n"
	.string "やまおとこに　ならんか？$"

RockTunnel_1F_Text_AshtonIntro::
	.string "ポケモン　ファイトー！\n"
	.string "レディー　ゴー！$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "やぶれたのか$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "ズバットでも\n"
	.string "とって　かえろうかな…$"

RockTunnel_1F_Text_LeahIntro::
	.string "きゃ　びっくり！\n"
	.string "うすぐらい　からって\l"
	.string "そんなに　ちかづかないで！$"

RockTunnel_1F_Text_LeahDefeat::
	.string "…　くらくて\n"
	.string "よく　みえないんだもん$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "トンネルにも　ポケモン　いるのね\n"
	.string "さっき　ワンリキーが　いたわ$"

RockTunnel_1F_Text_DanaIntro::
	.string "ポケモン　さがしに　きて\n"
	.string "こんな　とこまで　きちゃった！$"

RockTunnel_1F_Text_DanaDefeat::
	.string "もう　ポケモン　ないわ$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "かわいい　かお　して\n"
	.string "けっこう　つよい　じゃない$"

RockTunnel_1F_Text_ArianaIntro::
	.string "あ　それは　ポケモン！\n"
	.string "さっそく　はじめましょ！$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "でなおして　くるわ$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "エキサイト　して\n"
	.string "あせ　かいちゃったわ$"

RockTunnel_1F_Text_RouteSign::
	.string "ここは　イワヤマ　トンネル\n"
	.string "ハナダ　シティ　…　シオン　タウン$"

