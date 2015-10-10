//
//  project_1_entrega - Orange.h
//
#ifndef __ORANGE_H_INCLUDED__
#define __ORANGE_H_INCLUDED__

#include "DynamicObject.h"

class Orange : public DynamicObject{
private:
public:
    Orange();
    ~Orange();

    void draw();
    void update(float);
};

#endif /* defined(__ORANGE_H_INCLUDED__) */
