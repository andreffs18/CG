#include "Game.h"
#include "Player.h"

Player::Player() : StaticObject() {
    setLifes(0);
};
Player::~Player() {};


void Player::drawLifeObject(){
    glBegin(GL_POINTS);
    for (float x = -1.139; x <= 1.139; x += 0.001) {
        float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
        float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
        float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
        glVertex2f(x, y1);
        glVertex2f(x, y2);
    }
    glEnd();
};

void Player::die(){ setLifes(getLifes() - 1); };

bool Player::isDead(){ return getLifes() == 0;  };

int Player::getLifes(){ return _lifes; };
void Player::setLifes(int lifes){ _lifes = lifes; };

void Player::setupColor(){
    if(_lifes == 1)
        glColor3f(1.0f, 0.0f, 0.0f);
    else if (_lifes > 1 && _lifes <= 3)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.0f, 1.0f, 0.0f);
};


void Player::draw(){
    logger.debug("On Life::draw()");
    Camera * c = gm.getCamera(0);
    glPushMatrix();
    c->computeProjectionMatrix();
    glPushMatrix();
    c->computeVisualizationMatrix();
    
    setupColor();
    for(int i = 0, _light = 0; i < _lifes; i++){
        glPushMatrix();
        glLoadIdentity();
        
        // hack for making sure the objects are not affected by global light
        if(glIsEnabled(GL_LIGHTING)){ glDisable(GL_LIGHTING); _light = 1; }
        
        glTranslatef(-22.5f + 2.5*i, 22.0f, 10.0f);
        drawLifeObject();
        
        // hack for making sure the objects are not affected by global light
        if(_light!=0) glEnable(GL_LIGHTING);
        
        glPopMatrix();
    }
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}



//glPushMatrix();

//glColor3f(0.f, 0.f, 0.f);

//    glColor3f(1.0f, 1.0f, 1.0f);
//    GLfloat ones[4] = {1, 1, 1, 1};

//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ones);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ones);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ones);
//    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);


//    if (_game_over) {
//        glPushMatrix();
//        glTranslatef(-4, -4, 3);
//        Draw::texturedPlane(1, 1, 8, 8, _end_texture);
//        glPopMatrix();
//    }
//    if (_paused) {
//        glPushMatrix();
//        glTranslatef(-4, -4, 3);
//        Draw::texturedPlane(1, 1, 8, 8, _pause_texture);
//        glPopMatrix();
//    }
//
//
//    GLfloat zero[4] = {0, 0, 0, 1};
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, zero);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, zero);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, zero);
//    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);

//    glColor3f(0.f, 0.f, 0.f);
//    glTranslatef(0.f, -7.f, .5f);
//    glScalef(15.f, 1.f , 1.f);
//    glutSolidCube(1);
//glPopMatrix();