//
//  project_1_entrega - GameManager.h
//

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

#include <vector>
#include "DynamicObject.h"
#include "StaticObject.h"

class GameManager{
private:
    std::vector<StaticObject *> _static_objects;
    std::vector<DynamicObject *> _dynamic_objects;
    int _current_time, _previous_time;
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
    static void onMouseClick(int button, int state, int x, int y);
    static void onMouseMotion(int x, int y);
    static void onIdle();
};

#endif /* defined(__GAMEMANAGER_H_INCLUDED__) */
