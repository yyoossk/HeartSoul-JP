SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
	.string "うでだめしに\nカントーへ　いくんだ$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
	.string "かちたかった！$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
	.string "ジョウトの　トレーナーも\nカントーの　ジムリーダーと\lたたかえるんだ$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
	.string "チャンピオンを　めざして\nしゅぎょう　ちゅう！$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
	.string "わたしたちの　なにが\nちがうの？$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
	.string "いつか　あなたに\nかって　みせる！$"
