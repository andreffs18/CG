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
    // Global Variables
    // speed increment on car
    GLdouble SPEED_INCREMENT = 0.00005f;
    // max velocity allowed
    GLdouble MAX_VELOCITY = 0.0010f;
    // steering direction angle increment
    GLdouble ANGLE_INCREMENT = 4.0f;
    // car limits on track
    GLdouble TRACK_LIMITS = 1.0f;
    // amout of scale that affects all elements on the track
    // Note: this not affects car
    GLdouble AMOUNT = 1.0f;
    
public:
    GameObject();
    ~GameObject();
    virtual void draw();
    virtual void update(float);
    
    Vector3 * getPosition();
    void setPosition(Vector3 * pos);
};

#endif /* defined(__GAMEOBJECT_H_INCLUDED__) */
