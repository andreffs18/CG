//
//  project_1_entrega - Orange.h
//
#ifndef __ORANGE_H_INCLUDED__
#define __ORANGE_H_INCLUDED__

#include "DynamicObject.h"

class Orange : public DynamicObject{
private:
    GLfloat amb[4] ={1.0f,0.4f,0.0f,1.0f};
    GLfloat diffuse[4]={1.0f,0.55f,0.07568f,1.0f};
    GLfloat specular[4]={0.633f,0.727811f,0.633f,1.0f};
    GLfloat shine = 76.8f;
    
public:
    Orange();
    ~Orange();

    void draw();
    void update(float);
};

#endif /* defined(__ORANGE_H_INCLUDED__) */
