//
//  Camera.cpp
//  project_2_entrega
//
//  Created by Ana Isabel Galvão on 12/10/15.
//
//

#include "Camera.h"


Camera::Camera(double near, double far)
{
    _near = near;
    _far = far;
}


Camera::~Camera()
{
}

void Camera::setAt(double x, double y, double z) {
    if (_at == NULL) {
        _at = new Vector3(x, y, z);
    }
    else {
        _at->setVector3(_at);
    }
}

void Camera::update() {}
void Camera::computeProjectionMatrix() {}
void Camera::computeVisualizationMatrix() {}
