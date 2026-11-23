Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "ラジオで　ポケモンの　じょうほうを\nしいれてるんだ　かてるはず$"

Route35_Text_CamperIvanBeaten:
	.string "まいった！$"

Route35_Text_CamperIvanAfter:
	.string "ラジオの　おんがくで　やせいの\nポケモンの　きぶんが　かわるんだ$"

Route35_Text_CamperElliotSeen:
	.string "かのじょに　いい　ところを\nみせるんだ！$"

Route35_Text_CamperElliotBeaten:
	.string "まけて　ほしかったのに‥$"

Route35_Text_CamperElliotAfter:
	.string "かのじょの　まえで\nはじを　かいた‥$"

Route35_Text_PicnickerBrookeSeen:
	.string "かれし　よわいから\nたよれないの$"

Route35_Text_PicnickerBrookeBeaten:
	.string "まあ！　あなた　つよいのね！$"

Route35_Text_PicnickerBrookeAfter:
	.string "かれしより　ポケモンの　ほうが\nずっと　たよりに　なるわ$"

Route35_Text_PicnickerKimSeen:
	.string "ジムに　いくの？\nわたしも！$"

Route35_Text_PicnickerKimBeaten:
	.string "ああ　かてなかった‥$"

Route35_Text_PicnickerKimAfter:
	.string "ジムバッジって　きれいなの\nあつめてるのよ$"

Route35_Text_BirdKeeperBryanSeen:
	.string "きみは　どんな　ボールを\nつかってる？$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "ひえっ！　はやさが　たりない！$"

Route35_Text_BirdKeeperBryanAfter:
	.string "すぐ　にげる　ポケモンも　いる\pガンテツさんの　スピードボールで\nつかまえて　みな\pナナシのみを　みつけたら\nいつも　ガンテツさんに\lもっていくんだ\pとくべつな　ボールに\nしてくれるんだよ$"

Route35_Text_JugglerIrwinSeen:
	.string "わたしの　みごとな\nボールさばきを　みよ！$"

Route35_Text_JugglerIrwinBeaten:
	.string "ふう！　しびれたよ！$"

Route35_Text_JugglerIrwinAfter:
	.string "じまんの　ポケモンで　きみを\nおどろかせる　つもり　だったのに\pきみの　うでまえに\nしびれて　しまったよ！$"

Route35_Text_BugCatcherArnieSeen:
	.string "むしポケモンが　でるなら\nどこへでも　いくよ$"

Route35_Text_BugCatcherArnieBeaten:
	.string "あれ？　まける　はず\nなかったのに‥$"

Route35_Text_BugCatcherArnieAfter:
	.string "しぜんこうえんの　むしとりたいかいで\nコンパンで　ゆうしょう　したんだ$"

Route35_Text_IrwinRegister:
	.string "じまんの　ポケモンで　きみを\nおどろかせる　つもり　だったのに\pきみの　うでまえに\nしびれて　しまったよ！$"

Route35_Text_ArnieRegister:
	.string "しぜんこうえんの　むしとりたいかいで\nコンパンで　ゆうしょう　したんだ$"

Route35_Text_ArnieRematchIntro:
	.string "むしポケモンが　でるなら\nどこへでも　いくよ$"

Route35_Text_ArnieRematchDefeat:
	.string "あれ？　まける　はず\nなかったのに‥$"

Route35_Text_ArniePostRematch:
	.string "しぜんこうえんの　むしとりたいかいで\nコンパンで　ゆうしょう　したんだ$"

Route35_Text_BugCatcherArnieYanma:
	.string "わあ‥　ヤンヤンマが\nいっぱい！\pおどろいて　うごけないよ$"

Route35_Text_FirebreatherWaltSeen:
	.string "ひふきの　れんしゅう　ちゅうだ$"

Route35_Text_FirebreatherWaltBeaten:
	.string "あちっ！　はなの　さきを\nこがしちまった！$"

Route35_Text_FirebreatherWaltAfter:
	.string "ラジオの　ポケモンマーチは\nやせいの　ポケモンを　よびよせる$"

Route35_Text_OfficerDirkSeen:
	.string "よるには　きけんが\nひそんで　いる！$"

Route35_Text_OfficerDirkBeaten:
	.string "おっと！$"

Route35_Text_OfficerDirkAfter:
	.string "よるには　よるの\nたのしさが　あるが\pほどほどに　するんだぞ$"

Route35_Text_OfficerDirkTough:
	.string "きみの　ポケモンは\nつよそうだな\pどこへ　いっても\nあんぜん　だろう$"

Route35_Text_Sign:
	.string "35ばんどうろ$"

Route35_Text_Sign2:
	.string "しぜんこうえん　ゲート$"
