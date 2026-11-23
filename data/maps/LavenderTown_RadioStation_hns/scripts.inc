LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "いらっしゃいませ！　この　かいは\nじゆうに　ごらん　ください$"

LavenderTown_RadioStation_Text_Officer:
	.string "すみませんが　けんがく\nできるのは　1かい　だけです\pジョウトの　ラジオとうが　はんざい\nグループに　のっとられて　から\lけいびを　きょうか　して\lいるんです$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "この　ラジオとうでは　たくさんの\nひとが　はたらいて　いる\pいい　ばんぐみを　つくるために\nがんばってるんだろうな$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "ああ　だめだ　だめだ！\pはつでんしょが　とまってから\nほうそうが　できないんだ\pほうそう　できなければ\nこの　きょくを　つくった\lくろうが　みずの　あわだ\pもう　おしまいだ！$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "おお！　きみが　はつでんしょの\nもんだいを　かいけつ　した\l{PLAYER}くん　だね？\pおかげで　しごとを\nうしなわずに　すんだよ\pきみは　いのちの\nおんじんだ！\pおれいに　これを\nうけとって　くれ$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER}は\nかくちょうカードを　もらった！$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "それが　あれば　カントーの\nラジオばんぐみも　きけるぞ\pがはははは！$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "やあ！\pぼくは　スーパー\nおんがく　ディレクター！\p"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "やあ！\pぼくは　スーパー\nおんがく　ディレクター！\pでんぱに　のる　すてきな\nメロディーは　ぼくの　しごと\pかたい　こと　いわずに\nおんがくを　きいてよ！$"

LavenderTown_RadioStation_Text_Directory:
	.string "1F　うけつけ　2F　えいぎょうぶ\p3F　じんじぶ　4F　せいさくぶ\p5F　きょくちょうしつ$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "ポケモンの　ふえの　しらべで\nポケモンも　げんきに！\lチャンネル20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "うわあ！　ポケモンの　CDや\nビデオが　ぎっしりだ\pここは　しりょうしつ\nらしい$"

