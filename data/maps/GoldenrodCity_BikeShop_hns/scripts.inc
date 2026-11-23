GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "バッグで　とうろく　しておけば\nボタン　ひとつで　じてんしゃに\lのれるよ\pもっと　はやく　はしりたいなら\nまず　とまらないと　いけない！\pへんな　アドバイスに　きこえる\nけど　ギアは　とまっている\lときしか　かえられないんだ\pとまっている　ときに　Rボタンを\nおせば　つぎに　こいだ　とき\lもっと　はやく　はしれるよ！$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
	.string "‥はあ‥　ひっこして　きたけど\nじてんしゃが　うれないんだ\lなんで　だろう？\pじてんしゃに　のって\nせんでん　して　くれないか？$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
	.string "ほんとうかい？　たすかるよ！\pなまえと　でんわばんごうを\nおしえて　くれたら\lじてんしゃを　かして　あげるよ$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
	.string "{PLAYER}は\nじてんしゃを　かりた$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "カントーから　ひっこして　きて\nしょうばいが　たいへんでね\lてつだって　くれて　ありがとう！\pうちの　とっきょの　ギアチェンジを\nみせびらかして　きてね\pじてんしゃで　とまっている\nときに　Rボタンを　おすだけ\pきをつけて！　すごく\nはやく　なるからね！$"

GoldenrodCity_BikeShop_Text_Refused:
	.string "‥はあ‥　ひとの　やさしさが\nほしいなあ‥$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
	.string "しんはつばい！\pこうせいのうの　おりたたみ\nじてんしゃ！$"

GoldenrodCity_BikeShop_Text_Bicycle:
	.string "ピカピカの　あたらしい\nじてんしゃだ！$"
