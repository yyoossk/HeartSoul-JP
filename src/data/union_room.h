ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("もういちど　さいしょから　やりなおして　ください");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("ワイヤレス　アダプタの\nさがしを　ちゅうし　しました");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ほかの　プレイヤーからの\nつうしんを　まって　います"); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}！　ほかの\nプレイヤーの　つうしんを　まって　います");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}！　つうしんまち！\nそろったら　スタートを　おしてね");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("あと　1にん\nひつよう");
static const u8 sText_2PlayersNeeded[] = _("あと　2にん\nひつよう");
static const u8 sText_3PlayersNeeded[] = _("あと　3にん\nひつよう");
static const u8 sText_4PlayersNeeded[] = _("あと　4にん\nひつよう");
static const u8 sText_2PlayerMode[] = _("2にん\nモード");
static const u8 sText_3PlayerMode[] = _("3にん\nモード");
static const u8 sText_4PlayerMode[] = _("4にん\nモード");
static const u8 sText_5PlayerMode[] = _("5にん\nモード");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}やめる");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2}から　{STR_VAR_1}の\nさそいが　きました　うけますか？");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2}から　れんらくが　きました\n{STR_VAR_1}を　わけますか？");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2}から　れんらくが　きました\nメンバーに　くわえますか？");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}！\nこの　メンバーで　いいですか？");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("この　メンバーでの\n{STR_VAR_1}モードを　やめますか？");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("{STR_VAR_1}に\nOKを　おくりました");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("あいての　トレーナーは　いま\nつごうが　わるい　ようです…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("とおくに　いる　トレーナーとは\nつうしん　できません\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("ほかの　トレーナーの　じゅんびが\nまだ　できて　いません\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("この　メンバーでの\n{STR_VAR_1}モードを　ちゅうし　します{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("つうしんを　つづけられない\nメンバーが　います\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("あいての　トレーナーは\nつごうが　わるい　ようです…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1}から　OKが　きました！");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1}が　メンバーへの\nとうろくを　OKしました");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1}の　へんじは\nだめ…　でした\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}！\nほかの　メンバーを　まって　います！");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("メンバーを　やめますか？");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("メンバーを　やめました\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("ワイヤレス　アダプタで\nつうしんが　つながりました");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("ワイヤレス　アダプタの\nつうしんが　きれました…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("ともだちとの　つうしんが\nきれました…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1}の　へんじは\nだめ…　でした");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("{STR_VAR_2}モードを\nしますか？");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("{STR_VAR_2}モードを\nしますか？");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("つうしんちゅう…\nしばらく　おまちください"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("{STR_VAR_1}の　こうかんの\nへんじを　まって　います…");
ALIGNED(4) static const u8 sText_Communicating[] = _("つうしんちゅう{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("{STR_VAR_1}と　つうしんちゅう{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("しばらく　おまちください{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("やあ！　なにか\nしたい　ことは　ある？");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("こんにちは！\nなにか　する？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}「やあ　また　あったね！\nこんどは　なにを　する？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}「あ！　{PLAYER}　こんにちは！\nなにか　する？");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("なにか　する？");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("なにか　しませんか？");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}「つぎは　なにを\nする？");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}「ほかにも　なにか　する？"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("だれかから　れんらくが　きました{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1}から　れんらくが　きました{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("あいての　トレーナーの\nへんじを　まって　います…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("{STR_VAR_1}の\nへんじを　まって　います…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("あいての　トレーナーが\nトレーナーカードを　みせて　くれました\pあなたの　トレーナーカードも\nみせますか？");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("あいての　トレーナーが\nしょうぶを　いどんで　きました\pしょうぶを\nうけますか？");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("あいての　トレーナーが\nチャットに　さそって　います\pチャットに\nさんか　しますか？");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("あなたが　とうろくした\nLv.{DYNAMIC 0}の　{DYNAMIC 1}と\pLv.{DYNAMIC 2}の　{DYNAMIC 3}の\nこうかんの　もうしこみが　あります\pこうかん　しますか？");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("あなたが　とうろくした　タマゴとの\nこうかんの　もうしこみが　あります\lこうかん　しますか？");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("チャットが　きれました\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("もうしこみを　ことわりました\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("もうしこみを　ことわりました\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("チャットが　おわりました\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("あ　いま　チャット　してるんだ\nいっしょに　どう？");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}「やあ　{PLAYER}！\nいま　チャット　してるんだ\lいっしょに　どう？");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("あ　いま　チャット　してるの\nいっしょに　しない？");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}「あ　{PLAYER}！\nいま　チャット　してるの\lいっしょに　しない？");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nトレーナーは　いそがしい　ようです…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("しょうぶ　だね？\nよし　ちょっと　まってて");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("チャット　したいの？\nいいよ　すこし　まってね");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("いいよ！　あいさつがわりに\nトレーナーカードを　みせるね");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("しょうぶ？　もちろん！\nでも　じゅんびに　じかんが　ほしいな");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("チャット　したいの？\nいいよ　ちょっと　まってね");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("じこしょうかいに\nトレーナーカードを　みせるね");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("チャット　したいの？\nいいよ　すこし　まってね"); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("おまたせ！\nしょうぶ　はじめよう！{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("よし！\nチャット　しよう！{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("またせて　ごめんね！\nはじめよう！{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("またせて　ごめんね！\nチャット　しよう{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("こうかんを　はじめます{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("しょうぶを　はじめます{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("チャットに　はいります…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("ごめん！　いま　ポケモンの\nちょうしが　よくないんだ\lまた　こんど　しょうぶ　しよう\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("ほんとに　ごめんね　ポケモンの\nちょうしが　わるいの…\pまた　こんど　しょうぶ　しよう\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("あれ？　トレーナーカード…\nどこに　いったかな？\lごめん！　また　こんど　みせるね！\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("あれ？　トレーナーカードを\nどこに　しまったっけ？…\lごめん！　あとで　みせるね！\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("なにか　したく　なったら\nいつでも　こえを　かけてね！\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("なにか　したく　なったら\nえんりょ　しないでね\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("おっと！　ごめん　ほかに\nやる　ことが　あるんだ\lまた　こんどね？\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("しょうぶ　するには\nLv.30いかの　ポケモンが\l2ひき　ひつようだよ\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("しょうぶ　するには　Lv.30いかの\nポケモンが　2ひき　ひつようです\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("そっか\nいつでも　きてね\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("そう…\nいつでも　きてね\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("あ　ごめん！\nいまは　ちょっと　むりなんだ\lまた　こんど　チャット　しよう\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("ごめんね\nいま　とても　いそがしいの\lまた　こんど　チャット　しよう\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("わあ！\nきみ　かなり　つよいね！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("その　わざを　つかうの？\nいい　さくせんだね！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("やるね！\nめから　うろこだよ！\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("え！　その　ばめんで\nその　ポケモンを　だすの？\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("その　ポケモン…\nすごく　よく　そだってる！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("それだ！\nいまは　その　わざだね！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("すごい！\nそんな　たたかいかたが　あるんだ？\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("ポケモンを　いれかえる\nタイミングが　ばつぐんだね！\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("なるほど！\nべんきょうに　なるよ！\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("もう　おもしろい　こと　いわないで！\nわらいすぎて　おなかが　いたい！\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("へえ？\nそんな　ことが　あったんだ\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("ふむふむ…　え？\nつまり　こういう　こと？\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("そうなの？\nしらなかった\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("あはは！\nなに　それ？\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("そう！　まさに　それ！\nそれが　いいたかったの\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("つまり…\nそう！　そういう　こと！\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("あいさつ　がわりに\nトレーナーカードを　みせてるだけだよ\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("なかよく　なれると　いいな！\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("なかよく　なる　ために\nトレーナーカードを　みせあってるの\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("よろしくね\nこれからも　なかよく　してね！\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("やったー！\nこの　ポケモン　ほしかったんだ！\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("ずっと　ほしかった　ポケモンが\nやっと　こうかんで　てに　はいった\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("いま　ポケモンを　こうかん　してるの\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("ほしかった　ポケモンを\nやっと　こうかんで　ゲットしたよ！\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1}は\nこうかんボードを　みた\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("こうかんボードへ　ようこそ\pあなたの　ポケモンを　とうろく　して\nこうかんに　だす　ことが　できます\pポケモンを　とうろく\nしますか？");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("この　こうかんボードは\nポケモンを　こうかんに　だす\lための　ものです\pポケモンを　とうろく　するだけで\nだいじょうぶ　です\pほかの　トレーナーが　てもちの\nポケモンで　こうかんを\lもうしこんで　くれます\pポケモンを　とうろく　して　たくさんの\nトレーナーと　こうかん　して\lください\pポケモンを　とうろく\nしますか？");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("こうかんボードに　あなたの\nポケモンを　とうろく　しました\pごりよう　ありがとう　ございました！\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("こうかんボードに　とうろく　された\nポケモンは　いません\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("こうかんで　ほしい　ポケモンの\nタイプを　えらんで　ください\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("てもちの　どの　ポケモンを\nこうかんに　だしますか？\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("とうろくを　ちゅうし　しました\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("とうろくが　かんりょう　しました\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("こうかんを　ちゅうし　しました\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("とうろく　した　Lv.{STR_VAR_2}の\n{STR_VAR_1}の　とうろくを　やめますか？");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("とうろく　した　タマゴの\nとうろくを　やめますか？");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("とうろくを　とりけしました\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("こうかんを　のぞむ\nトレーナーが　ならびます"); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("ポケモンを　こうかん　する\nトレーナーを　えらんで　ください"); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("{STR_VAR_1}に　こうかんを\nもうしこみますか？");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("あいての　トレーナーの\nへんじを　まって　います…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("こうかん　する　ポケモンを\nとうろく　して　いません\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("{STR_VAR_1}が　ほしい　{STR_VAR_2}タイプの\nポケモンを　もって　いません\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("{STR_VAR_1}が　ほしい　タマゴを\nもって　いません\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1}は　いま　あなたの\nポケモンと　こうかん　できません\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("いま　{STR_VAR_1}の　ポケモンと\nこうかん　できません\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("こうかんの　もうしこみを\nことわられました\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("タマゴこうかん");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}えらぶ　{A_BUTTON}さんか　{B_BUTTON}やめる");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("トレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("シングルバトルの\nトレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("ダブルバトルの\nトレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("マルチバトルの\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("こうかん　する\nトレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("ふしぎな　カードを　わけて　いる\nトレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("ふしぎな　ニュースを　わけて　いる\nトレーナーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("ポケモンなわとび！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("きのみ　マッシャー！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("ドードリオの　きのみどり！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("きのみブレンダー！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("レコードコーナー！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("かっこよさコンテスト！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("うつくしさコンテスト！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("かわいさコンテスト！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("かしこさコンテスト！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("たくましさコンテスト！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("バトルタワー　レベル50！\nリーダーを　えらんで　ください");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("バトルタワー　オープンレベル！\nリーダーを　えらんで　ください");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("ワイヤレス　アダプタを\nさがして　います　おまちください…");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("ダブルバトルには　ポケモンが\n2ひき　いじょう　ひつようです\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("{STR_VAR_1}の　へんじを　まって　います…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1}に　メンバーとうろくを\nたのみました　おまちください");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("ワイヤレス　アダプタの\nへんじを　まって　います");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("ほかの　トレーナーが　あつまるのを\nまって　います"); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("いま　わけて　いる\nカードは　ない　ようです");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("いま　わけて　いる\nニュースは　ない　ようです");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("しょうぶ");
ALIGNED(4) static const u8 sText_Chat2[] = _("チャット");
ALIGNED(4) static const u8 sText_Greetings[] = _("あいさつ");
ALIGNED(4) static const u8 sText_Exit[] = _("やめる");
ALIGNED(4) static const u8 sText_Exit2[] = _("やめる");
ALIGNED(4) static const u8 sText_Info[] = _("せつめい");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("なまえ{CLEAR_TO 60}ほしい{CLEAR_TO 110}だす{CLEAR_TO 198}Lv.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("シングルバトル");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("ダブルバトル");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("マルチバトル");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("ポケモンこうかん");
ALIGNED(4) static const u8 sText_Chat[] = _("チャット");
ALIGNED(4) static const u8 sText_Cards[] = _("カード");
ALIGNED(4) static const u8 sText_WonderCards[] = _("ふしぎな　カード");
ALIGNED(4) static const u8 sText_WonderNews[] = _("ふしぎな　ニュース");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("ポケモンなわとび");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("きのみ　マッシャー");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("きのみどり");
ALIGNED(4) static const u8 sText_Search[] = _("さがす");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("きのみブレンダー");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("レコードコーナー");
ALIGNED(4) static const u8 sText_CoolContest[] = _("かっこよさコンテスト");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("うつくしさコンテスト");
ALIGNED(4) static const u8 sText_CuteContest[] = _("かわいさコンテスト");
ALIGNED(4) static const u8 sText_SmartContest[] = _("かしこさコンテスト");
ALIGNED(4) static const u8 sText_ToughContest[] = _("たくましさコンテスト");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("バトルタワー　Lv.50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("バトルタワー　オープンレベル");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("ノーマルカード　です");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("ブロンズカード　です！");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("カッパーカード　です！");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("シルバーカード　です！");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("ゴールドカード　です！");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("{DYNAMIC 0}　{DYNAMIC 1}の\nトレーナーカード…\l{DYNAMIC 2}\pずかん　{DYNAMIC 3}\nプレイじかん　{DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("たいせん　かち　{DYNAMIC 0}　まけ　{DYNAMIC 2}\nこうかん　{DYNAMIC 3}\p「{DYNAMIC 4}　{DYNAMIC 5}\n{DYNAMIC 6}　{DYNAMIC 7}」\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}「あえて　よかった！{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}「よろしくね！{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("{DYNAMIC 1}の　トレーナーカードを\nみおわりました{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

// Subtract two from the total type count to handle in-battle types not for display
static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES - 2] = {
    { gTypesInfo[TYPE_NORMAL].name,   TYPE_NORMAL         },
    { gTypesInfo[TYPE_FIRE].name,     TYPE_FIRE           },
    { gTypesInfo[TYPE_WATER].name,    TYPE_WATER          },
    { gTypesInfo[TYPE_ELECTRIC].name, TYPE_ELECTRIC       },
    { gTypesInfo[TYPE_GRASS].name,    TYPE_GRASS          },
    { gTypesInfo[TYPE_ICE].name,      TYPE_ICE            },
    { gTypesInfo[TYPE_GROUND].name,   TYPE_GROUND         },
    { gTypesInfo[TYPE_ROCK].name,     TYPE_ROCK           },
    { gTypesInfo[TYPE_FLYING].name,   TYPE_FLYING         },
    { gTypesInfo[TYPE_PSYCHIC].name,  TYPE_PSYCHIC        },
    { gTypesInfo[TYPE_FIGHTING].name, TYPE_FIGHTING       },
    { gTypesInfo[TYPE_POISON].name,   TYPE_POISON         },
    { gTypesInfo[TYPE_BUG].name,      TYPE_BUG            },
    { gTypesInfo[TYPE_GHOST].name,    TYPE_GHOST          },
    { gTypesInfo[TYPE_DRAGON].name,   TYPE_DRAGON         },
    { gTypesInfo[TYPE_STEEL].name,    TYPE_STEEL          },
    { gTypesInfo[TYPE_DARK].name,     TYPE_DARK           },
    { gTypesInfo[TYPE_FAIRY].name,    TYPE_FAIRY          },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
