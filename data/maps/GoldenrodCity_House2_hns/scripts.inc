GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
	.string "しょうぶ　ちゅうに　ポケモンが\nわざを　だせなく　なった\lことが　あるんだ\pわざの　パワーポイント\nつまり　PPが\lなくなって　いたんだ$"

GoldenrodPPSpeechHouse_Text_Lass:
	.string "げんきな　ポケモンでも　わざが\nだせない　ことが　あるの\pそんな　ときは　ポケモンセンターで\nかいふく　するか　どうぐを\lつかってね$"
