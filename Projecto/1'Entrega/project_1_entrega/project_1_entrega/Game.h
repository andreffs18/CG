//
//  project_1_entrega - Game.h
//
//  GLOBAL VARIABLES FILE:
//
//  To add variables:
//   #1 - Add variable in Game.h like below
//   #2 - Define variable value in Game.cpp.

#include <stdio.h>
#include <iostream>
#include "Logger.h"

#ifndef project_1_entrega_Game_h
#define project_1_entrega_Game_h

// WIDTH and HEIGHT size of game window
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
// Positon X and Y of window.
extern int WINDOW_X_POS;
extern int WINDOW_Y_POS;
// Window name
extern const char * WINDOW_NAME;
// Global logs variables. set to true logs that want enable
extern bool DEBUG_LOG;
extern bool INFO_LOG;
extern bool ERROR_LOG;
// Initialize Logger object
extern Log logger;

// Turn on axis on objects
extern bool ENABLE_AXIS;

extern float g_rotate_X;
extern float g_rotate_speed;
extern bool ENABLE_ROTATION;

#endif /* defined(__project_1_entrega__Game__) */

