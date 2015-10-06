//
//  project_1_entrega - GameManager.h
//

#ifndef __project_1_entrega__GameManager__
#define __project_1_entrega__GameManager__

#include <stdio.h>
#include <GLUT/glut.h>
#include "Track.h"
#include "Car.h"
#include "Cheerio.h"

class GameManager{
private:
    Car car;
public:
    GameManager();
    ~GameManager();
    
    void keyPress(int);
    void keyRelease(int);
    void drawAll();
    void updateAll();
    
    static void onReshape(GLsizei w, GLsizei h);
    static void onDisplay();
    static void onKeyboard(unsigned char key, int x, int y);
    static void onSpecialKeys(int key, int x, int y);
    static void onSpecialKeysUp(int key, int x, int y);
    static void onIdle();
};

#endif /* defined(__project_1_entrega__GameManager__) */
