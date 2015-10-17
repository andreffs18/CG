//
//  project_1_entrega - GameManager.cpp
//
#include <typeinfo>
#include <complex>
#include <ctime>
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
    time_t t;
    srand((unsigned) time(&t));
    
    // Initialize Track
    track = new Track();
    track->setPosition(new Vector3(0.0f, 0.0f, -0.20f));
    this->_static_objects.push_back(track);

    // Initialize Car
    car = new Car();
    car->setPosition(new Vector3(0.0f, 0.0f, 0.0f));
    this->_dynamic_objects.push_back(car);

    // Initialize Cheerios
    // angle start position
    GLdouble angle = 0.0f;
    for(int i = 0; angle < 360.0f; angle += 360.0f / (QTD_CHEERIOS), i++){
        // we draw the outer cheerio twice as much as the inner one
        // in a pair instance of the angle we dra both, otherwise
        // we just draw the outer cheerio
        if(i % 2 == 0){
            cheerio = new Cheerio();
            cheerio->setRotation(angle);
            cheerio->setPosition(new Vector3(INNER_CIRCLE_RADIUS, 0.0f, 0.0f));
            this->_static_objects.push_back(cheerio);
        }
        cheerio = new Cheerio();
        cheerio->setRotation(angle);
        cheerio->setPosition(new Vector3(OUTER_CIRCLE_RADIUS, 0.0f, 0.0f));
        this->_static_objects.push_back(cheerio);
        
    }
    // Initialize Oranges
    // define diferent quadrants
    GLdouble x_quad_oranges_pos[4] = {1, 1, -1, -1}; // imporve this
    GLdouble y_quad_oranges_pos[QTD_ORANGES];
    for(int i = 0; i < QTD_ORANGES; i++){
        //x_quad_pos[i] = () ? -1 : 1;
        y_quad_oranges_pos[i] = (i%2==0) ? 1 : -1;
    }
    for (int i = 0; i < QTD_ORANGES; i++) {
        GLdouble pos_x = (rand() % 95)/100.0 * x_quad_oranges_pos[i];
        GLdouble pos_y = (rand() % 95)/100.0 * y_quad_oranges_pos[i];
        orange = new Orange();
        orange->setPosition(new Vector3(pos_x, pos_y, 0.1f)); //orange->_height/2
        this->_dynamic_objects.push_back(orange);
    }
    // Initialize Butters
    GLdouble x_quad_butters_pos[4] = {1, 1, -1, -1}; // imporve this
    GLdouble y_quad_butters_pos[QTD_BUTTERS];
    for(int i = 0; i < QTD_BUTTERS; i++){
        //x_quad_pos[i] = () ? -1 : 1;
        y_quad_butters_pos[i] = (i%2==0) ? 1 : -1;
    }
    for(int i = 0; i < QTD_BUTTERS; i++){
        GLdouble pos_x = (rand() % 95)/100.0 * x_quad_butters_pos[i];
        GLdouble pos_y = (rand() % 95)/100.0 * y_quad_butters_pos[i];
        butter = new Butter();
        butter->setPosition(new Vector3(pos_x, pos_y, 0.05f));
        butter->setRotation(rand() % 360);
        this->_static_objects.push_back(butter);
    }
    
};
GameManager::~GameManager(){logger.debug("GameManager::~GameManager()");};

//  ------------------------------------------------------------ keyPress()
//  handles which direction was clicked. changes the state of
//  the variable in question.
void GameManager::keyPress(int key){
    logger.debug("GameManager::keyPress()");
    Car * car = (Car *)_dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->set_move_up(true);
    if(key == GLUT_KEY_DOWN)
        car->set_move_down(true);
    if(key == GLUT_KEY_LEFT)
        car->set_move_left(true);
    if(key == GLUT_KEY_RIGHT)
        car->set_move_right(true);
};

//  ---------------------------------------------------------- keyRelease()
//  handles which direction was released. changes the state of
//  the variable in question.
void GameManager::keyRelease(int key){
    logger.debug("GameManager::keyRelease()");
    Car * car = (Car *)_dynamic_objects.front();
    if(key == GLUT_KEY_UP)
        car->set_move_up(false);
    if(key == GLUT_KEY_DOWN)
        car->set_move_down(false);
    if(key == GLUT_KEY_LEFT)
        car->set_move_left(false);
    if(key == GLUT_KEY_RIGHT)
        car->set_move_right(false);
};

//  ------------------------------------------------------------- drawAll()
//  Method that handles the drawing of all objects in the display
void GameManager::drawAll(){
    logger.debug("GameManager::drawAll()");
    for(GameObject * obj: _dynamic_objects){
        obj->draw();
    }
    for(GameObject * obj: _static_objects){
        obj->draw();
    }
};

//  ----------------------------------------------------------- updateAll()
//  Method that handle all the updates, calculations, colisions
//  and what not of each object in the display
void GameManager::updateAll(){
    logger.debug("GameManager::updateAll()");
    
    // colisions
    for(GameObject * obj: _dynamic_objects){
        if(typeid(Car) == typeid(*obj)){ /* do nothing */ }
            
        if(typeid(Orange) == typeid(*obj)){
            if(car->collidesWith(obj)){
                logger.error("Touched orange");
                car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
                car->set_move_up(false);
            }
        }
    }
    for(GameObject * obj: _static_objects){
        if(typeid(Cheerio) == typeid(*obj)){
            if(car->collidesWith(obj)){
                logger.error("Touched cheerio");
            }
        }
        if(typeid(Butter) == typeid(*obj)){
            if(car->collidesWith(obj)){
                logger.error("Touched butter");
                car->setSpeed(new Vector3(0.0f, 0.0f, 0.0f));
                car->set_move_up(false);
            }
        }
    }
    
    // update
    _current_time = glutGet(GLUT_ELAPSED_TIME);
    for(GameObject * obj : _dynamic_objects){
        obj->update(_current_time - _previous_time);
    }
    _previous_time = glutGet(GLUT_ELAPSED_TIME);
};

//  ----------------------------------------------------------- onReshape()
//  Custom reshape function used when "glutReshapeFunc"
//  triggers an event. This handles the change in screen size
void GameManager::onReshape(GLsizei w, GLsizei h){
    logger.debug("GameManager::onReshape()");
    // define size of the viewport
    // args: x, y, weight, height
    // x and y are measure from the bottom left corner of the screen
    // weight and height are the actual size of the viewport
    float xmin = -1., xmax = 1., ymin = -1., ymax = 1.;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float) w / h;
    if (aspect > ratio)
        glViewport((w-h*ratio)/2, 0, h*ratio, h);
    else
        glViewport(0, (h-w/ratio)/2, w, w/ratio);
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
    glClear((ENABLE_DEPTH) ? GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT: GL_COLOR_BUFFER_BIT);
    
    // enable depth
    if(ENABLE_DEPTH){ glEnable(GL_DEPTH_TEST); } else { glDisable(GL_DEPTH_TEST); }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(fov, aspect_ration, near_plane, far_plane)
    // Field of View (degrees). the amount of "zoom". eg: 90°-extra wide|30°-zoomed in
    // Aspect Ratio. Width/Height eg: 4/3 or 16/9
    // Near clipping plane.
    // Far clipping plane.
    gluPerspective(P_FOV, P_ASPECT_RATIO, P_NEAR, P_FAR);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(POSCAM->getX(), POSCAM->getY(), POSCAM->getZ(), // camera pos
              POINTCAM->getX(), POINTCAM->getY(), POINTCAM->getZ(),  // where is the camera pointing to
              AXIS->getX(), AXIS->getY(), AXIS->getZ()); // which axis is the up
    // draw all objects
    gm.drawAll();
    // force the execution of the GL commands
    (ENABLE_DOUBLE_BUFFER) ? glutSwapBuffers() : glFlush();
    
};

//  -------------------------------------------------------------- onIdle()
//  Custom keyboard function used when "glutIdleFunc" triggers
//  an event. This runs all logic inside if glut has no events
//  to run
void GameManager::onIdle(){
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
        switch(key){
            case '1' : POSCAM->setX(POSCAM->getX() + ROTATION_SPEED); logger.info("Camera Position +X"); break;
            case '2' : POSCAM->setY(POSCAM->getY() + ROTATION_SPEED); logger.info("Camera Position +Y"); break;
            case '3' : POSCAM->setZ(POSCAM->getZ() + ROTATION_SPEED); logger.info("Camera Position +Z"); break;
            case '8' : POSCAM->setX(POSCAM->getX() - ROTATION_SPEED); logger.info("Camera Position -X"); break;
            case '9' : POSCAM->setY(POSCAM->getY() - ROTATION_SPEED); logger.info("Camera Position -Y"); break;
            case '0' : POSCAM->setZ(POSCAM->getZ() - ROTATION_SPEED); logger.info("Camera Position -Z"); break;
            case 'q' : POINTCAM->setX(POINTCAM->getX() + ROTATION_SPEED); logger.info("Camera Pointer +X"); break;
            case 'w' : POINTCAM->setY(POINTCAM->getY() + ROTATION_SPEED); logger.info("Camera Pointer +Y"); break;
            case 'e' : POINTCAM->setZ(POINTCAM->getZ() + ROTATION_SPEED); logger.info("Camera Pointer +Z"); break;
            case 'i' : POINTCAM->setX(POINTCAM->getX() - ROTATION_SPEED); logger.info("Camera Pointer -X"); break;
            case 'o' : POINTCAM->setY(POINTCAM->getY() - ROTATION_SPEED); logger.info("Camera Pointer -Y"); break;
            case 'p' : POINTCAM->setZ(POINTCAM->getZ() - ROTATION_SPEED); logger.info("Camera Pointer -Z"); break;
            case 'X' : AXIS->setX(1.0f); AXIS->setY(0.0f); AXIS->setZ(0.0f); break;
            case 'Y' : AXIS->setX(0.0f); AXIS->setY(1.0f); AXIS->setZ(0.0f); break;
            case 'Z' : AXIS->setX(0.0f); AXIS->setY(0.0f); AXIS->setZ(1.0f); break;
        }
    }
    glutPostRedisplay();
};

//  ------------------------------------------------------- onSpecialKeys()
//  Custom keyboard function used when "glutSpecialFunc"
//  triggers an event. This handles the special keys like
//  F1, Esc, Left arrow, Right Arrow...
void GameManager::onSpecialKeys(int key, int x, int y){
    gm.keyPress(key);
};

//  ----------------------------------------------------- onSpecialUpKeys()
//  Custom keyboard function used when "glutSpecialUpFunc"
//  triggers an event.
void GameManager::onSpecialKeysUp(int key, int x, int y){
    gm.keyRelease(key);
};

//  -------------------------------------------------------- onMouseClick()
//  Custom fucntion to handle all mouse click events
void GameManager::onMouseClick(int button, int state, int x, int y){};

//  ------------------------------------------------------- onMouseMotion()
//  Custom fucntion to handle all mouse movement
void GameManager::onMouseMotion(int x, int y){};


