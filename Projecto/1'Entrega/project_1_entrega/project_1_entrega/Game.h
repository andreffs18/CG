//
//  project_1_entrega - Game.h
//
//  GLOBAL VARIABLES FILE:
//
//  To add variables:
//   #1 - Add variable in Game.h like below
//   #2 - Define variable value in Game.cpp.

#include <GL\glut.h>
#include <stdio.h>
#include <iostream>
#include "GameManager.h"
#include "Logger.h"

#ifndef project_1_entrega_Game_h
#define project_1_entrega_Game_h

// WIDTH and HEIGHT size of game window
extern int VIEWPORT_WIDTH;
extern int VIEWPORT_HEIGHT;
// Positon X and Y of window.
extern int WINDOW_X_POS;
extern int WINDOW_Y_POS;
// Config Perspective
extern GLdouble P_FOV;
extern GLdouble P_ASPECT_RATIO;
extern GLdouble P_NEAR;
extern GLdouble P_FAR;
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
// Turn on/off axis on objects
extern bool ENABLE_AXIS;
// Turn on/off depth of field on 3D objs
extern bool ENABLE_DEPTH;
// Turn on/off double buffer
extern bool ENABLE_DOUBLE_BUFFER;
// Global Position for the camera
extern GLdouble G_CAMERA_POS_X;
extern GLdouble G_CAMERA_POS_Y;
extern GLdouble G_CAMERA_POS_Z;
extern GLdouble AXIS[3];
// Specific velocity
extern float ROTATION_SPEED;
// Global rotation (initialized @ zero)
extern float ROTATION_POS;

#endif /* defined(__project_1_entrega__Game__) */

