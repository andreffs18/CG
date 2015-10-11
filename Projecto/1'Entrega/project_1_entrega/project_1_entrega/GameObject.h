//
//  project_1_entrega - GameObject.h
//
#ifndef __GAMEOBJECT_H_INCLUDED__
#define __GAMEOBJECT_H_INCLUDED__

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif

#include "Vector3.h"

class GameObject{
protected:
    Vector3 * _position;
public:
    GameObject();
    ~GameObject();
    virtual void draw();
    virtual void update(float);
    
    Vector3 * getPosition();
    void setPosition(Vector3 * pos);
};

#endif /* defined(__GAMEOBJECT_H_INCLUDED__) */
