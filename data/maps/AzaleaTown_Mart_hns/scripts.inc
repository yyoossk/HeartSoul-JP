AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "スーパーボール　かえる？\nおれは　モンスターボールしか\lかえないんだ\pジムバッジを　もらうと\nかえる　どうぐが　ふえるらしい！\pガンテツさんに　とくべつな\nボールを　つくって　ほしいなあ$"

AzaleaMart_Text_BugCatcher:
	.string "スーパーボールは　モンスターボールより\nポケモンが　つかまえやすいんだ\pでも　ガンテツさんの　ボールの\nほうが　いい　ときも　あるよ$"

