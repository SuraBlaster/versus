#pragma once
#include "scene.h"
#include"player.h"
#include "bg.h"
class Tutorial :public Scene
{
public:
    static Tutorial* instance() { return &instance_tutorial; }

    void init();
    void deinit();
    void update();
    void draw();

    // ゲッターは後ろに_をつけない
    PlayerManager* playerManager() { return playerManager_; }



private:
    bool                isPaused;

    int BackGround;
    int rectposy;
    // メンバ変数は後ろに_をつける
    Player* player1_;
    Player2* player2_;
    PlayerManager* playerManager_;
    OBJ2D* obj2d_;
    BG* bgManager_;
    static Tutorial instance_tutorial;


};
