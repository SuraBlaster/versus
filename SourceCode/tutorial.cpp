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

    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

void Tutorial::update()
{

}

void Tutorial::draw()
{
}
