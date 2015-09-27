//
//  project_1_entrega - GameManager.h
//

#ifndef __project_1_entrega__GameManager__
#define __project_1_entrega__GameManager__

#include <stdio.h>
#include <GLUT/glut.h>

class GameManager{
private:
public:
    GameManager();
    ~GameManager();
    static void onReshape(GLsizei w, GLsizei h);
    static void onDisplay();
};

#endif /* defined(__project_1_entrega__GameManager__) */
