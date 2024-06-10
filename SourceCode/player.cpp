#include "all.h"
#include "stage.h"
using namespace GameLib::input;

//------< using >---------------------------------------------------------------
using namespace GameLib;
Player* playerPosition;
Player2* playerPosition2;
bool death;
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
    };

    AnimeData animePlayer2__Up[] = {
        {&sprPlayer2_Up0, 10}
    };

}


//--------------------------------
//  ���ڑ���
//--------------------------------
void Player::move(OBJ2D* obj,int t )
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
    

    playerPosition1X = obj->position.x;
    playerPosition1Y = obj->position.y;

    switch (obj->state)
    {
    case 0:
        //////// �����ݒ� ////////
        animeData = animePlayer_Up;   // �����l�Ƃ��ĉ������̃A�j����ݒ肷��

        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        obj->size = VECTOR2(120, 120);

        obj->state++;
        switch (t)
        {
        case 0:
            min1 = 0;
            max1 = 4;
            mindoor1 = 0;
            maxdoor1 = 2;
            break;
        case 1:
            min1 = 4;
            max1 = 12;
            mindoor1 = 2;
            maxdoor1 = 4;
            break;
        case 2:
            min1 = 12;
            max1 = 21;
            mindoor1 = 4;
            maxdoor1 = 6;
            break;
        }
        death = false;
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
        if (t == 1)
        {
            if (terrain[9].pos.y == 1100)
            {
                num1 = 1;
            }
            else if (terrain[9].pos.y == 1280)
            {
                num1 = -1;
            }
            terrain[9].pos.y = terrain[9].pos.y+ (3 * num1);
            
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[21]) || Game::instance()->bgManager()->hitCheck(obj, terrain[22]))
            {
                death = true;
            }
        }
        for (int i = min1; i < max1; ++i)
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

        
        for (int i = min1; i < max1; ++i) {
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

        for (int i = mindoor1; i < maxdoor1; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, door[i])) {
                Door1 = true;
                break;
            }
            else
            {
                Door1 = false;
            }
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

//--------------------------------
//  ����
//--------------------------------
void ErasePlayer::erase(OBJ2D* obj)
{
    obj->clear();           // OBJ2D����������
}

void Player2::move(OBJ2D* obj,int t)
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
    

    playerPosition2X = obj->position.x;
    playerPosition2Y = obj->position.y;

    switch (obj->state)
    {
    case 0:
        //////// �����ݒ� ////////
       
        //�A�j���̏����ݒ�
        animeData = animePlayer2__Up;   // �����l�Ƃ��ĉ������̃A�j����ݒ肷��

        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        obj->size = VECTOR2(96 / 3, 128);
        switch (t)
        {
        case 0:
            min2 = 0;
            max2 = 4;
            mindoor2 = 0;
            maxdoor2 = 2;
            break;
        case 1:
            min2 = 4;
            max2 = 12;
            mindoor2 = 2;
            maxdoor2 = 4;
            break;
        case 2:
            min2 = 12;
            max2 = 21;
            mindoor2 = 4;
            maxdoor2 = 6;
            break;
        }
        death = false;
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


        for (int i = min2; i < max2; ++i)
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

        if (t == 0)
        {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[21]) || Game::instance()->bgManager()->hitCheck(obj, terrain[22]))
            {
                death = true;
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

        for (int i = min2; i < max2; ++i) {
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
        for (int i = mindoor2; i < maxdoor2; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, door[i])) {
                Door2 = true;
                break;
            }
            else
            {
                Door2 = false;
            }
        };

        break;
    }

    // �A�j���[�V�����X�V
    if (animeData)
    {
        // animeData�ɒl�������Ă���΁Aobj->animeUpdate���\�b�h���Ă�
        obj->animeUpdate(animeData);
    }
}


