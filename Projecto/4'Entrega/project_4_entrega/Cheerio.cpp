//
//  project_1_entrega - Cheerio.cpp
//
#include "Game.h"
#include "Cheerio.h"

Cheerio::Cheerio() : StaticObject(){
    setRadius(0.6f);
};

Cheerio::~Cheerio(){};
void Cheerio::draw(){
    glPushMatrix();
    glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
    glScalef(0.8f, 0.8f, 0.8f);
    
    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(getRadius(), 10, 10);
    }
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb, diffuse, specular, &shine);
    glColor3f(1.0f, 0.5f, 0.0f);
    
    glutSolidTorus(.2f, 0.4f, 10.0, 100.0f);
    glPopMatrix();
};

bool Cheerio::isInnerCheerio(){
    GLdouble cheerio_pos_x = fabs(getPosition()->getX());
    GLdouble cheerio_pos_y = fabs(getPosition()->getY());
    
    return cheerio_pos_x <= (3*gm.INNER_CIRCLE_RADIUS/2) && cheerio_pos_y <= (3*gm.INNER_CIRCLE_RADIUS/2);
};

bool Cheerio::isOuterCheerio(){
    GLdouble cheerio_pos_x = fabs(getPosition()->getX());
    GLdouble cheerio_pos_y = fabs(getPosition()->getY());
    
    return cheerio_pos_x > (3*gm.INNER_CIRCLE_RADIUS/2) || cheerio_pos_y > (3*gm.INNER_CIRCLE_RADIUS/2);
};
