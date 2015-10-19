//
//  PerspectiveCamera.cpp
//  project_2_entrega
//

#include "PerspectiveCamera.h"
#include "Camera.h"



#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(GLdouble P_FOV, GLdouble P_NEAR, double P_FAR) : Camera(P_NEAR, P_FAR) {
    _fovy = P_FOV;
    _aspect = P_ASPECT_RATIO;
}

PerspectiveCamera::~PerspectiveCamera(void)
{
}

void PerspectiveCamera::update() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    
    float _aspect = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    //GLdouble _aspect = (float)VIEWPORT_WIDTH/(float)VIEWPORT_HEIGHT;

    
    gluPerspective(_fovy, _aspect, _near, _far);
    gluLookAt(POSCAM->getX(), POSCAM->getY(), POSCAM->getZ(), // camera pos
              POINTCAM->getX(), POINTCAM->getY(), POINTCAM->getZ(),  // where is the camera pointing to
              AXIS->getX(), AXIS->getY(), AXIS->getZ());
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void PerspectiveCamera::computeProjectionMatrix() {
    
}

void PerspectiveCamera::computeVisualizationMatrix() {
    
}



//void PerspectiveCamera::view(Camera){
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//        gluPerspective(_fovy, _aspect, _zNear, _zFar);
//        gluLookAt(POSCAM->getX(), POSCAM->getY(), POSCAM->getZ(), // camera pos
//                  POINTCAM->getX(), POINTCAM->getY(), POINTCAM->getZ(),  // where is the camera pointing to
//                  AXIS->getX(), AXIS->getY(), AXIS->getZ());
//        glutPostRedisplay();
//}

