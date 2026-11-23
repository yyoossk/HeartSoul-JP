SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
	.string "グレン　ポケモンジム\nリーダー　カツラ\pかった　トレーナー\nグリーン　レッド$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
	.string "グレン　ポケモンジム\nリーダー　カツラ\pかった　トレーナー\nグリーン　レッド　{PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "これも　もって　いけ！$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "その　わざマシンは\nすごいぞ　オーバーヒートじゃ！\pすさまじい　ねつで　あいてを\nこがすが　そのあと\lとくこうが　さがる\pつぎの　あいてが　やけどなおしを\nもってると　いいのう！\lうおおーっ！$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "カツラ『うおおーっ！\pグレンの　ジムが\nやけて　しもうた\pかざんの　せいで　わしと\nほのおポケモンは\lいえなし　じゃ\pうおおーっ！\pじゃが　この　どうくつで\nジムリーダーに\lふっかつ　したぞ！\pわしに　かてたら\nバッジを　やろう\pはっ！　やけどなおしを\nよういして　おけい！$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "カツラ『みごと！\nもえつきた‥\pクリムゾンバッジを\nやろう！$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER}は\nクリムゾンバッジを　もらった$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "カツラ『こんかいは　まけたが\nつぎは　かつぞ\pグレンジムを　たてなおしたら\nさいせん　じゃ$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "カツラ『わしの　ほのおポケモンは\nもっと　つよく　なるぞ\pみて　おれ！$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "カツラ『おおっ！\pカントーの　チャンピオンに\nなったのか！\pもえるのう！\pうでは　ちょういっきゅうじゃ\pわしは　いつでも\nしょうぶ　だいかんげいじゃ\pもう　いちど\nしょうぶ　するか？$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "カツラ『きみの　うでは\nまさに　ほのおじゃ！\pわしの　まもりを\nもやしつくした$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "よう！\p‥あれ？　もう\nおわったのか？\pわるい　わるい！\pグレンジムが　なくなったから\nどこに　いるか\lわからなくてさ\pでも　アドバイス\nなしでも　じゅうぶん　つよいな\lかつと　おもってたよ！$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "ジムリーダーが　いれば\nポケモンジムは　どこでも\lできるんだ\pたてもの　なんて\nいらないのさ$"
