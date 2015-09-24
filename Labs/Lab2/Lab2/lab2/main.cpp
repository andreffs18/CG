//
//  CG 2015
//  Lab #2
//
#include <iostream>         //
#include <stdlib.h>         // standard lib
#include <GLUT/glut.h>      // glut lib


void whiteSquare(){
    // delimit the vertices of a primitive or a group of like primitives
    glBegin(GL_POLYGON);
    // define white square
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
}
void greenRedSquare(){
    // start drawing green polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();

    // start drawing red polygon
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    
}

//  --------------------------------------------------------------- myDisplay()
//  Custom display function used when event "glutDisplayFunc" is
//  executed. This handles the drawing of the scenes
void myDisplay(void) {
    // Fundamental steps
    // #1 Clear all buffers
    // #2 Draw all lines, dots and polygons
    // #3 Force drawing
    
    // set color to black when buffer get clean
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // actually cleans buffer (Color buffer)
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    // draw cube with 1unit as size
    // glutSolidCube(1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glEnd();
    
    // FRONT
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(-0.500000, -0.500000, -0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.500000, -0.500000, 0.500000);
    glVertex3f(0.500000, -0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, -0.500000);
    glVertex3f(0.500000, 0.500000, 0.500000);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.500000, -0.500000,-0.500000);
    glVertex3f(-0.500000, -0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, 0.500000);
    glVertex3f(-0.500000, 0.500000, -0.500000);
    glEnd();
    
    // force the execution of the GL commands
    glFlush();
}

//  --------------------------------------------------------------- myReshape()
//  Custom reshape function used when event "glutReshapeFunc" is
//  executed. This handles the change in screen size

void myReshape(GLsizei w, GLsizei h) {
    // define size of the viewport
    // args: x, y, weight, height
    // x and y are measure from the bottom left corner of the screen
    // weight and height are the actual size of the viewport
    glViewport(0, 0, w, h);
    // changes the pointer for which Matrix we want to work on. GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    // puts the Identity Matrix as the top matrix of the stack GL_PROJECTION
    glLoadIdentity();
    // changes back the pointer to the GL_MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    // and set's the top matrix of that stack to be the Identity Matrix
    glLoadIdentity();
       
    
    // This call here defines the volume of the projection
    // args: left, right, bottom, top, nearVal, farVal;

    // Fixing resizing of the window
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
    
    // apply translate to change camera's position
    glTranslatef(0.0f, 0.0f, 0.0f);
    // glRotatef(180, 1, 0, 0);
    //glRotatef(20, 0, 1, 0);
    
    gluLookAt(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    
}

//  --------------------------------------------------------------- main()
int main(int argc, char * argv[]) {

    // initialise glut library
    glutInit(&argc, argv);
    // request a RGBA display mode, and we want single buffering
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    // set the initial window size
    glutInitWindowSize(400, 400);
    // set the initial window position
    glutInitWindowPosition (-1, -1);
    // create the window with properties defined before
    glutCreateWindow("Lab #1");
    // set the callback function to use to draw our scene
    glutDisplayFunc(myDisplay);
    // set the callback function to handle changes in screen size
    glutReshapeFunc(myReshape);
    // this function runs a forever in a loop to keep the program running
    glutMainLoop();
    return 0;
}