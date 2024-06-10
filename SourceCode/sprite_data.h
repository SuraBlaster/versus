#pragma once
//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "../GameLib/texture.h"

// ���x����`
enum TEXNO
{
    // �Q�[��
    PLAYER,
    PLAYER2,
    BACK_WHITE,
    BACK_BLACK,

};

extern GameLib::LoadTexture loadTexture[];

//------< �v���C���[ >-----------------------------------------------------------
//�����
extern GameLib::SpriteData sprPlayer_Up0;
extern GameLib::SpriteData sprPlayer_Up1;
extern GameLib::SpriteData sprPlayer_Up2;

extern GameLib::SpriteData sprPlayer2_Up0;

//�E����
extern GameLib::SpriteData sprPlayer_Right0;
extern GameLib::SpriteData sprPlayer_Right1;
extern GameLib::SpriteData sprPlayer_Right2;

//������
extern GameLib::SpriteData sprPlayer_Down0;
extern GameLib::SpriteData sprPlayer_Down1;
extern GameLib::SpriteData sprPlayer_Down2;

//������
extern GameLib::SpriteData sprPlayer_Left0;
extern GameLib::SpriteData sprPlayer_Left1;
extern GameLib::SpriteData sprPlayer_Left2;

extern GameLib::SpriteData sprPlayer2_Up0;


//******************************************************************************

