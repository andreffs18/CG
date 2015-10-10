//
//  project_1_entrega - Car.h
//
#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__

#include "DynamicObject.h"

class Car: public DynamicObject{
private:
    Vector3 _position = 

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

#endif /* defined(__CAR_H_INCLUDED__) */
