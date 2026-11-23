GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER}！\nこんな　とこで　あうなんて！\pミルタンクの　ための\nかいものに　きたんよ\pまた　しょうぶ　したいなら\nかくとうどうじょうに　きてな！$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "ポケモン　あつめてるの！\n{STR_VAR_1}　もってない？\pわたしの　{STR_VAR_2}と\nこうかん　しない？$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "やったー！\n{STR_VAR_1}　ゲット！\p{STR_VAR_2}\nげんきでね！$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "えー　ちがうよ\nそれ　{STR_VAR_1}じゃ　ないもん$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "こうかん　しないの？\nざんねん‥$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "ねえ　まえの\nワンリキー　げんき？$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
	.string "ラッキーチャンネル\nきいてる？\pあてたい　なら　たくさんの\nひとと　こうかん　して\lいろんな　IDを　あつめると\lいいんだって\pでも　いまは　むかしほど\nこうかん　できないのよね$"

GoldenrodDeptStore_Text_6FSuperNerd:
	.string "つかれたら　じどうはんばいきの\nのみものを　どうぞ\pポケモンも\nよろこぶよ$"

GoldenrodDeptStore_Text_6FDirectory:
	.string "かいものの　ひとやすみに！\p6F　いこいの　ひろば$"
