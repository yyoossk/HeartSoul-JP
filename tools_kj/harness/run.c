// 画面なしで GBA を動かす: run ROM SAV STATE_IN STATE_OUT SCRIPT OUTDIR
#include <mgba/flags.h>
// SCRIPT: 1行1命令  w N（待つ） / p KEYS N（KEYS を N フレーム押す。KEYS は ABsSRLUDrl の組み合わせ） / shot 名前
//          / r8 addr / r16 addr / r32 addr（読む） / w8 addr val / w16 addr val / w32 addr val（書く）
#include <mgba/core/core.h>
#include <mgba/core/serialize.h>
#include <mgba-util/vfs.h>
#include <mgba/core/log.h>
#include <stdio.h>
#include <stdarg.h>
static void quiet(struct mLogger* l, int c, enum mLogLevel lv, const char* f, va_list a) { (void)l;(void)c;(void)lv;(void)f;(void)a; }
static struct mLogger sQuiet = { .log = quiet };
#include <stdlib.h>
#include <string.h>
static struct mCore* core; static uint32_t* buf; static unsigned W, H; static const char* outdir;
static int keymask(const char* s) {
    int m = 0;
    for (; *s; s++) switch (*s) {
        case 'A': m |= 1; break; case 'B': m |= 2; break; case 's': m |= 4; break; case 'S': m |= 8; break;
        case 'R': m |= 16; break; case 'L': m |= 32; break; case 'U': m |= 64; break; case 'D': m |= 128; break;
        case 'r': m |= 256; break; case 'l': m |= 512; break; }
    return m;
}
static void shot(const char* name) {
    char p[512]; snprintf(p, sizeof p, "%s/%s.ppm", outdir, name);
    FILE* f = fopen(p, "wb"); fprintf(f, "P6 %u %u 255\n", W, H);
    for (unsigned i = 0; i < W * H; i++) { uint32_t c = buf[i]; unsigned char px[3] = { c & 0xFF, (c >> 8) & 0xFF, (c >> 16) & 0xFF }; fwrite(px, 1, 3, f); }
    fclose(f);
}
int main(int argc, char** argv) {
    if (argc < 7) { fprintf(stderr, "usage\n"); return 1; }
    outdir = argv[6]; mLogSetDefaultLogger(&sQuiet);
    core = mCoreFind(argv[1]); if (!core) return 2;
    core->init(core); mCoreInitConfig(core, NULL);
    W = 240; H = 160;
    buf = malloc(W * H * 4); core->setVideoBuffer(core, (mColor*) buf, W);
    if (!mCoreLoadFile(core, argv[1])) return 3;
    struct VFile* sav = VFileOpen(argv[2], O_CREAT | O_RDWR); core->loadSave(core, sav);
    core->reset(core);
    if (strcmp(argv[3], "-")) { struct VFile* st = VFileOpen(argv[3], O_RDONLY); if (st) { bool ok = mCoreLoadStateNamed(core, st, SAVESTATE_SAVEDATA | SAVESTATE_RTC); if (!ok) fprintf(stderr, "state load failed\n"); st->close(st); } else fprintf(stderr, "no state file\n"); }
    FILE* sc = fopen(argv[5], "r"); char line[256];
    while (sc && fgets(line, sizeof line, sc)) {
        char op[16], a[64]; long n = 0; unsigned long addr, val; a[0] = 0;
        if (sscanf(line, "%15s", op) != 1) continue;
        if (!strcmp(op, "w")) { sscanf(line, "%*s %ld", &n); for (long i = 0; i < n; i++) core->runFrame(core); }
        else if (!strcmp(op, "p")) { sscanf(line, "%*s %63s %ld", a, &n); core->setKeys(core, keymask(a)); for (long i = 0; i < n; i++) core->runFrame(core); core->setKeys(core, 0); }
        else if (!strcmp(op, "shot")) { sscanf(line, "%*s %63s", a); shot(a); }
        else if (!strcmp(op, "r8")) { sscanf(line, "%*s %lx", &addr); printf("%08lx: %02x\n", addr, core->busRead8(core, addr)); }
        else if (!strcmp(op, "r16")) { sscanf(line, "%*s %lx", &addr); printf("%08lx: %04x\n", addr, core->busRead16(core, addr)); }
        else if (!strcmp(op, "r32")) { sscanf(line, "%*s %lx", &addr); printf("%08lx: %08x\n", addr, core->busRead32(core, addr)); }
        else if (!strcmp(op, "pos")) { // pos gPlayerAvatar gObjectEvents : 自分のマスの座標（MAP_OFFSET を引いた値）とマップ
            unsigned long oe; sscanf(line, "%*s %lx %lx", &addr, &oe); uint32_t o = oe + core->busRead8(core, addr + 5) * 0x24;
            printf("pos x=%d y=%d map=%d.%d\n", (int16_t) core->busRead16(core, o + 0x10) - 7, (int16_t) core->busRead16(core, o + 0x12) - 7, core->busRead8(core, o + 0xA), core->busRead8(core, o + 9)); }
        else if (!strcmp(op, "w8")) { sscanf(line, "%*s %lx %lx", &addr, &val); core->busWrite8(core, addr, val); }
        else if (!strcmp(op, "w16")) { sscanf(line, "%*s %lx %lx", &addr, &val); core->busWrite16(core, addr, val); }
        else if (!strcmp(op, "w32")) { sscanf(line, "%*s %lx %lx", &addr, &val); core->busWrite32(core, addr, val); }
    }
    if (strcmp(argv[4], "-")) { struct VFile* st = VFileOpen(argv[4], O_CREAT | O_TRUNC | O_RDWR); mCoreSaveStateNamed(core, st, SAVESTATE_SAVEDATA | SAVESTATE_RTC); st->close(st); }
    core->deinit(core);
    return 0;
}
