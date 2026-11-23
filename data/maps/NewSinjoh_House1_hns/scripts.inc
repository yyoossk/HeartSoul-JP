NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
	.string "やあ　トレーナー！\pワカバタウンから\nはるばる　きたのかい？\pあちこち　たびを　して　きた\nきみに　たのみが　あるんだ\lぼくの　せかいで　いちばん\lすきな　ポケモンは\lまぼろしの　セレビィ　なんだ\pもし　もって　いたら\nみせて　くれないか？$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
	.string "すてきな　ポケモン\nだけど　ぼくが\lさがしてるのとは\lちがうんだ‥$"

NewSinjoh_House1_OffersWooper:
	.string "それだ！　ほんものの\nいきた　セレビィだ！！\pきたの　はてまで　みせに\nきて　くれて　ほんとうに\lありがとう\pかのじょが　とおくの　ちほうへ\nりょこう　した　ときに\lつかまえすぎた　ポケモンが\lいるんだ\pおれいに　この　とくべつな\nウパーを　うけとって\l{PLAYER}$"

NewSinjoh_House1_Text_Decline:
	.string "ざんねん\nみたかったなあ$"

NewSinjoh_House1_Text_TakeCareOfWooper:
	.string "その　ウパーを\nだいじに　してね？$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
	.string "また　あえて　うれしいよ\n{PLAYER}\pあの　ウパーは\nげんき　かい？$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
	.string "パソコンゲームや\nまんがで　ぎっしりの\lほんだなだ！$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
	.string "ブイ　ブイ？$"
