Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "ああ！　きょうも　いい　てんきだ$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "はれてるのに　ずぶぬれだ‥$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "あめの　ひは　ひが\nつきにくいんだ‥$"

Route3_Text_YoungsterWarren_Seen:
	.string "うーん‥　どうしよう‥$"

Route3_Text_YoungsterWarren_Beaten:
	.string "まけると　おもった‥$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "つよそうに　みえたから\nしょうぶ　するのが\lこわかったんだ‥$"

Route3_Text_YoungsterJimmy_Seen:
	.string "ぼくは　かぜの　ように\nはしれるんだ！$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "ふきとばされた！$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "いちねんじゅう　はんズボン\pそれが　ぼくの\nファッションの　こだわり$"

Route3_Text_FirebreatherBurt_Seen:
	.string "よってらっしゃい\nみてらっしゃい！$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "あちっ！　あついぜ！$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "カントー　いちの　ひふき\nそれが　おれさ\pでも　トレーナーとしては\nいちばんじゃない‥$"

Route3_Text_MtMoonSquareSign:
	.string "おつきみやま　ひろば\pかいだんを　のぼってね$"

