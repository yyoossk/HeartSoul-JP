BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "きょうは　つよい\nトレーナーの　インタビューを\lやるのかな？$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "ここで　レストランを\nひらいたら　ぜったい\lもうかるな$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "ふう‥\pはげしい　バトルの　あとは\nひといき　いれないと‥\pでも　いまも　さくせんや\nコンボを　かんがえるのは\lやめないよ$"

