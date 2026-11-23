Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "コイキング『コイ‥$"

Route12_Text_NewFisher:
	.string "きをつけな　この　みずには\nきょうぼうな　やつが　いるぞ$"

Route12_Text_FisherMartinSeen:
	.string "つりも　ポケモンも\nがまんが　だいじ$"

Route12_Text_FisherMartinBeaten:
	.string "ぐわあっ！$"

Route12_Text_FisherMartinAfterBattle:
	.string "おれは　つりには\nせっかち　すぎる‥$"

Route12_Text_FisherStephenSeen:
	.string "ラジオを　ききながらの\nつりは　しあわせだなあ$"

Route12_Text_FisherStephenBeaten:
	.string "ラジオに　きを　とられた！$"

Route12_Text_FisherStephenAfterBattle:
	.string "カントーの　ラジオばんぐみ\nきいてみた？　いろいろ\lあるんだぜ$"

Route12_Text_FisherBarneySeen:
	.string "まいにちの　くらしで\nいちばん　だいじな　ものは？$"

Route12_Text_FisherBarneyBeaten:
	.string "こたえは　このあと　すぐ！$"

Route12_Text_FisherBarneyAfterBattle:
	.string "くらしで　いちばん　だいじなのは\nでんきだと　おもうんだ\pでなきゃ　はつでんしょが\nとまった　とき　あんなに\lさわぎに　ならないだろ$"

Route12_Text_KyleRegister:
	.string "おぼえて　おくぞ\nばんごうを　おしえろ！$"

Route12_Text_KyleRematchIntro:
	.string "わすれたか？\nためして　みよう！$"

Route12_Text_KyleRematchDefeat:
	.string "おぼえていたか$"

Route12_Text_KylePostRematch:
	.string "しょうぶの　スリルは\nおおものを　つりあげるのと\lおなじ　くらい　いいぜ！$"

Route12_Text_FisherKyleSeen:
	.string "おぼえてるか？$"

Route12_Text_FisherKyleBeaten:
	.string "おぼえてるのか？$"

Route12_Text_FisherKyleAfterBattle:
	.string "ポケモンが　かかった　ときの\nつりざおの　てごたえ‥\pそれが　つりびとに　とって\nさいこうの　かんかくさ$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "12ばんどうろ\pきたへ　いくと　シオンタウン$"

Route12_Text_FishingSpotSign:
	.string "つりの　めいしょ$"

