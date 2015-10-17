#include "Game.h"
#include "Orange.h"

Orange::Orange() : DynamicObject(){
    _width = 0.2f;
    _height = 0.2f;
};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");
	glPushMatrix();
	glColor3f(1.0, 0.4, 0.0);
    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
    glScalef(0.1f, 0.1f, 0.1f);
    glutSolidSphere(1.0, 16.0, 16.0);
    // glColor3f(1.0f, 1.0f, 1.0f);
    // glutWireCube(1.5f);
    glPopMatrix();
    
};
void Orange::update(float delta){};