//
//  project_1_entrega - GameManager.cpp
//
#ifndef project_1_entrega_Logger_h
#include "Logger.h"
#endif

#include "GameManager.h"
#include "GameObjects.h"
#include <GLUT/glut.h>
#include <iostream>
#include "Cheerios.h"
#include "Track.h"

// initialize log object
Log logger = Log();

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
    
    
    
    
    float xmin = -2.0, xmax = 2.0, ymin = -2.0, ymax = 2.0;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float)w / h;
    if (aspect > ratio)
        glViewport((w - h*ratio) / 2, 0, h*ratio, h);
    else
        glViewport(0, (h - w / ratio) / 2, w, w / ratio);
    
    gluOrtho2D(xmin, xmax, ymin, ymax);
    
    
    
    // This call here defines the volume of the projection
    // args: left, right, bottom, top, nearVal, farVal;
    //glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
    // Fixing resizing of the window

    // TESTING
    // apply translate to change camera's position
    glTranslatef(0.0f, 0.0f, 0.0f);
    // apply rotations
  //  glRotatef(180, 1, 0, 0);
   // glRotatef(20, 0, 1, 0);
  //  glRotatef(20, 0, 0, 1);
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
    glClear(GL_COLOR_BUFFER_BIT);
    
    // draw objects
    GameObjects objs = GameObjects();
    objs.customSolidCube();
    
    Track t = Track();
    t.draw();
    
    glMatrixMode (GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet (GLUT_WINDOW_WIDTH);
    int h = glutGet (GLUT_WINDOW_HEIGHT);
    gluPerspective (40, w / h, 0.1, 100);
    
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
    glRotatef(145.0, 0.0, 1.0, 0.0);
    
    
    glutSwapBuffers();

    
    
    // force the execution of the GL commands
    glFlush();
};
