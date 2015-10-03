//
//  main.cpp
//  Lab2
//
//  Created by Ana Isabel Galvão on 24/09/15.
//  Copyright © 2015 Ana Isabel Galvão. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>


// ------------------------ ver_cube[][] that builds the cube vertexes in a matrix ------------------------
float ver_cube [8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};


// ---------------------- color[][] defines each colors for each vertex of the cube ----------------------
GLfloat color [8][3] =
{
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
    {0.5, 0.35, 0.05},
};

// ------------------------ quad() creates each square from vertexes ------------------------

void quad(int a,int b,int c,int d)
{
    glBegin (GL_QUADS);
    glColor3fv (color[a]);
    glVertex3fv (ver_cube[a]);
    
    glColor3fv (color[b]);
    glVertex3fv (ver_cube[b]);
    
    glColor3fv (color[c]);
    glVertex3fv (ver_cube[c]);
    
    glColor3fv (color[d]);
    glVertex3fv (ver_cube[d]);
    glEnd();
}

//------------------------ colorcube() colours each square (by its vertexes) ------------------------
void colorcube()
{
    quad (0,3,2,1);
    quad (2,3,7,6);
    quad (0,4,7,3);
    quad (1,2,6,5);
    quad (4,5,6,7);
    quad (0,1,5,4);
}

double rotate_y = 0;
double rotate_x = 0;
 
// ------------------------ specialKeys() defines rotation keys ------------------------
void specialKeys (int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}

// ------------------------ display() creates the display ------------------------
void display()
{
    glClearColor (0, 0, 0, 1);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode (GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet (GLUT_WINDOW_WIDTH);
    int h = glutGet (GLUT_WINDOW_HEIGHT);
    gluPerspective (40, w / h, 0.1, 100);
    
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
    (
     3, 3, 3,
     0, 0, 0,
     0, 0, 1
     );
    
    // specialKeys
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
  
    //test for rotation and perspective
    colorcube();
    
    glutSwapBuffers();
}

// ------------------------ reshape() mantains proportion when display size changes ------------------------ 
void reshape(int w, int h)
{
    float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float)w / h;
    if (aspect > ratio)
        glViewport((w - h*ratio) / 2, 0, h*ratio, h);
    else
        glViewport(0, (h - w / ratio) / 2, w, w / ratio);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(xmin, xmax, ymin, ymax);
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize (640, 480);
    glutCreateWindow ("CUBE");
    glutDisplayFunc (display);
    glutSpecialFunc (specialKeys);
    glutReshapeFunc(reshape);
    glEnable (GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
