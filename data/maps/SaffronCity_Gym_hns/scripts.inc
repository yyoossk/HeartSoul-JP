SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "ナツメ『あなたが　また\nくるのは　わかっていた‥\p"
	.string "3ねんぶりね　{PLAYER}\p"
	.string "あの　とき　あなたに　まけてから\nいまも　わたしの　よちは\lあなたの　みらいを　よめないの\p"
	.string "のぞむ　なら\nもう　いちど　ちょうのうりょくを\lみせて　あげる！$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "ナツメ『あなたの　ちから‥\pわたしの　よち　を\nはるかに　こえている‥\pみらいを　かんぜんに　よむ\nことは　できない　のかも‥\pいいわ　あなたの　かち\nゴールドバッジを　あげる$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER}は\nゴールドバッジを　もらった$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "ナツメ『ゴールドバッジは　あなたの\nせんざいてきな　ちからを\lひきだすわ‥\pあなたの　ちからは\nよめなかったけど　これだけは\lたしかよ\pあなたは　みんなに　あいされる\nチャンピオンに　なるわ！$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "これも　うけとって$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "それは　スキルスワップ\pあいての　とくせいを　うばって\nじぶんの　とくせいを\lあたえる　わざよ\pかしこく　つかってね‥$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "ナツメ『ポケモンへの　あいじょうが\nわたしの　ちょうのうりょくを\lうわまわった‥\pあいの　ちからも　きっと\nちょうのうりょくの　ひとつ‥$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "ナツメ『あら　カントーの\nチャンピオン\pあなたが　くるのを\nかんじて　いたわ\pちからが　おおきく\nなったわね\pいまも　あなたの　オーラを\nかんじる\pもう　いちど\nしょうぶ　する？$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "ナツメ『ポケモンへの　あいじょうが\nまた　わたしの　ちょうのうりょくを\lうわまわった‥$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "あなたが　たおした　ものたちの\nちからが　わたしに　あつまる！$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "つよい‥　つよすぎる‥$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "あなたの　ちからの\nみなもとは　なに？$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "ちょうのうりょくとは\nこころの　ちからだ$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "きみの　こころの　ほうが\nつよい！$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "きみは　うでだけで　なく\nこころも　きたえたんだね$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "ふふふふ‥　はっきり\nみえるわ\pあなたの　こころが\nみえる！$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "こころを　よんだのに\nまけた‥$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "しまった！　あなたに　まけると\nよちしたのを　わすれてた$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "となりの　かくとうどうじょうは\nむかし　この　まちの\lジム　だったんだ$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "かなわなかった‥$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "かくとうどうじょうの　しはん\nカラテおうは　ナツメさんに\lこてんぱんに　されたんだ$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "よう　チャンピオン！\p"
	.string "きみほどの　うでなら\nエスパータイプの　たいさくは\lいわなくても　わかるよな？\p"
	.string "きたい　してるぞ！\pがんばれよ！$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "また　すばらしい\nしょうぶ　だったな！$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
	.string "ヤマブキ　ポケモンジム\nリーダー　ナツメ\pかった　トレーナー\n{KANTO_RIVAL}　{PLAYER}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "ヤマブキ　ポケモンジム\nリーダー　ナツメ\pかった　トレーナー\n{KANTO_RIVAL}　{PLAYER}$"
