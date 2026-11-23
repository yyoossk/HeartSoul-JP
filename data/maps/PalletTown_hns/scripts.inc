PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "わたしも　ポケモンを\nそだてているの\pわたしの　ボディガード\nなのよ$"

PalletTown_Text_Fisher:
	.string "かがくの　ちからって　すげー！\pいまじゃ　ポケモンを　メールみたいに\nやりとり　できるんだからな$"

PalletTown_Text_Sign:
	.string "マサラタウン\pマサラは　まっしろ\nはじまりの　いろ$"

PalletTown_Text_RedsHouseSign:
	.string "レッドの　いえ$"

PalletTown_Text_OaksLabSign:
	.string "オーキド\nポケモンけんきゅうじょ$"

PalletTown_Text_BluesHouseSign:
	.string "グリーンの　いえ$"
