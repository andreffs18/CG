//
//  project_1_entrega - GameManager.h
//

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

#include <vector>

#include "Camera.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"

#include "DynamicObject.h"
#include "StaticObject.h"

#include "Car.h"
#include "Track.h"
#include "Orange.h"
#include "Butter.h"
#include "Cheerio.h"

class GameManager{
private:
    std::vector<StaticObject *> _static_objects;
    std::vector<DynamicObject *> _dynamic_objects;
    std::vector<Camera *> _cameras;
    int _current_time, _previous_time;

    Car * car;
    Track * track;
    Cheerio * cheerio;
    Butter * butter;
    Orange * orange;
public:
    // Global Variables
    // active camera pointer, could be 0,1 or 2
    int ACTIVE_CAMERA = 0;
    // speed increment on car
    GLdouble SPEED_INCREMENT = 0.00025f;
    // max velocity allowed
    GLdouble MAX_VELOCITY = 0.01f;
    // steering direction angle increment
    GLdouble ANGLE_INCREMENT = 1.5f;
    // distance from the car in 3'rd person view
    GLdouble THIRDPERSON_DISTANCE = 5.0f;
    // car limits on track
    GLdouble TRACK_LIMITS = 18.5f;
    GLdouble TRACK_SIZE = 20.0f;
    // track inner circle
    float INNER_CIRCLE_RADIUS = 8.0;
    // track outer circle
    float OUTER_CIRCLE_RADIUS = 14.0;
    // start position of the car
    Vector3 * START_POSITION = new Vector3((-1)*(INNER_CIRCLE_RADIUS + 3.0f), 0.0f, 0.0f);
    // qtd of object on table
    int QTD_CHEERIOS = 32;
    int QTD_ORANGES = 0;
    int QTD_BUTTERS = 4;
    // amount of scale that car increments or decrements when
    // on top of cheerios. Also limit of scaling on each cheerio
    float CAR_SCALE_DELTA = 0.005f;
    float CAR_MAX_SCALE_UP = 0.5f;
    float CAR_MAX_SCALE_DOWN = 0.2f;

	// array to decide if orange needs direction 
	bool SET_DIRECTION[4] = { true, true, true, true };
	// arrays to set which direction to go
	float XY_DIRECTION[4][2];
	// amount of increment of position
	double XY_INCREMENT[4][2];
	// amount of increase for speed of some time spent
	double INCREASE_FACTOR[4] = { 0.001, 0.001, 0.001, 0.001 };
	// to decide if speed must be increased
	bool INCREASE_SPEED[4] = { false, false, false, false };
	// counter to know which orange is being used
	int counter = 0;
	// initial time of each orange
	int TIME_ORANGES[4];
	float X_DIRECTION = 0.0f;
	float Y_DIRECTION = 0.0f;
	// variable that decides if moves in -x and/or -y
	float SET_NEG_X;
	float SET_NEG_Y;
	// initial velocidade of oranges
	float SPEED_INCREMENT_ORANGES = 0.0025;
	float MAX_VELOCITY_ORANGES = 0.05;

	GameManager();
	~GameManager();

    void keyPress(int);
    void keyRelease(int);
    void camera();
    void drawAll();
    void updateAll();
    void handleColisions();
    void Cam1();
    void Cam2();
    void Cam3();
    
    static void onReshape(GLsizei w, GLsizei h);
    static void onDisplay();
    static void onKeyboard(unsigned char key, int x, int y);
    static void onSpecialKeys(int key, int x, int y);
    static void onSpecialKeysUp(int key, int x, int y);
    static void onMouseClick(int button, int state, int x, int y);
    static void onMouseMotion(int x, int y);
    static void onIdle();
};

#endif /* defined(__GAMEMANAGER_H_INCLUDED__) */