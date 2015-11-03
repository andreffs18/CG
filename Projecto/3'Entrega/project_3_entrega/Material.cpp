//
//  Material.cpp
//  project_3_entrega
//
//  Created by Ana Isabel Galvão on 03/11/15.
//
//

#include "Material.h"
#include "Game.h"

Material::Material(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat shine){

}

Material::~Material(){};

void Material::setAmbient(GLfloat ambient[4]){_ambient = ambient;}
    
void Material::setDiffuse(GLfloat diffuse[4]){ _diffuse = diffuse; };
void Material::setSpecular(GLfloat specular[4]){_specular = specular; };

//void Material::setShine(GLfloat shine){ _shine = const 1; };

