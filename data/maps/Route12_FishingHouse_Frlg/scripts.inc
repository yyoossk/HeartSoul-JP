Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_KJ_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_KJ_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_KJ_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_KJ_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_KJ_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_KJ_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "わしは\n"
	.string "つりおやじの　おとうと　じゃ！\p"
	.string "もう　たまらん　ほど\n"
	.string "つりが　すき　なんだが\p"
	.string "きみは　つり　すき　かな？$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "そうか！\n"
	.string "きみとは　きが　あいそうだ！\p"
	.string "これ　あげるから\n"
	.string "きみも　つり　まくりなさいよ！$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "{PLAYER}は　つりおやじから\n"
	.string "すごいつりざおを　もらった！$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "つり　こそ\n"
	.string "さいこうの　ロマン　だ！\p"
	.string "うみでも　かわでも！\p"
	.string "えんりょ　なく\n"
	.string "つりざおを　つかって　くれい！\p"
	.string "で　そのつりざおで\n"
	.string "でっかい　コイキング　つったら\l"
	.string "わしに　みせに　こないか？\p"
	.string "わしは　つりも　だいすきだが\n"
	.string "でっかい　コイキングを　みるのも\l"
	.string "たまらんほど　すきなんじゃ！$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "なんじゃ…　がっかりだ$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "やー　{PLAYER}{KUN}！\p"
	.string "すごいつりざおは\n"
	.string "ばしょを　かえると\l"
	.string "つれる　ポケモンも　かわる！\p"
	.string "あっちこっちで\n"
	.string "つり　まくって　くれい！\p"
	.string "でっかい　コイキング\n"
	.string "みせて　くれるのも　わすれんでな！$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "やや　{PLAYER}{KUN}\n"
	.string "コイキングを　もってる　じゃないか\l"
	.string "さっそく　みせて　くれい！$"

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
	.string "………おおっ！　{STR_VAR_2}cm！\p"
	.string "キミは　つりの　ロマンの\n"
	.string "なんたるかを　わかってるな！\l"
	.string "これ　あげるから　もっていきなさい$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "さらに　いい　きろく\n"
	.string "きたいしてるぞ！$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
	.string "あれっ！　{STR_VAR_2}cm！\p"
	.string "こないだ　みたのと\n"
	.string "おなじ　おおきさ　じゃないか？$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
	.string "うーん…　{STR_VAR_2}cmだな\p"
	.string "まえの　{STR_VAR_3}cmの　ほうが\n"
	.string "おおもの　だったな$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "そ…　それは　ちょっと\n"
	.string "コイキングには　みえないなあ$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "ありゃー！\p"
	.string "いいもの　あげようと　したのに\n"
	.string "にもつが　いっぱいじゃ！$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
	.string "わしが　これまでに　みた\n"
	.string "いちばん　でかい　コイキング…\p"
	.string "{STR_VAR_3}cm$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "はりがみだ！\p"
	.string "なにかの　きろくを\n"
	.string "かきこめる　ように　なっている$"

