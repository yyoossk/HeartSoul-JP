ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "やあ　トレーナーさん！\nすてきな　えがお　だね\pぼくの　しゅみは　ポケモン\nトレーナーの　プロフィールを\lあつめる　ことなんだ$"

ProfileMan_Text_MayISeeYourProfile:
	.string "それで　どうかな？\nきみの　プロフィールを\lみせて　くれない？$"

ProfileMan_Text_EasyChatExplanation:
	.string "プロフィールは　ことばを\n4つ　くみあわせて\lつくるんだ\pれいとして　4つの　ことばで\nつくった　プロフィールを\lみせるね\pこの　4つの　ことばを\nほかの　ことばに　すきに\lいれかえて　じぶんの\lプロフィールを　つくるんだ\pつかえる　ことばは\nたくさん　あるよ\pポケモン　せいかつ　しゅみ\nなどの　グループに　わかれて\lいるから　さがしやすいよ\pまず　グループを　えらぶと\nことばの　リストが　でる\pそこから　つかいたい\nことばを　えらぶんだ\pのこりの　ことばも　おなじ\nように　えらべば　きみだけの\lプロフィールの　できあがり$"

ProfileMan_Text_LetsSeeItThen:
	.string "やった！　ありがとう！\nじゃあ　みせて！$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "え　ほんとに？\pきみ　みたいな　ひとなら\nすてきな　プロフィール\lだろうに‥$"

ProfileMan_Text_NotIntoItRightNow:
	.string "あれ？　いまは　そんな\nきぶんじゃ　ない？\pまあ　いつでも　いいよ！$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "やあ　トレーナーさん！\nすてきな　えがお　だね$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "あたらしい　プロフィールを\nみせて　くれない？$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "やった！　ありがとう！\pまえに　みせて　もらった\nのより　もっと　いいと\lいいな$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "いまの　プロフィールが\nきに　いってるんだね\pむりも　ない　いまの\nままでも　すてきな\lプロフィール　だもの$"

ProfileMan_Text_FantasticProfile:
	.string "す　すばらしい！\pきみの　プロフィール\nさいこう　だよ！\lきみらしさが　よく　でてる\pこの　プロフィールを　きいたら\nだれでも　きみに\lむちゅうに　なるよ！\pありがとう！$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
