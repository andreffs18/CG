#include "Game.h"
#include "Butter.h"

Butter::Butter() : StaticObject() {
    _radius = 1.7f;
};
Butter::~Butter() {};

void Butter::draw() {
	logger.debug("On Butter::draw()");
	glPushMatrix();

    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
    
    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(_radius, 10, 10);
    }
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(_rotation, 0.0f, 0.0f, 1.0f);
    glScalef(1.8f, 3.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();
};