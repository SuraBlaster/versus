#include "all.h"
using namespace GameLib::input;
#define ADJUST      (0.125f)

//�R���X�g���N�^
BG::BG()
{
}

//�f�X�g���N�^
BG::~BG()
{
}

void BG::init()
{
}

void BG::update()
{
    
}


/*****************************************************/
// ���ۂɕ\������ //
void BG::drawOpBack()
{

}

void BG::drawTitBack()
{

}

void BG::drawStageSelectBack()
{
}

void BG::drawGameBack()
{
    drawGame1(1);
    drawGame2(2);
}

void BG::drawGameOver()
{
}

void BG::drawGameClear()
{
}

bool BG::hitCheck(OBJ2D* rc1, object rc2)
{
    const float rc1Left = rc1->position.x - rc1->size.x;
    const float rc1Right = rc1->position.x + rc1->size.x;
    const float rc1Top = rc1->position.y - rc1->size.y / 2;
    const float rc1Bottom = rc1->position.y + rc1->size.y / 2;

    const float rc2Left = rc2.pos.x - rc2.hsize.x;
    const float rc2Right = rc2.pos.x + rc2.hsize.x;
    const float rc2Top = rc2.pos.y - rc2.hsize.y;
    const float rc2Bottom = rc2.pos.y + rc2.hsize.y;

    if (rc1Right < rc2Left) return false;
    if (rc1Left > rc2Right) return false;
    if (rc1Bottom < rc2Top) return false;
    if (rc1Top > rc2Bottom) return false;

    return true;
}

float BG::checkDown(OBJ2D* rc1,object rc2)
{
    const float rc1Bottom = rc1->position.y + rc1->size.y / 2;
    const float rc2Top = rc2.pos.y - rc2.hsize.y;

    return rc2Top - rc1Bottom - ADJUST;
}

float BG::checkUp(OBJ2D* rc1,object rc2)
{
    const float rc1Top = rc1->position.y - rc1->size.y / 2;
    const float rc2Bottom = rc2.pos.y + rc2.hsize.y;

    return rc2Bottom - rc1Top + ADJUST;
}

float BG::checkRight(OBJ2D* rc1,object rc2)
{
    const float rc1Right = rc1->position.x + rc1->size.x;
    const float rc2Left = rc2.pos.x - rc2.hsize.x;

    return rc2Left - rc1Right - ADJUST;
}

float BG::checkLeft(OBJ2D* rc1,object rc2)
{
    const float rc1Left = rc1->position.x - rc1->size.x;
    const float rc2Right = rc2.pos.x + rc2.hsize.x;

    return rc2Right - rc1Left + ADJUST;
}

void BG::changePos(OBJ2D* obj, OBJ2D* obj2)
{
    int Box[2];

    Box[0] = obj->position.y;
    Box[1] = obj2->position.y;

    while (obj->position.y == Box[1] && obj2->position.y == Box[0])
    {
        if (obj->position.y > 540.0f)
        {
            obj->position.y++;
            obj2->position.y--;
        }
        else
        {
            obj->position.y--;
            obj2->position.y++;
        }
    }

}

/****************************************************/
// �摜�̐ݒ� //
//���R:�������Ȃ��Ɖ摜���o�Ă���Ȃ��̂�

// �I�[�v�j���O //
void BG::drawOpBack1(int texNo)
{
}

void BG::drawOpBack2(int texNo)
{
}


// �^�C�g����� //
void BG::drawTit1(int texNo)
{

}

void BG::drawTit2(int texNo)
{

}


// �X�e�[�W�I����� //
void BG::drawStageSelect1(int texNo)
{
}

void BG::drawStageSelect2(int texNo)
{
}


// �Q�[����� //
void BG::drawGame1(int texNo)
{
    GameLib::texture::begin(texNo);
    GameLib::texture::draw(texNo,
        0, 0,//�ʒu
        1, 1,       //�傫��
        0, 0,       //�؂蔲���ʒu
        1980, 1080, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(texNo);
}

void BG::drawGame2(int texNo)
{
    GameLib::texture::begin(texNo);
    GameLib::texture::draw(texNo,
        0, 0,//�ʒu
        1, 1,       //�傫��
        0, 0,       //�؂蔲���ʒu
        960, 1080, //�؂蔲���T�C�Y
        0, 0,
        0
    );
    GameLib::texture::end(texNo);
}


// �Q�[���I�[�o�[��� //
void BG::drawGameOver1(int texNo)
{
}

void BG::drawGameOver2(int texNo)
{
}


// �N���A��� //
void BG::drawGameClear1(int texNo)
{
}

void BG::drawGameClear2(int texNo)
{
}
