CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "わしも　わかい　ころは\nすごうでの　トレーナー　じゃった！\pひとつ　アドバイスじゃ\nポケモンを　たくさん\lつかまえるのじゃ！\pそして　みんな　やさしく\nあつかって　やるんじゃぞ！$"
