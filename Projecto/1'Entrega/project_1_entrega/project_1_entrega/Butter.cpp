#include "Game.h"
#include "Butter.h"

Butter::Butter() : StaticObject() {};
Butter::~Butter() {};

void Butter::draw() {
	logger.debug("On Butter::draw()");
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
    glScalef(0.3f, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
};