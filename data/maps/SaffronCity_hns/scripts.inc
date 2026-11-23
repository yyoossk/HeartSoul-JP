SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "バオバ$"

SaffronCity_Text_Baoba:
	.string "バオバえんちょう『{PLAYER}くん！\pえんちょうの　バオバだ\pサファリゾーンが　また\nひろく　なったので　しらせたくて\lね！\pついに　わしの　サファリゾーンが\nかんせい　したんだ！\pばしょは　おぼえてるね？\pタンバシティの　すぐ　にしだ！\nまってるよ！$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "ロコン　だいすき！$"

SaffronCity_Text_Lass1:
	.string "ひとの　まねが　とくいな\nおんなのこが　ここに　すんでるの\pはなしてる　あいての　まねまで\nするの　こんがらがっちゃう$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "ものまねむすめが　さびしそうに\nしてたの\pだいじな　ピッピにんぎょうを\nなくしたんだって$"

SaffronCity_Text_PokefanM:
	.string "ジョウトから　きたのかい？\pリニアが　うごいて　いれば\nすぐ　かえれるんだけどね$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "ジョウトから　きたのかい？\pリニアに　のれば\nすぐ　かえれるよ$"

SaffronCity_Text_CooltrainerM:
	.string "トレーナーと　たたかう　き　まんまんで\nジムに　いったら‥\pとなりの　つかわれていない\nジムに　はいっちゃった\pいやあ　はずかしかったよ$"

SaffronCity_Text_CooltrainerF:
	.string "ここは　ポケモングッズで\nゆうめいな　シルフカンパニー\pそれで　むかし　ロケットだんに\nねらわれた　ことも　あるの$"

SaffronCity_Text_Fisher:
	.string "もぐ‥　もぐ‥\pはつでんしょで　おおごとに\nなってる　らしいぞ\pもぐ‥　もぐ‥$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "もぐ‥　もぐ‥\pはつでんしょで　おおごとが\nあったらしいぞ\pもぐ‥　もぐ‥　ふう　おなか　いっぱい！$"

SaffronCity_Text_Youngster1:
	.string "はじめて　ろじうらに　はいる\nときって　なんだか　ドキドキする$"

SaffronCity_Text_Youngster2:
	.string "トキワには　コンテストホールって\nところが　あって　あちこちから\lトレーナーが　あつまるんだ$"

SaffronCity_Text_Lass2:
	.string "この　まちが　ラジオばんぐみで\nとりあげられたの\pまちを　ほめられると　うれしいけど\nちょっと　はずかしいわね$"

SaffronCity_Text_Sign:
	.string "ヤマブキシティ\pヤマブキは　こがねいろ\nかがやく　しょうぎょうの　まち$"

SaffronCity_Text_GymSign:
	.string "ヤマブキシティ\nポケモンジム\lジムリーダー　ナツメ\pエスパー　しょうじょ！$"

SaffronCity_Text_FightingDojoSign:
	.string "だれでも　かんげい！\nかくとう　どうじょう$"

SaffronCity_Text_SilphCoSign:
	.string "シルフカンパニー\nほんしゃ　ビル$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "エスパーおやじの\nいえ$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ヤマブキシティ\nリニア　えき$"
