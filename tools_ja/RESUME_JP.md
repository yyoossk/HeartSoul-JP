# 日本語化の再開メモ

- 作業ブランチ: ja-main（GitHub の main に push）
- ツール一式: このフォルダ（tools_ja）。作業時は /home/claude/work にコピーして使う。
- ビルド: `make hns`（arm-none-eabi-gcc 14.2.1）
- 翻訳の流れ:
  1. `python3 -I next.py 17000 > /tmp/next.txt` で未訳のマップ文を取り出す（map_order.txt の順）
  2. `tr/mNNN.txt` に `## パス` と `@@ラベル` 形式で訳を書く（1行26文字以内、\n \l \p、句読点なし・スペース区切り）
  3. `python3 -I reinsert.py` で確認 → `python3 -I reinsert.py write` で反映 → ビルド
  4. `python3 -I progress.py` で進み具合
- 使えない文字: 、 ％ 〜 （） ＆ → 漢字（一 など）。ASCII の ':' は可
- 進み具合: マップ会話 67.9%（tr/m020.txt まで）。次はトレーナーヒル・アクア号・最果ての孤島・バトルフロンティア以降
- 残り: マップ会話の残り → data/text・data/scripts の残り → src の C 文字列（地名・メニューなど）→ 説明文（道具・わざ・特性・図鑑）→ 画面確認 → 日本版エメラルド用 BPS パッチ
