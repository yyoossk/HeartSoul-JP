SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
	.string "カントーで　ひふきの\nショーを　するんだ！$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
	.string "しゅう‥　ひが\nちっちゃい‥$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
	.string "うみの　うえでは　ほのおは\nよわいのかな\lかんけい　ない？　ほんと？$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
	.string "おばあちゃんの　いえで\nむしを　つかまえるんだ！$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
	.string "わあ　つよいね！$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
	.string "ジョウトの　きには\nポケモンが　たくさん\lいるよ！$"
