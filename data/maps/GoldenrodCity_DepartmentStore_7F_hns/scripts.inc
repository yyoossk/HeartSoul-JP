GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
	.string "ふう　つかれた\pときどき　おくじょうで\nかいものの　ひとやすみ\lするのよ$"

GoldenrodDeptStore_Text_RoofFisher:
	.string "え？　おとなが　むちゅうに\nなっちゃ　だめかい？\pにんぎょうを　ぜんぶ\nあつめる　ために\lまいにち　くるぞ！$"

GoldenrodDeptStore_Text_RoofTwin:
	.string "ここでは　ときどき\nバーゲンを　やってるの$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
	.string "うわあ！$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
	.string "じゃま　しないで\nくれる？$"

GoldenrodDeptStore_Text_RoofPokefanM:
	.string "ほしい　ものが　あるんだが\nおかねが　たりなくて‥\pあつめた　きのみでも\nうろうかな‥$"

GoldenrodDeptStore_Text_RoofTeacher:
	.string "まあ　なんでも　やすい！\pかいすぎて　バッグが\nぱんぱんよ！$"

GoldenrodDeptStore_Text_RoofBugCatcher:
	.string "だいじな　ときに　かぎって\nポケモンが　まひや　どくに\lなるんだ‥\pだから　なんでもなおしを\nかいに　きたんだ\pまだ　のこってるかな？$"
