#include "stage.h"
#include "../GameLib/game_lib.h"
#include "common.h"
#include "stage1.h"
#include "tutorial.h"
using namespace GameLib;
Stage Stage::instance_;

void Stage::update()
{
    using namespace input;
    switch (state)
    {
    case 0:
        //////// �����ݒ� ////////

        timer = 0;                                  // �^�C�}�[��������
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����
        state++;                                    // �����������̏I��
        table = 0;


        /*fallthrough*/                             // �Ӑ}�I��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////

        timer++;                            // �^�C�}�[�𑫂�

        if (TRG(0) & PAD_RIGHT && table< TABLE_MAX)
        {
            table++;
        }
        if (TRG(0) & PAD_LEFT && table>0)
        {
            table--;
        }

        if (TRG(0) & PAD_START)             // PAD_TRG1�������ꂽ��
        {
            switch (table)  //�������Ă�table�̃X�e�[�W�ɍs��
            {
            case 0:
                changeScene(Tutorial::instance());
                break;
            case 1:
                changeScene(Stage1::instance());
                break;
            case 2:

                break;
            }

        }
            //changeScene(Game::instance());  // �Q�[���V�[���ɐ؂�ւ�

        break;
    }
}

void Stage::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));

   

    switch (table)
    {
    case 0:
        if (timer / 40 % 2)
        {
            
            primitive::rect(200, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);

            font::textOut(4, "1", { 480, 540 }, { 2, 2 }, { 1, 0.5f, 0, 1 });
        }
        primitive::rect(900, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
        primitive::rect(1600, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
        break;
    case 1:
            
            if (timer / 40 % 2)
            {
                primitive::rect(900, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
                font::textOut(4, "2", { 700, 540 }, { 2, 2 }, { 1, 0.5f, 0, 1 });
            }
            primitive::rect(200, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
            primitive::rect(1600, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
        break;
     case 2:
            
            if (timer / 40 % 2)
            {
            primitive::rect(1600, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
                font::textOut(4, "2", { 700, 540 }, { 2, 2 }, { 1, 0.5f, 0, 1 });
            }
            primitive::rect(200, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
            primitive::rect(900, 500, 300, 300, 0, 0, 0, 0, 0, 0, 1);
        break;
    }
}
