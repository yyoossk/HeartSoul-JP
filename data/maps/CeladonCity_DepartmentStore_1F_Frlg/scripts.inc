CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "いらっしゃいませ！\n"
	.string "タマムシ　デパートに　ようこそ！\p"
	.string "かく　フロアの　あんないは\n"
	.string "みぎの　ボードを　ごらん　ください$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "１かい…サービス・カウンター\p"
	.string "２かい…トレーナーズ・マーケット\p"
	.string "３かい…テレビ　ゲーム　ショップ\p"
	.string "４かい…ワイズマン・ギフト\p"
	.string "５かい…ドラッグ　ストア\p"
	.string "おくじょう…じどう　はんばいき$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "１かい…サービス・カウンター$"

