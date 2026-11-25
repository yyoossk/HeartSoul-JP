#!/bin/bash
# to_rival.sh ROM 名前 : ニューゲームから研究所でゼニガメをもらい、ライバル戦の途中（戦闘画面）まで。名前_battle.png を撮る
H=/home/claude/harness; R=$1; N=$2
cd /tmp
bash $H/to_oak.sh $R $N >/dev/null
python3 $H/g.py $R $N "hU:10 w200 A30 w300 A30 w300 A30 w300" >/dev/null
python3 $H/g.py $R $N "hU:10 w100 A30 w300 A30 w400 A30 w400" >/dev/null
python3 $H/g.py $R $N "A w60 A w60 A w60 A w60 A w60 A w60 A w100 A w60 A w60 A w60 A w60 A w60 A w60 A w100 A w100 A w100 B w30 B w30 B w30 B w60" >/dev/null
python3 $H/walk.py $R $N "D1 R2" >/dev/null
python3 $H/g.py $R $N "hU:3 w10 A w150 A w150 A w100 A w100" >/dev/null
for i in 1 2 3 4 5 6 7 8 9 10 11 12; do python3 $H/g.py $R $N "B w100" >/dev/null; done
python3 $H/walk.py $R $N "L2 D1" >/dev/null
python3 $H/g.py $R $N "hD:16 w100 A w60 A w60 A w60 A w60 A w60 A w300 @battle1 A w200 A w200 @battle2 pos"
