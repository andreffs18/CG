//
//  project_3_entrega - OrthogonalCamera.h
//

#include "Light.h"

Light::Light(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4]){
    _ambientLight = ambient;
    _diffuseLight= diffuse;
    _specularLight = specular;
    
}

//directional light
Light::Light(){
	GLdouble new_pos_x;
	GLdouble new_pos_y;
	GLdouble new_dir_x;
	GLdouble new_dir_y;

    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambient[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat spotlight_direction[] = {0.0f, 0.0f, 0.0f};
	GLfloat position[] = {0.0, 0.0, 1.0, 1.0};
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotlight_direction);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT2, GL_POSITION, position);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotlight_direction);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT3, GL_POSITION, position);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotlight_direction);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT4, GL_POSITION, position);
	glLightfv(GL_LIGHT4, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT4, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotlight_direction);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT5, GL_POSITION, position);
	glLightfv(GL_LIGHT5, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT5, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotlight_direction);

	// -----------------------------------------------------------------

	new_pos_x = ((rand() % 41) - 20);
	new_pos_y = ((rand() % 41) - 20);
	position[0] = new_pos_x;
	position[1] = new_pos_y;
	new_dir_x = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_x *= -1;
	}
	new_dir_y = ((double)rand() / (RAND_MAX));
	if (((double)rand() / (RAND_MAX))) {
		new_dir_y *= -1;
	}
	spotlight_direction[0] = new_dir_x;
	spotlight_direction[1] = new_dir_y;

	glLightfv(GL_LIGHT6, GL_POSITION, position);
	glLightfv(GL_LIGHT6, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT6, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse);

	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotlight_direction);
}

Light::~Light(){};
