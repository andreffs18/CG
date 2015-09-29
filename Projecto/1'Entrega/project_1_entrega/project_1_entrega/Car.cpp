//
//  project_1_entrega - Car.cpp
//
#include "Game.h"
#include "Car.h"
#include <GLUT/glut.h>

Car::Car(){};
Car::~Car(){};

void Car::draw(float cube_size){
    logger.debug("Car::draw()");
//    // draw front triangle
//    glPushMatrix();
//    glTranslatef(0.0f, -0.5f, 0.0f);
//    glScalef(2.0f, 0.5f, 0.0f);
//    glutSolidCube(cube_size);
//    glPopMatrix();
//
    // draw wheels
    glPushMatrix();
    glColor3d(255, 0, 255);
    glScalef(1.0f, 1.0f, 1.0f);

    glPushMatrix();
        glTranslatef(-2.5f, 0.0f, 1.5f);
        glutSolidTorus(0.2f, 0.5f, 100, 24);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-2.5f, 0.0f, -1.5f);
        glutSolidTorus(0.2f, 0.5f, 100, 24);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.5f, 0.5f, 1.7f);
        glutSolidTorus(0.5f, 0.7f, 200, 24);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.5f, 0.5f, -1.7f);
        glutSolidTorus(0.5f, 0.7f, 200, 24);
    glPopMatrix();
    glPopMatrix();
    
//    // draw body square
//    glPushMatrix();
//    glColor3d(255, 255, 255);
//    glTranslatef(0.0f, -0.5f, 0.0f);
//    glScalef(2.0f, 0.5f, 2.0f);
//    glutSolidCube(cube_size);
//    glPopMatrix();
//    
//    // draw back cube
//    glPushMatrix();
//    glColor3d(255, 255, 0);
//    glTranslatef(2.5f, 0.0f, 0.0f);
//    // glScalef(2.0f, 2.0f, 2.0f);
//    glutSolidCube(cube_size);
//    glPopMatrix();


    
};


