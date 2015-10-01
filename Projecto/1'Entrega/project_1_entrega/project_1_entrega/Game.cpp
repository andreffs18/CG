//
//  project_1_entrega
//  Created by Ana Galvão, André Silva, Daniel Pinho on 25/9/15.
//

//  ------------------------------------------------------ Global Variables
#ifndef project_1_entrega_Game_h
// description of each global var in Game.h
#include "Game.h"
const char * WINDOW_NAME = "Projecto #1 Entrega";

int VIEWPORT_WIDTH = 800;
int VIEWPORT_HEIGHT = 600;
int WINDOW_X_POS = -1;
int WINDOW_Y_POS = -1;

bool DEBUG_LOG = true;
bool INFO_LOG = true;
bool ERROR_LOG = true;

bool ENABLE_AXIS = true;
bool ENABLE_DEPTH = true;

bool ENABLE_ROTATION_X = true;
bool ENABLE_ROTATION_Y = true;
bool ENABLE_ROTATION_Z = true;
float ROTATION_SPEED = 0.1f;
float ROTATION_POS = 0.0f;

float YOLO = 1.0f;

// initialize gloabl log object
#include "Logger.h"
Log logger = Log();
#endif

#include "GameManager.h"
#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>

//  ---------------------------------------------------------------- main()
int main(int argc, char * argv[]) {
    // Game manager instance.
    GameManager gm = GameManager();
    // initialise glut library
    glutInit(&argc, argv);
    // request a RGBA display mode, and we want single buffering
    if(ENABLE_DEPTH)
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH); // GLUT_DOUBLE|GLUT_DEPTH # QUESTION
    else
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
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
    // enable depth
    if(ENABLE_DEPTH) glEnable(GL_DEPTH_TEST);
    // this function runs a forever in a loop to keep the program running
    glutMainLoop();
    return 0;
}