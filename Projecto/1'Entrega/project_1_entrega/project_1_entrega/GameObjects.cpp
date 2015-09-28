//
//  project_1_entrega - GameObjects.cpp
//

#include "GameObjects.h"
#include <GLUT/glut.h>

GameObjects::GameObjects(){};
GameObjects::~GameObjects(){};

void GameObjects::customSolidCube(){
    glColor3f(0.5f, 0.35f, 0.05f);
    
    // draw cube with 1unit as size
    // glutSolidCube(1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glEnd();
    
    // FRONT
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(-0.500000, -0.500000, -0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-0.500000, -0.500000,-0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, -0.500000);
    glEnd();
    
    

};
void GameObjects::customRedRectangle(){
    // start drawing green polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();
};
void GameObjects::customGreenRectangle(){
    // start drawing red polygon
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
};
void GameObjects::customWhiteSquare(){
    // delimit the vertices of a primitive or a group of like primitives
    glBegin(GL_POLYGON);
    // define white square
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
};