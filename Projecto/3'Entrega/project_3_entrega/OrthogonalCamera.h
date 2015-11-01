//
//  project_2_entrega - OrthogonalCamera.h
//
#ifndef OrthogonalCamera_h
#define OrthogonalCamera_h

#include "Camera.h"

class OrthogonalCamera : public Camera{
private:
    double _left;
    double _right;
    double _bottom;
    double _top;
    
public:
    OrthogonalCamera(double in_left, double in_right, double in_bottom, double in_top, double in_near, double in_far);
    ~OrthogonalCamera(void);
    
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
    
};


#endif /* OrthogonalCamera_h */
