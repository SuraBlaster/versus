#pragma once
//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "../GameLib/texture.h"

// ラベル定義
enum TEXNO
{
    // ゲーム
    PLAYER,
    PLAYER2,
    BACK_WHITE,
    BACK_BLACK,
    BLACK_DOOR,
    WHITE_DOOR,

};

extern GameLib::LoadTexture loadTexture[];

//------< プレイヤー >-----------------------------------------------------------
//上歩き
extern GameLib::SpriteData sprPlayer_Up0;

extern GameLib::SpriteData sprPlayer2_Up0;


//******************************************************************************

