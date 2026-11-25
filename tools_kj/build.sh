#!/bin/bash
# カントー＆ジョウト のビルド（生成物を作り直してから make hns）
set -e
cd "$(dirname "$0")/.."
python3 -I tools_kj/gen_includes.py
python3 -I tools_kj/gen_tilesets.py
python3 -I tools_kj/add_jj.py
python3 -I tools_kj/gen_trainers.py
python3 -I tools_kj/gen_vars.py
python3 -I tools_kj/patch_frlg_scripts.py
python3 -I tools_kj/prune_common.py
python3 -I tools_kj/fix_labels.py
python3 -I tools_kj/gen_flags.py
rm -f data/layouts/layouts.inc data/layouts/layouts_table.inc include/constants/layouts.h \
      data/maps/groups.inc data/maps/connections.inc data/maps/headers.inc data/maps/events.inc include/constants/map_groups.h
make hns -j"$(nproc)" "$@"
