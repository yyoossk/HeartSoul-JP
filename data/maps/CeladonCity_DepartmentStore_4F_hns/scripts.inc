CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "かのじょに　おくる\nサーフメールを　かいに　きたんだ\pえ　うりきれ？$"

CeladonDeptStore4F_Text_Youngster:
	.string "ラブリーメールが　かえるのは\nここ　だけ\pだった　けどね\nうりきれ　だってさ$"

CeladonDeptStore4F_Text_Directory:
	.string "おくりもので　きもちを\nつたえよう！\p4F　ギフトショップ$"
