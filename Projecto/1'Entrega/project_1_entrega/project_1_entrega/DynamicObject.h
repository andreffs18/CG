//
//  project_1_entrega - DynamicObject.h
//

#ifndef __DYNAMICOBJECT_H_INCLUDED__
#define __DYNAMICOBJECT_H_INCLUDED__
#include "GameObject.h"

class DynamicObject : public GameObject{
protected:
    GLdouble _speed_x, _speed_y, _speed_z;
public:
    DynamicObject();
    ~DynamicObject();
    
    void draw();
    void update(float);
    
    
    void setSpeed()
    void 
    
    void keyPress(int);
    void keyRelease(int);    
};

#endif /* defined(__DYNAMICOBJECT_H_INCLUDED__) */
