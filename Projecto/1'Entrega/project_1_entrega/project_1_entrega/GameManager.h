//
//  project_1_entrega - GameManager.h
//

#ifndef __project_1_entrega__GameManager__
#define __project_1_entrega__GameManager__
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include <stdio.h>
#include "Track.h"
#include "Car.h"
#include "Cheerio.h"

class GameManager{
private:
    Car car;
    Track track;
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
