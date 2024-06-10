#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< データ >---------------------------------------------------------------

// 2D画像ロードデータ
LoadTexture loadTexture[] = {
   { TEXNO::PLAYER,    L"./Data/Images/player.png",   1U },// プレイヤー
    { TEXNO::PLAYER2,     L"./Data/Images/player2.png",    1U },// プレイヤー
    { TEXNO::BACK_WHITE, L"./Data/Images/White.png",     1U },//白い背景
    { TEXNO::BACK_BLACK, L"./Data/Images/Black.png",     1U },//黒い背景
    { TEXNO::BLACK_DOOR, L"./data/Images/blackdoor.png", 1U },
    { TEXNO::WHITE_DOOR, L"./data/Images/whitedoor.png", 1U },
    { -1, nullptr }	// 終了フラグ
};

//------< マクロ >--------------------------------------------------------------
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // 画像の真ん中が中心
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心

//------< プレイヤー >----------------------------------------------------------
//上歩き
SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER, 120 * 0, 120 * 0, 120, 120);

SpriteData sprPlayer2_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 120 * 0, 120 * 0, 120, 120);
//------------------------------------------------------------------------------
#undef SPRITE_CENTER
#undef SPRITE_BOTTOM
