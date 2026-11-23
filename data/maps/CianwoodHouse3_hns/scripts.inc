CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "し　し　しょっく　だよ！\pきみぐらいの　としの　めつきの\nするどい　かみの　ながい\lやつが　きて\pおどされて　だいじな\nポケモンを　とられたんだ！\pまだ　1ぴき　のこってるけど\nまた　きたら　どうしよう？\pきみ　つよそうだね　しばらく\nぼくの　ポケモンを　あずかって\lくれない？$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "ありがとう！\pだいじに　してね！$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER}は\nポケモンを　あずかった$"

CianwoodCity_Text_ManiacPartyFull:
	.string "てもちが　いっぱい　だよ$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "そんな‥　また　あいつが\nきたら　どうしよう？$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "やあ！　ぼくの\nポケモン　げんき？$"

CianwoodCity_Text_ManiacAskReturn:
	.string "やあ！　ぼくの\nポケモン　げんき？\pもう　だいじょうぶ　そうだから\nかえして　もらえる？$"

CianwoodCity_Text_ManiacThankYou:
	.string "ありがとう！$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "あれ　ぼくの　ポケモン\nつれて　ないじゃないか$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "ぼくの　ポケモン　きみに\nなついちゃった　みたい\pよし　きみが\nもってて　いいよ\pでも　だいじに　するって\nやくそく　してね！$"

CianwoodCity_Text_ManiacRobbed:
	.string "あれ　なにか\nおかしいぞ$"

CianwoodCity_Text_ManiacRobbed2:
	.string "そんな‥　これじゃ\nとられたのと　おなじだ$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "ポケモンに　とって\nだいじに　してくれる　ひとと\lいるのが　しあわせ　なんだ$"

CianwoodCity_Text_ManiacLastMon:
	.string "ぼくが　ポケモンを\nかえして　もらったら\lきみは　なにで　たたかうの？$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER}は\nツボを　かえした$"
