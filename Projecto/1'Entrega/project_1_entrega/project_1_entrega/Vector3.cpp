//
// project_1_entrega - Vector.cpp
//
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif


#include "Vector3.h"

Vector3::Vector3(double x, double y, double z){ _x = x; _y = y; _z = z; }

Vector3::Vector3(GLdouble x, GLdouble y, GLdouble z) {
    _x = x;
    _y = y;
    _z = z;
}

double Vector3::getX() {
    return _x;
}

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





