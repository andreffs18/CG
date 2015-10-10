//
//  project_1_entrega - Track.cpp
//
#include "Track.h"

#define AMOUNT 1.0f  // scale on track for a factor of AMOUNT

Track::Track(){
    _qtd_cheerios = 32;
    _inner_circle = 0.4;
    _outer_circle = 0.8;
};

Track::Track(int qtd_cheerios, GLdouble inner_circle, GLdouble outer_circle){
    _qtd_cheerios = qtd_cheerios;
    _inner_circle = inner_circle;
    _outer_circle = outer_circle;
};

Track::~Track(){};

void Track::draw(){
    logger.debug("Track::draw()");
    
    GameObject go = GameObject();
    
	glPushMatrix();
    // scale everything up by a factor of AMOUNT
    glScalef(AMOUNT, AMOUNT, 1.0f);
    // track is just a solid cube
    go.customSolidCube();
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

