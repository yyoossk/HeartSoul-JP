Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
	.string "ああっ！\pおまえの　せいで　ニョロモを\nにがしたぞ！　どうしてくれる？$"

Route44_Text_FisherWilton1Beaten:
	.string "もう　わすれて　くれ$"

Route44_Text_FisherWiltonHugePoliwag:
	.string "にがした　ニョロモ‥\nでかかったなあ\pぜったい　5メートルは\nあったぞ！$"

Route44_Text_WiltonRegister:
	.string "にがした　ニョロモ‥\nでかかったなあ\pぜったい　5メートルは\nあったぞ！$"

Route44_Text_WiltonRematchIntro:
	.string "ああっ！\pおまえの　せいで　ニョロモを\nにがしたぞ！　どうしてくれる？$"

Route44_Text_WiltonRematchDefeat:
	.string "もう　わすれて　くれ$"

Route44_Text_WiltonPostRematch:
	.string "にがした　ニョロモ‥\nでかかったなあ\pぜったい　5メートルは\nあったぞ！$"

Route44_Text_WiltonHasItem:
	.string "おーい！　ポケモンじゃない\nものが　つれたぞ！\pほら　やるよ！$"

Route44_Text_WiltonGaveItem:
	.string "また　なにか　つれたら\nしらせるぜ！$"

Route44_Text_WiltonNoRoom:
	.string "うーん　バッグが　いっぱいだな\pあきを　つくってから\nまた　こいよ$"

Route44_Text_FisherEdgarSeen:
	.string "つれなくなるまで　つる\pたおれるまで　たたかう\pそれが　おれと\nポケモンの　かんけいだ$"

Route44_Text_FisherEdgarBeaten:
	.string "うーん‥　こんな　はずじゃ$"

Route44_Text_FisherEdgarAfter:
	.string "これで　100しょう　101ぱいだ\pしばらく　しょうぶは\nやめておこう$"

Route44_Text_BirdKeeperVance1Seen:
	.string "でんせつの　とりポケモンを\nしってるか？$"

Route44_Text_BirdKeeperVance1Beaten:
	.string "ふう！　おまえ　すごいな$"

Route44_Text_BirdKeeperVanceBirds:
	.string "フリーザー　サンダー　ファイヤーが\nでんせつの　とりポケモンだ\pでも　ほかにも　でんせつの\nとりが　いるらしいぜ$"

Route44_Text_VanceRegister:
	.string "フリーザー　サンダー　ファイヤーが\nでんせつの　とりポケモンだ\pでも　ほかにも　でんせつの\nとりが　いるらしいぜ$"

Route44_Text_VanceRematchIntro:
	.string "でんせつの　とりポケモンを\nしってるか？$"

Route44_Text_VanceRematchDefeat:
	.string "ふう！　おまえ　すごいな$"

Route44_Text_VancePostRematch:
	.string "フリーザー　サンダー　ファイヤーが\nでんせつの　とりポケモンだ\pでも　ほかにも　でんせつの\nとりが　いるらしいぜ$"

Route44_Text_PsychicPhilSeen:
	.string "ぜったい　かつぞ！$"

Route44_Text_PsychicPhilBeaten:
	.string "うう‥　ショックな　まけだ‥$"

Route44_Text_PsychicPhilAfter:
	.string "しんねんを　もつ　ことが\nたいせつ　なんだ$"

Route44_Text_PokemaniacZachSeen:
	.string "めずらしい　ポケモンの\nためなら　なんでも　するぞ！$"

Route44_Text_PokemaniacZachBeaten:
	.string "おお　きみの　ポケモン\nみりょくてきだ$"

Route44_Text_PokemaniacZachAfter:
	.string "いつもと　いろが　ちがう\nポケモンは　かちが　あるんだ\pえ？　そうじゃない　って？$"

Route44_Text_CooltrainermAllenSeen:
	.string "みれば　いい　トレーナーだと\nわかるよ\pおれも　ポケモンは　とくいだが\nきみも　そうだな$"

Route44_Text_CooltrainermAllenBeaten:
	.string "ちっ！　かんぜんに\nおれの　まけだ$"

Route44_Text_CooltrainermAllenAfter:
	.string "わあ　バッジを　たくさん\nもってるな\pどうりで　つよい　わけだ\pエンジュジムの　マツバさんは\nまだ　しゅぎょう　してるかな？\pこてんぱんに　やられたよ$"

Route44_Text_CooltrainerfCybilSeen:
	.string "あなた　つよそうね\pいい　トレーナーは　ほんのうで\nつよい　あいてを　もとめるの$"

Route44_Text_CooltrainerfCybilBeaten:
	.string "だめ！　ぜんぜん　だめだわ$"

Route44_Text_CooltrainerfCybilAfter:
	.string "たくさん　しょうぶして\nみんな　つよく　なるの\pたくさん　たたかって　いまの\nエリートの　わたしが　あるのよ$"

Route44_Text_Sign1:
	.string "44ばんどうろ\nこの　さき　こおりのぬけみち$"

Route44_Text_Sign2:
	.string "44ばんどうろ\pチョウジタウン　ー　フスベシティ$"

