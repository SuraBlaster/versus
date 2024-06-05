#include "tutorial.h"
#include "../GameLib/game_lib.h"
using namespace GameLib;
Tutorial Tutorial::instance_tutorial;

void Tutorial::init()
{
    Scene::init();
    playerManager_ = new PlayerManager;
    isPaused = false;
}

void Tutorial::deinit()
{
    safe_delete(playerManager_);

    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

void Tutorial::update()
{

}

void Tutorial::draw()
{
}
