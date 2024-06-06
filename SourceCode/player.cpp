//******************************************************************************
//
//
//      �v���C���[�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >--------------------------------------------------------
#include "all.h"
using namespace GameLib::input;

//------< using >---------------------------------------------------------------
using namespace GameLib;

//******************************************************************************
//
//      �v���C���[�ړ�����
//
//******************************************************************************


//------< �v���C���[�̃A�j���f�[�^ >--------------------------------------------
namespace
{   // �����̃f�[�^�͒����̂ŁAVisual Studio�̋@�\�ŕ�����悤��namespace�𕪂��Ă���

    //------< �v���C���[�̃A�j���f�[�^ >------------------------------------------
    //�����
    AnimeData animePlayer_Up[] = {
        { &sprPlayer_Up0, 10 },
        { &sprPlayer_Up1, 10 },
        { &sprPlayer_Up2, 10 },
        { &sprPlayer_Up1, 10 },
        { nullptr, -1 },// �I���t���O
    };

    AnimeData animePlayer2__Up[] = {
        {&sprPlayer2_Up0, 10}
    };

    //�E����
    AnimeData animePlayer_Right[] = {
        { &sprPlayer_Right0, 10 },
        { &sprPlayer_Right1, 10 },
        { &sprPlayer_Right2, 10 },
        { &sprPlayer_Right1, 10 },
        { nullptr, -1 },// �I���t���O
    };
    //������
    AnimeData animePlayer_Down[] = {
        { &sprPlayer_Down0, 10 },
        { &sprPlayer_Down1, 10 },
        { &sprPlayer_Down2, 10 },
        { &sprPlayer_Down1, 10 },
        { nullptr, -1 },// �I���t���O
    };
    //������
    AnimeData animePlayer_Left[] = {
        { &sprPlayer_Left0, 10 },
        { &sprPlayer_Left1, 10 },
        { &sprPlayer_Left2, 10 },
        { &sprPlayer_Left1, 10 },
        { nullptr, -1 },// �I���t���O
    };
}

//--------------------------------
//  ���ڑ���
//--------------------------------
void Player::move(OBJ2D *obj)
{
    using namespace input;  // �֐����œ��͏������s���Ƃ��ɋL�q����

    // �萔�i�����͂��̊֐����ł����g�p���Ȃ����߁A�����Œ�`���Ă���j
    const float KASOKU          =  1.0f;    // �������E�c�����̉����x
    const float SPEED_MAX_X     =  8.0f;    // �������̍ő呬�x
    const float SPEED_MAX_Y     =  16.0f;   // �ő�̗������x
    const float SPEED_JUMP_Y    = -12.0f;   // �W�����v���̏㏸�X�s�[�h

    // �ϐ�
    AnimeData* animeData = nullptr;
    bool onGround = false;          // �n��t���O

    switch (obj->state)
    {
    case 0:
        //////// �����ݒ� ////////

        //�A�j���̏����ݒ�
        animeData = animePlayer_Down;   // �����l�Ƃ��ĉ������̃A�j����ݒ肷��

        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        obj->size = VECTOR2(96 / 3, 128);

        obj->state++;

        break;

    case 1:
        //////// �ʏ펞 ////////

        // ���t���[�����̏����ݒ�
        onGround = false;   // �n�ʃt���O�͖��t���[���̍ŏ���false�ɂ��Ă����A�n�ʂɐڂ��Ă�����true��ݒ肷��

        //TODO_01 �v���C���[�̈ړ��iY�����j
        obj->speed.y += KASOKU;

        obj->speed.y = (std::min)(obj->speed.y, SPEED_MAX_Y);
 
        obj->speed.y = (std::max)(obj->speed.y, -SPEED_MAX_Y);
        obj->position.y += obj->speed.y;


        for (int i = 0; i < TERRAIN_NUM; ++i)
        {
            if (Game::instance()->bgManager()->hitCheck(obj,terrain[i]))
            {
                float dist;
                if (obj->speed.y >= 0) {
                    dist = Game::instance()->bgManager()->checkDown(obj, terrain[i]);
                    onGround = true;
                }
                else
                    dist = Game::instance()->bgManager()->checkUp(obj,terrain[i]);
                obj->position.y += dist;
                obj->speed.y = 0;
                
            }
        }

        //TODO_03 ���E���͂̎��o��
        switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
        {
        case PAD_LEFT:  // ��������������Ă���ꍇ
            obj->speed.x -= KASOKU;
            animeData = animePlayer_Left;
            break;
        case PAD_RIGHT: // �E������������Ă���ꍇ
            obj->speed.x += KASOKU;
            animeData = animePlayer_Right;
            break;
        default:        // �ǂ����������Ă��Ȃ������E����Ă���ꍇ
            if (obj->speed.x > 0)
            {
                obj->speed.x -= (KASOKU / 2);
                
                if (obj->speed.x < 0)
                {
                    obj->speed.x = 0;
                }
            }
            if (obj->speed.x < 0)
            {
                obj->speed.x += (KASOKU / 2);

                if (obj->speed.x > 0)
                {
                    obj->speed.x = 0;
                }
            }
            break;
        }

        obj->speed.x = clamp(obj->speed.x, -16,16);

        //TODO_03 X�����ړ�
        obj->position.x += obj->speed.x;

        for (int i = 0; i < TERRAIN_NUM; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj,terrain[i])) {
                float dist;
                if (obj->speed.x > 0)
                    dist = Game::instance()->bgManager()->checkRight(obj,terrain[i]);
                else
                    dist = Game::instance()->bgManager()->checkLeft(obj,terrain[i]);
                obj->position.x += dist;
                obj->speed.x = 0;
                
            }
        }

        //TODO_04 �W�����v�`�F�b�N
        if (onGround == true && TRG(0) & PAD_TRG1)
        {
            obj->jumpTimer = 20;
        }
        
        //TODO_04 �W�����v��
        if (obj->jumpTimer > 0)
        {
            if (STATE(0) & PAD_TRG1)
            {
                obj->speed.y += SPEED_JUMP_Y;
                --obj->jumpTimer;
            }
            else
            {
                obj->jumpTimer = 0;
            }
        }

        debug::setString("onGround:%d", onGround);
        debug::setString("jumpTimer:%d", obj->jumpTimer);

        //TODO_05 �G���A�`�F�b�N
        const float left = 0 + obj->size.x;
        const float right = window::getWidth() - obj->size.x;

        if (obj->position.x < 0 + left)
        {
            obj->position.x = 0 + left;
            obj->speed.x = 0;
        }
        
        if (obj->position.x > right)
        {
            obj->position.x = right;
            obj->speed.x = 0;
        }

        break;
    }

    // �A�j���[�V�����X�V
    if (animeData)
    {
        // animeData�ɒl�������Ă���΁Aobj->animeUpdate���\�b�h���Ă�
        obj->animeUpdate(animeData);
    }
}

void Player::positionSubstitution(OBJ2D* obj)
{
    obj->position.x = playerPosition1X;
    obj->position.y = playerPosition1Y;
}



//--------------------------------
//  ����
//--------------------------------
void ErasePlayer::erase(OBJ2D* obj)
{
    obj->clear();           // OBJ2D����������
}

void Player2::move(OBJ2D* obj)
{
    using namespace input;  // �֐����œ��͏������s���Ƃ��ɋL�q����

    // �萔�i�����͂��̊֐����ł����g�p���Ȃ����߁A�����Œ�`���Ă���j
    const float KASOKU = 1.0f;    // �������E�c�����̉����x
    const float SPEED_MAX_X = 8.0f;    // �������̍ő呬�x
    const float SPEED_MAX_Y = 16.0f;   // �ő�̗������x
    const float SPEED_JUMP_Y = -12.0f;   // �W�����v���̏㏸�X�s�[�h

    // �ϐ�
    AnimeData* animeData = nullptr;
    bool onGround = false;          // �n��t���O

    switch (obj->state)
    {
    case 0:
        //////// �����ݒ� ////////

        //�A�j���̏����ݒ�
        animeData = animePlayer2__Up;   // �����l�Ƃ��ĉ������̃A�j����ݒ肷��

        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        obj->size = VECTOR2(96 / 3, 128);

        obj->state++;

        break;

    case 1:
        //////// �ʏ펞 ////////

        // ���t���[�����̏����ݒ�
        onGround = false;   // �n�ʃt���O�͖��t���[���̍ŏ���false�ɂ��Ă����A�n�ʂɐڂ��Ă�����true��ݒ肷��

        //TODO_01 �v���C���[�̈ړ��iY�����j
        obj->speed.y += KASOKU;

        obj->speed.y = (std::min)(obj->speed.y, SPEED_MAX_Y);

        obj->speed.y = (std::max)(obj->speed.y, -SPEED_MAX_Y);
        obj->position.y += obj->speed.y;


        for (int i = 0; i < TERRAIN_NUM; ++i)
        {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i]))
            {
                float dist;
                if (obj->speed.y >= 0) {
                    dist = Game::instance()->bgManager()->checkDown(obj, terrain[i]);
                    onGround = true;
                }
                else
                    dist = Game::instance()->bgManager()->checkUp(obj, terrain[i]);
                obj->position.y += dist;
                obj->speed.y = 0;

            }
        }

        //TODO_03 ���E���͂̎��o��
        switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
        {
        case PAD_LEFT:  // ��������������Ă���ꍇ
            obj->speed.x -= KASOKU;
            break;
        case PAD_RIGHT: // �E������������Ă���ꍇ
            obj->speed.x += KASOKU;
            break;
        default:        // �ǂ����������Ă��Ȃ������E����Ă���ꍇ
            if (obj->speed.x > 0)
            {
                obj->speed.x -= (KASOKU / 2);

                if (obj->speed.x < 0)
                {
                    obj->speed.x = 0;
                }
            }
            if (obj->speed.x < 0)
            {
                obj->speed.x += (KASOKU / 2);

                if (obj->speed.x > 0)
                {
                    obj->speed.x = 0;
                }
            }
            break;
        }

        obj->speed.x = clamp(obj->speed.x, -16, 16);

        //TODO_03 X�����ړ�
        obj->position.x += obj->speed.x;

        for (int i = 0; i < TERRAIN_NUM; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i])) {
                float dist;
                if (obj->speed.x > 0)
                    dist = Game::instance()->bgManager()->checkRight(obj, terrain[i]);
                else
                    dist = Game::instance()->bgManager()->checkLeft(obj, terrain[i]);
                obj->position.x += dist;
                obj->speed.x = 0;

            }
        }

        //TODO_04 �W�����v�`�F�b�N
        if (onGround == true && TRG(0) & PAD_TRG1)
        {
            obj->jumpTimer = 20;
        }

        //TODO_04 �W�����v��
        if (obj->jumpTimer > 0)
        {
            if (STATE(0) & PAD_TRG1)
            {
                obj->speed.y += SPEED_JUMP_Y;
                --obj->jumpTimer;
            }
            else
            {
                obj->jumpTimer = 0;
            }
        }

        debug::setString("onGround:%d", onGround);
        debug::setString("jumpTimer:%d", obj->jumpTimer);

        //TODO_05 �G���A�`�F�b�N
        const float left = 0 + obj->size.x;
        const float right = window::getWidth() - obj->size.x;

        if (obj->position.x < 0 + left)
        {
            obj->position.x = 0 + left;
            obj->speed.x = 0;
        }

        if (obj->position.x > right)
        {
            obj->position.x = right;
            obj->speed.x = 0;
        }

        break;
    }

    // �A�j���[�V�����X�V
    if (animeData)
    {
        // animeData�ɒl�������Ă���΁Aobj->animeUpdate���\�b�h���Ă�
        obj->animeUpdate(animeData);
    }
}

void Player2::positionSubstitution(OBJ2D* obj)
{
    obj->position.x = playerPosition2X;
    obj->position.y = playerPosition2Y;
}