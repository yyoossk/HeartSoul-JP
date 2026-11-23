CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "ひとが　たずねて　きたのは\nいつ　いらいかのう\pわしも　わかい　ころは\nポケモントレーナー　だった\lとうを　めざし　うみに\lもぐろうと　した\pいろんな　ことに\nうちこんだ　ものじゃ\pいまは　この　はまべで\nなみと　かぜの　おとを\lきいて　のんびり　しておる$"

CianwoodCity_Text_BellTowerStory:
	.string "エンジュの　スズのとうを\nしっておるか？\pとうの　うえには　とうめいな\nすずが　あるんじゃ\pつよい　かぜでも\nまったく　なりはせん\pならす　ほうほうは\nひとつ　だけ\pとうの　うえの　すずと　おなじ\nとうめいなスズを\lてに　いれることじゃ\pわしも　わかい　ころ\nさがしたが‥　ついに\lみつからなかった‥$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "うずまきじまを\nしっておるか？\pたきつぼには　うみなりの\nすずが　あるんじゃ\pあらい　なみでも\nまったく　なりはせん\pならす　ほうほうは\nひとつ　だけ\pたきつぼの　すずと　おなじ\nうみなりのスズを\lてに　いれることじゃ\pわしも　わかい　ころ\nさがしたが‥　ついに\lみつからなかった‥$"

CianwoodCity_Text_ClearBellReaction:
	.string "おお！　とうめいなスズを\nてに　いれたのか？\pわしの　むかしの　ゆめ‥\nそうか‥\pやりとげたのじゃな‥\n‥\l‥きこえる！\pスズのとうの　ほうから\nかぜに　のって　すずの\lねが‥$"

CianwoodCity_Text_TidalBellReaction:
	.string "おお！　うみなりのスズを\nてに　いれたのか？\pわしの　むかしの　ゆめ‥\nそうか‥\pやりとげたのじゃな‥\n‥\l‥きこえる！\pうずまきじまの　ほうから\nしおかぜに　のって　すずの\lねが‥$"
