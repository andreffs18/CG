//
//  Track.cpp
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//
#include "Game.h"
#include "Track.h"
#include "GameObjects.h"
#include "Cheerio.h"
#include <iostream>
#include <GLUT/GLUT.h>

Track::Track(){};
Track::~Track(){};

void Track::draw(){
    logger.debug("Track::draw()");
    GameObjects go = GameObjects();
    
    glPushMatrix();
    glScalef(5.5, 5.5, 1.5f);
    go.customSolidCube();
    if(ENABLE_AXIS) go.axis((GLdouble)10.f);
    
    //texture table - just playing
  /*  GLuint tex;

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    OIL_load_image("img.png", &width, &height, 0, SOIL_LOAD_RGB);
    
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, image); */
    
    
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
	while (pos_y > 0.8
		) {
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
