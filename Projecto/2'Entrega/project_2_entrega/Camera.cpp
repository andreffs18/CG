//
//  project_2_entrega - Camera.cpp
//
#include "Game.h"
#include "Camera.h"

Camera::Camera(GLdouble near, GLdouble far){
    _aspect = (GLdouble)VIEWPORT_WIDTH / VIEWPORT_HEIGHT;
    _near = near;
    _far = far;
    
    _pos = new Vector3(0.0f, 0.0f, 0.0f);
    _at = new Vector3(0.0f, 0.0f, 0.0f);
    _up = new Vector3(0.0f, 0.0f, 0.0f);
}

Camera::~Camera(){}

void Camera::setPos(Vector3 * newpos){ _pos->setVector3(newpos); };
void Camera::setAt(Vector3 * newat){ _at->setVector3(newat); };
void Camera::setUp(Vector3 * newup){ _up->setVector3(newup); };

void Camera::update() {}
void Camera::computeProjectionMatrix() {}
void Camera::computeVisualizationMatrix() {}
