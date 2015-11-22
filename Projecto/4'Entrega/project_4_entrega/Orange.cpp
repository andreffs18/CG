#include "Game.h"
#include "Orange.h"
#include <math.h>

Orange::Orange() : DynamicObject(){
    setRadius(0.75f);
	setRotation(0.0f);
};
Orange::~Orange(){};

void Orange::draw(){
	if (gm.DRAW_ORANGE[gm.counter]) {
		logger.debug("On Orange::draw()");
		glPushMatrix();
		glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
		glRotatef(getRotation(), gm.ROTATION_DIRECTION[gm.counter][0], gm.ROTATION_DIRECTION[gm.counter][1], 0.0f);

		if (COLISION_SPHERE) {
			glColor3f(1.0f, 1.0f, 1.0f);
			glutWireSphere(getRadius(), 10, 10);
		}

		if (glIsEnabled(GL_LIGHTING))
			material(amb, diffuse, specular, &shine);
		glColor3f(1.0, 0.4, 0.0);

		glScalef(0.75f, 0.75f, 0.75f);
        drawOrangeModel();
		//draws a stick over the orange
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.02f);
		glTranslatef(0.0f, 0.0f, 1.5f);
		//glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glScalef(0.1f, 0.1f, 1.0f);
		glutSolidCube(.5f);
		glPopMatrix();

		glPopMatrix();
	}

	gm.counter++;
	if (gm.counter == 2) gm.counter = 0;
};

void Orange::drawOrangeModel(){
    switch (VERSION) {
        case 1: drawV1(); break;
        case 2: drawV2(); break;
        default: logger.error("Orange version not available. Only V1 or V2");
            throw 0;
            break;
    }
};
void Orange::drawV1(){
    glutSolidSphere(1.0, 16.0, 16.0);
};

void Orange::drawV2(){
    double r = 1.0f;
    int lats = 16.0f;
    int longs =  16.0f;
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gm.getTexture("orange"));
    
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);
        
        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);
        
        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);
            
            glNormal3f(x * zr0, y * zr0, z0);
            glTexCoord2f(0 , 0);
            glVertex3f(x * zr0, y * zr0, z0);

            glNormal3f(x * zr1, y * zr1, z1);
            glTexCoord2f(1, 1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
};

void Orange::timer(int counter) {
	gm.DRAW_ORANGE[counter] = true;
};

void Orange::update(float delta) {
	if (gm.DRAW_ORANGE[gm.counter]) {
		setRotation(getRotation() + 2.5f);
		GLdouble new_pos_x;
		GLdouble new_pos_y;
		GLdouble new_pos_z = _position->getZ();

		if (gm.SET_DIRECTION[gm.counter]) {
			// randomly decides if moves in -x and/or -y
			gm.SET_NEG_X[gm.counter] = ((double)rand() / (RAND_MAX));
			gm.SET_NEG_Y[gm.counter] = ((double)rand() / (RAND_MAX));
			gm.SET_NEG_X[gm.counter] = round(gm.SET_NEG_X[gm.counter]);
			gm.SET_NEG_Y[gm.counter] = round(gm.SET_NEG_Y[gm.counter]);

			if (gm.SET_NEG_X[gm.counter]) { gm.XY_INCREMENT[gm.counter][0] = _speed->getX() * (-1) * (gm.counter + 1); }
			else { gm.XY_INCREMENT[gm.counter][0] = _speed->getX() * (gm.counter + 1); }

			if (gm.SET_NEG_Y[gm.counter]) { gm.XY_INCREMENT[gm.counter][1] = _speed->getY() * (-1) * (gm.counter + 1); }
			else { gm.XY_INCREMENT[gm.counter][1] = _speed->getY() * (gm.counter + 1); }

			if (gm.INCREASE_SPEED[gm.counter]) {
				if (gm.SET_NEG_X[gm.counter]) { gm.XY_INCREMENT[gm.counter][0] -= gm.INCREASE_FACTOR[gm.counter]; }
				else { gm.XY_INCREMENT[gm.counter][0] += gm.INCREASE_FACTOR[gm.counter]; }
				if (gm.SET_NEG_Y[gm.counter]) { gm.XY_INCREMENT[gm.counter][1] -= gm.INCREASE_FACTOR[gm.counter]; }
				else { gm.XY_INCREMENT[gm.counter][1] += gm.INCREASE_FACTOR[gm.counter]; }

				gm.INCREASE_FACTOR[gm.counter] += 0.0100;
				gm.INCREASE_SPEED[gm.counter] = false;
			}

			// which direction the orange moves
			// value between 0 and 1

			gm.X_DIRECTION = ((double)rand() / (RAND_MAX));
			gm.Y_DIRECTION = ((double)rand() / (RAND_MAX));
			gm.X_DIRECTION = round(gm.X_DIRECTION);
			gm.Y_DIRECTION = round(gm.Y_DIRECTION);

			// it guarantees at least x or y is choosen 
			// It may exist a better way to do this
			while (gm.X_DIRECTION != 1 && gm.Y_DIRECTION != 1) {
				gm.X_DIRECTION = ((double)rand() / (RAND_MAX));
				gm.Y_DIRECTION = ((double)rand() / (RAND_MAX));
				gm.X_DIRECTION = round(gm.X_DIRECTION);
				gm.Y_DIRECTION = round(gm.Y_DIRECTION);
			}

			gm.XY_DIRECTION[gm.counter][0] = gm.X_DIRECTION;
			gm.XY_DIRECTION[gm.counter][1] = gm.Y_DIRECTION;

			gm.TIME_ORANGES[gm.counter] = glutGet(GLUT_ELAPSED_TIME);

			gm.SET_DIRECTION[gm.counter] = false;
		}

		if (gm.XY_DIRECTION[gm.counter][0] && gm.XY_DIRECTION[gm.counter][1]) {
			new_pos_x = _position->getX() + gm.XY_INCREMENT[gm.counter][0] * delta;
			new_pos_y = _position->getY() + gm.XY_INCREMENT[gm.counter][1] * delta;
			new_pos_z = _position->getZ();

			if (gm.SET_NEG_X[gm.counter]) { gm.ROTATION_DIRECTION[gm.counter][1] = -1.0f; }
			else { gm.ROTATION_DIRECTION[gm.counter][1] = 1.0f; }

			if (gm.SET_NEG_Y[gm.counter]) { gm.ROTATION_DIRECTION[gm.counter][0] = 1.0f; }
			else { gm.ROTATION_DIRECTION[gm.counter][0] = -1.0f; }
		}

		else if (gm.XY_DIRECTION[gm.counter][0]) {
			new_pos_x = _position->getX() + gm.XY_INCREMENT[gm.counter][0] * delta;
			new_pos_y = _position->getY();
			new_pos_z = _position->getZ();
			if (gm.SET_NEG_X[gm.counter]) {
				gm.ROTATION_DIRECTION[gm.counter][1] = -1.0f;
				gm.ROTATION_DIRECTION[gm.counter][0] = 0.0f;
			}
			else { 
				gm.ROTATION_DIRECTION[gm.counter][1] = 1.0f;
				gm.ROTATION_DIRECTION[gm.counter][0] = 0.0f;
			}
		}

		else if (gm.XY_DIRECTION[gm.counter][1]) {
			new_pos_x = _position->getX();
			new_pos_y = _position->getY() + gm.XY_INCREMENT[gm.counter][1] * delta;
			new_pos_z = _position->getZ();
			if (gm.SET_NEG_Y[gm.counter]) {
				gm.ROTATION_DIRECTION[gm.counter][0] = 1.0f;
				gm.ROTATION_DIRECTION[gm.counter][1] = 0.0f;
			}
			else {
				gm.ROTATION_DIRECTION[gm.counter][0] = -1.0f;
				gm.ROTATION_DIRECTION[gm.counter][1] = 0.0f;
			}
		}

		// tests track limits
		// if it's off the table generates a new position
		if (fabs(new_pos_x) >= gm.TRACK_LIMITS) {
			new_pos_x = ((rand() % 41) - 20);
			new_pos_y = ((rand() % 41) - 20);
			setRotation(0.0f);
			gm.DRAW_ORANGE[gm.counter] = false;
			int time_to_wait = rand() % 10000 + 1;
			glutTimerFunc(time_to_wait, Orange::timer, gm.counter);
			gm.SET_DIRECTION[gm.counter] = true;
		}
		else if (fabs(new_pos_y) >= gm.TRACK_LIMITS) {
			new_pos_x = ((rand() % 41) - 20);
			new_pos_y = ((rand() % 41) - 20);
			setRotation(0.0f);
			gm.DRAW_ORANGE[gm.counter] = false;
			int time_to_wait = rand() % 10000 + 1;
			glutTimerFunc(time_to_wait, Orange::timer, gm.counter);
			gm.SET_DIRECTION[gm.counter] = true;
		}

		_position = new Vector3(new_pos_x, new_pos_y, new_pos_z);

		// _position = new Vector3(new_pos_x, new_pos_y, new_pos_z);
	}
	gm.counter++;
	if (gm.counter == 2) gm.counter = 0;
};