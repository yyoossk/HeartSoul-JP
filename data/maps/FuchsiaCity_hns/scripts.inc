FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "バオバ$"

FuchsiaCity_Text_Baoba:
	.string "バオバえんちょう『{PLAYER}くん！\pえんちょうの　バオバだ\pたいへんな　ことに　なった！\nセキチクシティの　むかしの　わしの\lサファリゾーンが　かいとられて\lさいかい　したんだ！\pしかも　めずらしい　ポケモンが\nいる　らしい！\pわしの　しょうばいが\nあがったりだ！\p{PLAYER}くん　あたらしい\nサファリゾーンに　いって\lポケモンを　つかまえて　わしに\lみせて　くれ　その　めずらしい\lポケモンの　ことを　しりたい\pたのむ　{PLAYER}くん！\nわしの　しょうばいが　かかって\lいるんだ！$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "してんのうの　ひとりは\nむかし　セキチクジムの\lリーダー　だったんだ$"

FuchsiaCity_Text_PokefanM:
	.string "キョウが　してんのうに　なってから\nむすめが　ジムリーダーを\lついだんだ$"

FuchsiaCity_Text_Teacher:
	.string "サファリゾーンの　けいえいしゃが\nかわったの\pあたらしい　ポケモンが\nいっぱい　いるのよ！$"

FuchsiaCity_Text_Sign:
	.string "セキチクシティ\pセキチク　ももいろ\nはなやかな　いろ$"

FuchsiaCity_Text_GymSign:
	.string "セキチクシティ　ポケモンジム\nジムリーダー　アンズ\pどくの　くのいち$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "はりがみが　ある‥\pサファリゾーン　じむしょは\nしばらく　おやすみ　します$"

FuchsiaCity_Text_SafariZone:
	.string "サファリゾーン\nけいえい　デボン\lコーポレーション$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "えんちょうが　かいがい　りょこう\nちゅうの　ため\pサファリゾーンは　おやすみです$"

FuchsiaCity_Text_NoLitteringSign:
	.string "ごみを　すてないで\pごみは　もちかえりましょう$"

