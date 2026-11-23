Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "しまの　くらしは\nとても　のどか！\pカントーの　まごたちにも\nふねで　すぐ　あえるしね！$"

Melemele_House3_Man_Text_0:
	.string "かんこうきゃく　ばかりだ！\pふどうさんやは　しずかな\nところと　いってたが‥\lアローラまで　いくより\lやすいから　くるんだな$"
