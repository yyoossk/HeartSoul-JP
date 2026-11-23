SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
	.string "かなしみを　わすれたいの\nしょうぶ　しましょう！$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
	.string "こころが　ないてる‥$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
	.string "しつれんには　ふなたびが\nいちばん\pでも　こうそくせんじゃ\nかなしむには　みじかすぎる$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
	.string "コガネの　ラジオとうで\nじさくの　うたの\lオーディションを　うけるんだ$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
	.string "うおっ！\nおとが　われた！$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
	.string "バトルタワーで　デビュー\nする　つもり　だったのに‥\pクチバに　もどって\nしゅぎょう　しなおしだ‥$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
	.string "ラジオとう　と　いえば\nこんしゅうの　ラッキー\lナンバーは　なんだっけ？$"
