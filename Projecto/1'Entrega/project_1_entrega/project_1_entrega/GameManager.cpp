//
//  project_1_entrega - GameManager.cpp
//
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include "Game.h"
#include "GameManager.h"
#include <iostream>

GameManager::GameManager(){
    logger.debug("GameManager::GameManager()");
    car = Car();
    track = Track();
    orange = Orange();
};
GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

//  ------------------------------------------------------------ keyPress()
//  game manager wrapper to handle all objects keyPress
void GameManager::keyPress(int key){
    car.keyPress(key);
};

//  ---------------------------------------------------------- keyRelease()
//  game manager wrapper to handle all objects keyRelease
void GameManager::keyRelease(int key){
    car.keyRelease(key);
}

//  ------------------------------------------------------------- drawAll()
//  Method that handles the drawing of all objects in the display
void GameManager::drawAll(){
    logger.debug("GameManager::drawAll()");
    car.draw();
    track.draw();
    orange.draw();
};

//  ----------------------------------------------------------- updateAll()
//  Method that handle all the updates, calculations and what
//  not of each object in the display
void GameManager::updateAll(float delta_t){
    logger.debug("GameManager::updateAll()");
    car.update(delta_t);
    //track.update();
};

//  ----------------------------------------------------------- onReshape()
//  Custom reshape function used when "glutReshapeFunc"
//  triggers an event. This handles the change in screen size
void GameManager::onReshape(GLsizei w, GLsizei h){
    logger.debug("GameManager::onReshape()");
    // define size of the viewport
    // args: x, y, weight, height
    // x and y are measure from the bottom left corner of the screen
    // weight and height are the actual size of the viewport
    float xmin = -1., xmax = 1., ymin = -1., ymax = 1.;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float) w / h;
    if (aspect > ratio)
        glViewport((w-h*ratio)/2, 0, h*ratio, h);
    else
        glViewport(0, (h-w/ratio)/2, w, w/ratio);
    // changes the pointer for which Matrix we want to work on. GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    // puts the Identity Matrix as the top matrix of the stack GL_PROJECTION
    glLoadIdentity();
    // changes back the pointer to the GL_MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    // and set's the top matrix of that stack to be the Identity Matrix
    glLoadIdentity();
    // define Ortho2d projection
    gluOrtho2D(xmin, xmax, ymin, ymax);
};

//  ----------------------------------------------------------- onDisplay()
//  Custom display function used when "glutDisplayFunc"
//  triggers an event. This handles the drawing of the scenes
void GameManager::onDisplay(){
    logger.debug("GameManager::onDisplay()");
    // Fundamental steps
    // #1 Clear all buffers
    // #2 Draw all lines, dots and polygons
    // #3 Force drawing
    // set color to black when buffer get clean
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // actually cleans buffer (Color buffer)
    glClear((ENABLE_DEPTH) ? GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT: GL_COLOR_BUFFER_BIT);
    
    // enable depth
    if(ENABLE_DEPTH){ glEnable(GL_DEPTH_TEST); } else { glDisable(GL_DEPTH_TEST); }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(fov, aspect_ration, near_plane, far_plane)
    // Field of View (degrees). the amount of "zoom". eg: 90°-extra wide|30°-zoomed in
    // Aspect Ratio. Width/Height eg: 4/3 or 16/9
    // Near clipping plane.
    // Far clipping plane.
    gluPerspective(P_FOV, P_ASPECT_RATIO, P_NEAR, P_FAR);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(G_CAMERA_POS_X,
              G_CAMERA_POS_Y,
              G_CAMERA_POS_Z, // the position of your camera, in world space
              0.0f, 0.0f, 0.0f,  // where is the camera pointing to
              AXIS[0], AXIS[1], AXIS[2]); // which axis is the up
    
    // draw all objects
    gm.drawAll();

    // force the execution of the GL commands
    (ENABLE_DOUBLE_BUFFER) ? glutSwapBuffers() : glFlush();
    
};

//  -------------------------------------------------------------- onIdle()
//  Custom keyboard function used when "glutIdleFunc" triggers
//  an event. This runs all logic inside if glut has no events
//  to run
void GameManager::onIdle(){
    float new_time = glutGet(GLUT_ELAPSED_TIME);
    float delta_t = new_time - INTERNAL_TIME;
    gm.updateAll(delta_t);
    INTERNAL_TIME = new_time;
    glutPostRedisplay();
}

//  ---------------------------------------------------------- onKeyboard()
//  Custom keyboard function used when "glutKeyboardFunc"
//  triggers an event. This handles the keyboardPress
void GameManager::onKeyboard(unsigned char key, int x, int y){
    // change to wireframe
    if (key == 'A' || key == 'a'){
        int polygonMode;
        glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
        if (polygonMode == GL_LINE){
            logger.debug("Changin to GL_FILL (Polygons)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        } else{
            logger.debug("Changin to GL_LINE (Wireframe)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        glutPostRedisplay();
    }
    else{
        switch(key){
            case '1' : G_CAMERA_POS_X += ROTATION_SPEED;
                    logger.info("Moving +X");
                break;
            case '2' : G_CAMERA_POS_Y += ROTATION_SPEED; logger.info("Moving +Y"); break;
            case '3' : G_CAMERA_POS_Z += ROTATION_SPEED; logger.info("Moving +Z"); break;
            case '8' : G_CAMERA_POS_X -= ROTATION_SPEED; logger.info("Moving -X"); break;
            case '9' : G_CAMERA_POS_Y -= ROTATION_SPEED; logger.info("Moving -Y"); break;
            case '0' : G_CAMERA_POS_Z -= ROTATION_SPEED; logger.info("Moving -Z"); break;
            case 'X' : AXIS[0] = 1.0f; AXIS[1] = 0.0f; AXIS[2] = 0.0f; break;
            case 'Y' : AXIS[0] = 0.0f; AXIS[1] = 1.0f; AXIS[2] = 0.0f; break;
            case 'Z' : AXIS[0] = 0.0f; AXIS[1] = 0.0f; AXIS[2] = 1.0f; break;
        }
        std::cout << "Key press: "<< key << std::endl;
        glutPostRedisplay();
    }
};

//  ------------------------------------------------------- onSpecialKeys()
//  Custom keyboard function used when "glutSpecialFunc"
//  triggers an event. This handles the special keys like
//  F1, Esc, Left arrow, Right Arrow...
void GameManager::onSpecialKeys(int key, int x, int y){
    gm.keyPress(key);
}

//  ----------------------------------------------------- onSpecialUpKeys()
//  Custom keyboard function used when "glutSpecialUpFunc"
//  triggers an event.
void GameManager::onSpecialKeysUp(int key, int x, int y){
    gm.keyRelease(key);
}


