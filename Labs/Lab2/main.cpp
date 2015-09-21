//
//  CG 2015
//  Lab #1
//

#include <iostream>         //
#include <stdlib.h>         // standard lib
#include <GLUT/glut.h>      // glut lib


//  --------------------------------------------------------------- myDisplay()
//  Custom display function used when event "glutDisplayFunc" is
//  executed. This handles the drawing of the scenes
void myDisplay(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (-1.0f, -1.0f, 0.0f);
    glVertex3f (1.0f, -1.0f, 0.0f);
    glVertex3f (1.0f, 1.0f, 0.0f);
    glVertex3f (-1.0f, 1.0f, 0.0f);
    glEnd();
    glFlush();
}

//  --------------------------------------------------------------- myReshape()
//  Custom reshape function used when event "glutReshapeFunc" is
//   executed. This handles the change in screen size

void myReshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//  --------------------------------------------------------------- main()
int main(int argc, char * argv[]) {

    // initialise glut
    glutInit(&argc, argv);
    // request a RGBA display mode, and we want single buffering
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    // set the initial window size
    glutInitWindowSize (400, 400);
    // set the initial window position
    glutInitWindowPosition (-1, -1);
    // create the window
    glutCreateWindow("Teste");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    
    //     glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    
    
    //     glutInitWindowSize(400,400);
    

    //     glutInitWindowPosition(-1, -1);
    
    
       //  glutCreateWindow("My first test");
    
    // set the function to use to draw our scene
    //     glutDisplayFunc(myDisplay);
    
    // set the function to handle changes in screen size

    
    // this function runs a while loop to keep the program running.
       //  glutMainLoop();
    return 0;
}