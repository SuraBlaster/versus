#pragma once
//******************************************************************************
//
//
//      OBJ2Dクラス
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <list>
#include "../GameLib/vector.h"
#include "../GameLib/obj2d_data.h"


#define TERRAIN_NUM (26)
// 前方宣言
class OBJ2D;

//==============================================================================

// 移動アルゴリズムクラス（抽象クラス）
class MoveAlg
{
public:
    virtual void move(OBJ2D* obj,int t) = 0;  // 純粋仮想関数を持つので、MoveAlg型のオブジェクトは定義できない（派生させて使う）
};

// 消去アルゴリズムクラス（抽象クラス）
class EraseAlg
{
public:
    virtual void erase(OBJ2D* obj) = 0; // 上と同様
};


//==============================================================================
//==============================================================================
//
//      OBJ2Dクラス
//
//==============================================================================

class OBJ2D
{
public:
    // メンバ変数
    GameLib::SpriteData* data;               // スプライトデータ
    GameLib::Anime          anime;              // アニメーションクラス

    VECTOR2                 position;           // 位置
    VECTOR2                 scale;              // スケール
    float                   angle;              // 角度
    VECTOR4                 color;              // 描画色
    VECTOR2                 size;               // あたり用サイズ（縦横）

    MoveAlg* mvAlg;              // 移動アルゴリズム
    EraseAlg* eraseAlg;           // 消去アルゴリズム

    float                   velocity;           // 速度
    VECTOR2                 speed;              // 瞬間の移動量ベクトル
    int                     state;              // ステート
    int                     timer;              // タイマー

    int                     param;              // 汎用パラメータ
    int                     jumpTimer;          // 長押しジャンプタイマー

    int                     iWork[16];          // 汎用（使い方は自由）
    float                   fWork[16];          // 汎用（使い方は自由）

    bool                    hashigoFlag;        // はしごフラグ
    bool                    drawHitRectFlag;    // あたり判定描画フラグ
    bool                    judgeFlag;          // あたり判定の有無（true:有り / false:無し）
    BYTE                    pad[1];             // 1バイトの空き
   



public:

    OBJ2D();        // コンストラクタ
    void clear();   // メンバ変数のクリア
    void move(int t);    // 移動
    void draw();    // 描画



    bool animeUpdate(GameLib::AnimeData* animeData);    // アニメーションのアップデート
};



//==============================================================================

// OBJ2DManagerクラス
class OBJ2DManager
{
protected:
    std::list<OBJ2D>  objList; // リスト（OBJ2Dの配列のようなもの）
public:
    // デストラクタ
    ~OBJ2DManager();

    void init();    // 初期化
    void update(int t);  // 更新
    void draw();    // 描画

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos = VECTOR2(0, 0)); // objListに新たなOBJ2Dを追加する
    std::list<OBJ2D>* getList() { return &objList; }                // objListを取得する

    bool deth();
};

struct object
{
    VECTOR2 pos;
    VECTOR2 hsize;

    float speed;
};

static object terrain[TERRAIN_NUM] = {
    //チュートリアルステージ
    {{ 0, 1060 },  {1900, 10 }, {}},
    {{0,530},{1900,10}, {}},
    {{1200,940},{30,120},{}},
    {{900,410},{30,120},{}},
    //ステージ1
     {{ 0, 1030 },  {500, 30 }, {}},
    {{0,500},{500,30}, {}},         
    {{0,300},{1900,20},{}},
    {{0,700},{400,20},{}},
    {{400,1080},{20,400},{}},
    {{350,1100},{50,250},{}},
    {{1700,1030},{300,30},{}},
    {{1700,500},{300,30},{}},
    //ステージ2
     {{ 0, 1040 },  {1900, 30 }, {}},
    {{0,500},{1900,30}, {}},
    { { 500,0 },{30,500},{} },
    {{1300,0},{30,500},{}},
    {{890,230} ,{ 250,200 }, {}},
    {{600,1000},{30,500},{}},
    {{1200,1000},{30,500},{}},
    {{900,1000},{300,30},{}},
    {{900,550},{300,30},{}},

    //ステージ１の針の当たり判定
    {{950,500},{450,20},{} },
    {{950,1020},{450,20},{}}
};
