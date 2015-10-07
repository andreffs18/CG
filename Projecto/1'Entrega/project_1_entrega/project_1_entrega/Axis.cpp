//
//  Axis.cpp
//  project_1_entrega
//
//  Created by André Silva on 9/30/15.
//
//
#include "Game.h"
#include "Car.h"
#include "Axis.h"
#include "GameObject.h"
#include <GL\glut.h>


Axis::Axis(){};
Axis::~Axis(){};

void Axis::draw(){
    int size = 1.5;
    glPushMatrix();
    glBegin(GL_LINES);
    // draw line for x axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0 * size, 0.0, 0.0);
    // draw line for y axis
    glColor3f(0.0, 1.0 , 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0 * size, 0.0);
    // draw line for Z axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0 * size);
    glEnd();
    // load the previous matrix
    glPopMatrix();
}