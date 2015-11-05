//
//  project_1_entrega - Game.h
//
//  GLOBAL VARIABLES FILE:
//
//  To add variables:
//   #1 - Add variable in Game.h like below
//   #2 - Define variable value in Game.cpp.
#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__
#include "Logger.h"
#include "GameManager.h"
#include "Vector3.h"
#include "Material.h"

// WIDTH and HEIGHT size of game window
extern int VIEWPORT_WIDTH;
extern int VIEWPORT_HEIGHT;
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
// Initialize GameManager object
extern GameManager gm;
// PI 3.1415.. constant
extern float PI;
// Gavitational constant
extern float GRAVIT_CONST;
// Enable collision sphere object to be seen
extern bool COLISION_SPHERE;
#endif /* defined(__GAME_H_INCLUDED__) */
