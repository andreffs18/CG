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
#include <complex>
#include "Game.h"
#include "Car.h"
#include "GameObject.h"

#define SPEED 0.00005
#define MAX_VELOCITY 0.0030
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
    // angle that car is facing (direction)
    _dir_angle = 0.0f;
    // speed of car
    _speed_x = 0.0f;
    _speed_y = 0.0f;
    _speed_z = 0.0f;
    
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

void Car::setSpeed(GLdouble x, GLdouble y, GLdouble z){
    this->_speed_x = x;
    this->_speed_y = y;
    this->_speed_z = z;
};

//  ---------------------------------------------------------------- update()
//  updates car's position, velocity and rotation
void Car::update(float _delta){
    logger.debug("Car::update()");
    
    GLdouble new_speed_x = this->_speed_x;
    GLdouble new_speed_y = this->_speed_y;
    GLdouble new_speed_z = this->_speed_z;
    
    if(this->_move_up && this->_speed_y < MAX_VELOCITY){
        logger.debug("UP");
        new_speed_x = 0;
        new_speed_y += SPEED;
        //newp = old_p + v0*_delta + 1/2*Gravit*_delta^2
        //new_x -= new_x + this->_speed*_delta + (1/2*(GRAVIT_CONST)*_delta*_delta);
    }
    
    if(this->_move_down && this->_speed_y < MAX_VELOCITY){
        new_speed_x = 0;
        new_speed_y -= SPEED;
        logger.debug("Down");
        //new_x += new_x + this->_speed*_delta + (1/2*(GRAVIT_CONST)*_delta*_delta);
    }
    
    if(this->_move_left){
        logger.debug("Left");
        new_speed_x = -SPEED;
        new_speed_y = 0;
        //this->_dir_angle += 0.1f;
    }
    
    if(this->_move_right){
        logger.debug("Right");
        new_speed_x = SPEED;
        new_speed_y = 0;
        //this->_dir_angle -= 0.1f;
        //std::cout << this->_dir_angle << std::endl;
    }
    
    if(!this->_move_up && !this->_move_down){
        logger.info("OMG!");
        new_speed_x -= SPEED;
        new_speed_y -= SPEED;
        
        if(new_speed_x < 0){
            new_speed_x = 0;
        }
        if(new_speed_y < 0){
            new_speed_y = 0;
        }
    }
    
    setSpeed(new_speed_x, new_speed_y, new_speed_z);
    GLdouble new_pos_x = this->_pos_x + this->_speed_x * _delta*(-sin(_dir_angle*3.14/180));
    GLdouble new_pos_y = this->_pos_y + this->_speed_y * _delta*(cos(_dir_angle*3.14/180));
    GLdouble new_pos_z = 0.0f;
    
    std::cout << "NEW_POS_X: " << new_pos_x << std::endl;
    std::cout << "NEW_POS_Y: " << new_pos_y << std::endl;
    
    if(std::abs(new_pos_x) > 4.5f){ // 4.0f because cube is 5.5f (scale) - 1.5f (scale) of car
        new_pos_x = this->_pos_x;
    }
    
    if(std::abs(new_pos_y) > 4.5f){ // 4.0f because cube is 5.5f (scale) - 1.5f (scale) of car
        new_pos_y = this->_pos_y;
    }
    
    
    setPosition(new_pos_x, new_pos_y, new_pos_z);
  
};

//  ------------------------------------------------------------------ draw()
//  draws car in screen
void Car::draw(){
    logger.debug("Car::draw()");
    GameObject go = GameObject();
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
    
    glPushMatrix();
   
    // move car to top of track
    glTranslatef(this->_pos_x, this->_pos_y, this->_pos_z);
    glRotated(this->_dir_angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,0.0f, 3.0f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    // put car paralel to track

    
    // streering whell
//    glRotated(this->_dir_angle, 0.0f, 1.0f, 0.0f);
    // place car in this position

    // scale it down

    
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
    
    // Draw body
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


