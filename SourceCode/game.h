#pragma once

//******************************************************************************
//
//
//      �Q�[���V�[��
//
//
//******************************************************************************
#include"bg.h"
//==============================================================================
//
//      Game�N���X
//
//==============================================================================

class Game : public Scene
{
public:
    // �N���X���ł̒萔�̒�`�̎d��
    // int�^�ł����const�ŗǂ����A����ȊO��constexpr���g�p����
    //static constexpr float UPPER_GROUND_POS_Y = 480.0f;
    //static constexpr float UNDER_GROUND_POS_Y = 980.0f;

public:
    static Game* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void draw();

    // �Q�b�^�[�͌���_�����Ȃ�
    PlayerManager* playerManager() { return playerManager_; }
    OBJ2D* obj2D() { return obj2d_; }
    BG* bgManager() { return bgManager_; }


private:
    bool                isPaused;

    int BackGround;
    // �����o�ϐ��͌���_������
    PlayerManager* playerManager_;
    OBJ2D* obj2d_;
    BG* bgManager_;
    static Game instance_;
};