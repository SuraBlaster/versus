#pragma once
#include "scene.h"
#include"player.h"
#include"bg.h"
class Stage2 :public Scene
{
public:
    static Stage2* instance() { return &instance_Stage2; }

    void init();
    void deinit();
    void update();
    void draw();

    // �Q�b�^�[�͌���_�����Ȃ�
    PlayerManager* playerManager() { return playerManager_; }



private:
    bool                isPaused;

    int BackGround;
    int rectposy;
    int num = 0;
    // �����o�ϐ��͌���_������
    Player* player1_;
    Player2* player2_;
    PlayerManager* playerManager_;
    OBJ2D* obj2d_;
    BG* bgManager_;
    static Stage2 instance_Stage2;
};