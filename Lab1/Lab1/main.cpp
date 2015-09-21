//
//  main.cpp
//  Lab1
//
//  Created by Ana Isabel Galvão on 19/09/15.
//  Copyright © 2015 Ana Isabel Galvão. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>



//  --------------------- myDisplay() ----------------------------
//  Custom display function used when event "glutDisplayFunc" is
//  executed. This handles the drawing of the scenes

void myDisplay(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    
    /* 
     glColor3f(1.0f, 1.0f, 1.0f); white inititial polygon
     glVertex3f (-1.0f, -1.0f, 0.0f);
     glVertex3f (-1.0f, 1.0f, 0.0f);
     glVertex3f (0.0f, -1.0f, 0.0f);
     glVertex3f (0.0f, 1.0f, 0.0f);
     */
    
    //green polygon starts here
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f (-1.0f, -1.0f, 0.0f);
    glVertex3f (-1.0f, 1.0f, 0.0f);
    //green polygon ends here
    glVertex3f (0.0f, 1.0f, 0.0f);
    glVertex3f (0.0f, -1.0f, 0.0f);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    //red polygon starts here
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f (1.0f, 1.0f, 0.0f);
    glVertex3f (1.0f, -1.0f, 0.0f);
    //red polygon ends here
    glVertex3f (0.0f, -1.0f, 0.0f);
    glVertex3f (0.0f, 1.0f, 0.0f);
    
    
    glEnd();
    glFlush();
}

//  ------------------------ myReshape() ---------------------------
//  Custom reshape function used when event "glutReshapeFunc" is
//   executed. This handles the change in screen size

void myReshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -2 * w/h, 2 * w/h, -2, 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//  -------------------------- main() ------------------------------
int main(int argc, char * argv[]) {
    std::cout << GLUT_SINGLE << std::endl;
    
    glutInit(&argc, argv); // start glut
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (-1, -1);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}


