SSAqua_RoomSE_hns_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN_HNS, SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
	.string "おい　ぼうず！\nしょうぶ　しないか？$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
	.string "つよいな！$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
	.string "ひとりで　たびを\nしてるのか？\lママが　しんぱい　しないか？$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
	.string "あかちゃん　あつかい？\nずるい！$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
	.string "あっ！　まけちゃった！$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
	.string "おんなのこに　あかちゃん\nなんて　しつれいよ！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
	.string "あかちゃんじゃ　ないもん！\nレディに　しつれいよ！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
	.string "あっ！　まけちゃった！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
	.string "こどもの　ほうが　おとなより\nかしこい　ときも　あるのよ！$"
