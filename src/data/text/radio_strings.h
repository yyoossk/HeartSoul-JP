// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("オーキドの　ポケモンこうざ");
static const u8 sRadioStationName_PokedexShow[]     = _("ポケモンずかん　ショー");
static const u8 sRadioStationName_PokemonMusic[]    = _("ポケモンミュージック");
static const u8 sRadioStationName_LuckyChannel[]    = _("ラッキーチャンネル");
static const u8 sRadioStationName_BuenasPassword[]  = _("クルミの　あいことば");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("ひとと　まちの　うわさ");
static const u8 sRadioStationName_LetsAllSing[]     = _("みんなで　うたおう！");
static const u8 sRadioStationName_PokeFlute[]       = _("ポケモンのふえ");

static const u8 sRadioStationName_HoennSound[]  = _("ホウエンの　しらべ");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("ホウエンと　いう　とおい");
static const u8 sRadioText_Hoenn2[] = _("ちほうの　ポケモンの　メロディ！");
static const u8 sRadioText_Hoenn3[] = _("その　ちほうの　やせいの　ポケモンが");
static const u8 sRadioText_Hoenn4[] = _("ちかくに　でるかも！");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("オーキドの　ずかん　ショー！");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("オーキド「きょうの　ポケモンは");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("クルミ「オーキドはかせの　ポケモンこうざ！");
static const u8 sRadioText_OPT_WithMeMary[] = _("アシスタントは　わたし　クルミ！");
static const u8 sRadioText_OPT_OakPrefix[] = _("オーキド「");
static const u8 sRadioText_OPT_SeenAround[] = _("ふきんで　みかける　らしい");
static const u8 sRadioText_OPT_MaryPrefix[] = _("クルミ「");
static const u8 sRadioText_OPT_MaryIs[] = _("は　");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("ポケモン　チャンネル");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("あまくて");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("くねくねして");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("なまえどおりで");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("まちがいなく");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("ほんとうに");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("すごく");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("どくどくしく");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("うっとりするほど");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("いたずらっぽく");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("いまどきで");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("くせになるほど");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("みずの　なかでは");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("しんか　したら");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("ちょうはつてきで");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("はちゃめちゃで");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("とろけるほど");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("かわいい");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("へん");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("ここちいい");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("だいたん　かな");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("こわい");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("ダンディ！");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("つよい");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("わくわく　する");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("ノリノリ！");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("かんどうてき");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("ひとなつっこい");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("あつい　あつい！");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("しげきてき");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("しんちょう");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("すてき");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("すばやい");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("ベン「ポケモン　ミュージック　チャンネル！");
static const u8 sRadioText_BenIntro2[] = _("DJ　ベンだよ！");
static const u8 sRadioText_FernIntro[] = _("フミ「ポケモン　ミュージック！");
static const u8 sRadioText_FernIntro2[] = _("DJ　フミと　いっしょに！");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("きょうは");
static const u8 sRadioText_BenFern_JamTo[] = _("さあ　いっしょに　きこう");
static const u8 sRadioText_BenFern_ChillTo[] = _("ゆったり　きいてね");
static const u8 sRadioText_BenFern_March[] = _("ポケモン　マーチ！");
static const u8 sRadioText_BenFern_Lullaby[] = _("ポケモン　こもりうた！");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("ヒロシ「イエーイ！　みんな　げんき？");
static const u8 sRadioText_LC2[] = _("ちょうしが　いい　ときも");
static const u8 sRadioText_LC3[] = _("わるい　ときも　わすれずに！");
static const u8 sRadioText_LC4[] = _("ラッキー　ナンバー　ショー！");
static const u8 sRadioText_LC5[] = _("こんしゅうの　ラッキーナンバーは");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("もういちど　いうよ！");
static const u8 sRadioText_LC_Match[] = _("ばんごうが　あったら");
static const u8 sRadioText_LC_Tower[] = _("ラジオとうへ　きてね！");
static const u8 sRadioText_LC_Drag1[] = _("…なんども　いうのは");
static const u8 sRadioText_LC_Drag2[] = _("ちょっと　めんどう…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("ひとと　まちの　うわさ！");
static const u8 sRadioText_PnP_Intro2[] = _("おとどけ　するのは　DJ　リリィ！");
static const u8 sRadioText_PnP_Space[] = _("　");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("って　かわいい");
static const u8 sRadioText_PnP_Lazy[]       = _("って　ちょっと　のんびりや");
static const u8 sRadioText_PnP_Happy[]      = _("って　いつも　ごきげん");
static const u8 sRadioText_PnP_Noisy[]      = _("って　かなり　にぎやか");
static const u8 sRadioText_PnP_Precocious[] = _("って　おませさん");
static const u8 sRadioText_PnP_Bold[]       = _("って　ちょっと　だいたん");
static const u8 sRadioText_PnP_Picky[]      = _("って　えりごのみが　はげしい！");
static const u8 sRadioText_PnP_SortOfOK[]   = _("って　まあまあ　かな");
static const u8 sRadioText_PnP_SoSo[]       = _("って　ふつう　かな");
static const u8 sRadioText_PnP_Great[]       = _("って　じつは　すごい");
static const u8 sRadioText_PnP_MyType[]      = _("って　わたしの　タイプ");
static const u8 sRadioText_PnP_Cool[]        = _("って　かっこいいよね？");
static const u8 sRadioText_PnP_Inspiring[]   = _("って　あこがれちゃう！");
static const u8 sRadioText_PnP_Weird[]       = _("って　ちょっと　へんかも");
static const u8 sRadioText_PnP_RightForMe[]  = _("って　わたしに　ぴったり？");
static const u8 sRadioText_PnP_Odd[]         = _("って　ぜったい　かわってる！");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("ロケットだん");
static const u8 sRadioText_Rocket1[]  = _("……ゴホン　われわれは");
static const u8 sRadioText_Rocket2[]  = _("ロケットだん　だ！");
static const u8 sRadioText_Rocket3[]  = _("3ねんかんの");
static const u8 sRadioText_Rocket4[]  = _("じゅんびを　へて");
static const u8 sRadioText_Rocket5[]  = _("いま　ここに");
static const u8 sRadioText_Rocket6[]  = _("ふっかつ　した！");
static const u8 sRadioText_Rocket7[]  = _("サカキさま！");
static const u8 sRadioText_Rocket8[]  = _("きこえますか？");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("クルミ「クルミ　です！");
static const u8 sRadioText_Buena2[] = _("きょうの　あいことば！");
static const u8 sRadioText_Buena3[] = _("えーと…　それは");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("わすれないでね！　わたしは");
static const u8 sRadioText_Buena6[] = _("コガネの　ラジオとうに　いるよ！");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("ワカバタウン");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("ヨシノシティ");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("ヒワダタウン");
static const u8 sRadioBuenaPassword_Flying[]          = _("ひこう");
static const u8 sRadioBuenaPassword_Bug[]             = _("むし");
static const u8 sRadioBuenaPassword_Grass[]           = _("くさ");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("ポケモンこうざ");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("ポケモンミュージック");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("ラッキーチャンネル");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("クルミ「こんやは　ポケモンこうざで");
static const u8 sOPT_Report_Clefairy_1[]  = _("めずらしい　つきあかりの　おはなし！");
static const u8 sOPT_Report_Clefairy_2[]  = _("オーキド「きょう　とりあげるのは");
static const u8 sOPT_Report_Clefairy_3[]  = _("ふしぎな　ピッピ！");
static const u8 sOPT_Report_Clefairy_4[]  = _("まんげつの　よるに");
static const u8 sOPT_Report_Clefairy_5[]  = _("おつきみやまに　あつまるんじゃ");
static const u8 sOPT_Report_Clefairy_6[]  = _("クルミ「わに　なって　おどるの！");
static const u8 sOPT_Report_Clefairy_7[]  = _("かわいくて　ふしぎ！");
static const u8 sOPT_Report_Clefairy_8[]  = _("オーキド「えいえんの　なぞ");
static const u8 sOPT_Report_Clefairy_9[]  = _("いちどは　みて　みたい　ものじゃ！");

static const u8 sOPT_Report_Lapras_0[]  = _("クルミ「きょうは　やさしい");
static const u8 sOPT_Report_Lapras_1[]  = _("おおきな　ポケモンの　ばん！");
static const u8 sOPT_Report_Lapras_2[]  = _("オーキド「うみの　わたしぶね");
static const u8 sOPT_Report_Lapras_3[]  = _("みんな　だいすき　ラプラスじゃ！");
static const u8 sOPT_Report_Lapras_4[]  = _("つながりのどうくつ　でしか");
static const u8 sOPT_Report_Lapras_5[]  = _("みられんのじゃ　ふしぎじゃのう！");
static const u8 sOPT_Report_Lapras_6[]  = _("クルミ「めずらしくて　おだやか！");
static const u8 sOPT_Report_Lapras_7[]  = _("それに　うたも　うたうの！");
static const u8 sOPT_Report_Lapras_8[]  = _("オーキド「その　うたは　うみの");
static const u8 sOPT_Report_Lapras_9[]  = _("たましいを　しずめると　いう");

static const u8 sOPT_Report_Ampharos_0[]  = _("クルミ「みなさん　おかえりなさい！");
static const u8 sOPT_Report_Ampharos_1[]  = _("ポケモンこうざの　じかんです！");
static const u8 sOPT_Report_Ampharos_2[]  = _("オーキド「きょうは　デンリュウに");
static const u8 sOPT_Report_Ampharos_3[]  = _("スポットを　あてるぞ！");
static const u8 sOPT_Report_Ampharos_4[]  = _("ひかる　しっぽは　きりの　なかでも");
static const u8 sOPT_Report_Ampharos_5[]  = _("まいごを　みちびくんじゃ");
static const u8 sOPT_Report_Ampharos_6[]  = _("クルミ「ちからづよくて　ゆうがで");
static const u8 sOPT_Report_Ampharos_7[]  = _("とっても　ひとなつっこい！");
static const u8 sOPT_Report_Ampharos_8[]  = _("オーキド「とうだいの　おはなしには");
static const u8 sOPT_Report_Ampharos_9[]  = _("かかせない　ポケモンじゃ！");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("クルミ「つぎは　36ばんどうろの");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("かわりものの　おはなし…");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("オーキド「ウソッキー！　きに");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("みえるが　きでは　ないんじゃ！");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("みちを　ふさいで　みずを");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("かけないと　うごかんのじゃ");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("クルミ「ゼニガメじょうろにだけ");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("はんのう　するのよね！");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("オーキド「あれは　くさむらでなく");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("いわタイプが　ばけて　おるんじゃ！");

static const u8 sOPT_Report_RedGyarados_0[]  = _("クルミ「きょうは　ジョウトの");
static const u8 sOPT_Report_RedGyarados_1[]  = _("びっくり　ニュース！");
static const u8 sOPT_Report_RedGyarados_2[]  = _("オーキド「いかりのみずうみで　あかい");
static const u8 sOPT_Report_RedGyarados_3[]  = _("ギャラドスが　みつかったそうじゃ！");
static const u8 sOPT_Report_RedGyarados_4[]  = _("ふつうの　あおい　ものと　ちがい");
static const u8 sOPT_Report_RedGyarados_5[]  = _("まっかな　いろを　しとる！");
static const u8 sOPT_Report_RedGyarados_6[]  = _("クルミ「へんな　でんぱと");
static const u8 sOPT_Report_RedGyarados_7[]  = _("かんけいが　あるって　うわさよ！");
static const u8 sOPT_Report_RedGyarados_8[]  = _("オーキド「なぞの　しんか…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("しぜんな　ものでは　ないかもしれん");

static const u8 sOPT_Report_Unown_0[]  = _("クルミ「アルフのいせきに　いった");
static const u8 sOPT_Report_Unown_1[]  = _("ことある？　ちょっと　こわいのよ！");
static const u8 sOPT_Report_Unown_2[]  = _("オーキド「かべには　こだいもじの");
static const u8 sOPT_Report_Unown_3[]  = _("ような　ふしぎな　もようが　ある");
static const u8 sOPT_Report_Unown_4[]  = _("なかには　アンノーンが　おって…");
static const u8 sOPT_Report_Unown_5[]  = _("みんな　もじの　かたちを　しとる！");
static const u8 sOPT_Report_Unown_6[]  = _("クルミ「なにかの　ことばなのかな？");
static const u8 sOPT_Report_Unown_7[]  = _("それとも　おどかしてるだけ？");
static const u8 sOPT_Report_Unown_8[]  = _("オーキド「しぜんの　なぞじゃ");
static const u8 sOPT_Report_Unown_9[]  = _("いまも　とけて　おらん");

static const u8 sOPT_Report_Snubbull_0[]  = _("クルミ「コガネの　ひとたちが");
static const u8 sOPT_Report_Snubbull_1[]  = _("あちこち　さがして　いるの！");
static const u8 sOPT_Report_Snubbull_2[]  = _("オーキド「ブルーが　にげだして");
static const u8 sOPT_Report_Snubbull_3[]  = _("まだ　みつかって　おらん！");
static const u8 sOPT_Report_Snubbull_4[]  = _("ふだんは　はずかしがりやじゃが");
static const u8 sOPT_Report_Snubbull_5[]  = _("えきの　ちかくで　みかけたそうじゃ");
static const u8 sOPT_Report_Snubbull_6[]  = _("クルミ「こいを　おいかけてるのかな");
static const u8 sOPT_Report_Snubbull_7[]  = _("それとも　ぼうけん　かしら！");
static const u8 sOPT_Report_Snubbull_8[]  = _("オーキド「よく　みはって");
static const u8 sOPT_Report_Snubbull_9[]  = _("リードを　よういして　おくんじゃ");

static const u8 sOPT_Report_Slowpoke_0[]  = _("クルミ「こんしゅうは　ヒワダタウンの");
static const u8 sOPT_Report_Slowpoke_1[]  = _("おおきな　ニュース！");
static const u8 sOPT_Report_Slowpoke_2[]  = _("オーキド「ヤドンたちが　ぶじに");
static const u8 sOPT_Report_Slowpoke_3[]  = _("いどへ　もどったそうじゃ！");
static const u8 sOPT_Report_Slowpoke_4[]  = _("ロケットだんが　しっぽを");
static const u8 sOPT_Report_Slowpoke_5[]  = _("きりとって　おったんじゃ！　ひどい！");
static const u8 sOPT_Report_Slowpoke_6[]  = _("クルミ「でも　ゆうかんな");
static const u8 sOPT_Report_Slowpoke_7[]  = _("トレーナーが　やっつけたの！");
static const u8 sOPT_Report_Slowpoke_8[]  = _("オーキド「ヤドンたちは　ぶじに");
static const u8 sOPT_Report_Slowpoke_9[]  = _("また　のんびり　いねむり　しとる");

static const u8 sOPT_Report_LavenderTower_0[]  = _("クルミ「シオンタウンの　とうが");
static const u8 sOPT_Report_LavenderTower_1[]  = _("かわったの！");
static const u8 sOPT_Report_LavenderTower_2[]  = _("オーキド「ふるい　ゆうれいの　とうが");
static const u8 sOPT_Report_LavenderTower_3[]  = _("いまでは　ラジオきょくじゃ！");
static const u8 sOPT_Report_LavenderTower_4[]  = _("いまでも　ちょっと　こわいと");
static const u8 sOPT_Report_LavenderTower_5[]  = _("いう　ひとも　おるが…");
static const u8 sOPT_Report_LavenderTower_6[]  = _("クルミ「マイクの　ちかくで");
static const u8 sOPT_Report_LavenderTower_7[]  = _("ゴースを　みた　きが　するの！");
static const u8 sOPT_Report_LavenderTower_8[]  = _("オーキド「ざつおんか…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("それとも　ゆうれいか！");

static const u8 sOPT_Report_Tentacruel_0[]  = _("クルミ「きょうは　うずまきじまの");
static const u8 sOPT_Report_Tentacruel_1[]  = _("ふしぎな　ニュース！");
static const u8 sOPT_Report_Tentacruel_2[]  = _("オーキド「どうくつの　いりぐちを");
static const u8 sOPT_Report_Tentacruel_3[]  = _("ドククラゲが　かこんで　おる！");
static const u8 sOPT_Report_Tentacruel_4[]  = _("おおきくて　まるで　なわばりを");
static const u8 sOPT_Report_Tentacruel_5[]  = _("まもって　いる　ようじゃ");
static const u8 sOPT_Report_Tentacruel_6[]  = _("クルミ「みちを　ふさぐけど");
static const u8 sOPT_Report_Tentacruel_7[]  = _("おそって　こないの…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("オーキド「まるで　うみの　そこの");
static const u8 sOPT_Report_Tentacruel_9[]  = _("なにかを　まもって　いる　ようじゃ");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
