PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "うぐぐ…　ゆうれいめ…\n"
	.string "…ケーッ！$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "はっ！\n"
	.string "ゆ　ゆうれいは　どこじゃ$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "むう…\n"
	.string "ゆめを　みてた　ようじゃ$"

PokemonTower_4F_Text_LaurelIntro::
	.string "イッ…　ショ…　ニ…\n"
	.string "…　ノロ…ワレ！$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "…はっ！$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "…どうしても　ゆうれいの\n"
	.string "しょうたいが　わからない…$"

PokemonTower_4F_Text_JodyIntro::
	.string "フフフッ…！\n"
	.string "…　カテ…　ルカーッ！$"

PokemonTower_4F_Text_JodyDefeat::
	.string "…ん　わしは？$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "ふう！　ポケモンの\n"
	.string "さまよえる　れいよ　やすらかに…$"

