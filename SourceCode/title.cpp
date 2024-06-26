//******************************************************************************
//
//
//      タイトル
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Title Title::instance_;

//--------------------------------
//  更新処理
//--------------------------------
void Title::update()
{
    using namespace input;

    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;                                  // タイマーを初期化
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
        state++;                                    // 初期化処理の終了

        /*fallthrough*/                             // 意図的にbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////

        timer++;                            // タイマーを足す

        if (TRG(0) & PAD_START)             // PAD_TRG1が押されたら
            changeScene(Game::instance());  // ゲームシーンに切り替え

        break;
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Title::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0.2f, 0.3f, 1.0f, 1));

    // タイトル表示
    font::textOut(4, "ECC COMP", { 60, 60 }, { 4, 4 }, { 1, 1, 0, 1 });
    font::textOut(4, "Game Programming II", { 60, 160 }, { 2, 2 }, { 0, 1, 1, 1 });

    // "Push Start Button" 点滅
    if (timer / 40 % 2)
    {
        font::textOut(4, "Push Start Button", { 480, 540 }, { 2, 2 }, { 1, 0.5f, 0, 1 });
    }

}

//******************************************************************************
