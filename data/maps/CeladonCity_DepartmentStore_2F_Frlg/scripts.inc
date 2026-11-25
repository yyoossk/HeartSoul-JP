CeladonCity_DepartmentStore_2F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM45
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
	.string "　そ　デぐねくけいいそ　Tぐねくけいいそ　zぐねくけういゆガあむすィい　かあゲっのくハコヌヂごのくニョぶぐねくそ　フぃのくけえフい　　　う　に　ね　せ　つ　ち　そ　た　ウ　　　フいゆガあむすィい　かあゲっのくハコヌヂごのくニョャぐねくそ　フぃのくけえフい　ゆあぁあざあぜあぱあぷあ　　フいシルバースプレーは　よわい\n"
	.string "ポケモンが　とびでて　こなくなる\p"
	.string "ほう！　むしよけスプレーの\n"
	.string "きょうりょくな　やつだな$"

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
	.string "とおで　するなら\n"
	.string "げんきのかけらは\l"
	.string "かっといた　ほうが　いいわ$"

CeladonCity_DepartmentStore_2F_Text_FloorSign::
	.string "トレーナーグッズが　いっぱい！\n"
	.string "２かい…トレーナーズ・マーケット$"

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
	.string "ここに　たまに　くる\n"
	.string "ワタルって　ひと…\l"
	.string "いつも　マントを　かっていくの\p"
	.string "おなじ　マントを\n"
	.string "なんまいも　もってるのかな？$"
