//
//  Cheerios.cpp
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#include "Cheerios.h"
#include <iostream>
#include <GL\glut.h>

Cheerios::Cheerios(){};
Cheerios::~Cheerios(){};
void Cheerios::draw(float pos_x, float pos_y, float pos_z){
	glColor3f(1.0f, 0.5f, 0.0f);
	glPushMatrix();
	glTranslatef(pos_x, pos_y, pos_z);
	glutSolidTorus(0.007f, 0.02f, 10.0, 100.0f);
	glPopMatrix();
    std::cout << "Cheerios::draw()" << std::endl;
};
