EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "エンジュシティ　ポケモンジム$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "エンジュシティ　ポケモンジム\pマツバ　にんてい　トレーナー\n{PLAYER}$"

MortyIntroText:
	.string "よく　きたね\pここ　エンジュでは　むかしから\nポケモンが　あがめられて　きた\pほんとうの　トレーナーの　まえには\nにじいろの　ポケモンが\lまいおりると　いわれている\pぼくは　その　いいつたえを\nしんじて　ここで　ひそかに\lしゅぎょうを　してきた\pおかげで　ひとに　みえない\nものが　みえる　ように　なった\pあと　すこし‥\pあと　すこしで　にじいろの\nポケモンに　であう　みらいが\lみえそう　なんだ\pきみは　その　ために\nてつだって　もらうよ！$"

MortyWinLossText:
	.string "ぼくは　まだ\nみじゅくだ‥\pわかった　この　バッジは\nきみの　ものだ$"

Text_ReceivedFogBadge:
	.string "{PLAYER}は\nファントムバッジを　もらった$"

MortyText_FogBadgeSpeech:
	.string "ファントムバッジが　あると\nレベル50までの　ポケモンが\lいうことを　きく\pそれに　なみのりを　おぼえた\nポケモンが　いつでも\lなみのりを　つかえる\pこれも　うけとって　ほしい$"

MortyText_ShadowBallSpeech:
	.string "それは　シャドーボール\nダメージを　あたえ　とくぼうを\lさげる　ことが　ある\pきみに　あうなら\nつかって　くれ$"

MortyFightDoneText:
	.string "そうか‥\pきみは　とおくまで\nたびを　して　きたんだね\pぼくより　たくさんの\nものを　みてきた\pそれが　うらやましいよ‥$"

MortyRematchText:
	.string "やあ　ジョウトの\nチャンピオン！　よく　きたね\pきみの　つよさは　わかってる\nでも　あれから　せいちょう\lしたかな？\pぼくも　あれから　ゴーストタイプと\nしゅぎょうを　つづけて　きた\pまた　かげを　のりこえられるか\nみせて　もらおう\pもう　いちど　しょうぶ\nするかい？$"

Morty_RematchDefeatText:
	.string "ぼくは　まだ\nみじゅくだ‥\pきみは　ぼくより　たくさんの\nものを　みてきた\pそれが　うらやましいよ‥$"

SageJeffreySeenText:
	.string "はるを　ポケモンと\nすごした\pそして　なつ　あき　ふゆ‥\pまた　はるが　きた\nながい　つきあい　じゃ$"

SageJeffreyBeatenText:
	.string "かちも　まけも\nどちらも　しっておる$"

SageJeffreyAfterBattleText:
	.string "ポケモンは　どこから\nきたのじゃろう？$"

SagePingSeenText:
	.string "われらの　ポケモンに\nダメージを　あたえられるかな？$"

SagePingBeatenText:
	.string "おお！　みごと！$"

SagePingAfterBattleText:
	.string "われらは　ゴーストタイプの\nポケモンを　つかう\pノーマルタイプの　わざは\nきかんのじゃ！$"

MediumMarthaSeenText:
	.string "かつのは　わたしよ！$"

MediumMarthaBeatenText:
	.string "ま‥　ま‥　まけた！$"

MediumMarthaAfterBattleText:
	.string "いちばん　かちたいと\nおもった　ものが\lかつのよ！$"

MediumGraceSeenText:
	.string "くらい　ろうかに\nまよって　いるの？\lヒントが　ほしいなら\lわたしに　かちなさい！$"

MediumGraceBeatenText:
	.string "な‥　なに？$"

MediumGraceAfterBattleText:
	.string "いいわ　かげの　ひみつを\nおしえて　あげる\pみちは　めの　まえに\nあるのよ！$"

EcruteakCity_GymGuideText:
	.string "よう　みらいの　チャンピオン！\nもう　すぐ　はんぶんだ！\pここの　トレーナーは　ゴーストと\nあくタイプの　ポケモンを　つかう\pマツバは　ゴーストタイプの\nつかいてだが　ふしぎな\lシカには　きを　つけろ\pへんな　あくむを　みせると\nいわれているぞ‥$"

EcruteakCity_GymGuideWinText:
	.string "ふう　{PLAYER}　よく\nやったな！\pおれは　こわくて　すみで\nふるえてたよ！$"

EcruteakCity_GymClosedText:
	.string "ジムリーダーの　マツバは\nいま　るす　です\pすみませんが\nおひきとり　ください\pほっほっほ$"
