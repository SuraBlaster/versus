#include "all.h"

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
