//
//  project_1_entrega - DynamicObject.h
//

#ifndef __DYNAMICOBJECT_H_INCLUDED__
#define __DYNAMICOBJECT_H_INCLUDED__
#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject{
protected:
    Vector3 _speed;
public:
    DynamicObject();
    ~DynamicObject();
    
    void draw();
    void update(float);
    
    void setSpeed(const Vector3& other);
    Vector3 * getSpeed();
    
    void keyPress(int);
    void keyRelease(int);    
};

#endif /* defined(__DYNAMICOBJECT_H_INCLUDED__) */
