//
//  project_1_entrega - GameManager.h
//

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

#include <vector>
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
    int _current_time, _previous_time;

    Car * car;
    Track * track;
    Cheerio * cheerio;
    Butter * butter;
    Orange * orange;
public:
    // Global Variables
    // speed increment on car
    GLdouble SPEED_INCREMENT = 0.00025f;
    // max velocity allowed
    GLdouble MAX_VELOCITY = 0.01f;
    // steering direction angle increment
    GLdouble ANGLE_INCREMENT = 1.0f;
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
    int QTD_ORANGES = 8;
    int QTD_BUTTERS = 4;
    // amount of scale that car increments or decrements when
    // on top of cheerios. Also limit of scaling on each cheerio
    float CAR_SCALE_DELTA = 0.005f;
    float CAR_MAX_SCALE_UP = 1.0f;
    float CAR_MAX_SCALE_DOWN = 0.2f;

	bool SET_DIRECTION[4] = {true, true, true, true};
	int counter = 0;
	float XY_DIRECTION[4][2];
	float XY_INCREMENT[4][2];
	float X_DIRECTION = 0.0f;
	float Y_DIRECTION = 0.0f;
	float SET_NEG_X;
	float SET_NEG_Y;
	float SPEED_INCREMENT_ORANGES = 0.00025;

    GameManager();
    ~GameManager();

    void keyPress(int);
    void keyRelease(int);
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
