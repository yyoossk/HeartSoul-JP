Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "わすれものは　ない？$"

Route15_Text_TeacherColetteBeaten:
	.string "きゃあっ！$"

Route15_Text_TeacherColetteAfterBattle:
	.string "せんせいに　なるまえは\nわたしも　わすれもの\lばかり　してたのよ$"

Route15_Text_TeacherHillarySeen:
	.string "はれた　ひは　こどもたちも\nきょうしつで　べんきょう　するより\lこうていで　あそびたいわよね$"

Route15_Text_TeacherHillaryBeaten:
	.string "まけたく　なかったのに‥$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "べんきょうも　だいじだけど\nうんどうも　おなじくらい\lだいじなのよ$"

Route15_Text_HillaryRegister:
	.string "いい　べんきょうに　なったわ！\nばんごうを　おしえて　くれる？$"

Route15_Text_HillaryRematchIntro:
	.string "こんどは　わたしが　おしえて\nあげるわ！$"

Route15_Text_HillaryRematchDefeat:
	.string "いちから　やりなおしね‥$"

Route15_Text_HillaryPostRematch:
	.string "ポケモンを　おしえるのは\nこどもを　おしえるのと　おなじ\lがまんが　だいじ！$"

Route15_Text_SchoolboyKippSeen:
	.string "ちょっと　まって\nママに　でんわ　しなきゃ$"

Route15_Text_SchoolboyKippBeaten:
	.string "ママ　ごめん！　まけちゃった！$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "ママが　すごく　しんぱいするから\nいつも　でんわ　しなきゃ\lいけないんだ$"

Route15_Text_SchoolboyTommySeen:
	.string "しょうぶだ！　まけないぞ！$"

Route15_Text_SchoolboyTommyBeaten:
	.string "しゅくだい　わすれてた！$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "グッバイ！　えいごの\nじゅぎょうで　ならったんだ$"

Route15_Text_SchoolboyJohnnySeen:
	.string "しゃかいかの　けんがくで\nシオンの　ラジオとうに\lいく　ところなんだ$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "めちゃくちゃ　つよいな！$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "あるき　つかれた\nひとやすみ　しなきゃ$"

Route15_Text_SchoolboyBillySeen:
	.string "すきな　じゅぎょうは\nたいいく！$"

Route15_Text_SchoolboyBillyBeaten:
	.string "ええ！　なんで　まけたんだ？$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "ポケモンが　がっこうの　かもく\nだったら　ぼくが　いちばんなのに！$"

Route15_Text_BillyRegister:
	.string "もっと　じゅぎょうを\nきいて　おけば　よかった\lばんごう　もらえる？$"

Route15_Text_BillyRematchIntro:
	.string "いっしょうけんめい　べんきょう\nしたんだ！　みせて　あげる！$"

Route15_Text_BillyRematchDefeat:
	.string "もっと　べんきょう\nしなきゃ‥$"

Route15_Text_BillyPostRematch:
	.string "べんきょう　だけじゃ　だめだ\nじっせんも　ひつようだね！$"

Route15_Text_Sign:
	.string "15ばんどうろ\pセキチクシティ　ー　シオンタウン$"

