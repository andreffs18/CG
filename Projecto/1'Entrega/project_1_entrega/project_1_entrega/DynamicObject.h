#pragma once
//
//  DynamicObject.h
//  project_1_entrega
//
//  Created by André Silva on 10/10/15.
//
//

#ifndef __project_1_entrega__DynamicObject__
#define __project_1_entrega__DynamicObject__


#include "Game.h"
#include "GameObject.h"
#include <stdio.h>

class DynamicObject : public GameObject{
protected:
public:
    DynamicObject();
    ~DynamicObject();
    
    void draw();
    void update(float);
    
    void keyPress(int);
    void keyRelease(int);    
};

#endif /* defined(__project_1_entrega__DynamicObject__) */
