//
//  Light.hpp
//  project_3_entrega
//
//  Created by Ana Isabel Galvão on 03/11/15.
//
//

#ifndef Light_h
#define Light_h

#include <stdio.h>
#include "Game.h"



class Light{
protected:
    GLfloat * _ambientLight;
    GLfloat * _diffuseLight;
    GLfloat * _specularLight;
    

public:
    Light(GLfloat ambientLight[4], GLfloat diffuseLight[4], GLfloat specularLight[4]);
    Light();
    ~Light();
};
#endif /* Light_h */
