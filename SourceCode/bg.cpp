#include "all.h"
#define ADJUST      (0.125f)

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
