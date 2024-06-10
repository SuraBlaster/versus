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
//      �ړ��A���S���Y��
//
//==============================================================================

// �v���C���[����N���X
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

// �ړ��A���S���Y���̎���
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

// �ړ��A���S���Y���̎���
EXTERN Player2 player2p;
//==============================================================================
//
//      �����A���S���Y��
//
//==============================================================================

// �����A���S���Y��
class ErasePlayer : public EraseAlg
{
    void erase(OBJ2D* obj);
};

// �����A���S���Y���̎���
//EXTERN ErasePlayer      erasePlayer;

//==============================================================================
//
//      PlayerManager�N���X
//
//==============================================================================
class PlayerManager : public OBJ2DManager
{
public:
    static constexpr float PLAYER_MOVE = 4.0f;

public:
    //OBJ2DManager�N���X�̂��̂��Ăяo�����Ηǂ��̂ŁA���L�I�[�o�[���C�h�͕s�v�ł���

    //void init();    // ������
    //void update();  // �X�V
    //void draw();    // �`��

};


//------< ���[�N�p >-------------------------------------------------------------


