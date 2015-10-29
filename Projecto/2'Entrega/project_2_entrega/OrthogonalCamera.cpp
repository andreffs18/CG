//
//  project_2_entrega - OrthogonalCamera.cpp
//
//
#include "OrthogonalCamera.h"
#include "Camera.h"


OrthogonalCamera::OrthogonalCamera(double in_left, double in_right, double in_bottom, double in_top, double in_near, double in_far) : Camera(in_near, in_far){
    
    _left = in_left;
    _right = in_right;
    _bottom = in_bottom;
    _top = in_top;
}


OrthogonalCamera::~OrthogonalCamera(void){
}

void OrthogonalCamera::update() {
    computeProjectionMatrix();
    computeVisualizationMatrix();
}

void OrthogonalCamera::computeProjectionMatrix() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float ratio = (_right - _left) / (_top - _bottom);

    if (ratio < _aspect){
        float delta = ((_top - _bottom) * _aspect - (_right - _left)) / 2;
        glOrtho(_left - delta, _right + delta, _bottom, _top, _near, _far);
    }
    else {
        float delta = ((_right - _left) / _aspect - (_top - _bottom)) / 2;
        glOrtho(_left, _right, _bottom - delta, _top + delta, _near, _far);
    }
}

void OrthogonalCamera::computeVisualizationMatrix() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
