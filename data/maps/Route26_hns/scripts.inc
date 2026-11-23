Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
	.string "ポケモンリーグの　さいごの\nしあげ　ちゅうなんだ$"

Route26_Text_CooltrainermJakeBeaten:
	.string "しくじった！$"

Route26_Text_CooltrainermJakeAfter:
	.string "リーグで　かつのは\nむずかしそうだ\pもっと　しゅぎょう　しなきゃ\pリーグの　してんのうは\nジムリーダーより　つよいらしい$"

Route26_Text_CooltrainermGavenSeen:
	.string "きびしい　しょうぶを　けいけん\nして　ちからを　つけるんだ$"

Route26_Text_CooltrainermGavenBeaten:
	.string "ぐあっ！　じんせいは\nもっと　きびしい！$"

Route26_Text_CooltrainermGavenAfter:
	.string "ポケモンリーグへ　いくには\nチャンピオンロードを\lぬけなきゃ　ならない\pでも　チャンピオンロードは\nけわしい\pほとんど　だれも\nいかないんだ！$"

Route26_Text_GavenRegister:
	.string "ポケモンリーグへ　いくには\nチャンピオンロードを\lぬけなきゃ　ならない\pでも　チャンピオンロードは\nけわしい\pほとんど　だれも\nいかないんだ！$"

Route26_Text_GavenRematchIntro:
	.string "きびしい　しょうぶを　けいけん\nして　ちからを　つけるんだ$"

Route26_Text_GavenRematchDefeat:
	.string "ぐあっ！　じんせいは\nもっと　きびしい！$"

Route26_Text_GavenPostRematch:
	.string "ポケモンリーグへ　いくには\nチャンピオンロードを\lぬけなきゃ　ならない\pでも　チャンピオンロードは\nけわしい\pほとんど　だれも\nいかないんだ！$"

Route26_Text_CooltrainerfJoyceSeen:
	.string "ここまで　きたって　ことは\nつよいのね\pこの　しょうぶに　ぜんりょくを\nかけるわ！$"

Route26_Text_CooltrainerfJoyceBeaten:
	.string "うそ！　しんじられない！$"

Route26_Text_CooltrainerfJoyceAfter:
	.string "ジムリーダーを　8にん　たおして\nじしんが　あったのに\pつぎは　もっと\nがんばらなきゃ$"

Route26_Text_CooltrainerfBethSeen:
	.string "{RIVAL}って　トレーナーに\nまけたの\pとても　つよかったけど‥\pなにが　なんでも　かたなきゃ\nいけない　みたいだった\pポケモンが　かわいそう\nだったわ$"

Route26_Text_CooltrainerfBethBeaten:
	.string "ポケモンは　せんそうの\nどうぐじゃ　ないわ$"

Route26_Text_CooltrainerfBethAfter:
	.string "ポケモンは　かけがえのない\nいっしょうの　パートナーよ$"

Route26_Text_BethRegister:
	.string "ポケモンは　かけがえのない\nいっしょうの　パートナーよ$"

Route26_Text_BethRematchIntro:
	.string "{RIVAL}って　トレーナーに\nまけたの\pでも　あなたには\nまけないわ！$"

Route26_Text_BethRematchDefeat:
	.string "ポケモンは　せんそうの\nどうぐじゃ　ないわ$"

Route26_Text_BethPostRematch:
	.string "ポケモンは　かけがえのない\nいっしょうの　パートナーよ$"

Route26_Text_PsychicRichardSeen:
	.string "わあ　バッジが　いっぱい！\nかんしんするよ\pでも　あつめる　だけじゃ\nまんぞく　しないだろう？$"

Route26_Text_PsychicRichardBeaten:
	.string "いい　しょうぶだ！$"

Route26_Text_PsychicRichardAfter:
	.string "ひとも　ポケモンも\nけいけんで　せいちょうする\pなまけて　まんぞく\nしては　いけないよ$"

Route26_Text_Sign:
	.string "26ばんどうろ\pポケモンリーグ\nうけつけ　ゲート$"

