#pragma once

//******************************************************************************
//
//
//      ゲームシーン
//
//
//******************************************************************************
#include"bg.h"
//==============================================================================
//
//      Gameクラス
//
//==============================================================================

class Game : public Scene
{
public:
    // クラス内での定数の定義の仕方
    // int型であればconstで良いが、それ以外はconstexprを使用する
    //static constexpr float UPPER_GROUND_POS_Y = 480.0f;
    //static constexpr float UNDER_GROUND_POS_Y = 980.0f;

public:
    static Game* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void draw();

    // ゲッターは後ろに_をつけない
    PlayerManager* playerManager() { return playerManager_; }
    OBJ2D* obj2D() { return obj2d_; }
    BG* bgManager() { return bgManager_; }


private:
    bool                isPaused;

    int BackGround;
    // メンバ変数は後ろに_をつける
    PlayerManager* playerManager_;
    OBJ2D* obj2d_;
    BG* bgManager_;
    static Game instance_;
};