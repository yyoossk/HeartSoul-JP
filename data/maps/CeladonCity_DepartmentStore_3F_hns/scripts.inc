CeladonCity_DepartmentStore_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonDept3_EventScript_ClerkPostGame
	pokemart CeladonDept3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

@ HnS JP: after the Hall of Fame, the TMs found in Kanto are sold too
CeladonDept3_EventScript_ClerkPostGame::
	pokemart CeladonDept3_PokemartPostGame
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonDept3_PokemartPostGame:
	.2byte ITEM_TM_WATER_PULSE
	.2byte ITEM_TM_TOXIC
	.2byte ITEM_TM_BULK_UP
	.2byte ITEM_TM_ICE_BEAM
	.2byte ITEM_TM_GIGA_DRAIN
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_FRUSTRATION
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_EARTHQUAKE
	.2byte ITEM_TM_PSYCHIC
	.2byte ITEM_TM_BRICK_BREAK
	.2byte ITEM_TM_SHOCK_WAVE
	.2byte ITEM_TM_FLAMETHROWER
	.2byte ITEM_TM_AERIAL_ACE
	.2byte ITEM_TM_TORMENT
	.2byte ITEM_TM_FACADE
	.2byte ITEM_TM_STEEL_WING
	.2byte ITEM_TM_SKILL_SWAP
	.2byte ITEM_TM_OVERHEAT
	.2byte ITEM_TM_ENERGY_BALL
	.2byte ITEM_TM_BRINE
	.2byte ITEM_TM_FLING
	.2byte ITEM_TM_ENDURE
	.2byte ITEM_TM_WILL_O_WISP
	.2byte ITEM_TM_SILVER_WIND
	.2byte ITEM_TM_EXPLOSION
	.2byte ITEM_TM_RECYCLE
	.2byte ITEM_TM_GIGA_IMPACT
	.2byte ITEM_TM_ROCK_POLISH
	.2byte ITEM_TM_STONE_EDGE
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_THUNDER_WAVE
	.2byte ITEM_TM_GYRO_BALL
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_PSYCH_UP
	.2byte ITEM_TM_CAPTIVATE
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_ROCK_SLIDE
	.2byte ITEM_TM_X_SCISSOR
	.2byte ITEM_TM_SLEEP_TALK
	.2byte ITEM_TM_POISON_JAB
	.2byte ITEM_TM_DREAM_EATER
	.2byte ITEM_TM_GRASS_KNOT
	.2byte ITEM_TM_FLASH_CANNON
	.2byte ITEM_TM_TRICK_ROOM
	pokemartlistend

	.align 2
CeladonDept3_Pokemart:
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_CAPTIVATE
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_BRINE
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_GYRO_BALL
	.2byte ITEM_TM_DREAM_EATER
	.2byte ITEM_TM_GIGA_IMPACT
	.2byte ITEM_TM_ENDURE
	pokemartlistend

CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "この　わざマシン　どの\nポケモンに　つかおうかな‥$"

CeladonDeptStore3F_Text_GameboyKid1:
	.string "しまった！　アップグレードを\nもたせた　まま　ポケモンを\lこうかん　しちゃった$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "やった！　やっと\nポリゴンが　てに　はいる！\pスロットが　へただから\nコインが　たまらなくて‥\p‥あれ？\pこうかん　した　ポリゴンが\nべつの　ポケモンに\lなっちゃった！$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "わざマシンショップには\nめずらしい　わざも　あるよ$"

CeladonDeptStore3F_Text_Directory:
	.string "3F　わざマシンショップ\pポケモンを　つよく　しよう！$"

