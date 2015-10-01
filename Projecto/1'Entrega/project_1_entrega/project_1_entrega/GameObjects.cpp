//
//  project_1_entrega - GameObjects.cpp
//

#include "GameObjects.h"
#include <GLUT/glut.h>

GameObjects::GameObjects(){};
GameObjects::~GameObjects(){};

void GameObjects::customSolidCube(){
    
    // draw cube with 1unit as size
    // glutSolidCube(1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    // FRONT
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0, -1.0,-1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
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
void GameObjects::axis(GLdouble size){
    glBegin(GL_LINES);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    glRotatef(0, 0.0f, 0.0f, 0.0f);
    
    // draw line for x axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(size, 0.0, 0.0);
    // draw line for y axis
    glColor3f(0.0, 1.0 , 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, size, 0.0);
    // draw line for Z axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, size);
    glEnd();    
    
};
