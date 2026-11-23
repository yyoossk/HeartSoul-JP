SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
	.string "ひとりかい？\nじゃあ　しょうぶだ！$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
	.string "てに　おえない！$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
	.string "カントーに　のぼりがいの\nある　やまは　あるかな？$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
	.string "リリーって　しってる？\nカントーの　にんきDJさ$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
	.string "ぎゃーーっ！$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
	.string "リリーも　いいけど\nクルミちゃんが　いちばん！\pジョウトの　ラジオばんぐみを\nききたいな！$"
