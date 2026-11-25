FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "えーと……\n"
	.string "そうだ　わし　わすれオヤジ\p"
	.string "ポケモンの　わざを\n"
	.string "わすれさせることが　できるんだ\p"
	.string "わざを　わすれさせるかい？$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "どの　ポケモン？$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
	.string "どの　わざを\n"
	.string "わすれさせるんだい？$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "{STR_VAR_1}は　わざを　１つしか\n"
	.string "もってないよ$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "おお！\n"
	.string "{STR_VAR_1}の　{STR_VAR_2}だね？$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "だいせいこう！　きみの　{STR_VAR_1}\n"
	.string "{STR_VAR_2}を　わすれたよ$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "そうか　わすれさせたい　わざが\n"
	.string "あったら　また　きてよ$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "おいおい　それは\n"
	.string "タマゴだよ$"

