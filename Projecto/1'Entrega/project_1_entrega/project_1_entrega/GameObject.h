#pragma once
//
//  project_1_entrega - GameObject.h
//

#ifndef __project_1_entrega__GameObject__
#define __project_1_entrega__GameObject__

#include "Game.h"
#include <stdio.h>

class GameObject{
protected:
    GLdouble _pos_x, _pos_y, _pos_z;
public:
    GameObject();
    ~GameObject();
    virtual void draw();
    virtual void update(float);

    // foooling around - tests
    void customSolidCube();
    void axis(GLdouble size = 2.0f);
};

#endif /* defined(__project_1_entrega__GameObject__) */
