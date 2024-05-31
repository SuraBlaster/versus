#include "all.h"
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

bool BG::hitCheck(object rc1, OBJ2D* rc2)
{
    const float rc1Left = rc1.pos.x - rc1.hsize.x;
    const float rc1Right = rc1.pos.x + rc1.hsize.x;
    const float rc1Top = rc1.pos.y - rc1.hsize.y;
    const float rc1Bottom = rc1.pos.y + rc1.hsize.y;

    const float rc2Left = rc2->position.x - rc2->size.x / 2;
    const float rc2Right = rc2->position.x + rc2->size.x / 2;
    const float rc2Top = rc2->position.y - rc2->size.y / 2;
    const float rc2Bottom = rc2->position.y + rc2->size.y / 2;

    if (rc1Right < rc2Left) return false;
    if (rc1Left > rc2Right) return false;
    if (rc1Bottom < rc2Top) return false;
    if (rc1Top > rc2Bottom) return false;

    return true;
}

float BG::checkDown(object rc1, OBJ2D* rc2)
{
    const float rc1Bottom = rc1.pos.y + rc1.hsize.y;
    const float rc2Top = rc2->position.y - rc2->size.y / 2;

    return rc2Top - rc1Bottom - ADJUST;
}

float BG::checkUp(object rc1, OBJ2D* rc2)
{
    const float rc1Top = rc1.pos.y - rc1.hsize.y;
    const float rc2Bottom = rc2->position.y + rc2->size.y / 2;

    return rc2Bottom - rc1Top + ADJUST;
}

float BG::checkRight(object rc1, OBJ2D* rc2)
{
    const float rc1Right = rc1.pos.x + rc1.hsize.x;
    const float rc2Left = rc2->position.x - rc2->size.x / 2;

    return rc2Left - rc1Right - ADJUST;
}

float BG::checkLeft(object rc1, OBJ2D* rc2)
{
    const float rc1Left = rc1.pos.x - rc1.hsize.x;
    const float rc2Right = rc2->position.x + rc2->size.x / 2;

    return rc2Right - rc1Left + ADJUST;
}

void BG::atarihantei(object rc, OBJ2D* obj)
{
    for (int i = 0; i < TERRAIN_NUM; ++i)
    {
        if (hitCheck(rc, obj))
        {
            float dist;
            if (obj->speed.y >= 0)
                dist = checkDown(rc, obj);
            else
                dist = checkUp(rc, obj);
            obj->position.y += dist;
            obj->speed.y = 0;
        }
    }

    for (int i = 0; i < TERRAIN_NUM; ++i) {
        if (hitCheck(rc, obj)) {
            float dist;
            if (obj->speed.y >= 0)
                dist = checkRight(rc, obj);
            else
                dist = checkLeft(rc, obj);
            obj->position.x += dist;
            obj->speed.y = 0;
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
