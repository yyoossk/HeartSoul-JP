Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "トレーナーどうし　であったら\nまずは　しょうぶだ$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "ああ‥　まけこしだ‥$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "トレーナーは　であったら\nしょうぶ　するのが　あたりまえ$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "そこの　あなた！\nしょうぶ　しない？$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "かんぱい‥$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "あなた　つよいのね\pきっと　いっしょうけんめい\nきたえたのね$"

Route1_Text_Sign:
	.string "1ばんどうろ\pマサラタウン　ー　トキワシティ$"
