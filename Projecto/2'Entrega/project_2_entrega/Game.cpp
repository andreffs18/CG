//
//  project_1_entrega
//  Created by Ana Galvão, André Silva, Daniel Pinho on CG-2015.
//
// description of each global var in Game.h
#include "Game.h"
#include <vector>

const char * WINDOW_NAME = "Projecto #2 Entrega";
int VIEWPORT_WIDTH = 800;
int VIEWPORT_HEIGHT = 800;
int WINDOW_X_POS = -1;
int WINDOW_Y_POS = -1;

float GRAVIT_CONST = 9.8f;
float PI = 3.14159;

bool DEBUG_LOG = false;
bool INFO_LOG = true;
bool ERROR_LOG = true;

bool COLISION_SPHERE = true;

// initialize global log object
Log logger = Log();
// initialize game manager
GameManager gm = GameManager();

//  ---------------------------------------------------------------- main()
int main(int argc, char * argv[]) {
    // initialise glut library
    glutInit(&argc, argv);
    // request a RGBA display mode, and we want single buffering
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    // set the initial window size
    glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    // set the initial window position
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
    // create the window with properties defined before
    glutCreateWindow(WINDOW_NAME);
    // stops continuisly pressing keyboard
    glutIgnoreKeyRepeat(1);
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
    // when mouse buttons are clicked
    glutMouseFunc(GameManager::onMouseClick);
    // when mouse move's
    glutMotionFunc(GameManager::onMouseMotion);
    // runs forever in a loop to keep the program running
    glutMainLoop();
    return 0;
}