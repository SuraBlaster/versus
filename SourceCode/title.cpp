//******************************************************************************
//
//
//      �^�C�g��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"
#include "stage.h"
using namespace GameLib::input;
//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Title Title::instance_;
Sprite* sprtitle;
Sprite* sprtri;
//--------------------------------
//  �X�V����
//--------------------------------
void Title::update()
{
    using namespace input;

    switch (state)
    {
    case 0:
        //////// �����ݒ� ////////

        timer = 0;                                  // �^�C�}�[��������
        Flag = false;
        sprtitle = sprite_load(L"./Data/Images/revarse.png");
        sprtri = sprite_load(L"./Data/Images/triangle.png");

        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����
        sound::play(0, 0);
        titleTimer = 100;
        state++;                                    // �����������̏I��

        /*fallthrough*/                             // �Ӑ}�I��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////


        timer++;                            // �^�C�}�[�𑫂�

        if (TRG(0) & PAD_START)             // PAD_TRG1�������ꂽ��
        {
            Flag = true;
        }

        if (Flag == true)
        {
            if (titleTimer < 50 && backpos <= 1080)
            {
                if (backpos <= 1080)
                {
                    backpos += 65;
                }
                else if (backpos <= 880)
                {
                    backpos += 50;
                }
                else if (backpos <= 680)
                {
                    backpos += 40;
                }
                else if (backpos <= 480)
                {
                    backpos += 30;
                }

            }


            titleTimer--;

            if (titleTimer <= 0)
            {
                changeScene(Stage::instance());
            }
        }
        break;
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Title::draw()
{
    // ��ʃN���A
    //GameLib::clear(VECTOR4(0.2f, 0.3f, 1.0f, 1));

    sprite_render(sprtitle, 0, 0);

    if (Flag == true)
    {
        if (timer / 10 % 2)
        {
            sprite_render(sprtri, 850, 582, 0.13f, 0.13f, 0, 0, 572, 493, 0, 0, ToRadian(90));
        }
    }
    else
    {
        sprite_render(sprtri, 850, 582, 0.13f, 0.13f, 0, 0, 572, 493, 0, 0, ToRadian(90));
    }


    primitive::rect(0, 1080 - backpos, 1920, 1200, 0, 0, 0, 0, 0, 0);

}
