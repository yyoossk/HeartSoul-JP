Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "よーし！　やまの　ポケモンの\nちからを　みせて　やる！$"

Route46_Text_HikerBaileyBeaten:
	.string "まいった！　きみの\nちからは　よく　わかった！$"

Route46_Text_HikerBaileyAfterBattle:
	.string "おわった　ことだ\nきにしない　やまおとこは\lそういう　もんさ$"

Route46_Text_CamperTedSeen:
	.string "ぼくも　ポケモンを\nそだててるんだ！\pしょうぶ　してくれる？$"

Route46_Text_CamperTedBeaten:
	.string "え‥？$"

Route46_Text_CamperTedAfterBattle:
	.string "せいいっぱい　やったけど\nとどかなかった\pいいわけ　しない\nぼくの　まけだ$"

Route46_Text_PicnickerErinSeen:
	.string "わたしも　ポケモンを\nそだててるの！\pしょうぶ　してくれる？$"

Route46_Text_PicnickerErinBeaten:
	.string "もう！　くやしい！$"

Route46_Text_PicnickerErinAfterBattle:
	.string "いろんな　ジムに　いったけど\nコガネの　ジムが　いちばん　すき\pきれいな　はなで\nいっぱい　なの！$"

Route46_Text_ErinRegister:
	.string "いろんな　ジムに　いったけど\nコガネの　ジムが　いちばん　すき\pきれいな　はなで\nいっぱい　なの！$"

Route46_Text_ErinRematchIntro:
	.string "わたしも　ポケモンを\nそだててるの！\pしょうぶ　してくれる？$"

Route46_Text_ErinRematchDefeat:
	.string "もう！　くやしい！$"

Route46_Text_ErinPostRematch:
	.string "いろんな　ジムに　いったけど\nコガネの　ジムが　いちばん　すき\pきれいな　はなで\nいっぱい　なの！$"

Route46_Text_PicnickerErin2Beaten:
	.string "もう‥　まけて　ばっかり！\pもっと　がんばらなきゃ！\nとにかく　なんども　しょうぶ\lしてくれて　ありがとう\pはい　この　まえの\nプレゼントよ$"

Route46_Text_Sign:
	.string "46ばんどうろ\nこの　さき　やまみち$"
