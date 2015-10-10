#pragma once
//
//  project_1_entrega - Car.h
//

#ifndef __project_1_entrega__Car__
#define __project_1_entrega__Car__

#include <complex>
#include <stdio.h>
#include "Game.h"
#include "GameObject.h"

class Car: public DynamicObject{
private:
    GLdouble _pos_x, _pos_y, _pos_z;
    GLdouble _dir_angle;
    GLdouble _speed_x, _speed_y, _speed_z;
    bool _move_up, _move_down, _move_left, _move_right;
    
    void setPosition(GLdouble, GLdouble, GLdouble);
    void setSpeed(GLdouble, GLdouble, GLdouble);
    
    void drawCarModel();
public:
    Car();
    ~Car();
    
    void draw();
    void update(float);
    
    void keyPress(int);
    void keyRelease(int);
};

#endif /* defined(__project_1_entrega__Car__) */
