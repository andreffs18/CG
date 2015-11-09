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
    GLdouble _rotation;
    GLdouble _radius;
    
public:
    GameObject();
    ~GameObject();
    virtual void draw();
    virtual void update(float);
    
    Vector3 * getPosition();
    void setPosition(Vector3 *);
    
    GLdouble getRadius();
    void setRadius(GLdouble);

    GLdouble getRotation();
    void setRotation(GLdouble);
    
    bool collidesWith(GameObject *);
    
    void material(GLfloat amb[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat shine[4]);

    GLfloat * normalize(GLfloat, GLfloat, GLfloat);
};

#endif /* defined(__GAMEOBJECT_H_INCLUDED__) */
