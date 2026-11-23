CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "エリカさんは　くさポケモンの\nたつじん\pゆだん　すると\nいたい　めに　あうわよ$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "ロケットだんの　アジトは\nゲームコーナーの　ちかに\lあるんだ\pおっと　それは　3ねんまえの\nはなし　だった$"

Celadon_Text_Eusine1:
	.string "ミナキ『やあ！\pふるさとに　かえって\nきたんだ\pずいぶん　ひさしぶりだよ$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}くん　きいたかい？\pスズのとうに　にじいろの\nポケモンが　あらわれたと\lいう　うわさが　あるんだ\pポケモンも　かいふく　したし\nいまから　エンジュへ　いくよ\pまたね　{PLAYER}くん！$"

Celadon_Text_NoBeasts:
	.string "そうそう　{PLAYER}くん\pでんせつの　ポケモン　ライコウと\nエンテイは　つかまえたかい？\p‥‥‥‥‥‥\pそうか‥\pもし　1ぴきでも　つかまえたら\nおしえて　ほしいな\pたのんだよ　{PLAYER}くん！$"
