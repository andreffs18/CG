#include "Game.h"
#include "Life.h"

Life::Life() : StaticObject() {};
Life::~Life() {};


void Life::drawLifeObject(){
    GLfloat scale = 10.f;
    glScalef(1.0f * scale, 1.0f * scale, 1.0f * scale);
    glRotatef(180, 0.f, 0.f, 1.0f);
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

void Life::setupColor(){
    if(gm.PLAYER_LIFES == 1)
        glColor3f(1.0f, 0.0f, 0.0f);
    else if (gm.PLAYER_LIFES > 1 && gm.PLAYER_LIFES <= 3)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.0f, 1.0f, 0.0f);
};

void Life::draw() {
    logger.debug("On Life::draw()");
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);

    setupColor();
    for(int i = 0; i<gm.PLAYER_LIFES; i++){
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(20.0f + 30.5*i, 30.f, 0.f);
        drawLifeObject();
        glPopMatrix();
    }

    // Making sure we can render 3d again
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
};
