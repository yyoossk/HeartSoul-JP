// カントー＆ジョウト（カントーから ジョウトへ）
#include "global.h"
#include "event_data.h"
#include "constants/flags.h"
#include "constants/vars.h"

#if IS_HNS
// ジョウト編の はじまり: カントー編で ジョウトの変数と共用していた変数を 0 に戻す
void KJ_StartJohto(void)
{
#define X(v) VarSet(v, 0);
    KJ_SHARED_VARS_LIST
#undef X
    FlagSet(FLAG_KJ_JOHTO_STARTED);
}
#else
void KJ_StartJohto(void) {}
#endif
