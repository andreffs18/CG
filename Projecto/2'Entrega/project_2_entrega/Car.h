//
//  project_1_entrega - Car.h
//
#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__

#include "DynamicObject.h"

class Car: public DynamicObject{
private:
    GLdouble _scale;
    bool _move_up, _move_down, _move_left, _move_right;
    void drawCarModel();
public:
    Car();
    ~Car();
    
    void draw();
    void update(float);
    
    void set_move_up(bool);
    void set_move_down(bool);
    void set_move_left(bool);
    void set_move_right(bool);
    
    bool is_move_up();
    bool is_move_down();
    bool is_move_left();
    bool is_move_rigth();

    
    void setScale(GLdouble);
    GLdouble getScale();
};

#endif /* defined(__CAR_H_INCLUDED__) */
