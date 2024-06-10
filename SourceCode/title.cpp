//******************************************************************************
//
//
//      タイトル
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"
#include "stage.h"
using namespace GameLib::input;
//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Title Title::instance_;
Sprite* sprtitle;
Sprite* sprtri;
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
        Flag = false;
        sprtitle = sprite_load(L"./Data/Images/revarse.png");
        sprtri = sprite_load(L"./Data/Images/triangle.png");

        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
        sound::play(0, 0);
        titleTimer = 100;
        state++;                                    // 初期化処理の終了

        /*fallthrough*/                             // 意図的にbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////


        timer++;                            // タイマーを足す

        if (TRG(0) & PAD_START)             // PAD_TRG1が押されたら
        {
            Flag = true;
        }

        if (Flag == true)
        {
            if (titleTimer < 50 && backpos <= 1080)
            {
                if (backpos <= 1080)
                {
                    backpos += 65;
                }
                else if (backpos <= 880)
                {
                    backpos += 50;
                }
                else if (backpos <= 680)
                {
                    backpos += 40;
                }
                else if (backpos <= 480)
                {
                    backpos += 30;
                }

            }


            titleTimer--;

            if (titleTimer <= 0)
            {
                changeScene(Stage::instance());
            }
        }
        break;
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Title::draw()
{
    // 画面クリア
    //GameLib::clear(VECTOR4(0.2f, 0.3f, 1.0f, 1));

    sprite_render(sprtitle, 0, 0);

    if (Flag == true)
    {
        if (timer / 10 % 2)
        {
            sprite_render(sprtri, 850, 582, 0.13f, 0.13f, 0, 0, 572, 493, 0, 0, ToRadian(90));
        }
    }
    else
    {
        sprite_render(sprtri, 850, 582, 0.13f, 0.13f, 0, 0, 572, 493, 0, 0, ToRadian(90));
    }


    primitive::rect(0, 1080 - backpos, 1920, 1200, 0, 0, 0, 0, 0, 0);

}
