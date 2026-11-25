SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina_Kj::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro_Kj, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_KJ_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_KJ_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_KJ_DEFEATED_SABRINA
	setflag FLAG_BADGE14_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_KJ_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle_Kj
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy_Kj::
	lock
	faceplayer
	goto_if_set FLAG_KJ_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue_Kj::
	lockall
	goto_if_set FLAG_BADGE14_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory_Kj
	msgbox SaffronCity_Gym_Text_GymStatue_Kj
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory_Kj::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon_Kj
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro_Kj::
	.string "…　やっぱり　きたわ！\n"
	.string "よかんが　したのよ！\p"
	.string "なにげに　スプーンを　なげたら\n"
	.string "まがって　いらい…　わたし\l"
	.string "エスパー　しょうじょ　なの\p"
	.string "たたかうの　すき　じゃない　けど\n"
	.string "あなたが　のぞむ　なら\l"
	.string "わたしの　ちから\l"
	.string "みせて　あげる！{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "まける　なんて…！\n"
	.string "とても　ショック！\l"
	.string "でも　まけは　まけ…！\p"
	.string "わたしの　しょうぶの　あまさを\n"
	.string "いさぎよく　みとめるわ！\p"
	.string "かった　あかしに\n"
	.string "ゴールド　バッジを\l"
	.string "あなたに　さしあげ　ましょう$"

SaffronCity_Gym_Text_SabrinaPostBattle_Kj::
	.string "ちょうのうりょくは　かぎられた\n"
	.string "ひとの　ちから　では　ないわ！\l"
	.string "だれでも　もってるのよ！\l"
	.string "ただ　それに　きが　つかない　だけ$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "ゴールド　バッジで\n"
	.string "レベル７０　までの　ポケモンが\l"
	.string "いうことを　ききます！\p"
	.string "それ　いじょう\n"
	.string "つよい　ポケモンは\l"
	.string "ソッポ　むいたり　ふてね　したり\l"
	.string "あつかいが　たいへん　です！\p"
	.string "だけど　そだて　すぎなきゃ\n"
	.string "そういう　しんぱいは　むようよ！\p"
	.string "それから…！\n"
	.string "わざマシンを　もって　いって$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "{PLAYER}は　ナツメから\n"
	.string "わざマシン０４を　もらった！$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "わざマシン０４は　めいそう！\n"
	.string "せいしんを　しゅうちゅう　させて\l"
	.string "とくこう　とくぼうを　あげるわ！$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "あ　にもつが　いっぱいよ$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "ナツメは…　わたし　より\n"
	.string "だいぶ　としした　だが！\l"
	.string "かのじょを　そんけい　している！$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "およばなかったか！$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "しょうぶが　ごかくの　ときは\n"
	.string "きもちが　つよい　ほうが　かつ！\p"
	.string "ナツメに　かちたい　なら\n"
	.string "きみも　かちたいッ！　と\l"
	.string "つよく　ねんじた　ほうが　いい$"

SaffronCity_Gym_Text_JohanIntro::
	.string "みえない　ちからを　つかう\n"
	.string "エスパーを　こわいと　おもうか！$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "こういう　ことも\n"
	.string "あるのか…$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "エスパーに　ゆうりな　もの？\n"
	.string "…　はははーッ！\l"
	.string "ゆうれい　や　むし　くらい　だぜ！$"

SaffronCity_Gym_Text_StacyIntro::
	.string "ポケモンは\n"
	.string "かいぬしに　にるって　しってるか？\p"
	.string "という　ことは…\n"
	.string "おまえの　ポケモンは　つよいかな？$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "わかった！$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "わたしも　まだ　まだ　だ…\n"
	.string "サイコキネシス　マスター　して\l"
	.string "ポケモンに　おしえ　なくては！$"

SaffronCity_Gym_Text_TyronIntro::
	.string "きみは　わかってる　だろ？\n"
	.string "ポケモンは　パワー　だけ\l"
	.string "あったって　かて　ない　ことを！$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "…　おれが\n"
	.string "まける　なんて　ばかな！$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "となりの　カラテ　だいおう　だって\n"
	.string "うちの　ナツメさんに\l"
	.string "コテンパンに　やられたんだぜ$"

SaffronCity_Gym_Text_TashaIntro::
	.string "きみは　わたしと\n"
	.string "ポケモンを　たたかわせる…！$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "くっ…！\n"
	.string "やはり　わたしが　やぶれたか$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "こういう　けっかは　わかってた…\n"
	.string "…　そう！\l"
	.string "これが　よち　のうりょく　だ$"

SaffronCity_Gym_Text_CameronIntro::
	.string "ナツメさんは　わかく　して\n"
	.string "この　ポケモン　ジムを　しきる\l"
	.string "じつりょくしゃ！\p"
	.string "かんたん　には　あわせ　ないぜ！$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "まけて　しまった！$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "おしえて　やろう…\n"
	.string "かつて　ヤマブキ　には\l"
	.string "ふたつの　ポケモン　ジムが　あった\p"
	.string "とういつ　しあいに　まけた　のが\n"
	.string "となりの　かくとう　どうじょうだ！$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "ヤマブキ　ジム！\l"
	.string "またの　なを\l"
	.string "エスパー　ようせい　じょ\l"
	.string "おまえ…\p"
	.string "…　ナツメに　あおうと　してるな？\n"
	.string "そうだろ！\l"
	.string "わかってるんだ！$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "ぐわああ…！$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "…　そうだ！\n"
	.string "ひとの　こころを　よむ\l"
	.string "のうりょくを　テレパス　という！$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "おーす！\n"
	.string "みらいの　チャンピオン！\p"
	.string "ナツメの　ポケモンは\n"
	.string "ちょうのうりょくを　つかって\l"
	.string "おまえの　ポケモンを　まどわすぜ！\p"
	.string "とくに…！　かくとう　ポケモンは\n"
	.string "あいしょうが　わるい！\p"
	.string "パワーを　はっきする　まえに\n"
	.string "エジキに　なっちまう　からな！$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "ちょうのうりょく…　か！\p"
	.string "おれに　そんな　ものが　あったら\n"
	.string "スロットで　あてほうだい　だぜ！$"

SaffronCity_Gym_Text_GymStatue_Kj::
	.string "ヤマブキ　ポケモン　ジム\n"
	.string "ナツメ　にんてい　トレーナー！\l"
	.string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon_Kj::
	.string "ヤマブキ　ポケモン　ジム\n"
	.string "ナツメ　にんてい　トレーナー！\l"
	.string "{RIVAL}　{PLAYER}$"

