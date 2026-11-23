Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
	.string "なにが　あっても　だいじょうぶな\nように　そなえろ！\pおまえの　ポケモンが　ちゃんと\nそだっているか　みせて　みろ！$"

Route45_Text_HikerErikBeaten:
	.string "ああ　まけちまった！$"

Route45_Text_HikerErikAfter:
	.string "フスベの　こおりのぬけみちに\nもどって　もっと　しゅぎょうだ$"

Route45_Text_HikerMichaelSeen:
	.string "よう！　げんきだな！　でも\nしってるか？\pげんきさ　だけなら\nおれが　いちばんだ！$"

Route45_Text_HikerMichaelBeaten:
	.string "おれの　ポケモンの\nげんきが　たりなかった！$"

Route45_Text_HikerMichaelAfter:
	.string "マックスアップが　だいすきでな！\nうまいんだ！\pポケモンの　ぶんまで\nのんじまうんだ！\pやめられない！$"

Route45_Text_HikerParrySeen:
	.string "おれの　ポケモンは\nパワー　まんさいだ！$"

Route45_Text_HikerParryBeaten:
	.string "がっはっは！　おれの\nだいはいぼくだ！$"

Route45_Text_HikerParryAfter:
	.string "おれは　かんがえるのが\nにがてで　な？\pだから　パワーで\nおしまくるのさ！$"

Route45_Text_ParryRegister:
	.string "おれは　かんがえるのが\nにがてで　な？\pだから　パワーで\nおしまくるのさ！$"

Route45_Text_ParryRematchIntro:
	.string "おれの　ポケモンは\nパワー　まんさいだ！$"

Route45_Text_ParryRematchDefeat:
	.string "がっはっは！　おれの\nだいはいぼくだ！$"

Route45_Text_ParryPostRematch:
	.string "おれは　かんがえるのが\nにがてで　な？\pだから　パワーで\nおしまくるのさ！$"

Route45_Text_HikerTimothySeen:
	.string "なぜ　やまに　のぼるか？\pそこに　やまが　あるからだ\pなぜ　ポケモンを　そだてるか？\pそこに　ポケモンが　いるからだ！$"

Route45_Text_HikerTimothyBeaten:
	.string "まけ‥　それも　そこに　ある！$"

Route45_Text_HikerTimothyAfter:
	.string "おれの　じんせいで　いちばんの\nできごとは　ポケモンとの\lであいさ$"

Route45_Text_HikerParryGivesIron:
	.string "どうしても　かてない！\pそのちょうしで　がんばれ！\pそうだ　これを　やろう　まえに\nあった　ときに　わたせなかった\lおくりものだ$"

Route45_Text_BlackbeltKenjiSeen:
	.string "ここで　ひとりで\nしゅぎょう　していた\pその　せいかを　みよ！$"

Route45_Text_BlackbeltKenjiBeaten:
	.string "うおおおっ！$"

Route45_Text_BlackbeltKenjiAfter:
	.string "こうなったら　やまに\nこもって　ひとりで\lしゅぎょうするしかない$"

Route45_Text_KenjiRegister:
	.string "こうなったら　やまに\nこもって　ひとりで\lしゅぎょうするしかない$"

Route45_Text_KenjiRematchIntro:
	.string "ここで　ひとりで\nしゅぎょう　していた\pその　せいかを　みよ！$"

Route45_Text_KenjiRematchDefeat:
	.string "うおおおっ！$"

Route45_Text_KenjiPostRematch:
	.string "こうなったら　やまに\nこもって　ひとりで\lしゅぎょうするしかない$"

Route45_Text_KenjiHasItem:
	.string "おう！　しゅぎょうの\nきゅうけい　ちゅうだ\pそとで　いい　ものを\nみつけた　うけとれ！$"

Route45_Text_KenjiGaveItem:
	.string "うまく　つかえよ！\pおれは　しゅぎょうに　もどる\nうおおおおおっ！$"

Route45_Text_KenjiNoRoom:
	.string "うーん　バッグが　いっぱいだな\pあきを　つくってから\nまた　こい$"

Route45_Text_BlackbeltKenjiMorning:
	.string "ひるめしの　まえに\nもう　すこし　しゅぎょうだ$"

Route45_Text_BlackbeltKenjiNight:
	.string "ひるめしで　たっぷり\nやすんだから\pまた　しゅぎょうの\nじゅんび　ばんたんだ！$"

Route45_Text_CooltrainermRyanSeen:
	.string "ポケモンの　そだてかたに\nついて　どう　おもう？$"

Route45_Text_CooltrainermRyanBeaten:
	.string "きみを　みとめるよ$"

Route45_Text_CooltrainermRyanAfter:
	.string "ポケモンを　だいじに\nそだてて　いるね\pきずなは　ピンチの\nときに　きみを　すくうよ$"

Route45_Text_CooltrainerfKellySeen:
	.string "あなたの　せんりゃくは　なに？\pつよい　わざを　むやみに\nつかうのは　おろかよ$"

Route45_Text_CooltrainerfKellyBeaten:
	.string "いいわ　わたしの　まけ$"

Route45_Text_CooltrainerfKellyAfter:
	.string "つよすぎる　わざは\nすきじゃないの\pかちたいけど　ポケモンを\nきずつけたくは　ないの$"

Route45_Text_CamperQuentinSeen:
	.string "ぼく　すっごく　つよいんだ！$"

Route45_Text_CamperQuentinBeaten:
	.string "トレーナーヒルでは\nつよかったのに‥$"

Route45_Text_CamperQuentinAfter:
	.string "トレーナーヒルに　いった？\pあそこでは　ぜったい\nまけないんだけど‥$"

Route45_Text_Sign:
	.string "45ばんどうろ\nこの　さき　やまみち$"
