//
//  project_1_entrega - Cheerio.cpp
//
#include "Cheerio.h"

Cheerio::Cheerio(){};
Cheerio::~Cheerio(){};
void Cheerio::draw(){
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glutSolidTorus(0.007f, 0.02f, 10.0, 100.0f);
    glPopMatrix();
};
