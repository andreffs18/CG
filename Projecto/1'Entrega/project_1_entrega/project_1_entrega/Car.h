//
//  project_1_entrega - Car.h
//


#ifndef __project_1_entrega__Car__
#define __project_1_entrega__Car__

#include "DynamicObject.h"
#include <stdio.h>

class Car{
private:
    GLdouble pos_x = 0.0f, pos_y = 0.0f, pos_z = 0.0f;
    GLdouble rot_angle = 90.0f, rot_x = 1.0f, rot_y = 0.0f, rot_z = 0.0f;
    void setRot(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    void setPos(GLdouble x, GLdouble y, GLdouble z);
public:
    Car();
    ~Car();
    void draw();
    void update();
    
    
    void move_left();
    void move_right();
    void move_forward();
    void move_backwards();
};

#endif /* defined(__project_1_entrega__Car__) */
