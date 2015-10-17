//
//  project_1_entrega - StaticObject.cpp
//
#include "StaticObject.h"

StaticObject::StaticObject(){
    _rotation = 0.0f;
};

StaticObject::~StaticObject(){};
void StaticObject::draw(){};

void StaticObject::setRotation(GLdouble rot){
    _rotation = rot;
};

GLdouble StaticObject::getRotation(){
    return _rotation;
};
