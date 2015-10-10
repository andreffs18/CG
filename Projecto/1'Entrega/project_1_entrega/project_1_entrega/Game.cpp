//
//  project_1_entrega
//  Created by Ana Galvão, André Silva, Daniel Pinho on 25/9/15.
//#include <iostream>
//#include <stdlib.h>
// description of each global var in Game.h

//#ifndef project_1_entrega_Game_h
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif

#include "Game.h"
#include <vector>

const char * WINDOW_NAME = "Projecto #1 Entrega";
int VIEWPORT_WIDTH = 600;
int VIEWPORT_HEIGHT = 600;
int WINDOW_X_POS = -1;
int WINDOW_Y_POS = -1;

GLdouble P_FOV = 60;
GLdouble P_ASPECT_RATIO = (float)VIEWPORT_WIDTH/(float)VIEWPORT_HEIGHT;
GLdouble P_NEAR = 0.1f;
GLdouble P_FAR = 100.0f;

float GRAVIT_CONST = 9.8f;
float PI = 3.14159;

bool DEBUG_LOG = false;
bool INFO_LOG = true;
bool ERROR_LOG = true;

bool ENABLE_AXIS = false;
bool ENABLE_DEPTH = true;
bool ENABLE_DOUBLE_BUFFER = false;

Vector3 * POSCAM = new Vector3(0.0f, 0.0f, 10.0f);

float ROTATION_SPEED = 0.5f;
GLdouble AXIS[3] = {0.0f, 1.0f, 0.0f};

// initialize global log object
Log logger = Log();
// initialize game manager
GameManager gm = GameManager();


//  ---------------------------------------------------------------- main()
int main(int argc, char * argv[]) {
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
    
    // stops continuisly pressing keyboard
    // glutIgnoreKeyRepeat(1);
    
    // set the callback function to use to draw our scene
    glutDisplayFunc(GameManager::onDisplay);
    // set the callback function to handle changes in screen size
    glutReshapeFunc(GameManager::onReshape);
    // set the keyboard function to handle keyboard events
    glutKeyboardFunc(GameManager::onKeyboard);
    // set the keyboard function to handle special keys events
    glutSpecialFunc(GameManager::onSpecialKeys);
    // set the keyboard function to handle the release of special keys events
    glutSpecialUpFunc(GameManager::onSpecialKeysUp);
    // when glut has no events to proccess
    glutIdleFunc(GameManager::onIdle);

    // runs forever in a loop to keep the program running
    glutMainLoop();
    return 0;
}