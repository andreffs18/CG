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

    GLfloat new_pos_x = getPosition()->getX() + getSpeed()->getX() * delta * (-sin(getRotation() * PI/180));
    GLfloat new_pos_y = getPosition()->getY() + getSpeed()->getX() * delta * ( cos(getRotation() * PI/180));
    GLfloat new_pos_z = 0.0f;
  
    setPosition(new Vector3(new_pos_x, new_pos_y, new_pos_z));
    
    Light * l = gm.getLights();
    l->init_headlights(this);
    
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

void Car::die(){
    setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
    setPosition(gm.START_POSITION);
	setRotation(0.0f);
	setScale(gm.CAR_MAX_SCALE_UP - 0.2f);
	setMoveUp(false);
	setMoveDown(false);
    setMoveLeft(false);
    setMoveRight(false);
}

void Car::setMoveUp(bool b){ _move_up = b; };
void Car::setMoveDown(bool b){ _move_down = b; };
void Car::setMoveLeft(bool b){ _move_left = b; };
void Car::setMoveRight(bool b){ _move_right = b; };

void Car::setScale(GLdouble s){
    _scale = s;
    setRadius(s * 3);
};
GLdouble Car::getScale(){ return _scale; };

void Car::drawV1(){
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
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb_front_wheel, diffuse_front_wheel, specular_front_wheel, &shine_front_wheel);
    glColor3f(1.0f, 1.0f, 1.0f);
    
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
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb_back_wheel, diffuse_back_wheel, specular_back_wheel, &shine_back_wheel);
    glColor3f(0, 1.0f, 1.0f);
    
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

    if(glIsEnabled(GL_LIGHTING))
        material(amb_body, diffuse_body, specular_body, &shine_body);
    glColor3f(0.0f, 0.0f, 1.0f);
    
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
    if(glIsEnabled(GL_LIGHTING))
        material(amb_spoiler, diffuse_spoiler, specular_spoiler, &shine_spoiler);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    glTranslatef(0.0f, -3.0f, 0.0f);
    glScalef(1.0f, 5.0f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();
};

void Car::drawV2(){
    // draw body
    glPushMatrix();
    glScalef(5.0f, 0.7f, 3.0f);
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb_body, diffuse_body, specular_body, &shine_body);
    glColor3f(0.0f, 0.0f, 1.0f);
    _drawCube();
    glPopMatrix();
    
    // draw wheels
    glPushMatrix();
    static float wheels[4][3] = {
        // front left        // front right
        {-5.0f, .5f, 4.2f}, {-5.0f, .5f, -4.2f},
        // back left        // back right
        {5.0f, .5f, 4.2f}, {5.0f, .5f, -4.2f},
    };
    glScalef(0.4f, 0.4f, 0.4f);
    for(int i=0; i<4; i++){
        glPushMatrix();
        glTranslatef(wheels[i][0], wheels[i][1], wheels[i][2]);
        
        if(glIsEnabled(GL_LIGHTING))
            material(amb_back_wheel, diffuse_back_wheel, specular_back_wheel, &shine_back_wheel);
        glColor3f(0.15f, 1.0f, 1.0f);
        
        // if right side of car, rotate wheels
        if(i%2!=0){
            glRotatef(180, 0.0f, 1.0f, 0.0f);
        }
        
        _drawHexagon();
        glPopMatrix();
    }
    glPopMatrix();

    // draw spoiler
    glPushMatrix();
    // Draw top spoiler
    if(glIsEnabled(GL_LIGHTING))
        material(amb_spoiler, diffuse_spoiler, specular_spoiler, &shine_spoiler);
    else
        glColor3f(1.0f, 0.0f, 0.0f);

    
    glTranslatef(2.5f, 1.5f, 0.0f);
    glScalef(1.0f, 0.1f, 4.0f);
    _drawCube();
    // Draw handle for spoiler
    glTranslatef(0.0f, -3.0f, 0.0f);
    glScalef(1.0f, 5.0f, 0.05f);
    // Draw handle for spoiler
    _drawCube();
    glPopMatrix();
};

void Car::_drawCube(){
    glBegin(GL_QUADS);
    // left
    // glColor3f(.7f, .7f, .7f);
    glNormal3fv(normalize(0.5, 0.5, 0.5));
    glVertex3f(0.5f, 0.5f, 0.5f);
    glNormal3fv(normalize(0.5, -0.5, 0.5));
    glVertex3f(0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, -0.5, 0.5));
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, 0.5, 0.5));
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // right
    // glColor3f(.7f, .7f, .7f);
    glNormal3fv(normalize(0.5, 0.5, -0.5));
    glVertex3f(0.5f, 0.5f, -0.5f);
    glNormal3fv(normalize(0.5, -0.5, -0.5));
    glVertex3f(0.5f, -0.5f, -0.5f);
    glNormal3fv(normalize(-0.5, -0.5, -0.5));
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glNormal3fv(normalize(-0.5, 0.5, -0.5));
    glVertex3f(-0.5f, 0.5f, -0.5f);
    
    // top
    // glColor3f(.5f, .5f, .5f);
    glNormal3fv(normalize(0.5, 0.5, 0.5));
    glVertex3f(0.5f, 0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, 0.5, 0.5));
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, 0.5, -0.5));
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glNormal3fv(normalize(0.5, 0.5, -0.5));
    glVertex3f(0.5f, 0.5f, -0.5f);
    
    // bottom
    // glColor3f(.3f, .3f, .3f);
    glNormal3fv(normalize(0.5, -0.5, 0.5));
    glVertex3f(0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, -0.5, 0.5));
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, -0.5, -0.5));
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glNormal3fv(normalize(0.5, -0.5, -0.5));
    glVertex3f(0.5f, -0.5f, -0.5f);
    
    // front
    //glColor3f(.5f, .7f, .9f);
    glNormal3fv(normalize(-0.5, 0.5, 0.5));
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, -0.5, 0.5));
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(-0.5, -0.5, -0.5));
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glNormal3fv(normalize(-0.5, 0.5, -0.5));
    glVertex3f(-0.5f, 0.5f, -0.5f);
    
    //back
    // glColor3f(.5f, .7f, .9f);
    glNormal3fv(normalize(0.5, 0.5, 0.5));
    glVertex3f(0.5f, 0.5f, 0.5f);
    glNormal3fv(normalize(0.5, -0.5, 0.5));
    glVertex3f(0.5f, -0.5f, 0.5f);
    glNormal3fv(normalize(0.5, -0.5, -0.5));
    glVertex3f(0.5f, -0.5f, -0.5f);
    glNormal3fv(normalize(0.5, 0.5, -0.5));
    glVertex3f(0.5f, 0.5f, -0.5f);
    glEnd();
}

void Car::_drawHexagon(){
    static float hexagonFront[6][3], hexagonBottom[6][3];
    // init positions
    for(int angle = 0, i = 0; angle < 360; angle += 360/6, i++){
        GLdouble _cos = cos(angle*(PI/180));
        GLdouble _sin = sin(angle*(PI/180));
        hexagonFront[i][0] = 2.5 * _cos;
        hexagonFront[i][1] = 2.5 * _sin;
        hexagonFront[i][2] = 0.5f;
        hexagonBottom[i][0] = hexagonFront[i][0];
        hexagonBottom[i][1] = hexagonFront[i][1];
        hexagonBottom[i][2] = -0.5f;
    }

    // front
    glBegin(GL_POLYGON);
    for(int i = 0; i<6; i++){
        glNormal3fv(normalize(hexagonFront[i][0], hexagonFront[i][1], hexagonFront[i][2]));
        glVertex3fv(hexagonFront[i]);
    }
    glEnd();
    
    // back
    glBegin(GL_POLYGON);
    for(int i = 0; i<6; i++){
        glNormal3fv(normalize(hexagonBottom[i][0], hexagonBottom[i][1], hexagonBottom[i][2]));
        glVertex3fv(hexagonBottom[i]);
    }
    glEnd();
    // all 8 quads
    
    glBegin (GL_QUADS);
    for (int i = 0, v = 0; i < 6; i++, v = (i + 1) % 6) {
        
        glNormal3fv(normalize(hexagonFront[v][0], hexagonFront[v][1], hexagonFront[v][2]));
        glVertex3f(hexagonFront[v][0], hexagonFront[v][1], hexagonFront[v][2]);
        
        //glNormal3fv(normalize(hexagonBottom[v][0], hexagonBottom[v][1], hexagonBottom[v][2]));
        glVertex3f(hexagonBottom[v][0], hexagonBottom[v][1], hexagonBottom[v][2]);
 
        //glNormal3fv(normalize(hexagonBottom[i][0], hexagonBottom[i][1], hexagonBottom[i][2]));
        glVertex3f(hexagonBottom[i][0], hexagonBottom[i][1], hexagonBottom[i][2]);
        
        //glNormal3fv(normalize(hexagonFront[i][0], hexagonFront[i][1], hexagonFront[i][2]));
        glVertex3f(hexagonFront[i][0], hexagonFront[i][1], hexagonFront[i][2]);
        
    }
    glEnd();
};

void Car::drawCarModel(){
    switch (VERSION) {
        case 1: drawV1(); break;
        case 2: drawV2(); break;
        default: logger.error("Car version not available. Only V1 or V2");
            throw 0;
            break;
    }
};

//// in case we need to check normals
//// draws an axis in the object
//glPushMatrix();
//glScalef(5.0f, 5.0f, 5.0f);
//glBegin(GL_LINES);
//
//glColor3f(1.0f, 0.0f, 0.0f);
//glVertex3f(0.0f, 0.0f, 0.0f);
//glVertex3f(1.0f, 0.0f, 0.0f);
//
//glColor3f(0.0f, 1.0f, 0.0f);
//glVertex3f(0.0f, 0.0f, 0.0f);
//glVertex3f(0.0f, 1.0f, 0.0f);
//
//glColor3f(0.0f, 0.0f, 1.0f);
//glVertex3f(0.0f, 0.0f, 0.0f);
//glVertex3f(0.0f, 0.0f, 1.0f);
//glEnd();
//glPopMatrix();

