NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "みて！　わたしの\nバッグ　みて！\pずかんから　すきな　ポケモンを\nいんさつ　して　はったの$"

NationalPark_Normal_Text_PokefanF:
	.string "むすめから　もらった\nメールなの　げんきが\lでるのよ$"

NationalPark_Normal_Text_Teacher1:
	.string "はい　ちゅうもく！\p‥あら　いつも　せんせいの\nくせが　でちゃう\pあなた　ポケモン\nトレーナーね\pがんばってる　あなたに\nこれを　あげるわ$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "その　せんせいのツメを\nポケモンに　もたせてね\pときどき　さきに\nこうげき　できるわ$"

NationalPark_Normal_Text_Youngster1:
	.string "ずかんから　いんさつ\nした　シールで\lあそんでるんだ$"

NationalPark_Normal_Text_Youngster2:
	.string "かったら　あいての\nずかんシールが　もらえるんだ$"

NationalPark_Normal_Text_Teacher2:
	.string "こうえんを　さんぽ　するけど\nくさむらには　はいらないの\pトレーナーが　いつも\nしょうぶを　したがるから‥\pたくさん　たたかって\nきたのね　ポケモンを\lかいふく　して　あげる$"

NationalPark_Normal_Text_Persian:
	.string "ペルシアン『フシャーッ！$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "ポケモンの　せかいは　ふかい\pまだ　わからない　ことが\nたくさん　ある\pでも　きみよりは\nしってるよ！$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "な　な　なんで？$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "まなぶ　ことは　たくさん\nある\pたとえば‥\pわざマシンは　92しゅるい\pこうかん　した　ポケモンは\nレベルが　あがりやすい$"

NationalPark_Normal_Text_JackRegister:
	.string "まなぶ　ことは　たくさん\nある\pたとえば‥\pわざマシンは　92しゅるい\pこうかん　した　ポケモンは\nレベルが　あがりやすい$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "まえに　たたかって　から\nたくさん　まなんだよ！\lいくぞ！$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "な　な　なんで？$"

NationalPark_Normal_Text_JackPostRematch:
	.string "まなぶ　ことは　たくさん\nある\pたとえば‥\pわざマシンは　92しゅるい\pこうかん　した　ポケモンは\nレベルが　あがりやすい$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "わたしの　ポケモンは\nほんとうに　かわいいの\pどれだけ　じまんの　こたちか\nおしえて　あげるわ$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "じまんでは　まけないけど‥$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "あなたの　ポケモンも\nとっても　かわいいわね$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "きらわれても　ポケモンを\nあいする\pそれが　ファンと\nいう　ものだ$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "お　おれの　ポケモンが！$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "しょうぶには　まけたが\nかわいさでは　おれの\lポケモンが　いちばんだ$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "なに？　どうして\nじっと　みてるの？\pあ　しょうぶ？$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "‥うーん‥$"

NationalPark_Normal_Text_LassKrise_After:
	.string "わたしが　かわいいから\nみてたと　おもったのに！$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "いこいの　ひろば\nしぜんこうえん$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "なんの　はりがみ　だろう？\pしょうぶは　くさむらの\nなかで　おねがいします\pしぜんこうえん　かんりじむしょ$"

NationalPark_Normal_Text_TrainerTips:
	.string "おトクな　けいじばん\pメールを　ひらいて　スタートを\nおすと　いんさつ　できる$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "あなたの　ポケモンも\nとっても　かわいいわね$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "あら　こんにちは！\nあなたに　あげる　ものが\lあるの\pかんしゃの　しるしに\nうけとってね！$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "わたしと　かわいい　ポケモンで\nおうえん　してるわ！$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "あら　バッグが\nいっぱいね\pあけてから\nまた　きてね$"
