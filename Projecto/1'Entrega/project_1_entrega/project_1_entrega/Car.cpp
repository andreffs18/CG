//
//  project_1_entrega - Car.cpp
//
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include "Game.h"
#include "Car.h"
#include "GameObject.h"

Car::Car(){
    // car is not moving
    _move_up = false;
    _move_down = false;
    _move_left = false;
    _move_right = false;
    // car is @ the origin of the world
    _pos_x = 0.0f;
    _pos_y = 0.0f;
    _pos_z = 0.0f;
};
Car::~Car(){};

//  ------------------------------------------------------------ keyPress()
//  handles which direction was clicked. changes the state of
//  the variable in question.
void Car::keyPress(int key){
    if(key == GLUT_KEY_UP)
        this->_move_up = true;
    if(key == GLUT_KEY_DOWN)
        this->_move_down = true;
    if(key == GLUT_KEY_LEFT)
        this->_move_left = true;
    if(key == GLUT_KEY_RIGHT)
        this->_move_right = true;
}

//  ---------------------------------------------------------- keyRelease()
//  handles which direction was released. changes the state of
//  the variable in question.
void Car::keyRelease(int key){
    if(key == GLUT_KEY_UP)
        this->_move_up = false;
    if(key == GLUT_KEY_DOWN)
        this->_move_down = false;
    if(key == GLUT_KEY_LEFT)
        this->_move_left = false;
    if(key == GLUT_KEY_RIGHT)
        this->_move_right = false;
}

//  --------------------------------------------------------- setPosition()
//  wrapper to manipulate car's position variables
void Car::setPosition(GLdouble x, GLdouble y, GLdouble z){
    this->_pos_x = x;
    this->_pos_y = y;
    this->_pos_z = z;
};

//  ---------------------------------------------------------------- update()
//  updates car's position, velocity and rotation
void Car::update(){
    logger.debug("Car::update()");
    
    GLdouble new_x = this->_pos_x;
    GLdouble new_y = this->_pos_y;
    GLdouble new_z = this->_pos_z;
    
    if(this->_move_up)
        logger.debug("UP");
    if(this->_move_down)
        logger.debug("Down");
    if(this->_move_left)
        logger.debug("Left");
    if(this->_move_right)
        logger.debug("Right");
};

//  ------------------------------------------------------------------ draw()
//  draws car in screen
void Car::draw(){
    logger.debug("Car::draw()");
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
    
    GameObject go = GameObject();
    glPushMatrix();
    
    glTranslatef(0.0f,0.0f, 3.0f);
    glTranslatef(this->_pos_x, this->_pos_y, this->_pos_z);
    glScalef(0.1f, 0.1f, 0.1f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);
    
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
    
    glPopMatrix();

};


