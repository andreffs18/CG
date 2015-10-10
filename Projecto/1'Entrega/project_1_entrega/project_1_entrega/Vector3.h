#ifndef __project_1_entrega__Vector__
#define __project_1_entrega__Vector__

#include <stdio.h>
class Vector3d {
    
private:
    double _x;
    double _y;
    double _z;

public:
    Vector3d(double x, double y, double z);
    ~Vector3d();
    
    double getX();
    double getY();
    double getZ();
    void setVector3d(double x, double y, double z);
    
    Vector3d operator=(const Vector3d& other);
    Vector3d operator*(double num);
    Vector3d operator+(const Vector3d& other);
    Vector3d operator-(const Vector3d& other);

};

#endif /* Vector3d_h */
