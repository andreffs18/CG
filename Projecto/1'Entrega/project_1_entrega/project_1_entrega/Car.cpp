//
//  project_1_entrega - Car.cpp
//
#include "Game.h"
#include "Car.h"
#include "GameObjects.h"
#include <GLUT/glut.h>

Car::Car(){};
Car::~Car(){};

void Car::draw(float cube_size){
    logger.debug("Car::draw()");
    GameObjects go = GameObjects();
//    // draw front triangle
//    glPushMatrix();
//    glTranslatef(0.0f, -0.5f, 0.0f);
//    glScalef(2.0f, 0.5f, 0.0f);
//    glutSolidCube(cube_size);
//    glPopMatrix();

    if(ENABLE_AXIS) go.axis((GLdouble)10.0f);
    
    // draw back cube
   
    // draw body square
    glPushMatrix();
    glColor3d(123, 123, 123);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glRotatef(10, 0.0f, 0.0f, 1.0f);
    glScalef(2.0f, 0.5f, 1.3f);
    glutSolidCube(cube_size);
    if(ENABLE_AXIS) go.axis();
    glPopMatrix();

    // draw wheels
    glPushMatrix();
        // front wheels
        // left
        glPushMatrix();
            glColor3d(255, 0, 255);
            glTranslatef(-2.0f, -0.5f, 1.5f);
            glutSolidTorus(0.2f, 0.5f, 100, 24);
            if(ENABLE_AXIS) go.axis();
        glPopMatrix();
        // right
        glPushMatrix();
            glColor3d(255, 0, 255);
            glTranslatef(-2.0f, -0.5f, -1.5f);
            glutSolidTorus(0.2f, 0.5f, 100, 24);
            if(ENABLE_AXIS) go.axis();
        glPopMatrix();

        // back wheels
        // left
        glPushMatrix();
            glColor3d(0, 255, 0);
            glTranslatef(2.5f, 0.4f, 2.7f);
            glutSolidTorus(0.5f, 1.2f, 200, 24);
            if(ENABLE_AXIS) go.axis();
        glPopMatrix();
        // right
        glPushMatrix();
            glColor3d(0, 255, 0);
            glTranslatef(2.5f, 0.4f, -2.7f);
            glutSolidTorus(0.5f, 1.2f, 200, 24);
            if(ENABLE_AXIS) go.axis();
        glPopMatrix();
    glPopMatrix();
    
    
    // draw back cube
    glPushMatrix();
    glColor3d(255, 255, 0);
    glTranslatef(3.0f, 2.0f, 0.0f);
    glScalef(2.0f, 2.0f, 2.0f);
    go.customSolidCube();
    if(ENABLE_AXIS) go.axis();
    // glutSolidCube(cube_size);
    glPopMatrix();    
   
    
};


