#include "Game.h"
#include "Orange.h"

Orange::Orange() : DynamicObject(){};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");

	glPushMatrix();
	glColor3f(1.0, 0.4, 0.0);
	glutSolidSphere(5.0, 15.0, 10.0);
	glPopMatrix();
};
void Orange::update(float delta){};