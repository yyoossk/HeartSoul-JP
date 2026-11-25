SSAnne_2F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
	.string "わかもの　との　しょうぶ　こそ\n"
	.string "じんせいの　たのしみ！$"

SSAnne_2F_Room2_Text_BrooksDefeat::
	.string "いい　しょうぶ！\n"
	.string "わかがえる　ようだ$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
	.string "１５ねん　まえ　なら\n"
	.string "わたしが　かって　いた　だろう！$"

SSAnne_2F_Room2_Text_DaleIntro::
	.string "おれが　つった\n"
	.string "じまんの　さかなを　みろ！$"

SSAnne_2F_Room2_Text_DaleDefeat::
	.string "もう　からっぽ！$"

SSAnne_2F_Room2_Text_DalePostBattle::
	.string "…　パーティ？\p"
	.string "せんじょう　パーティは\n"
	.string "もう　おわった　ころ　じゃないかな$"

