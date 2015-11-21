//
//  Menu.cpp
//  project_4_entrega
//


#include "Menu.h"
#include "Game.h"
#include "Texture.h"

Menu::Menu(){};
Menu::~Menu(){};

void Menu::draw(){
    Texture t;
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    glOrtho(-25, 25, -25, 25, -20, 5);
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glLoadIdentity();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 1);
    
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    t.loadTexture("pausa.bmp");
    
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-15.0f, 10.0f, 0.0f);
    glTexCoord2f(0, 1); glVertex3f(-15.0f, -10.0f, 0.0f);
    glTexCoord2f(1, 0); glVertex3f(15.0f, -10.0f, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(15.0f, 10.0f, 0.0f);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
    
    
}

