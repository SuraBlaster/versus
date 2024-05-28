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


/*****************************************************/
// 実際に表示する //
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
// 画像の設定 //
//理由:こうしないと画像が出てくれないので

// オープニング //
void BG::drawOpBack1(int texNo)
{
}

void BG::drawOpBack2(int texNo)
{
}


// タイトル画面 //
void BG::drawTit1(int texNo)
{

}

void BG::drawTit2(int texNo)
{

}


// ステージ選択画面 //
void BG::drawStageSelect1(int texNo)
{
}

void BG::drawStageSelect2(int texNo)
{
}


// ゲーム画面 //
void BG::drawGame1(int texNo)
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

void BG::drawGame2(int texNo)
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


// ゲームオーバー画面 //
void BG::drawGameOver1(int texNo)
{
}

void BG::drawGameOver2(int texNo)
{
}


// クリア画面 //
void BG::drawGameClear1(int texNo)
{
}

void BG::drawGameClear2(int texNo)
{
}
