//
//  project_1_entrega - GameObject.cpp
//
#include <complex.h>
#include <math.h>
#include "GameObject.h"

GameObject::GameObject(){
    // Global vars that all objects have access
    // set position in x y and z == 0 in our 3d world
    _position = new Vector3(0.0f, 0.0f, 0.0f);
    // defines radius of the colision sphere
    _radius = 0.0f;
    // defines rotation of object in z axis
    _rotation = 0.0f;
};
GameObject::~GameObject(){};

// generic draw and update method to all chindren implement.
void GameObject::draw(){};
void GameObject::update(float){};

// position getter and setter
Vector3 * GameObject::getPosition(){ return _position; };
void GameObject::setPosition(Vector3 * pos){ _position->setVector3(pos); };

// radius getter and setter
GLdouble GameObject::getRadius(){ return _radius; }
void GameObject::setRadius(GLdouble radius){ _radius = radius; };

// rotation getter and setter
GLdouble GameObject::getRotation(){ return _rotation; }
void GameObject::setRotation(GLdouble rot){ _rotation = rot; };

// colision method to handle collision for all objects.
bool GameObject::collidesWith(GameObject * obj){
    GLdouble dx = getPosition()->getX() - obj->getPosition()->getX();
    GLdouble dy = getPosition()->getY() - obj->getPosition()->getY();
    GLdouble r2 = getRadius() + obj->getRadius();
    return pow(r2, 2.0) > pow(dx, 2.0) + pow(dy, 2.0);
}
