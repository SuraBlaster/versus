#pragma once
#include "scene.h"
#include"player.h"
class Stage1 :public Scene
{
public:
    // �N���X���ł̒萔�̒�`�̎d��
    // int�^�ł����const�ŗǂ����A����ȊO��constexpr���g�p����
    static constexpr float GROUND_POS_Y = 980.0f;

public:
    static Stage1* instance() { return &instance_; }

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

    static Stage1 instance_;
};