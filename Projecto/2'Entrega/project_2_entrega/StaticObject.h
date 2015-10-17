//
//  project_1_entrega - StaticObject.h
//

#ifndef __STATICOBJECT_H_INCLUDED__
#define __STATICOBJECT_H_INCLUDED__

#include "GameObject.h"

class StaticObject : public GameObject{
protected:
    GLdouble _rotation;
public:
    StaticObject();
    ~StaticObject();
    
    void draw();
    
    void setRotation(GLdouble);
    GLdouble getRotation();
};

#endif /* defined(__STATICOBJECT_H_INCLUDED__) */