OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "あ‥　こんにちは\n{PLAYER}さん\pまえの　おさらは　ぜんぶ\nわたしの　では　なくて‥\pえっと‥\pじつは　まえに　ここに\nすわってた　ひとが\lたくさん　たべて‥\pまた　しょうぶ　するなら\nヤマブキシティの\lかくとうどうじょうへ\lきて　ください$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	call KJ_EventScript_GiveHM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "はっ！　おまえの　ポケモン\nひょろひょろ　だな！\pいわを　どかす　ちからも\nなさそうだ\pほら　これで　かいりきを\nおしえて　やれ！$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "うみの　うえで　たよれるのは\nじぶん　だけだ！\pおれは　この　にくたいが\nじまんさ！　おまえも\lきたえろよ！$"

OlivineCity_Text_CafeFishingGuru:
	.string "アサギしょくどうの　メニューは\nおれ　みたいな　たくましい\lふなのり　むけの　ものばかり！$"

OlivineCity_Text_CafeSailor:
	.string "この　まちに　くると　いつも\nアサギしょくどうに　よるんだ\pどれを　たべても　ちからが\nわいてくる　とまらない！$"

