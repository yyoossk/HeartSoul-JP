CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "じどうはんばいき　だ！\nメニューは　これ$"

CeladonDeptStore6F_Text_Clang:
	.string "ガコン！\p{STRING}が　でてきた$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "おっと　おかねが\nたりない‥$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "もう　もてない‥$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "あたりつきの\nじどうはんばいき‥\pいまどき　めずらしいな$"

CeladonDeptStore6F_Text_Youngster:
	.string "あーあ！　ここには\nゲームが　ない！\pあそびたかったのに‥$"

CeladonDeptStore6F_Text_Directory:
	.string "6F　おくじょう　ひろば\nじどうはんばいき$"
