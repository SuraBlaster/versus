//******************************************************************************
//
//
//      �Q�[��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Game Game::instance_;
Player* PlayerPosition;
Player2* PlayerPosition2;

//--------------------------------
//  ����������
//--------------------------------
void Game::init()
{
    Scene::init();	    // ���N���X��init���Ă�

    playerManager_      = new PlayerManager;
    obj2d_ = new OBJ2D;
    isPaused = false;   // �|�[�Y�t���O�̏�����

    BackGround = 960;

}

//--------------------------------
//  �I������
//--------------------------------
void Game::deinit()
{
    // �e�}�l�[�W���̉��
    safe_delete(playerManager_);

    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

//--------------------------------
//  �X�V����
//--------------------------------
void Game::update()
{
    using namespace input;

    // �\�t�g���Z�b�g
    if ((STATE(0) & PAD_SELECT) &&  // 0�R���̃Z���N�g�{�^����������Ă����Ԃ�
        (TRG(0) & PAD_START))       // 0�R���̃X�^�[�g�{�^���������ꂽ�u��
    {
        changeScene(Title::instance());   // �^�C�g���V�[���ɐ؂�ւ���
        return;
    }

    /*if (TRG(0) & PAD_TRG1)
    {
        if (BackGround > 0)
        {
            while (BackGround = 0)
            {
                BackGround--;
            }
        }
        else
        {
            while (BackGround < 960)
            {
                BackGround++;
            }
        }
    }*/

    
    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    // �|�[�Y����
    if (TRG(0) & PAD_START)
        isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
    if (isPaused) return;           // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

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
        playerManager()->add(&player2, VECTOR2(window::getWidth() / 3, 900));
        //playerManager()->add(&player[1], VECTOR2(window::getWidth() / 3, 900));
        
        
        

        state++;    // �����������̏I��

        /*fallthrough*/     // case 1:�̏����������ɍs���K�v�����邽�߁A�킴��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////

        timer++;
        
        // ����ւ�����
        if (TRG(0) & PAD_RKey)
        {
            
        }

        // �v���C���[�̍X�V
        playerManager()->update();

        break;
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Game::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

#if 2
//******************************************************************************
// TODO:02 �n�ʂ̕`��
//------------------------------------------------------------------------------
/*
�ۑ�j
    �n�ʂ�`�悵�Ȃ���

�q���g�j
    0, GROUND_POS_Y����A�� window::getWidth()�A���� window::getHeight() - GROUND_POS_Y��
    ��`��`�悵�Ȃ����B�F�͔w�i�F�ȊO�ł���΁A���F�ł��ǂ��B
*/
//******************************************************************************
#endif
    //TODO_02 �n�ʂ̕`��
    GameLib::texture::begin(TEXNO::BACK_WHITE);
    GameLib::texture::draw(TEXNO::BACK_WHITE,
        0, 0,//�ʒu
        1, 1,       //�傫��
        0, 0,       //�؂蔲���ʒu
        1980, 1080, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(TEXNO::BACK_WHITE);

    GameLib::texture::begin(TEXNO::BACK_BLACK);
    GameLib::texture::draw(TEXNO::BACK_BLACK,
        BackGround, 0,//�ʒu
        1, 1,       //�傫��
        0, 0,       //�؂蔲���ʒu
        960, 1080, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(TEXNO::BACK_BLACK);


    /*primitive::rect(0, UNDER_GROUND_POS_Y,
        window::getWidth(), window::getHeight()-UNDER_GROUND_POS_Y,0,0,ToRadian(0)
    ,1,0,0);*/


    for (int i = 0; i < TERRAIN_NUM; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

 

    // �v���C���[�̕`��
    playerManager()->draw();

    
}

//******************************************************************************
