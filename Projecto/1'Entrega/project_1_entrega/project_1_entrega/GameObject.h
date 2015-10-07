//
//  project_1_entrega - GameObject.h
//

#ifndef __project_1_entrega__GameObject__
#define __project_1_entrega__GameObject__
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include <stdio.h>

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
