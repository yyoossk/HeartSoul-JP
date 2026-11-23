gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2}は　だれかの\nパソコンに　てんそうされた！\pボックス『{STR_VAR_1}』に\nあずけられた！$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2}は\n"
#if IS_FRLG || IS_HNS
	.string "BILL'S PC.\p"
#else
	.string "LANETTE'S PC.\p"
#endif
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "だれかの　パソコンの　ボックス\n『{STR_VAR_3}』は　いっぱいだった\p{STR_VAR_2}は　ボックス\n『{STR_VAR_1}』に　てんそうされた！$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "ボックス『{STR_VAR_3}』は\n"
#if IS_FRLG || IS_HNS
	.string "BILL'S PC was full.\p"
#else
	.string "LANETTE'S PC was full.\p"
#endif
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2}は　{B_PC_CREATOR_NAME}\nパソコンに　おくられた！\pボックス『{STR_VAR_1}』に\nあずけられた！$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER}は\n{STR_VAR_1}を　てにいれた！$"

gText_NoMoreRoomForPokemon::
	.string "もう　ポケモンを　あずける\nばしょが　ない！\pポケモンボックスが　いっぱいで\nもう　あずけられない！$"

gText_NicknameThisPokemon::
	.string "てにいれた　{STR_VAR_1}に\nニックネームを　つけますか？$"
