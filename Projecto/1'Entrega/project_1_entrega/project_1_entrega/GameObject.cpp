//
//  project_1_entrega - GameObject.cpp
//

#include "GameObject.h"

GameObject::GameObject(){
    _position = new Vector3(0.0, 0.0, 0.0);
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