#ifndef __project_1_entrega__Vector__
#define __project_1_entrega__Vector__

#include <stdio.h>
class Vector3 {
    
private:
    double _x;
    double _y;
    double _z;

public:
    Vector3(double x, double y, double z);
    ~Vector3();
    
    double getVectorX();
    double getVectorY();
    double getVectorZ();
    void setVector3(double x, double y, double z);
    
    Vector3 operator=(const Vector3& vec);
    Vector3 operator*(double num);
    Vector3 operator+(const Vector3& vec);
    Vector3 operator-(const Vector3& vec);

};

#endif /* Vector_h */
