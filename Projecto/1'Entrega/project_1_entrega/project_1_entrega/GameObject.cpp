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


Vector3 * getPosition(){
    return _position;
};

void setPosition(const Vector3& pos){
    _position = pos;
};