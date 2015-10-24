#include "Game.h"
#include "Orange.h"

Orange::Orange() : DynamicObject(){
    _radius = 1.55f;
	setRotation(0.0f);
};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");
	glPushMatrix();
    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glRotatef(getRotation(), 0.0f, 1.0f, 0.0f);

    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(_radius, 10, 10);
    }
    glColor3f(1.0, 0.4, 0.0);
    glScalef(1.5f, 1.5f, 1.5f);
    glutSolidSphere(1.0, 16.0, 16.0);

	//draws a stick over the orange
	glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.02f);
    glTranslatef(0.0f, 1.0f, 0.5f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
    
};
void Orange::update(float delta){
	setRotation(getRotation() + 2.5f);
	GLdouble new_pos_x = _position->getX();
	GLdouble new_pos_y = _position->getY();
	GLdouble new_pos_z = _position->getZ();

	if (gm.SET_DIRECTION[gm.counter]) {
		gm.SET_NEG_X = ((double)rand() / (RAND_MAX));
		gm.SET_NEG_Y = ((double)rand() / (RAND_MAX));
		gm.SET_NEG_X = round(gm.SET_NEG_X);
		gm.SET_NEG_Y = round(gm.SET_NEG_Y);

		if (gm.SET_NEG_X) { gm.XY_INCREMENT[gm.counter][0] = _speed->getX() * (-1) * (gm.counter + 1); }
		else { gm.XY_INCREMENT[gm.counter][0] = _speed->getX() * (gm.counter + 1); }

		if (gm.SET_NEG_Y) { gm.XY_INCREMENT[gm.counter][1] = _speed->getY() * (-1) * (gm.counter + 1); }
		else { gm.XY_INCREMENT[gm.counter][1] = _speed->getY() * (gm.counter + 1); }

		gm.X_DIRECTION = ((double)rand() / (RAND_MAX));
		gm.Y_DIRECTION = ((double)rand() / (RAND_MAX));
		gm.X_DIRECTION = round(gm.X_DIRECTION);
		gm.Y_DIRECTION = round(gm.Y_DIRECTION);

		// It may exist a better way to do this
		while (gm.X_DIRECTION != 1 && gm.Y_DIRECTION != 1) {
			gm.X_DIRECTION = ((double)rand() / (RAND_MAX));
			gm.Y_DIRECTION = ((double)rand() / (RAND_MAX));
			gm.X_DIRECTION = round(gm.X_DIRECTION);
			gm.Y_DIRECTION = round(gm.Y_DIRECTION);
		}

		gm.XY_DIRECTION[gm.counter][0] = gm.X_DIRECTION;
		gm.XY_DIRECTION[gm.counter][1] = gm.Y_DIRECTION;

		gm.SET_DIRECTION[gm.counter] = false;
	}

	if (gm.XY_DIRECTION[gm.counter][0] && gm.XY_DIRECTION[gm.counter][1]) {
		new_pos_x = _position->getX() + gm.XY_INCREMENT[gm.counter][0] * delta;
		new_pos_y = _position->getY() + gm.XY_INCREMENT[gm.counter][1] * delta;
		new_pos_z = _position->getZ();
	}

	else if (gm.XY_DIRECTION[gm.counter][0]) {
		new_pos_x = _position->getX() + gm.XY_INCREMENT[gm.counter][0] * delta;
		new_pos_y = _position->getY();
		new_pos_z = _position->getZ();
	}

	else if (gm.XY_DIRECTION[gm.counter][1]) {
		new_pos_x = _position->getX();
		new_pos_y = _position->getY() + gm.XY_INCREMENT[gm.counter][1] * delta;
		new_pos_z = _position->getZ();
	}

	if (std::abs(new_pos_x) >= gm.TRACK_LIMITS) {
		new_pos_x = ((rand() % 41) - 20);
		new_pos_y = ((rand() % 41) - 20);
		gm.SET_DIRECTION[gm.counter] = true;
	}
	if (std::abs(new_pos_y) >= gm.TRACK_LIMITS) {
		new_pos_x = ((rand() % 41) - 20);
		new_pos_y = ((rand() % 41) - 20);
		gm.SET_DIRECTION[gm.counter] = true;
	}
	
	_position = new Vector3(new_pos_x, new_pos_y, new_pos_z);

	gm.counter++;
	if (gm.counter == 4) gm.counter = 0;

    // _position = new Vector3(new_pos_x, new_pos_y, new_pos_z);

    
};