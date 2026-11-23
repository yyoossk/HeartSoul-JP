TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "むむ！　むむ！\pついに　きたな！\nそう　きたのだ！\pまて！　いうな！\nひとりで　ここまで　きた\lわけは　わかって　おる！\pトレーナーヒルの　オーナーで\nある　わたしに　あいに\lきたのは‥\pわたしと　タッグを\nくみたい　からだな！\lワッフー！\p‥む？\nちがう？\pともかく　のぼって　くる\nところを　みて　いたよ\lすばらしい　たたかい！\lブラボー！$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "すばらしい　きみに\nすばらしい　おくりものと\lがんばった　ほうびの\lおかねを　あげよう！$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "おっと　もちものが\nいっぱいだ！\lあとで　とりに　きなさい！$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "おや　まてよ！\nずいぶん　すばらしく\lはやく　ついたのでは？\pなんと　みごと！　そんなに\nいそいで　わたしに\lあいに　こなくても！\pうれしいのう　うけつけの\nタイムボードを\lかきかえて　おこう！$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "だが　ううむ‥\nあまり　はやくは\lなかったな$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "つぎは　もっと　すばやく\nきて　くれると　うれしいの\pそしたら　よろこんで\nタッグを　くんで　あげよう！\pまた　あおう\nアミーゴ！$"
