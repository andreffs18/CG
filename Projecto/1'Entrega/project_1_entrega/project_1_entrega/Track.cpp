//
//  project_1_entrega - Track.cpp
//
#include "Game.h"
#include "Track.h"
#include "Cheerio.h"
#include "Butter.h"
#include "Orange.h"
#include <ctime>

Track::Track() : StaticObject(){
    _qtd_cheerios = 32;
    _inner_circle = 0.4;
    _outer_circle = 0.8;
    _qtd_butters = 4;
	_qtd_oranges = 3;
    
    __init__();
};

Track::Track(int qtd_cheerios, int qtd_butters, int qtd_oranges, GLdouble inner_circle, GLdouble outer_circle) : StaticObject(){
    _qtd_butters = qtd_butters;
    _qtd_cheerios = qtd_cheerios;
	_qtd_oranges = qtd_oranges;
    _inner_circle = inner_circle;
    _outer_circle = outer_circle;
    
    __init__();
};

void Track::__init__(){
    // init track
    // init random positions for butter
    // init random
    time_t t;
    srand((unsigned) time(&t));
    // set each butter in diferent quadrants
    // init diferent quadrands
    // eg: for the first 4 butters, the <x|y>_quad_mult sould be
    GLdouble x_quad_pos[4] = {1, 1, -1, -1};
    GLdouble y_quad_pos[4] = {1, -1, 1, -1};
    for(int i = 0; i < _qtd_butters; i++){
        // #TODO improve this to put more butters in the game.
        GLdouble pos_x = (rand() % 95)/100.0 * x_quad_pos[i];
        GLdouble pos_y = (rand() % 95)/100.0 * y_quad_pos[i];
        
        _random_butter_pos_x.push_back(pos_x);
        _random_butter_pos_y.push_back(pos_y);
        _random_butter_angle.push_back((rand() % 360));
    }
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

void Track::drawCheerios(){
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
};

void Track::drawButters(){
    // we want to draw a "_qtd_butters" amount butters in random places
    // so for that
    Butter b = Butter();

    for(int i = 0; i < _qtd_butters; i++){
        glPushMatrix();
        glTranslatef(_random_butter_pos_x[i], _random_butter_pos_y[i], 1.0f);
        std::cout << "angle: " << _random_butter_angle[i] << std::endl;
        glRotated(_random_butter_angle[i], 0.0f, 0.0f, 1.0f);
        b.draw();
        glPopMatrix();
        
    }
};

void Track::drawOranges() {
	
	Orange o = Orange();

	if (_set_position) {
		Vector3 * pos_st = new Vector3(0.1, 0.6, 1.125);
		Vector3 * pos_nd = new Vector3(-0.7, -0.6, 1.125);
		Vector3 * pos_rd = new Vector3(0.8, 0.2, 1.125);
		_orange_pos.push_back(pos_st);
		_orange_pos.push_back(pos_nd);
		_orange_pos.push_back(pos_rd);
		_set_position = false;
	}

	for (int i = 0; i < _qtd_oranges; i++) {
		glPushMatrix();
		glTranslatef(_orange_pos[i]->getX(), _orange_pos[i]->getY(), _orange_pos[i]->getZ());
		glScalef(0.025, 0.025, 0.025);
		o.draw();
		glPopMatrix();
	}
}

void Track::draw(){
    logger.debug("Track::draw()");
    
	glPushMatrix();
    // scale everything up by a factor of AMOUNT
    glScalef(AMOUNT, AMOUNT, 1.0f);
    // track is just a solid cube
    drawTrackModel();
    drawCheerios();
	drawOranges();
	drawButters();
    glPopMatrix();
};

