//
//  Track.cpp
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#include "Track.h"
#include "Cheerios.h"
#include <iostream>

Track::Track(){};
Track::~Track(){};

void Track::draw(){
	//Exterior da pista
	while (pos_y < 1.7) {
		pos_y += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.8
		) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.8) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 0.0) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.5) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.5) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.5) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}

	pos_x = -1.0;
	pos_y = -1.2;

	//Interior da pista
	while (pos_y < 1.2) {
		pos_y += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 1.0) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > 1.1) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > 0.2) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -0.3) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x < 0.9) {
		pos_x += 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_y > -1.0) {
		pos_y -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}
	while (pos_x > -1.0) {
		pos_x -= 0.2;
		Cheerios c = Cheerios();
		c.draw(pos_x, pos_y, pos_z);
	}

    std::cout << "Track::draw()" << std::endl;
};
