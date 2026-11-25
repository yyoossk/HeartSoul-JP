SlowpokeWell_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KJ_EventScript_JJ_Sync_WELL
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "ガンテツ『おう　{PLAYER}！\pうえの　みはりは　わしが\nどなったら　にげよった\pじゃが　わしは　いどに\nおちて　しもうた\pこしを　うって\nうごけんのじゃ\pくそっ！　げんき　なら\nわしの　ポケモンで\lこらしめて　やるのに‥\pしかたない\p{PLAYER}！　わしの　かわりに\nこんじょうを　みせて\lやれ！$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "ガンテツ『ようやった\n{PLAYER}！\pロケットだんは\nにげて　いったぞ\pわしの　こしも　なおった\nここから　でよう$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "くそっ！　うえで　みはって\nいたら　へんな　じじいに\lどなられた\pびっくり　して\nここに　おちちまった\pおまえで　うさばらし\nしてやる！$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "ぐわー！　きょうは\nついてない！$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "ああ　ヤドンの　しっぽを\nきって　うってるさ\pすべては　もうけの　ため\pそうさ！　おれたちは\nロケットだん　かねの　ためなら\lなんでも　するぜ！$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "なんの　ようだ？\pしごとの　じゃまを　するなら\nようしゃ　しないぞ！$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "きょうは　まあまあ　だが\nつぎは　こうは　いかんぞ！$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "そう　ロケットだんは\n3ねんまえに　かいさん　した\p"
	.string "おまえの　せいでな　{PLAYER}！\p"
	.string "ボスは　すがたを\nけした\p"
	.string "だが　われわれは　うらで\nかつどうを　つづけて　きた！\p"
	.string "こんどは　おまえ　ひとりに\nじゃま　される\lわれわれでは　ないぞ\p"
	.string "これから　おこる　ことを\nせいぜい　おそれる\lことだな！$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "ひゃっひゃっひゃ！\nヤドンのシッポを　とるのを\lやめろ　だと？\pばかを　いうな！\nいうことを　きいたら\lロケットだんの　なが　すたる！$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "ひゃっ‥\nつよすぎる‥$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "かねは　ひつよう　だけど\nヤドンのシッポを　うる\lなんてな‥\pしたっぱは　つらいよ！$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "しっぽを　とるのを\nやめろ？\pやれる　もんなら　わたしたち\nぜんいんを　たおして　みなさい！$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "この　くそがき！$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "ヤドンの　しっぽは\nすぐ　はえて　くるのよ！\pうって　なにが\nわるいの？$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "しっぽを　きられた\nヤドンだ‥\pん？　メールを　もってる\nよみますか？$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER}は　メールを\nよんだ\pおじいちゃんと　ヤドンと\nいいこで　るすばん\lしていてね\pパパより$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "しっぽを　きられた\nヤドンだ‥$"
