//
//  OrthogonalCamera.cpp
//  project_2_entrega
//

#include "OrthogonalCamera.h"

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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float ratio = (_right - _left) / (_top - _bottom);
    float aspect = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    
    if (ratio < aspect)
    {
        float delta = ((_top - _bottom) * aspect - (_right - _left)) / 2;
        glOrtho(_left - delta, _right + delta, _bottom, _top, _near, _far);
    }
    else
    {
        float delta = ((_right - _left) / aspect - (_top - _bottom)) / 2;
        glOrtho(_left, _right, _bottom - delta, _top + delta, _near, _far);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OrthogonalCamera::computeProjectionMatrix() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float ratio = (_right - _left) / (_top - _bottom);
    float aspect = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    
    if (ratio < aspect)
    {
        float delta = ((_top - _bottom) * aspect - (_right - _left)) / 2;
        glOrtho(_left - delta, _right + delta, _bottom, _top, _near, _far);
    }
    else
    {
        float delta = ((_right - _left) / aspect - (_top - _bottom)) / 2;
        glOrtho(_left, _right, _bottom - delta, _top + delta, _near, _far);
    }
}

void OrthogonalCamera::computeVisualizationMatrix() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
