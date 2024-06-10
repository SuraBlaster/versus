#pragma once
#include "obj2d.h"
#include "work.h"
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
    void move(OBJ2D* obj,int t);
    float playerPositionGet1X() { return playerPosition1X; }
    float playerPositionGet1Y() { return playerPosition1Y; }
    void playerPositionSet1X(float position_x) { this->playerPosition1X = position_x; }
    void playerPositionSet1Y(float position_y) { this->playerPosition1Y = position_y; }
    
private:
    float playerPosition1X = 0.0f;
    float playerPosition1Y = 0.0f;
    int min1 = 0;
    int max1 = 0;
    int num1 = 0;
    int mindoor1 = 0;
    int maxdoor1 = 0;

};

// 移動アルゴリズムの実体
EXTERN Player player;

class Player2 : public MoveAlg
{
public:
    void move(OBJ2D* obj,int t);
    float playerPositionGet2X() { return playerPosition2X; }
    float playerPositionGet2Y() { return playerPosition2Y; }
    void playerPositionSet2X(float position_x) { this->playerPosition2X = position_x; }
    void playerPositionSet2Y(float position_y) { this->playerPosition2Y = position_y; }
private:
    float playerPosition2X = 0.0f;
    float playerPosition2Y = 0.0f;
    int min2 = 0;
    int max2 = 0;
    int num2 = 0;
    int mindoor2 = 0;
    int maxdoor2 = 0;
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


