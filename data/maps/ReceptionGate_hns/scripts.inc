ReceptionGate_hns_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
	.string "アンズ『ちちうえに　おべんとうを\nとどけに　いく　ところなの\pしてんのうは　ひるも　よるも\nやすむ　ひまが　ないの\lたいへん　なのよ\pまた　しょうぶ　するなら\nあとで　どうじょうに　いるわ$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_INDIGOJUNCTION_POLICEMAN
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
	.string "みとめられた　トレーナー\nだけが　とおれます$"

VictoryRoadGate_Text_Kimono:
	.string "ごめんなさい　でんせつの\nポケモンを　だれかが\lしずめるまで　ここは\lとおれません‥$"

VictoryRoadGate_Text_NotEnoughBadges:
	.string "ジョウトの　ジムバッジが\nそろって　いませんね\pもうしわけ　ありませんが\nとおす　わけには　いきません$"

VictoryRoadGate_Text_EightBadges:
	.string "おお！　ジョウトの\nバッジが　8こ！\pどうぞ　おとおり　ください！$"

VictoryRoadGate_Text_LeftBlackBelt:
	.string "こっちは　シロガネやまへ\nつづいている\pおそろしく　つよい\nポケモンが　いるぞ$"

VictoryRoadGate_Text_RightBlackBelt:
	.string "ポケモンリーグへ　いくのか？\pしてんのうは　こわいほど\nつよいぞ　まちかまえてる！$"
