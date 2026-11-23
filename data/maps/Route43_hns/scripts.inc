Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
	.string "ポケモン　だいすき！\pだから　あつめはじめたし\nこれからも　あつめつづけるぞ！$"

Route43_Text_PokemaniacBenBeaten:
	.string "なんて　ことを　するんだ？$"

Route43_Text_PokemaniacBenAfter:
	.string "ポケモンの　ほかに　すきな　もの？\pラジオの　クルミちゃん\nきっと　かわいいよ！$"

Route43_Text_PokemaniacBrentSeen:
	.string "おい！　めずらしい\nポケモン　もってるか？$"

Route43_Text_PokemaniacBrentBeaten:
	.string "ああ　かわいそうな\nポケモンたち！$"

Route43_Text_PokemaniacBrentAfter:
	.string "めずらしい　ポケモンが　1ぴき\nいるだけで　しあわせ　なんだ$"

Route43_Text_BrentRegister:
	.string "めずらしい　ポケモンが　1ぴき\nいるだけで　しあわせ　なんだ$"

Route43_Text_BrentRematchIntro:
	.string "おい！　めずらしい\nポケモン　もってるか？$"

Route43_Text_BrentRematchDefeat:
	.string "ああ　かわいそうな\nポケモンたち！$"

Route43_Text_BrentPostRematch:
	.string "めずらしい　ポケモンが　1ぴき\nいるだけで　しあわせ　なんだ$"

Route43_Text_PokemaniacRonSeen:
	.string "きいてくれよ！\p{RIVAL}って　やつが　おれの\nポケモンを　ばかに　したんだ！\pくそう！　おれの　ポケモンは\nすごいんだ！$"

Route43_Text_PokemaniacRonBeaten:
	.string "ニドキングは　よく　がんばった！$"

Route43_Text_PokemaniacRonAfter:
	.string "すきな　ポケモンが　ひとそれぞれ\nちがっても　いいんだ\pつよい　ポケモンを　もつ　ことだけが\nポケモンじゃない$"

Route43_Text_FisherMarvinSeen:
	.string "スランプ　なんだ\pどうぐの　せいかな\pきぶんてんかんに　しょうぶだ！$"

Route43_Text_FisherMarvinBeaten:
	.string "まけたけど　すっきりしたよ$"

Route43_Text_FisherMarvinAfter:
	.string "つりあげた　ポケモンを　つかまえる\nなら　ガンテツさんの　ルアーボールが\lいちばんだ\pハイパーボールより\nずっと　よく　つかまるぞ$"

Route43_Text_CamperSpencerSeen:
	.string "ポケモンと　いろんな　ことが\nできて　すっごく　たのしい！$"

Route43_Text_CamperSpencerBeaten:
	.string "まけるのは　ちっとも　たのしくない‥$"

Route43_Text_CamperSpencerAfter:
	.string "いかりのみずうみで　なにが\nおきてるんだろう？\pキャンプする　つもりだったのに$"

Route43_Text_PicnickerTiffanySeen:
	.string "あなたも　いかりのみずうみに\nいくの？\pちょっと　あそびましょ！$"

Route43_Text_PicnickerTiffanyBeaten:
	.string "あそびすぎちゃった！$"

Route43_Text_PicnickerTiffanyWantsPicnic:
	.string "ポケモンと　ピクニック　ちゅうなの\pあなたも　いっしょに　どう？$"

Route43_Text_TiffanyRegister:
	.string "ポケモンと　ピクニック　ちゅうなの\pあなたも　いっしょに　どう？$"

Route43_Text_TiffanyRematchIntro:
	.string "あなたも　いかりのみずうみに\nいくの？\pちょっと　あそびましょ！$"

Route43_Text_TiffanyRematchDefeat:
	.string "あそびすぎちゃった！$"

Route43_Text_TiffanyPostRematch:
	.string "ポケモンと　ピクニック　ちゅうなの\pあなたも　いっしょに　どう？$"

Route43_Sign1:
	.string "43ばんどうろ\pいかりのみずうみ　ー　チョウジタウン$"

Route43_Sign2:
	.string "43ばんどうろ\pいかりのみずうみ　ー　チョウジタウン$"

Route43_TrainerTips:
	.string "トレーナーの　こころえ\pポケモンには　タイプによって\nとくいと　にがてが　ある\pタイプしだいでは　レベルが\nたかくても　まける　ことも\pじぶんの　ポケモンの　タイプの\nとくいと　にがてを　おぼえよう$"
