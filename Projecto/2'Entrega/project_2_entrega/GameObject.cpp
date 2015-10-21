//
//  project_1_entrega - GameObject.cpp
//
#include <complex.h>
#include <math.h>
#include "GameObject.h"

GameObject::GameObject(){
    // Global vars that all objects have access
    _position = new Vector3(0.0, 0.0, 0.0);
    // defines radius of the colision sphere
    _radius = 0.0f;
    _rotation = 0.0f;

};
GameObject::~GameObject(){};

void GameObject::draw(){};
void GameObject::update(float){};


Vector3 * GameObject::getPosition(){ return _position; };
void GameObject::setPosition(Vector3 * pos){ _position->setVector3(pos); };

GLdouble GameObject::getRadius(){ return _radius; }
void GameObject::setRadius(GLdouble radius){ _radius = radius; };

GLdouble GameObject::getRotation(){ return _rotation; }
void GameObject::setRotation(GLdouble rot){ _rotation = rot; };

bool GameObject::collidesWith(GameObject * obj){
    GLdouble dx = getPosition()->getX() - obj->getPosition()->getX();
    GLdouble dy = getPosition()->getY() - obj->getPosition()->getY();
    GLdouble r2 = getRadius() + obj->getRadius();
    return pow(r2, 2.0) > pow(dx, 2.0) + pow(dy, 2.0);
}
