NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "こんにちは　{PLAYER}くん！\nうちの　ひと　いつも　いそがしくて\lしんぱい　なのよ\pポケモンの　けんきゅうに\nむちゅうに　なると\lごはんも　わすれちゃうの$"

NewBarkTown_House2_Text_ElmsSon:
	.string "おおきく　なったら\nパパの　てつだいを　するんだ！\pりっぱな　ポケモンはかせに\nなるんだ！$"
