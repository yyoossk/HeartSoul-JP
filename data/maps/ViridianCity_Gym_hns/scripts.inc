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
	.string "グリーン『もう　きたのか？\pまた　おれと　やりたいなら\nかくとうどうじょうに　こい！$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "グリーン『よう！\nやっと　きたな？\pグレンでは　そんな　きぶんじゃ\nなかったが\pいまなら　あいて\nしてやるぜ\p‥\pジョウトの　ジムを\nぜんぶ　せいは　した　だと？\pへっ！　ジョウトの　ジムも\nたいした　こと　ないな\pまあ　きにするな\pおまえが　つよいか　どうか\nいま　たたかえば　わかる\pじゅんびは　いいか？\nジョウトの　チャンピオン！$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "グリーン『なに？\pなんで　おれが　おまえに\nまけるんだ？\p‥\pちっ　わかったよ‥\nほら　グリーンバッジだ$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER}は\nグリーンバッジを　もらった$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "グリーン『‥\pわかった　おれの　まちがい\nだった　おまえは　ほんもの\lいい　トレーナーだ\pだが　いつか\nおまえを　たおす\pわすれるなよ！$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "これを　もってけ$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "それは　トリックルーム\pたたかいの　ポケモンの\nすばやさが　ぎゃくに　なる\lおそい　ほうが　さきに\lうごくんだ\pたたかいを　ひっくりかえす\nのに　つかえ$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "グリーン『いいか\pおれが　おまえを　たおすまで\nまけるんじゃ　ねえぞ\lわかったな？$"


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
	.string "トキワ　ポケモンジム\nリーダー　グリーン\pかった　トレーナー\nグリーン　レッド$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "トキワ　ポケモンジム\nリーダー　グリーン\pかった　トレーナー\nグリーン　レッド　{PLAYER}$"

