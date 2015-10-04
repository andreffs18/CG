//
//  project_1_entrega - GameManager.cpp
//
#include <GL\glut.h>
#include <iostream>
#include "Game.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Cheerio.h"
#include "Track.h"
#include "Car.h"
#include "Butter.h"
#include "Orange.h"

int i;
float pos_x = -0.25;
float pos_y = 0.0;
float pos_z = 1.1;

GameManager::GameManager(){logger.debug("GameManager::GameManager()");};
GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

//pages = range(195, 257)
//front = []
//back = []
//c = 0
//for i in pages:
//    c += 1
//    if c in [1, 2]:
//        front.append(i)
//    elif c in [3, 4]:
//        back.append(i)
//    if c == 4:
//        c = 0
//print(", ".join(map(lambda x: str(x), front)))
//print(", ".join(map(lambda x: str(x), back)))


//  ----------------------------------------------------------- onReshape()
//  Custom reshape function used when "glutReshapeFunc"
//  triggers an event. This handles the change in screen size
void GameManager::onReshape(GLsizei w, GLsizei h){
    logger.debug("GameManager::onReshape()");
    // define size of the viewport
    // args: x, y, weight, height
    // x and y are measure from the bottom left corner of the screen
    // weight and height are the actual size of the viewport
    float xmin = -1., xmax = 1., ymin = -1., ymax = 1.;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float) w / h;
    if (aspect > ratio)
        glViewport((w-h*ratio)/2, 0, h*ratio, h);
    else
        glViewport(0, (h-w/ratio)/2, w, w/ratio);
    // changes the pointer for which Matrix we want to work on. GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    // puts the Identity Matrix as the top matrix of the stack GL_PROJECTION
    glLoadIdentity();
    // changes back the pointer to the GL_MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    // and set's the top matrix of that stack to be the Identity Matrix
    glLoadIdentity();
    // define Ortho2d projection
    gluOrtho2D(xmin, xmax, ymin, ymax);
};

//  ----------------------------------------------------------- onDisplay()
//  Custom display function used when "glutDisplayFunc"
//  triggers an event. This handles the drawing of the scenes
void GameManager::onDisplay(){
    logger.debug("GameManager::onDisplay()");
    // Fundamental steps
    // #1 Clear all buffers
    // #2 Draw all lines, dots and polygons
    // #3 Force drawing
    // set color to black when buffer get clean
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // actually cleans buffer (Color buffer)
    glClear((ENABLE_DEPTH) ? GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT: GL_COLOR_BUFFER_BIT);

    // enable depth
    if(ENABLE_DEPTH){
        glEnable(GL_DEPTH_TEST);
    } else {
        glDisable(GL_DEPTH_TEST);
    }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // gluPerspective(fov, aspect_ration, near_plane, far_plane)
    // Field of View (degrees). the amount of "zoom". eg: 90°-extra wide|30°-zoomed in
    // Aspect Ratio. Width/Height eg: 4/3 or 16/9
    // Near clipping plane.
    // Far clipping plane.
    gluPerspective(P_FOV, P_ASPECT_RATIO, P_NEAR, P_FAR);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(0.0f, 0.0f, 10.0f, // the position of your camera, in world space
              0.0f, 0.0f, 0.0f,  // where is the camera pointing to
              0.0f, 1.0f, 0.0f); // which axis is the up

    // draw objects
    Track track = Track();
    track.draw();

	for (i = 0; i < 3; i++) {
		if (i == 1) {
			pos_x = -0.2;
			pos_y = 0.4;
		}
		else if (i == 2) {
			pos_x = 0.8;
			pos_y = -0.5;
		}
		glPushMatrix();
		glScalef(5.5, 5.5, 1.5);
		glTranslatef(pos_x, pos_y, pos_z);
		Orange o = Orange();
		o.draw();
		glPopMatrix();
	}

	pos_x = -2.0;
	pos_y = 2.0;
	pos_z = 5.0;

	for (i = 0; i < 5; i++) {
		if (i == 1) {
			pos_x = -1.5;
			pos_y = -1.0;
		}
		else if (i == 2) {
			pos_x = 1.8;
			pos_y = 0.8;
		}
		else if (i == 3) {
			pos_x = -0.7;
			pos_y = -0.5;
		}
		else if (i == 4) {
			pos_x = -1.0;
			pos_y = 0.5;
		}
		else if (i == 5) {
			pos_x = 0.7;
			pos_y = -1.0;
		}
		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		Butter b = Butter();
		b.draw();
		glPopMatrix();
	}
    
    // for testing, this enable rotation on screen for the 3 axi
    if(ENABLE_ROTATION_X||ENABLE_ROTATION_Y||ENABLE_ROTATION_Z){
        if(ENABLE_ROTATION_X) glRotatef(ROTATION_POS, 1.0f, 0.0f, 0.0f);
        if(ENABLE_ROTATION_Y) glRotatef(ROTATION_POS, 0.0f, 1.0f, 0.0f);
        if(ENABLE_ROTATION_Z) glRotatef(ROTATION_POS, 0.0f, 0.0f, 1.0f);
        // ROTATION_POS += ROTATION_SPEED;
        ROTATION_POS += (ROTATION_POS > 1.0) ? -1.0 : ROTATION_SPEED;
        glutPostRedisplay();
    }
    // force the execution of the GL commands
    (ENABLE_DOUBLE_BUFFER) ? glutSwapBuffers() : glFlush();
    
};

//  ---------------------------------------------------------- onKeyboard()
//  Custom keyboard function used when "glutKeyboardFunc"
//  triggers an event. This handles the keyboardPress
void GameManager::onKeyboard(unsigned char key, int x, int y){
    // change to wireframe
    if (key == 'A' || key == 'a'){
        GLint polygonMode;
        glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
        if (polygonMode == GL_LINE){
            logger.debug("Changin to GL_FILL (Polygons)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        } else{
            logger.debug("Changin to GL_LINE (Wireframe)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        glutPostRedisplay();
    }
};

//  ------------------------------------------------------- onSpecialKeys()
//  Custom keyboard function used when "glutSpecialFunc"
//  triggers an event. This handles the special keys like
//  F1, Esc, Left arrow, Right Arrow...
void GameManager::onSpecialKeys(int key, int x, int y){
    if (key == GLUT_KEY_RIGHT)
        logger.debug("Moved right");
    else if (key == GLUT_KEY_LEFT)
        logger.debug("Moved left");
    else if (key == GLUT_KEY_UP)
        logger.debug("Moved up");
    else if (key == GLUT_KEY_DOWN)
        logger.debug("Moved down");
    
    glutPostRedisplay();
}


//  ------------------------------------------------------------- onMouse()
//  Custom keyboard function used when "glutMouseFunc" triggers
//  an event. This handles the mouse stuf
void GameManager::onMouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON )
        logger.debug("MOUSE LEFT_BUTTON CLICKED");
    else if (button == GLUT_RIGHT_BUTTON)
        logger.debug("MOUSE RIGHT_BUTTON CLICKED");
    else
        logger.debug("MOUSE SOMETHING CLICKED");
    
    glutPostRedisplay( );
}
