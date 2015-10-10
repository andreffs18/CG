//
// project_1_entrega - Vector.cpp
//

#include <iostream>
#include <stdlib.h>
#include "Vector3.h"

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

Vector3 Vector3::operator=(const Vector3 &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return * this;
}

Vector3 Vector3::operator*(double num) {
/*    double newX = _x*num;
    double newY = _y*num;
    double newZ = _z*num;*/
    
    _x = _x*num;
    _y = _y*num;
    _z = _z*num;
    return * this;
    //   return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator+(const Vector3 &other) {
    double sumX = getX() + other._x;
    double sumY = getY() + other._y;
    double sumZ = getZ() + other._z;
    
    Vector3 sumVector(sumX, sumY, sumZ);
    
    return sumVector;
}

Vector3 Vector3::operator-(const Vector3 &other) {
    double subX = getX() - other._x;
    double subY = getY() - other._y;
    double subZ = getZ() - other._z;
    
    return Vector3(subX, subY, subZ);
}





