
#include "Butter.h"

Butter::Butter() {};
Butter::~Butter() {};

void Butter::draw() {
	logger.debug("On Butter::draw()");
	GameObject go = GameObject();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.3f, 0.1, 0.1);
	glutSolidCube(4);
	glPopMatrix();


	if (ENABLE_AXIS) go.axis();
};