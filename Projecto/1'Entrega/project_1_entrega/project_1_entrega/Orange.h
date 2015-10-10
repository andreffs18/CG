//
//  project_1_entrega - Orange.h
//

#ifndef __ORANGE_H_INCLUDED__
#define __ORANGE_H_INCLUDED__
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif
//#include "Game.h"
//#include "GameObject.h"
#include "DynamicObject.h"
//#include <stdio.h>

class Orange : public DynamicObject{
private:
public:
    Orange();
    ~Orange();

    void draw();
    void update(float);
};

#endif /* defined(__ORANGE_H_INCLUDED__) */
