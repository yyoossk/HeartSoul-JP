Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "おれたちは　カントー\nポケモンれんごう　だ！\pタイヤで　ひいちまうぞ！$"

Route8_Text_BikerDwayneBeaten:
	.string "す‥　すみません！$"

Route8_Text_BikerDwayneAfter:
	.string "カントー　ポケモンれんごうは\nふめつだ！$"

Route8_Text_BikerHarrisSeen:
	.string "おまわりが　おれたちの\nちかつうろを　ふさぎやがった！\pまったく　むかつくぜ！$"

Route8_Text_BikerHarrisBeaten:
	.string "ゆ‥　ゆるして　くれ！$"

Route8_Text_BikerHarrisAfter:
	.string "ジョウトの　ガキに\nやられるなんて‥$"

Route8_Text_BikerZekeSeen:
	.string "おれたちは　カントー\nポケモンれんごう！\nイエーイ！$"

Route8_Text_BikerZekeBeaten:
	.string "ひえっ！　ごめん！$"

Route8_Text_BikerZekeAfter:
	.string "これからは　ひとに　めいわくを\nかけないように　するよ‥$"

Route8_Text_SupernerdSamSeen:
	.string "リニアって　どうやって\nうごいてるの？$"

Route8_Text_SupernerdSamBeaten:
	.string "リニアが　みたい　だけ\nなのに‥$"

Route8_Text_SupernerdSamAfter:
	.string "じしゃくの　ちからって\nすごいよね！$"

Route8_Text_SupernerdTomSeen:
	.string "ふむ‥　ジムバッジを\nたくさん　もってるな$"

Route8_Text_SupernerdTomBeaten:
	.string "おもった　とおり‥　つよい！$"

Route8_Text_SupernerdTomAfter:
	.string "ジムバッジは　しょうぶで\nゆうりに　なるんだ$"

Route8_Text_LockedDoor:
	.string "かぎが　かかっている‥$"

Route8_Text_UndergroundPathSign:
	.string "ちらしが　やぶれている\pよめない‥$"
