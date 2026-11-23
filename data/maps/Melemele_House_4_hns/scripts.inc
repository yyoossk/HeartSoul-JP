Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "アローラしょとうで\nバカンス　ちゅう！\pアローラちほう　そっくり\nなのに　カントーから\lちかい！\pりょひが　すごく\nうかったよ！$"

Melemele_House4_Woman_Text_0:
	.string "かれが　アローラへ\nいこうって　いったの‥\pてっきり　アローラちほうだと\nおもってた　カントーの\lちいさな　しまじゃ　なくて$"
