CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "みずポケモン　なら\nメノクラゲが　だんトツで\lいちばんだ！$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "みずポケモンが　ひつよう\nみたいだな\pほら　この　こを　やるよ\nたくさん　いるからな$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "ポケモンマニアに　あった？\pいつも　めずらしい　ポケモンを\nじまん　してるのよ$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "ここの　ジムの　トレーナーは\nマッチョな　らんぼうもの\pうろうろ　してたら\nおれが　ねらわれそうだ\pアドバイスだ　ジムリーダーは\nかくとうタイプを　つかう\pだから　エスパーポケモンで\nこまらせて　やれ\pちからを　だされる　まえに\nたおして　しまえ\pそれと　ジムの　まんなかの\nいわ　だが\pうまく　うごかさないと\nジムリーダーの　ところへ\lいけないぞ\pつまったら　いちど\nそとへ　でろ$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}！　かったな！\nみた　しゅんかんに\lわかったよ！$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "そだてた　ポケモンを\nみせびらかすのが　すきなんだ\pきみも　そうだろ？\pたくさん　しょうぶして\nぼくの　ポケモンを\lみせびらかすぞ！$"
