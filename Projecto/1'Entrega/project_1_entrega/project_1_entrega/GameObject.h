//
//  project_1_entrega - GameObject.h
//

#ifndef __project_1_entrega__GameObject__
#define __project_1_entrega__GameObject__

#include <stdio.h>
#include <GLUT/glut.h>

class GameObject{
private:
public:
    GameObject();
    ~GameObject();
    void draw();
    void update();
    
    // foooling around - tests
    void customSolidCube();
    void axis(GLdouble size = 2.0f);
};

#endif /* defined(__project_1_entrega__GameObject__) */
