//
//  DynamicObject.h
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#ifndef __project_1_entrega__DynamicObject__
#define __project_1_entrega__DynamicObject__

#include <stdio.h>

class DynamicObject{
private:
    float speed;
public:
    DynamicObject();
    ~DynamicObject();
    void update();
    void setSpeed(float);
    float getSpeed();
};

#endif /* defined(__project_1_entrega__DynamicObject__) */
