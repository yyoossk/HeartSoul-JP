EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "わい　マサキや\nあんたは　だれや？\pふーん　{PLAYER}か\nええ　ときに　きたな$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "いま　ポケモンあずかり\nシステムの　ちょうせいが\lおわった　とこや\pポケモンを　あずける\nパソコン　あるやろ？\pあれ　わいが\nつくったんやで！\pこれで　ジョウトと　カントーの\nポケモンセンター　ぜんぶで\lわいの　システムが　うごくで\pコガネに　かえって\nおやに　かお　みせな\lあかん　いつでも\lあそびに　きてや！\pほな　さいなら！$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "まいこはんの　おどりは\nすばらしい\pポケモンの\nあつかいかたも　な$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "もっと　たくさんの　ひとと\nたたかいたい　だろ？\pトレーナーが　あつまる\nばしょが　あるらしい\pどこかって？\pアサギシティの\nすこし　さきさ$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ジムリーダーの　マツバさん\nすっごく　かっこいいの\pポケモンも　すごく\nつよいのよ$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "いかりのみずうみ‥\pギャラドスの　たいりょう\nはっせい‥\pなにか　いんぼうの\nにおいが　する！$"

