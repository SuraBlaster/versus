#include "all.h"

void audio_init()
{
    // 音楽の読み込み
    GameLib::music::load(0, L"./Data/Musics/0.タイトルBGM.wav");
    GameLib::music::load(1, L"./Data/Musics/1.ゲーム中BGM.wav");
    GameLib::music::load(2, L"./Data/Musics/2.クリア画面BGM.wav");

    GameLib::sound::load(0, L"./Data/Sounds/SE.xwb");
}

void audio_deinit()
{
    // 音楽を全て解放
    GameLib::music::clear();
}