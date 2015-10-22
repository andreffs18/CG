/************************************************************
 *	APRON TUTORIALS PRESENTED BY MORROWLAND					*
 *************************************************************
 *	Project Name			: Camera 4						*
 *	Project Description		: 3RD Person Camera A			*
 *	Project Type			: OpenGL						*
 *	Author					: Ronny AndrÈ Reierstad			*
 *	Web Page				: www.morrowland.com			*
 *	E-Mail					: apron@morrowland.com			*
 *	Version					: English (UK)					*
 *	Date					: 17.10.2002					*
 ************************************************************/

#include "main.h"


bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=true;		// Window Active Flag Set To true By Default
bool	fullscreen=true;	// Fullscreen Flag Set To Fullscreen Mode By Default

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

CCamera objCamera;

void Draw_Character();
void Draw_Grid();

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
//										THE RESIZE GL SCENE
/////////////////////////////////////////////////////////////////////////////////////////////////
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
    if (height==0)										// Prevent A Divide By Zero By
    {
        height=1;										// Making Height Equal One
    }
    
    glViewport(0,0,width,height);						// Reset The Current Viewport
    
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix
    
    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    
    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix
    
}




/////////////////////////////////////////////////////////////////////////////////////////////////
//										THE OPENGL INIT
/////////////////////////////////////////////////////////////////////////////////////////////////
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    
    //NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
    // Position			View(target)  Up
    objCamera.Position_Camera(0, 1.5f, 4.0f,	0, 1.5f, 0,   0, 1.0f, 0);
    
    //NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
    
    return true;										// Initialization Went OK
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//										THE OPENGL RENDER
/////////////////////////////////////////////////////////////////////////////////////////////////
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();									// Reset The Current Modelview Matrix
    
    
    // use this function for opengl target camera
    gluLookAt(objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
              objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
              objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
    
    //NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
    
    glPushMatrix();
    // Always keep the character in the view
    glTranslatef(objCamera.mView.x,0.0f,objCamera.mView.z);
    Draw_Character();
    glPopMatrix();
    
    
    Draw_Grid();
    
    glPushMatrix();
    glScalef(0.5f, 0.5f, 0.5f);
    glTranslatef(0,1.0f,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glColor3f(1.0f,0.5f,0.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();
    glPopMatrix();
    
    //NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
    
    return true;										// Keep Going
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//										THE KEYBOARD INPUT
/////////////////////////////////////////////////////////////////////////////////////////////////

void Draw_Character() // This object will symbolize our character
{
    glScalef(0.3f,1.0f,0.3f);
    glTranslatef(0,1.0f,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);		
    glVertex3f( 0.0f, 1.0f, 0.0f);						
    glVertex3f( 1.0f,-1.0f, 1.0f);					
    glVertex3f( 1.0f,-1.0f, -1.0f);					
    glVertex3f( 0.0f, 1.0f, 0.0f);					
    glVertex3f( 1.0f,-1.0f, -1.0f);					
    glVertex3f(-1.0f,-1.0f, -1.0f);						
    glVertex3f( 0.0f, 1.0f, 0.0f);					
    glVertex3f(-1.0f,-1.0f,-1.0f);					
    glVertex3f(-1.0f,-1.0f, 1.0f);			
    glEnd();
}


void Draw_Grid()
{																	
    
    for(float i = -500; i <= 500; i += 5)
    {
        glBegin(GL_LINES);
        glColor3ub(150, 190, 150);							
        glVertex3f(-500, 0, i);									
        glVertex3f(500, 0, i);
        
        glVertex3f(i, 0, -500);								
        glVertex3f(i, 0, 500);
        glEnd();
    }
}

/*
 *****************************************************************************
	NOTES:
 *****************************************************************************
 
 Itís impossible for people to move around physically in a "virtual 3D world",
 we therefore use a "camera" to get orientated. When setting up a basic
 camera in OpenGL there are two main subjects to be taken into consideration,
 the camera handling and the perspective. 
 
 
 An OpenGL camera consists of three vectors: position, view and up.
 The "position", is the actual point where the camera is located,
 while the "view" is the target point that the camera is looking at.
 If you're standing in a room looking at a picture on the wall,
 then your eyes are the position and the picture is the view.
 You can say that the position point and the target point form a 
 view-vector.The "up" or "tilt" decides if the camera is tilting
 (used in flight simulators). 
 
 
 You can set up your "camera lens" in OpenGL by altering the perspective values. 
 The perspective of an OpenGL camera consists of four elements: fovy, aspect,
 near and far. "Fovy" specifies the field of view angle, in degrees,
 in the y-direction. "Aspect" specifies the aspect ratio that determines the
 field of view in the x-direction. The aspect ratio is the ratio of x (width)
 to y (height). "Near" specifies the distance from the viewer to the nearest
 clipping plane (always positive). "Far" specifies the disistance from the viewer
 to the far clipping plane (always positive). 
 
 There are many ways to create a camera, but since we always keep the
 character in our view, this is called a 3RD Person Camera. 
 
 Use the mouse and arrow keys or W A S D keys to move around.
 
 -----------------------------------------------------------------------------
 */
//Regards
//Ronny AndrÈ Reierstad
//www.morrowland.com
//apron@morrowland.com