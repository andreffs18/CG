//
// project_1_entrega - Vector.cpp
//

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

// equals operation
Vector3 Vector3::operator=(const Vector3 &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return * this;
}
// mul operation
Vector3 Vector3::operator*(double num) {
    _x = getX() * num;
    _y = getY() * num;
    _z = getZ() * num;
    return * this;
}

// sum operation
Vector3 Vector3:: operator+(const Vector3& other) {
    _x = getX() + other._x;
    _y = getY() + other._y;
    _z = getZ() + other._z;
    return * this;
}

// sub operation
Vector3 Vector3::operator-(const Vector3 &other) {
    _x = getX() - other._x;
    _y = getY() - other._y;
    _z = getZ() - other._z;
    return * this;
}





