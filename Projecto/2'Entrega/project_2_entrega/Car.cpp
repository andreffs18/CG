//
//  project_1_entrega - Car.cpp
//
#include <complex>
#include "Game.h"
#include "Car.h"

Car::Car() : DynamicObject(){
    setRotation(0.0f);
    setScale(gm.CAR_MAX_SCALE_UP - 0.2f);
    setRadius(getScale() * 3);

    // car is not moving
    setMoveUp(false);
    setMoveDown(false);
    setMoveLeft(false);
    setMoveRight(false);
    
};
Car::~Car(){};

//  ---------------------------------------------------------------- update()
//  updates car's position, velocity and rotation
void Car::update(float delta){
    logger.debug("Car::update()");
    
    // if right is clicked
    if(_move_right){
        // if is moving forward, then rotate (+)
        if(_move_up || getSpeed()->getX() > 0)
            // to drift when starts to speed up
            if(getSpeed()->getX() < gm.SPEED_INCREMENT * 4)
                setRotation(getRotation() - gm.ANGLE_INCREMENT / 2);
            else
				setRotation(getRotation() - gm.ANGLE_INCREMENT);
        // if is moving backward, then rotate (-)
        else if(_move_down || getSpeed()->getX() < 0)
            setRotation(getRotation() + gm.ANGLE_INCREMENT);
    }

    // if left is clicked
    if(_move_left){
        // if is moving forward, then rotate (-)
        if(_move_up || getSpeed()->getX() > 0)
            // to drift when starts to speed up
            if(getSpeed()->getX() < gm.SPEED_INCREMENT * 4)
				setRotation(getRotation() + gm.ANGLE_INCREMENT / 2);
            else
				setRotation(getRotation() + gm.ANGLE_INCREMENT);
        // if is moving backward, then rotate (+)
        else if(_move_down || getSpeed()->getX() < 0)
			setRotation(getRotation() - gm.ANGLE_INCREMENT);
    }
    
    // if moving forward and not max velocity
    if(_move_up && getSpeed()->getX() < gm.MAX_VELOCITY){
        getSpeed()->setX(getSpeed()->getX() + gm.SPEED_INCREMENT);
    }
    
    // if moving backwards
    if(_move_down && getSpeed()->getX() > -gm.MAX_VELOCITY/2){
        getSpeed()->setX(getSpeed()->getX() - gm.SPEED_INCREMENT);
    }
           
    // if not moving forward or backwards then it's
    if(!_move_up && !_move_down){
        if(getSpeed()->getX() > 0)
            getSpeed()->setX(getSpeed()->getX() - gm.SPEED_INCREMENT/2);
        if(getSpeed()->getX() < 0)
            getSpeed()->setX(getSpeed()->getX() + gm.SPEED_INCREMENT/2);
    }

    double new_pos_x = getPosition()->getX() + getSpeed()->getX() * delta * (-sin(getRotation() * PI/180));
    double new_pos_y = getPosition()->getY() + getSpeed()->getX() * delta * ( cos(getRotation() * PI/180));
    double new_pos_z = 0.0f;
    
     //define car limits on map
    if(std::abs(new_pos_x) > gm.TRACK_LIMITS){
        new_pos_x = getPosition()->getX();
    }
    if(std::abs(new_pos_y) > gm.TRACK_LIMITS){
        new_pos_y = getPosition()->getY();
    }
    
    setPosition(new Vector3(new_pos_x, new_pos_y, new_pos_z));
};

//  ------------------------------------------------------------------ draw()
//  draws car in screen
void Car::draw(){
    logger.debug("Car::draw()");
    glPushMatrix();
    // move car to top of track
    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
    glRotated(this->getRotation(), 0.0f, 0.0f, 1.0f);

    // rotate it to see it from above
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    // rotate again but now to put in facing Y positive
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    
    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(_radius, 10, 10);
    }
    // scale it down
    glScalef(_scale, _scale, _scale);
    
    drawCarModel();
    glPopMatrix();
};

void Car::setMoveUp(bool b){ _move_up = b; };
void Car::setMoveDown(bool b){ _move_down = b; };
void Car::setMoveLeft(bool b){ _move_left = b; };
void Car::setMoveRight(bool b){ _move_right = b; };

void Car::setScale(GLdouble s){
    _scale = s;
    setRadius(s * 3);
};
GLdouble Car::getScale(){ return _scale; };

void Car::drawCarModel(){
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
    glTranslatef(0.0f, -3.0f, 0.0f);
    glScalef(1.0f, 5.0f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();
};


