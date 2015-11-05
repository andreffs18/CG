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
    
    
    GLfloat amb_wheel[4] ={1.0f,1.0f,1.0f,1.0f};
    GLfloat diffuse_wheel[4]={1.0f,0.55f,0.07568f,1.0f};
    GLfloat specular_wheel[4]={0.633f,0.727811f,0.633f,1.0f};
    GLfloat shine_wheel=76.8f;
    
    GLfloat ambright[4] ={0.0f,1.0f,1.0f,1.0f};
    GLfloat diffuseright[4]={1.0f,0.55f,0.07568f,1.0f};
    GLfloat specularright[4]={0.633f,0.727811f,0.633f,1.0f};
    GLfloat shineright=76.8f;
    
    GLfloat amb_body[4] ={0.0f,0.0f,1.0f,1.0f};
    GLfloat diffuse_body[4]={0.0f,0.0f,1.0f,1.0f};
    GLfloat specular_body[4]={0.0f,0.0f,1.0f,1.0f};
    GLfloat shine_body=76.8f;
    
    GLfloat ambspoiler[4] ={1.0f,0.0f,0.0f,1.0f};
    GLfloat diffusespoiler[4]={1.0f,0.55f,0.07568f,1.0f};
    GLfloat specularspoiler[4]={0.633f,0.727811f,0.633f,1.0f};
    GLfloat shinespoiler=76.8f;
    
    
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
