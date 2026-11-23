CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "しってた？　すぐ　そこに\nサファリゾーンが　あるのよ\pすっごく　たのしいの！\nいろんな　ポケモンが\lいて　つかまえ　ほうだい！\pいかない　りゆうは\nないでしょ？\lすぐ　そこよ$"

CliffEdgeGate_Text_Expectations:
	.string "みんなが　たのしみに　して\nくれて　うれしいけど\pうけつけの　ひと\nちょっと　おおげさ　かも‥\pきたい　しすぎないでね！$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "なにもかも　ワクワク！\nたんけん　して　ポケモンを\lみつけよう！\lえんちょう　バオバの\lサファリゾーン　かいえん！$"

