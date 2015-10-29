//
//  Camera.hpp
//  project_2_entrega
//
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

#include "Game.h"

class Camera
{
protected:
    Vector3* _up;
    Vector3* _at;
    double _near;
    double _far;
    
public:
    Camera(double near, double far);
    ~Camera();
    virtual void update();
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
    void setAt(double x, double y, double z);
    
};

#endif /* Camera_h */
