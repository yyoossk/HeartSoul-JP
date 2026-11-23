Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "きに　のぼる　へんな　ポケモンを\nみたんだ　でも　マンキーじゃ\lなかった　ような‥$"

Route11_Text_YoungsterOwenSeen:
	.string "ポケモンに　ずるは　なしだ\pせいせいどうどう　いこう！$"

Route11_Text_YoungsterOwenBeaten:
	.string "あれ？　どうして　こうなった？$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "せいせいどうどう\nたたかったんだ\pぜんぜん　くやしくないよ$"

Route11_Text_YoungsterJasonSeen:
	.string "はんズボンで　くさむらに　いると\nちょっと　くすぐったいんだ$"

Route11_Text_YoungsterJasonBeaten:
	.string "あいやー！　ふみつぶされた！$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "くさむらで　もっと\nポケモンを　つかまえるぞ$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "‥\pめを　とじてる　あいだに\nまけていた‥$"

Route11_Text_PsychicFidelSeen:
	.string "みえる‥\pきみの　すべてが　みえる‥$"

Route11_Text_PsychicFidelBeaten:
	.string "きみの　ちからは\nよちできなかった‥$"

Route11_Text_PsychicFidelAfterBattle:
	.string "しんねんの　つよさ‥\pきみが　つよいのは　ポケモンを\nしんじて　いるからだ$"

Route11_Text_Sign:
	.string "11ばんどうろ$"

