SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "どんなに　はげしく　たたかっても\nとうは　びくとも　せん$"

SproutTower_Text_SageNico_Beaten:
	.string "がんばったが\nわしは　よわい$"

SproutTower_Text_SageNico_AfterBattle:
	.string "しなやかな　はしらが\nじしんからも　とうを\lまもって　おるのじゃ$"

SproutTower_Text_SageEdmond_Seen:
	.string "‥かぜに　ゆれる\nこのはの　ように‥$"

SproutTower_Text_SageEdmond_Beaten:
	.string "ああ　よわい！$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "マダツボミの　しなやかな\nうごきを　まねたが‥\pしゅぎょうが\nたりなかった$"

SproutTower_Text_2F_Statue:
	.string "ポケモンの　ぞう‥\pとても　ふうかくが　ある$"
