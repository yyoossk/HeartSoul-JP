PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "ずかんの　ほうは\nどうかな？$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "オーキド『おお　{PLAYER}！\nはるばる　カントーまで\lよく　きたな\pこちらの　トレーナーは\nどうじゃ？　てごわいじゃろう？$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "ちかくに　きたら\nまた　よって　おくれ$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "オーキド『なんと！　すばらしい！\pカントーの　ジムバッジを\nあつめたのか　みごとじゃ！\pわしの　みこんだ　とおりじゃった\pよし　{PLAYER}　シロガネやまへ\nいけるように　てはいして\lおこう\pシロガネやまは　やせいの\nポケモンが　たくさん　すむ\lおおきな　やまじゃ\pふつうの　トレーナーには\nきけん　なので　たちいり\lきんしじゃが　きみは\lとくべつじゃ\pセキエイこうげんへ　いきなさい\nそこから　シロガネやまへ\lいけるぞ$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "そうそう　セキエイこうげんと\nいえば　バッジを　16こ\lあつめた　きみの\lちょうせんを　カントーリーグが\lまた　うけつけて　くれるぞ\pじゃが　ワタルと　してんのうは\nこんどは　てかげん\lせんぞ\pがんばるのじゃぞ\n{PLAYER}！$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "オーキド『む？　カントーの\nジムバッジを　あつめて\lおらんのか？\pカントーの　ジムリーダーも\nジョウトに　まけず　つよいぞ\pちょうせん　してみる\nことを　すすめるぞ$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "オーキド『おお　カントーの\nジムバッジを　あつめて\lおるのか\pたいへん　じゃろうが\nきっと　いい　けいけんに\lなるぞ\pぜんぶ　あつめたら\nわしに　あいに　きなさい\pおくりものを　よういして\nおこう\pがんばれよ　{PLAYER}！$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "はかせの　ポケモンこうざは\nカントーでは　ほうそう\lされて　ないんだ\pざんねん‥　ききたいのに$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "きみが　ずかんを\nうめて　くれるので\lはかせの　けんきゅうも\lじゅんちょうだよ$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "ないしょ　だけど\nオーキドはかせの　ポケモンこうざは\lなまほうそう　じゃ　ないんだ$"

PalletTown_Lab_Text_OaksLabPC:
	.string "パソコンに　メールが\nとどいている\p‥\pオーキドはかせ　けんきゅうの\nほうは　いかが　ですか？\pわたしは　あいかわらず\nがんばって　います\p{PLAYER}くんが　ひょうばんに\nなって　いると　ききました\pうれしい　かぎりです\pワカバタウンの　ウツギより$"
