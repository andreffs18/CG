

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
    
    GLfloat amb_front_wheel[4]      = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat diffuse_front_wheel[4]  = {1.0f, 0.55f, 0.07568f, 1.0f};
    GLfloat specular_front_wheel[4] = {0.633f, 0.727811f, 0.633f, 1.0f};
    GLfloat shine_front_wheel       = 76.8f;
    
    GLfloat amb_back_wheel[4]       = {0.0f, 1.0f, 1.0f, 1.0f};
    GLfloat diffuse_back_wheel[4]   = {1.0f, 0.55f, 0.07568f, 1.0f};
    GLfloat specular_back_wheel[4]  = {0.633f, 0.727811f, 0.633f, 1.0f};
    GLfloat shine_back_wheel        = 76.8f;
    
    GLfloat amb_body[4]         = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat diffuse_body[4]     = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat specular_body[4]    = {0.0f, 0.0f, 0.633f, 1.0f}; //{0.633f, 0.727811f, 0.633f, 1.0f}
    GLfloat shine_body          = 76.8f;
    
    GLfloat amb_spoiler[4]      = {1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat diffuse_spoiler[4]  = {1.0f, 0.55f, 0.07568f, 1.0f};
    GLfloat specular_spoiler[4] = {0.633f, 0, 0, 1.0f};
    GLfloat shine_spoiler       = 76.8f;
    
public:
    Car();
    ~Car();
    
    void draw();
    void update(float);
    
    void die();
    
    void setMoveUp(bool);
    void setMoveDown(bool);
    void setMoveLeft(bool);
    void setMoveRight(bool);
    
    void setScale(GLdouble);
    GLdouble getScale();
};

#endif /* defined(__CAR_H_INCLUDED__) */
