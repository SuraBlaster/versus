#pragma once
#include "..\GameLib\DirectXTK-master\Inc\Keyboard.h"


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
    float playerPositionGet1X() { return playerPosition1X; }
    float playerPositionGet1Y() { return playerPosition1Y; }
private:
    float playerPosition1X = 0.0f;
    float playerPosition1Y = 0.0f;
};

// 移動アルゴリズムの実体
EXTERN Player player;


class Player2 : public MoveAlg
{
public:
    void move(OBJ2D* obj);
    float playerPositionGet2X() { return playerPosition2X; }
    float playerPositionGet2Y() { return playerPosition2Y; }
private:
    float playerPosition2X = 0.0f;
    float playerPosition2Y = 0.0f;
};

// 移動アルゴリズムの実体
EXTERN Player2 player2p;

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

