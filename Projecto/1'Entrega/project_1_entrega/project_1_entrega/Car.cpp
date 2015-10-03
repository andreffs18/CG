//
//  project_1_entrega - Car.cpp
//
#include "Game.h"
#include "Car.h"
#include "GameObjects.h"
#include <GLUT/glut.h>

Car::Car(){};
Car::~Car(){};

void Car::draw(){
    
    
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    
    // the size of the tores (depth) and the
    // amount of rings (how round you want it
    GLint t_sizes = 8;
    GLint t_rings = 20;
    // size of front and back wheels (betwenn inner and outer circle)
    GLdouble t_front_inner_size = 0.2f,
             t_front_outer_size = 0.4f,
             t_back_inner_size = 0.4f,
             t_back_outer_size = 0.8f;
    
    // position of front wheels in X, Y, Z space
    GLdouble t_front_pos_x = -2.5f,
             t_front_pos_y = t_front_outer_size,
             t_front_pos_z = 1.0f;
    // position of back wheels in X, Y, Z space
    GLdouble t_back_pos_x = 2.5f,
             t_back_pos_y = t_back_outer_size + 0.2f,// don't know why.
             t_back_pos_z = 1.2f;
    
    logger.debug("Car::draw()");
    GameObjects go = GameObjects();

    // Draw Car
    if(ENABLE_AXIS){glPushMatrix(); go.axis(); glPopMatrix();}
    
    // draw wheels
    glPushMatrix();
    glColor3d(255, 255, 255);
        // front left
        glPushMatrix();
        glTranslatef(t_front_pos_x, t_front_pos_y, t_front_pos_z);
        glutSolidTorus(t_front_inner_size, t_front_outer_size, t_sizes, t_rings);
        glPopMatrix();
        // front right
        glPushMatrix();
        glTranslatef(t_front_pos_x, t_front_pos_y, t_front_pos_z * (-1));
        glutSolidTorus(t_front_inner_size, t_front_outer_size, t_sizes, t_rings);
        glPopMatrix();
    glColor3d(0, 255, 255);
        // back left
        glPushMatrix();
        glTranslatef(t_back_pos_x, t_back_pos_y, t_back_pos_z);
        glutSolidTorus(t_back_inner_size, t_back_outer_size, t_sizes, t_rings);
        glPopMatrix();
        // back right
        glPushMatrix();
        glTranslatef(t_back_pos_x, t_back_pos_y, t_back_pos_z * (-1));
        glutSolidTorus(t_back_inner_size, t_back_outer_size, t_sizes, t_rings);
        glPopMatrix();
    glPopMatrix();
    
    // draw body
    glPushMatrix();
        glColor3d(0, 0, 255);
        glRotatef(5, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.0f, 0.8f, 0.0f);
        glScalef(3.0f, 0.4f, 0.8f);
        glutSolidCube(2.0f);
    glPopMatrix();
    
    // Draw spoiler
    glPushMatrix();
        // Draw top spoiler
        glTranslatef(2.5f, 2.5f, 0.0f);
        glScalef(1.0f, 0.1f, 4.0f);
        glutSolidCube(1);
    
        // Draw handle for spoiler
        glColor3d(255, 0, 0);
        glTranslatef(0.0f, -4.5f, 0.0f);
        glScalef(1.0f, 12.0f, 0.025f);
        glutSolidCube(1);
    glPopMatrix();

};


