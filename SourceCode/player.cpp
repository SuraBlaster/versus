#include "all.h"
#include "stage.h"
using namespace GameLib::input;

//------< using >---------------------------------------------------------------
using namespace GameLib;
Player* playerPosition;
Player2* playerPosition2;
bool death;
//******************************************************************************
//
//      プレイヤー移動処理
//
//******************************************************************************


//------< プレイヤーのアニメデータ >--------------------------------------------
namespace
{   // ※このデータは長いので、Visual Studioの機能で閉じられるようにnamespaceを分けている

    //------< プレイヤーのアニメデータ >------------------------------------------
    //上方向
    AnimeData animePlayer_Up[] = {
        { &sprPlayer_Up0, 10 },
    };

    AnimeData animePlayer2__Up[] = {
        {&sprPlayer2_Up0, 10}
    };

}


//--------------------------------
//  直接操作
//--------------------------------
void Player::move(OBJ2D* obj,int t )
{
    using namespace input;  // 関数内で入力処理を行うときに記述する

    // 定数（これらはこの関数内でしか使用しないため、ここで定義している）
    const float KASOKU = 1.0f;    // 横方向・縦方向の加速度
    const float SPEED_MAX_X = 8.0f;    // 横方向の最大速度
    const float SPEED_MAX_Y = 16.0f;   // 最大の落下速度
    const float SPEED_JUMP_Y = -12.0f;   // ジャンプ中の上昇スピード

    // 変数
    AnimeData* animeData = nullptr;
    bool onGround = false;          // 地上フラグ
    

    playerPosition1X = obj->position.x;
    playerPosition1Y = obj->position.y;

    switch (obj->state)
    {
    case 0:
        //////// 初期設定 ////////
        animeData = animePlayer_Up;   // 初期値として下向きのアニメを設定する

        // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
        obj->size = VECTOR2(120, 120);

        obj->state++;
        switch (t)
        {
        case 0:
            min1 = 0;
            max1 = 4;
            mindoor1 = 0;
            maxdoor1 = 2;
            break;
        case 1:
            min1 = 4;
            max1 = 12;
            mindoor1 = 2;
            maxdoor1 = 4;
            break;
        case 2:
            min1 = 12;
            max1 = 21;
            mindoor1 = 4;
            maxdoor1 = 6;
            break;
        }
        death = false;
        obj->state++;
        break;

    case 1:
        //////// 通常時 ////////
        
        // 毎フレーム毎の初期設定
        onGround = false;   // 地面フラグは毎フレームの最初にfalseにしておき、地面に接していたらtrueを設定する

        //TODO_01 プレイヤーの移動（Y方向）
        obj->speed.y += KASOKU;

        obj->speed.y = (std::min)(obj->speed.y, SPEED_MAX_Y);

        obj->speed.y = (std::max)(obj->speed.y, -SPEED_MAX_Y);
        obj->position.y += obj->speed.y;
        if (t == 1)
        {
            if (terrain[9].pos.y == 1100)
            {
                num1 = 1;
            }
            else if (terrain[9].pos.y == 1280)
            {
                num1 = -1;
            }
            terrain[9].pos.y = terrain[9].pos.y+ (3 * num1);
            
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[21]) || Game::instance()->bgManager()->hitCheck(obj, terrain[22]))
            {
                death = true;
            }
        }
        for (int i = min1; i < max1; ++i)
        {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i]))
            {
                float dist;
                if (obj->speed.y >= 0) {
                    dist = Game::instance()->bgManager()->checkDown(obj, terrain[i]);
                    onGround = true;
                }
                else
                    dist = Game::instance()->bgManager()->checkUp(obj, terrain[i]);
                obj->position.y += dist;
                obj->speed.y = 0;

            }
        }

        //TODO_03 左右入力の取り出し
        switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
        {
        case PAD_LEFT:  // 左だけが押されている場合
            obj->speed.x -= KASOKU;
            
           
            break;
        case PAD_RIGHT: // 右だけが押されている場合
            obj->speed.x += KASOKU;
           
            break;
        default:        // どちらも押されていないか相殺されている場合
            if (obj->speed.x > 0)
            {
                obj->speed.x -= (KASOKU / 2);

                if (obj->speed.x < 0)
                {
                    obj->speed.x = 0;
                }
            }
            if (obj->speed.x < 0)
            {
                obj->speed.x += (KASOKU / 2);

                if (obj->speed.x > 0)
                {
                    obj->speed.x = 0;
                }
            }
            break;
        }

        obj->speed.x = clamp(obj->speed.x, -16, 16);

        //TODO_03 X方向移動
        obj->position.x += obj->speed.x;

        
        for (int i = min1; i < max1; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i])) {
                float dist;
                if (obj->speed.x > 0)
                    dist = Game::instance()->bgManager()->checkRight(obj, terrain[i]);
                else
                    dist = Game::instance()->bgManager()->checkLeft(obj, terrain[i]);
                obj->position.x += dist;
                obj->speed.x = 0;

            }
        }

        //TODO_04 ジャンプチェック
        if (onGround == true && TRG(0) & PAD_TRG1)
        {
            obj->jumpTimer = 20;
        }

        //TODO_04 ジャンプ中
        if (obj->jumpTimer > 0)
        {
            if (STATE(0) & PAD_TRG1)
            {
                obj->speed.y += SPEED_JUMP_Y;
                --obj->jumpTimer;
            }
            else
            {
                obj->jumpTimer = 0;
            }
        }

        debug::setString("onGround:%d", onGround);
        debug::setString("jumpTimer:%d", obj->jumpTimer);
       
        //TODO_05 エリアチェック
        const float left = 0 + obj->size.x;
        const float right = window::getWidth() - obj->size.x;

        if (obj->position.x < 0 + left)
        {
            obj->position.x = 0 + left;
            obj->speed.x = 0;
        }

        if (obj->position.x > right)
        {
            obj->position.x = right;
            obj->speed.x = 0;
        }

        for (int i = mindoor1; i < maxdoor1; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, door[i])) {
                Door1 = true;
                break;
            }
            else
            {
                Door1 = false;
            }
        }

        break;
    }

    // アニメーション更新
    if (animeData)
    {
        // animeDataに値が入っていれば、obj->animeUpdateメソッドを呼ぶ
        obj->animeUpdate(animeData);
    }
}

//--------------------------------
//  消去
//--------------------------------
void ErasePlayer::erase(OBJ2D* obj)
{
    obj->clear();           // OBJ2Dを消去する
}

void Player2::move(OBJ2D* obj,int t)
{
    using namespace input;  // 関数内で入力処理を行うときに記述する

    // 定数（これらはこの関数内でしか使用しないため、ここで定義している）
    const float KASOKU = 1.0f;    // 横方向・縦方向の加速度
    const float SPEED_MAX_X = 8.0f;    // 横方向の最大速度
    const float SPEED_MAX_Y = 16.0f;   // 最大の落下速度
    const float SPEED_JUMP_Y = -12.0f;   // ジャンプ中の上昇スピード

    // 変数
    AnimeData* animeData = nullptr;
    bool onGround = false;          // 地上フラグ
    

    playerPosition2X = obj->position.x;
    playerPosition2Y = obj->position.y;

    switch (obj->state)
    {
    case 0:
        //////// 初期設定 ////////
       
        //アニメの初期設定
        animeData = animePlayer2__Up;   // 初期値として下向きのアニメを設定する

        // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
        obj->size = VECTOR2(96 / 3, 128);
        switch (t)
        {
        case 0:
            min2 = 0;
            max2 = 4;
            mindoor2 = 0;
            maxdoor2 = 2;
            break;
        case 1:
            min2 = 4;
            max2 = 12;
            mindoor2 = 2;
            maxdoor2 = 4;
            break;
        case 2:
            min2 = 12;
            max2 = 21;
            mindoor2 = 4;
            maxdoor2 = 6;
            break;
        }
        death = false;
        obj->state++;

        break;

    case 1:
        //////// 通常時 ////////

        // 毎フレーム毎の初期設定
        onGround = false;   // 地面フラグは毎フレームの最初にfalseにしておき、地面に接していたらtrueを設定する

        //TODO_01 プレイヤーの移動（Y方向）
        obj->speed.y += KASOKU;

        obj->speed.y = (std::min)(obj->speed.y, SPEED_MAX_Y);

        obj->speed.y = (std::max)(obj->speed.y, -SPEED_MAX_Y);
        obj->position.y += obj->speed.y;


        for (int i = min2; i < max2; ++i)
        {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i]))
            {
                float dist;
                if (obj->speed.y >= 0) {
                    dist = Game::instance()->bgManager()->checkDown(obj, terrain[i]);
                    onGround = true;
                }
                else
                    dist = Game::instance()->bgManager()->checkUp(obj, terrain[i]);
                obj->position.y += dist;
                obj->speed.y = 0;

            }
        }

        if (t == 0)
        {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[21]) || Game::instance()->bgManager()->hitCheck(obj, terrain[22]))
            {
                death = true;
            }
        }
        //TODO_03 左右入力の取り出し
        switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
        {
        case PAD_LEFT:  // 左だけが押されている場合
            obj->speed.x -= KASOKU;
            break;
        case PAD_RIGHT: // 右だけが押されている場合
            obj->speed.x += KASOKU;
            break;
        default:        // どちらも押されていないか相殺されている場合
            if (obj->speed.x > 0)
            {
                obj->speed.x -= (KASOKU / 2);

                if (obj->speed.x < 0)
                {
                    obj->speed.x = 0;
                }
            }
            if (obj->speed.x < 0)
            {
                obj->speed.x += (KASOKU / 2);

                if (obj->speed.x > 0)
                {
                    obj->speed.x = 0;
                }
            }
            break;
        }

        obj->speed.x = clamp(obj->speed.x, -16, 16);

        //TODO_03 X方向移動
        obj->position.x += obj->speed.x;

        for (int i = min2; i < max2; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, terrain[i])) {
                float dist;
                if (obj->speed.x > 0)
                    dist = Game::instance()->bgManager()->checkRight(obj, terrain[i]);
                else
                    dist = Game::instance()->bgManager()->checkLeft(obj, terrain[i]);
                obj->position.x += dist;
                obj->speed.x = 0;

            }
        }

        //TODO_04 ジャンプチェック
        if (onGround == true && TRG(0) & PAD_TRG1)
        {
            obj->jumpTimer = 20;
        }

        //TODO_04 ジャンプ中
        if (obj->jumpTimer > 0)
        {
            if (STATE(0) & PAD_TRG1)
            {
                obj->speed.y += SPEED_JUMP_Y;
                --obj->jumpTimer;
            }
            else
            {
                obj->jumpTimer = 0;
            }
        }

        debug::setString("onGround:%d", onGround);
        debug::setString("jumpTimer:%d", obj->jumpTimer);

        //TODO_05 エリアチェック
        const float left = 0 + obj->size.x;
        const float right = window::getWidth() - obj->size.x;

        if (obj->position.x < 0 + left)
        {
            obj->position.x = 0 + left;
            obj->speed.x = 0;
        }

        if (obj->position.x > right)
        {
            obj->position.x = right;
            obj->speed.x = 0;
        }
        for (int i = mindoor2; i < maxdoor2; ++i) {
            if (Game::instance()->bgManager()->hitCheck(obj, door[i])) {
                Door2 = true;
                break;
            }
            else
            {
                Door2 = false;
            }
        };

        break;
    }

    // アニメーション更新
    if (animeData)
    {
        // animeDataに値が入っていれば、obj->animeUpdateメソッドを呼ぶ
        obj->animeUpdate(animeData);
    }
}


