CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "エリカ『こんにちは‥\nいい　おてんき　ですわね\lとても　きもちいい‥\p‥うとうと　して\nしまいそう‥\pわたくしは　エリカ\nタマムシジムの　リーダー\lですの\p‥まあ　ジョウトから\nいらしたの？　すてき‥\pあら　ごめんなさい　わたくしに\nちょうせん　なさる　のですね\pわかりました　でも\nまけませんわ$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "エリカ『まあ！　まいりましたわ‥\pとても　おつよいのね‥\pレインボーバッジを\nさしあげますわ‥$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER}は\nレインボーバッジを　もらった$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "エリカ『すてきな\nしょうぶ　でしたわ\pかんどう　しましたの\nこの　わざマシンを\lうけとって　くださいな$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "それは　ギガドレイン\pあたえた　ダメージの　はんぶんを\nすいとって　ポケモンを\lかいふく　する　すてきな　わざ\pよろしければ\nおつかい　くださいね‥$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "エリカ『まけるのは\nくやしい　ものですわね‥\pでも　つよい　トレーナーが　いると\nしると　はげみに　なりますわ‥$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "エリカ『あら　こんにちは\pまあ　カントーの\nチャンピオン！\pまた　おあい　できて\nうれしいですわ\pきっと　すてきな\nたび　でしたのね\pチャンピオンも　ちょうせんは\nおすき　でしょう？\pもう　いちど\nしょうぶ　しませんこと？$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "エリカ『やはり　まけるのは\nくやしい　ものですわね‥\pでも　つよい　トレーナーが　いると\nしると　はげみに　なりますわ‥$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "おんなのこ　だけの　ジムって\nめずらしい　でしょ？$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "もう　いやっ！$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "ちょっと　ゆだん\nした　だけよ！$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "しょうぶ？　ちょっと\nこわいけど　いいわ！$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "え　もう　おわり？$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "わあ　バッジ　いっぱい！\nかてない　わけだわ！$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "みていたのは　おはな？\nそれとも　わたし？$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "しゃくに　さわるわ！$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "どうしたら　エリカさん\nみたいな　おしとやかな\lひとに　なれるかしら？$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "エリカさんに　おそわった\nわざを　みせて　あげる！$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "ああ‥　まけちゃった‥$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "エリカさんが　かたきを\nうって　くれるもん！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "エリカさんは　わたしたちが\nまもるの！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "かてなかった‥$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "エリカさんは　もっと\nもっと　つよいよ！$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
	.string "タマムシ　ポケモンジム\nリーダー　エリカ\pかった　トレーナー\nグリーン　レッド$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "タマムシ　ポケモンジム\nリーダー　エリカ\pかった　トレーナー\nグリーン　レッド　{PLAYER}$"
