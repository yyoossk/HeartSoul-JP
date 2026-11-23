EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
	.string "ママ『もしもし　げんき？\pあなたの　ちょきんで\nいいもの　かっちゃった！\pパソコンに　おくっておいたわ\nがんばってね！$"

Mom_Text_GiftCall_Berry:
	.string "ママ『もしもし　げんき？\pおみせで　いい　きのみを\nみつけたの！\pパソコンに　おくっておいたわ\nがんばってね！$"

Mom_Text_GiftCall_Decoration:
	.string "ママ『もしもし　げんき？\pあなたの　へやに　かわいい\nにんぎょうを　かったわよ！\pかえったら　もようがえを\nみてね　がんばってね！$"
