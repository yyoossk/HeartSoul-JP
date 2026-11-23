CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "どうくつで　わかれみちが\nあったら　たいてい　かたほうは\lせいかいで　もう　かたほうは\lいきどまり\pでも　ひとは　つい\nりょうほう　ためしたく\lなるんだよな$"
