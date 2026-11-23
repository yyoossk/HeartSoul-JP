GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
	.string "どうやって　ここまで　きた？\pしかたない\nかたづけて　やる$"

RadioTowerBasement_Text_GruntM24Beaten:
	.string "かたづけられた‥$"

RadioTowerBasement_Text_GruntM24After:
	.string "ロケットだんは　サカキさまの\nかえりを　まちつづける\pそのためなら\nなんでも　するぞ$"

RadioTowerBasement_Text_GruntM14Seen:
	.string "ここから　さきへは　いかせない！\pてきには　ようしゃ　しない\nガキでもな！$"

RadioTowerBasement_Text_GruntM14Beaten:
	.string "ちくしょう！$"

RadioTowerBasement_Text_GruntM14After:
	.string "まけた‥\pおゆるし　ください\nサカキさま！$"

RadioTowerBasement_Text_GruntM15Seen:
	.string "ひゃっひゃっひゃ！\nだれかと　おもえば！\pじゅんびは　いいか？\nおれは　つよく　なったぞ！$"

RadioTowerBasement_Text_GruntM15Beaten:
	.string "ひゃっひゃっひゃ！　つよいな！\pロケットだんは　ただの　しごと\nだけど　ひとを　きずつけてるって\lわかったよ\pもう　やめる\pほんとうに　ありがとう\nごめんなさい　サカキさま！$"

RadioTowerBasement_Text_GruntM15After:
	.string "ひゃっひゃっひゃ！　たのしかった！\nおまえの　ことは　わすれないぜ！$"

RadioTowerBasement_Text_DirectorIntro:
	.string "きょくちょう『だれだ？　なんだ？\nわたしを　たすけに　きたのか？\pありがとう！\pラジオとう！\pあっちは　どうなって　いる？\pロケットだんに　のっとられた？\pさあ　この　カードキーを\nもって　いきなさい$"

RadioTowerBasement_Text_DirectorCardKey:
	.string "きょくちょう『それで　3かいの\nシャッターを　あけるんだ$"

RadioTowerBasement_Text_DirectorAfter:
	.string "たのむ　たすけて　くれ\pやつらが　そうしんきを　にぎったら\nなにを　するか　わからない\pとくべつな　でんぱで　ポケモンを\nあやつる　つもりかも　しれない！\pたのめるのは　きみ　だけだ\pどうか　ラジオとうを\nすくって　くれ‥\pそして　ぜんこくの\nポケモンを！$"
