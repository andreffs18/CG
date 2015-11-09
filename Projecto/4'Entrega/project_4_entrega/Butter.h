#ifndef __BUTTER_H_INCLUDED__
#define __BUTTER_H_INCLUDED__

class Butter : public StaticObject{
private:
    GLfloat amb[4]      = {1.0f, 1.0f, 0.0f, 1.0f};
    GLfloat diffuse[4]  = {1.0f, 0.55f, 0.07568f, 1.0f};
    GLfloat specular[4] = {0.633f, 0.727811f, 0.633f, 1.0f};
    GLfloat shine       = 76.8f;
    
public:
	Butter();
	~Butter();
	void draw();
};

#endif /* defined(__BUTTER_H_INCLUDED__) */