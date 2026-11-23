EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "ドサッ！！$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}『なぜだ‥？　なんで\nおれが　ただの　まいこはん\lなんかに　まけるんだ‥？$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}『みてたのか\n{PLAYER}‥\pああ　そうだよ！\pまいこはん　5にんに　かつのが\nこんなに　むずかしいとはな‥\pこてんぱんに　やられたよ‥\p‥‥\pおまえも　おなじ　りゆうで\nきたんだろ？\pロケットだんを　たおした\nくらいで　いい　きに　なるなよ！\pこの　まいこはんたちは\nとんでもなく　つよい\pかてるもんなら　かってみろ\pだが　おれは　もどらない\nおまえが　かつ　ところなんか\lみたくないからな$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "イーブイ『ブイーッ！$"

EcruteakCity_Text_Vulpix:
	.string "ロコン『コーン！$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "ああ‥　どうしましょう‥\pむすめが　いなく　なったの\pまさか‥　やけたとうに\nいったんじゃ‥\pちかづいちゃ　だめって\nいったのに‥\pあそこでは　ひとが\nきえるって‥\pああ　どうしたら‥？$"

EcruteakCity_Text_Gramps1:
	.string "エンジュには　むかし\nひがしと　にしに　ひとつずつ\lとうが　あったんじゃ$"

EcruteakCity_Text_Gramps2:
	.string "おお　ぼうや　まいこはん\nみたいに　おどれるように\lなったかな？\pかぶれんじょうに　いけば\nかわった　じいさんが　いいものを\lくれる　らしいぞ$"

EcruteakCity_Text_Lass1:
	.string "これから　かぶれんじょうで\nおどりの　れんしゅう　なの\lいっしょに　どう？$"

EcruteakCity_Text_Lass2:
	.string "ここに　あった　とうはね‥\pおばあちゃんの　はなしだと\nもっと　ずっと　たかかったんだって\pいまは　ゆうれいが\nでるって　うわさよ$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "おおきな　ポケモンが　3びき\nばらばらの　ほうこうに\lかけていったの　あれは　なに？$"

EcruteakCity_Text_Fisher:
	.string "アサギの　とうだいの\nうわさを　きいたんだ\pとうだいの　あかりの　かわりを\nしている　ポケモンが　びょうきに\lなったらしい　たいへんそうだ$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "アサギの　とうだいの　ポケモンが\nげんきに　なったんだって\pこれで　また　よるも　ふねが\nあんぜんに　でられるな$"

EcruteakCity_Text_Youngster:
	.string "いかりのみずうみで　ポケモンが\nあばれてるって　きいたよ\lみてみたいなあ$"

EcruteakCity_Text_Gramps3:
	.string "とおい　むかし‥\pこの　とうは　かじで　もえた\nなもなき　ポケモンが　3びき\lとうの　なかで　いのちを　おとした\pにじいろの　ポケモンが　そらから\nまいおりて　3びきを\lよみがえらせた‥\pエンジュジムの　リーダーに\nつたわる　でんせつじゃ\pわし？\pわしも　むかしは\nトレーナー　じゃった　ほっほっほ！$"

EcruteakCity_Text_SageGym:
	.string "ジムリーダーの　マツバさんは\nいま　いません\lやけたとうに　いるかも　しれません$"

EcruteakCity_Text_Sign:
	.string "エンジュシティ\nむかしと　いまが\lであう　れきしの　まち$"

EcruteakCity_Text_TinTowerSign:
	.string "スズのとう\pでんせつの　ポケモンが\nまいおりると　いわれている$"

EcruteakCity_Text_OfficeSign:
	.string "スズのとう　せきしょ\pみとめられた　もの　いがい\nたちいり　きんし$"

EcruteakCity_Text_GymSign:
	.string "エンジュシティ　ポケモンジム\nジムリーダー　マツバ\pみらいを　みとおす\nしんぴの　みこ$"

EcruteakCity_Text_DanceTheaterSign:
	.string "エンジュ　かぶれんじょう$"

EcruteakCity_Text_BurnedTowerSign:
	.string "やけたとう\pなぞの　かじで　やけおちた\pあぶないので\nちかづかないで　ください$"
