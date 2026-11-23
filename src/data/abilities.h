const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("とくべつな　ちからは　ない"),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("あくしゅう"),
        .description = COMPOUND_STRING("あいてをひるませることがある"),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("あめふらし"),
        .description = COMPOUND_STRING("あめを　ふらせる"),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("かそく"),
        .description = COMPOUND_STRING("すばやさが　だんだん　あがる"),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("カブトアーマー"),
        .description = COMPOUND_STRING("きゅうしょに　あたらない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("がんじょう"),
        .description = COMPOUND_STRING("いちげきわざが　きかない"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("しめりけ"),
        .description = COMPOUND_STRING("じばくを　させない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("じゅうなん"),
        .description = COMPOUND_STRING("まひ　しない"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("すながくれ"),
        .description = COMPOUND_STRING("すなあらしでかいひりつがあがる"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("せいでんき"),
        .description = COMPOUND_STRING("さわると　まひ　させる"),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("ちくでん"),
        .description = COMPOUND_STRING("でんきで　HPが　かいふく"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("ちょすい"),
        .description = COMPOUND_STRING("みずで　HPが　かいふく"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("どんかん"),
        .description = COMPOUND_STRING("メロメロに　ならない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("ノーてんき"),
        .description = COMPOUND_STRING("てんきの　えいきょうを　けす"),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("ふくがん"),
        .description = COMPOUND_STRING("めいちゅうりつが　あがる"),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("ふみん"),
        .description = COMPOUND_STRING("ねむらない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("へんしょく"),
        .description = COMPOUND_STRING("うけた　わざの　タイプに　なる"),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("めんえき"),
        .description = COMPOUND_STRING("どくに　ならない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("もらいび"),
        .description = COMPOUND_STRING("ほのおで　パワーアップ"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("りんぷん"),
        .description = COMPOUND_STRING("わざの　ついかこうかを　うけない"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("マイペース"),
        .description = COMPOUND_STRING("こんらん　しない"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("きゅうばん"),
        .description = COMPOUND_STRING("じめんに　すいつく"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("いかく"),
        .description = COMPOUND_STRING("あいての　こうげきを　さげる"),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("かげふみ"),
        .description = COMPOUND_STRING("あいてを　にがさない"),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("さめはだ"),
        .description = COMPOUND_STRING("さわると　きずつく"),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("ふしぎなまもり"),
        .description = COMPOUND_STRING("ばつぐんの　わざしか　あたらない"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("ふゆう"),
        .description = COMPOUND_STRING("じめんわざが　あたらない"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("ほうし"),
        .description = COMPOUND_STRING("さわると　ほうしを　まく"),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("シンクロ"),
        .description = COMPOUND_STRING("じょうたいいじょうを　うつす"),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("クリアボディ"),
        .description = COMPOUND_STRING("のうりょくを　さげられない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("しぜんかいふく"),
        .description = COMPOUND_STRING("ひっこむと　かいふく　する"),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("ひらいしん"),
        .description = COMPOUND_STRING("でんきわざを　ひきよせる"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("てんのめぐみ"),
        .description = COMPOUND_STRING("ついかこうかが　でやすい"),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("すいすい"),
        .description = COMPOUND_STRING("あめで　すばやさが　あがる"),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("ようりょくそ"),
        .description = COMPOUND_STRING("はれで　すばやさが　あがる"),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("はっこう"),
        .description = COMPOUND_STRING("であう　かくりつが　あがる"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("トレース"),
        .description = COMPOUND_STRING("あいての　とくせいを　コピー"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("ちからもち"),
        .description = COMPOUND_STRING("こうげきが　あがる"),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("どくのトゲ"),
        .description = COMPOUND_STRING("さわると　どくに　する"),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("せいしんりょく"),
        .description = COMPOUND_STRING("ひるまない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("マグマのよろい"),
        .description = COMPOUND_STRING("こおらない"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("みずのベール"),
        .description = COMPOUND_STRING("やけど　しない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("じりょく"),
        .description = COMPOUND_STRING("はがねタイプを　にがさない"),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("ぼうおん"),
        .description = COMPOUND_STRING("おとの　わざを　うけない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("あめうけざら"),
        .description = COMPOUND_STRING("あめで　すこし　かいふく"),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("すなおこし"),
        .description = COMPOUND_STRING("すなあらしを　おこす"),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("プレッシャー"),
        .description = COMPOUND_STRING("あいての　PPを　おおく　へらす"),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("あついしぼう"),
        .description = COMPOUND_STRING("ほのおと　こおりに　つよい"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("はやおき"),
        .description = COMPOUND_STRING("すぐに　めを　さます"),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("ほのおのからだ"),
        .description = COMPOUND_STRING("さわると　やけどさせる"),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("にげあし"),
        .description = COMPOUND_STRING("にげやすく　なる"),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("するどいめ"),
        .description = COMPOUND_STRING("めいちゅうりつを　さげられない"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("かいりきバサミ"),
        .description = COMPOUND_STRING("こうげきを　さげられない"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("ものひろい"),
        .description = COMPOUND_STRING("どうぐを　ひろう　ことが　ある"),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("なまけ"),
        .description = COMPOUND_STRING("2ターンに1かいしかうごけない"),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("はりきり"),
        .description = COMPOUND_STRING("めいちゅうをさげていりょくアップ"),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("メロメロボディ"),
        .description = COMPOUND_STRING("さわると　メロメロに　する"),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("プラス"),
        .description = COMPOUND_STRING("マイナスといっしょでパワーアップ"),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("マイナス"),
        .description = COMPOUND_STRING("プラスといっしょでパワーアップ"),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("てんきや"),
        .description = COMPOUND_STRING("てんきで　すがたが　かわる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("ねんちゃく"),
        .description = COMPOUND_STRING("どうぐを　とられない"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("だっぴ"),
        .description = COMPOUND_STRING("だっぴして　なおす"),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("こんじょう"),
        .description = COMPOUND_STRING("じょうたいいじょうでこうげきアップ"),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("ふしぎなうろこ"),
        .description = COMPOUND_STRING("じょうたいいじょうでぼうぎょアップ"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("ヘドロえき"),
        .description = COMPOUND_STRING("すいとられると　きずつける"),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("しんりょく"),
        .description = COMPOUND_STRING("ピンチでくさわざがつよくなる"),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("もうか"),
        .description = COMPOUND_STRING("ピンチでほのおわざがつよくなる"),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("げきりゅう"),
        .description = COMPOUND_STRING("ピンチでみずわざがつよくなる"),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("むしのしらせ"),
        .description = COMPOUND_STRING("ピンチでむしわざがつよくなる"),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("いしあたま"),
        .description = COMPOUND_STRING("はんどうを　うけない"),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("ひでり"),
        .description = COMPOUND_STRING("ひざしを　つよく　する"),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("ありじごく"),
        .description = COMPOUND_STRING("あいてを　にがさない"),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("やるき"),
        .description = COMPOUND_STRING("ねむらない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("しろいけむり"),
        .description = COMPOUND_STRING("のうりょくを　さげられない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("ヨガパワー"),
        .description = COMPOUND_STRING("こうげきが　あがる"),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("シェルアーマー"),
        .description = COMPOUND_STRING("きゅうしょに　あたらない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("エアロック"),
        .description = COMPOUND_STRING("てんきの　えいきょうを　けす"),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("ちどりあし"),
        .description = COMPOUND_STRING("こんらんで　かいひりつが　あがる"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("でんきエンジン"),
        .description = COMPOUND_STRING("でんきで　すばやさが　あがる"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("とうそうしん"),
        .description = COMPOUND_STRING("おなじ　せいべつに　つよい"),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("ふくつのこころ"),
        .description = COMPOUND_STRING("ひるむと　すばやさが　あがる"),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("ゆきがくれ"),
        .description = COMPOUND_STRING("あられ　ゆきで　かいひりつアップ"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("くいしんぼう"),
        .description = COMPOUND_STRING("きのみを　はやめに　たべる"),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("いかりのつぼ"),
        .description = COMPOUND_STRING("きゅうしょで　こうげきが　あがる"),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("かるわざ"),
        .description = COMPOUND_STRING("どうぐをつかうとすばやさアップ"),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("たいねつ"),
        .description = COMPOUND_STRING("ほのおと　やけどに　つよい"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("たんじゅん"),
        .description = COMPOUND_STRING("のうりょくへんかが　はげしい"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("かんそうはだ"),
        .description = COMPOUND_STRING("はれに　よわく　あめに　つよい"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("ダウンロード"),
        .description = COMPOUND_STRING("いりょくを　つごうよく　かえる"),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("てつのこぶし"),
        .description = COMPOUND_STRING("パンチわざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("ポイズンヒール"),
        .description = COMPOUND_STRING("どくで　HPが　かいふく"),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("てきおうりょく"),
        .description = COMPOUND_STRING("おなじ　タイプの　わざが　つよい"),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("スキルリンク"),
        .description = COMPOUND_STRING("れんぞくわざが　5かい　あたる"),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("うるおいボディ"),
        .description = COMPOUND_STRING("あめでじょうたいいじょうがなおる"),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("サンパワー"),
        .description = COMPOUND_STRING("はれで　パワーアップ"),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("はやあし"),
        .description = COMPOUND_STRING("じょうたいいじょうですばやさアップ"),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("ノーマルスキン"),
        .description = COMPOUND_STRING("わざが　ノーマルタイプに　なる"),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("スナイパー"),
        .description = COMPOUND_STRING("きゅうしょの　いりょくアップ"),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("マジックガード"),
        .description = COMPOUND_STRING("こうげきわざでしかきずつかない"),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("ノーガード"),
        .description = COMPOUND_STRING("わざが　かならず　あたる"),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("あとだし"),
        .description = COMPOUND_STRING("いつも　さいごに　うごく"),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("テクニシャン"),
        .description = COMPOUND_STRING("いりょくのひくいわざがつよい"),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("リーフガード"),
        .description = COMPOUND_STRING("はれでじょうたいいじょうにならない"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("ぶきよう"),
        .description = COMPOUND_STRING("もちものを　つかえない"),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("かたやぶり"),
        .description = COMPOUND_STRING("とくせいを　むしして　こうげき"),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("きょううん"),
        .description = COMPOUND_STRING("きゅうしょに　あたりやすい"),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("ゆうばく"),
        .description = COMPOUND_STRING("たおれると　あいてに　ダメージ"),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("きけんよち"),
        .description = COMPOUND_STRING("きけんな　わざを　さっちする"),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("よちむ"),
        .description = COMPOUND_STRING("あいての　わざを　1つ　みぬく"),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("てんねん"),
        .description = COMPOUND_STRING("あいてののうりょくへんかをむし"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("いろめがね"),
        .description = COMPOUND_STRING("いまひとつのわざがつよくなる"),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("フィルター"),
        .description = COMPOUND_STRING("ばつぐんの　ダメージを　へらす"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("スロースタート"),
        .description = COMPOUND_STRING("なかなか　ちょうしが　でない"),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("きもったま"),
        .description = COMPOUND_STRING("ゴーストタイプにも　あたる"),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("よびみず"),
        .description = COMPOUND_STRING("みずわざを　ひきよせる"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("アイスボディ"),
        .description = COMPOUND_STRING("あられ　ゆきで　かいふく"),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("ハードロック"),
        .description = COMPOUND_STRING("ばつぐんの　ダメージを　へらす"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("ゆきふらし"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("ゆきを　ふらせる"),
    #else
        .description = COMPOUND_STRING("あられを　ふらせる"),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("みつあつめ"),
        .description = COMPOUND_STRING("あまいミツを　あつめる"),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("おみとおし"),
        .description = COMPOUND_STRING("あいての　もちものが　わかる"),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("すてみ"),
        .description = COMPOUND_STRING("はんどうの　ある　わざが　つよい"),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("マルチタイプ"),
        .description = COMPOUND_STRING("プレートで　タイプが　かわる"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("フラワーギフト"),
        .description = COMPOUND_STRING("はれで　みかたが　つよく　なる"),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("ナイトメア"),
        .description = COMPOUND_STRING("ねむった　あいてに　ダメージ"),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("わるいてぐせ"),
        .description = COMPOUND_STRING("あいての　もちものを　うばう"),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("ちからずく"),
        .description = COMPOUND_STRING("ついかこうかを　なくして　つよく"),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("あまのじゃく"),
        .description = COMPOUND_STRING("のうりょくへんかがぎゃくになる"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("きんちょうかん"),
        .description = COMPOUND_STRING("あいては　きのみを　たべられない"),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("まけんき"),
        .description = COMPOUND_STRING("さげられると　こうげきアップ"),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("よわき"),
        .description = COMPOUND_STRING("HPがはんぶんでやるきをなくす"),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("のろわれボディ"),
        .description = COMPOUND_STRING("さわると　わざを　ふうじる"),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("いやしのこころ"),
        .description = COMPOUND_STRING("みかたを　かいふく　する"),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("フレンドガード"),
        .description = COMPOUND_STRING("みかたの　ダメージを　へらす"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("くだけるよろい"),
        .description = COMPOUND_STRING("うけると　のうりょくが　かわる"),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("ヘヴィメタル"),
        .description = COMPOUND_STRING("おもさが　2ばいに　なる"),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("ライトメタル"),
        .description = COMPOUND_STRING("おもさが　はんぶんに　なる"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("マルチスケイル"),
        .description = COMPOUND_STRING("HPまんたんでダメージはんぶん"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("どくぼうそう"),
        .description = COMPOUND_STRING("どくで　こうげきが　あがる"),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("ねつぼうそう"),
        .description = COMPOUND_STRING("やけどで　とくこうが　あがる"),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("しゅうかく"),
        .description = COMPOUND_STRING("つかった　きのみを　つくりなおす"),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("テレパシー"),
        .description = COMPOUND_STRING("みかたの　こうげきを　うけない"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("ムラっけ"),
        .description = COMPOUND_STRING("のうりょくが　すこしずつ　かわる"),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("ぼうじん"),
        .description = COMPOUND_STRING("てんきと　こなを　ふせぐ"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("どくしゅ"),
        .description = COMPOUND_STRING("さわると　どくに　する"),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("さいせいりょく"),
        .description = COMPOUND_STRING("ひっこむと　かいふく　する"),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("はとむね"),
        .description = COMPOUND_STRING("ぼうぎょを　さげられない"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("すなかき"),
        .description = COMPOUND_STRING("すなあらしで　すばやさアップ"),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("ミラクルスキン"),
        .description = COMPOUND_STRING("じょうたいいじょうをさけることも"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("アナライズ"),
        .description = COMPOUND_STRING("さいごにうごくといりょくアップ"),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("イリュージョン"),
        .description = COMPOUND_STRING("なかまの　すがたで　あらわれる"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("かわりもの"),
        .description = COMPOUND_STRING("あいてに　へんしん　する"),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("すりぬけ"),
        .description = COMPOUND_STRING("かべを　すりぬける"),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("ミイラ"),
        .description = COMPOUND_STRING("さわると　うつる"),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("じしんかじょう"),
        .description = COMPOUND_STRING("たおすと　こうげきアップ"),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("せいぎのこころ"),
        .description = COMPOUND_STRING("あくわざで　こうげきアップ"),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("びびり"),
        .description = COMPOUND_STRING("こわがると　すばやさアップ"),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("マジックミラー"),
        .description = COMPOUND_STRING("へんかわざを　はねかえす"),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("そうしょく"),
        .description = COMPOUND_STRING("くさで　こうげきアップ"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("いたずらごころ"),
        .description = COMPOUND_STRING("へんかわざが　せんせいに　なる"),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("すなのちから"),
        .description = COMPOUND_STRING("すなあらしで　パワーアップ"),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("てつのトゲ"),
        .description = COMPOUND_STRING("さわると　きずつく"),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("ダルマモード"),
        .description = COMPOUND_STRING("HPはんぶんで　すがたが　かわる"),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("しょうりのほし"),
        .description = COMPOUND_STRING("みかたの　めいちゅうりつアップ"),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("ターボブレイズ"),
        .description = COMPOUND_STRING("とくせいを　むしして　こうげき"),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("テラボルテージ"),
        .description = COMPOUND_STRING("とくせいを　むしして　こうげき"),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("アロマベール"),
        .description = COMPOUND_STRING("わざを　ふうじられない"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("フラワーベール"),
        .description = COMPOUND_STRING("くさタイプを　まもる"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("ほおぶくろ"),
        .description = COMPOUND_STRING("きのみで　HPを　かいふく"),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("へんげんじざい"),
        .description = COMPOUND_STRING("つかう　わざの　タイプに　なる"),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("ファーコート"),
        .description = COMPOUND_STRING("ぼうぎょが　あがる"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("マジシャン"),
        .description = COMPOUND_STRING("あいての　もちものを　うばう"),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("ぼうだん"),
        .description = COMPOUND_STRING("いくつかのたまのわざをふせぐ"),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("かちき"),
        .description = COMPOUND_STRING("さげられると　とくこうアップ"),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("がんじょうあご"),
        .description = COMPOUND_STRING("かむ　わざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("フリーズスキン"),
        .description = COMPOUND_STRING("ノーマルわざが　こおりに　なる"),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("スイートベール"),
        .description = COMPOUND_STRING("みかたを　ねむらせない"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("バトルスイッチ"),
        .description = COMPOUND_STRING("たたかうと　すがたが　かわる"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("はやてのつばさ"),
        .description = COMPOUND_STRING("ひこうわざが　せんせいに　なる"),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("メガランチャー"),
        .description = COMPOUND_STRING("はどうの　わざが　つよく　なる"),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("くさのけがわ"),
        .description = COMPOUND_STRING("くさで　ぼうぎょアップ"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("きょうせい"),
        .description = COMPOUND_STRING("みかたに　どうぐを　わたす"),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("かたいツメ"),
        .description = COMPOUND_STRING("せっしょくわざが　つよく　なる"),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("フェアリースキン"),
        .description = COMPOUND_STRING("ノーマルわざがフェアリーになる"),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("ぬめぬめ"),
        .description = COMPOUND_STRING("さわると　すばやさを　さげる"),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("スカイスキン"),
        .description = COMPOUND_STRING("ノーマルわざが　ひこうに　なる"),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("おやこあい"),
        .description = COMPOUND_STRING("わざが　2かい　あたる"),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("ダークオーラ"),
        .description = COMPOUND_STRING("あくわざが　つよく　なる"),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("フェアリーオーラ"),
        .description = COMPOUND_STRING("フェアリーわざが　つよく　なる"),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("オーラブレイク"),
        .description = COMPOUND_STRING("オーラのこうかをぎゃくにする"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("はじまりのうみ"),
        .description = COMPOUND_STRING("おおあめを　ふらせる"),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("おわりのだいち"),
        .description = COMPOUND_STRING("ひざしを　とても　つよく　する"),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("デルタストリーム"),
        .description = COMPOUND_STRING("らんきりゅうを　おこす"),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("じきゅうりょく"),
        .description = COMPOUND_STRING("うけると　ぼうぎょアップ"),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("にげごし"),
        .description = COMPOUND_STRING("HPはんぶんで　にげだす"),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("ききかいひ"),
        .description = COMPOUND_STRING("HPはんぶんで　にげだす"),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("みずがため"),
        .description = COMPOUND_STRING("みずで　ぼうぎょアップ"),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("ひとでなし"),
        .description = COMPOUND_STRING("どくの　あいてに　きゅうしょ"),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("リミットシールド"),
        .description = COMPOUND_STRING("HPはんぶんで　からが　われる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("はりこみ"),
        .description = COMPOUND_STRING("あいてが　かわると　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("すいほう"),
        .description = COMPOUND_STRING("ほのおと　やけどから　まもる"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("はがねつかい"),
        .description = COMPOUND_STRING("はがねわざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("ぎゃくじょう"),
        .description = COMPOUND_STRING("HPがすくないととくこうアップ"),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("ゆきかき"),
        .description = COMPOUND_STRING("あられ　ゆきで　すばやさアップ"),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("えんかく"),
        .description = COMPOUND_STRING("せっしょく　しない"),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("うるおいボイス"),
        .description = COMPOUND_STRING("おとの　わざが　みずに　なる"),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("ヒーリングシフト"),
        .description = COMPOUND_STRING("かいふくわざが　せんせいに　なる"),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("エレキスキン"),
        .description = COMPOUND_STRING("ノーマルわざが　でんきに　なる"),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("サーフテール"),
        .description = COMPOUND_STRING("でんきで　すばやく　なる"),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("ぎょぐん"),
        .description = COMPOUND_STRING("つよいと　むれに　なる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("ばけのかわ"),
        .description = COMPOUND_STRING("みがわりで　1かい　まもる"),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("きずなへんげ"),
        .description = COMPOUND_STRING("たおすと　すがたが　かわる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("スワームチェンジ"),
        .description = COMPOUND_STRING("よわると　セルが　たすける"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("ふしょく"),
        .description = COMPOUND_STRING("どんな　タイプでも　どくに　する"),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("ぜったいねむり"),
        .description = COMPOUND_STRING("いつも　ねむっている"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("じょおうのいげん"),
        .description = COMPOUND_STRING("せんせいわざを　ふせぐ"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("とびだすなかみ"),
        .description = COMPOUND_STRING("たおされると　ダメージ"),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("おどりこ"),
        .description = COMPOUND_STRING("ほかの　おどりに　あわせる"),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("バッテリー"),
        .description = COMPOUND_STRING("みかたの　とくこうアップ"),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("もふもふ"),
        .description = COMPOUND_STRING("かたいが　ほのおに　よわい"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("ビビッドボディ"),
        .description = COMPOUND_STRING("せんせいわざを　ふせぐ"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("ソウルハート"),
        .description = COMPOUND_STRING("たおすと　とくこうアップ"),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("カーリーヘアー"),
        .description = COMPOUND_STRING("さわると　すばやさを　さげる"),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("レシーバー"),
        .description = COMPOUND_STRING("みかたの　とくせいを　コピー"),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("かがくのちから"),
        .description = COMPOUND_STRING("みかたの　とくせいを　コピー"),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("ビーストブースト"),
        .description = COMPOUND_STRING("たおすといちばんたかいのうりょくアップ"),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("ARシステム"),
        .description = COMPOUND_STRING("メモリで　タイプが　かわる"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("エレキメイカー"),
        .description = COMPOUND_STRING("エレキフィールドに　なる"),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("サイコメイカー"),
        .description = COMPOUND_STRING("サイコフィールドに　なる"),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("ミストメイカー"),
        .description = COMPOUND_STRING("ミストフィールドに　なる"),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("グラスメイカー"),
        .description = COMPOUND_STRING("グラスフィールドに　なる"),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("メタルプロテクト"),
        .description = COMPOUND_STRING("のうりょくを　さげられない"),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("ファントムガード"),
        .description = COMPOUND_STRING("HPまんたんでダメージはんぶん"),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("プリズムアーマー"),
        .description = COMPOUND_STRING("ばつぐんの　ダメージを　へらす"),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("ブレインフォース"),
        .description = COMPOUND_STRING("ばつぐんの　わざが　つよい"),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("ふとうのけん"),
        .description = COMPOUND_STRING("でると　こうげきアップ"),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("ふくつのたて"),
        .description = COMPOUND_STRING("でると　ぼうぎょアップ"),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("リベロ"),
        .description = COMPOUND_STRING("わざの　タイプに　なる"),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("たまひろい"),
        .description = COMPOUND_STRING("しっぱいした　ボールを　ひろう"),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("わたげ"),
        .description = COMPOUND_STRING("うけるとみんなのすばやさダウン"),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("スクリューおびれ"),
        .description = COMPOUND_STRING("ひきよせる　こうかを　むし"),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("ミラーアーマー"),
        .description = COMPOUND_STRING("のうりょくダウンを　はねかえす"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("うのミサイル"),
        .description = COMPOUND_STRING("うけると　えものを　はきだす"),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("すじがねいり"),
        .description = COMPOUND_STRING("ひきよせる　こうかを　むし"),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("じょうききかん"),
        .description = COMPOUND_STRING("ほのおか　みずで　すばやさアップ"),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("パンクロック"),
        .description = COMPOUND_STRING("おとわざがつよくおとにつよい"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("すなはき"),
        .description = COMPOUND_STRING("うけると　すなあらしを　おこす"),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("こおりのりんぷん"),
        .description = COMPOUND_STRING("とくしゅの　ダメージ　はんぶん"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("じゅくせい"),
        .description = COMPOUND_STRING("きのみの　こうかが　2ばい"),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("アイスフェイス"),
        .description = COMPOUND_STRING("あられ　ゆきで　つぎも　まもる"),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("パワースポット"),
        .description = COMPOUND_STRING("みかたの　わざが　つよく　なる"),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("ぎたい"),
        .description = COMPOUND_STRING("フィールドで　タイプが　かわる"),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("バリアフリー"),
        .description = COMPOUND_STRING("ひかりの　かべを　こわす"),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("はがねのせいしん"),
        .description = COMPOUND_STRING("みかたの　はがねわざアップ"),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("ほろびのボディ"),
        .description = COMPOUND_STRING("うけると　3ターンで　ほろびる"),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("さまようたましい"),
        .description = COMPOUND_STRING("さわると　とくせいを　こうかん"),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("ごりむちゅう"),
        .description = COMPOUND_STRING("こうげきアップ　わざが　こてい"),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("かがくへんかガス"),
        .description = COMPOUND_STRING("すべての　とくせいを　けす"),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("パステルベール"),
        .description = COMPOUND_STRING("みかたを　どくから　まもる"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("はらぺこスイッチ"),
        .description = COMPOUND_STRING("まいターン　すがたが　かわる"),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("クイックドロウ"),
        .description = COMPOUND_STRING("ときどき　さきに　うごく"),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("ふかしのこぶし"),
        .description = COMPOUND_STRING("まもるを　むしして　せっしょく"),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("きみょうなくすり"),
        .description = COMPOUND_STRING("みかたののうりょくへんかをけす"),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("トランジスタ"),
        .description = COMPOUND_STRING("でんきわざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("りゅうのあぎと"),
        .description = COMPOUND_STRING("ドラゴンわざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("しろのいななき"),
        .description = COMPOUND_STRING("たおすと　こうげきアップ"),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("くろのいななき"),
        .description = COMPOUND_STRING("たおすと　とくこうアップ"),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("じんばいったい"),
        .description = COMPOUND_STRING("きんちょうかんと　しろのいななき"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("じんばいったい"),
        .description = COMPOUND_STRING("きんちょうかんと　くろのいななき"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("とれないにおい"),
        .description = COMPOUND_STRING("さわると　うつる"),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("こぼれダネ"),
        .description = COMPOUND_STRING("うけると　フィールドが　かわる"),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("ねつこうかん"),
        .description = COMPOUND_STRING("ほのおで　こうげきアップ"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("いかりのこうら"),
        .description = COMPOUND_STRING("HPはんぶんで　いかる"),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("きよめのしお"),
        .description = COMPOUND_STRING("しおで　まもられる"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("こんがりボディ"),
        .description = COMPOUND_STRING("ほのおで　つよく　なる"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("かぜのり"),
        .description = COMPOUND_STRING("かぜで　こうげきアップ"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("ばんけん"),
        .description = COMPOUND_STRING("いかくが　きかない"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("いわはこび"),
        .description = COMPOUND_STRING("いわわざが　つよく　なる"),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("ふうりょくでんき"),
        .description = COMPOUND_STRING("かぜで　じゅうでん　する"),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("マイティチェンジ"),
        .description = COMPOUND_STRING("ひっこむと　すがたが　かわる"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("しれいとう"),
        .description = COMPOUND_STRING("ヘイラッシャに　しれいを　だす"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("でんきにかえる"),
        .description = COMPOUND_STRING("うけると　じゅうでん　する"),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("こだいかっせい"),
        .description = COMPOUND_STRING("はれでいちばんたかいのうりょくアップ"),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("クォークチャージ"),
        .description = COMPOUND_STRING("エレキでいちばんたかいのうりょくアップ"),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("おうごんのからだ"),
        .description = COMPOUND_STRING("へんかわざを　さける"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("わざわいのうつわ"),
        .description = COMPOUND_STRING("あいてのとくしゅダメージをへらす"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("わざわいのつるぎ"),
        .description = COMPOUND_STRING("あいての　ぼうぎょを　さげる"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("わざわいのおふだ"),
        .description = COMPOUND_STRING("あいての　ダメージを　へらす"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("わざわいのたま"),
        .description = COMPOUND_STRING("あいての　とくぼうを　さげる"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("ひひいろのこどう"),
        .description = COMPOUND_STRING("ひざしを　つよく　する"),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("ハドロンエンジン"),
        .description = COMPOUND_STRING("エレキフィールドに　なる"),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("びんじょう"),
        .description = COMPOUND_STRING("あいてののうりょくへんかをまねる"),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("はんすう"),
        .description = COMPOUND_STRING("つかった　きのみを　また　たべる"),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("きれあじ"),
        .description = COMPOUND_STRING("きる　わざが　つよく　なる"),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("そうだいしょう"),
        .description = COMPOUND_STRING("たおれたなかまのちからをうけつぐ"),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("きょうえん"),
        .description = COMPOUND_STRING("みかたののうりょくへんかをまねる"),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("どくげしょう"),
        .description = COMPOUND_STRING("うけると　どくびしを　まく"),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("テイルアーマー"),
        .description = COMPOUND_STRING("せんせいわざを　ふせぐ"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("どしょく"),
        .description = COMPOUND_STRING("じめんを　たべて　かいふく"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("きんしのちから"),
        .description = COMPOUND_STRING("へんかわざが　かならず　きまる"),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("おもてなし"),
        .description = COMPOUND_STRING("みかたの　HPを　かいふく"),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("しんがん"),
        .description = COMPOUND_STRING("するどいめと　きもったま"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("おもかげやどし"),
        .description = COMPOUND_STRING("すばやさが　あがる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("おもかげやどし"),
        .description = COMPOUND_STRING("こうげきが　あがる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("おもかげやどし"),
        .description = COMPOUND_STRING("とくぼうが　あがる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("おもかげやどし"),
        .description = COMPOUND_STRING("ぼうぎょが　あがる"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("どくのくさり"),
        .description = COMPOUND_STRING("わざでどくにすることがある"),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("かんろなミツ"),
        .description = COMPOUND_STRING("あいての　かいひりつを　さげる"),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("テラスチェンジ"),
        .description = COMPOUND_STRING("でると　テラスタル　する"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("テラスシェル"),
        .description = COMPOUND_STRING("HPまんたんで　すべてに　つよい"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("ゼロフォーミング"),
        .description = COMPOUND_STRING("てんきと　フィールドを　けす"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("どくくぐつ"),
        .description = COMPOUND_STRING("どくのあいてをこんらんさせる"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
