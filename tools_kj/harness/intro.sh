#!/bin/bash
# intro.sh ROM 名前 : ニューゲームから自分の部屋まで（名前はサトシ・シゲルのまま）
rm -f "$2.ss" "$2.sav"
python3 /home/claude/harness/g.py "$1" "$2" "w600 A w200 A w120 A w200 A40 w60 A33 w100 S w30 A w60 A w60 A w60 A w60 A w60 w100 S w30 A w60 A w60 A w60 A20 w60 r w60 r w60 r w40 r w40 r w40 r w60 A w60 A w60 A10 w100 A10 w200 pos"
