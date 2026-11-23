UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "ヒワダへ　いくのか？\pたたかう　しかくが　あるか\nおれの　ポケモンが　みてやる$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "おっ　おっ　おっ！$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "よし　きめた！\pポケモンが　つよく　なるまで\nここを　でないぞ！$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "ポケモンを　さがして\nあちこち　まわってるんだ\pきみも　ポケモンを\nさがしてるの？\pじゃあ　コレクションの\nライバルだ！$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "うう　ぼくの\nポケモンが‥$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "ときどき　どうくつの　おくから\nポケモンの　ほえごえが\lきこえるんだ$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "おっ！　びっくり！\pこんな　ところで　ひとに\nあうとは　おもわなかった！$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "うわっ！　ぼろまけだ！$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "だまされて　ヤドンのシッポを\nかわされたんだ\pヤドンが　かわいそうだよ$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "ズバットの　ちょうおんぱで\nポケモンが　こんらん\lしちゃうんだ\pほんとに　はらが　たつ！$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "ひが　きえた！$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "しゅうまつには　どうくつの\nおくから　へんな\lほえごえが　きこえるよ$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "あかるければ　どうくつは\nこわくない\pつよければ　ポケモンも\nこわくない$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "フラッシュ！$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "この　どうくつを\nてらしてるのは　おれの\lポケモンの　ほのおさ$"
