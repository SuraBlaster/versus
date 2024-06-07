#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Game Game::instance_;

//--------------------------------
//  初期化処理
//--------------------------------
void Game::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    playerManager_ = new PlayerManager;
    obj2d_ = new OBJ2D;
    player1_ = new Player; // player1_のインスタンスを作成
    player2_ = new Player2; // player2_のインスタンスを作成
    isPaused = false;   // ポーズフラグの初期化

    BackGround = 960;

}

//--------------------------------
//  終了処理
//--------------------------------
void Game::deinit()
{
    // 各マネージャの解放
    safe_delete(playerManager_);
    safe_delete(player1_); // player1_の解放
    safe_delete(player2_); // player2_の解放

    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

//--------------------------------
//  更新処理
//--------------------------------
void Game::update()
{
    using namespace input;

    // ソフトリセット
    if ((STATE(0) & PAD_SELECT) &&  // 0コンのセレクトボタンが押されている状態で
        (TRG(0) & PAD_START))       // 0コンのスタートボタンが押された瞬間
    {
        changeScene(Title::instance());   // タイトルシーンに切り替える
        return;
    }

    // 入れ替え処理
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

    /*if (TRG(0) & PAD_TRG1)
    {
        if (BackGround > 0)
        {
            while (BackGround = 0)
            {
                BackGround--;
            }
        }
        else
        {
            while (BackGround < 960)
            {
                BackGround++;
            }
        }
    }*/


    // デバッグ文字列表示
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    // ポーズ処理
    if (TRG(0) & PAD_START)
        isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
    if (isPaused) return;           // この時点でポーズ中ならリターン

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
        playerManager()->add(&player, VECTOR2(window::getWidth() / 3, window::getHeight() / 3));
        playerManager()->add(&player2p, VECTOR2(window::getWidth() / 3, 900));
        //playerManager()->add(&player[1], VECTOR2(window::getWidth() / 3, 900));

        state++;    // 初期化処理の終了

        /*fallthrough*/     // case 1:の処理も同時に行う必要があるため、わざとbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////

        timer++;

        // プレイヤーの更新
        playerManager()->update(1);

        break;
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Game::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

#if 2
    //******************************************************************************
    // TODO:02 地面の描画
    //------------------------------------------------------------------------------
    /*
    課題）
        地面を描画しなさい

    ヒント）
        0, GROUND_POS_Yから、幅 window::getWidth()、高さ window::getHeight() - GROUND_POS_Yの
        矩形を描画しなさい。色は背景色以外であれば、何色でも良い。
    */
    //******************************************************************************
#endif
    //TODO_02 地面の描画
    GameLib::texture::begin(TEXNO::BACK_WHITE);
    GameLib::texture::draw(TEXNO::BACK_WHITE,
        0, 0,//位置
        1, 1,       //大きさ
        0, 0,       //切り抜き位置
        1980, 1080, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(TEXNO::BACK_WHITE);

    GameLib::texture::begin(TEXNO::BACK_BLACK);
    GameLib::texture::draw(TEXNO::BACK_BLACK,
        BackGround, 0,//位置
        1, 1,       //大きさ
        0, 0,       //切り抜き位置
        960, 1080, //切り抜きサイズ
        0, 0,
        0
    );
    GameLib::texture::end(TEXNO::BACK_BLACK);


    /*primitive::rect(0, UNDER_GROUND_POS_Y,
        window::getWidth(), window::getHeight()-UNDER_GROUND_POS_Y,0,0,ToRadian(0)
    ,1,0,0);*/


   /* for (int i = 0; i < TERRAIN_NUM; ++i)
    {
        primitive::rect(
            terrain[i].pos,
            terrain[i].hsize * 2,
            terrain[i].hsize, 0,
            { 1, 0, 1, 1 }
        );
    }*/



    // プレイヤーの描画
    playerManager()->draw();


}
