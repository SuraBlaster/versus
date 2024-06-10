#pragma once
#include "scene.h"

class Stage :public Scene
{
public:
    static Stage* instance() { return &instance_; }
    void update();
    void draw();

private:
    static Stage instance_;
    int backpos;
    int backpos2;
    bool Flag;
    int stagetimer;
};