//
//  Orange.cpp
//  project_1_entrega
//
//  Created by André Silva on 10/1/15.
//
//
#include "Game.h"
#include "Orange.h"
#include <GL\glut.h>
#include "GameObject.h"

Orange::Orange(){};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");
	GameObject go = GameObject();

	glPushMatrix();
	glColor3f(1.0, 0.4, 0.0);
	glScalef(0.025, 0.025, 0.025);
		glPushMatrix();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutSolidSphere(5.0, 15.0, 10.0);
		glPopMatrix();
	if (ENABLE_AXIS) go.axis();
	glPopMatrix();
};