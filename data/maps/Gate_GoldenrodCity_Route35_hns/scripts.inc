Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "ちょっと　きみ！\nたのみを　きいて　くれない？\pこの　メールを　もった　ポケモンを\nともだちに　とどけて　ほしいんだ\p31ばんどうろに　いるよ$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "いいの？　たすかる！\nありがとう！\pともだちは　いつも\nねている　ふとった　やつさ\pすぐ　わかるよ！$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER}は　メールを\nもった　ポケモンを\lあずかった$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "ともだちに　あったら　その\nポケモンを　せんとうに\lしておいてね！\p31ばんどうろだよ！\pそうそう　へんな　きが\nみちを　ふさいでたな\pもう　なくなったかな？$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "もう　ポケモンを\nもてないね‥$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "そうか‥　じゃあ\nいいよ‥$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "ありがとう！　とどけて\nくれたんだね！\pおれいに　これを\nどうぞ！$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "あいつ　ねてた　だろ？\nへへ　いった　とおり\lだろ？$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "へんな　きが　みちを\nふさいでるの\pはなしかけると\nくねくね　うごくのよ\pだれかが　ゼニガメじょうろで\nみずを　かけたら　あばれだした\lらしいわ$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "ラジオで　ながれる\nポケモンの　こもりうたが\lすきなの$"

Route35GoldenrodGate_Text_Fisher:
	.string "せかいには　なんしゅるいの\nポケモンが　いるんだろう\p3ねんまえ　オーキドはかせは\n150しゅるい　いると\lいっていた\pでも　さいきん　400しゅるい\nいじょう　いると　きいたよ！$"
