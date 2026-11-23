GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
	.string "コガネ　デパートへ\nようこそ$"

GoldenrodDeptStore1_Text_Gentleman:
	.string "デパートは　しなぞろえが\nいいが\pゲームコーナーの　けいひんで\nしか　てに　はいらない\lものも　あるんだ$"

GoldenrodDeptStore1_Text_PokefanF:
	.string "きょうも　かいもの\nするわよー！$"

GoldenrodDeptStore1_Text_BugCatcher:
	.string "ママは　やすい　ものを\nさがすのが　うまいんだ\pいつも　やすく\nかって　くるよ$"

GoldenrodDeptStore1_Text_Directory:
	.string "1F　サービスカウンター\nげんざいち\p2F　トレーナーズマーケット\p3F　バトルコレクション\p4F　くすりの　はこ\p5F　わざマシンコーナー\p6F　いこいの　ひろば\pおくじょう　てんぼうだい$"
