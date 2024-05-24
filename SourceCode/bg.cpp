#include "all.h"

//コンストラクタ
BG::BG()
{
}

//デストラクタ
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
        0, 0,//位置
        1, 1,       //大きさ
        0, 0,       //切り抜き位置
        1980, 1080, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(texNo);
}

void BG::drawTit2(int texNo)
{
    GameLib::texture::begin(texNo);
    GameLib::texture::draw(texNo,
        0, 0,//位置
        1, 1,       //大きさ
        0, 0,       //切り抜き位置
        960, 1080, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(texNo);
}