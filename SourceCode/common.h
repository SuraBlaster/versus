#pragma once

//******************************************************************************
//
//
//      common
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <DirectXMath.h>

//------< �֐� >----------------------------------------------------------------
static constexpr int TABLE_MAX = 3;
static constexpr int YUKA = 550;

static float(*const ToRadian)(float) = DirectX::XMConvertToRadians;  // �p�x�����W�A����
static float(*const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ���W�A�����p�x��

