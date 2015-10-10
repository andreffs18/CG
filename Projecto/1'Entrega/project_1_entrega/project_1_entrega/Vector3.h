#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__

class Vector3 {
private:
    double _x;
    double _y;
    double _z;

public:
    Vector3(double x, double y, double z);
    ~Vector3();
    
    double getX();
    double getY();
    double getZ();
    void setVector3(double x, double y, double z);
    
    Vector3 operator=(const Vector3& other);
    Vector3 operator*(double num);
    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);

};

#endif /* __VECTOR3_H_INCLUDED__ */