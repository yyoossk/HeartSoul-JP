UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "ひとに　あうのは\nひさしぶりだ\pえんりょ　するな\nしょうぶ　しよう！$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "うぐぐ‥$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "ずっと　まよってるんだ‥\pここは　きらいじゃ　ないけど\nおなかが　すいた！$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "おお！　おきゃくさんだ！$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "わはは！\nげんきな　やつだ！$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "おれは　ここに\nすんでるんだ\pきみも　すみたけりゃ\nどうぞ\pばしょは　いくらでも\nあるからな$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "だれだ？\pぼくと　ポケモンを\nほっといて　くれ！$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "あ‥　あっちへ　いけ！$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "ぼくと　ポケモン　だけ\nしあわせで　たまらない$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "ポケモンの　けんきゅうの\nために　ここまで　きたんだ\pじっせんで　けんきゅうの\nせいかを　みせて　あげる！$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "みせられたのは\nこっち　だった！$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "けんきゅうの　せいかを\nまとめて　はっぴょう　しよう\pウツギはかせ　みたいに\nゆうめいに　なれるかも$"
