Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "ポケモンを　そだてて　るんだ\nしょうぶ　しない？$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "あっ！　まけちゃった‥$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "そだてたい　ポケモンが　いたら\nさいしょに　だして　すぐ\lいれかえるんだ\pそれが　コツさ$"

Route4_Text_PicnickerHope_Seen:
	.string "なんだか　かてそうな\nきが　するの\pあたるか　ためして　みましょ！$"

Route4_Text_PicnickerHope_Beaten:
	.string "もう　つよすぎるわ$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "おつきみやまに　ピッピが\nでるって　きいたの\pどこに　いるのかしら？$"

Route4_Text_PicnickerSharon_Seen:
	.string "あの‥\nわたし‥$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "‥‥もっと　しゅぎょう　してくる‥$"

Route4_Text_MtMoonSquareSign:
	.string "らくばんの　ため　おつきみやま\nあたらしい　いりぐち\pあしもとに　ちゅうい$"

