Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "リニアの　まち\nヤマブキシティへ　ようこそ！\p‥と　いいたい　ところ　だが\nリニアは　いま\lうごいて　いないんだ\pはつでんしょの　こしょうで\nでんきが　こないんだよ$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "ヤマブキで　いちばん\nゆうめいなのは　リニアだ$"
