//
//  project_1_entrega - DynamicObject.cpp
//
#include "DynamicObject.h"

DynamicObject::DynamicObject(){
    _speed = new Vector3(0.0, 0.0, 0.0);
};
DynamicObject::~DynamicObject(){};

void DynamicObject::draw(){};
void DynamicObject::update(float delta){};

void DynamicObject::keyPress(int key){};
void DynamicObject::keyRelease(int key){};

void DynamicObject::setSpeed(Vector3 * other){
    _speed->setVector3(other);
};

Vector3 * DynamicObject::getSpeed(){
    return _speed;
};