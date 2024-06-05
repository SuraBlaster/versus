#include "all.h"

void audio_init()
{
    // ���y�̓ǂݍ���
    GameLib::music::load(0, L"./Data/Musics/0.�^�C�g��BGM.wav");
    GameLib::music::load(1, L"./Data/Musics/1.�Q�[����BGM.wav");
    GameLib::music::load(2, L"./Data/Musics/2.�N���A���BGM.wav");

    GameLib::sound::load(0, L"./Data/Sounds/SE.xwb");
}

void audio_deinit()
{
    // ���y��S�ĉ��
    GameLib::music::clear();
}