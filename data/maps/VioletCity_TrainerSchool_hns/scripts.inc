VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "ゲームボーイアドバンス　せだい\nじゃないけど　ポケモンの\lゲームが　だいすきなの！\pむかしの　ゲームでは　やせいの\nポケモンと　たくさん　たたかって\lけいけんちを　かせいだのよ\pでも　さいきんの　ゲームでは\nがくしゅうそうちで　レベルが\lあがりすぎちゃうの\pこの　ゲームの　がくしゅうそうちは\nちょうど　いい　レベルに　なるように\lちょうせい　されてるの\lたたかう　かずに　よっては\lすこし　たかめに　なるわ\pむかしながらの　1〜4せだいの\nあそびかたが　したいなら\lがくしゅうそうちを　オフ\lいまどきの　あそびかたなら\lがくしゅうそうちを　オンにしてね\pあそびかたは　あなたが\nきめていいのよ！$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "アール　わたしです！\pポケモン　すばらしい　です！\pもっと　いい　トレーナーに\nなれるよう　おしえて　あげます！$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "さいしょは　よわくて\nつよく　なるまでに　ほかより\lずっと　けいけんちが　いる\lポケモンも　います\pたとえば　ヨーギラスは　とても\nよわいですが　たくさんの\lけいけんちを　つめば　やがて\lつよい　バンギラスに　なります\pそういう　ポケモンを　そだてるのは\nほんとうに　ねっしんな\lトレーナー　だけに\lしましょうね$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "グッド！　おしえて　あげます！\pしょうぶ　では　リストの\nいちばん　うえの　ポケモン\pさいしょに　でます！\nならびかえ　しょうぶ\lらくに　なる　かも！\pもっと　ききたい　ですか？$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "では　ポケモンの　じょうずな\nそだてかた　しりたい　ですか？$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "グッド！　おしえて　あげます！\pしょうぶに　すこしでも　でた\nポケモン　けいけんち\pもらえます\nリストの　いちばん　うえに\pよわい　ポケモン　おいて\nすぐ　いれかえ！\pこれで　よわい　ポケモン\nつよく　なります！$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "オー！　かしこい　せいと\nですね！　もう　おしえる\lこと　ありません！\pもっと　しりたければ\nせいとに　きいて　ください！$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "こうかんでしか　しんか　しないと\nおもわれていた　ポケモンも\pレベルアップで　しんか　するんだ\nゴーリキーと　ゴローンは\pレベル38　ユンゲラーと\nゴーストは　レベル42だよ\pメタルコートみたいに　もたせて\nレベルを　あげると\pしんか　する　ポケモンが\nいる　どうぐも　あるんだ$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "その　ばしょで　とれる　おもな\nポケモンは　フィールドで\lみえるんだ！\pでも　どうろは　ひるも　よるも\nたしかめてね！$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "ジョウトの　きのみは　かいふくや\nボールづくりに　つかえるの\pカントーの　きのみは　ポケモンの\nのうりょくを　さげるのに　いいの\pカントーの　どうじょうでは\nのうりょくを　ひとつずつ\lみがけるのよ$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "あいては　タイプの　バランスが\nいい　チームを　つかって\lくるから　これからの　たびは\lもっと　きびしく　なるよ$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "こくばんに　ひでんわざの\nことが　かいてある\pひでんわざは　つかえるように\nなれば　おぼえさせなくても\lつかえる$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "この　こどもの　ノートだ‥\pポケモンは　モンスターボールで\nつかまえよう\pてもちには　6ぴきまで\nつれて　いける\pつづきを　よむ？$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "ボールを　なげる　まえに\nあいてを　よわらせよう\pどくや　やけどの　ポケモンは\nつかまえやすい\pつづきを　よむ？$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "わざで　こんらん　することがある\pこんらんすると　じぶんを\nこうげき　することがある\pしょうぶから　でれば\nこんらんは　なおる\pつづきを　よむ？$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "ポケモンを　つかまえて\nしょうぶに　つかう　ひとが\nポケモントレーナー\pトレーナーは　ポケモンジムを\nまわって　ほかの　トレーナーに\nかつ　ことを　めざす\pつぎの　ページは‥　まっしろだ！\pしょうねん『えへへ‥\pまだ　かいて　ないんだ‥$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "データを　シールに　して\nだしてくれる　すごい　きかいだ！$"
