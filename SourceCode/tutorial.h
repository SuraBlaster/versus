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

    // �Q�b�^�[�͌���_�����Ȃ�
    PlayerManager* playerManager() { return playerManager_; }



private:
    bool                isPaused;

    // �����o�ϐ��͌���_������
    PlayerManager* playerManager_;

    static Tutorial instance_tutorial;
};