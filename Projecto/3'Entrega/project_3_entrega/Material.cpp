

#include "Material.h"


Material::Material(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat shine){
    _ambientMaterial = ambient;
    _diffuseMaterial = diffuse;
    _specularMaterial = specular;
    _shine = shine;
    
}

Material::~Material(){};


