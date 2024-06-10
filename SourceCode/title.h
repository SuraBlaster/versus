﻿#pragma once

//******************************************************************************
//
//
//      ^Cg‹V[“
//
//
//******************************************************************************

//==============================================================================
//
//      TitleN‰X
//
//==============================================================================

class Title : public Scene
{
public:
    static Title* instance() { return &instance_; }

    void update();
    void draw();

private:
    static Title instance_;
    bool Flag;
    int titleTimer;
    int backpos;
};
