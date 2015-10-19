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
//    
//    glPushMatrix();
//    glColor3f(0.0f, 0.0f, 0.02f);
//    glTranslatef(1.0f, 1.0f, 1.0f);
//    glScalef(0.1f, 0.1f, 1.0f);
//    glutSolidCube(1.0f);
//    glPopMatrix();
//    
    glPopMatrix();
    
};
void Orange::update(float delta){
    
    GLdouble new_pos_x = _position->getX() + delta * _speed->getX();
    GLdouble new_pos_y = _position->getY() + delta * _speed->getY();
    GLdouble new_pos_z = _position->getZ();
    
    
    _position = new Vector3(new_pos_x, new_pos_y, new_pos_z);
    
};