FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_KJ_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_KJ_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster_Kj::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign_Kj::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign_Kj, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign_Kj::
	lockall
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign_Kj
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_KJ_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
	.string "サファリ　ゲーム　もう　やった？\n"
	.string "あそこでしか　とれない\l"
	.string "めずらしい　ポケモンも　いるよ！$"

FuchsiaCity_Text_SafariZoneZooInFront::
	.string "サファリ　ゾーンは\n"
	.string "いりぐち　ふきんは　どうぶつえんで\p"
	.string "おくに　いくと　ポケモンが\n"
	.string "とりほうだいの　サファリ　ゲームじゃ$"

FuchsiaCity_Text_WheresSara::
	.string "コージ“おかしいな？　アツコと\n"
	.string "ポケモンとりで　まちあわせって…\l"
	.string "とりポケモンが　みつからない！$"

FuchsiaCity_Text_ItemBallInThere::
	.string "あの　アイテム　ボール\n"
	.string "ほしいって　おもった？\l"
	.string "…　…　…　ぼくもさ！\l"
	.string "…　え　あれ　いきものなの？$"

FuchsiaCity_Text_CitySign::
	.string "ここは　セキチク　シティ\n"
	.string "セキチクは　ピンク　はなやかな　いろ$"

FuchsiaCity_Text_SafariZoneSign::
	.string "いろんな　ポケモン　いっぱい！\n"
	.string "…　サファリ　ゾーンに　ようこそ！$"

FuchsiaCity_Text_SafariGameSign::
	.string "めいぶつ！　サファリ　ゲーム！\n"
	.string "…　…　ポケモン　とりほうだい！$"

FuchsiaCity_Text_WardensHomeSign::
	.string "サファリ　ゾーン\n"
	.string "えんちょうの　いえ$"

FuchsiaCity_Text_SafariZoneOfficeSign_Kj::
	.string "いろんな　ポケモン　いっぱい！\n"
	.string "サファリ　ゾーンに　ようこそ！\n"
	.string "サファリ　ゾーン　じむ　きょく$"

FuchsiaCity_Text_GymSign_Kj::
	.string "セキチク　シティ　ポケモン　ジム\n"
	.string "リーダー　キョウ\l"
	.string "どくの　ことなら　なんでも　ござれ$"

FuchsiaCity_Text_ChanseySign::
	.string "なまえ　ラッキー\n"
	.string "つかまえたら　スーパー　ラッキー！$"

FuchsiaCity_Text_VoltorbSign::
	.string "なまえ　ビリリダマ\n"
	.string "モンスター　ボールに　そっくり！$"

FuchsiaCity_Text_KangaskhanSign::
	.string "なまえ　ガルーラ\n"
	.string "なかの　よい　おやこ　ポケモン！\p"
	.string "おなかに　こどもを　いれて\n"
	.string "そだてて　います！$"

FuchsiaCity_Text_SlowpokeSign::
	.string "なまえ　ヤドン\n"
	.string "ひとなつこい　せいかくが　にんき！\l"
	.string "うごきが　のろい　ポケモン！$"

FuchsiaCity_Text_LaprasSign::
	.string "なまえ　ラプラス\n"
	.string "シー　ドラゴン　とも　よばれる\l"
	.string "うみの　おうじゃ　です！$"

FuchsiaCity_Text_OmanyteSign::
	.string "なまえ　オムナイト\n"
	.string "カセキ　から　いき　かえった\l"
	.string "めずらしい　ポケモン！$"

FuchsiaCity_Text_KabutoSign::
	.string "なまえ　カブト\n"
	.string "カセキ　から　いき　かえった\l"
	.string "めずらしい　ポケモン！$"

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
	.string "……$"

Text_SubstituteTeach::
	.string "いいな　いいな\p"
	.string "ガルーラの　こどもの\n"
	.string "みがわりに　なって\l"
	.string "あの　おなかの　ふくろに\l"
	.string "はいって　みたいな！\l"
	.string "みがわり　つかえる　のは\l"
	.string "ポケモンだけ　だけどね…\p"
	.string "みがわり　おしえて　あげようか？$"

Text_SubstituteDeclined::
	.string "みがわり　おもしろそう　なのにー$"

Text_SubstituteWhichMon::
	.string "どの　ポケモンが　いい？$"

Text_SubstituteTaught::
	.string "でも　やっぱり\n"
	.string "ガルーラの　ふくろに\l"
	.string "はいって　みたーい！$"

FuchsiaCity_Text_MyFatherIsGymLeader::
	.string "ちちうえは　このまちの\n"
	.string "ジムリーダー　なんだ！\p"
	.string "あたいも　ちちうえ　みたいに\n"
	.string "うまく　どくポケモンを\l"
	.string "つかえる　ように　なるんだ！$"

