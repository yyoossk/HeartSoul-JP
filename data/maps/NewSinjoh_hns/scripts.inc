NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "まいこはんたちを\nまたせない　ほうが　いい$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
	.string "オドシー！$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "ダイゴ『おくさん　あちらの\nおんせんまで　おつれ\lしましょうか？\pばしょは　まだ　たくさん\nあいて　いるようです$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "わたしは　ミルクマン\pわたしの　ミルクは\nおいしいよ\pきょう　ほしい　なら\n500円だ$"

NewSinjoh_MilkMan_GotMilk:
	.string "はい　どうぞ！\nせかいが　もとめる　ものが\lはいってるよ$"

NewSinjoh_MilkMan_NoMoney:
	.string "わるいね\nおかねが　あれば\lうって　あげるよ！$"

NewSinjoh_MilkMan_NoRoom:
	.string "バッグが　いっぱい\nみたいだね$"

NewSinjoh_MilkMan_NoSale:
	.string "いらないの？\nせかいに　ふさわしい\lものが　はいってるのに$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "もう　1ぽん　どう？$"

NewSinjoh_Text_GotMilk:
	.string "{PLAYER}は\nモーモーミルクを　てにいれた$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "わたしは　ミルクマン\pわたしの　ミルクは\nおいしいよ\pきょうは　とくべつ\nはいたつだ！$"

NewSinjoh_MilkMan_text_Lose:
	.string "この　せかいは\nかんぺき　だろう？$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

NewSinjoh_Text_TravelShopGreeting:
	.string "ちいさな　よろずやへ\nようこそ\lなにに　しますか？$"

NewSinjoh_Text_TravelShopEnd:
	.string "また　どうぞ$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
	.string "うちの　しなものは　ぜんぶ\nてづくりで　じもと　さんです！\pおおきな　まちから　とおすぎて\nフレンドリィショップが\lみせを　だして　くれないので\lあねが　この　みせを\lひらいたんです$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "ここ　さいこう！\pこの　おんせんを　せかいに\nかくしてる　なんて\lもったいない！\pともだち　みんなに\nおしえるぞ！$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "おんせんは　すてき　だけど\nじもとの　ひとに　にらまれて\lいる　きが　するの$"
NewSinjoh_Text_JaniceAfter:
	.string "おんせんは　すてきだし\nじもとの　ひとも　はなして\lみたら　とても　やさしいの！$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "いい　けしきほど　としよりの\nこころを　げんきに\lする　ものは　ないねえ$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "まったく　かんこうきゃくが\nおんせんを　ひとりじめ　して！\pさいきんは　わるい\nことばかり　つづくよ！$"
NewSinjoh_Text_OldLady2Steven:
	.string "まあ　すてきな\nわかもの！\pかんこうきゃくも　そう\nわるくは　ない　かもね$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "あの　ひとは　どうして\nおきゃくさんに　あんなに\lしつれい　なのかしら？\pおんせんに　つかって\nおちつけば　いいのに\pばしょは　みんなの　ぶん\nたくさん　あるわ$"
NewSinjoh_Text_OldLady3After:
	.string "みんな　おたがいに\nなれて　きたみたいね\pよかった！$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "あたらしい　ひとびとが　きてから\nむらは　わかれ　あらそいが\lたえぬ\pどちらの　たちばで　あれ\nつりあいが　みだれて\lいるのは　あきらかじゃ\pじもとの　ものにも\nかんこうきゃくにも\lやさしく　して　おくれ$"
NewSinjoh_Text_SpringsSageAfter:
	.string "でんせつの　ポケモンが\nしずまって　から\lよく　なった\pシンジョウに　つりあいが\nもどったのじゃ$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "ときは　かわれど　オドシシは\nいまも　あつまる\lありがたい　ことじゃ$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
	.string "わーーーい！！\pみて　ママ！\nてばなし！\pスノーボーダー\nみたいでしょ！$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
	.string "うちの　こ　かわいい\nでしょ！\pこの　リンクは　むかしから\nあるけど　こどもたちが　つかい\lだしたのは　あたらしい　ひとが\lきてから　なのよ$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "ニューシンジョウ$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "ファミリーカフェ$"

NewSinjoh_EventScript_Cave_Sign::
	msgbox NewSinjoh_Text_Cave_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Cave_Sign:
	.string "おんせんの　どうくつ$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "しょうばいは　だいはんじょう！\nでも　まちの　ひとが　この\lむらに　きょうみを　もって\lから　ものの　ねだんが\lあがって　しまった$"
NewSinjoh_Text_HikerAfter:
	.string "しょうばいは　だいはんじょう！\pそれに　あの　ぎんいろの　かみの\nひとが　チップを　はずむ　から\lねだんも　さがったよ！$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "じもとの　ひとに\nしか　うらないよ！$"
NewSinjoh_Text_OldLady4After:
	.string "いまでも　じもとの\nひとに　しか　うらないよ！$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end


