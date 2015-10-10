//
//  project_1_entrega - Orange.cpp
//
#include "Orange.h"


Orange::Orange(){};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");
	GameObject go = GameObject();

	glPushMatrix();
    glTranslatef(0.0f, 0.0f, 3.0f);
	glColor3f(1.0, 0.4, 0.0);
	glScalef(0.025, 0.025, 0.025);
		glPushMatrix();
		glutSolidSphere(5.0, 15.0, 10.0);
		glPopMatrix();
	if (ENABLE_AXIS) go.axis();
	glPopMatrix();
};