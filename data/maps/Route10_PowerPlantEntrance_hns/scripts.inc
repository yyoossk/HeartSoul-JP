Route10_PowerPlantEntrance_hns_MapScripts::
	.byte 0

Route10_PowerPlantEntrance_EventScript_Cop::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopAfterDone
	msgbox Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopDuringRocket::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopAfterDone::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_Engineer1::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer1Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer1Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer2Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Cop2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Cop2Done
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious, MSGBOX_NPC
	end
Route10_PowerPlantEntrance_EventScript_Cop2Done::
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer3Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_Trigger_Cop::
	lock
	playse SE_POKENAV_CALL
	applymovement2 LOCALID_POWERPLANT_COP, Common_Movement_ExclamationMark
	waitse
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkToPlayer
	waitmovement 0
	turnobject LOCALID_POWERPLANT_ENGINEER, DIR_SOUTH
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_POWERPLANT_COP, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkBack
	waitmovement 0
	setvar VAR_KANTO_ROCKET_STORY_STATE, 2
	clearflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	release
	end

Route10_PowerPlantEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route10_PowerPlantEntrance_Movement_WalkBack:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn:
	.string "はつでんしょに　どろぼうが\nはいった‥\pよのなか　どう\nなってるんだ？$"

Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter:
	.string "ハナダから　れんらくが\nあった\pあやしい　やつが\nうろついて　いる\lらしい$"

Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation:
	.string "きょうりょく　して\nもらえないか？$"

Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity:
	.string "けいびを　つよめ\nなければ$"

Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart:
	.string "はつでんきに　かかせない\nぶひんが　ぬすまれたんだ\pあれが　ないと　あたらしい\nはつでんきは　うごかない！$"

Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning:
	.string "はつでんきは　ちゃんと\nうごいてるよ\lでんきは　あまる　くらいだ$"

Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning:
	.string "この　はつでんしょは\nむかし　すてられて　いたんだ\pリニアに　でんきを\nおくるために　また\lうごかしたんだよ$"

Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain:
	.string "はつでんきが\nまた　うごいたぞ！$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious:
	.string "しょちょうは　おくの　へやで\nはつでんきの　そばに　いる\pだれかに　はつでんきを\nこわされてから　かなしいやら\lおこるやら‥$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful:
	.string "はつでんきが　なおってから\nしょちょうは　ごきげんだよ$"

Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity:
	.string "リニアは　でんきを\nたくさん　つかうんだ\pあたらしい　はつでんきが\nうごかないと　はしれない$"

Route10_PowerPlantEntrance_EventScript_Lorenzo::
	lock
	faceplayer
	goto_if_set FLAG_POWERPLANT_NPC_TRADE_COMPLETED, Route10_PowerPlantEntrance_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MAGNETON, Route10_PowerPlantEntrance_Text_WantToTrade, Route10_PowerPlantEntrance_EventScript_DeclineTrade, Route10_PowerPlantEntrance_EventScript_NotRequestedMon, Route10_PowerPlantEntrance_Text_TakeCare
	setflag FLAG_POWERPLANT_NPC_TRADE_COMPLETED
	release
	end

Route10_PowerPlantEntrance_EventScript_DeclineTrade::
	msgbox Route10_PowerPlantEntrance_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route10_PowerPlantEntrance_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_TradeCompleted::
	msgbox Route10_PowerPlantEntrance_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_Text_WantToTrade:
	.string "ぼくは　この　はつでんしょで\nはたらいてる\lレアコイルは　ながねんの\lあいぼう　なんだ\pでも　ずっと　{STR_VAR_1}が\nほしくてね\pぼくの　{STR_VAR_2}と\nこうかん　しない？$"

Route10_PowerPlantEntrance_Text_TakeCare:
	.string "ありがとう！\nマギーを　よろしくね！$"

Route10_PowerPlantEntrance_Text_DeclineTrade:
	.string "だめ？　ざんねん\nレアコイルは　はたらきもの\lなのに$"

Route10_PowerPlantEntrance_Text_NotRequestedMon:
	.string "うーん　それは　{STR_VAR_1}じゃ\nないね　ほしいのは\lそれじゃ　ないんだ$"

Route10_PowerPlantEntrance_Text_TradeCompleted:
	.string "マギーは　げんき？\nじばが　だいすき　なんだ！$"

Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning:
	.string "よし！　これで　やっと\nリニアを　うごかせるぞ$"
