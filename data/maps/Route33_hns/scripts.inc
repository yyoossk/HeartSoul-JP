Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "トンネルを　ぬけて　きたけど\nまだまだ　げんきが\lありあまってるぜ$"

Route33_Text_HikerAnthony2Beaten:
	.string "うおっ！　おまえ　おれより\nげんきだな！$"

Route33_Text_HikerAnthony2After:
	.string "やまおとこは　やまで\nいちばん　かがやくのさ$"

Route33_Text_AnthonyRegister:
	.string "やまおとこは　やまで\nいちばん　かがやくのさ$"

Route33_Text_AnthonyRematchIntro:
	.string "トンネルを　ぬけて　きたけど\nまだまだ　げんきが\lありあまってるぜ$"

Route33_Text_AnthonyRematchDefeat:
	.string "うおっ！　おまえ　おれより\nげんきだな！$"

Route33_Text_AnthonyPostRematch:
	.string "やまおとこは　やまで\nいちばん　かがやくのさ$"

Route33_Text_HikerAnthonyDunsparce:
	.string "よう　ノコッチは　つかまえたか？\pおれも　1ぴき　つかまえたんだ\pあかるい　ところで　みてみな\nおもしろい　かおを　してるぜ！$"

Route33_Text_Lass:
	.string "ふう　ふう‥\pあの　どうくつ　おもってたより\nひろかったわ\pマリルを　さがして　つかれちゃって\nそとに　でて　きたの$"
