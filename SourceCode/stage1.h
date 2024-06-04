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

    // �Q�b�^�[�͌���_�����Ȃ�
    PlayerManager* playerManager() { return playerManager_; }



private:
    bool                isPaused;

    // �����o�ϐ��͌���_������
    PlayerManager* playerManager_;

    static Stage1 instance_Stage1;
};