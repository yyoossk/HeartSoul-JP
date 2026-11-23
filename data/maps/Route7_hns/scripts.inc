Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "なんの　ちらし　だろう？\p‥ちかつうろで　ぎょうぎの　わるい\nトレーナーが　しょうぶを\lしています\pちかくの　じゅうみんから\nくじょうが　ふえた　ため\lちかつうろは　とうぶん　へいさ\lします\pタマムシけいさつ$"

Route7_Text_LockedDoor:
	.string "かぎが　かかっている‥$"

