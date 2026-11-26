#include "global.h"
#include "coins.h"
#include "text.h"
#include "window.h"
#include "strings.h"
#include "string_util.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/coins.h"

static EWRAM_DATA u8 sCoinsWindowId = 0;

// HnS JP: "コイン" at the left and "<N>まい" at the right, with narrow digits,
// so the 8-tile window fits (Japanese digits and spaces are 8 px wide).
static const u8 sText_CoinsLabel[] = _("コイン");
static const u8 sText_CoinsUnit[] = _("まい");
void PrintCoinsString(u32 coinAmount)
{
    u8 *ptr = gStringVar4;

    FillWindowPixelBuffer(sCoinsWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(sCoinsWindowId, FONT_NORMAL, sText_CoinsLabel, 0, 1, TEXT_SKIP_DRAW, NULL);

    *ptr++ = EXT_CTRL_CODE_BEGIN;
    *ptr++ = EXT_CTRL_CODE_ENG;
    ptr = ConvertIntToDecimalStringN(ptr, coinAmount, STR_CONV_MODE_LEFT_ALIGN, MAX_COIN_DIGITS);
    *ptr++ = EXT_CTRL_CODE_BEGIN;
    *ptr++ = EXT_CTRL_CODE_JPN;
    *ptr = EOS;
    StringAppend(gStringVar4, sText_CoinsUnit);
    AddTextPrinterParameterized(sCoinsWindowId, FONT_NORMAL, gStringVar4,
                                64 - GetStringWidth(FONT_NORMAL, gStringVar4, 0), 1, 0, NULL);
}

void ShowCoinsWindow(u32 coinAmount, u8 x, u8 y)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, 0, x, y, 8, 2, 0xF, 0x141);
    sCoinsWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sCoinsWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sCoinsWindowId);
    DrawStdFrameWithCustomTileAndPalette(sCoinsWindowId, FALSE, 0x214, 0xE);
    PrintCoinsString(coinAmount);
}

void HideCoinsWindow(void)
{
    ClearStdWindowAndFrame(sCoinsWindowId, TRUE);
    RemoveWindow(sCoinsWindowId);
}

u16 GetCoins(void)
{
    return gSaveBlock1Ptr->coins ^ gSaveBlock2Ptr->encryptionKey;
}

void SetCoins(u16 coinAmount)
{
    gSaveBlock1Ptr->coins = coinAmount ^ gSaveBlock2Ptr->encryptionKey;
}

bool8 AddCoins(u16 toAdd)
{
    u16 newAmount;
    u16 ownedCoins = GetCoins();
    if (ownedCoins >= MAX_COINS)
        return FALSE;
    // check overflow, can't have less coins than previously
    if (ownedCoins > ownedCoins + toAdd)
    {
        newAmount = MAX_COINS;
    }
    else
    {
        ownedCoins += toAdd;
        if (ownedCoins > MAX_COINS)
            ownedCoins = MAX_COINS;
        newAmount = ownedCoins;
    }
    SetCoins(newAmount);
    return TRUE;
}

bool8 RemoveCoins(u16 toSub)
{
    u16 ownedCoins = GetCoins();
    if (ownedCoins >= toSub)
    {
        SetCoins(ownedCoins - toSub);
        return TRUE;
    }
    return FALSE;
}
