# Pokémon Heart & Soul 日本版エメラルド移植（日本語化）

[Pokémon Heart & Soul](https://github.com/PokemonHnS-Development/pokehns-expansion) v2.0.6 を、日本版エメラルドで遊べるように日本語化したものです。

## ビルド

```
make hns
```

できあがった `pokehns.gba` と日本版エメラルドから BPS パッチを作ります。

## 変更点

- ポケモン・技・特性・道具の名前を日本語に（第3世代までは日本版エメラルドの正式名）
- 文字を日本版エメラルドのフォントで表示（`src/text.c`）
- 日本語フォントに「ヴ」を追加、文字表（`charmap.txt`）に日本語の記号を追加
- 会話・メニューの翻訳（作業中）

## クレジット

元のゲーム：Lil Dill と Heart & Soul 開発チーム。土台：pret/pokeemerald、RHH/pokeemerald-expansion、resetes12/Modern Emerald。
