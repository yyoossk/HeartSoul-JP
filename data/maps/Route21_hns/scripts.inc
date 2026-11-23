Route21_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH_HNS, Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI_HNS, Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD_HNS, Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "りくが　みえた！\nがんばるぞ！$"

Route21_Text_SwimmermSethBeaten:
	.string "ごぼごぼ‥$"

Route21_Text_SwimmermSethAfterBattle:
	.string "グレンの　かざんに\nえらそうな　やつが　いたぜ$"

Route21_Text_SwimmerfNikkiSeen:
	.string "わたしが　かったら\nひやけどめ　ぬるのを\lてつだってね！$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "ひやけが　しんぱい‥$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "ひやけの　シミには\nきを　つけなきゃ$"

Route21_Text_FisherArnoldSeen:
	.string "つりに　あきた\nしょうぶしよう！$"

Route21_Text_FisherArnoldBeaten:
	.string "だいしっぱい‥$"

Route21_Text_FisherArnoldAfterBattle:
	.string "つりに　もどるか‥$"

