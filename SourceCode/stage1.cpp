#include "stage1.h"
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "sprite_data.h"
#include "common.h"
using namespace GameLib::input;
using namespace GameLib;
Stage1 Stage1::instance_Stage1;
Sprite* kabe;
Sprite* hari;
void Stage1::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ
    rectposy = 550;

    playerManager_ = new PlayerManager;
    obj2d_ = new OBJ2D;
    player1_ = new Player; // player1_のインスタンスを作成
    player2_ = new Player2; // player2_のインスタンスを作成
    isPaused = false;   // ポーズフラグの初期化
    kabe = sprite_load(L"./Data/Images/kabe.png");
    hari = sprite_load(L"./Data/Images/hari.png");
}

void Stage1::deinit()
{
    safe_delete(playerManager_);
    safe_delete(player1_); // player1_の解放
    safe_delete(player2_); // player2_の解放

    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

void Stage1::update()
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
        if (terrain[9].pos.y == 1100)
        {
            num = 1;
        }
        else if (terrain[9].pos.y == 1280)
        {
            num = -1;
        }
        terrain[9].pos.y += 3 * num;
        playerManager()->update(1);

        timer++;
        break;
    }
}

void Stage1::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));

    for (int i = 4; i < 12; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }

    for (int i = 500; i < 1360; i += 60)
    {
        sprite_render(hari,i, 470, 0.5f, 0.5f);
        sprite_render(hari,i, 1000, 0.5f, 0.5f);
    }

    sprite_render(kabe, 0, 680,0.5f,0.5f);
    // プレイヤーの描画
    playerManager()->draw();
}
