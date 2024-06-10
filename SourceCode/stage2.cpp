#include "stage2.h"
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "sprite_data.h"
#include "common.h"
#include "game.h"
#include "stage.h"
using namespace GameLib::input;
using namespace GameLib;
Stage2 Stage2::instance_Stage2;
void Stage2::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ
    rectposy = 500;

    playerManager_ = new PlayerManager;
    obj2d_ = new OBJ2D;
    player1_ = new Player; // player1_のインスタンスを作成
    player2_ = new Player2; // player2_のインスタンスを作成
    isPaused = false;   // ポーズフラグの初期化
}

void Stage2::deinit()
{
    safe_delete(playerManager_);
    safe_delete(player1_); // player1_の解放
    safe_delete(player2_); // player2_の解放

    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

void Stage2::update()
{
    if (TRG(0) & PAD_RKey)
    {


        //プレイヤーの数
        int player_count = 0;
        //プレイヤーの位置保存
        VECTOR2 player1_position, player2_position;

        OBJ2D player1, player2;


        // プレイヤーマネージャーの全ての要素をループ
        for (auto& it : *playerManager_->getList())
        {
            //カウントを取ってプレイヤーの種類を判別
            player_count++;

            //位置を保存
            if (player_count == 1)player1_position.y = it.position.y;
            if (player_count == 2)player2_position.y = it.position.y;
        }

        //初期化
        player_count = 0;
        //

        // プレイヤーマネージャーの全ての要素をループ
        for (auto& it : *playerManager_->getList())
        {
            //カウントを取ってプレイヤーの種類を判別
            player_count++;

            //保存した位置を変更
            if (player_count == 1)it.position.y = player2_position.y;
            if (player_count == 2)it.position.y = player1_position.y;
        }





    }
    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

        // テクスチャの読み込み
        texture::load(loadTexture);

        // プレイヤーマネージャの初期化
        playerManager()->init();

        // プレイヤー（自分で操作）を追加する
        playerManager()->add(&player, VECTOR2(window::getWidth() / 8, window::getHeight() / 2));
        playerManager()->add(&player2p, VECTOR2(window::getWidth() / 8, 1000));
        //playerManager()->add(&player[1], VECTOR2(window::getWidth() / 3, 900));


        state++;    // 初期化処理の終了

        /*fallthrough*/     // case 1:の処理も同時に行う必要があるため、わざとbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////

        playerManager()->update(2);
        if (TRG(0) & PAD_RKey)
        {
            if (rectposy == 500)rectposy = 0;
            else if (rectposy == 0)rectposy = 500;
        }
        if (Door1 == true && Door2 == true)
        {
            changeScene(Stage::instance());
        }
        timer++;
        break;
    }
}

void Stage2::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));
    bgManager_->drawGame1(BACK_WHITE);
    primitive::rect(0, rectposy, 1920, 540, 0, 0, 0, 0, 0, 0, 1);

    for (int i = 12; i < 24; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }


    /*for (int j = 4; j < 6; ++j)
    {
        primitive::rect(
            door[j].pos,
            door[j].hsize * 2,
            door[j].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }*/

    GameLib::texture::begin(WHITE_DOOR);
    GameLib::texture::draw(WHITE_DOOR,
        840, 775,  //位置
        0.5f, 0.66f,//大きさ
        0, 0,       //切り抜き位置
        240, 360, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(WHITE_DOOR);

    GameLib::texture::begin(BLACK_DOOR);
    GameLib::texture::draw(BLACK_DOOR,
        1738, 235,  //位置
        0.5f, 0.66f,//大きさ
        0, 0,       //切り抜き位置
        240, 360, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(BLACK_DOOR);
    playerManager()->draw();
}