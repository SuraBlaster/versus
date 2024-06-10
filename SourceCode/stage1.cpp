#include "stage1.h"
#include "tutorial.h"
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "sprite_data.h"
#include "common.h"
#include "game.h"
#include "stage.h"
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

        //OBJ2D player1, player2;
        VECTOR2 sa1, sa2;

        // �v���C���[�}�l�[�W���[�̑S�Ă̗v�f�����[�v
        for (auto& it : *playerManager_->getList())
        {
            //�J�E���g������ăv���C���[�̎�ނ𔻕�
            player_count++;

            //�ʒu��ۑ�
            /*if (player_count == 1)player1_position.y = it.position.y;
            if (player_count == 2)player2_position.y = it.position.y;*/

            if (player_count == 1)
            {
                if (it.position.y < 500)
                {
                    sa1.y = 500 - it.position.y;
                    player1_position.y = 500;
                }
                else if (it.position.y > 500 && it.position.y < 1030)
                {
                    sa1.y = 1030 - it.position.y;
                    player1_position.y = 1030;
                }

            }
            if (player_count == 2)
            {
                if (it.position.y < 500)
                {
                    sa2.y = 500 - it.position.y;
                    player2_position.y = 500;
                }
                else if (it.position.y > 500 && it.position.y < 1030)
                {
                    sa2.y = 1030 - it.position.y;
                    player2_position.y = 1030;
                }

            }

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
            /*if (player_count == 1)it.position.y = player2_position.y;
            if (player_count == 2)it.position.y = player1_position.y;*/

            if (player_count == 1)it.position.y = player2_position.y - sa1.y;
            if (player_count == 2)it.position.y = player1_position.y - sa2.y;
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
        playerManager()->add(&player2p, VECTOR2(window::getWidth() / 8, 990));
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

        if (Door1 == true && Door2 == true)
        {
            changeScene(Stage::instance());
        }

        break;
    }
}

void Stage1::draw()
{
    GameLib::clear(VECTOR4(0, 1, 1, 1));

    for (int i = 4; i < 12; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

    for (int i = 2; i < 4; ++i)
    {
        primitive::rect(
            door[i].pos,
            door[i].hsize * 2,
            door[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

    for (int i = 500; i < 1360; i += 60)
    {
        sprite_render(hari,i, 470, 0.5f, 0.5f);
        sprite_render(hari,i, 1010, 0.5f, 0.5f);
    }



    sprite_render(kabe, 0, 680,0.5f,0.5f);

    //sprite_render(whitedoor, 10, 780, 0.5f, 0.62f);


    GameLib::texture::begin(WHITE_DOOR);
    GameLib::texture::draw(WHITE_DOOR,
        40, 770,  //�ʒu
        0.5f, 0.66f,//�傫��
        0, 0,       //�؂蔲���ʒu
        240, 360, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(WHITE_DOOR);

    GameLib::texture::begin(BLACK_DOOR);
    GameLib::texture::draw(BLACK_DOOR,
        1680, 230,  //�ʒu
        0.5f, 0.66f,//�傫��
        0, 0,       //�؂蔲���ʒu
        240, 360, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(BLACK_DOOR);

   

    // �v���C���[�̕`��
    playerManager()->draw();

    
}
