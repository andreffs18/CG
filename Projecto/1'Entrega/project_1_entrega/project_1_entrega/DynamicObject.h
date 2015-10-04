//
//  DynamicObject.h
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#ifndef __project_1_entrega__DynamicObject__
#define __project_1_entrega__DynamicObject__

#include "GameObject.h"
#include <stdio.h>

class DynamicObject: public GameObject{
private:
    float _pos_x, _pos_y, _pos_z;
    float _speed_x, _speed_y, _speed_z;
public:
    DynamicObject();
    ~DynamicObject();
    void setSpeed(float x, float y, float z);
    float getSpeed();
};

#endif /* defined(__project_1_entrega__DynamicObject__) */
