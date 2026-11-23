GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
	.string "おれは　つよい　ポケモンが\nすきでね\pタウリンを　あたえて\nこうげきを　あげてるんだ$"

GoldenrodDeptStore_Text_4FBugCatcher:
	.string "ブロムヘキシンは　ポケモンの\nぼうぎょを　あげるよ$"

GoldenrodDeptStore_Text_4FGameboyKid:
	.string "つうしんケーブルで　こうかん\nしないと　しんか　しない\lポケモンが　いるって\lうわさが　あったんだ\pふん‥\pそんなの　デマさ\pうわさの　ポケモンは　しってる\nゴーリキー　ユンゲラー\lゴースト　それに　ゴローン\pでも　みんな　レベルアップで\nしんか　するんだよ$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
	.string "ポケモンを　パワーアップ！\p4F　くすりの　はこ$"
