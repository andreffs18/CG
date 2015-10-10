//
//  project_1_entrega - Car.h
//
#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__

#include "DynamicObject.h"

class Car: public DynamicObject{
private:
    GLdouble _dir_angle;
    
    bool _move_up, _move_down, _move_left, _move_right;
    void drawCarModel();
public:
    Car();
    ~Car();
    
    void draw();
    void update(float);
    
    void keyPress(int);
    void keyRelease(int);
};

#endif /* defined(__CAR_H_INCLUDED__) */
