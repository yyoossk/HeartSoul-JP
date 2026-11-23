BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "えへへ！\nポケモンの　きもちが\lわかるんだよ！\pおねがい！\nポケモン　みせて！$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "ぶー！\nけち！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "ふむふむ‥\pこの　こ　たたかうのが\nすきだって！\lいたいいたいでも\lたたかうって！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "ふむふむ‥\pこの　こ　たたかうのが\nすきだって！\lでも　いたいいたいが\lふえたら　じぶんを\lだいじに　するって！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "ふむふむ‥\pこの　こ　たたかうのが\nすきだって！\lでも　いたいいたいが\lふえたら　ずるく　なるって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "ふむふむ‥\pこの　こ　じぶんを\nだいじに　するって！\lでも　いたいいたいが\lふえたら　やりかえすって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "ふむふむ‥\pこの　こ　じぶんを\nだいじに　するって！\lいたいいたいでも　そう\lじゃなくても　じぶんを\lだいじに　するって！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "ふむふむ‥\pこの　こ　じぶんを\nだいじに　するって！\lでも　いたいいたいが\lふえたら　ずるく　なるって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "ふむふむ‥\pこの　こ　ずるいのが\nすきだって！\lでも　いたいいたいが\lふえたら　やりかえすって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "ふむふむ‥\pこの　こ　ずるいのが\nすきだって！\lでも　いたいいたいが\lふえたら　じぶんを\lだいじに　するって！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "ふむふむ‥\pこの　こ　ずるいのが\nすきだって！\lいたいいたいでも\lずるく　するって！$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "へんなの！　タマゴは\nねてるよ！\lおはなし　できないよ！$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "かわいらしい！\nあの　おじょうちゃん\lポケモンの　きもちが\lわかるん　ですって！$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "あの　おんなのこ\nなんだか　ふかい　ことを\lいってる　きが　するわ$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "しってるよ！\pあの　おんなのこ\nあかい　いえで\lよく　あそんでるの！$"

