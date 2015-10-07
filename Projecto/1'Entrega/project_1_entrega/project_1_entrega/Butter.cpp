#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include "Game.h"
#include "Butter.h"
#include "GameObject.h"

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