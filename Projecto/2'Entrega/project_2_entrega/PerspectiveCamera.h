//
//  PerspectiveCamera.hpp
//  project_2_entrega
//

#ifndef __PERSPECTIVECAMERA_H_INCLUDED__
#define __PERSPECTIVECAMERA_H_INCLUDED__


#include <stdio.h>
#include "Camera.h"
#include "Car.h"
#include "GameObject.h"

class PerspectiveCamera : public Camera {
    
private:
    GLdouble _fovy;
    Vector3* _campos;
    float _aspect;
    
public:
    PerspectiveCamera(GLdouble P_FOV, GLdouble P_NEAR, GLdouble P_FAR);
    ~PerspectiveCamera(void);
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
};




#endif /* PerspectiveCamera_h */
