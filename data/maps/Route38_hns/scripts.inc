Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "そらたかく　まいあがれ\nわたしの　かわいい　とりポケモン！$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "このまま　とんでいって\nしまいたい　きぶんだ$"

Route38_Text_BirdKeeperTobyAfter:
	.string "タンバシティで　しゅぎょうして\nポケモンに　そらをとぶを\lおぼえさせる　つもりだ$"

Route38_Text_SchoolboyChad1Seen:
	.string "きょう　ならった　ことを\nためさせて　もらうよ$"

Route38_Text_SchoolboyChad1Beaten:
	.string "べんきょう　たりなかった\nみたい$"

Route38_Text_SchoolboyChadAfter:
	.string "テストが　おおくて\nポケモンの　じかんが\lあまり　ないんだ\pだから　あそべる　ときは\nしゅうちゅう　するんだ$"

Route38_Text_ChadRegister:
	.string "テストが　おおくて\nポケモンの　じかんが\lあまり　ないんだ\pだから　あそべる　ときは\nしゅうちゅう　するんだ$"

Route38_Text_ChadRematchIntro:
	.string "きょう　ならった　ことを\nためさせて　もらうよ$"

Route38_Text_ChadRematchDefeat:
	.string "べんきょう　たりなかった\nみたい$"

Route38_Text_ChadPostRematch:
	.string "テストが　おおくて\nポケモンの　じかんが\lあまり　ないんだ\pだから　あそべる　ときは\nしゅうちゅう　するんだ$"

Route38_Text_LassDana1Seen:
	.string "あなた　ポケモン\nとくい　みたいね\pだったら　なにか　アドバイス\nしてくれない？$"

Route38_Text_LassDana1Beaten:
	.string "なるほど　そういう\nたたかいかたも　あるのね$"

Route38_Text_LassDanaAfter:
	.string "いい　こと　しってるわ！\pモーモーぼくじょうの　ミルクは\nおいしいので　ゆうめいなの$"

Route38_Text_BeautyValerieSeen:
	.string "こんにちは！\nかわいい　トレーナーさんね！\pポケモンを　みせて\nくれる？$"

Route38_Text_BeautyValerieBeaten:
	.string "ポケモンが　みられて\nうれしかったわ！$"

Route38_Text_BeautyValerieAfter:
	.string "ポケモンを　みていると\nこころが　やすらぐの$"

Route38_Text_SailorHarrySeen:
	.string "かいがいに　いってたから\nいろんな　ポケモンを\lしってるぜ！$"

Route38_Text_SailorHarryBeaten:
	.string "せかいレベルの　うでまえだ！$"

Route38_Text_SailorHarryAfter:
	.string "せかいじゅうの　ひとが\nポケモンと　なかよく\lくらしてるんだ$"

Route38_Text_BeautyOliviaSeen:
	.string "わたしと　ポケモン\nうつくしいと　おもわない？$"

Route38_Text_BeautyOliviaBeaten:
	.string "わたしたち　まいにち\nモーモーミルクを　のんでるの$"

Route38_Text_BeautyOliviaAfter:
	.string "モーモーミルクは　びようと\nけんこうに　いいの\pでも　1ぽんずつしか\nうってくれないのよね$"

Route38_Text_Sign:
	.string "38ばんどうろ\pアサギシティ　ー　エンジュシティ$"

Route38_Text_TrainerTips:
	.string "トレーナーの　こころえ\pポケモンが　しんか\nしようとしても　とめられる\pしんかの　とちゅうで\nBボタンを　おすと　とまる\pポケモンが　おどろいて\nしんかが　とまるのだ$"


Route38_Text_WaterSign:
	.string "およぐのも　つりも　きんし\nのうぎょうようの　みずです\p　エンジュ　ぎかい$"

Route38_Text_DanaRegister:
	.string "いい　こと　しってるわ！\pモーモーぼくじょうの　ミルクは\nおいしいので　ゆうめいなの$"

Route38_Text_DanaRematchIntro:
	.string "あなた　ポケモン\nとくい　みたいね\pだったら　なにか　アドバイス\nしてくれない？$"

Route38_Text_DanaRematchDefeat:
	.string "なるほど　そういう\nたたかいかたも　あるのね$"

Route38_Text_DanaPostRematch:
	.string "いい　こと　しってるわ！\pモーモーぼくじょうの　ミルクは\nおいしいので　ゆうめいなの$"

Route38_Text_DanaHasItem:
	.string "ねえ！　おもしろい　ものを\nみつけたの！\pはい　あげる！$"

Route38_Text_DanaGaveItem:
	.string "また　なにか　みつけたら\nしらせるね！$"

Route38_Text_DanaNoRoom:
	.string "うーん　バッグが　いっぱいね\pあきを　つくってから\nまた　きて$"
