//
//  GameObject.h
//  project_1_entrega
//
//  Created by André Silva on 9/27/15.
//
//

#ifndef __project_1_entrega__GameObject__
#define __project_1_entrega__GameObject__

#include <stdio.h>
#include <GL\glut.h>

class GameObject{
private:
public:
    GameObject();
    ~GameObject();
    void draw();
    void update();
    
    
    
    
    
    
    // foooling around - tests
    void customSolidCube();
    void customRedRectangle();
    void customGreenRectangle();
    void customWhiteSquare();
    void axis(GLdouble size = 2.0f);
};

#endif /* defined(__project_1_entrega__GameObject__) */
