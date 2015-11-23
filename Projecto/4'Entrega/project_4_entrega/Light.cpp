//
//  project_3_entrega - Light.cpp
//
#include "Light.h"
#include "Game.h"

//directional light
Light::Light(){
    // specular, diffuse and ambiente definitions
    specular[0] = 1.0f;
    specular[1] = 1.0f;
    specular[2] = 1.0f;
    specular[3] = 1.0f;
    
    diffuse[0] = 1.0f;
    diffuse[1] = 1.0f;
    diffuse[2] = 1.0f;
    diffuse[3] = 1.0f;
    
    ambient[0] = 0.5f;
    ambient[1] = 0.5f;
    ambient[2] = 0.5f;
    ambient[3] = 1.0f;
    
    // directional position on the table.
    directional_position[0] = 0.0f;
    directional_position[1] = 5.0f;
    directional_position[2] = 5.0f;
    directional_position[3] = 0.0f;
    
    // spotlight position on the table. we want to
    // setup first (x, y, z) = 0,0,10 for it to be on the center
    // and 10 units high.
    spot_position[0] = 0.0f;
    spot_position[1] = 0.0f;
    spot_position[2] = 10.0f;
    spot_position[3] = 1.0f;
}

Light::~Light(){};

void Light::init(){
    // apply light properties
    logger.info("Init Directional Light");
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, directional_position);
    
    // init spotlights (candles)
    // max of 6 candles because we are using Light0 for the directional and
    // will be using the Light7 and light8 for the headlights of the car
    if(gm.QTD_CANDLES > 6) gm.QTD_CANDLES = 6;
    // always point the spotlight down to the track
    GLfloat spotlight_direction[3] = {0.0f, 0.0f, -1.0f};
    // calc pos of the candles. want them to be 2/3 the distance from
    // center and 1/3 the border of the track.
    float d_center = 2 * gm.TRACK_SIZE / 3;
    logger.info("Init Spotlights Light (Candles)");
    for(double angle = 0.0f, i = 0; angle < 360.0f; angle += 360.0f / (gm.QTD_CANDLES), i++){
        // if not only one candle. we calc the pos around the track
        if(gm.QTD_CANDLES != 1){
            spot_position[0] = d_center * cos(angle*(PI/180));
            spot_position[1] = d_center * sin(angle*(PI/180));
        }
        glLightfv(GL_LIGHT1+i, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT1+i, GL_AMBIENT,  ambient);
        glLightfv(GL_LIGHT1+i, GL_DIFFUSE,  diffuse);
        
        glLightfv(GL_LIGHT1+i, GL_POSITION, spot_position);
        //glLightfv(GL_LIGHT1+i, GL_SPOT_DIRECTION, spotlight_direction);
        // we want to redeuce the angle of apperture of the spotligth
        // for as many candles we have.. this means, if less candles, more
        // cutoff angle, with a maximum of 120º
		//glLightf(GL_LIGHT1+i, GL_CONSTANT_ATTENUATION,1.0f);
		//glLightf(GL_LIGHT1+i, GL_LINEAR_ATTENUATION, 1.25f);
		//glLightf(GL_LIGHT1+i, GL_QUADRATIC_ATTENUATION, 2.56f);
        glLightf(GL_LIGHT1+i, GL_SPOT_CUTOFF, (60.0f * 2/ gm.QTD_CANDLES));
        glLightf(GL_LIGHT1+i, GL_SPOT_EXPONENT, 2.0f);
    }

	glLightfv(GL_LIGHT7, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT7, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuse);

	glLightfv(GL_LIGHT7, GL_POSITION, gm.headlight_pos);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, gm.headlight_direction);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, (60.0f * 2 / gm.QTD_CANDLES));
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 2.0f); 
}




bool Light::areCandlesOn(){
    // checks if candles are active. we just check for light 1 because
    // from light1 to ligth 6, those lights are reserved for candles.. so
    // if one is active the rest is aswell
    return glIsEnabled(GL_LIGHT1);
}

void Light::turnCandlesOn(){
    for(int i=0; i < gm.QTD_CANDLES; i++)
        glEnable(GL_LIGHT1 + i);
};
void Light::turnCandlesOff(){
    for(int i=0; i < gm.QTD_CANDLES; i++)
        glDisable(GL_LIGHT1 + i);
};

void Light::turnHeadlightOn(){
	glEnable(GL_LIGHT7);
};

void Light::turnHeadlightOff(){
	glDisable(GL_LIGHT7);
};
