CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "アサギから　きたの？\pとちゅうの　4つの　しまを\nおぼえてる？\pしまには　まぼろしの　うみの\nいきものが　かくれて\lいるんだって$"

CianwoodCity_Text_LugiaHouseLass:
	.string "ぎんいろのはねが　ないと\nあえないって　きいたわ\pきっと　その　いきものと\nおなじ　においが　するのね$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "しまの　まわりの　うずしおは\nその　うみの　いきものの\lしわざ　なんだって\pとおるには　とくべつな\nわざが　いるかもね$"
