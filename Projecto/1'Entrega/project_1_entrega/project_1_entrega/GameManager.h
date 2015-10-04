//
//  project_1_entrega - GameManager.h
//

#ifndef __project_1_entrega__GameManager__
#define __project_1_entrega__GameManager__

#include <stdio.h>
#include <GL\glut.h>

class GameManager{
private:
public:
    GameManager();
    ~GameManager();
    static void onReshape(GLsizei w, GLsizei h);
    static void onDisplay();
    static void onKeyboard(unsigned char key, int x, int y);
    static void onMouse(int button, int state, int x, int y);
    static void onSpecialKeys(int key, int x, int y);
};

#endif /* defined(__project_1_entrega__GameManager__) */
