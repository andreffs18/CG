//
//  project_1_entrega - Car.cpp
//
#include <complex>
#include "Game.h"
#include "Car.h"

Car::Car() : DynamicObject(){
    this->setRotation(0.0f);
    _scale = 0.7f;
    _radius = _scale * 3;

    // car is not moving
    _move_up = false;
    _move_down = false;
    _move_left = false;
    _move_right = false;
    
};
Car::~Car(){};

//  ---------------------------------------------------------------- update()
//  updates car's position, velocity and rotation
void Car::update(float delta){
    logger.debug("Car::update()");
    
    // if right is clicked
    if(_move_right){
        // if is moving forward, then rotate (+)
        if(_move_up || _speed->getX() > 0)
            // to drift when starts to speed up
            if(_speed->getX() < gm.SPEED_INCREMENT * 4)
                this->setRotation(this->getRotation() - gm.ANGLE_INCREMENT / 2);
            else
				this->setRotation(this->getRotation() - gm.ANGLE_INCREMENT);
        // if is moving backward, then rotate (-)
        else if(_move_down ||  _speed->getX() < 0)
			this->setRotation(this->getRotation() + gm.ANGLE_INCREMENT);
    }

    // if left is clicked
    if(_move_left){
        // if is moving forward, then rotate (-)
        if(_move_up || _speed->getX() > 0)
            // to drift when starts to speed up
            if(_speed->getX() < gm.SPEED_INCREMENT * 4)
				this->setRotation(this->getRotation() + gm.ANGLE_INCREMENT / 2);
            else
				this->setRotation(this->getRotation() + gm.ANGLE_INCREMENT);
        // if is moving backward, then rotate (+)
        else if(_move_down || _speed->getX() < 0)
			this->setRotation(this->getRotation() - gm.ANGLE_INCREMENT);
    }
    
    // if moving forward and not max velocity
    if(_move_up && _speed->getX() < gm.MAX_VELOCITY){
        _speed->setX(_speed->getX() + gm.SPEED_INCREMENT);
    }
    
    // if moving backwards
    if(_move_down && _speed->getX() > -gm.MAX_VELOCITY/2){
        _speed->setX(_speed->getX() - gm.SPEED_INCREMENT);
    }
           
    // if not moving forward or backwards then it's
    if(!_move_up && !_move_down){
        if(_speed->getX() > 0)
            _speed->setX(_speed->getX() - gm.SPEED_INCREMENT/2);
        if(_speed->getX() < 0)
            _speed->setX(_speed->getX() + gm.SPEED_INCREMENT/2);
    }

    double new_pos_x = _position->getX() + _speed->getX() * delta * (-sin(this->getRotation() * PI/180));
    double new_pos_y = _position->getY() + _speed->getX() * delta * ( cos(this->getRotation() * PI/180));
    double new_pos_z = 0.0f;
    
     //define car limits on map
    if(std::abs(new_pos_x) > gm.TRACK_LIMITS){
        new_pos_x = _position->getX();
    }
    if(std::abs(new_pos_y) > gm.TRACK_LIMITS){
        new_pos_y = _position->getY();
    }
    
    _position = new Vector3(new_pos_x, new_pos_y, new_pos_z);
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

bool Car::is_move_up(){ return _move_up; };
bool Car::is_move_down(){ return _move_down; };
bool Car::is_move_left(){ return _move_left; };
bool Car::is_move_rigth(){ return _move_right; };


void Car::set_move_up(bool b){ _move_up = b; };
void Car::set_move_down(bool b){ _move_down = b; };
void Car::set_move_left(bool b){ _move_left = b; };
void Car::set_move_right(bool b){ _move_right = b; };

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
    glTranslatef(0.0f, -2.5f, 0.0f);
    glScalef(1.0f, 5.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
};


