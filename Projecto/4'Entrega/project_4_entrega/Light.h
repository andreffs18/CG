//
//  project_3_entrega - Light.h
//
#ifndef Light_h
#define Light_h

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif

#include <stdio.h>
#include <complex>

class Light{
private:
    GLfloat specular[4];
    GLfloat diffuse[4];
    GLfloat ambient[4];
    
    GLfloat directional_position[4];
    GLfloat spot_position[4];
    
    void _enable_lights();
    void _disable_lights();
    
public:
    Light();
    ~Light();
    
    void init();

	void update_headlights();
    
    bool areCandlesOn();
    
    void turnCandlesOn();
    void turnCandlesOff();

	void turnHeadlightOn();
	void turnHeadlightOff();
    
    void turnOn();
    void turnOff();
    
};
#endif /* Light_h */
