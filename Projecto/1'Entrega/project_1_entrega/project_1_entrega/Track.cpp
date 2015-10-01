//
//  Track.cpp
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#include "Track.h"
#include "Cheerios.h"
#include <iostream>
#include <GLUT/GLUT.h>

Track::Track(){};
Track::~Track(){};

void Track::draw(){
    glPushMatrix();
    glScalef(1.5, 1.5, 0);
    
    //table
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
    
    
    
	//Exterior da pista
	while (pos_y < 1.7) {
		pos_y += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.8
		) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.8) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.0) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.5) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.5) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}

	pos_x = -1.0;
	pos_y = -1.2;

	//Interior da pista
	while (pos_y < 1.2) {
		pos_y += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.0) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 1.1) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.2) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -0.3) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 0.9) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.0) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.0) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
    glPopMatrix();
    std::cout << "Track::draw()" << std::endl;
};
