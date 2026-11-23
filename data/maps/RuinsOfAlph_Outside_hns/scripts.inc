RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "ヌオー『ヌオッ　ヌオッ$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "む？　それは　ずかん\nだね？　みせて　くれる？\pポケモンって　いろんな\nしゅるいが　いるね\pん？　これは　なんだ？\pこの　ポケモンは　なに？\pいせきの　かべの\nふしぎな　もじに\pそっくりだ\pあの　えが　ほんとうに\nポケモン　なら　もっと\lたくさん　いる　はずだ\pそうだ！　ずかんを\nパワーアップ　して　あげる\lついて　きて$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "なんだ？　べんきょう　ちゅうだ\nじゃまを　するな！$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "ごめん‥\nなかなか　なぞが　とけなくて\pいらいら　してたんだ‥$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "いせきは　およそ\n1500ねん　まえの　もの\pだれが　つくったのかは\nわからない\pポケモンの　ぞうに　いみが\nあるのかも　わからない\pすべてが　なぞ　なんだ‥$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "うーん‥　ここは\nふしぎな　ところだ$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "ここで　かんがえごとを\nするのが　すきなんだ$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "なぞの　いしの　へや$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "アルフのいせき\nけんがく　じゆう$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "アルフのいせき　けんきゅうじょ\pアルフのいせき\nけんきゅうの　だいいちにんしゃ$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "いせきを　たんけん　してたら\nきゅうに　へんな　けはいを\lかんじたんだ\pみんな　こわくて　にげたよ\nきみも　きを　つけてね$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "いせきには　おおきな\nひみつが　ある！\p‥と　おもう‥$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "アンノーンは　いろんな\nしゅるいが　いるから\lあんごうに　つかってるんだ$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A‥　H‥　E‥　A‥　D‥\nうーん‥\pなに？\pいま　あんごうを\nかいどく　ちゅう　なの！$"
