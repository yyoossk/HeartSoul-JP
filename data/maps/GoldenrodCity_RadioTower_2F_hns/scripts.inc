GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "ブエナ『え？　きょうの\nあいことば？\lもちろん　たすけて　よ！$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "ラジオは　どこでも\nきけるよ　きいてね！$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "ここから　さきは\nかんけいしゃ　いがい\lたちいり　きんし　です$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "ラジオの　こもりうたで\nポケモンが　ねむっちゃう\lことも　あるのよ$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "どうして　ラジオとうを\nのっとったり　するの？$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "プリン『プリィ‥$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "わるいが　ここから　さきは\nかんけいしゃ　いがい\lとおせない\pまえは　こんな　こと\nなかったのに\pきょくちょうの\nようすが　へんなんだ‥$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "どこでも　じゆうに\nみて　いって　くれ\pきょくちょうも　もとの\nやさしい　ひとに\lもどったよ$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "3ねんまえ　ロケットだんは\nかいさんに　おいこまれた\pだが　ここで\nふっかつ　するのだ！$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "ぐわっ！　なまいきな！$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "ふっかつの　けいかくを\nじゃまは　させないぞ！$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "おれたちは　ポケモンを\nりようする　ロケットだん！\pわるい　ことが\nだいすきさ！　こわいか？$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "ヒーロー　きどりか？$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "いつも　わるい　わけじゃない\nすきな　ことを　してる\lだけだ$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "おいおい！\nじゃまを　するな！$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "ぐわー　まいった$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "かんぶたちが　ここを\nのっとろうと　している\pなにか　おおきな　けいかくが\nあるらしい　なんだろうな？$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "あははは！\pつまらない！　ここを\nのっとるのは　かんたん\lすぎたわ！\pさあ　たのしませて\nちょうだい！$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "あ　あなた　なにもの？$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "まけた　ことは\nわすれないわよ！$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "ブエナ『わたしの　あいことば\nショーを　きいてね！\pきょうの　あいことばが\nわかるわよ！$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "ブエナ『はーい！\pきょうの　あいことば\nわかる？\pよし！　どれかな？$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "ブエナ『せいかい！\pしょうひんの　{STR_VAR_1}を\nどうぞ！$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "ブエナ『ブブー！　ざんねん！\pまた　あした　ちょうせん\nしてね！$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "ブエナ『こたえないの？\nわかったら　またきてね！$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "ブエナ『きょうは　もう\nこたえた　でしょ！\pまた　あした\nきいてね！$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "ブエナ『せいかい　だけど\nバッグが　いっぱいね！\pかたづけたら　また\nはなしかけてね！$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2F　えいぎょうぶ$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "オーキドはかせの　ポケモンこうざ\pだいにんきの　ばんぐみ！$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "いつでも　どこでも　ポケモンラジオ$"
