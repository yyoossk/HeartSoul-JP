EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "とうの　つばさの　もとに\nある　ものに　スズの　すずは\lすんだ　ねを　ひびかせる$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "スズのとうは　ふさわしく\nない　ものは　はいれません\pもうしわけ　ないが\nおひきとり　ください$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "スズのとうは　エンジュジムの\nバッジを　もたない　かたは\lはいれません\pおお！\pエンジュジムの　バッジ！\nどうぞ　おとおり　ください$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "たいへんな　ことが\nおきました\pもうしわけ　ないが\nおひきとり　ください\p‥こころを　いやす　もの‥\pさんにんの　けんじゃの\nことばは　まことに\lむずかしい‥$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "たいへんな　ことが\nおきました\pもうしわけ　ないが\nおひきとり　ください\p‥‥‥‥‥‥‥‥‥‥$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "おお！\pその　とうめいなスズの　ね！\pな‥　なんと　うつくしい！\pこれほど　きれいな　おとは\nきいた　ことが　ない！\pスズの　ねいろは　もつ　ものの\nこころを　うつすと　いいます\pあなたなら‥\pスズのとうを　のぼれる\nかもしれません\pどうぞ　おすすみ　ください$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "どうぞ　おすすみ　ください$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "スズの　ねいろは　もつ　ものの\nこころを　うつすと　いいます\pあなたは‥\nまことに　ふさわしい$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "この　さきの　スズのとうは\nかみがかった　うつくしさの\l9そうの　とう\pみる　ものの　こころを\nいやして　くれます$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "スズのとうが　ゆれた！\nポケモンが　とうの\lうえに　もどったに\lちがいない！$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "ふたつの　とう‥\nふたつの　ポケモン‥\pだが　ひとつが　もえた　とき\n2ひきとも　とびさり\lにどと　もどらなかった$"
