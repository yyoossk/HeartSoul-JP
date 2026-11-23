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
	pokemart CeladonDept3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

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

