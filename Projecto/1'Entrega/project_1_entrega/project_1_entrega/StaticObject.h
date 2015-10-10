//
//  project_1_entrega - StaticObject.h
//

#ifndef __STATICOBJECT_H_INCLUDED__
#define __STATICOBJECT_H_INCLUDED__
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif
//#include <stdio.h>
#include "GameObject.h"
//

class StaticObject : public GameObject{
protected:
public:
    StaticObject();
    ~StaticObject();
    
    void draw();
};

#endif /* defined(__STATICOBJECT_H_INCLUDED__) */