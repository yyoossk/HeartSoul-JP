#!/bin/bash
# usage: cycle.sh "<msg>" nextfile
cd /home/claude/work && python3 -I reinsert.py write | tail -1 && cd /home/claude/hns2 && export PATH=/tmp/xpack-arm-none-eabi-gcc-14.2.1-1.1/bin:$PATH && make hns -j$(nproc) > /tmp/build2.log 2>&1; grep -n 'rror' /tmp/build2.log | grep -v 'gbagfx\|mid2agb\|_error\|error\.' | head -5; cp /home/claude/work/tr/*.txt tools_ja/tr/; cp /home/claude/work/*.py /home/claude/work/*.txt /home/claude/work/cycle.sh tools_ja/ 2>/dev/null; git add -A && git commit -qm "$1

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01MxHc5Xxbfh8Ffya6uMVE1j" && git push -q jp ja-main:main 2>&1|tail -1; cd /home/claude/work && python3 -I next2.py 13000 > $2; grep '^##' $2
