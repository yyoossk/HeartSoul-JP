@ カントー＆ジョウト: ムサシとコジロウ（ピカチュウ版の場面。tools_kj/add_jj.py で作成）

KJ_EventScript_JJ_MTMOON::
	trainerbattle_single TRAINER_KJ_JJ_1, KJ_Text_JJ_MTMOON_Intro, KJ_Text_JJ_MTMOON_Defeat, KJ_EventScript_JJ_MTMOON_After
	end

KJ_EventScript_JJ_MTMOON_Kojiro::
	goto KJ_EventScript_JJ_MTMOON
	end

KJ_EventScript_JJ_MTMOON_After::
	msgbox KJ_Text_JJ_MTMOON_Post
	closemessage
	applymovement LOCALID_KJ_MUSASHI_MTMOON, Common_Movement_JumpInPlaceDownKj
	applymovement LOCALID_KJ_KOJIRO_MTMOON, Common_Movement_JumpInPlaceDownKj
	waitmovement 0
	playse SE_FLEE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KJ_MUSASHI_MTMOON
	removeobject LOCALID_KJ_KOJIRO_MTMOON
	setflag FLAG_KJ_HIDE_JJ_MTMOON
	fadescreen FADE_FROM_BLACK
	release
	end

KJ_Text_JJ_MTMOON_Intro::
	.string "ムサシ“ちょっと　まったー！\pコジロウ“この　やまの　カセキは\nロケットだんが　いただくぜ！\pムサシ“じゃまする　こは\nおしおき　よ！$"

KJ_Text_JJ_MTMOON_Defeat::
	.string "ムサシ“うそ！\nまけちゃった……$"

KJ_Text_JJ_MTMOON_Post::
	.string "コジロウ“おぼえてろよー！\pムサシ・コジロウ“やなかんじー！$"

KJ_EventScript_JJ_HIDEOUT::
	trainerbattle_single TRAINER_KJ_JJ_2, KJ_Text_JJ_HIDEOUT_Intro, KJ_Text_JJ_HIDEOUT_Defeat, KJ_EventScript_JJ_HIDEOUT_After
	end

KJ_EventScript_JJ_HIDEOUT_Kojiro::
	goto KJ_EventScript_JJ_HIDEOUT
	end

KJ_EventScript_JJ_HIDEOUT_After::
	msgbox KJ_Text_JJ_HIDEOUT_Post
	closemessage
	applymovement LOCALID_KJ_MUSASHI_HIDEOUT, Common_Movement_JumpInPlaceDownKj
	applymovement LOCALID_KJ_KOJIRO_HIDEOUT, Common_Movement_JumpInPlaceDownKj
	waitmovement 0
	playse SE_FLEE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KJ_MUSASHI_HIDEOUT
	removeobject LOCALID_KJ_KOJIRO_HIDEOUT
	setflag FLAG_KJ_HIDE_JJ_HIDEOUT
	fadescreen FADE_FROM_BLACK
	goto KJ_EventScript_JJ_HideoutLiftKey
	end

KJ_Text_JJ_HIDEOUT_Intro::
	.string "ムサシ“また　あんたね！\pコジロウ“サカキさまの　ところへは\nいかせないぜ！$"

KJ_Text_JJ_HIDEOUT_Defeat::
	.string "コジロウ“くっ……\nなんて　つよさだ……$"

KJ_Text_JJ_HIDEOUT_Post::
	.string "ムサシ“リフトキーなら\nそのへんに　おとしちゃったわ！\pムサシ・コジロウ“やなかんじー！$"

KJ_EventScript_JJ_TOWER::
	trainerbattle_single TRAINER_KJ_JJ_3, KJ_Text_JJ_TOWER_Intro, KJ_Text_JJ_TOWER_Defeat, KJ_EventScript_JJ_TOWER_After
	end

KJ_EventScript_JJ_TOWER_Kojiro::
	goto KJ_EventScript_JJ_TOWER
	end

KJ_EventScript_JJ_TOWER_After::
	msgbox KJ_Text_JJ_TOWER_Post
	closemessage
	applymovement LOCALID_POKEMON_TOWER_GRUNT1, Common_Movement_JumpInPlaceDownKj
	applymovement LOCALID_KJ_KOJIRO_TOWER, Common_Movement_JumpInPlaceDownKj
	waitmovement 0
	playse SE_FLEE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_POKEMON_TOWER_GRUNT1
	removeobject LOCALID_KJ_KOJIRO_TOWER
	setflag FLAG_KJ_HIDE_JJ_TOWER
	fadescreen FADE_FROM_BLACK
	release
	end

KJ_Text_JJ_TOWER_Intro::
	.string "ムサシ“あーら　また　あったわね\pコジロウ“この　タワーは\nロケットだんが　いただいたぜ！$"

KJ_Text_JJ_TOWER_Defeat::
	.string "ムサシ“もう！\nなんで　かてないのよ！$"

KJ_Text_JJ_TOWER_Post::
	.string "コジロウ“フジろうじんは\nかえして　やるよ……\pムサシ・コジロウ“やなかんじー！$"

KJ_EventScript_JJ_SILPH::
	trainerbattle_single TRAINER_KJ_JJ_4, KJ_Text_JJ_SILPH_Intro, KJ_Text_JJ_SILPH_Defeat, KJ_EventScript_JJ_SILPH_After
	end

KJ_EventScript_JJ_SILPH_Kojiro::
	goto KJ_EventScript_JJ_SILPH
	end

KJ_EventScript_JJ_SILPH_After::
	msgbox KJ_Text_JJ_SILPH_Post
	closemessage
	applymovement LOCALID_SILPH_CO_11F_GRUNT1, Common_Movement_JumpInPlaceDownKj
	applymovement LOCALID_KJ_KOJIRO_SILPH, Common_Movement_JumpInPlaceDownKj
	waitmovement 0
	playse SE_FLEE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_KJ_KOJIRO_SILPH
	setflag FLAG_KJ_HIDE_JJ_SILPH
	fadescreen FADE_FROM_BLACK
	release
	end

KJ_Text_JJ_SILPH_Intro::
	.string "ムサシ“こんな　ところまで\nきたのね！\pコジロウ“しゃちょうしつへは\nいかせないぜ！$"

KJ_Text_JJ_SILPH_Defeat::
	.string "コジロウ“また　まけた……$"

KJ_Text_JJ_SILPH_Post::
	.string "ムサシ“サカキさまに\nおこられちゃう……\pムサシ・コジロウ“やなかんじー！$"

KJ_EventScript_JJ_HideoutLiftKey::
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_KJ_HIDE_LIFT_KEY
	release
	end

Common_Movement_JumpInPlaceDownKj::
	jump_in_place_down
	jump_in_place_down
	step_end
