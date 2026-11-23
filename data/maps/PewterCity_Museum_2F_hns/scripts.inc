PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "たんじょうのしまに　いんせきが\nおちたと　いわれている\pこの　はくぶつかんに\nかざりたいんだけど‥\pふしぎな　エネルギーを　だして\nもちだせない　らしいんだ‥$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
	.string "ピカチュウ　ほしい！\nかわいいんだもん！\pパパに　つかまえてって\nたのんだの！$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
	.string "うん　ピカチュウ　すぐ\nつかまえて　くるよ！$"

PewterCity_Museum_2F_Text_SpaceShuttle::
	.string "スペースシャトル$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
	.string "おつきみやまに　おちた　いんせき\nつきのいしと　かんがえられている$"
