//
//  project_1_entrega - DynamicObject.cpp
//
#include "DynamicObject.h"

DynamicObject::DynamicObject(){
    // Global vars that all dynamic objects have access
    // set speed of object
    setSpeed(new Vector3(0.0, 0.0, 0.0));
};
DynamicObject::~DynamicObject(){};

// generic draw and update method to all chindren implement.
void DynamicObject::draw(){};
void DynamicObject::update(float delta){};

// speed getters and setter
void DynamicObject::setSpeed(Vector3 * other){ _speed->setVector3(other); };
Vector3 * DynamicObject::getSpeed(){ return _speed; };
