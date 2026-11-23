Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "ひとを　こいしく　おもうのは‥\nしかたない　ことだ\pでも　しょうぶは　しょうぶ\nいくぞ！$"

Route47_Text_HikerBeaten::
	.string "わはは！$"

Route47_Text_HikerAfter::
	.string "しょうぶの　あとは\nわらって　わかれるもんだ！$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "ひとごみが　にがてで\nポケモンと　ここで\lキャンプ　してるんだ！$"

Route47_Text_CamperBeaten::
	.string "もっと　やまの　おくに\nいくべき　かな‥$"

Route47_Text_CamperAfter::
	.string "じゃあね！$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "トム『1たす1は　2　でも\nふたりなら　もっと　つよい！\pカエ『わたしたち　ありきたりな\nコンビじゃ　ないわよ！$"

Route47_Text_Couple1Beaten::
	.string "トム『そうぞう　してたのと　ちがう\lカエ『あなたも　かわってるわ！$"

Route47_Text_Couple1After1::
	.string "トム『きみの　ちからは\nまったく　よそく　できない！$"

Route47_Text_Couple1After2::
	.string "カエ『ただの　ひとりぼっちの\nトレーナーだと　おもってた\lとんだ　かんちがいね！$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "ダフ『かのじょを　みまもると\nこころが　はずむ！\pエダ『かれへの　おもいは　うみ\nのように　ひろくて　ふかいの！$"

Route47_Text_Couple2Beaten::
	.string "ダフ『きみには　かなわなかった‥\lエダ『あなた　ほんとうに　すごい‥$"

Route47_Text_Couple2After1::
	.string "ダフ『すばらしい　しょうぶを\nありがとう！　じゃあね！$"

Route47_Text_Couple2After2::
	.string "エダ『あなたも　すてきな\nパートナーを　みつけてね！$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "やあ　こんにちは！\pこの　あなの　さきには　むかし\nそらたかく　そびえる\lきょだいな　とうが　あったそうじゃ\pはんぶんが　がけに　うまった\nふしぎな　とう　だったらしい\pそらに　むかって　のびる　だけで\nなく　ちかふかくにも\lのびて　いたんじゃ！\pうみの　そこまで　とどいて\nいたという　うわさも　ある\pつまり　この　いせきは\nそらと　だいちと　うみを\lつないで　いたんじゃな‥\pいまでは　ほとんど　くずれて\nのこっているのは　いりぐちと\lなかの　ふしぎな　もようだけじゃ$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "チョンチー『チョン！$"
