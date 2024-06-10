#include "stage.h"
#include "../GameLib/game_lib.h"
#include "common.h"
#include "stage1.h"
#include "stage2.h"
#include "game.h"
#include "tutorial.h"
using namespace GameLib;
Stage Stage::instance_;

void Stage::update()
{
    using namespace input;
    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;                                  // タイマーを初期化
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
        state++;                                    // 初期化処理の終了
        stagetimer = 100;
        Flag = false;
        backpos = 0;
        backpos2 = 0;
        table = 0;


        /*fallthrough*/                             // 意図的にbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////

        timer++;                            // タイマーを足す

        if (TRG(0) & PAD_RIGHT && table < 2)
        {
            table++;
        }
        if (TRG(0) & PAD_LEFT && table > 0)
        {
            table--;
        }



        if (backpos >= -1080)
        {
            if (backpos >= -1080)
            {
                backpos += 65;
            }
            else if (backpos >= 880)
            {
                backpos += 50;
            }
            else if (backpos >= 680)
            {
                backpos += 40;
            }
            else if (backpos >= 480)
            {
                backpos += 30;
            }

        }


        if (TRG(0) & PAD_START)             // PAD_TRG1が押されたら
        {
            Flag = true;
        }

        if (Flag == true)
        {
            if (stagetimer < 50 && backpos2 <= 1080)
            {
                if (backpos2 <= 1080)
                {
                    backpos2 += 65;
                }
                else if (backpos2 <= 880)
                {
                    backpos2 += 50;
                }
                else if (backpos2 <= 680)
                {
                    backpos2 += 40;
                }
                else if (backpos2 <= 480)
                {
                    backpos2 += 30;
                }

            }


            stagetimer--;

            if (stagetimer <= 0)
            {
                switch (table)  //今持ってるtableのステージに行く
                {
                case 0:
                    changeScene(Tutorial::instance());
                    break;
                case 1:
                    changeScene(Stage1::instance());
                    break;
                case 2:
                    changeScene(Stage2::instance());
                    break;
                }
            }
        }



        break;
    }
}

void Stage::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));



    switch (table)
    {
    case 0:
        if (timer / 40 % 2)
        {

            primitive::rect(100, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);

            font::textOut(3, "TUTORIAL", { 155,430 }, { 3.0f, 3.0f }, { 1,1,1,1 });
        }

        primitive::rect(750, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        primitive::rect(1400, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        break;
    case 1:

        if (timer / 40 % 2)
        {
            primitive::rect(750, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);

            font::textOut(3, "STAGE1", { 840,430 }, { 3.0f, 3.0f }, { 1,1,1,1 });

        }
        primitive::rect(100, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        primitive::rect(1400, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        break;
    case 2:

        if (timer / 40 % 2)
        {
            primitive::rect(1400, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);

            font::textOut(3, "STAGE2", { 1490,430 }, { 3.0f, 3.0f }, { 1,1,1,1 });

        }
        primitive::rect(100, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        primitive::rect(750, 200, 400, 500, 0, 0, 0, 0, 0, 0, 1);
        break;
    }

    primitive::rect(0, 0, 1920, 100, 0, 0, 0, 0, 0, 0, 1);

    font::textOut(3, "STAGE SELECT", { 20,30 }, { 4.0f, 4.0f }, { 1,1,1,1 });

    primitive::rect(0, 0 - backpos, 1920, 1080, 0, 0, 0, 0, 0, 0);

    primitive::rect(0, 1080 - backpos2, 1920, 1200, 0, 0, 0, 0, 0, 0);
}