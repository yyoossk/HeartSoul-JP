GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
	.string "マサキ『おお　{PLAYER}！　ひとつ\nたのみが　あるんや　この\lイーブイ　もらって　くれへん？\pわいが　システムの　しごとで\nるすの　あいだ　あずかってたんや\pだれかが　せわ　せなあかんけど\nわい　そとに　でるの\lすきや　ないねん\p{PLAYER}　こいつと　あそんで\nやって　くれるか？$"

BillHouse_Text_CountingOnYou:
	.string "マサキ『そう　いうと　おもてたわ！\pさすがや！　ほんまもんやな！\pほな　たのんだで\pだいじに　したってな！$"

BillHouse_Text_ReceivedEevee:
	.string "{PLAYER}は\nイーブイを　もらった！$"

BillHouse_Text_EeveeMayEvolve:
	.string "マサキ『ウツギはかせが　いうには\nイーブイは　まだ　しられて　へん\lしんかを　するかも　しれんらしい$"

BillHouse_Text_PartyFull:
	.string "おっと　まち　もう\nポケモン　もたれへんで$"

BillHouse_Text_NoEevee:
	.string "そうか‥　どないしよ？$"

BillHouse_Text_PopWontWork:
	.string "マサキ『うちの　おやじ\nぜんぜん　はたらかへんねん\lいちにちじゅう　あそんでばっかり\pほんま　あたま　いたいわ‥$"

BillHouse_Text_MomBeforeEcruteak:
	.string "あら　ポケモンを　あつめてるの？\nむすこの　マサキは　くわしいわよ\pちょうど　エンジュシティの\nポケモンセンターに\lよばれて　いったのよ\pうちの　ひとは　よばれても\nいないのに　ゲームコーナーへ‥$"

BillHouse_Text_MomAfterEcruteak:
	.string "うちの　ひと　むかしは\nポケモンマニアで　ゆうめい\lだったのよ\pマサキは　ちちおやに\nにたのね$"

BillHouse_Text_SisterUsefulNumber:
	.string "あなた　トレーナー？\pやくに　たつ　でんわばんごうを\nおしえて　あげる$"

BillHouse_Text_RecordedBillsNumber:
	.string "{PLAYER}は　マサキの\nでんわばんごうを　とうろく　した$"

BillHouse_Text_SisterRefusedNumber:
	.string "あにが　パソコンで　ポケモンを\nあずける　システムを　つくったの\pマサキの　ばんごうを\nおしえようと　したのに‥$"

BillHouse_Text_SisterPhoneFull:
	.string "もう　ばんごうを\nとうろく　できないわね$"

BillHouse_Text_SisterStorageSystem:
	.string "おにいちゃんの　マサキが　パソコンで\nポケモンを　あずける　システムを\lつくったの$"
