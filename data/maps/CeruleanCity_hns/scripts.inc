CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "ここは　ハナダのどうくつ\pなかには　おそろしく　つよい\nポケモンが　すんでいる\pとくべつな　トレーナーしか\nなかには　はいれないんだ\pまず　カントーの　ポケモンリーグで\nチャンピオンに　なれるくらい\lつよくなくては　いけない\pそれに　なにか　おおきな\nことを　なしとげて\lいなければ　ならないんだ$"

CeruleanCity_Text_CooltrainerM1:
	.string "カントーの　はつでんしょ？\pここから　ひがしへ　いく\n9ばんどうろの　はずれだよ\pなにか　じこが　あったらしい$"

CeruleanCity_Text_CooltrainerM2:
	.string "ポケモンを　ぜんしゅるい\nあつめてるの？\pたいへんそう　だけど\nたのしそう　だね$"

CeruleanCity_Text_SuperNerd:
	.string "きたの　みさきは\nデートに　ぴったり\pおんなのこに　にんきさ！$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "ヤドラン『ヤーン？$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "わたしと　ヤドランは\nさいこうの　コンビよ！$"

CeruleanCity_Text_CooltrainerF2:
	.string "ヤドラン　ねんりきを\nみせて！$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "ハナダジムの　カスミの\nだいファン　なんだ$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "あやしい　やつが　ハナダの\nみさきの　ほうへ　いったのを\lみたよ$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "まちの　きたの　どうくつには\nおそろしく　つよい\lポケモンが　いるんだ$"

CeruleanCity_Text_Youngster2:
	.string "あれ？\pダウジングマシンが\nはんのう　してる‥$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "ハナダシティ\pハナダ　みずいろ\nしんぴの　いろ$"

CeruleanCity_Text_GymSign:
	.string "ハナダシティ\nポケモンジム\nジムリーダー　カスミ\pおてんばな　にんぎょ$"

CeruleanCity_Text_BikeShopSign:
	.string "はりがみが　ある‥\pじてんしゃやは　ジョウトの\nコガネシティに　ひっこしました‥$"

CeruleanCity_Text_PoliceSign:
	.string "はりがみが　ある‥\pどろぼうを　なくして\nあかるく　たのしい\lまちに　しよう！\pハナダけいさつ$"

CeruleanCity_Text_CapeSign:
	.string "この　さき\nハナダの　みさき$"

CeruleanCity_Text_LockedDoor:
	.string "かぎが　かかっている‥$"

