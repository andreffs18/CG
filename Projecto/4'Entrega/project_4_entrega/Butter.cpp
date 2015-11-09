#include "Game.h"
#include "Butter.h"

Butter::Butter() : StaticObject() {
    setRadius(1.7f);
};
Butter::~Butter() {};

void Butter::draw() {
	logger.debug("On Butter::draw()");
	glPushMatrix();

    glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
    
    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(getRadius(), 10, 10);
    }
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb, diffuse, specular, &shine);
    glColor3f(1.0f, 1.0f, 0.0f);
    
    
    glRotatef(getRotation(), 0.0f, 0.0f, 1.0f);
    glScalef(1.8f, 3.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();
};