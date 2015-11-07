

//
//  project_1_entrega - Car.h
//
#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__

#include "DynamicObject.h"

class Car: public DynamicObject{
private:
    // car VERSION 1 is built with glut function
    // VERSION 2 with primitives and normalized vectors
    int VERSION = 2;
    
    GLdouble _scale;
    bool _move_up, _move_down, _move_left, _move_right;
    void drawCarModel();
    
    void drawV1();
    void drawV2();
    
    void _drawCube();
    void _drawHexagon();
    
public:
    Car();
    ~Car();
    
    void draw();
    void update(float);
    
    void setMoveUp(bool);
    void setMoveDown(bool);
    void setMoveLeft(bool);
    void setMoveRight(bool);
    
    void setScale(GLdouble);
    GLdouble getScale();
};

#endif /* defined(__CAR_H_INCLUDED__) */
