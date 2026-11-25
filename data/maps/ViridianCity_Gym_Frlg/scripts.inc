ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE16_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy_Kj::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue_Kj::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory_Kj
	msgbox ViridianCity_Gym_Text_GymStatue_Kj
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory_Kj::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon_Kj
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "ふはははは！\nわたしの　かくれがへ　ようこそ！\pロケットだんを　かつての\nすがたに　もどす　まで\lここが　かくれがだ\pだが　また　みつかって\nしまった　ようだな\lよかろう\lこんどは　てかげん　しないぞ！\pふたたび　さいきょうの\nトレーナー　サカキが\lあいて　してやろう！{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "はっ！\nじつに　はげしい　たたかい\lだった　きみの　かちだ！\pあかしとして\nグリーンバッジを　やろう！\n{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "こんな　まけかたを　しては\nぶかに　あわせる　かおが　ない\lかれらの　しんらいを\lうらぎって　しまった\pきょうかぎりで\nロケットだんは　かいさん　する！\pわたしは　もう　いちど\nしゅぎょうに　うちこむ　つもりだ\pいつか　また　あおう！\nさらばだ！$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "グリーンバッジが　あれば\nどんな　レベルの　ポケモンも\lいうことを　きく\pポケモントレーナーとして\nうでを　きわめた　あかしだ\pそれが　あれば\nポケモンリーグに　ちょうせん\lできる\pそれと　この　わざマシンも\nもって　いけ\pポケモンリーグへの\nはなむけだ$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "{PLAYER}は　サカキから\nわざマシン26を　もらった$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "わざマシン26は　じしん\pおおきな　ゆれを　おこす\nつよい　こうげきだ\pわたしが　ここの　ジムを\nやって　いた　ころに　つくった\lもう　ずいぶん　むかしの　ことだ‥$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "もちものが　いっぱいの\nようだな！$"

ViridianCity_Gym_Text_YujiIntro::
	.string "へっ！\nもう　そろそろ\lいきが　きれて　きた　ころだろ！$"

ViridianCity_Gym_Text_YujiDefeat::
	.string "ちからつきた！$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "うちの　ジムリーダーに\nついて　いくには　ちからが\lひつようだぞ$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "ぐおおお！\nいかりが　こみあげて　きたぞ！$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "うおおー！$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "まだまだ　しゅぎょうが　たりない！$"

ViridianCity_Gym_Text_JasonIntro::
	.string "ポケモンと　ぼくは\nすてきな　おんがくを　かなでるんだ！$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "かんぺきな　ハーモニーだ！$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "ここの　ジムリーダーが\nだれだか　しってる？$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "からては　さいきょうの\nかくとうぎだ！$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "アイヤー！$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "おれの　ポケモンが　おれくらい\nからてが　うまければ‥$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "ほんとうの　じつりょくしゃは\nかっこよく　かつ　ものさ$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "てが　すべった！$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "こんな　まけかたを　したら\nリーダーに　しかられる‥$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "おれは　からて　だいおう！\nおまえの　うんめいは　おれ　しだい！$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "アイヤッ！$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "ポケモンリーグ？\nおまえが？　ちょうしに　のるな！$"

ViridianCity_Gym_Text_ColeIntro::
	.string "おれの　ムチの　おとで\nポケモンが　すくみあがるぞ！$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "いてて！\nムチうちだ！$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "まて！\nちょっと　ゆだん　しただけだ！$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "トキワジムは　ながい　あいだ\nしまって　いた\pでも　いまは　リーダーが\nもどって　きたんだ！$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "まけた　だと？$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "ポケモンリーグへ　いけるのは\nうちの　リーダーを\lたおした　ものだけだ！$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "よう！\nみらいの　チャンピオン！\pトキワの　リーダーが　だれなのか\nおれにも　わからない\pだが　ひとつ　たしかな　ことが\nある　ジムリーダーの　なかで\lいちばん　てごわい\pそれと　ここの　トレーナーは\nじめんタイプの　ポケモンが\lすき　らしいぞ$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "びっくり　したぜ！\nサカキが　トキワの\lジムリーダー　だったのか？$"

ViridianCity_Gym_Text_GymStatue_Kj::
	.string "トキワ　ポケモンジム\nリーダー　？\pにんてい　トレーナー\n{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon_Kj::
	.string "トキワ　ポケモンジム\nリーダー　サカキ\pにんてい　トレーナー\n{RIVAL}　{PLAYER}$"

