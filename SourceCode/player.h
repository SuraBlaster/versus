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
    void positionSubstitution(OBJ2D* obj);
    float playerPositionGetX() { return playerPosition1X; }
    float playerPositionGetY() { return playerPosition1Y; }
private:
    float playerPosition1X;
    float playerPosition1Y;
};

// 移動アルゴリズムの実体
EXTERN Player player;


class Player2 : public MoveAlg
{
public:
    void move(OBJ2D* obj);
    void positionSubstitution(OBJ2D* obj);
    float playerPositionGetX() { return playerPosition2X; }
    float playerPositionGetY() { return playerPosition2Y; }
private:
    float playerPosition2X;
    float playerPosition2Y;
};

// 移動アルゴリズムの実体
EXTERN Player2 player2;

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

