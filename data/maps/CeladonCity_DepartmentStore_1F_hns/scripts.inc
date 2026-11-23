CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
	.string "こんにちは！\nタマムシデパートへ　ようこそ！\pあんないばんは　かべに\nございます$"

CeladonDeptStore_Text_1FGentleman:
	.string "この　デパートは　コガネシティの\nデパートと　おなじ\lチェーンなんだ\pどちらも　おなじ　ときに\nかいそう　されたんだよ$"

CeladonDeptStore_Text_1FTeacher:
	.string "ここに　くるのは\nはじめて\pひろくて‥\pまいごに　なりそう$"

CeladonDeptStore_Text_1FDirectory:
	.string "1F　サービスカウンター\p2F　トレーナーズマーケット\p3F　わざマシンショップ\p4F　ギフトショップ\p5F　くすりやさん\p6F　おくじょう　ひろば$"
