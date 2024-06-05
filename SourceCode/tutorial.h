#pragma once
#include "scene.h"
#include"player.h"
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

    // メンバ変数は後ろに_をつける
    PlayerManager* playerManager_;

    static Tutorial instance_tutorial;
};