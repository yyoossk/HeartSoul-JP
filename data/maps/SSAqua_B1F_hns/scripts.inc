SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
	.string "うえっ！\nみなきゃ　よかった！$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "おい　ぼうず　あいぼうを\nさがして　くれないか？\pどこかで　さぼってるんだ\nあの　なまけもの！\pさがしに　いきたいが\nいまは　しごと　ちゅうなんだ$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "ああ　まいったな‥\pせんちょうが　かんかんに\nなるぞ‥$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "ありがとう　ぼうず！\nもう　さぼらない　ように\lしっかり　しかって　おいた！$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "ちいさな　おんなのこ？\pここを　とおって\nいったかも　しれないな$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "この　さきが　しょくどうだ\pおくの　かいだんは\nせんちょうしつに\lつづいてるぞ$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "きゅうけい　ちゅうの\nしょうぶは　さいこうだ$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "かっても　まけても\nきゅうけいは　おわりだ！$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "ほんきに　ならないと\nかてないな$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "たいくつ‥\nしょうぶ　しない？$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "きゃっ！　つよすぎ！$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "ヤマブキ　タマムシ‥\nカントーには　おおきな\lまちが　たくさん　あるって$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "うぷ‥\nふなよいだ！$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "もう　うごけない‥$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "もう　ふねは　こりごり\nつぎは\pリニアに　のるよ$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "ここは　ふなのりの\nしごとばだ！$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "ホームで　まけるとは‥$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "クチバシティから　アサギシティ\nまで　いろんな\pおきゃくを　のせるんだ$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "うみに　でてるのに\nつりが　できない！\pたいくつだ！\nしょうぶ　しよう！$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "も　もう　たいくつ\nじゃない‥$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "クチバの　さんばしで\nつりを　する　つもりだ$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "ふねの　ゆれに\nたえて\pあしを　きたえて　いる！$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "ゆさぶられて\nたおれた！$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "ジョウトで　カラテおうを\nみつけられなかった\pどこかの　どうくつで\nしゅぎょう　してる\lらしいんだが$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "おれは　うみの　おとこ！\pでも　ポケモンを　きたえて\nチャンピオンを　めざすぞ！$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "しゅぎょう　ぶそくが\nまるわかりだ‥$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "バッジが　8こ！\nジムリーダーに　かった\pあかし　だな\pつよい　わけだ！$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "せいとたちに　ゆび\nいっぽん　ふれさせない\lわよ！$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "きゃーっ！$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "キキョウの　そとの　いせきへ\nえんそく　なの$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "アルフのいせきって\nしってる？$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "うわーっ！$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "いせきの　なかでは\nラジオが　へんな　でんぱを\lひろうんだ$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "アルフのいせきには\nへんな　いしの　パネルが\lあるんだ$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "やられた！$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "いしの　パネルは　4まい\nあるって　ほんで　よんだよ$"

