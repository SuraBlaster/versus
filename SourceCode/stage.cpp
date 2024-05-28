#include "stage.h"
#include "../GameLib/game_lib.h"
#include "common.h"
#include "stage1.h"
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
                changeScene(Stage1::instance());
                break;
            }

        }
            //changeScene(Game::instance());  // �Q�[���V�[���ɐ؂�ւ�

        break;
    }
}

void Stage::draw()
{

}
