//
//  project_2_entrega - PerspectiveCamera.cpp
//
//
#include "PerspectiveCamera.h"
#include "Camera.h"

PerspectiveCamera::PerspectiveCamera(GLdouble fov, GLdouble near, GLdouble far) : Camera(near, far) {
    _fovy = fov;
};

PerspectiveCamera::~PerspectiveCamera(){}

void PerspectiveCamera::update() {
    computeProjectionMatrix();
    computeVisualizationMatrix();
};

void PerspectiveCamera::computeProjectionMatrix() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(_fovy, _aspect, _near, _far);
    gluLookAt(_pos->getX(), _pos->getY(), _pos->getZ(),
              _at->getX(), _at->getY(), _at->getZ(),
              _up->getX(), _up->getY(), _up->getZ());
};