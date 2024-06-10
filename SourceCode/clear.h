#pragma once
#include "scene.h"
class Clear : public Scene
{
public:
    static Clear* instance() { return &instance_; }

    void update();
    void draw();

private:
    static Clear instance_;
  
};
