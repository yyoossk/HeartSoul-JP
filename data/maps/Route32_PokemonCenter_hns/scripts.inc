Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "ここは　いい　つりばだ\pつりを　してる　ひとを\nみたかい？　きみは　どうだ？\pわしの　つりざおを\nひとつ　やろうか？$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "へへ　そう　こなくちゃ\pこれで　きみも\nつりびとだ！$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "つりは　いいぞ！\pうみでも　かわでも　みずが\nあったら　つりざおを\lつかって　みな$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "そうか‥　ざんねんだ‥$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "よう　ぼうず\nつれてるか？$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "ポケモンに　なにを\nもたせようかな？\pこうげきりょくが　あがる\nどうぐ　とか‥$"

