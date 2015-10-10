#pragma once
//
//  StaticObject.h
//  project_1_entrega
//
//  Created by André Silva on 10/10/15.
//
//

#ifndef __project_1_entrega__StaticObject__
#define __project_1_entrega__StaticObject__

#include "Game.h"
#include "GameObject.h"
#include <stdio.h>

class StaticObject : public GameObject{
protected:
public:
    StaticObject();
    ~StaticObject();
    
    void draw();
};

#endif /* defined(__project_1_entrega__StaticObject__) */