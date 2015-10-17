//
//  project_1_entrega - GameObject.cpp
//

#include "GameObject.h"

GameObject::GameObject(){
    // Global vars that all objects have access
    _position = new Vector3(0.0, 0.0, 0.0);
    _width = 0.0f;
    _height = 0.0f;

};
GameObject::~GameObject(){};

void GameObject::draw(){};
void GameObject::update(float){};


Vector3 * GameObject::getPosition(){
    return _position;
};

void GameObject::setPosition(Vector3 * pos){
    _position->setVector3(pos);
};

bool GameObject::collidesWith(GameObject * obj){
    return getXMax() > obj->getXMin() &&
           getXMin() < obj->getXMax() &&
           getYMax() > obj->getYMin() &&
           getYMin() < obj->getYMax();
}

GLdouble GameObject::getXMax(){ return _position->getX() + _width/2; }

GLdouble GameObject::getXMin(){ return _position->getX() - _width/2; }

GLdouble GameObject::getYMax(){ return _position->getY() + _height/2; }

GLdouble GameObject::getYMin(){ return _position->getY() - _height/2; }
