#pragma once
//
//  project_1_entrega - GameManager.h
//
#ifndef __project_1_entrega__GameManager__
#define __project_1_entrega__GameManager__
#include "Game.h"

#include "DynamicObject.h"
#include "StaticObject.h"

#include "Car.h"
#include "Track.h"
#include "Cheerio.h"
#include "Orange.h"
#include "Butter.h"

#include <vector>
#include <iostream>
#include <stdio.h>

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
    void updateAll(float);
    
    static void onReshape(GLsizei w, GLsizei h);
    static void onDisplay();
    static void onKeyboard(unsigned char key, int x, int y);
    static void onSpecialKeys(int key, int x, int y);
    static void onSpecialKeysUp(int key, int x, int y);
    static void onIdle();
};

#endif /* defined(__project_1_entrega__GameManager__) */
