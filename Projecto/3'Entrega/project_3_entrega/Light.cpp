//
//  project_3_entrega - OrthogonalCamera.h
//

#include "Light.h"

Light::Light(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4]){
    _ambientLight = ambient;
    _diffuseLight= diffuse;
    _specularLight = specular;
    
}

//directional light
Light::Light(){
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambient[] = {0.5, 0.5, 0.5, 1.0};
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
}

Light::~Light(){};
