Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "よるの　うみで　およいだ\nこと　あるか？$"

Route19_Text_SwimmermHaroldBeaten:
	.string "ぶくぶく‥$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "よるの　うみは　まっくろで\nのみこまれそうな　きが　するんだ$"

Route19_Text_SwimmermTuckerSeen:
	.string "ぜえ　ぜえ‥　もう‥　すこしで‥\pセキチク‥　まで‥$"

Route19_Text_SwimmermTuckerBeaten:
	.string "おぼれる！$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "かのじょに‥　セキチクまで\nおよごうって　いわれて‥　ぜえ‥$"

Route19_Text_SwimmerfDawnSeen:
	.string "いくじなしは　だいきらい！$"

Route19_Text_SwimmerfDawnBeaten:
	.string "およぎなら　かてるのに‥$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "セキチクから　ふたごじままで\nすぐ　なのに‥\pまったく　なさけない\nかれしね！$"

Route19_Text_SwimmermJeromeSeen:
	.string "およぎ？　にがて　なんだ\pあさい　ところで\nパチャパチャ　してるだけさ$"

Route19_Text_SwimmermJeromeBeaten:
	.string "かてると　おもったのに$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "およぎは　にがてでも\nうみは　だいすきさ$"

Route19_Text_Fisher1:
	.string "わるいね　この　みちは\nこうじちゅう　なんだ\pグレンに　いきたいなら\nマサラタウンから　みなみへ\lいくと　いいよ$"

Route19_Text_Kingler:
	.string "キングラー『キイイイイイイッ$"

Route19_Text_Fisher1_RocksCleared:
	.string "あせだくだ\nひとおよぎ　するか！$"

Route19_Text_Fisher2:
	.string "まいったな　キングラーが\nはまべを　ふさいでるよ$"

Route19_Text_FisherBefore:
	.string "キングラーが　いなくなるまで\nつりは　できないな$"

Route19_Text_Fisher2_RocksCleared:
	.string "やっと　キングラーが\nいなくなった！\pこれで　また　つりが　できる$"

Route19_Text_Sign:
	.string "19ばんすいどう\pセキチクシティ　ー　ふたごじま$"

Route19_Text_CarefulSwimmingSign:
	.string "ふたごじままで　およぐ　ときは\nきをつけて　ください\pセキチクけいさつ$"

