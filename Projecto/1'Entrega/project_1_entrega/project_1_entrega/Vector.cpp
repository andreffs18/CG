//
//  Vector.cpp
//  project_1_entrega
//
//  Created by Ana Isabel Galvão on 10/10/15.
//
//
#include <iostream>
#include <stdlib.h>
#include "Vector.h"

Vector3::Vector3(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

double Vector3::getX() {
    return _x;
}

double Vector3::getY() {
    return _y;
}

double Vector3::getZ() {
    return _z;
}

void Vector3::setVector3(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

Vector3 Vector3::operator=(const Vector3 &vec) {
    _x = vec._x;
    _y = vec._y;
    _z = vec._z;
    return * this;
}


// vector mul operator
Vector3 Vector3::operator*(double num) {
    double newX = _x*num;
    double newY = _y*num;
    double newZ = _z*num;
    
    return Vector3(newX, newY, newZ);
    
}
// vector sum operator
Vector3 Vector3::operator+(const Vector3& other) {
    double sumX = getVectorX() + other._x;
    double sumY = getVectorY()+ other._y;
    double sumZ = getVectorZ() + other._z;
    
    Vector3 sumVector(sumX, sumY, sumZ);
    
    return sumVector;
}

// vector subtraction operator
Vector3 Vector3::operator-(const Vector3& other) {
    double subX = getVectorX() - other._x;
    double subY = getVectorY() - other._y;
    double subZ = getVectorZ() - other._z;
    
    return Vector3(subX, subY, subZ);
}





