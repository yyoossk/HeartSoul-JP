Gate_RuinsOfAlph_Route36_hns_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "アルフのいせき\pみて　さわれる\nかんこうち\pいしの　パズルに\nちょうせん　しよう！$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "いせきを　しらべてるの？\pみらいの　かがくしゃ　だね$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "いしの　パネルに\nえが　かいてある\pうごかして　みたけど\nなんだろう？$"
