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

void BG::drawBack()
{

}

void BG::drawTitBack()
{
    drawTit1(1);
    drawTit2(2);
}

void BG::drawTit1(int texNo)
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

void BG::drawTit2(int texNo)
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