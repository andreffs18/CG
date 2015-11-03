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
    GLfloat * _ambient;
    GLfloat * _diffuse;
    GLfloat * _specular;
    GLfloat _shine;
    
    public:
        Material(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat shine);
        ~Material();
    
    void setAmbient(GLfloat ambient[4]);
    void setDiffuse(GLfloat diffuse[4]);
    void setSpecular(GLfloat specular[4]);
    //void setShine(GLfloat shine);
    
};
#endif /* Material_h */
