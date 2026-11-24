GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "ここは　コガネジムよ！\pリーダーの　アカネは\nいま　いないの\lラジオとうに　いるかも$"

GoldenrodCity_Text_Woman:
	.string "まえは　アカネの　ジムで\nしゅぎょう　してたけど\lあの　なきごえで　あたまが\lいたく　なっちゃって$"

GoldenrodCity_Text_HikerDay:
	.string "ゲームコーナーに　はいった　ときは\nよる　だったのに‥\lおれ　どれだけ　いたんだ！？$"

GoldenrodCity_Text_HikerNight:
	.string "ゲームコーナーに　はいった　ときは\nひるま　だったのに‥\lおれ　どれだけ　いたんだ！？$"

GoldenrodCity_Text_Snubbull:
	.string "ブルー『ブルーッ！$"

GoldenrodCity_Text_MrMime:
	.string "‥‥‥‥‥‥‥‥‥‥‥‥‥‥$"

GoldenrodCity_Text_ElmName:
	.string "ウツギはかせ$"

GoldenrodCity_Text_ElmCall:
	.string "ウツギ『もしもし　{PLAYER}くん？\nタマゴは　もう　かえったかい？\pかえったら　けんきゅうじょに\nつれてきてね！　ぜひ\lみたいんだ！$"

GoldenrodCity_Text_PokefanM:
	.string "ふるくて　ギシギシいう　とうの\nかわりに　あたらしい\lラジオとうを　たてたんだ$"

GoldenrodCity_Text_Youngster1:
	.string "あたらしい　じてんしゃやが\nあるって　きいたけど\lどこにも　みつからないんだ$"

GoldenrodCity_Text_CooltrainerF1:
	.string "あの　くろい　ふくの　ひと\nロケットだんの　かっこう　してる？\pへんなの！$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "あの　くろい　ふくの　ひと\nほんとうに　ロケットだん　だったの？\lしんじられない！$"

GoldenrodCity_Text_CooltrainerF2:
	.string "コガネシティの　ラジオとうは\nまちの　シンボルなの\pいま　キャンペーンを\nやってるのよ\pクイズに　ごうかく　したら\nあたらしい　ラジオが　もらえるの$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "あら　あなたの　ポケギア\nもう　ラジオに　なってるのね！$"

GoldenrodCity_Text_Youngster2:
	.string "えへへへ‥\pデパートの　ちかで　あそんでたら\nおこられちゃった$"

GoldenrodCity_Text_Lass:
	.string "なかに　いる　ひとが　ポケモンの\nニックネームを　うらなって　くれるの\pなまえを　かえる　ことも　できるのよ$"

GoldenrodCity_Text_Gramps:
	.string "ふう！　この　まちは　ひろすぎて\nなにも　みつからんわい$"

GoldenrodCity_Text_RocketScout1:
	.string "ここが　ラジオとうか‥$"

GoldenrodCity_Text_RocketScout2:
	.string "なんだ　ガキ？\nさっさと　うせろ！$"

GoldenrodCity_Text_Rocket1:
	.string "じゃまだ　どけ！\nあっちへ　いけ！$"

GoldenrodCity_Text_Rocket2:
	.string "ラジオとうを　のっとる‥\pなに？　おまえには\nかんけい　ないだろ！$"

GoldenrodCity_Text_Rocket3:
	.string "ポケモン？　かねもうけの\nどうぐに　すぎないさ！$"

GoldenrodCity_Text_Rocket4:
	.string "おれたちの　ゆめが\nもうすぐ　かなう‥\pながく　くるしい\nたたかい　だった‥$"

GoldenrodCity_Text_Rocket5:
	.string "おい　ガキ！　ここは\nおまえの　くる　ところじゃない！\lさっさと　きえろ！$"

GoldenrodCity_Text_Rocket6:
	.string "ロケットだんの　おそろしさを\nあじわわせて　やる！$"

GoldenrodCity_Text_StationSign:
	.string "コガネシティ　えき$"

GoldenrodCity_Text_RadioTowerSign:
	.string "コガネシティ　ラジオとう$"

GoldenrodCity_Text_DeptStoreSign:
	.string "ポケモングッズ　ずらり　かんび！\pコガネシティ　デパート$"

GoldenrodCity_Text_GymSign:
	.string "コガネシティ　ポケモンジム\nジムリーダー　アカネ\pダイナマイト　プリティ　ギャル！$"

GoldenrodCity_Text_CitySign:
	.string "コガネシティ\pはなやかで　にぎやかな　まち$"

GoldenrodCity_Text_BikeShopSign:
	.string "せかいは　サイクリングロード！\nじてんしゃや$"

GoldenrodCity_Text_GameCornerSign:
	.string "あそびの　ひろば！\pコガネシティ　ゲームコーナー$"

GoldenrodCity_Text_NameRaterSign:
	.string "せいめい　はんだんし\pポケモンの　ニックネームを\nうらないます$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ちかつうろ　いりぐち$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ちかつうろ　いりぐち$"


GoldenrodCity_Text_FlowerShopSign:
	.string "はなが　いっぱい　フラワーショップ$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "おまえの　ポケモンに　すっごい\nわざを　おしえて　やれるぞ！\pおしえて　やろうか？$"

GoldenrodCity_Text_MoveTutorCost:
	.string "コイン　1000まい　いただくが\nいいかい？$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "ええー‥　すごい　わざ　なのに！$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "わははは！　こうかい　させないぞ！\pどの　わざを　おしえる？$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "ざんねん\nいえから　おかねを　もってくるか‥$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "この　わざの　よさが　わかれば\nおまえも　いちにんまえの\lトレーナーだ$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "わははは！　さらばだ！$"

GoldenrodCity_Text_MoveTutorBut:
	.string "で‥　でも‥$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "‥コインが　たりないぞ‥$"
