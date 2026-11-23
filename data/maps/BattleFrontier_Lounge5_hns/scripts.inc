BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "えへへ！\nポケモンの　きもちが\lわかるの！\pおねがい！\nポケモン　みせて？$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "ぶー！\nけち！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "ふむふむ‥\pこのこ　たたかうのが\nすきだって！\lいたくても　たたかうって！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "ふむふむ‥\pこのこ　たたかうのが\nすきだって！\lでも　いたく　なったら\lじぶんを　まもるって！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "ふむふむ‥\pこのこ　たたかうのが\nすきだって！\lでも　いたく　なったら\lずるく　なるって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "ふむふむ‥\pこのこ　じぶんを　まもるのが\nすきだって！\lでも　いたく　なったら\lやりかえすって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "ふむふむ‥\pこのこ　じぶんを　まもるのが\nすきだって！\lいたくても　いたくなくても\lじぶんを　まもるって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "ふむふむ‥\pこのこ　じぶんを　まもるのが\nすきだって！\lでも　いたく　なったら\lずるく　なるって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "ふむふむ‥\pこのこ　ずるいのが\nすきだって！\lでも　いたく　なったら\lやりかえすって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "ふむふむ‥\pこのこ　ずるいのが\nすきだって！\lでも　いたく　なったら\lじぶんを　まもるって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "ふむふむ‥\pこのこ　ずるいのが\nすきだって！\lいたくても　ずるく\lたたかうって！$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "へんなの！　タマゴは\nねてるんだよ！\lおはなし　できないよ！$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "かわいいわね！\nあの　おじょうちゃん\lポケモンの　ことばが\lわかるん　ですって！$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "あの　おんなのこ　なにか\nふかい　ことを　いってる\lきが　するんだ$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "しってるよ！\pあの　おんなのこ　あかい\nいえで　よく　あそんでるの！$"

