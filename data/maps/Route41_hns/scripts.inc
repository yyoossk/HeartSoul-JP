Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "ここの　みずは　あったかい\nからだも　ほぐれてるぜ\pいいとも　あいてを　しよう！$"

Route41_Text_SwimmermCharlieBeaten:
	.string "うわっ！　ゆびが\nしわしわだ！$"

Route41_Text_SwimmermCharlieAfter:
	.string "こうして　ぷかぷか　うかんでると\nおちつくよなあ$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "ちょっと　つかれた\nかったら　ポケモン　かしてくれ$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "ぜえ　ぜえ‥$"

Route41_Text_SwimmermGeorgeAfter:
	.string "タンバまで　とおすぎる\pでも　アサギに　もどるのも\nらくじゃ　ない\pどうしよう？$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "うずしおに　かこまれた\nしまが　みえるだろ？\pぜったい　なにか\nひみつが　あるはずだ！$"

Route41_Text_SwimmermBerkeBeaten:
	.string "きみの　つよさの　ひみつは？$"

Route41_Text_SwimmermBerkeAfter:
	.string "あらしの　よる　だった‥\pしまから　とびたつ\nきょだいな　ポケモンを　みたんだ\pぎんいろの　つばさから\nはねを　まきちらしていた$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "ここは　なみが　あらい\pおよいでいると\nつかれるんだ$"

Route41_Text_SwimmermKirkBeaten:
	.string "へとへとだ！$"

Route41_Text_SwimmermKirkAfter:
	.string "ながれが　つよくて\nあの　しまに　とどかない$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "うずまきじまの　ひみつを\nさがしてるのか？$"

Route41_Text_SwimmermMathewBeaten:
	.string "おお　すごい　たいりょくだ！$"

Route41_Text_SwimmermMathewAfter:
	.string "うずまきじまの　ひみつ‥\pなかは　まっくら　なんだ！$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "うずまきじまに　いく\nとちゅうなの\pともだちと　たんけんよ$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "そういう　ふうに　やるのね？$"

Route41_Text_SwimmerfKayleeAfter:
	.string "うずまきじまの　おくふかくに\nおおきな　ポケモンが　いるらしいの\pなんだろう？$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "ポケモンに　のって\nゆうがね$"

Route41_Text_SwimmerfSusieBeaten:
	.string "くやしい‥$"

Route41_Text_SwimmerfSusieAfter:
	.string "ラプラスに　のった　しょうねんの\nヒットきょくが　なかった？$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "てんきが　よすぎて\nぼーっと　しちゃう！$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "ああっ！$"

Route41_Text_SwimmerfDeniseAfter:
	.string "ひやけは　はだに　わるいの\pでも　ひやけどめは　ぬらない\pうみを　よごしたくないもの$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "やすみたい　ときは\nたちおよぎ　すれば　いいの\pいきが　ととのえば\nまた　およげるわ$"

Route41_Text_SwimmerfKaraBeaten:
	.string "まあ！　わたしより\nげんきね$"

Route41_Text_SwimmerfKaraAfter:
	.string "しまの　おくから\nうなりごえが　きこえたの$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "よるに　なると　ヒトデマンが\nすいめんに　あつまるの$"

Route41_Text_SwimmerfWendyBeaten:
	.string "あらまあ‥$"

Route41_Text_SwimmerfWendyAfter:
	.string "ヒトデマンの　むれが\nいっせいに　ひかるの\pきれいすぎて　こわいくらい$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "ドククラゲ『クルルル‥$"

Route41_Text_TentacruelAttack:
	.string "ドククラゲ『クルルルルッ！$"

Route41_Text_TentacruelHeal:
	.string "ドククラゲは　じこさいせいを\nつかった！　たいりょくが　もどった！$"
