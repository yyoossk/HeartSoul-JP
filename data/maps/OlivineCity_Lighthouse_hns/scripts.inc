OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "この　とうだいでは\nトレーナーが　しゅぎょう\lしている\pなかで　まちかまえて　いるから\nのぼるのは　たいへんだぞ$"

OlivineLighthouse_Text_1FPokefanF:
	.string "むかしは　ポケモンが　よるの\nアサギの　うみを　てらして\lいたの\pとうだいは　その　けだかい\nポケモンを　たたえて\lたてられたのよ$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "うみの　おとこは　いつでも\nしょうぶに　うえてるぜ！$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "うぐっ！\nまけた！$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "すごい　ちからだ！\nおれと　うみに　でないか？$"

OlivineLighthouse_Text_HueyRegister:
	.string "すごい　ちからだ！\nおれと　うみに　でないか？$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "うみの　おとこは　いつでも\nしょうぶに　うえてるぜ！$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "うぐっ！\nまけた！$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "すごい　ちからだ！\nおれと　うみに　でないか？$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "む？　ここは　あそび\nばでは　ないぞ$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "おお！　ほんきの\nようだな$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "うえには　とうだいを\nてらす　ポケモンが　いる\pだが　いまは　びょうきで\nふつうの　ほうほうでは\lなおらない　らしい$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "なにしに　きた？\nけんぶつ　なら\lかえって　くれ！$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "きみも　びょうきの　ポケモンを\nしんぱい　してるんだね‥$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "どうやって　のぼるんだ？\pびょうきの　ポケモンに\nあいたいのに　のぼれない‥$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "ふなのりは　やさしくて\nつよい　きみは　どうだ？$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "きみは　やさしくて\nつよい‥$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "アサギに　もどる　たびに\nジムに　よるんだ\pいつのまにか　ジムリーダーの\nポケモンの　タイプが\lかわってたよ$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "せかいを　たびして　ポケモンを\nきたえて　いる\lきみと　たたかいたい$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "‥はあ‥　もっと\nきたえねば‥$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "ミカンは　むかし　イワークの\nような　いわタイプの\lポケモンを　つかって　いた$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "ミカンさんは　ここの　ポケモンが\nしんぱいで　たまらないんだ\pさいきんは　わらいも\nしない$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "おれも　わらえないよ‥$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "びょうき　と　いえば\nタンバに　いい\lくすりやが　あるらしい$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "ミカンさんは　この　まちの\nジムリーダー\pわたしが　つれもどすの\pじゃまは　させないわ！$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "きゃあ！\nわたしの　ポケモン！$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "そうよね　じぶんの　ポケモンが\nけがを　したら\lだれだって　しんぱいよね\pミカンさんが　ジムに　もどれる\nように　ここの　ポケモンの\lために　いのるわ$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "ミカンさんと　たたかい\nたかったけど　いまは\lそれどころ　じゃない\pじゃあ　きみは　どうだ？$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "うわわ！\nかなわない！$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "A GYM LEADER isn't just about being\n"
	.string "strong.\p"
	.string "A LEADER also needs to be\n"
	.string "compassionate.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "We're pretty high up here. My bird\n"
	.string "POKéMON are in prime form.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Oops… They crashed…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "My POKéMON learned how to use FLY in\n"
	.string "CIANWOOD.\p"
	.string "Well, since I'm a loser, I'll FLY\n"
	.string "across the sea…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE: …This POKéMON always kept\n"
	.string "the sea lit at night.\p"
	.string "…But it suddenly got sick… It's\n"
	.string "gasping for air…\p"
	.string "…I understand that there is a\n"
	.string "wonderful PHARMACY in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "There is a wonderful PHARMACY\n"
	.string "in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…\p"
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE: …Will that medicine cure\n"
	.string "AMPHY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} handed the SECRET POTION to\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE: …Um, please don't be\n"
	.string "offended…\p"
	.string "…AMPHY will not take anything from\n"
	.string "anyone but me…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE: …\p"
	.string "AMPHY, how are you feeling?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE: …Oh, I'm so relieved…\p"
	.string "This is just so wonderful…\p"
	.string "Thank you so very, very much.\p"
	.string "…I will return to the GYM…\p"
	.string "I'll also warn you, STEEL types\n"
	.string "are powerful.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE: …I see…\n"
	.string "…AMPHY, hang on!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Its breathing is terribly\n"
	.string "labored…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: Palu! Palulu!$"


