//
// project_1_entrega - Vector.cpp
//

#include <iostream>
#include <stdlib.h>
#include "Vector3.h"

/* Vector3d v1 = Vector3d(4, 3, 6);
Vector3d v2 = Vector3d(1, 2, 3);
 */

Vector3d::Vector3d(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

double Vector3d::getX() {
    return _x;
}

double Vector3d::getY() {
    return _y;
}

double Vector3d::getZ() {
    return _z;
}

void Vector3d::setVector3d(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

// equals operation
Vector3d Vector3d::operator=(const Vector3d &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return * this;
}
// mul operation
Vector3d Vector3d::operator*(double num) {
    _x = getX() * num;
    _y = getY() * num;
    _z = getZ() * num;
    return * this;
}

// sum operation
Vector3d Vector3d:: operator+(const Vector3d& other) {
    _x = getX() + other._x;
    _y = getY() + other._y;
    _z = getZ() + other._z;
    return * this;
}

// sub operation
Vector3d Vector3d::operator-(const Vector3d &other) {
    _x = getX() - other._x;
    _y = getY() - other._y;
    _z = getZ() - other._z;
    return * this;
}





