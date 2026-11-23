Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "AかBボタンで　とじます$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "ポケモンは　くさむらに\nかくれておる\lいつ　とびだすか　わからんぞ‥$"

Route29_Text_OldMan2:
	.string "なんどか　みかけたのう\nポケモンは　なんびき\lつかまえたかな？\pポケモンの　つかまえかたを\nおしえて　あげようか？$"

Route29_Text_OldManExplanation:
	.string "まず　よわらせると\nポケモンは　つかまえやすい\pそれから　バッグから　ボールを\nなげるのじゃ！　どの　ボールでも\lかまわんぞ\pもっと　しりたければ\nキキョウシティの　ポケモンじゅくに\lいくと　いい！\pそこの　せいとは　ポケモンに\nとても　くわしいぞ$"

Route29_Text_OldManDeclined:
	.string "そうか　まあ　よかろう\pどうろを　ぜんぶ　まわれば\nいろんな　ポケモンが　みつかる\pずかんでも　すみかが\nわかるぞ！\pもっと　しりたければ\nキキョウシティの　ポケモンじゅくに\lいくと　いい！\pそこの　せいとは　ポケモンに\nとても　くわしいぞ$"

Route29_Text_Youngster:
	.string "よう　ポケモンの　ちょうしは　どう？\pよわってて　しょうぶ　できないなら\nくさむらに　はいっちゃ　だめだよ$"

Route29_Text_Lass:
	.string "あの　だんさ　みえる？\nとびおりるのは　こわいけど\pくさむらを　とおらずに\nワカバへ　いけるのよ$"

Route29_Text_Girl:
	.string "ひとやすみ　したくて\nレポートを　かいたの$"

Route29_Text_Boy_WaitingForDay:
	.string "ひるまに　しか　でない\nポケモンを　まってるんだ$"

Route29_Text_Boy_WaitingForNight:
	.string "よるに　しか　でない\nポケモンを　まってるんだ$"

Route29_Text_MeetTuscany:
	.string "カヨ『はじめまして　かしら？\pわたくし　ようび　きょうだいの\nカヨと　もうします\pわたくしの　すきな　ようびを\nあてたら　ごほうびを　さしあげますわ$"

Route29_Text_TuscanyNope:
	.string "ちがいますわ！$"

Route29_Text_TuscanyGivesGift:
	.string "そのとおり！　おちかづきの\nしるしに　この　シルクのスカーフを\lどうぞ$"

Route29_Text_TuscanyGaveGift:
	.string "カヨ『とても　かわいらしいと\nおもいません　こと？\pノーマルタイプの　わざが\nつよくなりますの\pきっと　おやくに　たちますわ$"

Route29_Text_TuscanyTuesday:
	.string "カヨ『あねの　ツキコには\nおあいに　なりまして？\pおとうとの　スイには？\pわたくしは　7にん　きょうだいの\n3ばんめ　ですのよ$"

Route29_Text_Sign1:
	.string "29ばんどうろ\pヨシノシティ　ー　ワカバタウン$"

