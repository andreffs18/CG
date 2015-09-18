//
//  CG 2015
//  Lab #1
//

#include <iostream>     //
#include <stdlib.h>     // standard lib
#include <GLUT/glut.h>    // glut lib

//  --------------------------------------------------------------- myDisplay()
//  Custom display function used when event "glutDisplayFunc" is
//  executed. This handles the drawing of the scenes
void myDisplay(){
    
}
//  --------------------------------------------------------------- myReshape()
//  Custom reshape function used when event "glutReshapeFunc" is
//   executed. This handles the change in screen size
void myReshape(){
    
}

//  --------------------------------------------------------------- main()
int main(int argc, const char * argv[]) {
    
    // initialise glut
    glutInit(&argc, argv);
    
    // request a RGBA display mode, and we want single buffering
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    
    // set the initial window size
    glutInitWindowSize(400,400);
    
    // set the initial window position
    glutInitWindowPosition(-1, -1);
    
    // create the window
    glutCreateWindow("My first test");
    
    // set the function to use to draw our scene
    glutDisplayFunc(myDisplay);
    
    // set the function to handle changes in screen size
    glutReshapeFunc(myReshape);
    
    // this function runs a while loop to keep the program running.
    glutMainLoop();
    return 0;
}