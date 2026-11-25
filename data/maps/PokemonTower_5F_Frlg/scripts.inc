PokemonTower_5F_Frlg_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
	.string "さあ　こっちへ　きなさい！\n"
	.string "ここには　けっかいを　はってある\p"
	.string "やすんで　いくが　よい！$"

PokemonTower_5F_Text_TammyIntro::
	.string "…　タマ…　シ…　イ\n"
	.string "…　ヨ…　コセッ！$"

PokemonTower_5F_Text_TammyDefeat::
	.string "ハア　ハア…！$"

PokemonTower_5F_Text_TammyPostBattle::
	.string "わたしは…\n"
	.string "とり　つかれて　おったか$"

PokemonTower_5F_Text_RuthIntro::
	.string "オ…　マ…　エモ…\n"
	.string "…　ナカ…マニッ！$"

PokemonTower_5F_Text_RuthDefeat::
	.string "なんとした　ことじゃ$"

PokemonTower_5F_Text_RuthPostBattle::
	.string "とり　つかれるとは\n"
	.string "わしも　まだまだ…$"

PokemonTower_5F_Text_KarinaIntro::
	.string "…　ぞ…　ゾゾ…\n"
	.string "…　ンビーッ…！$"

PokemonTower_5F_Text_KarinaDefeat::
	.string "…ゾ　ぞぞ？$"

PokemonTower_5F_Text_KarinaPostBattle::
	.string "うう\n"
	.string "しょうきに　もどった！$"

PokemonTower_5F_Text_JanaeIntro::
	.string "…　ド…　ギャ\n"
	.string "…　ギ…　ギャ…ーン！$"

PokemonTower_5F_Text_JanaeDefeat::
	.string "ぶるぶる…$"

PokemonTower_5F_Text_JanaePostBattle::
	.string "やまおくで　しゅぎょう　したのに\n"
	.string "…　なさけない$"

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
	.string "せいなる　いのりに　まもられた\n"
	.string "けっかいへ　はいった！\p"
	.string "{PLAYER}と　ポケモンは\n"
	.string "ひと　やすみして　げんきに　なった！$"

