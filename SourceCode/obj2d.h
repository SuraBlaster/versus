#pragma once
//******************************************************************************
//
//
//      OBJ2D�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <list>
#include "../GameLib/vector.h"
#include "../GameLib/obj2d_data.h"


#define TERRAIN_NUM (26)
// �O���錾
class OBJ2D;

//==============================================================================

// �ړ��A���S���Y���N���X�i���ۃN���X�j
class MoveAlg
{
public:
    virtual void move(OBJ2D* obj,int t) = 0;  // �������z�֐������̂ŁAMoveAlg�^�̃I�u�W�F�N�g�͒�`�ł��Ȃ��i�h�������Ďg���j
};

// �����A���S���Y���N���X�i���ۃN���X�j
class EraseAlg
{
public:
    virtual void erase(OBJ2D* obj) = 0; // ��Ɠ��l
};


//==============================================================================
//==============================================================================
//
//      OBJ2D�N���X
//
//==============================================================================

class OBJ2D
{
public:
    // �����o�ϐ�
    GameLib::SpriteData* data;               // �X�v���C�g�f�[�^
    GameLib::Anime          anime;              // �A�j���[�V�����N���X

    VECTOR2                 position;           // �ʒu
    VECTOR2                 scale;              // �X�P�[��
    float                   angle;              // �p�x
    VECTOR4                 color;              // �`��F
    VECTOR2                 size;               // ������p�T�C�Y�i�c���j

    MoveAlg* mvAlg;              // �ړ��A���S���Y��
    EraseAlg* eraseAlg;           // �����A���S���Y��

    float                   velocity;           // ���x
    VECTOR2                 speed;              // �u�Ԃ̈ړ��ʃx�N�g��
    int                     state;              // �X�e�[�g
    int                     timer;              // �^�C�}�[

    int                     param;              // �ėp�p�����[�^
    int                     jumpTimer;          // �������W�����v�^�C�}�[

    int                     iWork[16];          // �ėp�i�g�����͎��R�j
    float                   fWork[16];          // �ėp�i�g�����͎��R�j

    bool                    hashigoFlag;        // �͂����t���O
    bool                    drawHitRectFlag;    // �����蔻��`��t���O
    bool                    judgeFlag;          // �����蔻��̗L���itrue:�L�� / false:�����j
    BYTE                    pad[1];             // 1�o�C�g�̋�
   



public:

    OBJ2D();        // �R���X�g���N�^
    void clear();   // �����o�ϐ��̃N���A
    void move(int t);    // �ړ�
    void draw();    // �`��



    bool animeUpdate(GameLib::AnimeData* animeData);    // �A�j���[�V�����̃A�b�v�f�[�g
};



//==============================================================================

// OBJ2DManager�N���X
class OBJ2DManager
{
protected:
    std::list<OBJ2D>  objList; // ���X�g�iOBJ2D�̔z��̂悤�Ȃ��́j
public:
    // �f�X�g���N�^
    ~OBJ2DManager();

    void init();    // ������
    void update(int t);  // �X�V
    void draw();    // �`��

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos = VECTOR2(0, 0)); // objList�ɐV����OBJ2D��ǉ�����
    std::list<OBJ2D>* getList() { return &objList; }                // objList���擾����

    bool deth();
};

struct object
{
    VECTOR2 pos;
    VECTOR2 hsize;

    float speed;
};

static object terrain[TERRAIN_NUM] = {
    //�`���[�g���A���X�e�[�W
    {{ 0, 1060 },  {1900, 10 }, {}},
    {{0,530},{1900,10}, {}},
    {{1200,940},{30,120},{}},
    {{900,410},{30,120},{}},
    //�X�e�[�W1
     {{ 0, 1030 },  {500, 30 }, {}},
    {{0,500},{500,30}, {}},         
    {{0,300},{1900,20},{}},
    {{0,710},{400,30},{}},//
    {{390,1080},{30,400},{}},//
    {{350,1120},{50,200},{}},
    {{1700,1030},{300,30},{}},
    {{1700,500},{300,30},{}},
    //�X�e�[�W2
     {{ 0, 1040 },  {1900, 30 }, {}},
    {{0,500},{1900,30}, {}},
    { { 500,0 },{30,500},{} },
    {{1300,0},{30,500},{}},
    {{890,230} ,{ 250,200 }, {}},
    {{600,1000},{30,500},{}},
    {{1200,1000},{30,500},{}},
    {{900,1000},{300,30},{}},
    {{900,550},{300,30},{}},

    //�X�e�[�W�P�̐j�̓����蔻��
    {{950,500},{450,20},{} },
    {{950,1020},{450,20},{}}
};
