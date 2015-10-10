#pragma once
//
//  project_1_entrega - Orange.h
//

#ifndef __project_1_entrega__Orange__
#define __project_1_entrega__Orange__

#include "Game.h"
#include "GameObject.h"
#include <stdio.h>

class Orange : public DynamicObject{
private:
public:
    Orange();
    ~Orange();

    void draw();
    void update(float);
};

#endif /* defined(__project_1_entrega__Orange__) */
