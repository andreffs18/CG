//
//  project_1_entrega
//  Created by Ana Galvão, André Silva, Daniel Pinho on 25/9/15.
//

//  ------------------------------------------------------ Global Variables

#include "GameManager.h"
#include "Track.h"
#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
#ifndef project_1_entrega_Game_h
// description of each global var in Game.h
#include "Game.h"
const char * WINDOW_NAME = "Projecto #1 Entrega";

int VIEWPORT_WIDTH = 600;
int VIEWPORT_HEIGHT = 600;
int WINDOW_X_POS = -1;
int WINDOW_Y_POS = -1;

GLdouble P_FOV = 60;
GLdouble P_ASPECT_RATIO = (float)VIEWPORT_WIDTH/(float)VIEWPORT_HEIGHT;
GLdouble P_NEAR = 0.1f;
GLdouble P_FAR = 100.0f;

bool DEBUG_LOG = true;
bool INFO_LOG = true;
bool ERROR_LOG = true;
bool ENABLE_AXIS = false;
bool ENABLE_DEPTH = false;
bool ENABLE_DOUBLE_BUFFER = false;
bool ENABLE_ROTATION_X = false;
bool ENABLE_ROTATION_Y = false;
bool ENABLE_ROTATION_Z = false;
float ROTATION_SPEED = 0.5f;
float ROTATION_POS = 0.0f;

// Track track = Track();

// initialize gloabl log object
#include "Logger.h"
Log logger = Log();
#endif



// if depth enable enable depth test in init and also glut double buffer

//  ---------------------------------------------------------------- main()
int main(int argc, char * argv[]) {
    // Game manager instance.
    GameManager gm = GameManager();
    
    // initialise glut library
    glutInit(&argc, argv);
    // request a RGBA display mode, and we want single buffering
    unsigned int BUFFER = (ENABLE_DOUBLE_BUFFER) ? GLUT_DOUBLE : GLUT_SINGLE;
    unsigned int DEPTH = (ENABLE_DEPTH) ? GLUT_DEPTH : 0;
    glutInitDisplayMode(GLUT_RGB|BUFFER|DEPTH);
    // set the initial window size
    glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    // set the initial window position
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
    // create the window with properties defined before
    glutCreateWindow(WINDOW_NAME);
    
    // set the callback function to use to draw our scene
    glutDisplayFunc(gm.onDisplay);
    // set the callback function to handle changes in screen size
    glutReshapeFunc(gm.onReshape);
    // set the keyboard function to handle keyboard events
    glutKeyboardFunc(gm.onKeyboard);
    // set the keyboard function to handle special keys events
    glutSpecialFunc(gm.onSpecialKeys);
    // set the mouse function to handle mouse stuff
    // glutMouseFunc(gm.onMouse);
    
    // runs forever in a loop to keep the program running
    glutMainLoop();
    return 0;
}