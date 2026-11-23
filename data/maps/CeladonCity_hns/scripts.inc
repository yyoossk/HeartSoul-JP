CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
	.string "あら　{PLAYER}さん\nきょうの　ふんすいは\lすてきだと　おもいません？\pまた　しょうぶを　ごきぼうなら\nかくとうどうじょうに　おりますわ$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "この　ニョロボンは\nおれの　あいぼう　なんだ\pいつか　カエルの　ポケモンに\nしんか　するかな$"

CeladonCity_Text_Poliwrath:
	.string "ニョロボン『ゲコッ！$"

CeladonCity_Text_Teacher1:
	.string "また　スロットで　まけちゃった‥\pいまは　おんなのこも\nスロットで　あそぶのよ\pあなたも　やってみたら？$"

CeladonCity_Text_Gramps1:
	.string "さいきん　ベトベターが\nでるように　なった\pいえの　まえの　いけが　みえるか？\nいまは　ベトベターが　すんでおる\pどこから　きたのか？\nこれは　ゆゆしき　もんだいじゃ‥$"

CeladonCity_Text_Gramps2:
	.string "にひひ！　この　ジムは　さいこう！\nおんなのこ　しか　いないんじゃ！$"

CeladonCity_Text_Youngster1:
	.string "ひみつ　おしえて　あげようか？\pタマムシマンションには\nかくれた　うらぐちが　あるんだ$"

CeladonCity_Text_Youngster2:
	.string "レストランで　おおぐい\nたいかいを　やってるよ\pみてるだけで　おなかが\nいっぱいに　なりそう‥$"

CeladonCity_Text_Teacher2:
	.string "タマムシデパートは　しなぞろえが\nいちばん　すごいのよ\pあそこで　かえない　ものは\nどこでも　かえないわ\pあら‥　てんいんさん　みたいね$"

CeladonCity_Text_Lass:
	.string "じめんを　みながら　あるいてたら\nめが　まわっちゃった$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "タマムシシティ\pタマムシは　にじいろ\nゆめの　いろ$"

CeladonGym_Text_Sign:
	.string "タマムシシティ　ポケモンジム\nジムリーダー　エリカ\pしぜんを　あいする　おじょうさま$"

CeladonCity_Text_DeptStoreSign:
	.string "ほしい　ものは\nタマムシデパートで！$"

CeladonCity_Text_MansionSign:
	.string "タマムシマンション$"

CeladonCity_Text_GameCornerSign:
	.string "みんなの　あそびば\nタマムシ　ゲームコーナー$"

CeladonCity_Text_TrainerTips:
	.string "トレーナーの　こころえ\pエフェクトガードは　かえんほうしゃや\nなみのりなどの　とくしゅ\lこうげきから　ポケモンを　まもる\pどうぐは　タマムシデパートで\nかおう！$"
