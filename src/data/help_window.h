// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("おしらせ　ヘルプウィンドウ"),
        .desc = COMPOUND_STRING("これは　ヘルプウィンドウ　です\nがめんに　たくさん　もじを　だせますが\nだれも　よまないでしょう！\n\nすばらしいでしょう！"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("おしらせ　さらなる　せってい"),
        .desc = COMPOUND_STRING("とけいは　どの　ポケモンセンターでも\nペナルティなしで　かえられます\nバッグの　だいじなもの　と\nせっていメニューも　みて　みてね\nもっと　じぶんの　すきに　あそべます\nたのしんでね！"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("ちゅうい　つうしんの　あいしょう"),
        .desc = COMPOUND_STRING("まちがった　つうしんを　すると\nセーブデータが　こわれる　ことが　あります\nつぎの　ときだけ　つうしん　してください\nふたりとも　ハートアンドソウル\nふたりとも　おなじ　バージョン\nふたりとも　おなじ　チャレンジせってい\nランダマイザーを　つかって　いない"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("おまけ　コンテンツ　テレポーター"),
        .desc = COMPOUND_STRING("テレポーターは　ポケモンを\nガラルの　すがたに　かえます\nこれは　もとに　もどせません\nガラルの　すがたは　ストーリーや\nぜんこくずかんの　かんせいには\nひつよう　ありません"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("おまけ　コンテンツ　シンオウ"),
        .desc = COMPOUND_STRING("この　ひとに　はなしかけると\nおまけの　シンオウに　いけます\nストーリーや　ぜんこくずかんの\nかんせいには　ひつよう　ありません\n\nただの　おまけです　おこのみで　どうぞ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("おまけ　コンテンツ　しょとう"),
        .desc = COMPOUND_STRING("この　ひとに　はなしかけると\nおまけの　しょとうに　いけます\nストーリーや　ぜんこくずかんの\nかんせいには　ひつよう　ありません\n\nただの　おまけです　おこのみで　どうぞ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("ベビィポケモンの　とくせい"),
        .desc = COMPOUND_STRING("ピチューの　とくせいは　せいでんき\nピィの　とくせいは　メロメロボディ\nププリンの　とくせいは　メロメロボディ\nバルキーの　とくせいは　こんじょう\nムチュールの　とくせいは　どんかん\nエレキッドの　とくせいは　せいでんき\nブビィの　とくせいは　ほのおのからだ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("ベビィポケモンの　タイプ"),
        .desc = COMPOUND_STRING("ピチューは　でんきタイプ\nピィは　ノーマルタイプ\nププリンは　ノーマルタイプ\nバルキーは　かくとうタイプ\nムチュールは　こおりタイプ\nエレキッドは　でんきタイプ\nブビィは　ほのおタイプ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("ベビィポケモンの　なきごえ"),
        .desc = COMPOUND_STRING("ピチューは　ワーン\nピィは　キャッ\nププリンは　ラララ\nバルキーは　ハイヤッ\nムチュールは　エヘヘ\nエレキッドは　オイ　オイ　オイ\nブビィは　チッ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("ベビィポケモンの　すること"),
        .desc = COMPOUND_STRING("ピチューは　いちにちじゅう　あそぶ\nピィは　つきを　みあげる\nププリンは　みんなを　ねむらせる\nバルキーは　いつも　とっくん\nムチュールは　みせびらかすのが　すき\nエレキッドは　でんきを　ためる\nブビィは　よく　おこる"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("えさば　ふつうの　ポロック"),
        .desc = COMPOUND_STRING("ポロックの　いろで　さいこうの　こたいちが\n3つの　ポケモンを　よぶ　H　HP　A　こうげき\nB　ぼうぎょ　C　とくこう　D　とくぼう　S　すばやさ\nあか　HAS　あお　HCS　ピンク　ACS\nみどり　HBD　きいろ　HAB　むらさき　ABD\nあい　HCD　ちゃ　BSD　みずいろ　CSD\nオリーブ　ABS　はいいろ　HAC\nどの　ポロックも　かくれとくせいを　よぶ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("えさば　きんの　ポロック"),
        .desc = COMPOUND_STRING("きんの　ポロックは　さいこうの\nこたいちが　5つ　ある　ポケモンを　よぶ\nあじで　さいこうで　ない　ものが　きまる\nからい　とくこう　しぶい　こうげき\nあまい　とくぼう　にがい　すばやさ\nすっぱい　HP\nどの　ポロックも　かくれとくせいを　よぶ"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
