//
//  project_1_entrega - GameManager.cpp
//
#include <GLUT/glut.h>
#include <iostream>
#include "Game.h"
#include "GameManager.h"
#include "GameObjects.h"
#include "Cheerio.h"
#include "Track.h"
#include "Car.h"

GameManager::GameManager(){logger.debug("GameManager::GameManager()");};
GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

//  ----------------------------------------------------------- onReshape()
//  Custom reshape function used when event "glutReshapeFunc"
//  is executed. This handles the change in screen size
void GameManager::onReshape(GLsizei w, GLsizei h){
    logger.debug("GameManager::onReshape()");

    // define size of the viewport
    // args: x, y, weight, height
    // x and y are measure from the bottom left corner of the screen
    // weight and height are the actual size of the viewport
    glViewport(0, 0, w, h);
    // changes the pointer for which Matrix we want to work on. GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    // puts the Identity Matrix as the top matrix of the stack GL_PROJECTION
    glLoadIdentity();
    // changes back the pointer to the GL_MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    // and set's the top matrix of that stack to be the Identity Matrix
    glLoadIdentity();
    
    
    float xmin = -4.0, xmax = 4.0, ymin = -4.0, ymax = 4.0;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float)w / h;
    if (aspect > ratio)
        glViewport((w - h*ratio) / 2, 0, h*ratio, h);
    else
        glViewport(0, (h - w / ratio) / 2, w, w / ratio);
    
    gluOrtho2D(xmin, xmax, ymin, ymax);
    
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, 8.0f, -8.0f);
    
    // This call here defines the volume of the projection
    // args: left, right, bottom, top, nearVal, farVal;

    //glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);

    // Fixing resizing of the window

    // TESTING
    // apply translate to change camera's position
//    glTranslatef(0.0f, 0.0f, 0.0f);
//    // apply rotations
//    glRotatef(0, 1, 0, 0);
//    glRotatef(0, 0, 1, 0);
// glRotatef(0, 0, 0, 1);
    // this does all of it
    //gluLookAt(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    
};

    

//  ----------------------------------------------------------- onDisplay()
//  Custom display function used when event "glutDisplayFunc" is
//  executed. This handles the drawing of the scenes
void GameManager::onDisplay(){
    logger.debug("GameManager::onDisplay()");
    // Fundamental steps
    // #1 Clear all buffers
    // #2 Draw all lines, dots and polygons
    // #3 Force drawing
    // set color to black when buffer get clean
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // actually cleans buffer (Color buffer)
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // draw objects
    GameObjects objs = GameObjects();
    
    Track t = Track();
    t.draw();
    
    Car c = Car();
    // c.draw();

    /* O QUE E QUE ISTO FAZE*/
    /* glMatrixMode (GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet (GLUT_WINDOW_WIDTH);
    int h = glutGet (GLUT_WINDOW_HEIGHT);
    gluPerspective (60, w / h, 0.1, 100);
    
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    
    
    gluLookAt
    (
     3, 3, 3,
     0, 0, 0,
     0, 0, 1
     );
    
    //test for rotation and perspective
    glRotatef (45.0, 0.0, 0.0, 1.0);
    glRotatef(145.0, 0.0, 1.0, 0.0);*/
    
    
    if(ENABLE_ROTATION_X||ENABLE_ROTATION_Y||ENABLE_ROTATION_Z){
        if(ENABLE_ROTATION_X) glRotatef(ROTATION_POS, 1.0f, 0.0f, 0.0f);
        if(ENABLE_ROTATION_Y) glRotatef(ROTATION_POS, 0.0f, 1.0f, 0.0f);
        if(ENABLE_ROTATION_Z) glRotatef(ROTATION_POS, 0.0f, 0.0f, 1.0f);
        ROTATION_POS += (ROTATION_POS > 1.0) ? -1.0 : ROTATION_SPEED;
        glutPostRedisplay();
    }
    
    // force the execution of the GL commands
    glFlush(); // glutSwapBuffers();
};
