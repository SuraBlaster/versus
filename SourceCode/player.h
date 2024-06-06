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
//      �ړ��A���S���Y��
//
//==============================================================================

// �v���C���[����N���X
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

// �ړ��A���S���Y���̎���
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

// �ړ��A���S���Y���̎���
EXTERN Player2 player2;

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

