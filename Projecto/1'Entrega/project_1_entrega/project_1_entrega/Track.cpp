//
//  project_1_entrega - Track.cpp
//
#include "Game.h"
#include "Track.h"
#include "GameObject.h"
#include "Cheerio.h"
#include "Car.h"
#include <iostream>
#include <GL\glut.h>

Track::Track(){};
Track::~Track(){};

void Track::draw(){
    logger.debug("Track::draw()");
    GameObject go = GameObject();
    
	glPushMatrix();
	glScalef(5.5, 5.5, 1.5f);
    go.customSolidCube();
    if(ENABLE_AXIS) go.axis((GLdouble)10.f);
    
    glTranslatef(0.0, 0.0, 1.0);
	//Exterior da pista
	while (pos_y < 1.7) {
		pos_y += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.8) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.8) {
		pos_x -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.0) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.5) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.5) {
		pos_x -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}

	pos_x = -1.0;
	pos_y = -1.2;

	//Interior da pista
	while (pos_y < 1.2) {
		pos_y += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.0) {
		pos_x += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 1.1) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.2) {
		pos_x -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -0.3) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 0.9) {
		pos_x += 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.0) {
		pos_y -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.0) {
		pos_x -= 0.2;
		Cheerio c = Cheerio();
		c.draw(pos_x, pos_y, pos_z);
	}
    glPopMatrix();
    
};

