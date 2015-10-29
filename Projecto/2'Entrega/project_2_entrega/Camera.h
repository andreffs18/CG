//
//  project_2_entrega - Camera.h
//
#ifndef __CAMERA_H_INCLUDED__
#define __CAMERA_H_INCLUDED__

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include "Vector3.h"


class Camera{
protected:
    Vector3 * _pos;
    Vector3 * _up;
    Vector3 * _at;
    GLdouble _near;
    GLdouble _far;
    GLdouble _aspect;
    GLdouble _fovy;
    
public:
    Camera(GLdouble near, GLdouble far);
    ~Camera();
    
    virtual void update();
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
    
    void setPos(Vector3 * newpos);
    void setAt(Vector3 * newat);
    void setUp(Vector3 * newup);
};
#endif /* Camera_h */
