VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "わたしは　キキョウ\nポケモンジムの　リーダー　ハヤト！\pでんきで　ひこうタイプの\nポケモンを\pしびれさせる　なんて\nいわれるが‥　とりポケモンへの\lそんな　ぶじょくは　ゆるさない！\pすばらしい　とりポケモンの\nほんとうの　ちからを　みせて\lやる！$"

VioletGym_Text_Falkner_WinLoss:
	.string "‥くそっ！　ちちが　だいじに\nしてきた　とりポケモンが‥\pわかった　これを　うけとれ\pポケモンリーグ　こうにんの\nウイングバッジだ$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER}は　ウイングバッジを\nもらった$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "ウイングバッジは　ポケモンの\nこうげきりょくを　あげる\pそれに　おぼえられる\nポケモンなら　いつでも\lフラッシュが　つかえる\pそれと　これも　うけとれ$"

VioletGym_Text_Falkner_TMExplain:
	.string "わざマシンを　つかえば\nポケモンは　すぐに　あたらしい\lわざを　おぼえる\pその　わざマシンは　はねやすめ\pポケモンの　さいだいHPの\nはんぶんまで　かいふくする\pつまり　ポケモンを\nかいふく　させる　わざだ$"

VioletGym_Text_Falkner_AfterFight:
	.string "この　さきの　まちにも\nポケモンジムが　ある\pその　ジムで　うでを\nためすと　いい\pわたしは　さいこうの　とりつかいに\nなるため　もっと　しゅぎょうする！$"

VioletGym_Text_Falkner_Rematch:
	.string "してんのうに　かったそうだな\nおめでとう！\pわたしも　ひこうタイプの\nポケモンを　さらに　きたえた\pもう　いちど　おおぞらの\nちからに　いどめるか？$"

VioletGym_Text_Falkner_RematchLoss:
	.string "なんと‥　また　まけたか\pさいこうの　とりつかいに\nなるため　もっと　しゅぎょうする！$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "あいことばは　こんじょう！\pここの　ものは　とりポケモンの\nたつじんを　めざし　ひるも\lよるも　しゅぎょう　している\pかかって　こい！$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "ぐわあっ！$"

VioletGym_Text_BirdKeeperRod_After:
	.string "ハヤトさんの　うでまえは\nほんものだ！\pおれに　かった　くらいで\nちょうしに　のるなよ！$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "ハヤトさんと　たたかう\nうでが　あるか　みせて　もらおう！$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "そんな　ばかな！$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "しんまい　トレーナーに\nまけるなんて　なさけない‥$"

VioletGym_Text_GymGuide_Intro:
	.string "よう！　げんきか？　おれは\nトレーナーじゃ　ないけど\lアドバイスは　できるぜ！\pしんじろ！　しんじれば\nチャンピオンの　ゆめも　かなう\pしんじたか？　じゃあ　きけ\pハヤトの　エースは　きのみが\nだいすきな　タフな　フクロウだ\pつよくは　ないが\nなかなか　たおれない\pでんきや　いわタイプの　わざが\nきくが　どろかけには\lきを　つけろ！\pもっと　しりたかったら\nポケモンじゅくに　いきな\pあそこの　せいとは\nほんとうに　くわしいぜ！$"

VioletGym_Text_GymGuide_Win:
	.string "いい　しょうぶ　だった！\nこの　ちょうしなら　すぐに\lチャンピオンだ！$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "キキョウシティ　ポケモンジム$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "キキョウシティ　ポケモンジム\pハヤト　にんてい　トレーナー\n{PLAYER}$"
