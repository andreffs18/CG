//
//  project_1_entrega - Track.cpp
//
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif
//#include "Game.h"

//#include "GameObject.h"

//#include "Car.h"
//#include <iostream>
#include "Game.h"
#include "Track.h"
#include "Cheerio.h"

#define AMOUNT 1.0f  // scale on track for a factor of AMOUNT

Track::Track() : StaticObject(){
    _qtd_cheerios = 32;
    _inner_circle = 0.4;
    _outer_circle = 0.8;
};

Track::Track(int qtd_cheerios, GLdouble inner_circle, GLdouble outer_circle) : StaticObject(){
    _qtd_cheerios = qtd_cheerios;
    _inner_circle = inner_circle;
    _outer_circle = outer_circle;
};

Track::~Track(){};

void Track::drawTrackModel(){
    // draw cube with 1unit as size
    // glutSolidCube(1.0f);
    glPushMatrix();
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0,-1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();
    
    glPopMatrix();
};

void Track::draw(){
    logger.debug("Track::draw()");
    
	glPushMatrix();
    // scale everything up by a factor of AMOUNT
    glScalef(AMOUNT, AMOUNT, 1.0f);
    // track is just a solid cube
    drawTrackModel();
    // angle start position
    GLdouble angle = 0.0f;
    Cheerio c = Cheerio();
    for(int i = 0; angle < 360.0f; angle += 360.0f / (this->_qtd_cheerios), i++){
        // we draw the outer cheerio twice as much as the inner one
        // in a pair instance of the angle we dra both, otherwise
        // we just draw the outer cheerio
        if(i % 2 == 0){
            glPushMatrix();
            glRotatef(angle, 0.0f, 0.0f, 1.0f);
            glTranslatef(this->_inner_circle, 0.0f, 1.0f);
            c.draw();
            glPopMatrix();
        }
        glPushMatrix();
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glTranslatef(this->_outer_circle, 0.0f, 1.0f);
        c.draw();
        glPopMatrix();
    }
    glPopMatrix();
};

