Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "イワヤマトンネルを　たんけん\nしに　きたんだ$"

Route9_Text_CamperDeanBeaten:
	.string "うわっ！　きけんだ$"

Route9_Text_CamperDeanAfter:
	.string "イワヤマトンネルに　はいるまえに\nポケモンが　きずついちゃった\pすぐ　ポケモンセンターに\nつれていかなきゃ$"

Route9_Text_PicnickerHeidiSeen:
	.string "ピクニックって　したこと　ある？\pすっごく　たのしいのよ！$"

Route9_Text_PicnickerHeidiBeaten:
	.string "ああーん！$"

Route9_Text_PicnickerHeidiAfter:
	.string "おかしを　たくさん　やいて\nみんなで　わけるの\pとっても　おいしいのよ！$"

Route9_Text_CamperSidSeen:
	.string "おい　きみ！　ごみを\nすてるな！$"

Route9_Text_CamperSidBeaten:
	.string "ちゅうい　しただけ　なのに‥$"

Route9_Text_CamperSidAfter:
	.string "ごめん　きみは　すてて\nなかったね　かんちがいだ$"

Route9_Text_PicnickerEdnaSeen:
	.string "ごみを　のこして\nいっては　いけないわ$"

Route9_Text_PicnickerEdnaBeaten:
	.string "ああ‥　まけちゃった‥$"

Route9_Text_PicnickerEdnaAfter:
	.string "しょうエネも　だいじだけど\nかんきょうは　もっと\lだいじなのよ$"

Route9_Text_HikerTimSeen:
	.string "やまの　むこうから\nやってくる‥\pシロガネやまって\nジョウト　だっけ？$"

Route9_Text_HikerTimBeaten:
	.string "うたうのに　むちゅうで‥$"

Route9_Text_HikerTimAfter:
	.string "しょうぶは　しゅうちゅうりょくだ$"

Route9_Text_HikerSidneySeen:
	.string "ひみつを　おしえて　やろう\pでも　まずは　しょうぶだ！$"

Route9_Text_HikerSidneyBeaten:
	.string "くそう！　まけちまった‥$"

Route9_Text_HikerSidneyAfter:
	.string "はつでんしょは　ちいさな\nかわの　むこうだ$"

Route9_Text_Sign:
	.string "9ばんどうろ\pハナダシティ　ー　イワヤマトンネル$"
