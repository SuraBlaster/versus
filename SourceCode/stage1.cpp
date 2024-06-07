#include "stage1.h"
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "sprite_data.h"
#include "common.h"
using namespace GameLib::input;
using namespace GameLib;
Stage1 Stage1::instance_Stage1;
Sprite* kabe;
Sprite* hari;
void Stage1::init()
{
    Scene::init();	    // ���N���X��init���Ă�
    rectposy = 550;

    playerManager_ = new PlayerManager;
    obj2d_ = new OBJ2D;
    player1_ = new Player; // player1_�̃C���X�^���X���쐬
    player2_ = new Player2; // player2_�̃C���X�^���X���쐬
    isPaused = false;   // �|�[�Y�t���O�̏�����
    kabe = sprite_load(L"./Data/Images/kabe.png");
    hari = sprite_load(L"./Data/Images/hari.png");
}

void Stage1::deinit()
{
    safe_delete(playerManager_);
    safe_delete(player1_); // player1_�̉��
    safe_delete(player2_); // player2_�̉��

    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

void Stage1::update()
{
    if (TRG(0) & PAD_RKey)
    {


        //�v���C���[�̐�
        int player_count = 0;
        //�v���C���[�̈ʒu�ۑ�
        VECTOR2 player1_position, player2_position;

        OBJ2D player1, player2;


        // �v���C���[�}�l�[�W���[�̑S�Ă̗v�f�����[�v
        for (auto& it : *playerManager_->getList())
        {
            //�J�E���g������ăv���C���[�̎�ނ𔻕�
            player_count++;

            //�ʒu��ۑ�
            if (player_count == 1)player1_position.y = it.position.y;
            if (player_count == 2)player2_position.y = it.position.y;
        }

        //������
        player_count = 0;
        //

        // �v���C���[�}�l�[�W���[�̑S�Ă̗v�f�����[�v
        for (auto& it : *playerManager_->getList())
        {
            //�J�E���g������ăv���C���[�̎�ނ𔻕�
            player_count++;

            //�ۑ������ʒu��ύX
            if (player_count == 1)it.position.y = player2_position.y;
            if (player_count == 2)it.position.y = player1_position.y;
        }

       



    }
    switch (state)
    {
    case 0:
        //////// �����ݒ� ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����

        // �e�N�X�`���̓ǂݍ���
        texture::load(loadTexture);

        // �v���C���[�}�l�[�W���̏�����
        playerManager()->init();

        // �v���C���[�i�����ő���j��ǉ�����
        playerManager()->add(&player, VECTOR2(window::getWidth() / 8, window::getHeight() / 2));
        playerManager()->add(&player2p, VECTOR2(window::getWidth() / 8, 1000));
        //playerManager()->add(&player[1], VECTOR2(window::getWidth() / 3, 900));

       
        state++;    // �����������̏I��

        /*fallthrough*/     // case 1:�̏����������ɍs���K�v�����邽�߁A�킴��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////
        if (terrain[9].pos.y == 1100)
        {
            num = 1;
        }
        else if (terrain[9].pos.y == 1280)
        {
            num = -1;
        }
        terrain[9].pos.y += 3 * num;
        playerManager()->update(1);

        timer++;
        break;
    }
}

void Stage1::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));

    for (int i = 4; i < 12; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

    for (int i = 500; i < 1360; i += 60)
    {
        sprite_render(hari,i, 470, 0.5f, 0.5f);
        sprite_render(hari,i, 1000, 0.5f, 0.5f);
    }

    sprite_render(kabe, 0, 680,0.5f,0.5f);
    // �v���C���[�̕`��
    playerManager()->draw();
}
