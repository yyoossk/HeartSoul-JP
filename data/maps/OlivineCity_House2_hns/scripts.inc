OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "タンバへ　いく　とちゅうに\nむじんとうが　4つ　あるんだ\pわるい　こは　おしおきで\nそこへ　つれて　いかれるぞ！$"

OlivineCity_Text_PunishmentBoy:
	.string "わるい　ことを　すると\nいつも　にいちゃんが\lおどかすんだ$"
