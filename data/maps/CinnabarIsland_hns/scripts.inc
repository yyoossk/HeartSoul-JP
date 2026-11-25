CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
	.string "カツラ『グレンジムを　たてなおす\nひまで　わしは　ぜったい\lあきらめんぞ！\pそれまでは　かくとうどうじょうに\nおるからな$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "{PLAYER}！？\nひさしぶり　じゃねえか！\pジョウトに　いってたんだってな\n3ねんぶり　か‥\pおれは　いま　トキワの\nジムリーダー　やってるぜ\pで　なんの　ようだ？\nおれに　ちょうせん　でも\lしにきたのか？\p‥いいたくないけど　いまは\nしょうぶする　きぶんじゃ\lないんだ\pまわりを　よく　みてみろよ‥\pかざんが　ふんかしたら\nまち　ひとつが　あっというまに\lきえちまう\pポケモンで　かったり　まけたり\nしてても　しぜんが　ちょっと\lうごけば　いっしゅんで　まけさ\p‥\pそういう　もんさ‥\pでも　おれは　やっぱり\nトレーナーだ\pつよい　あいてを　みると\nしょうぶ　したくなる\pおれと　しょうぶ　したいなら\nまず　バッジを　15こ　あつめな\pそしたら　あいてを　してやる$"

CinnabarIsland_Text_Blue:
	.string "{PLAYER}！？\nひさしぶり　じゃねえか！\pジョウトに　いってたんだってな\n3ねんぶり　か‥\pおれは　いま　トキワの\nジムリーダー　やってるぜ\pで　なんの　ようだ？\nおれに　ちょうせん　でも\lしにきたのか？\p‥いいたくないけど　いまは\nしょうぶする　きぶんじゃ\lないんだ\pまわりを　よく　みてみろよ‥\pかざんが　ふんかしたら\nまち　ひとつが　あっというまに\lきえちまう\pポケモンで　かったり　まけたり\nしてても　しぜんが　ちょっと\lうごけば　いっしゅんで　まけさ\p‥\pそういう　もんさ‥\pでも　おれは　やっぱり\nトレーナーだ\pつよい　あいてを　みると\nしょうぶ　したくなる\pおれと　しょうぶ　したいなら\nトキワジムに　こい\pそしたら　あいてを　してやる$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "はりがみが　ある‥\pグレンジムは　ふたごじまに\nうつりました\pカツラ$"

CinnabarIsland_Text_Sign:
	.string "グレンタウン\pグレンは　くれない\nもえる　とうしの　いろ$"

