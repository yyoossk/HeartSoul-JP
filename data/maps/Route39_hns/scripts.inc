Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "バオバ『なんと！　いまの　かげは\nポケモン　だったのか？\pちゃんと　みえたかい？\nなにいろ　だったか\lわからなかった‥$"

Route39_Text_BaobaIntro::
	.string "ふしぎだ‥\p‥おお！\nきみが　もっているのは‥\lいわゆる‥　ポケモンずかん！\pひさしぶりに　みたよ\pわしの　なまえは　バオバ！\nむかし　セキチクシティで\lサファリゾーンを　やって　いたが\lあたらしい　あそびが　ふえて\lじだいおくれに　なってしまった\pそこで　かいがいで　さいしんの\nぎじゅつを　まなんで　タンバに\lさいせんたんの　サファリゾーンを\lひらく　ことに　したんだ\pこうして　はなして　いるのも\nなにかの　えんかも　しれない\pポケギアに　おたがいの　ばんごうを\nとうろく　しないかね？\pサファリゾーンが　オープン　したら\nだれよりも　さきに　きみに\lでんわ　するよ！$"

Route39_Text_Registered:
	.string "{PLAYER}は　ポケギアに\nバオバを　とうろく　した！$"


Route39_Text_WillCall:
	.string "バオバ『ちかいうちに　ポケギアで\nしらせるよ！$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "あの　かげ‥　もしかして\nおおきな　ポッポ　かしら？$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "ミルタンク『モーッ！$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "アサギに　かえって　きた\nばかりだ\pポケモンしょうぶ　しないか？$"

Route39_Text_SailorEugeneBeaten:
	.string "うわあああっ！$"

Route39_Text_SailorEugeneAfter:
	.string "おれの　ポケモンは　かいがいで\nつかまえて　そだてたんだ\pながい　こうかいの\nなかまなのさ$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "ピカチュウを　じまん　する\nチャンスだ！$"

Route39_Text_PokefanMDerekBeaten:
	.string "ピカチュウを　じまん　する\nひまも　なかった‥$"

Route39_Text_PokefanMDerekAfter:
	.string "きみの　じまんは　きかないよ！\pポケモン　だいすきクラブは\nひとの　じまんは　きかない\lきまり　なんだ！$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "かわいい　ポケモンたち\pいっしょに　ポケモンを\nみせあいましょう$"

Route39_Text_PokefanFRuthBeaten:
	.string "まけても　かまわないわ$"

Route39_Text_PokefanFRuthAfter:
	.string "ベビィポケモンって\nしってる？\pきっと　すごく\nかわいいわよ！$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "きみの　ポケモンの\nちからを　みせて　もらおう$"

Route39_Text_PsychicNormanBeaten:
	.string "おお　きみの　ポケモンには\nかのうせいが　ある$"

Route39_Text_PsychicNormanAfter:
	.string "ポケモンって　それぞれ\nのうりょくが　ちがうだろ？\pひとも　おなじさ\nみんな　ちがう\lかのうせいを　もってる$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "ちょうど　いい　ところに\nきたわね\pしょうぶしましょう$"

Route39_Text_PokefanFJaimeBeaten:
	.string "まあ　ざんねん‥$"

Route39_Text_PokefanFJaimeAfter:
	.string "よるに　この　39ばんどうろで\nブラッキーに　であったの\pなぜか　ここで　とっくん\nすると　よろこぶのよ\pほかの　どこよりも　ここで\nとっくん　すると　なつく\lみたいなの$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "39ばんどうろ\pアサギシティ　ー　エンジュシティ$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "モーモーぼくじょう\pしんせんで　おいしい\nミルクを　どうぞ$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "トレーナーの　こころえ\pきに　ずつきを　すると\nポケモンが　おちてくる\pきによって　ちがう　ポケモンが\nおちてくるぞ\pみかけた　きには\nどんどん　ずつきだ！$"

Route39_Text_DerekRegister:
	.string "きみの　じまんは　きかないよ！\pポケモン　だいすきクラブは\nひとの　じまんは　きかない\lきまり　なんだ！$"

Route39_Text_DerekHasItem:
	.string "おーい！　ピカチュウを　じまん\nしてたら　いいもの　みつけたよ\pはい　あげる！$"

Route39_Text_DerekGaveItem:
	.string "ピカチュウ　さいこう！\nそう　おもうだろ？$"

Route39_Text_DerekNoRoom:
	.string "うーん　バッグが　いっぱいだね\pあきを　つくってから\nまた　きて$"
