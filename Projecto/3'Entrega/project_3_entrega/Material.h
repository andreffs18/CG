//
//  Material.hpp
//  project_3_entrega
//
//  Created by Ana Isabel Galvão on 03/11/15.
//
//

#ifndef Material_h
#define Material_h

#include <stdio.h>
#include "Game.h"


class Material{
protected:
    
    GLfloat * _ambientMaterial;
    GLfloat * _diffuseMaterial;
    GLfloat * _specularMaterial;
    GLfloat _shine;
    
    
    public:
        Material(GLfloat ambientMaterial[4], GLfloat diffuseMaterial[4], GLfloat specularMaterial[4], GLfloat shine);
        ~Material();
};
#endif /* Material_h */
