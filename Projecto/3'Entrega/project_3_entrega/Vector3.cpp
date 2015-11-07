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


#include <iostream>
#include <stdlib.h>
#include "Vector3.h"

Vector3::Vector3(GLdouble x, GLdouble y, GLdouble z){ _x = x; _y = y; _z = z; }

void Vector3::setX(GLdouble x){ _x = x; }
void Vector3::setY(GLdouble y){ _y = y; }
void Vector3::setZ(GLdouble z){ _z = z; }

GLdouble Vector3::getX(){ return _x; }
GLdouble Vector3::getY(){ return _y; }
GLdouble Vector3::getZ(){ return _z; }

void Vector3::setVector3(Vector3 * pos) {
    _x = pos->getX();
    _y = pos->getY();
    _z = pos->getZ();
}

//Vector3 Vector3::crossProduct(Vector3 v1, Vector3 v2){
//    Vector3 cross = {
//        v1.getY() * v2.getZ() - v1.getZ() * v2.getY(),
//        v1.getZ() * v2.getX() - v1.getX() * v2.getZ(),
//        v1.getX() * v2.getY() - v1.getY() * v2.getX()
//    };
//    return cross;
//}
//
//Vector3 Vector3::getSurfaceNormal(Vector3 * v1, Vector3 * v2, Vector3 * v3){
//    Vector3 polyVector1 = {v2->getX() - v1->getX(), v2->getY() - v1->getY(), v2->getZ() - v1->getZ()};
//    Vector3 polyVector2 = {v3->getX() - v1->getX(), v3->getY() - v1->getY(), v3->getZ() - v1->getZ()};
//    
//    Vector3 cross = crossProduct(polyVector1, polyVector2);
//    
//    //normalize(cross);
//    
//    return cross;
//}

// equals operation
Vector3 Vector3::operator=(Vector3 * other) {
    _x = other->getX();
    _y = other->getY();
    _z = other->getZ();
    return * this;
}

// mul operation
Vector3 Vector3::operator*(GLdouble num) {
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
Vector3 Vector3::operator-(Vector3 * other) {
    _x = getX() - other->getX();
    _y = getY() - other->getY();
    _z = getZ() - other->getZ();
    return * this;
}