//
//  project_1_entrega - StaticObject.h
//
#ifndef __STATICOBJECT_H_INCLUDED__
#define __STATICOBJECT_H_INCLUDED__
#include "GameObject.h"

class StaticObject : public GameObject{
protected:
public:
    StaticObject();
    ~StaticObject();
    
    void draw();
};

#endif /* defined(__STATICOBJECT_H_INCLUDED__) */