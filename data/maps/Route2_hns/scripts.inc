Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "ばんごう　おしえてよ！$"

Route2_Text_RobRematchIntro:
	.string "もっと　むしを　つかまえたんだ！\nみてよ！$"

Route2_Text_RobRematchDefeat:
	.string "もっと　いい　むしが　ほしい！$"

Route2_Text_RobPostRematch:
	.string "トキワの　むしは　ぜんぶ\nつかまえた　もっと　いい\lもりは　ないかな？$"

Route2_Text_BugCatcherRob_Seen:
	.string "ぼくの　むしポケモンは　つよいぞ\nかくごしろ！$"

Route2_Text_BugCatcherRob_Beaten:
	.string "こてんぱんだ‥$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "もっと　つよい　むしポケモンを\nさがしに　いくよ$"

Route2_Text_BugCatcherEd_Seen:
	.string "はんズボンで　くさむらを\nあるくと　きずだらけに\lなるかな？$"

Route2_Text_BugCatcherEd_Beaten:
	.string "いてて　いてて！$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "おふろに　はいると\nすごく　しみるんだよ$"

Route2_Text_BugCatcherDoug_Seen:
	.string "なんで　おんなのこは\nむしポケモンが　きらいなの？$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "だめだ！$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "むしポケモンは　おなかを　にぎると\nぬいぐるみ　みたいに\lむにゅって　なるんだ\pその　かんしょくが　たまらない！$"

Route2_Text_Sign:
	.string "2ばんどうろ\pトキワシティ　ー　ニビシティ$"

Route2_Text_DiglettsCaveSign:
	.string "ディグダのあな$"

