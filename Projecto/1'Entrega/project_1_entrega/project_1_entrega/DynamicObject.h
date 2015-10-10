//
//  project_1_entrega - DynamicObject.h
//

#ifndef __DYNAMICOBJECT_H_INCLUDED__
#define __DYNAMICOBJECT_H_INCLUDED__
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif
//
#include "GameObject.h"
//#include <stdio.h>

class DynamicObject : public GameObject{
protected:
    GLdouble _speed;
public:
    DynamicObject();
    ~DynamicObject();
    
    void draw();
    void update(float);
    
    void keyPress(int);
    void keyRelease(int);    
};

#endif /* defined(__DYNAMICOBJECT_H_INCLUDED__) */
