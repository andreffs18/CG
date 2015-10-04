//
//  project_1_entrega - Car.cpp
//
#include "Game.h"
#include "Car.h"
#include "GameObject.h"
#include <GLUT/glut.h>

Car::Car(){};
Car::~Car(){};

void Car::setPos(GLdouble x, GLdouble y, GLdouble z){
    car.pos_x = x;
    car.pos_y = y;
    car.pos_z = z;
};

void Car::setRot(GLdouble angle, GLdouble x, GLdouble y, GLdouble z){
    car.rot_angle = angle;
    car.rot_x = x;
    car.rot_y = y;
    car.rot_z = z;
};

// FAKE AS F$#%, just to test if works
GLdouble STEP = 0.5f;
void Car::move_left(){
    car.setPos(car.pos_x - STEP, car.pos_y, car.pos_z);
    // car.setRot(90.0, 0.0f, 1.0f, 0.0f);
};
void Car::move_right(){
    car.setPos(car.pos_x + STEP, car.pos_y, car.pos_z);
    // car.setRot(-90.0, 0.0f, 1.0f, 0.0f);
};
void Car::move_forward(){
    car.setPos(car.pos_x, car.pos_y + STEP, car.pos_z);
    // car.setRot(90.0, 1.0f, 0.0f, 0.0f);
};
void Car::move_backwards(){
    car.setPos(car.pos_x, car.pos_y - STEP, car.pos_z);
    //car.setRot(360.0, 1.0f, 0.0f, 0.0f);
};

void Car::update(){};

void Car::draw(){
    glTranslatef(car.pos_x, car.pos_y, car.pos_z);
    glScalef(0.1f, 0.1f, 0.1f);
    glRotatef(car.rot_angle, car.rot_x, car.rot_y, car.rot_z);
    glRotatef(-car.rot_angle, 0.0f, 1.0f, 0.0f);
    
    // the size of the tores (depth) and the
    // amount of rings (how round you want it
    GLint t_sizes = 8;
    GLint t_rings = 20;
    // size of front and back wheels (betwenn inner and outer circle)
    GLdouble t_front_inner_size = 0.1f,
             t_front_outer_size = 0.2f,
             t_back_inner_size = 0.2f,
             t_back_outer_size = 0.4f;
    
    // height from the center of the whell
    GLdouble t_front_height = t_front_inner_size * 2 + t_front_outer_size;
    GLdouble t_back_height = t_back_inner_size * 2 + t_back_outer_size;
    
    
    // position of front wheels in X, Y, Z space
    GLdouble t_front_pos_x = -2.5f,
             t_front_pos_y = t_front_height,
             t_front_pos_z = 1.25f;
    // position of back wheels in X, Y, Z space
    GLdouble t_back_pos_x = 2.5f,
             t_back_pos_y = t_back_height,
             t_back_pos_z = 1.5f;
    
    logger.debug("Car::draw()");
    GameObject go = GameObject();

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
        glTranslatef(0.0f, t_back_height, 0.0f);
        glScalef(1.0f, 0.05f, 0.5f);
        glutSolidCube(5.0f);
    glPopMatrix();
    
    // Draw spoiler
    glPushMatrix();
        // Draw top spoiler
        glTranslatef(2.5f, 1.5f, 0.0f);
        glScalef(1.0f, 0.1f, 4.0f);
        glutSolidCube(1.0f);
    
        // Draw handle for spoiler
        glColor3d(255, 0, 0);
        glTranslatef(0.0f, -2.5f, 0.0f);
        glScalef(1.0f, 5.0f, 0.1f);
        glutSolidCube(1.0f);
    glPopMatrix();

};


