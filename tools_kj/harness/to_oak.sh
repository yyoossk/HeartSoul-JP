#!/bin/bash
# to_oak.sh ROM 名前 : ニューゲームからマサラの北（オーキドが止めるマス）の手前まで
H=/home/claude/harness
$H/intro.sh "$1" "$2" >/dev/null
python3 $H/walk.py "$1" "$2" "R1 U4 D2 R3 U2 R1" >/dev/null
python3 $H/g.py "$1" "$2" "hL:8 w8 hL:8 w120"
python3 $H/walk.py "$1" "$2" "D5 L6" >/dev/null
python3 $H/g.py "$1" "$2" "hD:8 w8 hD:12 w150"
python3 $H/walk.py "$1" "$2" "R1 D1 R5 U6"
