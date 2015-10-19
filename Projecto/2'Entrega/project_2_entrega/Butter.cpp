#include "Game.h"
#include "Butter.h"

Butter::Butter() : StaticObject() {
    _width = 0.2;
    _height = 0.2;
};
Butter::~Butter() {};

void Butter::draw() {
	logger.debug("On Butter::draw()");
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
    glRotatef(_rotation, 0.0f, 0.0f, 1.0f);
    glScalef(0.3f, 0.1, 0.1);
	glutSolidCube(1);
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glutWireCube(1.5f);
	glPopMatrix();
};