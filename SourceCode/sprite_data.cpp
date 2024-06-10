#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �f�[�^ >---------------------------------------------------------------

// 2D�摜���[�h�f�[�^
LoadTexture loadTexture[] = {
   { TEXNO::PLAYER,    L"./Data/Images/player.png",   1U },// �v���C���[
    { TEXNO::PLAYER2,     L"./Data/Images/player2.png",    1U },// �v���C���[
    { TEXNO::BACK_WHITE, L"./Data/Images/White.png",     1U },//�����w�i
    { TEXNO::BACK_BLACK, L"./Data/Images/Black.png",     1U },//�����w�i
    { TEXNO::BLACK_DOOR, L"./data/Images/blackdoor.png", 1U },
    { TEXNO::WHITE_DOOR, L"./data/Images/whitedoor.png", 1U },
    { -1, nullptr }	// �I���t���O
};

//------< �}�N�� >--------------------------------------------------------------
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // �摜�̐^�񒆂����S
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // �摜�̑��������S

//------< �v���C���[ >----------------------------------------------------------
//�����
SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER, 120 * 0, 120 * 0, 120, 120);

SpriteData sprPlayer2_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 120 * 0, 120 * 0, 120, 120);
//------------------------------------------------------------------------------
#undef SPRITE_CENTER
#undef SPRITE_BOTTOM
