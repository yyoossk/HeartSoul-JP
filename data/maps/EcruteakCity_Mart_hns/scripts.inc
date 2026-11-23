EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "ぼくの　イーブイは\nエーフィに　しんかした\pでも　ともだちの　イーブイは\nブラッキーに　なったんだ\pなんでだろう？　おなじ　ように\nそだてて　いたのに‥$"

EcruteakMart_Text_Granny:
	.string "げんきのかけらを　つかうと\nひんしの　ポケモンが\lすぐ　げんきに　なるよ$"
