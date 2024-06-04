//******************************************************************************
//
//
//      シーン管理
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//==============================================================================
//
//      Sceneクラス
//
//==============================================================================

//--------------------------------
//  実行
//--------------------------------
Scene* Scene::execute()
{
    using namespace GameLib;

    // 初期化処理
    init();

    // ゲームループ
    while (GameLib::gameLoop(true))    // falseをtrueにするとタイトルバーにフレームレート表示
    {
        // 入力処理
        input::update();

        // 更新処理
        update();

        // ステンシルモード：通常
        DepthStencil::instance().set(DepthStencil::MODE::NONE);

        // 描画処理
        draw();

        // ステンシルモード：通常
        DepthStencil::instance().set(DepthStencil::MODE::NONE);

        // デバッグ文字列の描画
        debug::display(1, 1, 1, 1, 1);
        //debug::setString("GP2_03 SAMPLE");

        // 画面フリップ
        GameLib::present(1, 0);

        // 終了チェック
        if (nextScene) break;
    }

    // 終了処理
    deinit();

    return nextScene;	// 次のシーンを返す
}

//******************************************************************************
//
//      SceneManagerクラス
//
//******************************************************************************

//--------------------------------
//  実行
//--------------------------------
void SceneManager::execute(Scene* scene)
{
    using namespace GameLib;

    bool isFullScreen = false;	// フルスクリーンにするならtrueに変える
                                //（Releaseモードのみ）

    // ゲームライブラリの初期化処理
    GameLib::init(L"ゲームプログラミング�U", 1920, 1080, isFullScreen);

#ifndef _DEBUG
    ShowCursor(!isFullScreen);	// フルスクリーン時はカーソルを消す
#endif

    // メインループ
    while (scene)
    {
        scene = scene->execute();
    }

    // ゲームライブラリの終了処理
    GameLib::uninit();
}

//******************************************************************************
