GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
	.string "こんにちは\nあら　あなたの　ポケモン‥$"

GoldenrodDeptStore_Text_5FReceptionistWait:
	.string "あら　その　わざマシンは\nもう　あげたわよ！$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "うーん‥\nわるくは　ないけど\lよくも　ないわね\pトレーナーの　あなたが\nもっと　がんばらなきゃ$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
	.string "あなたに　とても\nなついて　いるわ\pこの　わざは　あなたたちに\nぴったりよ$"

GoldenrodDeptStore_Text_5FLass:
	.string "ひるまに　ポケモンを　みて\nくれる　おねえさんが\lくるの\pわざマシンも\nくれるのよ！$"

GoldenrodDeptStore_Text_5FPokefanM:
	.string "こうかんで　もらった\nポケモンの　なまえは\lかえられない\pなまえには　おやの\nおもいが　こもって\lいるからね$"

GoldenrodDeptStore_Text_Girl:
	.string "おねえさんに　おんがえしを\nもらったの！\pわたしの　ポケモン\nなついてるのね！$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, GoldenrodDeptStore5_EventScript_ClerkPostGame
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

@ HnS JP: after the Hall of Fame, the TMs found in Johto are sold too
GoldenrodDeptStore5_EventScript_ClerkPostGame::
	pokemart GoldenrodDeptStore5_PokemartPostGame
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_PokemartPostGame:
	.2byte ITEM_TM_FOCUS_PUNCH
	.2byte ITEM_TM_DRAGON_CLAW
	.2byte ITEM_TM_CALM_MIND
	.2byte ITEM_TM_ROAR
	.2byte ITEM_TM_HAIL
	.2byte ITEM_TM_BULLET_SEED
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SUNNY_DAY
	.2byte ITEM_TM_TAUNT
	.2byte ITEM_TM_ICE_BEAM
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_RAIN_DANCE
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_IRON_TAIL
	.2byte ITEM_TM_THUNDERBOLT
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_RETURN
	.2byte ITEM_TM_DIG
	.2byte ITEM_TM_SHADOW_BALL
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_FLAMETHROWER
	.2byte ITEM_TM_SLUDGE_BOMB
	.2byte ITEM_TM_SANDSTORM
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_ROCK_TOMB
	.2byte ITEM_TM_AERIAL_ACE
	.2byte ITEM_TM_FACADE
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_TM_REST
	.2byte ITEM_TM_ATTRACT
	.2byte ITEM_TM_THIEF
	.2byte ITEM_TM_SNATCH
	.2byte ITEM_TM_ROOST
	.2byte ITEM_TM_FOCUS_BLAST
	.2byte ITEM_TM_FALSE_SWIPE
	.2byte ITEM_TM_CHARGE_BEAM
	.2byte ITEM_TM_DRAGON_PULSE
	.2byte ITEM_TM_DRAIN_PUNCH
	.2byte ITEM_TM_EMBARGO
	.2byte ITEM_TM_SHADOW_CLAW
	.2byte ITEM_TM_PAYBACK
	.2byte ITEM_TM_ROCK_CLIMB
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_SWORDS_DANCE
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_SWAGGER
	.2byte ITEM_TM_PLUCK
	.2byte ITEM_TM_U_TURN
	.2byte ITEM_TM_SUBSTITUTE
	pokemartlistend

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
	.string "ポケモンを　カスタマイズ\p5F　わざマシンコーナー$"

@ HnS JP: after the Hall of Fame, this tutor teaches every tutor move
GoldenrodDeptStore5_EventScript_AllMovesTutor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, GoldenrodDeptStore5_EventScript_AllMovesTutorNotYet
	setflag P_FLAG_TUTOR_MOVES
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorIntro, MSGBOX_DEFAULT
GoldenrodDeptStore5_EventScript_AllMovesTutorChoose::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_TUTOR_MOVES
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodDeptStore5_EventScript_AllMovesTutorBye
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, GoldenrodDeptStore5_EventScript_AllMovesTutorEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, GoldenrodDeptStore5_EventScript_AllMovesTutorNone
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
GoldenrodDeptStore5_EventScript_AllMovesTutorAgain::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodDeptStore5_EventScript_AllMovesTutorChoose
GoldenrodDeptStore5_EventScript_AllMovesTutorBye::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorBye, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_EventScript_AllMovesTutorEgg::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorEgg, MSGBOX_DEFAULT
	goto GoldenrodDeptStore5_EventScript_AllMovesTutorAgain
	end

GoldenrodDeptStore5_EventScript_AllMovesTutorNone::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorNone, MSGBOX_DEFAULT
	goto GoldenrodDeptStore5_EventScript_AllMovesTutorAgain
	end

GoldenrodDeptStore5_EventScript_AllMovesTutorNotYet::
	msgbox GoldenrodDeptStore5_Text_AllMovesTutorNotYet, MSGBOX_DEFAULT
	release
	end

GoldenrodDeptStore5_Text_AllMovesTutorNotYet:
	.string "わしは　あちこちの　わざおしえの\nわざを　ぜんぶ　しっておる\pでんどういりを　はたした\nトレーナーにだけ　おしえて　やろう$"

GoldenrodDeptStore5_Text_AllMovesTutorIntro:
	.string "おお　でんどういりを　はたしたか！\pわしは　あちこちの　わざおしえの\nわざを　ぜんぶ　しっておる\pなんどでも　ただで\nおしえて　やろう！$"

GoldenrodDeptStore5_Text_AllMovesTutorWhichMon:
	.string "どの　ポケモンに　おしえる？$"

GoldenrodDeptStore5_Text_AllMovesTutorWhichMove:
	.string "どの　わざを　おしえようか？$"

GoldenrodDeptStore5_Text_AllMovesTutorAgain:
	.string "ほかにも　おしえて　ほしいかね？$"

GoldenrodDeptStore5_Text_AllMovesTutorBye:
	.string "また　いつでも　きなさい$"

GoldenrodDeptStore5_Text_AllMovesTutorEgg:
	.string "タマゴには　おしえられんよ$"

GoldenrodDeptStore5_Text_AllMovesTutorNone:
	.string "その　ポケモンに　おしえられる\nわざは　もう　ないのう$"
