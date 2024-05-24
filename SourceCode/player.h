#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

//******************************************************************************
//
//
//      Player.h
//
//
//******************************************************************************

//==============================================================================
//
//      移動アルゴリズム
//
//==============================================================================

// プレイヤー操作クラス
class Player : public MoveAlg
{
public:
    void move(OBJ2D* obj);
};

// 移動アルゴリズムの実体
EXTERN Player player;

//==============================================================================
//
//      消去アルゴリズム
//
//==============================================================================

// 消去アルゴリズム
class ErasePlayer : public EraseAlg
{
    void erase(OBJ2D* obj);
};

// 消去アルゴリズムの実体
//EXTERN ErasePlayer      erasePlayer;

//==============================================================================
//
//      PlayerManagerクラス
//
//==============================================================================
class PlayerManager : public OBJ2DManager
{
public:
    static constexpr float PLAYER_MOVE = 4.0f;

public:
    //OBJ2DManagerクラスのものが呼び出されれば良いので、下記オーバーライドは不要である

    //void init();    // 初期化
    //void update();  // 更新
    //void draw();    // 描画
};

//------< ワーク用 >-------------------------------------------------------------

#endif // !INCLUDED_PLAYER
