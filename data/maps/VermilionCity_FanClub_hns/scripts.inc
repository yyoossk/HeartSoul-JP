VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "わしは　ポケモンだいすき\nクラブの　かいちょうじゃ\pそだてた　ポケモンは\n150ぴき　いじょう！\pポケモンには　うるさいぞ\pわしの　ポケモンの　はなしを\nききに　きたのかね？$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "よし！　では　きくがよい！\pわしの　だいすきな　ギャロップ‥\pこいつが‥　かわいくて‥\nかしこくて‥　たまらんのじゃ\lそれに‥　すごくて‥　そう\lおもうじゃろ？‥\lたまらん‥　ワイルドで‥\lうつくしくて‥　やさしくて‥\lだいすきじゃ！\pねている　ときに‥　だきしめると\nあったかくて‥\lそれに‥　すばらしく‥\lうっとり‥　まさに　かみ‥\pおっと！　もう　こんな　じかん！\nひきとめて　しまったな！$"

PokemonFanClub_Text_Chairman_Gift:
	.string "はなしを　きいて　くれて\nありがとう　これを　あげよう！$"

PokemonFanClub_Text_Chairman_Candy:
	.string "それは　ポケモンを　つよく\nする　ふしぎなアメじゃ\pわしは　しょうぶで　ポケモンを\nきたえる　ほうが　すきなので\lおまえさんに　あげよう$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "やあ　{PLAYER}！\pまた　わしの　ポケモンの\nはなしを　ききに　きたか？\pちがう？　そうか‥\nまだ　はなしたい　ことが\lあったのに‥$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "ざんねんじゃ‥\pききたく　なったら\nまた　くるがよい$"

PokemonFanClub_Text_Receptionist:
	.string "かいちょうは　ポケモンの\nことに　なると　ねっしん\lなんです‥$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "ピッピが　ゆびをふるを\nつかう　ときの\lゆびの　ふりかたが　すき\pかわいいんだ！$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "ピッピが　すきだけど\nつかまえられ　なくて\pだから　ひろった\nピッピにんぎょうで\lがまん　してるんだ$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "そうか　この　にんぎょうを\nなくした　こが\lかなしんでるんだね‥\pわかった　この　ピッピにんぎょうを\nその　こに　かえして\lあげて　くれる？\pほんものの　ピッピとは　いつか\nじぶんで　ともだちに　なるよ\lしんぱい　しないで！$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "みてて　よ　ほんものの\nピッピと　ともだちに\lなるからね$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "わたしの　かわいい\nベイリーフを　みて！\pあたまの　はっぱが\nかわいいでしょ！$"

PokemonFanClub_Text_ClefairyDoll:
	.string "ピッピだ！　あれ？\pなんだ　ピッピにんぎょうか$"

PokemonFanClub_Text_Bayleef:
	.string "ベイリーフ『リー　リーフ！$"

PokemonFanClub_Text_Listen:
	.string "ほかの　トレーナーの　はなしは\nしずかに　ききましょう$"

PokemonFanClub_Text_Bragging:
	.string "じまん　されたら\nじまんで　かえせ！$"
