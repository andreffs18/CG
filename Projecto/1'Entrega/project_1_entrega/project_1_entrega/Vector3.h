#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__

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
    void setVector3(Vector3 * pos);
    void setX(GLdouble x);
    void setY(GLdouble y);
    void setZ(GLdouble z);
    
    Vector3 operator=(Vector3 * other);
    Vector3 operator*(GLdouble num);
    Vector3 operator+(Vector3 * other);
    Vector3 operator-(Vector3 * other);

};

#endif /* __VECTOR3_H_INCLUDED__ */