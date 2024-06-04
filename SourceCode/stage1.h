#pragma once
#include "scene.h"
#include"player.h"
class Stage1 :public Scene
{
public:
    static Stage1* instance() { return &instance_Stage1; }

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

    static Stage1 instance_Stage1;
};