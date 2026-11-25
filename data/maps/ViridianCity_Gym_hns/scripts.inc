ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "{KANTO_RIVAL}『もう　きたのか？\p"
	.string "また　おれと　やりたいなら\nかくとうどうじょうに　こい！$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "{KANTO_RIVAL}『よう　{PLAYER}！\nやっと　きたな？\p"
	.string "グレンでは　そんな　きぶんじゃ\nなかったが\p"
	.string "いまなら　あいて\nしてやるぜ\p‥\p"
	.string "ジョウトの　ジムを\nぜんぶ　せいは　した　だと？\p"
	.string "へっ！　さすが\nおれの　ライバルだぜ\p"
	.string "だが　3ねんまえの　おれと\nおなじだと　おもうなよ\p"
	.string "じゅんびは　いいか？\n{PLAYER}！$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "{KANTO_RIVAL}『なに？\p"
	.string "なんで　また　おれが\nおまえに　まけるんだ？\p‥\p"
	.string "ちっ　わかったよ‥\nほら　グリーンバッジだ$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER}は\nグリーンバッジを　もらった$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "{KANTO_RIVAL}『‥\p"
	.string "やっぱり　おまえは\nつよいな　{PLAYER}\p"
	.string "だが　いつか　かならず\nおまえを　たおす\p"
	.string "わすれるなよ！$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "これを　もってけ$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "それは　トリックルーム\pたたかいの　ポケモンの\nすばやさが　ぎゃくに　なる\lおそい　ほうが　さきに\lうごくんだ\pたたかいを　ひっくりかえす\nのに　つかえ$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "{KANTO_RIVAL}『いいか\p"
	.string "おれが　おまえを　たおすまで\nまけるんじゃ　ねえぞ\lわかったな？$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "よう！　みらいの　チャンピオン！\pちょうしは　どうだ？\nのってる　みたいだな\pここの　ジムリーダーは\n3ねんまえに　チャンピオンと\lたたかった　おとこだ\pあまく　ないぞ\pぜんりょくで　いけ！$"

ViridianCity_Gym_Text_Guide_Win:
	.string "いやあ　ほんとうに\nつよいな‥\pかんどうの　しょうぶ\nだった　なみだが\lでて　きたよ$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
	.string "トキワ　ポケモンジム\nリーダー　{KANTO_RIVAL}\pかった　トレーナー\nまだ　いない$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "トキワ　ポケモンジム\nリーダー　{KANTO_RIVAL}\pかった　トレーナー\n{PLAYER}$"

