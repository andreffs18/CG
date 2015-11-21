//
//  project_3_entrega - GameManager.cpp
//
#include <typeinfo>
#include <complex>
#include <time.h>
#include <cmath>
#include "Game.h"
#include "GameManager.h"

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
    _init_track();
    // Initialize Car
    _init_car();
    // Initialize Cheerios
    // _init_cheerio();
    // Initialize Oranges
    // _init_orange();
    // Initialize Butters
	// _init_butter();
    // Initialize Player lifes
    _init_player();
    
    // Initalize cameras
    std::vector<Camera *> _cameras;
    // first camera, look from above
    Camera * cam1 = new OrthogonalCamera(-25, 25, -25, 25, -20, 5);
    cam1->setPos(new Vector3(0.0f, 0.0f, 30.0f));
    cam1->setUp(new Vector3(0.0f, 1.0f, 0.0f));
    this->_cameras.push_back(cam1);
    
    // second camera, isometric look
    Camera * cam2= new PerspectiveCamera(60, 0.1, 100);
    cam2->setPos(new Vector3(-20.0f, -20.0f, 20.0f));
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
    
    this->lights = new Light();
    this->textures = new Texture();
};

GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

void GameManager::init(){
    this->lights->init();
    this->textures->init();
};

//  ----------------------------------------------------------_init_<obj>()
//  aux methods to init objects in game manager
void GameManager::_init_track(){
    logger.debug("GameManager::_init_track()");
    track = new Track();
    track->setPosition(new Vector3(0.0f, 0.0f, -.25f));
    this->_static_objects.push_back(track);
};
void GameManager::_init_car(){
    logger.debug("GameManager::_init_car()");
    car = new Car();
    car->setPosition(START_POSITION);
    car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
    this->_dynamic_objects.push_back(car);
};
void GameManager::_init_cheerio(){
    logger.debug("GameManager::_init_cheerio()");
    // remove cheerios from statiobject
    std::vector<StaticObject*> aux;
    for (GameObject * obj : _static_objects) {
        // colision with cheerios:
        if (typeid(Cheerio) != typeid(*obj)) {
            aux.push_back((StaticObject*)obj);
        }
    }
    _static_objects.swap(aux);
    
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
};
void GameManager::_init_orange(){
    logger.debug("GameManager::_init_orange()");
    // remove oranges from statiobject
    std::vector<DynamicObject*> aux;
    for (GameObject * obj : _dynamic_objects) {
        // colision with cheerios:
        if (typeid(Orange) != typeid(*obj)) {
            aux.push_back((DynamicObject*)obj);
        }
    }
    _dynamic_objects.swap(aux);
    
    for(int i = 0, px = 0, py = 0, v = -1; i < 2; v=px, i++){
        px = (i%2==0) ? (-1)*v : v;
        py = (i%2==0) ? 1 : -1;
        // TRACK_SIZE-2 is for not generate a pos to place oranges
        // in extact end of the table (track)
        GLdouble pos_x = (rand() % 95)/100.0 * px * (TRACK_SIZE - 2);
        GLdouble pos_y = (rand() % 95)/100.0 * py * (TRACK_SIZE - 2);
        
        orange = new Orange();
        orange->setPosition(new Vector3(pos_x, pos_y, 0.75f)); //orange->_height/2
        orange->setSpeed(new Vector3(SPEED_INCREMENT_ORANGES, SPEED_INCREMENT_ORANGES, 0.0f));
        this->_dynamic_objects.push_back(orange);
    }
};
void GameManager::_init_butter(){
    logger.debug("GameManager::_init_butter()");
    // remove butters from statiobject
    std::vector<StaticObject*> aux;
    for (GameObject * obj : _static_objects) {
        // colision with cheerios:
        if (typeid(Butter) != typeid(*obj)) {
            aux.push_back((StaticObject*)obj);
        }
    }
    _static_objects.swap(aux);
    
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
};
void GameManager::_init_player(){
    logger.debug("GameManager::_init_player()");
    // remove player from statiobject
    std::vector<StaticObject*> aux;
    for (GameObject * obj : _static_objects) {
        if (typeid(Player) != typeid(*obj)) {
            aux.push_back((StaticObject*)obj);
        }
    }
    _static_objects.swap(aux);
    
    player = new Player();
    player->setLifes(AMOUNT_PLAYER_LIFES);
    this->_static_objects.push_back(player);
};

GLuint GameManager::getTexture(const char * filename){
    if(!strcmp(filename, "pause")){
        return this->textures->pauseTextureUint();
    } else if(!strcmp(filename, "gameover")){
        return this->textures->gameoverTextureUint();
    } else {
        logger.error("Texture not found");
    }
    // should never happen
    return 0;
};

//  ------------------------------------------------------------- drawAll()
//  Method that handles the drawing of all objects in the display
void GameManager::drawAll() {
	logger.debug("GameManager::drawAll()");
    if(PAUSE or GAMEOVER)
        m.draw();
    
    for (GameObject * obj : _dynamic_objects) { obj->draw(); }
    for (GameObject * obj : _static_objects) { obj->draw(); }
};

//  ----------------------------------------------------- handleColisions()
//  Method that checks and handles all colisions between
//  car and gameobjects
void GameManager::handleColisions(float delta) {
    logger.debug("GameManager::handleColisions()");
    
	// colisions with dynamic objects like oranges
	for (GameObject * obj : _dynamic_objects) {
		// colision with car:
		if (typeid(Car) == typeid(*obj)) {
            // colision car with table boundries
            if(std::abs(car->getPosition()->getX()) > gm.TRACK_LIMITS ||
               std::fabs(car->getPosition()->getY()) > gm.TRACK_LIMITS){
                logger.info("Touched track limits. Killing car reset vars");
                car->die();
                player->die();
            }
        }
		// colision with oranges:
		if (typeid(Orange) == typeid(*obj)) {
            // car with oranges
			if (car->collidesWith(obj)) {
				logger.info("Touched orange. Killing car reset vars");
                car->die();
                player->die();
			}
        }
	}
	// colisions with static objects like butters and cheerios
	for (GameObject * obj : _static_objects) {
		// colision with cheerios:
		if (typeid(Cheerio) == typeid(*obj)) {
            // car with cheerio
			if (car->collidesWith(obj)) {
				// the detection of which cheerio is touched only works for
				// this type of track (circular). We just check where the
				// cheerio is, relative to the radius of the cheerio's on the
				// track. For demonstration purspuses it works.
                Cheerio * cheerio = (Cheerio*)obj;

                GLdouble newcposx = cheerio->getPosition()->getX() + car->getSpeed()->getX() * (delta+2) * (-sin(car->getRotation() * PI / 180));
                GLdouble newcposy = cheerio->getPosition()->getY() + car->getSpeed()->getX() * (delta+2) * ( cos(car->getRotation() * PI / 180));
                GLdouble newcposz = cheerio->getPosition()->getZ();
                cheerio->setPosition(new Vector3(newcposx, newcposy, newcposz));
            
                GLdouble bounce_r = car->getRotation() - gm.ANGLE_INCREMENT;
                GLdouble bounce_x = car->getPosition()->getX() + car->getSpeed()->getX() * (sin(bounce_r * PI / (180)));
                GLdouble bounce_y = car->getPosition()->getY() + car->getSpeed()->getX() * (-cos(bounce_r * PI / (180)));
                GLdouble bounce_z = car->getPosition()->getZ();
                car->setPosition(new Vector3(bounce_x, bounce_y, bounce_z));
                
                if(cheerio->isInnerCheerio()){
                    logger.info("Touched Inner Cherrio: Decreasing car size");
                    if (car->getScale() > CAR_MAX_SCALE_DOWN) {
                        car->setScale(car->getScale() - CAR_SCALE_DELTA);
                        THIRDPERSON_DISTANCE = THIRDPERSON_DISTANCE - CAR_SCALE_DELTA * 4;
                    }
                } else if (cheerio->isOuterCheerio()){
                    logger.info("Touched Outer Cheerio: Increasing car size");
                    if (car->getScale() < CAR_MAX_SCALE_UP) {
                        car->setScale(car->getScale() + CAR_SCALE_DELTA);
                        THIRDPERSON_DISTANCE = THIRDPERSON_DISTANCE + CAR_SCALE_DELTA * 4;
                    }
                } else {/* do nothing */}
            }
            // cheerio with track limits
            if(std::abs(obj->getPosition()->getX()) > gm.TRACK_LIMITS ||
               std::fabs(obj->getPosition()->getY()) > gm.TRACK_LIMITS){
                logger.info("Touched track limits. Killing cheerio");
                obj->setPosition(new Vector3(0.0f, 0.0f, -10.0f));
            }
		}
		// colision with butters:
		if (typeid(Butter) == typeid(*obj)) {
            // car with butter
			if (car->collidesWith(obj)) {
				logger.info("Touched butter");
                Butter * butter = (Butter*)obj;
				GLdouble newbposx = butter->getPosition()->getX() + car->getSpeed()->getX() * (delta+5) * (-sin(car->getRotation() * PI / 180));
				GLdouble newbposy = butter->getPosition()->getY() + car->getSpeed()->getX() * (delta+5) * ( cos(car->getRotation() * PI / 180));
                GLdouble newbposz = butter->getPosition()->getZ();
				butter->setPosition(new Vector3(newbposx, newbposy, newbposz));
                
                GLdouble bounce_r = car->getRotation() - gm.ANGLE_INCREMENT;
                GLdouble bounce_x = car->getPosition()->getX() + car->getSpeed()->getX() * 2 * (sin(bounce_r * PI / (180)));
                GLdouble bounce_y = car->getPosition()->getY() + car->getSpeed()->getX() * 2 *(-cos(bounce_r * PI / (180)));
                GLdouble bounce_z = car->getPosition()->getZ();
                car->setPosition(new Vector3(bounce_x, bounce_y, bounce_z));
			}
            // butter with track limits
            if(std::abs(obj->getPosition()->getX()) > gm.TRACK_LIMITS ||
               std::fabs(obj->getPosition()->getY()) > gm.TRACK_LIMITS){
                logger.info("Touched track limits. Killing butter");
                obj->setPosition(new Vector3(0.0f, 0.0f, -10.0f));
            }
		}
	}
};

//  ----------------------------------------------------------- updateAll()
//  Method that handle all the updates, calculations, colisions
//  for each object in the game
void GameManager::updateAll() {
	logger.debug("GameManager::updateAll()");

    if(PAUSE){ // check if paused
        logger.info("Game Paused. To unpause press 'S'.");
        _previous_time = glutGet(GLUT_ELAPSED_TIME);
        // draw pause menu on draw()
    } else {  // otherwise, just play game
        if(player->isDead()){ // check if dead
            // show restart message
            logger.info("Player reached 0 lifes. Do you want to restart? Press 'R'.");
            GAMEOVER = true;
            
        } else { // otherwise, just play game
            // update
            _current_time = glutGet(GLUT_ELAPSED_TIME);
            // colisions
            handleColisions(_current_time - _previous_time);
            for (GameObject * obj : _dynamic_objects) {
                obj->update(_current_time - _previous_time);
            }
            _previous_time = glutGet(GLUT_ELAPSED_TIME);
        }
    }
};

//  -------------------------------------------------------------- getCamera()
//  method returns respective camera object.
Camera * GameManager::getCamera(int idx){
    return this->_cameras.at(idx);
};

//  -------------------------------------------------------------- camera()
//  method that handles which camera is active.
void GameManager::camera(){
    logger.debug("GameManager::camera()");
    Camera * camera = getCamera(ACTIVE_CAMERA);
    
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
    // enable shade model
    glShadeModel((gm.SHADE) ? GL_SMOOTH : GL_FLAT);
    // wrapper around model and projection matrix
    gm.camera();
    // draw all objects
    gm.drawAll();
    // force the execution of the GL commands
    glutSwapBuffers();
};

//  -------------------------------------------------------------- onIdle()
//  Custom keyboard function used when "glutIdleFunc" triggers
//  an event. This runs the updateAll method and forces onDisplay
void GameManager::onIdle(){
    logger.debug("GameManager::onIdle()");
    gm.updateAll();
    glutPostRedisplay();
};


//  -------------------------------------------------------------- onTime()
//  Custom timer function used on "glutTimerFunc" events. Sets up
//  different level configurations through out the game
void GameManager::onTime(int level){
    logger.debug("GameManager::onTime()");
    // saves the level
    gm.CURRENT_LEVEL = level;
    if(level == 0) {
        logger.info("Setting up level #1");
        gm.ACTIVE_CAMERA = 0;
        gm.SPEED_INCREMENT = 0.00025f;
        gm.MAX_VELOCITY = 0.01f;
        gm.ANGLE_INCREMENT = 1.5f;
        gm.THIRDPERSON_DISTANCE = 5.0f;
        gm.QTD_CHEERIOS = 32;
        gm.QTD_ORANGES = 4;
        gm.QTD_BUTTERS = 4;
        gm.CAR_SCALE_DELTA = 0.005f;
        gm.CAR_MAX_SCALE_UP = 0.5f;
        gm.CAR_MAX_SCALE_DOWN = 0.1f;
        gm.counter = 0;
        gm.SPEED_INCREMENT_ORANGES = 0.0025;
        gm.MAX_VELOCITY_ORANGES = 0.000005;
    } else if(level == 1) {
        logger.info("Setting up level #2");
        gm.SPEED_INCREMENT = 0.00035f;
        gm.MAX_VELOCITY = 0.02f;
        gm.ANGLE_INCREMENT = 2.0f;
        gm.THIRDPERSON_DISTANCE = 4.0f;
        gm.QTD_CHEERIOS = 64;
        gm.QTD_ORANGES = 3;
        gm.QTD_BUTTERS = 1;
        gm.CAR_SCALE_DELTA = 0.01f;
        gm.CAR_MAX_SCALE_UP = 0.4f;
        gm.CAR_MAX_SCALE_DOWN = 0.2f;
        gm.SPEED_INCREMENT_ORANGES = 0.003;
        gm.MAX_VELOCITY_ORANGES = 0.06;
    } else if(level == 2) {
        logger.info("Setting up level #3");
        gm.SPEED_INCREMENT = 0.00045f;
        gm.MAX_VELOCITY = 0.025f;
        gm.ANGLE_INCREMENT = 2.5f;
        gm.THIRDPERSON_DISTANCE = 4.5f;
        gm.QTD_CHEERIOS = 16;
        gm.QTD_ORANGES = 4;
        gm.QTD_BUTTERS = 2;
        gm.CAR_SCALE_DELTA = 0.01f;
        gm.CAR_MAX_SCALE_UP = 0.4f;
        gm.CAR_MAX_SCALE_DOWN = 0.2f;
        gm.SPEED_INCREMENT_ORANGES = 0.004;
        gm.MAX_VELOCITY_ORANGES = 0.065;
    } else if(level == 3){
        logger.info("Setting up level #4");
        gm.SPEED_INCREMENT = 0.00045f;
        gm.MAX_VELOCITY = 0.025f;
        gm.ANGLE_INCREMENT = 2.5f;
        gm.THIRDPERSON_DISTANCE = 4.5f;
        gm.QTD_CHEERIOS = 32;
        gm.QTD_BUTTERS = 4;
        gm.SPEED_INCREMENT_ORANGES = 0.0045;
        gm.MAX_VELOCITY_ORANGES = 0.07;
    }
    
    gm._init_butter();
    gm._init_orange();
    gm._init_cheerio();
};

//  ---------------------------------------------------------- onKeyboard()
//  Custom keyboard function used when "glutKeyboardFunc"
//  triggers an event. This handles the keyboardPress
void GameManager::onKeyboard(unsigned char key, int x, int y){
    logger.debug("GameManager::onKeyboard()");
    // change to wireframe
    if (key == 'A' || key == 'a'){
        int polygonMode;
        glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
        if (polygonMode == GL_LINE){
            logger.info("Changin to GL_FILL (Polygons)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        } else {
            logger.info("Changin to GL_LINE (Wireframe)");
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
    }
    // turn On/Off directional Light Source
    else if (key =='N' || key == 'n'){
        if(glIsEnabled(GL_LIGHT0)){
            logger.info("Turn off Directional Light");
            glDisable(GL_LIGHT0);
        } else {
            logger.info("Turn on Directional Light");
            glEnable(GL_LIGHT0);
        }
    }
    // turn shade model between flat/smooth
    else if (key == 'G' || key == 'g'){
        logger.info("Toggle Shade model beween Flat/Smooth");
        gm.SHADE = !gm.SHADE;
    }
    // turn on/off light calc
    else if (key == 'L' || key == 'l'){
        if(glIsEnabled(GL_LIGHTING)){
            logger.info("Turn off Light Calc");
            glDisable(GL_LIGHTING);
        } else {
            logger.info("Turn on Light Calc");
            glEnable(GL_LIGHTING);
        }
    }
    // turn on/off spotlights calc
    else if (key == 'H' || key == 'h'){
        if(gm.lights->areSpotlightsOn()){
            logger.info("Turn off Car Spotlights");
            gm.lights->turnSpotlightsOff();
        } else {
            logger.info("Turn on Light Calc");
            gm.lights->turnSpotlightsOn();
        }
    }
    // turn on/off all candles
    else if (key == 'C' || key == 'c'){
        if(gm.lights->areCandlesOn()){
            logger.info("Turn off all candles Calc");
            gm.lights->turnCandlesOff();
        } else {
            logger.info("Turn on all candles Calc");
            gm.lights->turnCandlesOn();
        }
    }
    // pause/unpause
    else if (!gm.player->isDead() && (key == 'S' || key == 's')){
        logger.info("Pausing or Unpausing");
        // change state variable PAUSE
        gm.PAUSE = !gm.PAUSE;
    }
    // if player dead and R pressed, restart game
    else if (gm.player->isDead() && (key == 'R' || key == 'r')){
        logger.info("Restart Game");
        // change state variables
        gm.player->setLifes(gm.AMOUNT_PLAYER_LIFES);
        gm.CURRENT_LEVEL = 0;
        gm.GAMEOVER = false;
        // set time event handler for glut. this defines diferent levels p/time
        for(int i = 0; i < sizeof(gm.LEVEL_LIFE)/sizeof(gm.LEVEL_LIFE[0]); i++){
            glutTimerFunc(gm.LEVEL_LIFE[i], GameManager::onTime, i);
        }
    }
    // changing which camera is on
    else{
        switch(key){
            case '1': gm.ACTIVE_CAMERA = 0; break;
            case '2': gm.ACTIVE_CAMERA = 1; break;
            case '3': gm.ACTIVE_CAMERA = 2; break;
            case '4': GLOBAL1 += 1.f; std::cout << "++GLOBAL1: " << GLOBAL1 << std::endl; break;
            case '5': GLOBAL1 -= 1.f; std::cout << "--GLOBAL1: " << GLOBAL1 << std::endl; break;
            case '6': GLOBAL2 += 1.f; std::cout << "++GLOBAL2: " << GLOBAL2 << std::endl; break;
            case '7': GLOBAL2 -= 1.f; std::cout << "--GLOBAL2: " << GLOBAL2 << std::endl; break;
            case '8': GLOBAL3 += 1.f; std::cout << "++GLOBAL3: " << GLOBAL3 << std::endl; break;
            case '9': GLOBAL3 -= 1.f; std::cout << "--GLOBAL3: " << GLOBAL3 << std::endl; break;
            case 27: exit(0); break;
        }
    }
    glutPostRedisplay();
};

//  ------------------------------------------------------- onSpecialKeys()
//  Custom keyboard function used when "glutSpecialFunc"
//  triggers an event. This handles the special keys press
void GameManager::onSpecialKeys(int key, int x, int y) {
    logger.debug("GameManager::keyPress()");
    Car * car = (Car *)gm._dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->setMoveUp(true);
    if(key == GLUT_KEY_DOWN)
        car->setMoveDown(true);
    if(key == GLUT_KEY_LEFT)
        car->setMoveLeft(true);
    if(key == GLUT_KEY_RIGHT)
        car->setMoveRight(true);
};

//  ----------------------------------------------------- onSpecialUpKeys()
//  Custom keyboard function used when "glutSpecialUpFunc"
//  triggers an event. This handles key release
void GameManager::onSpecialKeysUp(int key, int x, int y) {
    logger.debug("GameManager::keyRelease()");
    Car * car = (Car *)gm._dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->setMoveUp(false);
    if(key == GLUT_KEY_DOWN)
        car->setMoveDown(false);
    if(key == GLUT_KEY_LEFT)
        car->setMoveLeft(false);
    if(key == GLUT_KEY_RIGHT)
        car->setMoveRight(false);
};

