AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "まちから　ヤドンが\nいなく　なって　しまった\pもりの　かみさまが\nおこって　いるのかも‥\pわるい　まえぶれかも　しれん\nいえに　いた　ほうが　いい$"

CharcoalKiln_Text_Boss2:
	.string "ヤドンが　もどって　きた‥$"

CharcoalKiln_Text_Boss3:
	.string "ヤドンが　もどって　きた‥\pだが　でしが　ウバメのもりから\nもどって　こない\pあの　なまけものは\nどこに　いるんだ？$"

CharcoalKiln_Text_Boss4:
	.string "ロケットだんを　おいはらって\nひとりで　ウバメのもりへ\lいったのか？\pいい　どきょうだ！　きにいった\nうちで　しゅぎょう　しないか$"

CharcoalKiln_Text_Apprentice1:
	.string "ヤドンたち　どこへ\nいっちゃったんだろう？\pどこかで　あそんでるのかな？$"

CharcoalKiln_Text_Apprentice2:
	.string "ヤドンが　もどって　きた！$"

CharcoalKiln_Text_Apprentice3:
	.string "ごめん　おれい　いうの\nわすれてた\pこれは　おれが　つくった\nもくたん　なんだ\pほのおタイプの　ポケモンに\nもたせると　よろこぶよ$"

CharcoalKiln_Text_Apprentice4:
	.string "ヤドンも　もどったし\nカモネギまで　みつけて\lくれるなんて\pきみ　さいこうに\nかっこいいよ！$"

CharcoalKiln_Text_Farfetchd:
	.string "カモネギ『クワッ！$"
