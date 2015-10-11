#ifndef __project_1_entrega__Vector__
#define __project_1_entrega__Vector__

#include <stdio.h>
class Vector3 {
    
private:
    GLdouble _x;
    GLdouble _y;
    GLdouble _z;

public:
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    ~Vector3();
    
    GLdouble getX();
    GLdouble getY();
    GLdouble getZ();
    void setVector3(GLdouble x, GLdouble y, GLdouble z);
    void setX(GLdouble x);
    void setY(GLdouble y);
    void setZ(GLdouble z);
    
    Vector3 operator=(const Vector3& other);
    Vector3 operator*(GLdouble num);
    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);

};

#endif /* Vector3_h */
