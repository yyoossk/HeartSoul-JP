Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "おい　おまえ！\nジョウトから　きたんだってな？$"

Route17_Text_BikerRileyBeaten:
	.string "うおっ　やるじゃねえか！$"

Route17_Text_BikerRileyAfterBattle:
	.string "ちょうしに　のるなよ\nジョウトの　ガキ！$"

Route17_Text_BikerJoelSeen:
	.string "うわ　かっこいい\nじてんしゃ　だな！$"

Route17_Text_BikerJoelBeaten:
	.string "みためだけじゃ　ないんだな‥$"

Route17_Text_BikerJoelAfterBattle:
	.string "おれは　みためは　かっこいいけど\nよわいから　ほんとうは\lかっこよくない\pもっと　しゅぎょう　しなきゃ‥$"

Route17_Text_BikerGlennSeen:
	.string "おい！　スピードしょうぶ\nしないか？$"

Route17_Text_BikerGlennBeaten:
	.string "ひえっ！　すげえ　パワーだ！$"

Route17_Text_BikerGlennAfterBattle:
	.string "サイクリングロードでは\nてばなし　うんてんが\lかっこいい　とされてる$"

Route17_Text_BikerCharlesSeen:
	.string "おれたちは　おそれを　しらない\nハイウェイスター！$"

Route17_Text_BikerCharlesBeaten:
	.string "うがあっ！　だいクラッシュだ！$"

Route17_Text_BikerCharlesAfterBattle:
	.string "むちゃな　うんてんは\nじこの　もとだ！　ほどほどにな！$"

Route17_Text_RileyRegister:
	.string "ジョウトの　ガキに　しちゃ\nわるくないな！$"

Route17_Text_RileyRematchIntro:
	.string "ジョウトの　ガキが　かてるのは\nいちどだけだ！$"

Route17_Text_RileyRematchDefeat:
	.string "やられた‥$"

Route17_Text_RileyPostRematch:
	.string "やっぱり　ジョウトで\nしゅぎょう　するべきかな$"

Route17_Text_JoelRegister:
	.string "おまえ　かっこいいな！\nばんごうを　こうかん　しようぜ！$"

Route17_Text_JoelRematchIntro:
	.string "どっちが　かっこいいか\nしょうぶだ！$"

Route17_Text_JoelRematchDefeat:
	.string "まだ　かっこよさが　たりない‥$"

Route17_Text_JoelPostRematch:
	.string "おまえ　みたいに　かっこよく\nなれるように　しゅぎょう\lするぜ！$"

Route17_Text_CharlesRegister:
	.string "おまえも　おれと　おなじ\nプレイボーイだな！\lばんごうを　くれ！$"

Route17_Text_CharlesRematchIntro:
	.string "おれは　ただの　ハイウェイスター\nじゃない　プレイボーイさ！$"

Route17_Text_CharlesRematchDefeat:
	.string "また　だいクラッシュだ！$"

Route17_Text_CharlesPostRematch:
	.string "イッシュで　おまえ　みたいな\nトレーナーに　あったぜ\lクラッシュ　するなよ！$"

