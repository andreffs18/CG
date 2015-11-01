//
//  project_1_entrega - GameManager.cpp
//
#include <typeinfo>
#include <complex>
#include <time.h>
#include <cmath>
#include "Game.h"
#include "GameManager.h"

#include "Car.h"
#include "Track.h"
#include "Cheerio.h"
#include "Orange.h"
#include "Butter.h"

GameManager::GameManager(){
    logger.debug("GameManager::GameManager()");
    // init time tracking
    _previous_time = 0, _current_time = 0;
    // init vector of gameobjects, dynamic and static
    std::vector<DynamicObject *> _dynamic_objects;
    std::vector<StaticObject *> _static_objects;
    
    // init random
    srand((unsigned int)time(NULL));
    
    // Initialize Track
    track = new Track();
    track->setPosition(new Vector3(0.0f, 0.0f, -0.5f));
    this->_static_objects.push_back(track);
    
    // Initialize Car
    car = new Car();
    car->setPosition(START_POSITION);
    car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
    this->_dynamic_objects.push_back(car);
    
    // Initialize Cheerios
    for(double angle = 0.0f, i = 0; angle < 360.0f; angle += 360.0f / (QTD_CHEERIOS), i++){
        // we draw the outer cheerio twice as much as the inner one
        // in a pair instance of the angle we dra both, otherwise
        // we just draw the outer cheerio
        GLdouble _cos = cos(angle*(PI/180));
        GLdouble _sin = sin(angle*(PI/180));
        
        if(int(i) % 2 == 0){
            cheerio = new Cheerio();
            Vector3 * new_pos = new Vector3(INNER_CIRCLE_RADIUS * _cos, INNER_CIRCLE_RADIUS * _sin, 0.0f);
            cheerio->setPosition(new_pos);
            this->_static_objects.push_back(cheerio);
        }
        cheerio = new Cheerio();
        Vector3 * new_pos = new Vector3(OUTER_CIRCLE_RADIUS * _cos, OUTER_CIRCLE_RADIUS * _sin, 0.0f);
        cheerio->setPosition(new_pos);
        this->_static_objects.push_back(cheerio);
        
    }
    // Initialize Oranges
    for(int i = 0, px = 0, py = 0, v = -1; i < QTD_ORANGES; v=px, i++){
        px = (i%2==0) ? (-1)*v : v;
        py = (i%2==0) ? 1 : -1;
        // TRACK_SIZE-2 is for not generate a pos to place oranges
        // in extact end of the table (track)
        GLdouble pos_x = (rand() % 95)/100.0 * px * (TRACK_SIZE - 2);
        GLdouble pos_y = (rand() % 95)/100.0 * py * (TRACK_SIZE - 2);
        
        orange = new Orange();
        orange->setPosition(new Vector3(pos_x, pos_y, 1.0f)); //orange->_height/2
        orange->setSpeed(new Vector3(SPEED_INCREMENT_ORANGES, SPEED_INCREMENT_ORANGES, 0.0f));
        this->_dynamic_objects.push_back(orange);
    }
    
    // Initialize Butters
    for(int i = 0, px = 0, py = 0, v = -1; i < QTD_BUTTERS; v=px, i++){
        px = (i%2==0) ? (-1)*v : v;
        py = (i%2==0) ? 1 : -1;
        // TRACK_SIZE-2 is for not generate a pos to place butters
        // in extact end of the table (track)
        GLdouble pos_x = (rand() % 95)/100.0 * px * (TRACK_SIZE - 2);
        GLdouble pos_y = (rand() % 95)/100.0 * py * (TRACK_SIZE - 2);
        
        butter = new Butter();
        butter->setPosition(new Vector3(pos_x, pos_y, 0.05f));
        butter->setRotation(rand() % 360);
        this->_static_objects.push_back(butter);
    }
    
    // Initalize cameras
    std::vector<Camera *> _cameras;
    // first camera, look from above
    Camera * cam1 = new OrthogonalCamera(-25, 25, -25, 25, -20, 5);
    cam1->setPos(new Vector3(0.0f, 0.0f, 30.0f));
    cam1->setUp(new Vector3(0.0f, 1.0f, 0.0f));
    this->_cameras.push_back(cam1);
    
    // second camera, isometric look
    Camera * cam2= new PerspectiveCamera(60, 0.1, 100);
    cam2->setPos(new Vector3(-30.0f, -30.0f, 30.0f));
    cam2->setUp(new Vector3(0.0f, 0.0f, 1.0f));
    this->_cameras.push_back(cam2);
    
    // third camera, 3'rd person shooter
    GLdouble carx = car->getPosition()->getX();
    GLdouble cary = car->getPosition()->getY();
    Camera * cam3= new PerspectiveCamera(60, 0.1, 100);
    cam3->setPos(new Vector3(carx, cary, 2.0f));
    cam3->setAt(new Vector3(carx, cary, 2.0f));
    cam3->setUp(new Vector3(0.0f, 0.0f, 1.0f));
    this->_cameras.push_back(cam3);
};

GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

//  ------------------------------------------------------------ keyPress()
//  handles which direction was clicked. changes the state of
//  the variable in question.
void GameManager::keyPress(int key){
    logger.debug("GameManager::keyPress()");
    Car * car = (Car *)_dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->setMoveUp(true);
    if(key == GLUT_KEY_DOWN)
        car->setMoveDown(true);
    if(key == GLUT_KEY_LEFT)
        car->setMoveLeft(true);
    if(key == GLUT_KEY_RIGHT)
        car->setMoveRight(true);
};

//  ---------------------------------------------------------- keyRelease()
//  handles which direction was released. changes the state of
//  the variable in question.
void GameManager::keyRelease(int key){
    logger.debug("GameManager::keyRelease()");
    Car * car = (Car *)_dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->setMoveUp(false);
    if(key == GLUT_KEY_DOWN)
        car->setMoveDown(false);
    if(key == GLUT_KEY_LEFT)
        car->setMoveLeft(false);
    if(key == GLUT_KEY_RIGHT)
        car->setMoveRight(false);
};

//  ------------------------------------------------------------- drawAll()
//  Method that handles the drawing of all objects in the display
void GameManager::drawAll() {
	logger.debug("GameManager::drawAll()");
	for (GameObject * obj : _dynamic_objects) {
		obj->draw();
	}
	for (GameObject * obj : _static_objects) {
		obj->draw();
	}
};

//  ----------------------------------------------------- handleColisions()
//  Method that checks and handles all colisions between
//  car and gameobjects
void GameManager::handleColisions() {
	// colisions with dynamic objects like oranges
	for (GameObject * obj : _dynamic_objects) {
		// colision with car:
		if (typeid(Car) == typeid(*obj)) { /* do nothing */ }
		// colision with oranges:
		if (typeid(Orange) == typeid(*obj)) {
			if (car->collidesWith(obj)) {
				logger.error("Touched orange");
				// TODO
				GLdouble start_position = -INNER_CIRCLE_RADIUS - 3;
				car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
				car->setPosition(new Vector3(start_position, 0.0f, 0.0f));
				car->setRotation(0.0f);
				car->setScale(0.7f);
				car->setMoveUp(false);
			}
		}
	}
	// colisions with static objects like butters and cheerios
	for (GameObject * obj : _static_objects) {
		// colision with cheerios:
		if (typeid(Cheerio) == typeid(*obj)) {
			if (car->collidesWith(obj)) {
				// the detection of which cheerio is touched only works for
				// this type of track (circular). We just check where the
				// cheerio is, relative to the radius of the cheerio's on the
				// track. For demonstration purspuses it works.
				GLdouble cheerio_pos_x = fabs(obj->getPosition()->getX());
				GLdouble cheerio_pos_y = fabs(obj->getPosition()->getY());
				bool is_inner_cheerio = cheerio_pos_x <= INNER_CIRCLE_RADIUS && cheerio_pos_y <= INNER_CIRCLE_RADIUS;
				bool is_outer_cheerio = cheerio_pos_x > INNER_CIRCLE_RADIUS || cheerio_pos_y > INNER_CIRCLE_RADIUS;

				GLdouble new_cheerio_pos_x = obj->getPosition()->getX() + car->getSpeed()->getX() * 2 * (-sin(car->getRotation() * PI / 180));
				GLdouble new_cheerio_pos_y = obj->getPosition()->getY() + car->getSpeed()->getX() * 2 * (cos(car->getRotation() * PI / 180));

				obj->setPosition(new Vector3(new_cheerio_pos_x, new_cheerio_pos_y, obj->getPosition()->getZ()));

				// both inner and outer circle
				// (after scaling car, this can happend)
				if (is_inner_cheerio && is_outer_cheerio) { /* do nothing */ }
				// check if colision with inner circle
				else if (is_inner_cheerio) {
					logger.error("Touched Inner Cherrio: Decreasing car size");
					if (car->getScale() > CAR_MAX_SCALE_DOWN) {
						car->setScale(car->getScale() - CAR_SCALE_DELTA);
						THIRDPERSON_DISTANCE = THIRDPERSON_DISTANCE - CAR_SCALE_DELTA * 4;
					}

				}
				// check if colision with outer circle
				else if (is_outer_cheerio) {
					logger.error("Touched Outer Cheerio: Increasing car size");
					if (car->getScale() < CAR_MAX_SCALE_UP) {
						car->setScale(car->getScale() + CAR_SCALE_DELTA);
						THIRDPERSON_DISTANCE = THIRDPERSON_DISTANCE + CAR_SCALE_DELTA * 4;
					}
				}
                car->setMoveUp(false);

                GLdouble bounce_r = car->getRotation() - gm.ANGLE_INCREMENT;
                GLdouble bounce_x = car->getPosition()->getX() + car->getSpeed()->getX() * 30 * (sin(bounce_r * PI / (180)));
                GLdouble bounce_y = car->getPosition()->getY() + car->getSpeed()->getX() * 30 * (-cos(bounce_r * PI / (180)));
                
                car->setPosition(new Vector3(bounce_x, bounce_y, car->getPosition()->getZ()));
                car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
			}
		}
		// colision with butters:
		if (typeid(Butter) == typeid(*obj)) {
			if (car->collidesWith(obj)) {
				logger.error("Touched butter");

				double new_bpos_x = obj->getPosition()->getX() + car->getSpeed()->getX() * 4 * (-sin(car->getRotation() * PI / 180));
				double new_bpos_y = obj->getPosition()->getY() + car->getSpeed()->getX() * 4 * (cos(car->getRotation() * PI / 180));

				obj->setPosition(new Vector3(new_bpos_x, new_bpos_y, obj->getPosition()->getZ()));
				car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
				car->setMoveUp(false);
			}
		}
	}
};

//  ----------------------------------------------------------- updateAll()
//  Method that handle all the updates, calculations, colisions
//  and what not of each object in the display
void GameManager::updateAll() {
	logger.debug("GameManager::updateAll()");

	// colisions
	handleColisions();

	// update
	_current_time = glutGet(GLUT_ELAPSED_TIME);
	for (GameObject * obj : _dynamic_objects) {
		obj->update(_current_time - _previous_time);
	}
	_previous_time = glutGet(GLUT_ELAPSED_TIME);

};

//  ----------------------------------------------------------- onReshape()
//  Custom reshape function used when "glutReshapeFunc"
//  triggers an event. This handles the change in screen size
void GameManager::onReshape(GLsizei w, GLsizei h) {
	logger.debug("GameManager::onReshape()");
	// define size of the viewport
	// args: x, y, weight, height
	// x and y are measure from the bottom left corner of the screen
	// weight and height are the actual size of the viewport
	float xmin = -1., xmax = 1., ymin = -1., ymax = 1.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	if (aspect > ratio)
		glViewport((w - h*ratio) / 2, 0, h*ratio, h);
	else
		glViewport(0, (h - w / ratio) / 2, w, w / ratio);
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

//  -------------------------------------------------------------- camera()
//  method that handles which camera is active.
void GameManager::camera(){
    Camera * camera = _cameras.at(ACTIVE_CAMERA);
    
    // look up camera.
    if(ACTIVE_CAMERA == 0){ /* do nothing */ }
    // isometric view
    else if (ACTIVE_CAMERA == 1){ /* do nothing */ }
    // 3'rd person shooter view
    else if (ACTIVE_CAMERA == 2){
        // update camera pos and at vectors to match car
        Car * car = (Car *)_dynamic_objects.front();
        
        GLdouble car_posx = car->getPosition()->getX();
        GLdouble car_posy = car->getPosition()->getY();
        
        GLdouble poscamx = car_posx - THIRDPERSON_DISTANCE * (-sin(car->getRotation() * PI/180));
        GLdouble poscamy = car_posy - THIRDPERSON_DISTANCE * ( cos(car->getRotation() * PI/180));
        
        camera->setPos(new Vector3(poscamx, poscamy, 2.0f));
        camera->setAt(new Vector3(car_posx, car_posy, 0.0f));
    }    
    camera->update();
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
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // enable depth
    glEnable(GL_DEPTH_TEST);
    // wrapper around model and projection matrix
    gm.camera();
    // draw all objects
    gm.drawAll();
    // force the execution of the GL commands
    glutSwapBuffers();
};


//  -------------------------------------------------------------- onIdle()
//  Custom keyboard function used when "glutIdleFunc" triggers
//  an event. This runs all logic inside if glut has no events
//  to run
void GameManager::onIdle() {
	gm.updateAll();
	glutPostRedisplay();
}

//  ---------------------------------------------------------- onKeyboard()
//  Custom keyboard function used when "glutKeyboardFunc"
//  triggers an event. This handles the keyboardPress
void GameManager::onKeyboard(unsigned char key, int x, int y){
    // change to wireframe
    if (key == 'A' || key == 'a'){
        int polygonMode;
        glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
        if (polygonMode == GL_LINE){
            logger.debug("Changin to GL_FILL (Polygons)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        } else{
            logger.debug("Changin to GL_LINE (Wireframe)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
    }
    else{
        // changing which camera is on
        switch(key){
            case '1': gm.ACTIVE_CAMERA = 0; break;
            case '2': gm.ACTIVE_CAMERA = 1; break;
            case '3': gm.ACTIVE_CAMERA = 2; break;
        }
    }
    glutPostRedisplay();
};

//  ------------------------------------------------------- onSpecialKeys()
//  Custom keyboard function used when "glutSpecialFunc"
//  triggers an event. This handles the special keys like
//  F1, Esc, Left arrow, Right Arrow...
void GameManager::onSpecialKeys(int key, int x, int y) {
	gm.keyPress(key);
};

//  ----------------------------------------------------- onSpecialUpKeys()
//  Custom keyboard function used when "glutSpecialUpFunc"
//  triggers an event.
void GameManager::onSpecialKeysUp(int key, int x, int y) {
	gm.keyRelease(key);
};

//  -------------------------------------------------------- onMouseClick()
//  Custom fucntion to handle all mouse click events
void GameManager::onMouseClick(int button, int state, int x, int y) {};

//  ------------------------------------------------------- onMouseMotion()
//  Custom fucntion to handle all mouse movement
void GameManager::onMouseMotion(int x, int y) {};
