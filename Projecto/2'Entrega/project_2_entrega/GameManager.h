//
//  project_1_entrega - GameManager.h
//

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

#include <vector>
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Car.h"
#include "Track.h"
#include "Orange.h"
#include "Butter.h"
#include "Cheerio.h"

class GameManager{
private:
    std::vector<StaticObject *> _static_objects;
    std::vector<DynamicObject *> _dynamic_objects;
    int _current_time, _previous_time;

public:
    // Global Variables
    // speed increment on car
    GLdouble SPEED_INCREMENT = 0.00005f;
    // max velocity allowed
    GLdouble MAX_VELOCITY = 0.0010f;
    // steering direction angle increment
    GLdouble ANGLE_INCREMENT = 4.0f;
    // car limits on track
    GLdouble TRACK_LIMITS = 1.0f;
    // track inner circle
    float INNER_CIRCLE_RADIUS = 0.5;
    // track outer circle
    float OUTER_CIRCLE_RADIUS = 0.8;
    // qtd of object on table
    int QTD_CHEERIOS = 32;
    int QTD_ORANGES = 4;
    int QTD_BUTTERS = 4;
    
    GameManager();
    ~GameManager();

    void keyPress(int);
    void keyRelease(int);
    void drawAll();
    void updateAll();
    void Cam1();
    void Cam2();
    void Cam3();
    
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
