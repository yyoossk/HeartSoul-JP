Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "おい！　マンキーを　さがしてるんだ！$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "とおりすがりの　ひとに\nまけるなんて！$"

Route34_Text_YoungsterSamuel_After:
	.string "もっと　しゅぎょう　するぞ\pなにしろ　ジムリーダーを\nめざしてるんだからな$"

Route34_Text_YoungsterIan_Seen:
	.string "ぼくは　クラスで　いちばん\nポケモンが　つよいんだ$"

Route34_Text_YoungsterIan_Beaten:
	.string "そんな！　うえには　うえが‥$"

Route34_Text_YoungsterIan_After:
	.string "クラスの　スターに　なれるように\nがんばってるんだ$"

Route34_Text_CamperTodd_Seen:
	.string "ポケモンを　そだてる\nうでには　じしんが　あるんだ\pみたい？$"

Route34_Text_CamperTodd_Beaten:
	.string "そだてかた　まちがえたかな？$"

Route34_Text_CamperTodd_After:
	.string "そだてやに　あずけるか\nどうぐを　つかうか‥$"

Route34_Text_ToddRegister:
	.string "そだてやに　あずけるか\nどうぐを　つかうか‥$"

Route34_Text_ToddRematchIntro:
	.string "ポケモンを　そだてる\nうでには　じしんが　あるんだ\pみたい？$"

Route34_Text_ToddRematchDefeat:
	.string "そだてかた　まちがえたかな？$"

Route34_Text_ToddPostRematch:
	.string "そだてやに　あずけるか\nどうぐを　つかうか‥$"

Route34_Text_GinaRegister:
	.string "あなた　つよすぎて\nれんしゅうあいてに　ならないわ$"

Route34_Text_PicnickerGina_Seen:
	.string "あなた　トレーナー？\pれんしゅうじあい　しましょ$"

Route34_Text_PicnickerGina_Beaten:
	.string "ああ！　どうしても　かてない‥$"

Route34_Text_PicnickerGina_After:
	.string "あなた　つよすぎて\nれんしゅうあいてに　ならないわ$"

Route34_Text_OfficerKeith_Seen:
	.string "だれだ！\nなにを　している？$"

Route34_Text_OfficerKeith_Win:
	.string "つよい　こどもだな$"

Route34_Text_OfficerKeith_After:
	.string "うむ　きょうも　いじょう　なし\pいいこに　して\nもめごとは　おこすなよ$"

Route34_Text_OfficerKeith_Daytime:
	.string "あやしい　ものが　いないか\nパトロール　ちゅうだ$"

Route34_Text_PokefanBrandon_Seen:
	.string "そだてやから　ポケモンを\nひきとった　ばかりなんだ\pどれだけ　つよく　なったか\nためして　みよう！$"

Route34_Text_PokefanBrandon_Beaten:
	.string "どうして　こうなるんだ？$"

Route34_Text_PokefanBrandon_After:
	.string "ポケモンが　あたらしい　わざを\nおぼえて　かえってきたんだ\pもう　わけが　わからないよ！$"

Route34_Text_Sign_IlexForest:
	.string "ウバメのもり\nゲートを　ぬけて　すぐ$"

Route34_Text_Sign_Route34:
	.string "34ばんどうろ\nコガネシティ　ー　ヒワダタウン\pとちゅうに　ウバメのもり$"

Route34_Text_TrainerTips:
	.string "トレーナーの　こころえ\pきのみの　きは　1にちに　なんども\nあたらしい　みを　つける\pどの　きに　どの　きのみが\nなるか　おぼえて　おこう$"

Route34_Text_CooltrainerIrene_Seen:
	.string "アイリーン『あなた　だれ！？$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "アイリーン『ああっ！　つよすぎる！$"

Route34_Text_CooltrainerIrene_After1:
	.string "アイリーン『おねえちゃんの　ケイトが\nしかえし　してくれるわ！$"

Route34_Text_CooltrainerIrene_After2:
	.string "アイリーン『すてきな　はまべ\nでしょ？\pわたしたちの　ひみつの\nかくれがなの！$"

Route34_Text_CooltrainerJenn_Seen:
	.string "ジェン『な‥　なに？\nなにしてるの？$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "ジェン『ごめんね　アイリーン！\nおねえちゃん！$"

Route34_Text_CooltrainerJenn_After1:
	.string "ジェン『ちょうしに　のらないでよ！\nケイトねえさんは　つよいんだから！$"

Route34_Text_CooltrainerJenn_After2:
	.string "ジェン『ひなたぼっこは\nからだを　じょうぶに　するの$"

Route34_Text_CooltrainerKate_Seen:
	.string "ケイト『いもうとたちの　かりは\nかえさせて　もらうわ！$"

Route34_Text_CooltrainerKate_Beaten:
	.string "ケイト『うそ！　まけるなんて$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "ケイト『あなた　つよいわね\nいいわけ　できないわ‥\pはい　これ　あげる！$"

Route34_Text_CooltrainerKate_After:
	.string "ケイト『いきなり　ごめんなさいね\pここで　ひとに　あうなんて\nおもわなかったから\lびっくり　しちゃった$"


Route34_Text_Sign_DayCare:
	.string "そだてや\pあなたの　ポケモン\nそだてます！$"
