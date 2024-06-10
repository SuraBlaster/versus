#include "tutorial.h"
#include "stage.h"
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "sprite_data.h"
#include "common.h"
#include "game.h"
using namespace GameLib::input;
using namespace GameLib;
Tutorial Tutorial::instance_tutorial;

Sprite* blackdoor;
Sprite* whitedoor;

void Tutorial::init()
{
    Scene::init();	    // ���N���X��init���Ă�
    rectposy = 550;

    playerManager_ = new PlayerManager;
    obj2d_ = new OBJ2D;
    player1_ = new Player; // player1_�̃C���X�^���X���쐬
    player2_ = new Player2; // player2_�̃C���X�^���X���쐬
    isPaused = false;   // �|�[�Y�t���O�̏�����
    BackGround = 960;
    blackdoor = sprite_load(L"./data/Images/blackdoor.png");
    whitedoor = sprite_load(L"./data/Images/whitedoor.png");
    Door1 = false;
    Door2 = false;
}

void Tutorial::deinit()
{
    safe_delete(playerManager_);
    safe_delete(player1_); // player1_�̉��
    safe_delete(player2_); // player2_�̉��

    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

void Tutorial::update()
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
        playerManager()->add(&player, VECTOR2(window::getWidth() / 3, window::getHeight() / 3));
        playerManager()->add(&player2p, VECTOR2(window::getWidth() / 3, 900));
        //playerManager()->add(&player[1], VECTOR2(window::getWidth() / 3, 900));



        state++;    // �����������̏I��

        /*fallthrough*/     // case 1:�̏����������ɍs���K�v�����邽�߁A�킴��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////

        timer++;

        if (TRG(0) & PAD_RKey)
        {
            if (rectposy == YUKA)rectposy = 0;
            else if (rectposy == 0)rectposy = YUKA;
        }



        debug::setString("Door1:%d", Door1);
        debug::setString("Door2:%d", Door2);

        // �v���C���[�̍X�V
        playerManager()->update(0);

        if (Door1 == true && Door2 == true)
        {
            changeScene(Stage::instance());
        }

        break;
    }
}

void Tutorial::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));

    bgManager_->drawGame1(BACK_WHITE);

    primitive::rect(0, rectposy, 1920, 540, 0, 0, 0, 0, 0, 0, 1);

    for (int i = 0; i < 4; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

    for (int i = 0; i < 2; ++i)
    {
        primitive::rect(
            door[i].pos,
            door[i].hsize * 2,
            door[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }



    sprite_render(whitedoor, 1680, 300, 0.5f, 0.62f);

    
    sprite_render(blackdoor, 1680, 830, 0.5f, 0.62f);
    // �v���C���[�̕`��
    playerManager()->draw();

}