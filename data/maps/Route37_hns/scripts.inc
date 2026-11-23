Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "アン『わたしと　アンナは\nいつも　いっしょ！$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "アンとアンナ『うーん‥\nちょっと　つよすぎ$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "アン『いもうとと　ポケモンの\nかんがえてる　ことが　わかるの$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "アンナ『わたしと　アンは\nいつも　いっしょ！$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "アンとアンナ『うーん‥\nちょっと　つよすぎ$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "アンナ『わたしたちは　ポケモンと\nきもちが　つながってるの$"

Route37_Text_PsychicGreg_Seen:
	.string "ねむっている　ポケモンは\nなにも　できない\pその　こわさを\nおしえて　やろう！$"

Route37_Text_PsychicGreg_Beaten:
	.string "まけた　かなしいな‥$"

Route37_Text_PsychicGreg_After:
	.string "ポケモンを　ねむらせたり\nまひさせたりするのは\lいい　せんぽうだ$"

Route37_Text_Sunny_Meet:
	.string "ニチ『こんにちは！\pぼく　ようび　きょうだいの\nニチだよ！\pぼくの　すきな　ようびを\nあてたら　ごほうびを　あげる$"

Route37_Text_Sunny_GiveGift1:
	.string "きみに　あったら　これを\nわたすように　いわれてたんだ！$"

Route37_Text_Sunny_GiveGift2:
	.string "きみに　あったら　これを\nわたすように　いわれてたんだ！$"

Route37_Text_Sunny_GaveGift:
	.string "ニチ『それね‥\pえっと‥\p‥なんだっけ‥\p‥\pあ！　おもいだした！\pでんきの　わざを　おぼえてる\nポケモンに　もたせるんだ\pツキコねえちゃんが　でんきの\nわざが　つよくなるって　いってた！$"

Route37_Text_Sunny_Sunday:
	.string "ニチ『ぼくの　きょうだいは\nツキコ　カヨ　スイ　モク\lキンコ　ドヨウ　だよ\pみんな　ぼくより\nとしうえ　なんだ！$"

Route37_Text_Sunny_NotSunday:
	.string "ニチ『きょうって　にちようび\nじゃないの？　えっと‥\lわすれちゃった！$"

Route37_Text_Sign:
	.string "37ばんどうろ\nこの　さき　エンジュシティ$"
