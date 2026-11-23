CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "スロットは　ぜんぶ\nさいしんしき　だよ$"

CeladonGameCorner_Text_Teacher:
	.string "ほしいのは　この　だいよ\pきのう　ぼろまけ　したから\nきょうは　でるはず$"

CeladonGameCorner_Text_FishingGuru:
	.string "この　スロットは　でる\nきが　する‥\pだいに　よって　でかたが\nちがうんだ$"

CeladonGameCorner_Text_Fisher1:
	.string "がはははは！\pコインが　どんどん\nでてくるぞ！\pん？　なんだ　ぼうず？\nあそびたいのか？\pおれの　うんを　わけて\nやろう！$"

CeladonGameCorner_Text_Fisher2:
	.string "がはははは！\pひとに　いい　ことを　すると\nきもちが　いいな！$"

CeladonGameCorner_Text_GymGuide:
	.string "よう！　みらいの　チャンピオン！\pきみも　スロットかい？\pけいひんの　ポケモンが\nほしくて　コインを\lためてるんだ\pでも　まだ　たりなくて‥$"

CeladonGameCorner_Text_PokefanF:
	.string "ルーレット‥\pスロットより　かくりつが\nよみやすいから　すきなの\pでも　はいとうが\nずっと　すくないのよね$"

CeladonGameCorner_Text_Gramps:
	.string "うーむ‥　あおに　ぜんぶ\nかけた　ほうが　かくりつは\lいいが‥　どうしたものか$"

CeladonGameCorner_Text_Woman:
	.string "かちが　とまらない！$"
