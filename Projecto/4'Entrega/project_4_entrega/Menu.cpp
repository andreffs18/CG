//
//  Menu.cpp
//  project_4_entrega
//

#include "Menu.h"
#include "Game.h"
#include "Texture.h"

Menu::Menu(){};
Menu::~Menu(){};

void Menu::drawPlaneForTexture(){
    GLfloat size_x = 25.0f;
    GLfloat size_y = 23.5f;
    GLfloat pos_z = 20.0f;
    bool _light = false;
    
    // hack for making sure the objects are not affected by global light
    if(glIsEnabled(GL_LIGHTING)){ glDisable(GL_LIGHTING); _light = true; }
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-size_x, -size_y, pos_z);
    glTexCoord2f(0, 1);
    glVertex3f(-size_x, size_y, pos_z);
    glTexCoord2f(1, 1);
    glVertex3f(size_x, size_y, pos_z);
    glTexCoord2f(1, 0);
    glVertex3f(size_x, -size_y, pos_z);
    glEnd();
    
    // hack for making sure the objects are not affected by global light
    if(_light) glEnable(GL_LIGHTING);
}

void Menu::drawPauseScreen(){
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, gm.getTexture("pause"));
    drawPlaneForTexture();
};

void Menu::drawGameOverScreen(){
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, gm.getTexture("gameover"));
    drawPlaneForTexture();
};

void Menu::drawTableTexture(){
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, gm.getTexture("table"));
}

void Menu::draw(){
    logger.debug("On Menu::draw()");
    Camera * c = gm.getCamera(0);
    glPushMatrix();
    c->computeProjectionMatrix();
    glPushMatrix();
    c->computeVisualizationMatrix();
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    // if pause
    if (gm.PAUSE)
        drawPauseScreen();
    // if gameover
    else if (gm.GAMEOVER)
        drawGameOverScreen();
    
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE0);
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();}

