# ハート＆ソウル カントー＆ジョウト（逆走パッチ）作業メモ

ブランチ: kanto-johto（HeartSoul-JP の main から）

## 方針（決まったこと）
- 最初のカントー編は、リポジトリに入っている FRLG（ファイアレッド）のカントー（マップ・話・トレーナー）を hns ビルドに入れて使う
- 主人公と話の流れはクリスタル カントー＆ジョウト（サトシMOD）と同じ：サトシ（名前は選べる）・初代御三家・ライバルはシゲル・ムサシとコジロウ
- カントーの殿堂入り → オーキドから船のチケット → 3年後、ワカバタウン（ウツギ博士）からジョウト編。手持ちはそのまま
- ジョウト編のあとのカントーは、ハート＆ソウルの 3年後のカントー（*_hns のマップ）

## ビルド
    tools_kj/build.sh        （生成物を作り直して make hns）
  arm-none-eabi-gcc 14.2.1（xPack）

## しくみ（tools_kj/）
- kanto_maps.py   ……カントー編で使う FRLG マップ（セブンアイランド等を除く 253 マップ）
                     → data/maps/kj_frlg_maps.txt・data/layouts/kj_frlg_layouts.txt
- tools/mapjson   ……hns ビルドでも上の許可リストの FRLG マップ・レイアウトを入れる
- gen_includes.py ……FRLG マップのスクリプトと共通スクリプトの include（data/kj_frlg_scripts.inc）
- gen_trainers.py ……使う FRLG トレーナー（439人）を hns の表のうしろに足す
                     （include/constants/opponents_kj.h・src/data/trainers_kj.party）
                     番号 864 以降のトレーナーフラグは ENGINE_FLAGS のうしろ（KJ_TRAINER_FLAGS_START、TRAINER_FLAG_ID）
- gen_vars.py     ……FRLG の変数（42）を hns の空き変数（34）とジョウト専用の変数（8、KJ_SHARED_VARS_LIST）に割り当てる
                     ジョウト編に入るとき KJ_SHARED_VARS_LIST を 0 に戻す（まだ）
- gen_flags.py    ……FRLG のフラグ（496）を FLAG_KJ_* にして、拡張フラグ（KJ_FRLG_FLAGS_START〜）に置く
                     （hns の flags_hns.h では FRLG のフラグ名の多くが 0 になっていたため）
- gen_tilesets.py ……使う FRLG タイルセット（51）を src/data/tilesets/kj_frlg.h に（属性は ALIGNED(4)）
- patch_frlg_scripts.py ……FRLG のバッジ 1〜8 → hns のカントーのバッジ 9〜16
- prune_common.py ……共通スクリプトからセブンアイランドの分を除く
- fix_labels.py   ……hns とぶつかるラベルは FRLG 側を 〜_Kj に
- FRLG の人の絵（object_events の IS_FRLG ブロック）は hns でも入れる
- フラグ: FLAG_KJ_JOHTO_STARTED・FLAG_KJ_KANTO_CHAMPION（include/constants/flags_kj.h）
- カントーのライバルの名前: SaveBlock1.kjKantoRivalName（ジョウト編の前は {RIVAL} がこれ）

## 進み具合
- [x] FRLG カントー入りでビルドが通る（ROM 31.0MB 使用）
- [x] ニューゲームがマサラタウンの自分の部屋から始まる。1階・外・オーキドのイベントまで動く
- [x] 会話の日本語化：日本版ファイアレッドから取り出して入れた（2881 文。残りは看板などの共通文・通信クラブ）
      tools_kj/jp/: walk.py（pokefirered と日本版のスクリプトを並べてたどり、会話の番地を求める）→ fill.py → apply_jp.py
- [x] 研究所で御三家を選び、ライバル戦（シゲル）まで動く
- [ ] オープニング（名前入力にサトシ・ライバルの名前入力）
- [ ] 初代御三家・シゲル・ムサシとコジロウ
- [ ] ひでんわざをカントーのバッジで使えるように
- [ ] 殿堂入り → 3年後 → ワカバへ
- [ ] ジョウト後のカントーのジムリーダーなどを「3年後」に合わせる
- [ ] 通しの確認

## テスト
- tools_kj/harness（mGBA のライブラリと組む run.c、g.py・walk.py・intro.sh・m.py）。defs.txt の設定で libmgba.a と組む
