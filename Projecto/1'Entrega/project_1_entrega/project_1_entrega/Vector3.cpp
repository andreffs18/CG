//
// project_1_entrega - Vector.cpp
//

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z){ _x = x; _y = y; _z = z; }

void Vector3::setX(double x){ _x = x; }
void Vector3::setY(double y){ _y = y; }
void Vector3::setZ(double z){ _z = z; }

double Vector3::getX(){ return _x; }
double Vector3::getY(){ return _y; }
double Vector3::getZ(){ return _z; }

void Vector3::setVector3(Vector3 * pos) {
    _x = pos->getX();
    _y = pos->getY();
    _z = pos->getZ();
}


// equals operation
Vector3 Vector3::operator=(Vector3 * other) {
    _x = other->getX();
    _y = other->getY();
    _z = other->getZ();
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
Vector3 Vector3:: operator+(Vector3 * other) {
    _x = getX() + other->getX();
    _y = getY() + other->getY();
    _z = getZ() + other->getZ();
    return * this;
}

// sub operation
Vector3 Vector3::operator-(Vector3  * other) {
    _x = getX() - other->getX();
    _y = getY() - other->getY();
    _z = getZ() - other->getZ();
    return * this;
}





